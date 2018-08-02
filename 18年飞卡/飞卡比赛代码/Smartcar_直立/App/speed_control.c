#include "speed_control.h"
#include"include.h"

/**
* @file		计算速度偏差
* @note      	产生全局变量g_fSpeedError
* @author     jassy
* @date		2017
*/
float RealSpeed = 0;
float ExpectSpeed = 80;
float SpeedErr = 0;
float SpeedErrorTemp[5];
float SpeedOut = 0;
float SpeedOutNew = 0;
float SpeedOutOld = 0;
float Speed_Kp = 20;
int Flag_SpeedControl = 0;



float Speed_Ki = 0.1;
float Speed_I = 0;

/*
 @ 作者:邓
 @ 功能介绍 计算速度偏差
 @ 参数:
 @ null
*/
void CalSpeedError(void)
{ 
	static float speed_old = 0, speed_filter = 0;
	const float speed_new = (motorEncorderL + motorEncorderR)*0.5;
	RealSpeed = speed_new;														//真实速度
	speed_old = speed_filter;

	//限制变化速率
	if (speed_new >= speed_old)
		speed_filter = ((speed_new - speed_old) > 10 ? (speed_old + 10) : speed_new);
	else
		speed_filter = ((speed_new - speed_old) < -10 ? (speed_old - 10) : speed_new);


	SpeedErr = ExpectSpeed - RealSpeed;

	SpeedErrorTemp[4] = SpeedErrorTemp[3];
	SpeedErrorTemp[3] = SpeedErrorTemp[2];
	SpeedErrorTemp[2] = SpeedErrorTemp[1];
	SpeedErrorTemp[1] = SpeedErrorTemp[0];
	SpeedErrorTemp[0] = SpeedErr;
}

/**
* @file		速度控制
* @note      	速度梯度平滑
* @author     jassy
* @date		2017
*/
void SpeedControl(void)
{
	//	static float fSpeedErrorDot = 0;
	CalSpeedError();

	if (SpeedErr > 0)
		SpeedErr = (SpeedErr > 10 ? 10 : SpeedErr);//速度偏差限幅
	else
		SpeedErr = (SpeedErr < -10 ? -10 : SpeedErr);//速度偏差限幅
	vcan_send_buff[3] = SpeedErr;
	SpeedOutOld = SpeedOutNew;
	SpeedOutNew = Speed_Kp * SpeedErr;
}
/*
 @ 作者:邓
 @ 功能介绍 速度平滑控制，一次速度输出分为10次变化
 @ 参数:
 @ null
*/
void SpeedControlOut(void)
{
	SpeedOut = (SpeedOutNew - SpeedOutOld)*Flag_SpeedControl / 10 +
		SpeedOutOld;
}