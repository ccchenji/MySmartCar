/*
				 ██████╗ █████╗ ██╗   ██╗ ██████╗
				██╔════╝██╔══██╗██║   ██║██╔════╝
				██║     ███████║██║   ██║██║
				██║     ██╔══██║██║   ██║██║
				╚██████╗██║  ██║╚██████╔╝╚██████╗
				 ╚═════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝

*/

/*!
* @file       sensor.c
* @brief      传感器控制
* @author     JassyLiu
* @date       2016-12-05
* @revision
* @note
*/
#include "common.h"
#include "include.h"
#include "sensor.h"
#include  "math.h"						 
/*         变量定义         */
float AngleSpeed = 0;//车角速度
int offset_AngleSpeed = 0;
float g_AngleOfCar;//车角度
BMX055Datatypedef      BMX055_data;

EulerAngleTypedef      SystemAttitude;            /////姿态角
EulerAngleTypedef      SystemAttitudeRate;        /////姿态角速度
AttitudeDatatypedef    GyroOffset;

int AngleAccel = 0;
int offset_AngleAccel = 0;
//非矩阵卡尔曼滤波
float Peried = 1 / 200.0;
float KalmanGain = 1.0;//卡尔曼增益
float Q = 10; //2.0;//过程噪声2.0		越小积分越慢，跟踪加速度计越慢越平滑
float R = 2000;//5000.0;//测量噪声5000.0	越小跟踪加速度计越快


float angle_offset=-11.5;//角度偏置
/*
			  Z轴
				\ ↗
			↖	 \
	  X轴一一一一一@
			↗    |
				↘|↗
				  |
				 Y轴
*/
/**
* @file			非矩阵卡尔曼滤波
* @note      	输入角速度g_fAngleSpeed[0]，角度g_fAngleOfAcce
* @note      	得到全局变量g_AngleOfCar
* @date
*/
void KalmanFilter(void)
{
	//卡尔曼滤波局部参量
	static float Priori_Estimation = 0;//先验估计
	static float Posterior_Estimation = 0;//后验估计
	static float Priori_Convariance = 0;//先验方差
	static float Posterior_Convariance = 0;//后验方差
	AngleSpeed = mpu_gyro_x - offset_AngleSpeed;
	AngleAccel = mpu_acc_y - offset_AngleAccel;
	//卡尔曼滤波
	//1.时间更新(预测) : X(k|k-1) = A(k,k-1)*X(k-1|k-1) + B(k)*u(k) 
	Priori_Estimation = Posterior_Estimation + AngleSpeed * Peried;		//先验估计，积分获得角度
	//2.更新先验协方差  : P(k|k-1) = A(k,k-1)*P(k-1|k-1)*A(k,k-1)'+Q(k) 
	Priori_Convariance = (float)sqrt(Posterior_Convariance * Posterior_Convariance + Q * Q);
	//  卡尔曼后验估计：测量更新  
	// 1.计算卡尔曼增益  : K(k) = P(k|k-1)*H(k)' / (H(k)*P(k|k-1)*H(k)' + R(k)) /
	KalmanGain = (float)sqrt(Priori_Convariance * Priori_Convariance / (Priori_Convariance * Priori_Convariance + R * R));
	//2.测量更新(校正): X(k|k) = X(k|k-1)+K(k)*(Z(k)-H(k)*X(k|k-1)) 

	//vcan_send_buff[1] = AngleAccel;

	Posterior_Estimation = Priori_Estimation + KalmanGain * (AngleAccel - Priori_Estimation);
	// 3.更新后验协方差  : P(k|k) =（I-K(k)*H(k)）*P(k|k-1) 
	Posterior_Convariance = (float)sqrt((1 - KalmanGain) * Priori_Convariance * Priori_Convariance);
	//得到最终角度 
	g_AngleOfCar = Posterior_Estimation + angle_offset;
	//vcan_send_buff[2] = Posterior_Estimation;
        vcan_send_buff[3] = AngleSpeed;
}



