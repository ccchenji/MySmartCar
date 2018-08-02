#ifndef _MOTOR_CONTROL_H_
#define _MOTOR_CONTROL_H_
/*---------------电机PWM限幅控制-------------------*/
#define Motor_speed_Max ( 9800)
#define Motor_speed_Min (-9800)
/*-------------------------------------------------*/
extern int16 LeftMotorPulseSigma;          //左边电机计数信号
extern int16 RightMotorPulseSigma;         //右边电机计数信号
/*-----------------电机控制接口函数区域-------------*/
extern void  Motor_PWM_init(void);
extern void  Right_Motor_Control(int32 speed);
extern void  Left_Motor_Control(int32 speed);
/*-----------------编码器控制接口函数区域-------------*/
extern void Encoder_Init(void);
extern void GetMotorPulse(void);
/*-------------------------------------------------*/
#endif