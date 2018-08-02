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
  本例程用到中断，需要在 MKEA128_it.h 文件里添加：
  #define PIT_CH0_IRQHandler  pit0_irq
  表示pit通道0的中断函数为pit0_irq
*/
void pit0_irq(void)
{
  led_turn(LED1);
    lose_line_deal(adc_value, adc_value[0]-adc_value[3], left_lossline_Range, right_lossline_Range);
    Speed_calulate();
    Speed_PidControl(g_set_speed,g_real_speed);
    Dir_PdControl();
    Motor_control();
    PIT_Flag_Clear(PIT0); //清中断标志位
    led_turn(LED1); 
}
void pit1_irq(void)
{
   key_value = Key_Scan();
   SOLGUI_InputKey(key_value);
   SOLGUI_Menu_PageStage(); //
   SOLGUI_Refresh();        //OLED刷新
   PIT_Flag_Clear(PIT1);
  led_turn(LED0); //闪烁 LED0
}
void main(void)
{
    gpio_init(PTD4, GPO, 0); //初始化蜂鸣器
    gpio_init(PTH6, GPO, 0); //初始化LED0
    gpio_init(PTH7, GPO, 0); //初始化LED1
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
    
    /*PWM初始化：FTM2,CH0-CH3,频率2K,精度1000u*/
    ftm_pwm_init(FTM2, FTM_CH0, 10000, 100);
    ftm_pwm_init(FTM2, FTM_CH1, 10000, 100); //前进通道左

    ftm_pwm_init(FTM2, FTM_CH2, 10000, 100); //前进通道右
    ftm_pwm_init(FTM2, FTM_CH3, 10000, 100);
    
    /*oled初始化*/
    SOLGUI_Init(&UI_MENU);
    SOLGUI_Refresh();
    
    Sensor_init();
    led_init(LED0);
    Encoder_init();
    pit_init_ms(PIT0, 10);
    pit_init_ms(PIT1, 100);
   enable_irq(PIT_CH0_IRQn);  
   enable_irq(PIT_CH1_IRQn);
    EnableInterrupts; //打开总的中断开关
    
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
 *  @brief      main函数
 *  @since      v6.0
 *  @note       山外 flash data

                本例程需要在线调试，看变量的值的变化。
                把 md 加入watch，单步调试，逐步分析md的元素数据变化。
 */
/*void  main(void)
{
    //这部分是用户自己的数据，不一定是结构体，也可以是数组，但数据必须连续，且大小确定
    my_data_t  md;
    md.a = 0;
    md.b = 0;

    //这部分是配置 flash 保存参数
    data.sectornum_start    = FLASH_SECTOR_NUM - 3;     //起始扇区      用最后的3个扇区来作为保存参数
    data.sectornum_end    = FLASH_SECTOR_NUM - 1;       //结束扇区

    data.data_addr      = &md;                          //数据的地址
    data.data_size      = sizeof(md);                  //数据的大小

    //开始函数调用
    flash_data_init(&data);

    //重置flash(看个人需求)
    //flash_data_reset(&data);

    //一开始，不知道数据是否有效的
    if(flash_data_load(&data))
    {
        //加载最后一次存储的数据成功

    }
    else
    {
        //加载数据无效。flash数据是空白的

        flash_data_reset(&data);        //重置一下flash数据

        md.a = 0x1234;                  //对变量初始化
        md.b = 0x5678;

        //写入初始化值
        flash_data_save(&data) ;

        //读回来测试
        md.a = 0;
        md.b = 0;
        flash_data_load(&data) ;
    }

    //到了这里，我们可以设端点，看 md 的数据是否恢复了

    //一般情况下，我们不需要调用 flash_data_reset 来清空，除非你不想要 flash的数据。

    md.a = 0x3210;
    md.b = 0x8765;
    flash_data_save(&data) ;

    //我们先清空 md 的数据，然后从 flash 恢复数据
    md.a = 0;
    md.b = 0;
    flash_data_load(&data) ;


    md.a = 0xabcd;
    md.b = 0x3456;
    flash_data_save(&data) ;

    //我们先清空 md 的数据，然后从 flash 恢复数据
    md.a = 0;
    md.b = 0;
    flash_data_load(&data) ;

}*/