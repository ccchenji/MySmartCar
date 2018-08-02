/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       vectors.c
 * @brief      �ж�������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-07-02
 */

#include "MKEA128_it.h"
#include "vectors.h"
#include "common.h"




#pragma location = ".intvec"                    //ָ�� ����������� intvec ��
const vector_entry  __vector_table[] =          //@ ".intvec" =
{
    VECTOR_000,           /* ��ֵ��λ����ʱ���Ƶ� SP ����ָ��ջ��ַ          */
    VECTOR_001,           /* ��ֵ��λ����ʱ���Ƶ� PC ������������ִ�еĺ���  */
    NMI_Handler,
    HardFault_Handler,      //�ں˹����ж�
    VECTOR_004,
    VECTOR_005,
    VECTOR_006,
    VECTOR_007,
    VECTOR_008,
    VECTOR_009,
    VECTOR_010,
    SVC_Handler,
    VECTOR_012,
    VECTOR_013,
    PendSV_Handler,         //ϵͳ������������ж�
    SysTick_Handler,        //�δ�ʱ���ж�

    VECTOR_016,
    VECTOR_017,
    VECTOR_018,
    VECTOR_019,
    VECTOR_020,
    FTMRE_IRQHandler,       //FTMRE       �������
    PMC_IRQHandler,         //PMC         �͵�ѹ����
    IRQ_IRQHandler,         //IRQ         �ⲿIO�ж�
    I2C0_IRQHandler,        //I2C0
    I2C1_IRQHandler,        //I2C1
    SPI0_IRQHandler,        //SPI0
    SPI1_IRQHandler,        //SPI1
    UART0_IRQHandler,       //UART0       ״̬�ʹ���
    UART1_IRQHandler,       //UART1       ״̬�ʹ���
    UART2_IRQHandler,       //UART2       ״̬�ʹ���
    ADC0_IRQHandler,        //ADC0        ADCת������ж�
    ACMP0_IRQHandler,       //ACMP0       ģ��Ƚ���0�ж�
    FTM0_IRQHandler,        //FTM0
    FTM1_IRQHandler,        //FTM1
    FTM2_IRQHandler,        //FTM2
    RTC_IRQHandler,         //RTC         RTC���
    ACMP1_IRQHandler,       //ACMP1       ģ��Ƚ���1�ж�
    PIT_CH0_IRQHandler,     //PIT_CH0     PITͨ��0���
    PIT_CH1_IRQHandler,     //PIT_CH1     PITͨ��1���
    KBI0_IRQHandler,        //KBI0        Keyboard�����ж�0
    KBI1_IRQHandler,        //KBI1        Keyboard�����ж�1
    VECTOR_042,
    ICS_IRQHandler,         //ICS         ���໷ʱ�Ӷ�ʧ
    WDOG_IRQHandler,        //WDOG        ���Ź�ʱ�䵽
    PWT_IRQHandler,         //PWT
    MSCAN_Rx_IRQHandler,
    MSCAN_Tx_Err_WakeUp_IRQHandler,


};


/******************************************************************************/
/* End of "vectors.c" */
