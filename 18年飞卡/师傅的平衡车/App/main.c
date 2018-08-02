/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2017,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       main.c
 * @brief      山外KEA 平台主程序
 * @author     山外科技
 * @version    v6.0
 * @date       2017-12-10
 */

#include "common.h"
#include "include.h"

#define SW_3_OLEDreflash	PTC3  
float var[8] = { 0 };		//山外上位机数组 	
int16 PwmSet0 = 0;
int16 PwmSet1 = 0;
int16 PwmSet2 = 0;
int16 PwmSet3 = 0;
uint16 AD_Value0 = 0;
uint16 AD_Value1 = 0;
uint16 AD_Value2 = 0;
uint16 AD_Value3 = 0;

uint16 ErrLoop = 0;

/*!   
 *  @brief      main函数   
 *  @since      v6.0   
 *  @note       测试 LED 功能是否正常   
                看到的效果是LED0和LED1同时亮灭闪烁   
 */   
void main()    
{
    led_init(LED0);                         //初始化LED0    
    led_init(LED1);                         //初始化LED1  
	key_init(KEY_MAX);
	gpio_init(SW_3_OLEDreflash, GPI, 1); //初始化拨码开关 
    OLED_Init(); //初始化OLED
    OLED_Fill(0x00); //黑屏
    draw_cauc_logo();
    ErrLoop = 0;
    IIC_init();
    while(BMX055_init() == 0)
  {
    ErrLoop++;
	if (ErrLoop >= 20)
		while (1);
  }; 

	SOLGUI_Init(&UI_List);		    //UI初始化界面
	SOLGUI_Refresh();		    	//UI刷新 
	
	ftm_pwm_init(FTM2, FTM_CH0, 13000, 0);
	ftm_pwm_init(FTM2, FTM_CH1, 13000, 0);
	ftm_pwm_init(FTM2, FTM_CH2, 13000, 0);
	ftm_pwm_init(FTM2, FTM_CH3, 13000, 0);  //设置PWM

	ftm_pulse_init(FTM0, FTM_PS_1, TCLK1);
	ftm_pulse_init(FTM1, FTM_PS_1, TCLK2); //设置捕获
	gpio_init(PTD2, GPI, 0);
	gpio_init(PTD3, GPI, 0);

	adc_init(ADC0_SE12);
	adc_init(ADC0_SE13);
	adc_init(ADC0_SE14);
	adc_init(ADC0_SE15);			//设置ADC

	pit_init_ms(PIT0,5);			//5ms 中断
	pit_init_ms(PIT1,100);			//100msUI刷新
	enable_irq(PIT_CH0_IRQn);
	enable_irq(PIT_CH1_IRQn);


	EnableInterrupts;
    while(1)    
    {      
       // led_turn(LED1);                     //LED1翻转       
       // DELAY_MS(50);                      //延时500ms  
		
		//ftm_pwm_duty(FTM2, FTM_CH0, PwmSet0);
		//ftm_pwm_duty(FTM2, FTM_CH1, PwmSet1);
		//ftm_pwm_duty(FTM2, FTM_CH2, PwmSet2);
		//ftm_pwm_duty(FTM2, FTM_CH3, PwmSet3);

		

		vcan_sendware(var, sizeof(var));
		if (gpio_get(SW_3_OLEDreflash) == 0)
		{
			OLED_Init();
			OLED_Fill(0x00);
		}
		
    }    
}   

