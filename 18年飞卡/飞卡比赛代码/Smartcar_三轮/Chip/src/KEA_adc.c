/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_adc.c
 * @brief      ADC函数
 * @author     山外科技
 * @version    v5.1
 * @date       2014-01-16
 */

#include "common.h"
#include "KEA_adc.h"


static void  inline   adc_start   (ADCn_Ch_e, ADC_nbit);    //开始adc转换

/*!
 *  @brief      ADC初始化
 *  @param      ADCn_Ch_e    ADC通道
 *  @since      v5.0
 *  @note       此初始化仅支持软件触发，不是每个通道都支持ADC 软件触发，
                具体说明见 ADCn_Ch_e 的注释说明
 *  Sample usage:       adc_init (ADC0_SE10 );    //初始化 ADC0_SE10
 */
void adc_init(ADCn_Ch_e adcn_ch)
{

    ASSERT(adcn_ch < ADCn_Ch_MAX ) ;

    SIM_SCGC |= SIM_SCGC_ADC_MASK;  //使能时钟

    ADC_APCTL1 |= 1 << adcn_ch;     //引脚号

    ADC_SC2 = (0
               //|  ADC_SC2_ADTRG_MASK  //0为软触发。1为硬件触发
               |  ADC_SC2_REFSEL(0)     //使用外部参考电压 VREFH/VREFL
              );
}

/*!
 *  @brief      获取ADC采样值(不支持B通道)
 *  @param      ADCn_Ch_e    ADC通道
 *  @param      ADC_nbit     ADC精度（ ADC_8bit,ADC_12bit, ADC_10bit, ADC_16bit ）
 *  @return     采样值
 *  @since      v5.0
 *  Sample usage:       uint16 var = adc_once(ADC0_SE10, ADC_8bit);
 */
uint16 adc_once(ADCn_Ch_e adcn_ch, ADC_nbit bit) //采集某路模拟量的AD值
{
    uint16 result = 0;

    adc_start(adcn_ch, bit);      //启动ADC转换

    while (!( ADC_SC1 & ADC_SC1_COCO_MASK ));   //等待转换完成
    result = ADC_R;
    ADC_SC1 &= ~ADC_SC1_COCO_MASK;
    return result;
}

/*!
 *  @brief      启动ADC软件采样(不支持B通道)
 *  @param      ADCn_Ch_e    ADC通道
 *  @param      ADC_nbit     ADC精度（ ADC_8bit,ADC_12bit, ADC_10bit, ADC_16bit ）
 *  @since      v5.0
 *  @note       此函数内部调用，启动后即可等待数据采集完成
 *  Sample usage:       adc_start(ADC0_SE10, ADC_8bit);
 */
void adc_start(ADCn_Ch_e adcn_ch, ADC_nbit bit)
{
    ADC->SC3  = (0
                  |ADC_SC3_ADICLK(0)            //选择总线时钟
                  |ADC_SC3_MODE(bit)            //分辨率采集
                  //|ADC_SC3_ADLSMP_MASK        //0为短采样时间
                  |ADC_SC3_ADIV(0)              //分频系数为1
                  //|ADC_SC3_ADLPC_MASK         //长步长时间
                  );
                  
    //写入 SC1 启动转换
    ADC_SC1                     = (0
                                   | ADC_SC1_AIEN_MASK          // 转换完成中断,0为禁止，1为使能
                                   //| ADC_SC1_DIFF_MASK        // 差分模式使能,0为单端，1为差分
                                   | ADC_SC1_ADCH( adcn_ch )
                                  );

}

/*!
 *  @brief      停止ADC软件采样
 *  @param      ADCn_e       ADC模块号（ ADC0、 ADC1）
 *  @since      v5.0
 *  Sample usage:       adc_stop(ADC0);
 */
void adc_stop(ADCn_e adcn)
{
    ADC_SC1 = (0
               | ADC_SC1_AIEN_MASK                       // 转换完成中断,0为禁止，1为使能
               //| ADC_SC1_DIFF_MASK                     // 差分模式使能,0为单端，1为差分
               | ADC_SC1_ADCH(Module0_Dis)               //输入通道选择,此处选择禁止通道
              );
}

