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



#define ADC_CH0 ADC0_SE12
#define ADC_CH1 ADC0_SE13
#define ADC_CH2 ADC0_SE14
#define ADC_CH3 ADC0_SE15


int adc_value[4];
int key_value = 0;
char KEY_NUM;
int position;
int left_lossline_Range = 10, right_lossline_Range=10;
extern int g_real_speed,g_set_speed,loseline;

/*
  �������õ��жϣ���Ҫ�� MKEA128_it.h �ļ�����ӣ�
  #define PIT_CH0_IRQHandler  pit0_irq
  ��ʾpitͨ��0���жϺ���Ϊpit0_irq
*/
void pit0_irq(void)
{
  led_turn(LED1);
    lose_line_deal(adc_value, adc_value[0]-adc_value[3], left_lossline_Range, right_lossline_Range);
    Speed_calulate();
    Speed_PidControl(g_set_speed,g_real_speed);
    Dir_PdControl();
    Motor_control();
    PIT_Flag_Clear(PIT0); //���жϱ�־λ
    led_turn(LED1); 
}
void pit1_irq(void)
{
   key_value = Key_Scan();
   SOLGUI_InputKey(key_value);
   SOLGUI_Menu_PageStage(); //
   SOLGUI_Refresh();        //OLEDˢ��
   PIT_Flag_Clear(PIT1);
  led_turn(LED0); //��˸ LED0
}
void main(void)
{
    gpio_init(PTD4, GPO, 0); //��ʼ��������
    gpio_init(PTH6, GPO, 0); //��ʼ��LED0
    gpio_init(PTH7, GPO, 0); //��ʼ��LED1
    led_init (LED0);
    key_init(KEY_MAX);

    OLED_Init();
    OLED_Fill(0x00);
    draw_cauc_logo();

    gpio_turn(PTD4);
    systick_delay_ms(50);
    gpio_turn(PTD4);
    systick_delay_ms(50);
    gpio_turn(PTD4);
    systick_delay_ms(50);
    gpio_turn(PTD4);

    DELAY_MS(500);
    
    /*PWM��ʼ����FTM2,CH0-CH3,Ƶ��2K,����1000u*/
    ftm_pwm_init(FTM2, FTM_CH0, 10000, 100);
    ftm_pwm_init(FTM2, FTM_CH1, 10000, 100); //ǰ��ͨ����

    ftm_pwm_init(FTM2, FTM_CH2, 10000, 100); //ǰ��ͨ����
    ftm_pwm_init(FTM2, FTM_CH3, 10000, 100);
    
    /*oled��ʼ��*/
    SOLGUI_Init(&UI_MENU);
    SOLGUI_Refresh();
    
    Sensor_init();
    led_init(LED0);
    Encoder_init();
    pit_init_ms(PIT0, 10);
    pit_init_ms(PIT1, 100);
   enable_irq(PIT_CH0_IRQn);  
   enable_irq(PIT_CH1_IRQn);
    EnableInterrupts; //���ܵ��жϿ���
    
    for (;;)
    {    
        //printf("hello world\n");
        adc_value[0] = adc_once(ADC_CH0, ADC_10bit);
        adc_value[1] = adc_once(ADC_CH1, ADC_10bit);
        adc_value[2] = adc_once(ADC_CH2, ADC_10bit);
        adc_value[3] = adc_once(ADC_CH3, ADC_10bit);
       // position = adc_value[0]-adc_value[3];
		//ftm_pwm_duty(FTM2, FTM_CH1, 150);
		//ftm_pwm_duty(FTM2, FTM_CH2, 150);
    }
}

/*!
 *  @brief      main����
 *  @since      v6.0
 *  @note       ɽ�� flash data

                ��������Ҫ���ߵ��ԣ���������ֵ�ı仯��
                �� md ����watch���������ԣ��𲽷���md��Ԫ�����ݱ仯��
 */
/*void  main(void)
{
    //�ⲿ�����û��Լ������ݣ���һ���ǽṹ�壬Ҳ���������飬�����ݱ����������Ҵ�Сȷ��
    my_data_t  md;
    md.a = 0;
    md.b = 0;

    //�ⲿ�������� flash �������
    data.sectornum_start    = FLASH_SECTOR_NUM - 3;     //��ʼ����      ������3����������Ϊ�������
    data.sectornum_end    = FLASH_SECTOR_NUM - 1;       //��������

    data.data_addr      = &md;                          //���ݵĵ�ַ
    data.data_size      = sizeof(md);                  //���ݵĴ�С

    //��ʼ��������
    flash_data_init(&data);

    //����flash(����������)
    //flash_data_reset(&data);

    //һ��ʼ����֪�������Ƿ���Ч��
    if(flash_data_load(&data))
    {
        //�������һ�δ洢�����ݳɹ�

    }
    else
    {
        //����������Ч��flash�����ǿհ׵�

        flash_data_reset(&data);        //����һ��flash����

        md.a = 0x1234;                  //�Ա�����ʼ��
        md.b = 0x5678;

        //д���ʼ��ֵ
        flash_data_save(&data) ;

        //����������
        md.a = 0;
        md.b = 0;
        flash_data_load(&data) ;
    }

    //����������ǿ�����˵㣬�� md �������Ƿ�ָ���

    //һ������£����ǲ���Ҫ���� flash_data_reset ����գ������㲻��Ҫ flash�����ݡ�

    md.a = 0x3210;
    md.b = 0x8765;
    flash_data_save(&data) ;

    //��������� md �����ݣ�Ȼ��� flash �ָ�����
    md.a = 0;
    md.b = 0;
    flash_data_load(&data) ;


    md.a = 0xabcd;
    md.b = 0x3456;
    flash_data_save(&data) ;

    //��������� md �����ݣ�Ȼ��� flash �ָ�����
    md.a = 0;
    md.b = 0;
    flash_data_load(&data) ;

}*/