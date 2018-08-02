#ifndef _MOTOR_CONTROL_H_
#define _MOTOR_CONTROL_H_

#define Motor_speed_Max ( 800)
#define Motor_speed_Min (-800)

extern int16 LeftMotorPulseSigma;          //��ߵ�������ź�
extern int16 RightMotorPulseSigma;         //�ұߵ�������ź�

void Right_Motor_Control(int32 speed);
void Left_Motor_Control(int32 speed);
#endif