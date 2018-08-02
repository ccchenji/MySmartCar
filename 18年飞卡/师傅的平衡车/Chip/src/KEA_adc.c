/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_adc.c
 * @brief      ADC����
 * @author     ɽ��Ƽ�
 * @version    v5.1
 * @date       2014-01-16
 */

#include "common.h"
#include "KEA_adc.h"


static void  inline   adc_start   (ADCn_Ch_e, ADC_nbit);    //��ʼadcת��

/*!
 *  @brief      ADC��ʼ��
 *  @param      ADCn_Ch_e    ADCͨ��
 *  @since      v5.0
 *  @note       �˳�ʼ����֧���������������ÿ��ͨ����֧��ADC ���������
                ����˵���� ADCn_Ch_e ��ע��˵��
 *  Sample usage:       adc_init (ADC0_SE10 );    //��ʼ�� ADC0_SE10
 */
void adc_init(ADCn_Ch_e adcn_ch)
{

    ASSERT(adcn_ch < ADCn_Ch_MAX ) ;

    SIM_SCGC |= SIM_SCGC_ADC_MASK;  //ʹ��ʱ��

    ADC_APCTL1 |= 1 << adcn_ch;     //���ź�

    ADC_SC2 = (0
               //|  ADC_SC2_ADTRG_MASK  //0Ϊ������1ΪӲ������
               |  ADC_SC2_REFSEL(0)     //ʹ���ⲿ�ο���ѹ VREFH/VREFL
              );
}

/*!
 *  @brief      ��ȡADC����ֵ(��֧��Bͨ��)
 *  @param      ADCn_Ch_e    ADCͨ��
 *  @param      ADC_nbit     ADC���ȣ� ADC_8bit,ADC_12bit, ADC_10bit, ADC_16bit ��
 *  @return     ����ֵ
 *  @since      v5.0
 *  Sample usage:       uint16 var = adc_once(ADC0_SE10, ADC_8bit);
 */
uint16 adc_once(ADCn_Ch_e adcn_ch, ADC_nbit bit) //�ɼ�ĳ·ģ������ADֵ
{
    uint16 result = 0;

    adc_start(adcn_ch, bit);      //����ADCת��

    while (!( ADC_SC1 & ADC_SC1_COCO_MASK ));   //�ȴ�ת�����
    result = ADC_R;
    ADC_SC1 &= ~ADC_SC1_COCO_MASK;
    return result;
}

/*!
 *  @brief      ����ADC�������(��֧��Bͨ��)
 *  @param      ADCn_Ch_e    ADCͨ��
 *  @param      ADC_nbit     ADC���ȣ� ADC_8bit,ADC_12bit, ADC_10bit, ADC_16bit ��
 *  @since      v5.0
 *  @note       �˺����ڲ����ã������󼴿ɵȴ����ݲɼ����
 *  Sample usage:       adc_start(ADC0_SE10, ADC_8bit);
 */
void adc_start(ADCn_Ch_e adcn_ch, ADC_nbit bit)
{
    ADC->SC3  = (0
                  |ADC_SC3_ADICLK(0)            //ѡ������ʱ��
                  |ADC_SC3_MODE(bit)            //�ֱ��ʲɼ�
                  //|ADC_SC3_ADLSMP_MASK        //0Ϊ�̲���ʱ��
                  |ADC_SC3_ADIV(0)              //��Ƶϵ��Ϊ1
                  //|ADC_SC3_ADLPC_MASK         //������ʱ��
                  );
                  
    //д�� SC1 ����ת��
    ADC_SC1                     = (0
                                   | ADC_SC1_AIEN_MASK          // ת������ж�,0Ϊ��ֹ��1Ϊʹ��
                                   //| ADC_SC1_DIFF_MASK        // ���ģʽʹ��,0Ϊ���ˣ�1Ϊ���
                                   | ADC_SC1_ADCH( adcn_ch )
                                  );

}

/*!
 *  @brief      ֹͣADC�������
 *  @param      ADCn_e       ADCģ��ţ� ADC0�� ADC1��
 *  @since      v5.0
 *  Sample usage:       adc_stop(ADC0);
 */
void adc_stop(ADCn_e adcn)
{
    ADC_SC1 = (0
               | ADC_SC1_AIEN_MASK                       // ת������ж�,0Ϊ��ֹ��1Ϊʹ��
               //| ADC_SC1_DIFF_MASK                     // ���ģʽʹ��,0Ϊ���ˣ�1Ϊ���
               | ADC_SC1_ADCH(Module0_Dis)               //����ͨ��ѡ��,�˴�ѡ���ֹͨ��
              );
}
/**
*
*  �������ƣ�ad_ave
*  ����˵������β�����ȡƽ��ֵ
*  ����˵����ADCx        ģ��ţ� ADC0�� ADC1��
*            ADC_Channel ͨ����
*            ADC_nbit    ���ȣ� ADC_8bit,ADC_12bit, ADC_10bit, ADC_16bit ��
*            N           ��ֵ�˲�����(��Χ:0~255)
*  �������أ�16λ�޷��Ž��ֵ
**/
u16 ad_ave(ADCn_Ch_e adcn_ch, ADC_nbit bit, u8 N) //��ֵ�˲�
{
	u32 tmp = 0;
	u8  i;

	for (i = 0; i < N; i++)
		tmp += adc_once(adcn_ch, bit);
	tmp = tmp / N;
	return (u16)tmp;
}
