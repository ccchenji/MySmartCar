/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2017,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       KEA128_it.c
 * @brief      ɽ��KEA ƽ̨������
 * @author     ɽ��Ƽ�
 * @version    v6.0
 * @date       2017-12-10
 */

 
#include "common.h"
#include "include.h"
#include  "MKEA128_it.h"


unsigned char g_nKeyValue = 0;
unsigned char TimeSlice_Flag = 0;    //1msʱ��Ƭ�ηָ�
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
EulerAngleTypedef      SystemAttitude;            /////��̬��
EulerAngleTypedef      SystemAttitudeRate;        /////��̬���ٶ�
AttitudeDatatypedef    GyroOffset;

float AccZAngle = 0;
float QZAngle = 0;
 /*!
 *  @brief      PIT0�жϴ�����
 *  @param      none
 *  @return     none
 *  @date       2018-03-29
 */
void pit_ch0_irq(void)
{
		static uint8 MAGcnt= 0;
		static uint8 IsAttitudeinit = 0;
		//====================================�ɼ��ӽ��� 1.3ms================================
		//====================================�ɼ�380us======================================
		led(LED0, LED_ON);             
		//TimeSlice_Flag++;
		//if (TimeSlice_Flag > 5)TimeSlice_Flag = 1;  //5��Ƭ����ѯ
		MAGcnt++;
		if (MAGcnt < 15)
		{
			BMX055_DataRead(&BMX055_data, 0);
		}
		else
		{
			BMX055_DataRead(&BMX055_data, 1);
		}
                
		
		//====================================�ɼ�380us======================================
		led(LED0, LED_OFF);
		BMX055_data.GYROXdata = (BMX055_data.GYROXdata - 0) * 0.030517578;
		BMX055_data.GYROYdata = (BMX055_data.GYROYdata - 0) * 0.030517578;
		BMX055_data.GYROZdata = (BMX055_data.GYROZdata - 0) * 0.030517578;
		///////1000 / 32768     //////BMX055������Ʈ�������Ժ��Բ��ƣ����ǰ�ȫ������ǽ���һ��
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
		var[2] = BMX055_data.ACCZdata;   //���ٶȼ�ֵ 

		if (IsAttitudeinit == 0)
		{
			Quaternion_init();                    //��̬�����ʼ��        
			IsAttitudeinit = 1;
		}
		else
		{
			Attitude_UpdateGyro();                /////���ٸ���
			Attitude_UpdateAcc();                 /////����ںϸ���
			SystemAttitude.Pitch = -EulerAngle.Roll / PI * 180;         //תΪ�Ƕ�
			SystemAttitude.Roll = EulerAngle.Pitch / PI * 180;
			SystemAttitude.Yaw = EulerAngle.Yaw / PI * 180;
			SystemAttitudeRate.Pitch = -EulerAngleRate.Roll / PI * 180;  //ֱ��
			SystemAttitudeRate.Yaw = EulerAngleRate.Yaw / PI * 180;   //���� 
			/////Ϊ�˸���׼�Ļ�ø����ǣ��ٴν��л����˲�

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
		
		//====================================�ɼ��ӽ��� 1.3ms================================
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



	PIT_Flag_Clear(PIT0);       //���жϱ�־λ
}
/*!
*  @brief      PIT1�жϴ�����
*  @param      none
*  @return     none
*  @date       2018-03-29
*/
void pit_ch1_irq(void)
{

	//led(LED0, LED_ON);
	//====================================================
	g_nKeyValue = key_scan();
	SOLGUI_InputKey(g_nKeyValue);//����GUI 
	SOLGUI_Menu_PageStage();
	SOLGUI_Refresh(); //OLEDǰ̨ˢ��	
	//========================15ms========================
	//led(LED0, LED_OFF);
	PIT_Flag_Clear(PIT1);       //���жϱ�־λ      

}

