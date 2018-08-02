/*
				 �������������[ �����������[ �����[   �����[ �������������[                   
				�����X�T�T�T�T�a�����X�T�T�����[�����U   �����U�����X�T�T�T�T�a                   
				�����U     ���������������U�����U   �����U�����U                        
				�����U     �����X�T�T�����U�����U   �����U�����U                        
				�^�������������[�����U  �����U�^�������������X�a�^�������������[                   
				 �^�T�T�T�T�T�a�^�T�a  �^�T�a �^�T�T�T�T�T�a  �^�T�T�T�T�T�a                   
																	
*/ 
/*!
* @file       moror_control.c
* @brief      �������
* @author     JassyLiu
* @date       2016-12-05
* @revision   
* @note 
*/

#include "common.h"
#include "include.h"
#include "motor_control.h"

int16 LeftMotorPulseSigma = 0;          //��ߵ�������ź�
int16 RightMotorPulseSigma = 0;         //�ұߵ�������ź�

/*!
*  @brief     
*  @param     
*  @date   2016-12-05
*  @revision
*  @note
*/
/*!
*  @brief  ��ʼ��PWMͨ��
*  @date   2016-12-05
*  @revision
*  @note   ռ�ձȾ�����ftm.h���޸�
*/
void Motor_PWM_init(void)
{
	/* ��ʼ������PWMͨ�� */
	ftm_pwm_init(FTM3, FTM_CH0, 10 * 1000, 0);   
	ftm_pwm_init(FTM3, FTM_CH1, 10 * 1000, 0);       
	/* ��ʼ���ҵ��PWMͨ�� */
	ftm_pwm_init(FTM3, FTM_CH2, 10 * 1000, 0);   
	ftm_pwm_init(FTM3, FTM_CH3, 10 * 1000, 0);    
}

/*!
*  @brief  �ұߵ������
*  @param  int32 speed ռ�ձ�����
*  @date   2016-12-05
*  @revision 
*  @note
*/
void Right_Motor_Control(int32 speed)
{
	if (speed > Motor_speed_Max)           //�޷�����
		speed = Motor_speed_Max;
	if (speed < Motor_speed_Min)
		speed = Motor_speed_Min;

	if (speed >= 0)                        //�������
	{
		ftm_pwm_duty(FTM3, FTM_CH0, 0);
		ftm_pwm_duty(FTM3, FTM_CH1, speed);
	}
	if (speed < 0)
	{
		ftm_pwm_duty(FTM3, FTM_CH0, (-speed));
		ftm_pwm_duty(FTM3, FTM_CH1, 0);
	}
}

/*!
*  @brief  ��ߵ������
*  @param  int32 speed ռ�ձ�����
*  @date   2016-12-05
*  @revision
*  @note
*/
void Left_Motor_Control(int32 speed)
{
	if (speed > Motor_speed_Max)           //�޷�����
		speed = Motor_speed_Max;
	if (speed < Motor_speed_Min)
		speed = Motor_speed_Min;

	if (speed >= 0)                        //�������
	{
		ftm_pwm_duty(FTM3, FTM_CH2, 0);
		ftm_pwm_duty(FTM3, FTM_CH3, speed);
	}
	if (speed < 0)
	{
		ftm_pwm_duty(FTM3, FTM_CH2, (-speed));
		ftm_pwm_duty(FTM3, FTM_CH3, 0);
	}
}

/*!
*  @brief  ���������ʼ��
*  @param  
*  @date   2016-12-05
*  @revision
*  @note
*/
void Encoder_Init(void)
{
	ftm_quad_init(FTM1);		//PTA12 PTA13
	ftm_quad_init(FTM2);		//PTA10 PTA11

}

/*!
*  @brief  ��ȡ�������������� 
*  @param 
*  @date   2016-12-05
*  @revision
*  @note  ������¼��ȫ�ֱ��� LeftMotorPulseSigma&RightMotorPulseSigma
*/
void GetMotorPulse(void)
{

	LeftMotorPulseSigma = 0-ftm_quad_get(FTM2);  //��ȡFTM �������� ��������(������ʾ������)
	ftm_quad_clean(FTM2);
	RightMotorPulseSigma = ftm_quad_get(FTM1); //��ȡFTM �������� ��������(������ʾ������)
	ftm_quad_clean(FTM1);
}
