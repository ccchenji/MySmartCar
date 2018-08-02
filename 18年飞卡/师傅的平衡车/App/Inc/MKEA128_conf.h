/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MKEA128_conf.h
 * @brief      山外K60 平台配置文件
 * @author     山外科技
 * @version    v5.1
 * @date       2013-06-26
 */

#ifndef __MK66_CONF_H__
#define __MK66_CONF_H__

/*
 * 定义平台[放在工程选项里定义]
 */
//#define MK60DZ10
//#define MK60F15
//#define  MK66F18
//#define  MKEA128

/*
 * 定义LCD型号
 */
#define LCD_ST7735S     2       //LCD_ST7735S 与 LCD_ST7735R 外观一样，寄存器操作略有不同
#define LCD_ST7735R     3       //

#define USE_LCD         LCD_ST7735S             //选择使用的 LCD

/*
 * 选择是否输出调试信息，不输出则注释下面的宏定义
 */
#define DEBUG_PRINT

/*
 * 定义晶振时钟，单位为MHz
 */
#define EXTAL_IN_MHz            (8)


/*
 * 定义 ICS 超频 频率 (不同的平台，有不同的超频配置)
 */
#define CORE_CLK                80      // 20、40 或 80

#define BUS_ISDIV               1       // bus是否从CORE二分频，1为分频，0为不分频
#define TIMER_ISDIV             1       // timer是否从CORE二分频，1为分频，0为不分频


/*
 * 定义 printf函数 的 串口输出端口 和 串口信息
 */
#define VCAN_PORT           UART0
#define VCAN_BAUD           115200

/*
 * 配置延时函数
 */
#if 0
#include "KEA_pit.h"
#define DELAY()         pit_delay_ms(PIT1,500)
#define DELAY_MS(ms)    pit_delay_ms(PIT1,ms)
#define DELAY_US(us)    pit_delay_us(PIT1,us)
#elif 0
#include "KEA_SysTick.h"
#define DELAY()         systick_delay_ms(500)
#define DELAY_MS(ms)    systick_delay_ms(ms)
#define DELAY_US(us)    systick_delay_us(us)
#else
#include "misc.h"
#define DELAY()         soft_delay_ms(500)
#define DELAY_MS(ms)    soft_delay_ms(ms)
#define DELAY_US(us)    soft_delay_us(us)
#endif


/*
 * 配置断言和其实现函数
 */
void assert_failed(char *, int);

#if defined( DEBUG_MODE )
#define ASSERT(expr) \
    if (!(expr)) \
        assert_failed(__FILE__, __LINE__)
#else
#define ASSERT(expr)
#endif

/*
 * 配置调试输出函数
 */
#if( defined(DEBUG_MODE) && defined(DEBUG_PRINT))
#define DEBUG_PRINTF(FORMAT,...)        do{printf(FORMAT,##__VA_ARGS__);}while(0)	/*无需打印调试信息时，请将宏内容注释掉*/
#else
#define DEBUG_PRINTF(FORMAT,...)
#endif


#endif /* __MK66_CONF_H__  */
