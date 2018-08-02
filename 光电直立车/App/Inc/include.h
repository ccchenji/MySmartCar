#ifndef __INCLUDE_H__
#define __INCLUDE_H__


#include  "common.h"

/*
 * Include �û��Զ����ͷ�ļ�
 */
#include  "MK60_wdog.h"
#include  "MK60_gpio.h"     //IO�ڲ���
#include  "MK60_uart.h"     //����
#include  "MK60_SysTick.h"
#include  "MK60_lptmr.h"    //�͹��Ķ�ʱ��(��ʱ)
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
#include  "VCAN_camera.h"       //����ͷ��ͷ�ļ�
#include  "OLED.H"				//OLED���� 
#include  "motor_control.h"     //�������
#include  "sensor.h"			//������
#include "parameter.h"          //����
#include  "datamap.h"      
#include  "IMU_IIC.H"          //IMU_IIC
#include  "MPU3050.H"          //MPU3050
#include  "MMA8451.H"          //MMA8451  �˴�Ϊ�����Ǽ��ٶȼ�ͷ�ļ�
#include  "sdcard.h"
#include "Inc/Fuzzy_control.h"
#include  "speed.h"
#include  "direction.h"
#include  "image_deal_new.h"
//------------�����塿
#include  "Font4x6_ASCII.h"
#include  "Font6x8_ASCII.h"
#include  "Font8x10_ASCII.h"
#include  "Font8x8_ASCII.h"
#include "SOLGUI_Type.h"
#include "SOLGUI_Config.h"
 //-----------���м�㡿
#include "SOLGUI_Common.h"
#include "SOLGUI_Printf.h"
#include "SOLGUI_GBasic.h"
#include "SOLGUI_Picture.h"
 //-----------��Ӧ�ò㡿
#include "SOLGUI_Menu.h"
#include "SOLGUI_Widget.h"



#include  "VCAN_computer.h"     //�๦�ܵ�������
#endif  //__INCLUDE_H__
