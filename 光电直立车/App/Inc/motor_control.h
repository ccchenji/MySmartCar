#ifndef _MOTOR_CONTROL_H_
#define _MOTOR_CONTROL_H_
/*---------------���PWM�޷�����-------------------*/
#define Motor_speed_Max ( 9800)
#define Motor_speed_Min (-9800)
/*-------------------------------------------------*/
extern int16 LeftMotorPulseSigma;          //��ߵ�������ź�
extern int16 RightMotorPulseSigma;         //�ұߵ�������ź�
/*-----------------������ƽӿں�������-------------*/
extern void  Motor_PWM_init(void);
extern void  Right_Motor_Control(int32 speed);
extern void  Left_Motor_Control(int32 speed);
/*-----------------���������ƽӿں�������-------------*/
extern void Encoder_Init(void);
extern void GetMotorPulse(void);
/*-------------------------------------------------*/
#endif