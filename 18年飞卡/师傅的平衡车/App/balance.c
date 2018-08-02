/*!
* @file       balance.c
* @brief      ��ƽ�ⲿ�ִ���
* @author     ������
* @date       2018-03-29
*/

#include  "common.h"
#include  "include.h"
#include  "math.h"

#define danbihuan 



/**********ȫ�ֱ�������********/

//ƽ�����
float g_fBalance_P = 60;
float g_fBalance_D = -99;
float g_fBalanceOutput = 0;
float g_fAngleOffset = 2.6;

extern float var[8];

extern EulerAngleTypedef      SystemAttitude;            /////��̬��
extern EulerAngleTypedef      SystemAttitudeRate;        /////��̬���ٶ�

/*!
*  @brief      ֱ����ʼ��
*  @param      none
*  @return     none
*  @date       2018-03-29
*/
void BalanceInit(void)
{
	IMU_IIC_Init();
	MPU3050_Init();
	MMA8451_Init();
	OffsetGyroY();    
}







/**
*  @brief      ƽ�����
*  @param      none
*  @return     none
*  @note	   
*  @date       2018-03-29
*/
void BalanceControl(void)
{
#ifdef danbihuan
	static float g_upstandControl_PWMTemp[5];
	float fPWM;

	//	if(g_AngleOfCar<-55||g_AngleOfCar>0)Flag_Stop = 1;//��������

	fPWM = (((-g_fAngleOffset +SystemAttitude.Pitch) * g_fBalance_P) + (-SystemAttitudeRate.Pitch * (g_fBalance_D / 100.0)));
	var[6] = g_fAngleOffset;

	fPWM = (float)(fPWM > BALANCE_PWM_MAX ? BALANCE_PWM_MAX : fPWM);
	fPWM = (float)(fPWM < BALANCE_PWM_MIN ? BALANCE_PWM_MIN : fPWM);

	g_upstandControl_PWMTemp[4] = g_upstandControl_PWMTemp[3];
	g_upstandControl_PWMTemp[3] = g_upstandControl_PWMTemp[2];
	g_upstandControl_PWMTemp[2] = g_upstandControl_PWMTemp[1];
	g_upstandControl_PWMTemp[1] = g_upstandControl_PWMTemp[0];
	g_upstandControl_PWMTemp[0] = fPWM;

	g_fBalanceOutput = 0.7 * g_upstandControl_PWMTemp[0] + 0.2 * g_upstandControl_PWMTemp[1] + \
	0.1 * g_upstandControl_PWMTemp[2] + 0 * g_upstandControl_PWMTemp[3] + 0 * g_upstandControl_PWMTemp[4];
#endif 

#ifdef shuangbihuan 
	static float g_upstandControl_PWMTemp[5];
	float fPWM;

	//	if(g_AngleOfCar<-55||g_AngleOfCar>0)Flag_Stop = 1;//��������

	fPWM = ((-g_AngleOfCar * g_fBalance_P) + (-g_fAngleSpeed * (g_fBalance_D / 100.0)));


	fPWM = (float)(fPWM > BALANCE_PWM_MAX ? BALANCE_PWM_MAX : fPWM);
	fPWM = (float)(fPWM < BALANCE_PWM_MIN ? BALANCE_PWM_MIN : fPWM);

	g_upstandControl_PWMTemp[4] = g_upstandControl_PWMTemp[3];
	g_upstandControl_PWMTemp[3] = g_upstandControl_PWMTemp[2];
	g_upstandControl_PWMTemp[2] = g_upstandControl_PWMTemp[1];
	g_upstandControl_PWMTemp[1] = g_upstandControl_PWMTemp[0];
	g_upstandControl_PWMTemp[0] = fPWM;

	g_fBalanceOutput = 0.7 * g_upstandControl_PWMTemp[0] + 0.2 * g_upstandControl_PWMTemp[1] + \
		0.1 * g_upstandControl_PWMTemp[2] + 0 * g_upstandControl_PWMTemp[3] + 0 * g_upstandControl_PWMTemp[4];
#endif
}

/*!
*  @brief      ������������ƫ
*  @param      none
*  @return     none
*  @note	   ͨ��ȫ�ֱ��� g_nGyroValueOffset ����
*  @date       2018-03-29
*/

