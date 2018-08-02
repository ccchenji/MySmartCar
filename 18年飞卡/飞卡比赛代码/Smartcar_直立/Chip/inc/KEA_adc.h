/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_adc.h
 * @brief      ADC函数
 * @author     山外科技
 * @version    v5.0
 * @date       2013-08-28
 */


#ifndef __KEA_ADC_H__
#define __KEA_ADC_H__  1

typedef enum
{
    //AD0-AD15
    ADC0_SE0,       // PTA0
    ADC0_SE1,       // PTA1

    ADC0_SE2,       // PTA6
    ADC0_SE3,       // PTA7

    ADC0_SE4,       // PTB0
    ADC0_SE5,       // PTB1
    ADC0_SE6,       // PTB2
    ADC0_SE7,       // PTB3

    ADC0_SE8,       // PTC0
    ADC0_SE9,       // PTC1
    ADC0_SE10,      // PTC2
    ADC0_SE11,      // PTC3

    ADC0_SE12,      // PTF4
    ADC0_SE13,      // PTF5
    ADC0_SE14,      // PTF6
    ADC0_SE15,      // PTF7

    Temp_Sensor = B8(10110),   //温度传感器
    Bandgap = B8(10111),
    VREFH = B8(11101),        // 参考高电压
    VREFL = B8(11110),        // 参考低电压

    Module0_Dis = B8(11111),


    ADCn_Ch_MAX
} ADCn_Ch_e;

typedef enum  //ADC模块
{
    ADC0,
    ADC1
} ADCn_e;

//精度位数
typedef enum ADC_nbit
{
    ADC_8bit   = 0x00,
    ADC_10bit  = 0x01,
    ADC_12bit  = 0x02,
} ADC_nbit;


//外部函数接口声明
extern void     adc_init    (ADCn_Ch_e);                //ADC初始化
extern uint16   adc_once    (ADCn_Ch_e, ADC_nbit);      //采集一次一路模拟量的AD值

extern void     adc_stop    (ADCn_e);                   //停止ADC转换


#endif /* __KEA_ADC_H__ */
