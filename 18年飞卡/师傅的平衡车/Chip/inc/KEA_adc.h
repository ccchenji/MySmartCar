/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_adc.h
 * @brief      ADC����
 * @author     ɽ��Ƽ�
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

    Temp_Sensor = B8(10110),   //�¶ȴ�����
    Bandgap = B8(10111),
    VREFH = B8(11101),        // �ο��ߵ�ѹ
    VREFL = B8(11110),        // �ο��͵�ѹ

    Module0_Dis = B8(11111),


    ADCn_Ch_MAX
} ADCn_Ch_e;

typedef enum  //ADCģ��
{
    ADC0,
    ADC1
} ADCn_e;

//����λ��
typedef enum ADC_nbit
{
    ADC_8bit   = 0x00,
    ADC_10bit  = 0x01,
    ADC_12bit  = 0x02,
} ADC_nbit;


//�ⲿ�����ӿ�����
extern void     adc_init    (ADCn_Ch_e);                //ADC��ʼ��
extern uint16   adc_once    (ADCn_Ch_e, ADC_nbit);      //�ɼ�һ��һ·ģ������ADֵ

extern void     adc_stop    (ADCn_e);                   //ֹͣADCת��

extern u16 ad_ave(ADCn_Ch_e adcn_ch, ADC_nbit bit, u8 N); //��ֵ�˲�
#endif /* __KEA_ADC_H__ */
