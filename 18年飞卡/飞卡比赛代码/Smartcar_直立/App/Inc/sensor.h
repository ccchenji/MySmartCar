#ifndef _SENSOR_H_
#define _SENSOR_H_
#include "common.h"

#include "Attitude_Calculation.h"
#include "BMX055.h"
#define  qinghua  0
#define  kaerman  1
#define  MPU3050_USED   //使用3050  
//MPU6050_USED    //使用6050

#ifdef MPU3050_USED
/**********全局变量外部申明********/
extern float g_AngleOfCar;
extern float angle_offset;
extern float AngleSpeed;
extern int AngleAccel;
extern BMX055Datatypedef      BMX055_data;
extern EulerAngleTypedef SystemAttitude, SystemAttitudeRate;
extern AttitudeDatatypedef    GyroOffset;
/**********函数申明********/
void KalmanFilter(void);

typedef enum
{
	GyroY,
	GyroX
}Gyron;

#endif

#endif