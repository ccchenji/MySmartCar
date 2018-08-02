#ifndef __SPEED_H__
#define __SPEED_H__

#include  "common.h"



/**********ȫ�ֱ����ⲿ����********/
extern int32 g_nLeftpulse;
extern int32 g_nRighpulse;
extern float g_fSpeedError;
extern float g_fRealSpeed;
extern float g_fLeftRealSpeed;
extern float g_fRighRealSpeed;
extern float g_fSpeedFilter;
extern float fSpeedErrorInteg;
extern float g_fSpeedControlOut;
extern float g_PWMOut;
extern int32 g_nLeftPWM, g_nRighPWM;
extern float g_speedControl_P;		//���ٱ���
extern float g_speedControl_I;		//λ�Ʊ���
extern float g_fExpectSpeed;

/***********��������***********/
void MotorInit(void);
void PWMOut(void);
void CalSpeedError(void);
void SpeedControl(void);
void SpeedControlOut(void);


#endif