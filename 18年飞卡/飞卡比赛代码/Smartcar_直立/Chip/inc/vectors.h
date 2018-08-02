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
 * @brief      �ж�������ĺ�����ַ����
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-07-02
 * @note       ���´���ӷ�˼�����ٷ����̼̳���������΢�޸�
 */

#ifndef __VECTORS_H
#define __VECTORS_H     1

extern void default_isr(void);                  //����Ĭ���жϷ�����

typedef void (*vector_entry)(void);             //�����ж�������ĺ�������

extern void Reset_Handler (void);                //������λ�������� .s �ļ��ﶨ��

extern unsigned long __BOOT_STACK_ADDRESS[];    //����ջ��ַ����linker�ļ���*.icf �����

// Address     Vector IRQ   Source module   Source description
#define VECTOR_000      (vector_entry)__BOOT_STACK_ADDRESS  //          ARM core        Initial Supervisor SP

#define VECTOR_001          Reset_Handler   // 1 -                           Reset_Handler        Initial Program Counter


#ifdef NMI_Handler
extern void NMI_Handler(void);
#else
#define NMI_Handler    nmi_handler_default
static void nmi_handler_default(void)
{
    default_isr();
}
#endif

#ifdef HardFault_Handler
extern void HardFault_Handler(void);
#else
#define HardFault_Handler    hardfault_handler_default      //�ں˹����ж�
static void hardfault_handler_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_004
extern void VECTOR_004(void);
#else
#define VECTOR_004    vector_004_default
static void vector_004_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_005
extern void VECTOR_005(void);
#else
#define VECTOR_005    vector_005_default
static void vector_005_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_006
extern void VECTOR_006(void);
#else
#define VECTOR_006    vector_006_default
static void vector_006_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_007
extern void VECTOR_007(void);
#else
#define VECTOR_007    vector_007_default
static void vector_007_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_008
extern void VECTOR_008(void);
#else
#define VECTOR_008    vector_008_default
static void vector_008_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_009
extern void VECTOR_009(void);
#else
#define VECTOR_009    vector_009_default
static void vector_009_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_010
extern void VECTOR_010(void);
#else
#define VECTOR_010    vector_010_default
static void vector_010_default(void)
{
    default_isr();
}
#endif

#ifdef SVC_Handler
extern void SVC_Handler(void);
#else
#define SVC_Handler    svc_handler_default
static void svc_handler_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_012
extern void VECTOR_012(void);
#else
#define VECTOR_012    vector_012_default
static void vector_012_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_013
extern void VECTOR_013(void);
#else
#define VECTOR_013    vector_013_default
static void vector_013_default(void)
{
    default_isr();
}
#endif

#ifdef PendSV_Handler
extern void PendSV_Handler(void);
#else
#define PendSV_Handler    pendsv_handler_default         //ϵͳ������������ж�
static void pendsv_handler_default(void)
{
    default_isr();
}
#endif

#ifdef SysTick_Handler
extern void SysTick_Handler(void);
#else
#define SysTick_Handler    systick_handler_default        //�δ�ʱ���ж�
static void systick_handler_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_016
extern void VECTOR_016(void);
#else
#define VECTOR_016    vector_016_default
static void vector_016_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_017
extern void VECTOR_017(void);
#else
#define VECTOR_017    vector_017_default
static void vector_017_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_018
extern void VECTOR_018(void);
#else
#define VECTOR_018    vector_018_default
static void vector_018_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_019
extern void VECTOR_019(void);
#else
#define VECTOR_019    vector_019_default
static void vector_019_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_020
extern void VECTOR_020(void);
#else
#define VECTOR_020    vector_020_default
static void vector_020_default(void)
{
    default_isr();
}
#endif

#ifdef FTMRE_IRQHandler
extern void FTMRE_IRQHandler(void);
#else
#define FTMRE_IRQHandler    ftmre_irqhandler_default       //FTMRE       �������
static void ftmre_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef PMC_IRQHandler
extern void PMC_IRQHandler(void);
#else
#define PMC_IRQHandler    pmc_irqhandler_default         //PMC         �͵�ѹ����
static void pmc_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef IRQ_IRQHandler
extern void IRQ_IRQHandler(void);
#else
#define IRQ_IRQHandler    irq_irqhandler_default         //IRQ         �ⲿIO�ж�
static void irq_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef I2C0_IRQHandler
extern void I2C0_IRQHandler(void);
#else
#define I2C0_IRQHandler    i2c0_irqhandler_default        //I2C0
static void i2c0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef I2C1_IRQHandler
extern void I2C1_IRQHandler(void);
#else
#define I2C1_IRQHandler    i2c1_irqhandler_default        //I2C1
static void i2c1_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef SPI0_IRQHandler
extern void SPI0_IRQHandler(void);
#else
#define SPI0_IRQHandler    spi0_irqhandler_default        //SPI0
static void spi0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef SPI1_IRQHandler
extern void SPI1_IRQHandler(void);
#else
#define SPI1_IRQHandler    spi1_irqhandler_default        //SPI1
static void spi1_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef UART0_IRQHandler
extern void UART0_IRQHandler(void);
#else
#define UART0_IRQHandler    uart0_irqhandler_default       //UART0       ״̬�ʹ���
static void uart0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef UART1_IRQHandler
extern void UART1_IRQHandler(void);
#else
#define UART1_IRQHandler    uart1_irqhandler_default       //UART1       ״̬�ʹ���
static void uart1_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef UART2_IRQHandler
extern void UART2_IRQHandler(void);
#else
#define UART2_IRQHandler    uart2_irqhandler_default       //UART2       ״̬�ʹ���
static void uart2_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef ADC0_IRQHandler
extern void ADC0_IRQHandler(void);
#else
#define ADC0_IRQHandler    adc0_irqhandler_default        //ADC0        ADCת������ж�
static void adc0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef ACMP0_IRQHandler
extern void ACMP0_IRQHandler(void);
#else
#define ACMP0_IRQHandler    acmp0_irqhandler_default       //ACMP0       ģ��Ƚ���0�ж�
static void acmp0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef FTM0_IRQHandler
extern void FTM0_IRQHandler(void);
#else
#define FTM0_IRQHandler    ftm0_irqhandler_default        //FTM0
static void ftm0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef FTM1_IRQHandler
extern void FTM1_IRQHandler(void);
#else
#define FTM1_IRQHandler    ftm1_irqhandler_default        //FTM1
static void ftm1_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef FTM2_IRQHandler
extern void FTM2_IRQHandler(void);
#else
#define FTM2_IRQHandler    ftm2_irqhandler_default        //FTM2
static void ftm2_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef RTC_IRQHandler
extern void RTC_IRQHandler(void);
#else
#define RTC_IRQHandler    rtc_irqhandler_default         //RTC         RTC���
static void rtc_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef ACMP1_IRQHandler
extern void ACMP1_IRQHandler(void);
#else
#define ACMP1_IRQHandler    acmp1_irqhandler_default       //ACMP1       ģ��Ƚ���1�ж�
static void acmp1_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef PIT_CH0_IRQHandler
extern void PIT_CH0_IRQHandler(void);
#else
#define PIT_CH0_IRQHandler    pit_ch0_irqhandler_default     //PIT_CH0     PITͨ��0���
static void pit_ch0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef PIT_CH1_IRQHandler
extern void PIT_CH1_IRQHandler(void);
#else
#define PIT_CH1_IRQHandler    pit_ch1_irqhandler_default     //PIT_CH1     PITͨ��1���
static void pit_ch1_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef KBI0_IRQHandler
extern void KBI0_IRQHandler(void);
#else
#define KBI0_IRQHandler    kbi0_irqhandler_default        //KBI0        Keyboard�����ж�0
static void kbi0_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef KBI1_IRQHandler
extern void KBI1_IRQHandler(void);
#else
#define KBI1_IRQHandler    kbi1_irqhandler_default        //KBI1        Keyboard�����ж�1
static void kbi1_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef VECTOR_042
extern void VECTOR_042(void);
#else
#define VECTOR_042    vector_042_default
static void vector_042_default(void)
{
    default_isr();
}
#endif

#ifdef ICS_IRQHandler
extern void ICS_IRQHandler(void);
#else
#define ICS_IRQHandler    ics_irqhandler_default         //ICS         ���໷ʱ�Ӷ�ʧ
static void ics_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef WDOG_IRQHandler
extern void WDOG_IRQHandler(void);
#else
#define WDOG_IRQHandler    wdog_irqhandler_default        //WDOG        ���Ź�ʱ�䵽
static void wdog_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef PWT_IRQHandler
extern void PWT_IRQHandler(void);
#else
#define PWT_IRQHandler    pwt_irqhandler_default         //PWT
static void pwt_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef MSCAN_Rx_IRQHandler
extern void MSCAN_Rx_IRQHandler(void);
#else
#define MSCAN_Rx_IRQHandler    mscan_rx_irqhandler_default
static void mscan_rx_irqhandler_default(void)
{
    default_isr();
}
#endif

#ifdef MSCAN_Tx_Err_WakeUp_IRQHandler
extern void MSCAN_Tx_Err_WakeUp_IRQHandler(void);
#else
#define MSCAN_Tx_Err_WakeUp_IRQHandler    mscan_tx_err_wakeup_irqhandler_default
static void mscan_tx_err_wakeup_irqhandler_default(void)
{
    default_isr();
}
#endif





/* Flash configuration field values below */
/* Please be careful when modifying any of
 * the values below as it can secure the
 * flash (possibly permanently).
 */
#define CONFIG_1    (vector_entry)0xffffffff
#define CONFIG_2    (vector_entry)0xffffffff
#define CONFIG_3    (vector_entry)0xffffffff
#define CONFIG_4    (vector_entry)0xfffeffff

#endif /*__VECTORS_H*/

/* End of "vectors.h" */
