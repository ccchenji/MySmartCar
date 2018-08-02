#ifndef _SPEED_CONTROL_H_
#define _SPEED_CONTROL_H_
void CalSpeedError(void);
void SpeedControlOut(void);
void SpeedControl(void);
extern int Flag_SpeedControl;
extern float SpeedOut;
extern float RealSpeed;
extern float SpeedOutNew;
extern float Speed_Kp;
extern float ExpectSpeed;
extern float Speed_Ki;
#endif