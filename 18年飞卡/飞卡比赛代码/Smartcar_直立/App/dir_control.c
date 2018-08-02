#include "include.h"
float DirErr, DirErrLast;
float DirKp = 170, DirKd = 310;
float DirOut;
float DirErrList[10];
int bInCircle = 0.5;
int enCircle = 1;
float Mvalue[4];


float turnKp = 0.3;
extern float RealSpeed;
int theGroung = 100;

int turnNum = 30;
int cirControl = 0;

int timeToCircle = 35;
int timeOutCircle = 100;

extern int ADCFianlly[4];
/*
 @ 作者:邓
 @ 功能介绍 俊奇的获取传感器偏差值
 @ 参数:
 @ 传感器数据数组
*/
float Get_ADC_Err(int *ADC_value)
{
	float g_fDirectionError;
	static float g_fDirectionErrorTemp[5];
	//传感器对应

	//ADC_value[3] ADC_value[2] ADC_value[1] ADC_value[0]
//	//    value[1]    value[3]    value[2]    value[0]
	//       o-----------o-----------o-----------o     
	//                    \         /
	//                     \       /
	//                      \     /

	Mvalue[0] = ADC_value[1];
	Mvalue[1] = ADC_value[3];
	Mvalue[2] = ADC_value[0];
	Mvalue[3] = ADC_value[2];


	//-----------------------圆环重新2次修订版-----------------------------//
	if (enCircle == 1 && cirControl == 1)
	{
		if (((Mvalue[0] + Mvalue[1]) > theGroung * 2) && bInCircle <= 2)//进环条件,说明检查测到圆环
		{
			if ((Mvalue[2] > timeToCircle || Mvalue[3] > timeToCircle) && bInCircle == 0)
			{
				if (Mvalue[2] >= Mvalue[3])//判断进环时机，刚进圆环肯定有一个值很大
				{
					bInCircle = 1;
				}
				else
				{
					bInCircle = 2;
				}
			}
		}
		if (bInCircle == 1)
		{
			if (Mvalue[2] < turnNum)//进环时机
			{
				bInCircle = 4;
			}
		}
		if (bInCircle == 2)
		{
			if (Mvalue[3] < turnNum)//进环时机
			{
				bInCircle = 3;
			}
		}
		if (bInCircle == 3 || bInCircle == 4)
		{
			if (bInCircle == 3)
			{
				Mvalue[1] = 50 + turnKp* RealSpeed;//将转弯和速度关联
				Mvalue[0] = 50 - turnKp* RealSpeed;
				if ((ADC_value[1] < timeOutCircle) && (ADC_value[0] < 10))
				{
					bInCircle = 0;
					enCircle = 0;
				}
			}
			else if (bInCircle == 4)
			{
				Mvalue[0] = 50 + turnKp* RealSpeed;
				Mvalue[1] = 50 - turnKp* RealSpeed;
				if ((ADC_value[0] < timeOutCircle) && (ADC_value[1] < 10))
				{
					bInCircle = 0;
					enCircle = 0;
				}
			}
		}
	}
	if ((Mvalue[0] + Mvalue[1]) > 0)
	{
		g_fDirectionError = (float)(Mvalue[0] - Mvalue[1]) / (Mvalue[0] + Mvalue[1]);//差比和
	}
	else
	{
		g_fDirectionError = 0;
	}
	return g_fDirectionError;
}
void Dir_Control(void)
{
	float DirectionError_dot;
	DirErr = Get_ADC_Err(ADCFianlly);
	DirErrList[0] = DirErrList[1];
	DirErrList[1] = DirErrList[2];
	DirErrList[2] = DirErrList[3];
	DirErrList[3] = DirErrList[4];
	DirErrList[4] = DirErr;
	DirectionError_dot = DirErr - DirErrList[0];
	//微分项限幅，按需加
	//DirectionError_dot = (DirectionError_dot>0.05 ? 0.05 : DirectionError_dot);
	//DirectionError_dot = (DirectionError_dot<-0.05 ? -0.05 : DirectionError_dot);
	DirOut = DirKp * DirErr + DirKd * DirectionError_dot;
}