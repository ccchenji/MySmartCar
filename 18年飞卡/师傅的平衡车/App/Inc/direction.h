#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include  "common.h"
#include  "include.h"

/**********全局变量外部申明********/
extern float g_dirControl_P;
extern float g_dirControl_D;
extern float g_fDirectionError;
extern float g_fDirectionError_dot;
extern float g_fDirectionControlOut;
extern int16 g_ValueOfAD[4];




/***********函数声明***********/

void DirectionControl(void);


void Read_ADC(void);



#endif
