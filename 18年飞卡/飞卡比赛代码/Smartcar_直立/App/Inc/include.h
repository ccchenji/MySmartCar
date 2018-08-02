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

#include "iic.h"
#include "mpu6050.h"
#include "SOLGUI_Include.h"
#include "control.h"
#include "MyOLED.h"
#include "sensor.h"

#include  "MPU3050.H"          //MPU3050
#include  "MMA8451.H"          //MMA8451  此处为陀螺仪加速度计头文件

#include "VCAN_computer.h"
#include "control.h"
#include "speed_control.h"
#include "motor_control.h"
#include "balance_control.h"
#include "dir_control.h"
#include "BMX055.h"
#include "Attitude_Calculation.h"
#include "myiic.h"
extern float vcan_send_buff[4]; //山外上位机虚拟示波器
#endif  //__INCLUDE_H__
