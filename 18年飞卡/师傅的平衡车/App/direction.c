#include "direction.h"

/**********全局变量定义********/
float g_dirControl_P = 190;
float g_dirControl_D = 300;
float g_fDirectionError;
float g_fDirectionError_dot;
float g_fDirectionControlOut;
int16 g_ValueOfAD[4] = { 0 };

extern char Flag_Stop;
void DirectionControl(void)
{
	static float g_fDirectionErrorTemp[5];

	Read_ADC();


	g_ValueOfAD[0] = (g_ValueOfAD[0] < 2 ? 2 : g_ValueOfAD[0]);
	g_ValueOfAD[1] = (g_ValueOfAD[1] < 2 ? 2 : g_ValueOfAD[1]);
	g_ValueOfAD[2] = (g_ValueOfAD[2] < 2 ? 2 : g_ValueOfAD[2]);
	g_ValueOfAD[3] = (g_ValueOfAD[3] < 2 ? 2 : g_ValueOfAD[3]);
	if (g_ValueOfAD[0]<10 && g_ValueOfAD[1]<10&&g_ValueOfAD[2]<10 && g_ValueOfAD[3]<10)Flag_Stop = 0;//冲出赛道保护

	g_fDirectionError = (float)(g_ValueOfAD[0] - g_ValueOfAD[1]) / (g_ValueOfAD[0] + g_ValueOfAD[1]);//差比和
	g_fDirectionError = (g_fDirectionError >= 1 ? 1 : g_fDirectionError);//差比和限幅
	g_fDirectionError = (g_fDirectionError <= -1 ? -1 : g_fDirectionError);

	g_fDirectionErrorTemp[4] = g_fDirectionErrorTemp[3];
	g_fDirectionErrorTemp[3] = g_fDirectionErrorTemp[2];
	g_fDirectionErrorTemp[2] = g_fDirectionErrorTemp[1];
	g_fDirectionErrorTemp[1] = g_fDirectionErrorTemp[0];
	g_fDirectionErrorTemp[0] = g_fDirectionError;
	g_fDirectionError_dot = 1500 * (g_fDirectionErrorTemp[0] - g_fDirectionErrorTemp[3]);//偏差微分
	g_fDirectionError_dot = (g_fDirectionError_dot>65 ? 65 : g_fDirectionError_dot);//微分限幅
	g_fDirectionError_dot = (g_fDirectionError_dot<-65 ? -65 : g_fDirectionError_dot);

	//关联速度的动态PD
	//if (g_fSpeedFilter<2000) { g_dirControl_P = 180; g_dirControl_D = 300; }
	//else if (g_fSpeedFilter<2000) { g_dirControl_P = 220; g_dirControl_D = 330; }
	//else if (g_fSpeedFilter<2100) { g_dirControl_P = 250; g_dirControl_D = 340; }
	//else if (g_fSpeedFilter<2200) { g_dirControl_P = 300; g_dirControl_D = 360; }
	//else if (g_fSpeedFilter<2300) { g_dirControl_P = 320; g_dirControl_D = 380; }
	//else if (g_fSpeedFilter<2400) { g_dirControl_P = 360; g_dirControl_D = 410; }
	//else if (g_fSpeedFilter<2500) { g_dirControl_P = 380; g_dirControl_D = 430; }
	//else if (g_fSpeedFilter<2600) { g_dirControl_P = 410; g_dirControl_D = 450; }
	//else if (g_fSpeedFilter<2700) { g_dirControl_P = 420; g_dirControl_D = 470; }
	//else if (g_fSpeedFilter<2800) { g_dirControl_P = 430; g_dirControl_D = 500; }
	//else if (g_fSpeedFilter<2900) { g_dirControl_P = 440; g_dirControl_D = 550; }
	//else if (g_fSpeedFilter<3000) { g_dirControl_P = 450; g_dirControl_D = 600; }
	//else if (g_fSpeedFilter>3000) { g_dirControl_P = 470; g_dirControl_D = 750; }
	//else if (g_fSpeedFilter>3100) { g_dirControl_P = 470; g_dirControl_D = 800; }
	//g_dirControl_P =400 ;g_dirControl_D = 450;

	g_fDirectionControlOut = g_fDirectionError * g_dirControl_P + g_fDirectionError_dot * (g_dirControl_D / 100.0);//PD转向

	g_fDirectionControlOut = (g_fDirectionControlOut > 350 ? 350 : g_fDirectionControlOut);//转向输出限幅
	g_fDirectionControlOut = (g_fDirectionControlOut < -350 ? -350 : g_fDirectionControlOut);
}



void Read_ADC(void)
{
	int16  i, j, k, temp;
	int16  ad_valu[4][5], ad_valu1[4], ad_sum[4];
	static int16 ad_valu1_temp[4][5] = { 0 };

	//AD_Value0 = adc_once(ADC0_SE12, ADC_10bit);
	//AD_Value1 = adc_once(ADC0_SE13, ADC_10bit);
	//AD_Value2 = adc_once(ADC0_SE14, ADC_10bit);
	//AD_Value3 = adc_once(ADC0_SE15, ADC_10bit);
	for (i = 0; i<5; i++)
	{
		ad_valu[0][i] = ad_ave(ADC0_SE15, ADC_12bit, 5);  			// AD1水平左
		ad_valu[1][i] = ad_ave(ADC0_SE13, ADC_12bit, 5);     		// AD2水平右
		ad_valu[2][i] = ad_ave(ADC0_SE12, ADC_12bit, 5);  			// AD1水平左
		ad_valu[3][i] = ad_ave(ADC0_SE14, ADC_12bit, 5);     		// AD2水平右
	}
	/*=========================冒泡排序升序==========================*/
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			for (k = 0; k<4 - j; k++)
			{
				if (ad_valu[i][k] > ad_valu[i][k + 1])        //前面的比后面的大  则进行交换
				{
					temp = ad_valu[i][k + 1];
					ad_valu[i][k + 1] = ad_valu[i][k];
					ad_valu[i][k] = temp;
				}
			}
		}
	}
	/*===========================中值滤波=================================*/
	for (i = 0; i<4; i++)    //求中间三项的和
	{
		ad_sum[i] = ad_valu[i][1] + ad_valu[i][2] + ad_valu[i][3];
		ad_valu1[i] = ad_sum[i] / 3;
	}
	/*============================滑动平均滤波============================= */

	for (i = 0; i<4; i++)
	{
		ad_valu1_temp[i][4] = ad_valu1_temp[i][3];
		ad_valu1_temp[i][3] = ad_valu1_temp[i][2];
		ad_valu1_temp[i][2] = ad_valu1_temp[i][1];
		ad_valu1_temp[i][1] = ad_valu1_temp[i][0];
		ad_valu1_temp[i][0] = ad_valu1[i];
	}

	for (i = 0; i<4; i++)
	{
		g_ValueOfAD[i] = (int16)(ad_valu1_temp[i][0]);
		g_ValueOfAD[i] = (int16)(ad_valu1_temp[i][0] / 10);
		g_ValueOfAD[i] = g_ValueOfAD[i] * 10;
	}
}





