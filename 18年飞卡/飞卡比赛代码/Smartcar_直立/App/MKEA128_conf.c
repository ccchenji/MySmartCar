/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_conf.c
 * @brief      山外K60 平台配置功能实现文件
 * @author     山外科技
 * @version    v5.1
 * @date       2013-06-26
 */

#include    "common.h"
//#include    "stdio.h"
#include    "include.h"
#include    "KEA_uart.h"


/*!
 *  @brief      断言失败所执行的函数
 *  @param      file    文件路径地址
 *  @param      line    行数
 *  @since      v5.0
 *  Sample usage:       assert_failed(__FILE__, __LINE__);
 */
const char ASSERT_FAILED_STR[] = "Assertion failed in %s at line %d\n";

void assert_failed(char *file, int line)
{
    //led_init(LED0);
    while (1)
    {

        DEBUG_PRINTF(ASSERT_FAILED_STR, file, line);      //通过串口提示断言失败

        //死循环等待程序员检测为何断言失败
        led_turn(LED0);
        DELAY_MS(1000);

    }
}

/*!
 *  @brief      重定义printf 到串口
 *  @param      ch      需要打印的字节
 *  @param      stream  数据流
 *  @since      v5.0
 *  @note       此函数由编译器自带库里的printf所调用
 */
/*
int fputc(int ch, FILE *stream)
{
    uart_putchar(VCAN_PORT, (char)ch);
    return(ch);
} */


/*!
 *  @brief      重定义printf 到串口
 *  @param      ch      需要打印的字节
 *  @param      stream  数据流
 *  @since      v5.0
 *  @note       此函数由山外FWD库里的printf所调用
 */
int enter_fputc(char ch)
{
    uart_putchar(VCAN_PORT, (char)ch);
    return(ch);
}

/*!
 *  @brief      默认中断服务函数
 *  @since      v5.0
 *  @note       此函数写入中断向量表里，不需要用户执行
 */
void default_isr(void)
{
    led_init(LED0);
    while(1)
    {
        led_turn(LED0);
        DELAY_MS(1000);

    }
}
