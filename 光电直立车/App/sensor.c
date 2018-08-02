/*
				 �������������[ �����������[ �����[   �����[ �������������[                   
				�����X�T�T�T�T�a�����X�T�T�����[�����U   �����U�����X�T�T�T�T�a                   
				�����U     ���������������U�����U   �����U�����U                        
				�����U     �����X�T�T�����U�����U   �����U�����U                        
				�^�������������[�����U  �����U�^�������������X�a�^�������������[                   
				 �^�T�T�T�T�T�a�^�T�a  �^�T�a �^�T�T�T�T�T�a  �^�T�T�T�T�T�a                   

*/ 

/*!
* @file       sensor.c
* @brief      ����������
* @author     JassyLiu
* @date       2016-12-05
* @revision
* @note
*/
#include "common.h"
#include "include.h"
#include "sensor.h"
#include  "math.h"						 
/*         ��������         */
/*
			  Z��     
				\ �J
			�I	 \
	  X��һһһһһ@
			�J    |
				�K|�J
				  |
				 Y��
*/

#ifdef MPU3050_USED
extern char car_1or2_flag ;
/**********ȫ�ֱ�������********/
//���ٶȼ�
int32 g_nValueOfAcce;
float g_fAngleOfAcce;
int16 Offset_Acce = 680;//700��Сǰ��
float Ratio_Acce = 0.105;
//������
int32 g_nValueOfGyro[2];
float g_fAngleSpeed[2];
float Offset_Gyro[2] = { 0,0 };
float Raito_Gyro[2] = { 0.24, 0.24 };
float angle_Difference;
//�����˲�
float g_fAngleOfGyro[2];
float Const_Time = 3;
uint8 Freq_Inte = 200;
float g_BlanceControlOut;
float g_upstandControl_P = 7.5;
float g_upstandControl_D = 0.3;
//�Ǿ��󿨶����˲�
float Peried = 1 / 150.0;
float KalmanGain = 1.0;//����������
float Q =2.8; //2.0;//��������2.0		ԽС����Խ�������ټ��ٶȼ�Խ��Խƽ��
float R = 1000;//5000.0;//��������5000.0	ԽС���ټ��ٶȼ�Խ��
float g_AngleOfCar;

//ֱ���������� 
float angle_offset = 57;
/**
* @note		    ��ʼ��I2C�����ٶȼƺ�������
* @author		jassy
* @date		    2017
*/
void UpstandInit(void)
{
	MPU3050_Init();
	MMA8451_Init();
	//OffsetGyroY();
}

/**
* @file			��ȡ���ٶȼƵ�ֵ������ɽǶ�
* @file			��ȡ�����ǵ�ֵ��ת��Ϊ���ٶ�
* @note      	�õ�ȫ�ֱ���g_nValueOfAcce��g_fAngleOfAcce
* @note      	�õ�ȫ�ֱ���g_nValueOfGyro[2], g_fAngleSpeed
* @author		jassy
* @date			2017
*/
void GalAcceAndGyroY(void)
{
	int16 nValueOfAcce = 0;
	int16 nValueOfGyro = 0;
	int8 i = 0;
//	for (i = 0; i<5; i++)
//	{
		nValueOfAcce += MMA8451_GetResult(MMA8451_STATUS_Z_READY, MMA8451_REG_OUTZ_MSB) ;
		nValueOfGyro += MPU3050_GetResult(1, MPU3050_OUT_Y_H);
//	}

	g_nValueOfAcce = (int32)(nValueOfAcce - Offset_Acce);
	g_fAngleOfAcce = Ratio_Acce * g_nValueOfAcce;

	g_nValueOfGyro[GyroY] = (int32)(nValueOfGyro - Offset_Gyro[GyroY]);
	g_fAngleSpeed[GyroY] = Raito_Gyro[GyroY] * g_nValueOfGyro[GyroY];

}


/**
* @file			�����˲�
* @file			�����ǻ��ֵõ��Ƕ�
* @note      	�õ�ȫ�ֱ���g_fAngleOfGyro[2]
* @author		jassy
* @date			2017
*/
void CalAngleOfGyro(void)
{
	float fDeltaValue;
	static float fAngleOfgyro0;
	fAngleOfgyro0 = g_fAngleOfGyro[0];
	fDeltaValue = (g_fAngleOfAcce - fAngleOfgyro0) / Const_Time;
	g_fAngleOfGyro[0] += (g_fAngleSpeed[0] + fDeltaValue) / Freq_Inte;

}


/**
* @file			�Ǿ��󿨶����˲�
* @note      	������ٶ�g_fAngleSpeed[0]���Ƕ�g_fAngleOfAcce
* @note      	�õ�ȫ�ֱ���g_AngleOfCar
* @date
*/
void KalmanFilter(void)
{
	//�������˲��ֲ�����
	static float Priori_Estimation = 0;//�������
	static float Posterior_Estimation = 0;//�������
	static float Priori_Convariance = 0;//���鷽��
	static float Posterior_Convariance = 0;//���鷽��

	//�������˲�
	//1.ʱ�����(Ԥ��) : X(k|k-1) = A(k,k-1)*X(k-1|k-1) + B(k)*u(k) 
	Priori_Estimation = Posterior_Estimation + g_fAngleSpeed[0] * Peried;		//������ƣ����ֻ�ýǶ�
	//2.��������Э����  : P(k|k-1) = A(k,k-1)*P(k-1|k-1)*A(k,k-1)'+Q(k) 
	Priori_Convariance = (float)sqrt(Posterior_Convariance * Posterior_Convariance + Q * Q);
	//  ������������ƣ���������  
	// 1.���㿨��������  : K(k) = P(k|k-1)*H(k)' / (H(k)*P(k|k-1)*H(k)' + R(k)) /
	KalmanGain = (float)sqrt(Priori_Convariance * Priori_Convariance / (Priori_Convariance * Priori_Convariance + R * R));
	//2.��������(У��): X(k|k) = X(k|k-1)+K(k)*(Z(k)-H(k)*X(k|k-1)) 

	vcan_send_buff[1] = g_fAngleOfAcce;
	
	Posterior_Estimation = Priori_Estimation + KalmanGain * (g_fAngleOfAcce - Priori_Estimation);
	// 3.���º���Э����  : P(k|k) =��I-K(k)*H(k)��*P(k|k-1) 
	Posterior_Convariance = (float)sqrt((1 - KalmanGain) * Priori_Convariance * Priori_Convariance);
	//�õ����սǶ� 
	  g_AngleOfCar = Posterior_Estimation+angle_offset;
	  vcan_send_buff[2] = Posterior_Estimation;
        if(car_1or2_flag == 1)
        {
              g_AngleOfCar +=83;
              
         }

		

}

/**
* @file			ƽ����Ƶ�PD����
* @note      	�õ�ȫ�ֱ���g_BlanceControlOut
* @author		Jassy
* @date			2017
*/
void BalanceControl(void)
{
	static float g_upstandControl_PWMTemp[5];
	float fPWM;
	//��������

	fPWM = ((-g_AngleOfCar*g_upstandControl_P) + (-g_fAngleSpeed[0] * g_upstandControl_D));
	//	fPWM = (( - g_AngleOfCar*float01)+( - g_fAngleSpeed[0]*float02));
	g_upstandControl_PWMTemp[4] = g_upstandControl_PWMTemp[3];
	g_upstandControl_PWMTemp[3] = g_upstandControl_PWMTemp[2];
	g_upstandControl_PWMTemp[2] = g_upstandControl_PWMTemp[1];
	g_upstandControl_PWMTemp[1] = g_upstandControl_PWMTemp[0];
	g_upstandControl_PWMTemp[0] = fPWM;
	g_BlanceControlOut = 1 * g_upstandControl_PWMTemp[0] + 0 * g_upstandControl_PWMTemp[1];
}

/**
* @file			ֱ�������ǵĿ�������ʼ��
* @note      	�ɼ�1000��ƽ��
* @author		��������ѧԺ
* @date			2017
*/
void OffsetGyroY()
{
	int16 i;
	float Offset_Gyros = 0;
	for (i = 0; i<1000; i++)
	{
		Offset_Gyros += (MPU3050_GetResult(1, MPU3050_OUT_Y_H) / 1000.0);
	}
	Offset_Gyro[0] = Offset_Gyros;
}

#endif 



