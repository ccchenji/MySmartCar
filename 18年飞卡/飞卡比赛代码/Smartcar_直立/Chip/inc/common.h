/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       common.h
 * @brief      山外K60 平台常用类型声明和宏定义
 * @author     山外科技
 * @version    v5.1
 * @date       2014-04-25
 */

#ifndef _COMMON_H_
#define _COMMON_H_

/*
 * 数据类型声明
 */
typedef unsigned char       uint8;  /*  8 bits */
typedef unsigned short int  uint16; /* 16 bits */
typedef unsigned long int   uint32; /* 32 bits */
typedef unsigned long long  uint64; /* 64 bits */

typedef char                int8;   /*  8 bits */
typedef short int           int16;  /* 16 bits */
typedef long  int           int32;  /* 32 bits */
typedef long  long          int64;  /* 64 bits */

typedef volatile int8       vint8;  /*  8 bits */
typedef volatile int16      vint16; /* 16 bits */
typedef volatile int32      vint32; /* 32 bits */
typedef volatile int64      vint64; /* 64 bits */

typedef volatile uint8      vuint8;  /*  8 bits */
typedef volatile uint16     vuint16; /* 16 bits */
typedef volatile uint32     vuint32; /* 32 bits */
typedef volatile uint64     vuint64; /* 64 bits */

/*
 * 定义带位域的联合体类型
 */
typedef union
{
    uint32  DW;
    uint16  W[2];
    uint8   B[4];
    struct
    {
        uint32 b0: 1;
        uint32 b1: 1;
        uint32 b2: 1;
        uint32 b3: 1;
        uint32 b4: 1;
        uint32 b5: 1;
        uint32 b6: 1;
        uint32 b7: 1;
        uint32 b8: 1;
        uint32 b9: 1;
        uint32 b10: 1;
        uint32 b11: 1;
        uint32 b12: 1;
        uint32 b13: 1;
        uint32 b14: 1;
        uint32 b15: 1;
        uint32 b16: 1;
        uint32 b17: 1;
        uint32 b18: 1;
        uint32 b19: 1;
        uint32 b20: 1;
        uint32 b21: 1;
        uint32 b22: 1;
        uint32 b23: 1;
        uint32 b24: 1;
        uint32 b25: 1;
        uint32 b26: 1;
        uint32 b27: 1;
        uint32 b28: 1;
        uint32 b29: 1;
        uint32 b30: 1;
        uint32 b31: 1;
    };
} Dtype;    //sizeof(Dtype) 为 4

/*
 * 定义坐标结构体
 */
typedef struct
{
    uint16 x;
    uint16 y;
} Site_t;

/*
 * 定义矩形大小结构体
 */
typedef struct
{
    uint16 W;       //宽
    uint16 H;       //高
} Size_t;

#define TRUE    1
#define FALSE   0

#define ENABLE    1
#define DISABLE   0

/*
 * 中断号类型声明
 */
typedef enum
{
    /* Core interrupts */
    NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
    HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
    SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
    PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
    SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

    /* Device specific interrupts */
    Reserved16_IRQn              = 0,                /**< Reserved interrupt */
    Reserved17_IRQn              = 1,                /**< Reserved interrupt */
    Reserved18_IRQn              = 2,                /**< Reserved interrupt */
    Reserved19_IRQn              = 3,                /**< Reserved interrupt */
    Reserved20_IRQn              = 4,                /**< Reserved interrupt */
    FTMRE_IRQn                   = 5,                /**< Command complete and read collision */
    PMC_IRQn                     = 6,                /**< Low-voltage detect, low-voltage warning */
    IRQ_IRQn                     = 7,                /**< External Interrupt */
    I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
    I2C1_IRQn                    = 9,                /**< I2C1 interrupt */
    SPI0_IRQn                    = 10,               /**< SPI0 single interrupt vector for all sources */
    SPI1_IRQn                    = 11,               /**< SPI1 single interrupt vector for all sources */
    UART0_IRQn                   = 12,               /**< UART0 status and error */
    UART1_IRQn                   = 13,               /**< UART1 status and error */
    UART2_IRQn                   = 14,               /**< UART2 status and error */
    ADC_IRQn                     = 15,               /**< ADC interrupt */
    ACMP0_IRQn                   = 16,               /**< ACMP0 interrupt */
    FTM0_IRQn                    = 17,               /**< FTM0 single interrupt vector for all sources */
    FTM1_IRQn                    = 18,               /**< FTM1 single interrupt vector for all sources */
    FTM2_IRQn                    = 19,               /**< FTM2 single interrupt vector for all sources */
    RTC_IRQn                     = 20,               /**< RTC overflow */
    ACMP1_IRQn                   = 21,               /**< ACMP1 interrupt */
    PIT_CH0_IRQn                 = 22,               /**< PIT CH0 overflow */
    PIT_CH1_IRQn                 = 23,               /**< PIT CH1 overflow */
    KBI0_IRQn                    = 24,               /**< Keyboard interrupt0(32bit) */
    KBI1_IRQn                    = 25,               /**< Keyboard interrupt1(32bit) */
    Reserved42_IRQn              = 26,               /**< Reserved interrupt */
    ICS_IRQn                     = 27,               /**< ICS interrupt */
    WDOG_IRQn                    = 28,               /**< Watchdog timeout */
    PWT_IRQn                     = 29,               /**< PWT interrupt */
    MSCAN_RX_IRQn                = 30,               /**< MSCAN Rx Interrupt */
    MSCAN_TX_IRQn                = 31                /**< MSCAN Tx, Err and Wake-up interrupt */
} IRQn_t, IRQn_Type;



/*
 * 中断向量表编号声明
 */
typedef enum
{
    /* Core interrupts */
    NonMaskableInt_VECTORn           = 2,              /**< Non Maskable Interrupt */
    HardFault_VECTORn                = 3,              /**< Cortex-M0 SV Hard Fault Interrupt */
    SVCall_VECTORn                   = 11,               /**< Cortex-M0 SV Call Interrupt */
    PendSV_VECTORn                   = 14,               /**< Cortex-M0 Pend SV Interrupt */
    SysTick_VECTORn                  = 15,               /**< Cortex-M0 System Tick Interrupt */

    /* Device specific interrupts */
    FTMRE_VECTORn                    = 21,                /**< Command complete and read collision */
    PMC_VECTORn                      = 22,                /**< Low-voltage detect, low-voltage warning */
    IRQ_VECTORn                      = 23,                /**< External Interrupt */
    I2C0_VECTORn                     = 24,                /**< I2C0 interrupt */
    I2C1_VECTORn                     = 25,                /**< I2C1 interrupt */
    SPI0_VECTORn                     = 26,               /**< SPI0 single interrupt vector for all sources */
    SPI1_VECTORn                     = 27,               /**< SPI1 single interrupt vector for all sources */
    UART0_VECTORn                    = 28,               /**< UART0 status and error */
    UART1_VECTORn                    = 29,               /**< UART1 status and error */
    UART2_VECTORn                    = 30,               /**< UART2 status and error */
    ADC_VECTORn                      = 31,               /**< ADC interrupt */
    ACMP0_VECTORn                    = 32,               /**< ACMP0 interrupt */
    FTM0_VECTORn                     = 33,               /**< FTM0 single interrupt vector for all sources */
    FTM1_VECTORn                     = 34,               /**< FTM1 single interrupt vector for all sources */
    FTM2_VECTORn                     = 35,               /**< FTM2 single interrupt vector for all sources */
    RTC_VECTORn                      = 36,               /**< RTC overflow */
    ACMP1_VECTORn                    = 37,               /**< ACMP1 interrupt */
    PIT_CH0_VECTORn                  = 38,               /**< PIT CH0 overflow */
    PIT_CH1_VECTORn                  = 39,               /**< PIT CH1 overflow */
    KBI0_VECTORn                     = 40,               /**< Keyboard interrupt0(32bit) */
    KBI1_VECTORn                     = 41,               /**< Keyboard interrupt1(32bit) */

    ICS_VECTORn                      = 43,               /**< ICS interrupt */
    WDOG_VECTORn                     = 44,               /**< Watchdog timeout */
    PWT_VECTORn                      = 45,               /**< PWT interrupt */
    MSCAN_RX_VECTORn                 = 46,               /**< MSCAN Rx Interrupt */
    MSCAN_TX_VECTORn                 = 47                /**< MSCAN Tx, Err and Wake-up interrupt */
} VECTORn_t;

/*
 * 定义运行到RAM的函数
 */
#if defined(__ICCARM__)
//IAR 用 __ramfunc 来声明
#define     __RAMFUNC __ramfunc
#else
#define     __RAMFUNC
#endif


/*
 * 包含Cortex-M内核的通用头文件
 */
#include    <stdio.h>                       //printf
#include    <string.h>                      //memcpy
#include    <stdlib.h>                      //malloc
#include    <intrinsics.h>
#include "misc.h"        //这两个顺序不能反，因为 arm_math.h 里需要  __NVIC_PRIO_BITS 的定义

#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
//#define __NVIC_PRIO_BITS              2        /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  0         /**< Defines if an FPU is present or not */

#include "core_cm0plus.h"                  /* Core Peripheral Access Layer */
#include "core_cmFunc.h"
#include "arm_math.h"


/* 优先级分组  -------------------------------------------------*/
#define NVIC_PriorityGroup_0          ((uint32)0x7) /* 0 bits for pre-emption priority
4 bits for subpriority */
#define NVIC_PriorityGroup_1          ((uint32)0x6) /* 1 bits for pre-emption priority
3 bits for subpriority */
#define NVIC_PriorityGroup_2          ((uint32)0x5) /* 2 bits for pre-emption priority
    2 bits for subpriority */
#define NVIC_PriorityGroup_3          ((uint32)0x4) /* 3 bits for pre-emption priority
        1 bits for subpriority */
#define NVIC_PriorityGroup_4          ((uint32)0x3) /* 4 bits for pre-emption priority
            0 bits for subpriority */

                /*
                 * 包含山外K60平台的配置头文件
                 */
#include "MKEA128_conf.h"

                /*
                 * 包含平台头文件
                 */
#if   defined(MKEA128)

#include "SKEAZ1284.h"
#else
#error "error"
#endif



                /*
                 * 包含常用头文件
                 */
#include    "system_SKEAZ1284.h"             //系统配置
#include    "PORT_cfg.h"                    //管脚复用配置
#include    "MKEA128_conf.h"

#if (defined(IAR))
#include "intrinsics.h"
#endif




                /**
                 *  @brief 变量的位清0和置1
                 */
#define BIT_CLEAN(var,n)        (var) &= ~(1<<(n))   //变量var 的n位（即第n+1位）清0
#define BIT_SET(var,n)          (var) |=  (1<<(n))   //变量var 的n位（即第n+1位）置1
#define BIT_GET(var,n)          (((var)>>(n))&0x01)  //读取变量var 的n位（即第n+1位）

                /**
                 *  @brief 仿二进制赋值
                 */
#define  HEX__(n)   0x##n##UL
#define  B8__(x)   ( (x & 0x0000000FUL) ? 1:0 )\
    +( (x & 0x000000F0UL) ? 2:0 )\
    +( (x & 0x00000F00UL) ? 4:0 )\
    +( (x & 0x0000F000UL) ? 8:0 )\
    +( (x & 0x000F0000UL) ? 16:0 )\
    +( (x & 0x00F00000UL) ? 32:0 )\
    +( (x & 0x0F000000UL) ? 64:0 )\
    +( (x & 0xF0000000UL) ? 128:0 )
#define  B8(x)                                     ((unsigned char)B8__(HEX__(x)))
#define  B16(x_msb,x_lsb)                (((unsigned int)B8(x_msb)<<8) + B8(x_lsb))
#define  B32(x_msb,x_2,x_3,x_lsb)   (((unsigned long)B8(x_msb)<<24) + ((unsigned long)B8(x_2)<<16) + ((unsigned long)B8(x_3)<<8) + B8(x_lsb))
                /* Sample usage:
                B8(01010101) = 85
                B16(10101010,01010101) = 43605
                B32(10000000,11111111,10101010,01010101) = 2164238933
                */

                /*
                 * 打印宏定义展开结果
                 */
#define _MKSTR(str)  #str
#define MKSTR(str)  _MKSTR(str)                       //把宏定义展开结果转换为字符串

#define DEFINE_PRINTF(def)  printf(MKSTR(def)"\n")    //串口打印宏定义展开结果


                /*
                 * 求最大值和最小值
                 */
#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )


                /*
                 * 返回数组元素的个数
                 */
#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( ((a)[0]) ) )

                /*
                 * 宏定义实现返回绝对值（x里不能有自加自减的语句，否则变量出错）
                 */
#define ABS(x) (((x) > 0) ? (x) : (-(x)))

                /*
                 * 获取结构体某成员偏移
                 */
#define OFFSET(type, member)    (uint32)(&(((type *)0)->member))

                /*
                 * 确保x的范围为 min~max
                 */
#define RANGE(x,max,min)        ((uint8)((x)<(min) ? (min) : ( (x)>(max) ? (max):(x) )))

                /*
                 * 交换32位数据的4字节顺序
                 */
#if 1         //两种方法，第一种是CMSIS库自带
#define SWAP32(data)    __REV(data)
#else
#define SWAP32(data)    (uint32)((((uint32)(data) & (0xFFu<<0 ))<<24)      \
                          | (((uint32)(data) & (0xFFu<<8 ))<<8)            \
                          | (((uint32)(data) & (0xFFu<<16))>>8)            \
                          | (((uint32)(data) & (0xFFu<<24))>>24)           \
                        )
#endif

                /*
                 * 交换16位数据的2字节顺序
                 */
#if 1         //两种方法，第一种是CMSIS库自带
#define SWAP16(data)    __REVSH(data)
#else
#define SWAP16(data)    (uint32)((((uint16)(data) & (0xFF<<0 ))<<8)      \
                          | (((uint32)(data) & (0xFF<<8))>>8)            \
                        )
#endif

                /*
                 * 交换 x, y 的值
                 */
#define SWAP(x,y)           do{x^=y;y^=x;x^=y;}while(0)


                /********************************************************************/

#endif /* _COMMON_H_ */
