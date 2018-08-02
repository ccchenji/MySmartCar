/*！
* @file       speed.c
* @brief      速度部分程序
* @version    v5.2
* @author     jassy
* @date       2017
*/
#include  "common.h"
#include  "include.h"



/**********全局变量定义********/
int32 LeftDead = 0;
int32 RighDead = 0;
float Ratio_Encoder_Left = 203 / (256 * (20 / 150.0));// 左轮速度=counter*左轮周长(mm)/(左轮转一圈对应的脉冲数*程序周期)
float Ratio_Encoder_Righ = 203 / (256 * (20 / 150.0));//  右轮速度=counter*右轮周长(mm)/(右轮转一圈对应的脉冲数*程序周期)
float g_fRealSpeed = 0;
float g_fLeftRealSpeed;
float g_fRighRealSpeed;
float g_fSpeedFilter = 0;
float g_fExpectSpeed = 4000;
float g_fSpeedError;
float g_fSpeedErrorTemp[5] = { 0 };
float fSpeedErrorInteg = 0;
int32 g_nLeftpulse = 0, g_nRighpulse = 0;
float g_PWMOut;
int32 g_nLeftPWM, g_nRighPWM;
//清华速度控制
float g_speedControl_P = 0.71;//纯P速度控制
float g_speedControl_I = 0;
//位移比例
float g_fSpeedControlOutOld = 0, g_fSpeedControlOutNew = 0;
float g_fSpeedControlOut = 0;


/**
* @file		电机、编码器初始化
* @author     jassy
* @date		2017
*/
void MotorInit(void)
{

	/* 初始化左电机PWM通道 */
	ftm_pwm_init(FTM3, FTM_CH0, 10 * 1000, 0);
	ftm_pwm_init(FTM3, FTM_CH1, 10 * 1000, 0);
	/* 初始化右电机PWM通道 */
	ftm_pwm_init(FTM3, FTM_CH2, 10 * 1000, 0);
	ftm_pwm_init(FTM3, FTM_CH3, 10 * 1000, 0);
	//初始化编码器输入口
	ftm_quad_init(FTM1);		//PTA12 PTA13
	ftm_quad_init(FTM2);		//PTA10 PTA11
//	ftm_quad_init(FTM2);//初始化 TPM2 (PA10\11)为正交解码,左编码器
//	ftm_quad_init(FTM1);//初始化 TPM1 (PA12\13)为正交解码,右编码器
}


/**
* @file		PWM输出
* @author     jassy
* @date		2017
*/
void PWMOut(void)
{
	int32 nLeftPWM, nRighPWM;

	g_PWMOut = g_BlanceControlOut - g_fSpeedControlOut;
	if (Flag_Speed == OFF)g_PWMOut = g_BlanceControlOut;		//如果Flag_Speed == OFF不输出速度

	if (g_fDirectionControlOut >= 0)
	{
		g_nLeftPWM = (int32)(g_PWMOut + g_fDirectionControlOut);
		g_nRighPWM = (int32)(g_PWMOut - g_fDirectionControlOut);
	}
	if (g_fDirectionControlOut<0)
	{
		g_nLeftPWM = (int32)(g_PWMOut + g_fDirectionControlOut);
		g_nRighPWM = (int32)(g_PWMOut - g_fDirectionControlOut);
	}

	//	g_nLeftPWM = g_nLeftPWM;//电机差异补偿
	//	g_nRighPWM = g_nRighPWM;


	if (Flag_Direction == OFF)
	{
		g_nLeftPWM = (int32)g_PWMOut;		//如果Flag_Direction == OFF不输出方向
		g_nRighPWM = (int32)g_PWMOut;		//如果Flag_Direction == OFF不输出方向
	}

	if (Flag_Stop == OFF) 		//如果Flag_Stop == OFF电机输出0
	{
		g_nLeftPWM = 0; g_nRighPWM = 0;//停车时左右差异消除
	}
	if (g_AngleOfCar < -300 || g_AngleOfCar>90)  //车倒保护
	{
		g_nLeftPWM = 0; g_nRighPWM = 0;
	}
	if (g_nLeftPWM < 0)
	{
		nLeftPWM = -LeftDead - g_nLeftPWM;
		nLeftPWM = (nLeftPWM > 800 ? 800 : nLeftPWM);
		ftm_pwm_duty(FTM3, FTM_CH2, nLeftPWM);
		ftm_pwm_duty(FTM3, FTM_CH3, 0);
	}
	else
	{
		nLeftPWM = LeftDead + g_nLeftPWM;
		nLeftPWM = (nLeftPWM > 800 ? 800 : nLeftPWM);
		ftm_pwm_duty(FTM3, FTM_CH2, 0);
		ftm_pwm_duty(FTM3, FTM_CH3, nLeftPWM);

	}

	if (g_nRighPWM < 0)
	{
		nRighPWM = -RighDead - g_nRighPWM;
		nRighPWM = (nRighPWM > 800 ? 800 : nRighPWM);
		ftm_pwm_duty(FTM3, FTM_CH0, nRighPWM);
		ftm_pwm_duty(FTM3, FTM_CH1, 0);
	}
	else
	{
		nRighPWM = RighDead + g_nRighPWM;
		nRighPWM = (nRighPWM > 800 ? 800 : nRighPWM);
		ftm_pwm_duty(FTM3, FTM_CH0, 0);
		ftm_pwm_duty(FTM3, FTM_CH1, nRighPWM);
	}
}


/**
* @file		计算速度偏差
* @note      	产生全局变量g_fSpeedError
* @author     jassy
* @date		2017
*/
void CalSpeedError(void)
{
	static float fSpeedOld = 0, fSpeedNew = 0;

	g_nLeftpulse = -ftm_quad_get(FTM2); //读取左轮脉冲
	ftm_input_clean(FTM2);
	g_nRighpulse = ftm_quad_get(FTM1);
	ftm_input_clean(FTM1);

	g_fLeftRealSpeed = g_nLeftpulse*Ratio_Encoder_Left;
	g_fLeftRealSpeed = (g_fLeftRealSpeed>20000 ? 20000 : g_fLeftRealSpeed);		//滤左编码器的噪声
	g_fRighRealSpeed = g_nRighpulse*Ratio_Encoder_Righ;
	g_fRighRealSpeed = (g_fRighRealSpeed>20000 ? 20000 : g_fRighRealSpeed);		//滤右编码器的噪声

	g_fRealSpeed = (g_fLeftRealSpeed + g_fRighRealSpeed)*0.5;				//真实速度
																			//速度采集梯度平滑，每次采集最大变化200
	fSpeedOld = g_fSpeedFilter;
	fSpeedNew = g_fRealSpeed;

	if (fSpeedNew >= fSpeedOld)
		g_fSpeedFilter = ((fSpeedNew - fSpeedOld)>200 ? (fSpeedOld + 200) : fSpeedNew);
	else
		g_fSpeedFilter = ((fSpeedNew - fSpeedOld)<-200 ? (fSpeedOld - 200) : fSpeedNew);

	g_fSpeedError = g_fExpectSpeed - g_fSpeedFilter;
	//	g_fSpeedError = float04 - g_fSpeedFilter;

	g_fSpeedErrorTemp[4] = g_fSpeedErrorTemp[3];
	g_fSpeedErrorTemp[3] = g_fSpeedErrorTemp[2];
	g_fSpeedErrorTemp[2] = g_fSpeedErrorTemp[1];
	g_fSpeedErrorTemp[1] = g_fSpeedErrorTemp[0];
	g_fSpeedErrorTemp[0] = g_fSpeedError;

}


/**
* @file		速度控制（未用到积分，积分忽略）
* @note      	速度梯度平滑
* @author     jassy
* @date		2017
*/
void SpeedControl(void)
{
	//	static float fSpeedErrorDot = 0;

	CalSpeedError();
	g_fSpeedError = (g_fSpeedError>1600 ? 1600 : g_fSpeedError);//速度偏差限幅
	vcan_send_buff[3] = g_fSpeedError;  //速度偏差
	 //动态期望速度
	 //g_fExpectSpeed = 2900 + g_fSpeedError/5.9;					
	 //g_fExpectSpeed = (g_fExpectSpeed>3100?3100:g_fExpectSpeed);
	 //g_fExpectSpeed = (g_fExpectSpeed<2800?2800:g_fExpectSpeed);

	fSpeedErrorInteg += (g_speedControl_I / 100.0) * g_fSpeedError;
	if (Flag_Stop == 1 | Flag_Speed == 1)fSpeedErrorInteg = 0;		//停车积分清零

	fSpeedErrorInteg = (fSpeedErrorInteg < 0.0 ? 0.0 : fSpeedErrorInteg);//积分下限
	fSpeedErrorInteg = (fSpeedErrorInteg > 50.0 ? 50.0 : fSpeedErrorInteg);//积分上限

	g_fSpeedControlOutOld = g_fSpeedControlOutNew;
	g_fSpeedControlOutNew = g_speedControl_P*g_fSpeedError + fSpeedErrorInteg;
	//	g_fSpeedControlOutNew = float03*g_fSpeedError + fSpeedErrorInteg;
	
}

/**
* @file		速度控制平滑输出
* @note      	分20次输出
* @author     jassy
* @date		2017

*/
void SpeedControlOut(void)
{
	g_fSpeedControlOut = (g_fSpeedControlOutNew - g_fSpeedControlOutOld)*Flag_SpeedControl / 20 +
		g_fSpeedControlOutOld;

}






