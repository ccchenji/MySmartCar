/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2017,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       KEA128_it.c
 * @brief      山外KEA 平台主程序
 * @author     山外科技
 * @version    v6.0
 * @date       2017-12-10
 */

 
#include "common.h"
#include "include.h"
#include  "MKEA128_it.h"


unsigned char g_nKeyValue = 0;
unsigned char TimeSlice_Flag = 0;    //1ms时间片段分割
unsigned char SpeedControl_Flag = 0;

extern uint16 AD_Value0;
extern uint16 AD_Value1;
extern uint16 AD_Value2;
extern uint16 AD_Value3;

BNO055EulerData EularValue;
extern float var[8];
BNO055LinAccData LinAccValue;
BNO055QuaData QuaValue;

BMX055Datatypedef      BMX055_data;
EulerAngleTypedef      SystemAttitude;            /////姿态角
EulerAngleTypedef      SystemAttitudeRate;        /////姿态角速度
AttitudeDatatypedef    GyroOffset;

float AccZAngle = 0;
float QZAngle = 0;
 /*!
 *  @brief      PIT0中断处理函数
 *  @param      none
 *  @return     none
 *  @date       2018-03-29
 */
void pit_ch0_irq(void)
{
		static uint8 MAGcnt= 0;
		static uint8 IsAttitudeinit = 0;
		//====================================采集加解算 1.3ms================================
		//====================================采集380us======================================
		led(LED0, LED_ON);             
		//TimeSlice_Flag++;
		//if (TimeSlice_Flag > 5)TimeSlice_Flag = 1;  //5次片段轮询
		MAGcnt++;
		if (MAGcnt < 15)
		{
			BMX055_DataRead(&BMX055_data, 0);
		}
		else
		{
			BMX055_DataRead(&BMX055_data, 1);
		}
                
		
		//====================================采集380us======================================
		led(LED0, LED_OFF);
		BMX055_data.GYROXdata = (BMX055_data.GYROXdata - 0) * 0.030517578;
		BMX055_data.GYROYdata = (BMX055_data.GYROYdata - 0) * 0.030517578;
		BMX055_data.GYROZdata = (BMX055_data.GYROZdata - 0) * 0.030517578;
		///////1000 / 32768     //////BMX055本身零飘几乎可以忽略不计，但是安全起见还是矫正一下
		BMX055_data.ACCXdata *= 0.001953125;    ///////4 / 2048
		BMX055_data.ACCYdata *= 0.001953125;
		BMX055_data.ACCZdata *= 0.001953125;

		Acc.Xdata = BMX055_data.ACCXdata;
		Acc.Ydata = BMX055_data.ACCYdata;
		Acc.Zdata = BMX055_data.ACCZdata;
		Gyro.Xdata = BMX055_data.GYROXdata;
		Gyro.Ydata = BMX055_data.GYROYdata;
		Gyro.Zdata = BMX055_data.GYROZdata;
                
        var[0] = BMX055_data.ACCXdata;	
		var[1] = BMX055_data.ACCYdata;
		var[2] = BMX055_data.ACCZdata;   //加速度计值 

		if (IsAttitudeinit == 0)
		{
			Quaternion_init();                    //姿态解算初始化        
			IsAttitudeinit = 1;
		}
		else
		{
			Attitude_UpdateGyro();                /////快速更新
			Attitude_UpdateAcc();                 /////深度融合更新
			SystemAttitude.Pitch = -EulerAngle.Roll / PI * 180;         //转为角度
			SystemAttitude.Roll = EulerAngle.Pitch / PI * 180;
			SystemAttitude.Yaw = EulerAngle.Yaw / PI * 180;
			SystemAttitudeRate.Pitch = -EulerAngleRate.Roll / PI * 180;  //直立
			SystemAttitudeRate.Yaw = EulerAngleRate.Yaw / PI * 180;   //方向 
			/////为了更精准的获得俯仰角，再次进行互补滤波

			float AccZ = 0, AccZAdjust = 0;
			AccZ = -Acc.Zdata;
			if (AccZ > 1)
				AccZ = 1;
			if (AccZ < -1)
				AccZ = -1;
			AccZAngle = asinf(AccZ) * 180 / PI;
			QZAngle = SystemAttitude.Pitch;
			AccZAdjust = (AccZAngle - SystemAttitude.Pitch);
			SystemAttitude.Pitch += (-Gyro.Xdata + AccZAdjust) * PERIODS;
		}
		var[3] = AccZAngle;
		var[4] = SystemAttitude.Pitch;
		var[5] = SystemAttitudeRate.Pitch;
		
		//====================================采集加解算 1.3ms================================
		AD_Value0 = adc_once(ADC0_SE12, ADC_10bit);
		AD_Value1 = adc_once(ADC0_SE13, ADC_10bit);
		AD_Value2 = adc_once(ADC0_SE14, ADC_10bit);
		AD_Value3 = adc_once(ADC0_SE15, ADC_10bit);
		BalanceControl();
		DirectionControl();

		SpeedControl_Flag++;
		if (SpeedControl_Flag >= 20)
		{
			SpeedControl();
			SpeedControl_Flag = 0;
		}
		SpeedControlOut();
		PWMOut();



	PIT_Flag_Clear(PIT0);       //清中断标志位
}
/*!
*  @brief      PIT1中断处理函数
*  @param      none
*  @return     none
*  @date       2018-03-29
*/
void pit_ch1_irq(void)
{

	//led(LED0, LED_ON);
	//====================================================
	g_nKeyValue = key_scan();
	SOLGUI_InputKey(g_nKeyValue);//传入GUI 
	SOLGUI_Menu_PageStage();
	SOLGUI_Refresh(); //OLED前台刷新	
	//========================15ms========================
	//led(LED0, LED_OFF);
	PIT_Flag_Clear(PIT1);       //清中断标志位      

}

