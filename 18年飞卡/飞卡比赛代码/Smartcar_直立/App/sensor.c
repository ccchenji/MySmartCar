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
float AngleSpeed = 0;//�����ٶ�
int offset_AngleSpeed = 0;
float g_AngleOfCar;//���Ƕ�
BMX055Datatypedef      BMX055_data;

EulerAngleTypedef      SystemAttitude;            /////��̬��
EulerAngleTypedef      SystemAttitudeRate;        /////��̬���ٶ�
AttitudeDatatypedef    GyroOffset;

int AngleAccel = 0;
int offset_AngleAccel = 0;
//�Ǿ��󿨶����˲�
float Peried = 1 / 200.0;
float KalmanGain = 1.0;//����������
float Q = 10; //2.0;//��������2.0		ԽС����Խ�������ټ��ٶȼ�Խ��Խƽ��
float R = 2000;//5000.0;//��������5000.0	ԽС���ټ��ٶȼ�Խ��


float angle_offset=-11.5;//�Ƕ�ƫ��
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
	AngleSpeed = mpu_gyro_x - offset_AngleSpeed;
	AngleAccel = mpu_acc_y - offset_AngleAccel;
	//�������˲�
	//1.ʱ�����(Ԥ��) : X(k|k-1) = A(k,k-1)*X(k-1|k-1) + B(k)*u(k) 
	Priori_Estimation = Posterior_Estimation + AngleSpeed * Peried;		//������ƣ����ֻ�ýǶ�
	//2.��������Э����  : P(k|k-1) = A(k,k-1)*P(k-1|k-1)*A(k,k-1)'+Q(k) 
	Priori_Convariance = (float)sqrt(Posterior_Convariance * Posterior_Convariance + Q * Q);
	//  ������������ƣ���������  
	// 1.���㿨��������  : K(k) = P(k|k-1)*H(k)' / (H(k)*P(k|k-1)*H(k)' + R(k)) /
	KalmanGain = (float)sqrt(Priori_Convariance * Priori_Convariance / (Priori_Convariance * Priori_Convariance + R * R));
	//2.��������(У��): X(k|k) = X(k|k-1)+K(k)*(Z(k)-H(k)*X(k|k-1)) 

	//vcan_send_buff[1] = AngleAccel;

	Posterior_Estimation = Priori_Estimation + KalmanGain * (AngleAccel - Priori_Estimation);
	// 3.���º���Э����  : P(k|k) =��I-K(k)*H(k)��*P(k|k-1) 
	Posterior_Convariance = (float)sqrt((1 - KalmanGain) * Priori_Convariance * Priori_Convariance);
	//�õ����սǶ� 
	g_AngleOfCar = Posterior_Estimation + angle_offset;
	//vcan_send_buff[2] = Posterior_Estimation;
        vcan_send_buff[3] = AngleSpeed;
}



