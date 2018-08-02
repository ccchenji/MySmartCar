#ifndef __INCLUDE_H__
#define __INCLUDE_H__


#include  "common.h"

/*
 * Include 用户自定义的头文件
 */
#include  "MK60_wdog.h"
#include  "MK60_gpio.h"     //IO口操作
#include  "MK60_uart.h"     //串口
#include  "MK60_SysTick.h"
#include  "MK60_lptmr.h"    //低功耗定时器(延时)
#include  "MK60_pit.h"      //PIT
#include  "MK60_FLASH.h"    //FLASH
#include  "MK60_FTM.h"      //FTM
#include  "MK60_adc.h"      //ADC
#include  "MK60_dac.h"      //DAC
#include  "MK60_dma.h"      //DMA
#include  "MK60_spi.h"      //SPI
#include  "MK60_rtc.h"      //RTC

#include  "VCAN_LED.H"          //LED
#include  "VCAN_KEY.H"          //KEY
#include  "VCAN_camera.h"       //摄像头总头文件
#include  "OLED.H"				//OLED驱动 
#include  "motor_control.h"     //电机控制
#include  "sensor.h"			//传感器
#include "parameter.h"          //参数
#include  "datamap.h"      
#include  "IMU_IIC.H"          //IMU_IIC
#include  "MPU3050.H"          //MPU3050
#include  "MMA8451.H"          //MMA8451  此处为陀螺仪加速度计头文件
#include  "sdcard.h"
#include "Inc/Fuzzy_control.h"
#include  "speed.h"
#include  "direction.h"
#include  "image_deal_new.h"
//------------【字体】
#include  "Font4x6_ASCII.h"
#include  "Font6x8_ASCII.h"
#include  "Font8x10_ASCII.h"
#include  "Font8x8_ASCII.h"
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



#include  "VCAN_computer.h"     //多功能调试助手
#endif  //__INCLUDE_H__
