#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include  "common.h"

#include "enter.h"
/*
 * Include 用户自定义的头文件
 */
#include "KEA_gpio.h"
#include "KEA_uart.h"
#include "KEA_adc.h"
#include "KEA_ftm.h"
#include "KEA_pit.h"
#include "KEA_SysTick.h"

#include "VCAN_LED.h"
#include "VCAN_key.h"
#include "VCAN_NRF24L0.h"
#include "VCAN_lcd.h"

#include "MyOLED.h"
#include "IMU_IIC.h"
#include "MMA8451.h"
#include "MPU3050.h"
#include "balance.h"
#include "speed.h"
#include "BNO055.h"
#include "myiic.h"
#include "BMX055.h"
#include "Attitude_Calculation.h"
#include "direction.h"
 //-----------【移植设置】
#include "SOLGUI_Type.h"
#include "SOLGUI_Config.h"

 //-----------【中间层】
#include "SOLGUI_Common.h"
#include "SOLGUI_Printf.h"
#include "SOLGUI_GBasic.h"
#include "SOLGUI_Picture.h"
 //-----------【应用层】
#include "SOLGUI_Menu.h"
#include "SOLGUI_Widget.h"







#endif  //__INCLUDE_H__
