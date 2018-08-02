#ifndef __BALANCE_H__
#define __BALANCE_H__

#include  "common.h"

/**********全局变量外部申明********/



 //平衡控制
 extern float g_fBalance_P;
 extern float g_fBalance_D;
 extern float g_fBalanceOutput;

/**********函数申明********/
 void BalanceInit(void);

 void BalanceControl(void);



#define BALANCE_PWM_MAX (1000)
#define BALANCE_PWM_MIN (-1000)

#endif
