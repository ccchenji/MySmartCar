#ifndef _BALANCE_CONTROL_H_
#define _BALANCE_CONTROL_H_

void BalanceControl(void);

extern float Balance_Kp;
extern float Balance_Kd;
extern float Balance_Out; 
extern float Balance_Inside_Kp;
extern float Balance_Inside_Kd;
extern float Balance_Inside_Out; 
extern float Balance_Err, Balance_LastErr;
extern float AccZAngle , QZAngle ;
extern void GetAngle();
#endif