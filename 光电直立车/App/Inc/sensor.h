#ifndef _SENSOR_H_
#define _SENSOR_H_
#include "common.h"
#define  qinghua  0
#define  kaerman  1
#define  MPU3050_USED   //使用3050  
//MPU6050_USED    //使用6050

#ifdef MPU3050_USED
/**********全局变量外部申明********/
extern int16 Offset_Acce;
extern int32 g_nValueOfAcce;
extern float g_fAngleOfAcce;
extern int32 g_nValueOfGyro[2];
extern float Raito_Gyro[2];
extern float Offset_Gyro[2];
extern float g_fAngleSpeed[2];
extern float g_fAngleOfGyro[2];
extern float g_AngleOfCar;
extern float g_BlanceControlOut;
extern float g_upstandControl_P;
extern float g_upstandControl_D;
extern float angle_offset;


/**********函数申明********/
void UpstandInit(void);
void GalAcceAndGyroY(void);
void CalAngleOfGyro(void);
void BalanceControl(void);
void OffsetGyroY();
void KalmanFilter(void);

typedef enum
{
	GyroY,
	GyroX
}Gyron;

#endif

#endif