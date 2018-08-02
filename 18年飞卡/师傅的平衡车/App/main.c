/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2017,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       main.c
 * @brief      ɽ��KEA ƽ̨������
 * @author     ɽ��Ƽ�
 * @version    v6.0
 * @date       2017-12-10
 */

#include "common.h"
#include "include.h"

#define SW_3_OLEDreflash	PTC3  
float var[8] = { 0 };		//ɽ����λ������ 	
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
 *  @brief      main����   
 *  @since      v6.0   
 *  @note       ���� LED �����Ƿ�����   
                ������Ч����LED0��LED1ͬʱ������˸   
 */   
void main()    
{
    led_init(LED0);                         //��ʼ��LED0    
    led_init(LED1);                         //��ʼ��LED1  
	key_init(KEY_MAX);
	gpio_init(SW_3_OLEDreflash, GPI, 1); //��ʼ�����뿪�� 
    OLED_Init(); //��ʼ��OLED
    OLED_Fill(0x00); //����
    draw_cauc_logo();
    ErrLoop = 0;
    IIC_init();
    while(BMX055_init() == 0)
  {
    ErrLoop++;
	if (ErrLoop >= 20)
		while (1);
  }; 

	SOLGUI_Init(&UI_List);		    //UI��ʼ������
	SOLGUI_Refresh();		    	//UIˢ�� 
	
	ftm_pwm_init(FTM2, FTM_CH0, 13000, 0);
	ftm_pwm_init(FTM2, FTM_CH1, 13000, 0);
	ftm_pwm_init(FTM2, FTM_CH2, 13000, 0);
	ftm_pwm_init(FTM2, FTM_CH3, 13000, 0);  //����PWM

	ftm_pulse_init(FTM0, FTM_PS_1, TCLK1);
	ftm_pulse_init(FTM1, FTM_PS_1, TCLK2); //���ò���
	gpio_init(PTD2, GPI, 0);
	gpio_init(PTD3, GPI, 0);

	adc_init(ADC0_SE12);
	adc_init(ADC0_SE13);
	adc_init(ADC0_SE14);
	adc_init(ADC0_SE15);			//����ADC

	pit_init_ms(PIT0,5);			//5ms �ж�
	pit_init_ms(PIT1,100);			//100msUIˢ��
	enable_irq(PIT_CH0_IRQn);
	enable_irq(PIT_CH1_IRQn);


	EnableInterrupts;
    while(1)    
    {      
       // led_turn(LED1);                     //LED1��ת       
       // DELAY_MS(50);                      //��ʱ500ms  
		
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

