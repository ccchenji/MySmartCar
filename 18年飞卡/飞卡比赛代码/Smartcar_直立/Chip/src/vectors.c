/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       vectors.c
 * @brief      中断向量表
 * @author     山外科技
 * @version    v5.0
 * @date       2013-07-02
 */

#include "MKEA128_it.h"
#include "vectors.h"
#include "common.h"




#pragma location = ".intvec"                    //指定 如下数组放入 intvec 段
const vector_entry  __vector_table[] =          //@ ".intvec" =
{
    VECTOR_000,           /* 此值复位启动时复制到 SP ，即指定栈地址          */
    VECTOR_001,           /* 此值复位启动时复制到 PC ，即启动马上执行的函数  */
    NMI_Handler,
    HardFault_Handler,      //内核故障中断
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
    PendSV_Handler,         //系统服务挂起请求中断
    SysTick_Handler,        //滴答定时器中断

    VECTOR_016,
    VECTOR_017,
    VECTOR_018,
    VECTOR_019,
    VECTOR_020,
    FTMRE_IRQHandler,       //FTMRE       命令完成
    PMC_IRQHandler,         //PMC         低电压警告
    IRQ_IRQHandler,         //IRQ         外部IO中断
    I2C0_IRQHandler,        //I2C0
    I2C1_IRQHandler,        //I2C1
    SPI0_IRQHandler,        //SPI0
    SPI1_IRQHandler,        //SPI1
    UART0_IRQHandler,       //UART0       状态和错误
    UART1_IRQHandler,       //UART1       状态和错误
    UART2_IRQHandler,       //UART2       状态和错误
    ADC0_IRQHandler,        //ADC0        ADC转换完成中断
    ACMP0_IRQHandler,       //ACMP0       模拟比较器0中断
    FTM0_IRQHandler,        //FTM0
    FTM1_IRQHandler,        //FTM1
    FTM2_IRQHandler,        //FTM2
    RTC_IRQHandler,         //RTC         RTC溢出
    ACMP1_IRQHandler,       //ACMP1       模拟比较器1中断
    PIT_CH0_IRQHandler,     //PIT_CH0     PIT通道0溢出
    PIT_CH1_IRQHandler,     //PIT_CH1     PIT通道1溢出
    KBI0_IRQHandler,        //KBI0        Keyboard键盘中断0
    KBI1_IRQHandler,        //KBI1        Keyboard键盘中断1
    VECTOR_042,
    ICS_IRQHandler,         //ICS         锁相环时钟丢失
    WDOG_IRQHandler,        //WDOG        看门狗时间到
    PWT_IRQHandler,         //PWT
    MSCAN_Rx_IRQHandler,
    MSCAN_Tx_Err_WakeUp_IRQHandler,


};


/******************************************************************************/
/* End of "vectors.c" */
