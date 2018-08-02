/*!
* @file       speed.c
* @brief      速度控制代码
* @author     刘俊奇
* @date       2018-03-29
*/

#include  "common.h"
#include  "include.h"



/**********全局变量定义********/
int32 LeftDead = 0;
int32 RighDead = 0;   //死区
//轮子一圈580脉冲  周长206mm
float Ratio_Encoder_Left = 206 / (1070 * 0.1);// 左轮速度=counter*左轮周长(mm)/(左轮转一圈对应的脉冲数*程序周期)
float Ratio_Encoder_Righ = 206 / (1070 * 0.1);//  右轮速度=counter*右轮周长(mm)/(右轮转一圈对应的脉冲数*程序周期)
float g_fRealSpeed = 0;
float g_fLeftRealSpeed;
float g_fRighRealSpeed;
float g_fSpeedFilter = 0;
float g_fExpectSpeed = 0;//2200;
float g_fSpeedError;
float g_fSpeedErrorTemp[5] = { 0 };
float fSpeedErrorInteg = 0;
int32 g_nLeftSpeed = 0, g_nRighSpeed = 0;
float g_fPWMOut;
int32 g_nLeftPWM, g_nRighPWM;
//清华速度控制
float g_speedControl_P = 58;//纯P速度控制
float g_speedControl_I = 0;
float g_speedControl_D = 0;
//位移比例
float g_fSpeedControlOutOld = 0, g_fSpeedControlOutNew = 0;
float g_fSpeedOutput = 0;
float g_fSpeedControlOut = 0;
extern unsigned char SpeedControl_Flag ;

float distance_m = 0;

char Flag_Speed = 1;
char Flag_Direction = 1;
char Flag_Stop = 1;
/*!
*  @brief      电机初始化
*  @param      none
*  @return     none
*  @date       2018-03-29
*/
void MotorInit(void)
{
	ftm_pwm_init(FTM2, FTM_CH0, 8000, 0);
	ftm_pwm_init(FTM2, FTM_CH1, 8000, 0);
	ftm_pwm_init(FTM2, FTM_CH2, 8000, 0);
	ftm_pwm_init(FTM2, FTM_CH3, 8000, 0);

	ftm_pulse_init(FTM1, FTM_PS_1, TCLK1);
	ftm_pulse_init(FTM2, FTM_PS_1, TCLK2);
	port_pull(FTM1_PULSE_PIN, PULLUP_ENBLE);
	port_pull(FTM2_PULSE_PIN, PULLUP_ENBLE);
	gpio_init(PTD2, GPI, 0);				  //编码器方向
	gpio_init(PTD3, GPI, 0);
	
}


/*!
*  @brief      PWM输出
*  @param      none
*  @return     none
*  @date       2018-03-29
*/
void PWMOut(void)
{
	int32 nLeftPWM, nRighPWM;

	g_fPWMOut = g_fBalanceOutput - g_fSpeedControlOut;
	if (Flag_Speed == 0)g_fPWMOut = g_fBalanceOutput;		//如果Flag_Speed == OFF不输出速度

	if (g_fDirectionControlOut >= 0)
	{
		g_nLeftPWM = g_fPWMOut - 1.5*g_fDirectionControlOut;
		g_nRighPWM = g_fPWMOut + 0.5*g_fDirectionControlOut;
	}
	else
	{
		g_nLeftPWM = g_fPWMOut - 0.5*g_fDirectionControlOut;
		g_nRighPWM = g_fPWMOut + 1.5*g_fDirectionControlOut;
	}
	if (Flag_Direction == 0)
	{
		g_nLeftPWM = (int32)g_fPWMOut;		//如果Flag_Direction == OFF不输出方向
		g_nRighPWM = (int32)g_fPWMOut;		//如果Flag_Direction == OFF不输出方向
	}

	if (Flag_Stop == 0) 		//如果Flag_Stop == OFF电机输出0
	{
		g_nLeftPWM = 0; g_nRighPWM = 0;//停车时左右差异消除
	}
		//g_nLeftPWM = g_nLeftPWM*1.03;//电机差异补偿
		//g_nRighPWM = g_nRighPWM;

	//g_nLeftPWM = g_fPWMOut;
	//g_nRighPWM = g_fPWMOut;
	//if (Flag_Direction == OFF)
	//{
	//	g_nLeftPWM = g_fPWMOut;		//如果Flag_Direction == OFF不输出方向
	//	g_nRighPWM = g_fPWMOut;		//如果Flag_Direction == OFF不输出方向
	//}

	//if (Flag_Stop == OFF) 		//如果Flag_Stop == OFF电机输出0
	//{
	//	g_nLeftPWM = 0; g_nRighPWM = 0;//停车时左右差异消除
	//}

	if (g_nLeftPWM < 0)
	{
		nLeftPWM = LeftDead - g_nLeftPWM;
		nLeftPWM = (nLeftPWM > 980 ? 980 : nLeftPWM);
		ftm_pwm_duty(FTM2, FTM_CH0, 0);
		ftm_pwm_duty(FTM2, FTM_CH1, nLeftPWM);
	}
	else
	{
		nLeftPWM = LeftDead + g_nLeftPWM;
		nLeftPWM = (nLeftPWM > 980 ? 980 : nLeftPWM);
		ftm_pwm_duty(FTM2, FTM_CH0, nLeftPWM);
		ftm_pwm_duty(FTM2, FTM_CH1, 0);
	}

//	if (g_nRighPWM < 0)
//	{
//		nRighPWM = RighDead - g_nRighPWM;
//		nRighPWM = (nRighPWM > 980 ? 980 : nRighPWM);
//		ftm_pwm_duty(FTM2, FTM_CH2, 0);
//		ftm_pwm_duty(FTM2, FTM_CH3, nRighPWM);
//	}
//	else
//	{
//		nRighPWM = RighDead + g_nRighPWM;
//		nRighPWM = (nRighPWM > 980 ? 980 : nRighPWM);
//		ftm_pwm_duty(FTM2, FTM_CH2, nRighPWM);
//		ftm_pwm_duty(FTM2, FTM_CH3, 0);
//	}(-ftm_pulse_get(FTM1)));
//	ftm_pulse_clean(FTM1);

	distance_m += (float)(g_nRighSpeed + g_nLeftSpeed) / 580.0*206.0 / 1000.0;
	g_fLeftRealSpeed = (float)(g_nLeftSpeed)/580.0*206.0*10;  //mm/s
	g_fLeftRealSpeed = (g_fLeftRealSpeed>4000 ? 4000 : g_fLeftRealSpeed);		//滤左编码器的噪声
	g_fRighRealSpeed = (float)(g_nRighSpeed) / 580.0*206.0;
	g_fRighRealSpeed = (g_fRighRealSpeed>4000 ? 4000 : g_fRighRealSpeed);		//滤右编码器的噪声

	g_fRealSpeed = (g_fLeftRealSpeed + g_fRighRealSpeed)*0.5;				//真实速度
	//速度采集梯度平滑，每次采集最大变化200
//	fSpeedOld = g_fSpeedFilter;
//	fSpeedNew = g_fRealSpeed;
//
//	if (fSpeedNew >= fSpeedOld)
}


/*!
*  @brief      获取速度偏差
*  @param      none
*  @return     none
*  @date       2018-03-29
*/
void GetSpeedError(void)
{
	static float fSpeedOld = 0, fSpeedNew = 0;
//
//	g_nRighSpeed = (gpio_get(PTD2) == 1 ? ftm_pulse_get(FTM0) : (-ftm_pulse_get(FTM0)));
//	ftm_pulse_clean(FTM0);
//	g_nLeftSpeed = (gpio_get(PTD3) == 0 ? ftm_pulse_get(FTM1) : 
//		g_fSpeedFilter = ((fSpeedNew - fSpeedOld) > 200 ? (fSpeedOld + 200) : fSpeedNew);
//	else
//		g_fSpeedFilter = ((fSpeedNew - fSpeedOld) < -200 ? (fSpeedOld - 200) : fSpeedNew);
//
//	g_fSpeedError = g_fExpectSpeed - g_fSpeedFilter;
	g_fSpeedErrorTemp[4] = g_fSpeedErrorTemp[3];
	g_fSpeedErrorTemp[3] = g_fSpeedErrorTemp[2];
	g_fSpeedErrorTemp[2] = g_fSpeedErrorTemp[1];
	g_fSpeedErrorTemp[1] = g_fSpeedErrorTemp[0];
	g_fSpeedErrorTemp[0] = g_fSpeedError;

}


/**
* @file		速度控制（未用到积分，积分忽略）
* @note      	速度梯度平滑
* @brief		山外KL26平台
* @author		湖北工程学院（参考清华方案）
* @date		2016
*			   欢迎各校各组别与我校真诚交流、共同进步！
*/
void SpeedControl(void)
{
	static float fSpeedErrorDot = 0;

	GetSpeedError();
	//if (Flag_OpenStart == 1) { g_fSpeedError = (g_fSpeedError>1300 ? 1300 : g_fSpeedError); }//起跑速度偏差限幅
	//else 
	g_fSpeedError = (g_fSpeedError>800 ? 800 : g_fSpeedError);//速度偏差限幅
																   //动态期望速度
	//g_fExpectSpeed = 2900 + g_fSpeedError / 5.9;					//超2.9减速
	//g_fExpectSpeed = (g_fExpectSpeed>3100 ? 3100 : g_fExpectSpeed);
	//g_fExpectSpeed = (g_fExpectSpeed<2800 ? 2800 : g_fExpectSpeed);

	fSpeedErrorInteg += (g_speedControl_I / 100.0) * g_fSpeedError;
	//if (Flag_Stop == 1 | Flag_Speed == 1)fSpeedErrorInteg = 0;		//停车积分清零

	fSpeedErrorInteg = (fSpeedErrorInteg < 0.0 ? 0.0 : fSpeedErrorInteg);//积分下限
	fSpeedErrorInteg = (fSpeedErrorInteg > 50.0 ? 50.0 : fSpeedErrorInteg);//积分上限

	g_fSpeedControlOutOld = g_fSpeedControlOutNew;
	g_fSpeedControlOutNew = (g_speedControl_P / 100.0)*g_fSpeedError + fSpeedErrorInteg + g_speedControl_D * (g_fSpeedErrorTemp[0] - g_fSpeedErrorTemp[1]);
}

/**
* @file		速度控制平滑输出
* @note      	分20次输出
* @brief		山外KL26平台
* @author		湖北工程学院（参考清华方案）
* @date		2016
*			   欢迎各校各组别与我校真诚交流、共同进步！
*/
void SpeedControlOut(void)
{
	g_fSpeedControlOut = (g_fSpeedControlOutNew - g_fSpeedControlOutOld)*SpeedControl_Flag / 20 +
		g_fSpeedControlOutOld;

}






