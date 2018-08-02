/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       port_cfg.h
 * @brief      山外K60 复用管脚配置
 * @author     山外科技
 * @version    v5.1
 * @date       2013-06-26
 */
#ifndef _PORT_CFG_H_
#define _PORT_CFG_H_

#include "KEA_port.h"

/**********************************    IRQ   ***************************************/
#define IRQ_PIN                  PTI2                //PTI0~I6 (另外一个PTA5为复位引脚，不可用)

/**********************************  UART   ***************************************/

#define UART0_RX_B0_TX_B1   0
#define UART0_RX_A2_TX_A3   1
#define USE_UART0_MODE          UART0_RX_A2_TX_A3       //定义 UART0 引脚方案


#define UART1_RX_C6_TX_C7   0
#define UART1_RX_F2_TX_F3   1
#define USE_UART1_MODE          UART1_RX_C6_TX_C7       //定义 UART1 引脚方案


#define UART2_RX_D6_TX_D7   0
#define UART2_RX_I0_TX_I1   1
#define USE_UART2_MODE          UART2_RX_D6_TX_D7       //定义 UART2 引脚方案


/**********************************  FTM    ***************************************/

//      模块通道    端口          可选范围              建议
#define FTM0_CH0_PIN    PTA0        //PTA0、PTB2
#define FTM0_CH1_PIN    PTA1        //PTA1、PTB3

//      模块通道    端口          可选范围              建议
#define FTM1_CH0_PIN    PTH2       //PTC4、PTH2      (C4 是下载口，不可用)
#define FTM1_CH1_PIN    PTE7       //PTC5、PTE7

//      模块通道    端口          可选范围              建议
#define FTM2_CH0_PIN    PTF0       //PTC0、PTF0、PTH0
#define FTM2_CH1_PIN    PTF1       //PTC1、PTF1、PTH1
#define FTM2_CH2_PIN    PTG4       //PTC2、PTD0、PTG4
#define FTM2_CH3_PIN    PTG5       //PTC3、PTD1、PTG5
#define FTM2_CH4_PIN    PTB4       //PTB4、PTG6       (B4是NMI中断引脚，有可能不稳定)
#define FTM2_CH5_PIN    PTB5       //PTB5、PTG7


#define TCLK0           PTA5              // (A5 是复位引脚，不可用)
#define TCLK1           PTE0
#define TCLK2           PTE7

#define FTM0_PULSE_PIN   PTA5        //从 TCLKn里任意选其中一个
#define FTM1_PULSE_PIN   PTA5        //从 TCLKn里任意选其中一个
#define FTM2_PULSE_PIN   PTA5        //从 TCLKn里任意选其中一个



#define PWT_IN0_PIN     PTD5           //PTD5、PTE2
#define PWT_IN1_PIN     PTH7           //PTB0、PTH7



/**********************************  SPI   ***************************************/
//PCS 可任意配置其他IO引脚

#define SPI0_CLK_B2_MO_B3_MI_B4_CS_B5  0
#define SPI0_CLK_E0_MO_E1_MI_E2_CS_E3  1
#define USE_SPI0_MODE          SPI0_CLK_E0_MO_E1_MI_E2_CS_E3       //定义 SPI0 引脚方案


#define SPI1_CLK_D0_MO_D1_MI_D2_CS_D3  0
#define SPI1_CLK_G4_MO_G5_MI_G6_CS_G7  1
#define USE_SPI1_MODE          SPI1_CLK_G4_MO_G5_MI_G6_CS_G7       //定义 SPI0 引脚方案




#endif  //_PORT_CFG_H_


