
#include "include.h"
//外环参数
float Balance_Kp = 75;//75
float Balance_Kd = 3;
float Balance_Out = 0;
//内环参数（已弃用）
float Balance_Inside_Kp = 0;
float Balance_Inside_Kd = 0;
float Balance_Inside_Out = 0;
float Balance_Err, Balance_LastErr, Balance_Inside_Err, Balance_Inside_LastErr;
float AngleSpeed_Old;
float g_upstandControl_PWMTemp[5];


float AccZAngle = 0, QZAngle = 0;
/**
* @file			平衡控制的PD计算
* @note      	得到全局变量g_BlanceControlOut
* @author		Jassy
* @date			2017
*/
void BalanceControl(void)
{
	float fPWM = ((g_AngleOfCar * Balance_Kp) + (AngleSpeed * Balance_Kd));
	g_upstandControl_PWMTemp[4] = g_upstandControl_PWMTemp[3];
	g_upstandControl_PWMTemp[3] = g_upstandControl_PWMTemp[2];
	g_upstandControl_PWMTemp[2] = g_upstandControl_PWMTemp[1];
	g_upstandControl_PWMTemp[1] = g_upstandControl_PWMTemp[0];
	g_upstandControl_PWMTemp[0] = fPWM;
	Balance_Out = fPWM;
}
/*
 @ 作者:邓
 @ 功能介绍 俊奇的获取角度函数
 @ 参数:
 @ null
*/
void GetAngle()
{
	static int IsAttitudeinit = 0;//初始化标志
	static int MAGcnt = 0;
	MAGcnt++;
	if (MAGcnt < 15)
	{
		BMX055_DataRead(&BMX055_data, 0);
	}
	else
	{
		BMX055_DataRead(&BMX055_data, 1);
	}
	BMX055_data.GYROXdata = (BMX055_data.GYROXdata - 0) * 0.030517578;
	BMX055_data.GYROYdata = (BMX055_data.GYROYdata - 0) * 0.030517578;
	BMX055_data.GYROZdata = (BMX055_data.GYROZdata - 0) * 0.030517578;

	BMX055_data.ACCXdata *= 0.001953125;    ///////4 / 2048
	BMX055_data.ACCYdata *= 0.001953125;
	BMX055_data.ACCZdata *= 0.001953125;

	Acc.Xdata = BMX055_data.ACCXdata;
	Acc.Ydata = BMX055_data.ACCYdata;
	Acc.Zdata = BMX055_data.ACCZdata;
	Gyro.Xdata = BMX055_data.GYROXdata;
	Gyro.Ydata = BMX055_data.GYROYdata;
	Gyro.Zdata = BMX055_data.GYROZdata;

	if (IsAttitudeinit == 0)//初始化标志
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
		g_AngleOfCar = SystemAttitude.Pitch + angle_offset;
		AngleSpeed = SystemAttitudeRate.Pitch;
	}
}