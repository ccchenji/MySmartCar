#include "include.h"
#include "motor_control.h"

int16 LeftMotorPulseSigma = 0;          //左边电机计数信号
int16 RightMotorPulseSigma = 0;         //右边电机计数信号


/*!
*  @brief  右边电机控制
*  @param  int32 speed 占空比设置
*  @date   2016-12-05
*  @revision
*  @note   CH2、CH3
*/
void Right_Motor_Control(int32 speed)
{
	if (speed > Motor_speed_Max)           //限幅处理
		speed = Motor_speed_Max;
	if (speed < Motor_speed_Min)
		speed = Motor_speed_Min;

	if (speed >= 0)                        //方向控制
	{
		ftm_pwm_duty(FTM2, FTM_CH2, 0);
		ftm_pwm_duty(FTM2, FTM_CH3, speed);
	}
	if (speed < 0)
	{
		ftm_pwm_duty(FTM2, FTM_CH2, (-speed));
		ftm_pwm_duty(FTM2, FTM_CH3, 0);
	}
}

/*!
*  @brief  左边电机控制
*  @param  int32 speed 占空比设置
*  @date   2016-12-05
*  @revision
*  @note   CH0、CH1
*/
void Left_Motor_Control(int32 speed)
{
	if (speed > Motor_speed_Max)           //限幅处理
		speed = Motor_speed_Max;
	if (speed < Motor_speed_Min)
		speed = Motor_speed_Min;

	if (speed >= 0)                        //方向控制
	{
		ftm_pwm_duty(FTM2, FTM_CH1, 0);
		ftm_pwm_duty(FTM2, FTM_CH0, speed);
	}
	if (speed < 0)
	{
		ftm_pwm_duty(FTM2, FTM_CH1, (-speed));
		ftm_pwm_duty(FTM2, FTM_CH0, 0);
	}
}
