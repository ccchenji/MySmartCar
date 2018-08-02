/*
				 ██████╗ █████╗ ██╗   ██╗ ██████╗                   
				██╔════╝██╔══██╗██║   ██║██╔════╝                   
				██║     ███████║██║   ██║██║                        
				██║     ██╔══██║██║   ██║██║                        
				╚██████╗██║  ██║╚██████╔╝╚██████╗                   
				 ╚═════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝                   
																	
*/ 
/*!
* @file       moror_control.c
* @brief      电机控制
* @author     JassyLiu
* @date       2016-12-05
* @revision   
* @note 
*/

#include "common.h"
#include "include.h"
#include "motor_control.h"

int16 LeftMotorPulseSigma = 0;          //左边电机计数信号
int16 RightMotorPulseSigma = 0;         //右边电机计数信号

/*!
*  @brief     
*  @param     
*  @date   2016-12-05
*  @revision
*  @note
*/
/*!
*  @brief  初始化PWM通道
*  @date   2016-12-05
*  @revision
*  @note   占空比精度在ftm.h里修改
*/
void Motor_PWM_init(void)
{
	/* 初始化左电机PWM通道 */
	ftm_pwm_init(FTM3, FTM_CH0, 10 * 1000, 0);   
	ftm_pwm_init(FTM3, FTM_CH1, 10 * 1000, 0);       
	/* 初始化右电机PWM通道 */
	ftm_pwm_init(FTM3, FTM_CH2, 10 * 1000, 0);   
	ftm_pwm_init(FTM3, FTM_CH3, 10 * 1000, 0);    
}

/*!
*  @brief  右边电机控制
*  @param  int32 speed 占空比设置
*  @date   2016-12-05
*  @revision 
*  @note
*/
void Right_Motor_Control(int32 speed)
{
	if (speed > Motor_speed_Max)           //限幅处理
		speed = Motor_speed_Max;
	if (speed < Motor_speed_Min)
		speed = Motor_speed_Min;

	if (speed >= 0)                        //方向控制
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
*  @brief  左边电机控制
*  @param  int32 speed 占空比设置
*  @date   2016-12-05
*  @revision
*  @note
*/
void Left_Motor_Control(int32 speed)
{
	if (speed > Motor_speed_Max)           //限幅处理
		speed = Motor_speed_Max;
	if (speed < Motor_speed_Min)
		speed = Motor_speed_Min;

	if (speed >= 0)                        //方向控制
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
*  @brief  正交解码初始化
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
*  @brief  获取正交解码脉冲数 
*  @param 
*  @date   2016-12-05
*  @revision
*  @note  参数记录在全局变量 LeftMotorPulseSigma&RightMotorPulseSigma
*/
void GetMotorPulse(void)
{

	LeftMotorPulseSigma = 0-ftm_quad_get(FTM2);  //获取FTM 正交解码 的脉冲数(负数表示反方向)
	ftm_quad_clean(FTM2);
	RightMotorPulseSigma = ftm_quad_get(FTM1); //获取FTM 正交解码 的脉冲数(负数表示反方向)
	ftm_quad_clean(FTM1);
}
