
#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include  "common.h"



/**********ȫ�ֱ����ⲿ����********/
extern float g_dirControl_P;
extern float g_dirControl_D;
extern int16 g_nDirectionError;
extern float g_fDirectionError_dot;
extern float g_fDirectionControlOut;
extern float g_dirControl_gyro_D;


/***********��������***********/

void DirectionControl(void);
void OffsetGyroX();
void GalAngleSpeedX(void);
void GetDirControl_PD(float speed, float SpeedError, float dir, float dir_dt);


#endif