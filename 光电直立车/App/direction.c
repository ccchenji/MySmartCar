/*!
* @file       direction.c
* @brief      方向部分程序
* @version    v5.2
* @author     Jassy
* @date       2017
*/
#include  "common.h"
#include  "include.h"
#include  "math.h"  


/**********全局变量定义********/
float g_dirControl_P = -5.63;
float g_dirControl_D = -20.53; //1.5;
float g_dirControl_gyro_D = 0;
int16 g_nDirectionError;
int16 g_nDirectionError_last;
float g_fDirectionError_dot;
float g_fDirectionControlOut;
float g_fDirectionControlOut_last;
int16 g_nDirectionError_watch;
int16 g_nDirectionError_watch1;
/**
* @file		方向控制
* @author		jassy
* @date		2017
*/
void DirectionControl(void)
{
	static float g_nDirectionErrorTemp[7];
        int16 ValueOfGyroX = 0;
        float GyroX = 0;
	g_nDirectionError = (int16)get_picture_diff(89, 1);//方向偏差
	g_nDirectionError = (g_nDirectionError >= 50 ? 50 : g_nDirectionError);//限幅
	g_nDirectionError = (g_nDirectionError <= -50 ? -50 : g_nDirectionError);
	vcan_send_buff[5] = g_nDirectionError;
        ValueOfGyroX = MPU3050_GetResult(1, MPU3050_OUT_X_H);
        GyroX = ValueOfGyroX*0.24;
	g_nDirectionErrorTemp[5] = g_nDirectionErrorTemp[4];
	g_nDirectionErrorTemp[4] = g_nDirectionErrorTemp[3];
	g_nDirectionErrorTemp[3] = g_nDirectionErrorTemp[2];
	g_nDirectionErrorTemp[2] = g_nDirectionErrorTemp[1];
	g_nDirectionErrorTemp[1] = g_nDirectionErrorTemp[0];
	g_nDirectionErrorTemp[0] = g_nDirectionError;
	g_fDirectionError_dot = g_nDirectionErrorTemp[0] - g_nDirectionErrorTemp[5];//偏差微分
	g_fDirectionError_dot = (g_fDirectionError_dot>50 ? 50 : g_fDirectionError_dot);//微分限幅
	g_fDirectionError_dot = (g_fDirectionError_dot<-50 ? -50 : g_fDirectionError_dot);

	//关联速度的动态PD
	
// 	if(g_fSpeedFilter<2000)	   {g_dirControl_P =180 ;g_dirControl_D = 300;}
// 	else if(g_fSpeedFilter<2000){g_dirControl_P =220 ;g_dirControl_D = 330;}
// 	else if(g_fSpeedFilter<2100){g_dirControl_P =250 ;g_dirControl_D = 340;}
// 	else if(g_fSpeedFilter<2200){g_dirControl_P =300 ;g_dirControl_D = 360;}
// 	else if(g_fSpeedFilter<2300){g_dirControl_P =320 ;g_dirControl_D = 380;}
// 	else if(g_fSpeedFilter<2400){g_dirControl_P =360 ;g_dirControl_D = 410;}
// 	else if(g_fSpeedFilter<2500){g_dirControl_P =380 ;g_dirControl_D = 430;}
// 	else if(g_fSpeedFilter<2600){g_dirControl_P =410 ;g_dirControl_D = 450;}
// 	else if(g_fSpeedFilter<2700){g_dirControl_P =420 ;g_dirControl_D = 470;}
// 	else if(g_fSpeedFilter<2800){g_dirControl_P =430 ;g_dirControl_D = 500;}
// 	else if(g_fSpeedFilter<2900){g_dirControl_P =440 ;g_dirControl_D = 550;}
// 	else if(g_fSpeedFilter<3000){g_dirControl_P =450 ;g_dirControl_D = 600;}
// 	else if(g_fSpeedFilter>3000){g_dirControl_P =470 ;g_dirControl_D = 750;}
// 	else if(g_fSpeedFilter>3100){g_dirControl_P =470 ;g_dirControl_D = 800;}
	

	g_fDirectionControlOut = g_nDirectionError*g_dirControl_P + g_fDirectionError_dot*g_dirControl_D+GyroX*g_dirControl_gyro_D;//PD转向
	 //	g_fDirectionControlOut = g_nDirectionError*float05 + g_fDirectionError_dot*float06;//PD转向
	
	 g_fDirectionControlOut = (g_fDirectionControlOut > 400? 400: g_fDirectionControlOut);//转向输出限幅
	 g_fDirectionControlOut = (g_fDirectionControlOut < -400? -400: g_fDirectionControlOut);	
	 g_fDirectionControlOut = g_fDirectionControlOut*0.85+ g_fDirectionControlOut_last*0.15;

	 vcan_send_buff[4] = g_fDirectionControlOut;
}

