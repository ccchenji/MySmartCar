/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_it.h
 * @brief      山外K60 平台中断服务重定向头文件
 * @author     山外科技
 * @version    v5.0
 * @date       2013-06-26
 */


#ifndef __MK60_IT_H__
#define __MK60_IT_H__

/*                          重新定义中断向量表
 */


//需要用到哪个中断，就定义哪个即可。下方有参考的模版

//#define NMI_Handler                                       nmi_irq
//#define HardFault_Handler                                 hardfault_irq
//#define SVC_Handler                                       svc_irq
//#define PendSV_Handler                                    pendsv_irq
//#define SysTick_Handler                                   systick_irq


//#define FTMRE_IRQHandler                                  ftmre_irq
//#define PMC_IRQHandler                                    pmc_irq
//#define IRQ_IRQHandler                                    irq_irq
//#define I2C0_IRQHandler                                   i2c0_irq
//#define I2C1_IRQHandler                                   i2c1_irq
//#define SPI0_IRQHandler                                   spi0_irq
//#define SPI1_IRQHandler                                   spi1_irq
//#define UART0_IRQHandler                                  uart0_irq
//#define UART1_IRQHandler                                  uart1_irq
//#define UART2_IRQHandler                                  uart2_irq
//#define ADC0_IRQHandler                                   adc0_irq
//#define ACMP0_IRQHandler                                  acmp0_irq
//#define FTM0_IRQHandler                                   ftm0_irq
//#define FTM1_IRQHandler                                   ftm1_irq
//#define FTM2_IRQHandler                                   ftm2_irq
//#define RTC_IRQHandler                                    rtc_irq
//#define ACMP1_IRQHandler                                  acmp1_irq
#define PIT_CH0_IRQHandler                                pit0_irq
#define PIT_CH1_IRQHandler                                pit1_irq
//#define KBI0_IRQHandler                                   kbi0_irq
//#define KBI1_IRQHandler                                   kbi1_irq
//#define ICS_IRQHandler                                    ics_irq
//#define WDOG_IRQHandler                                   wdog_irq
//#define PWT_IRQHandler                                    pwt_irq
//#define MSCAN_Rx_IRQHandler                               mscan_rx_irq
//#define MSCAN_Tx_Err_WakeUp_IRQHandler                    mscan_tx_err_wakeup_irq





#endif  //__MK60_IT_H__
