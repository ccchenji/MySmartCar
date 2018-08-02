/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_conf.c
 * @brief      ɽ��K60 ƽ̨���ù���ʵ���ļ�
 * @author     ɽ��Ƽ�
 * @version    v5.1
 * @date       2013-06-26
 */

#include    "common.h"
//#include    "stdio.h"
#include    "include.h"
#include    "KEA_uart.h"


/*!
 *  @brief      ����ʧ����ִ�еĺ���
 *  @param      file    �ļ�·����ַ
 *  @param      line    ����
 *  @since      v5.0
 *  Sample usage:       assert_failed(__FILE__, __LINE__);
 */
const char ASSERT_FAILED_STR[] = "Assertion failed in %s at line %d\n";

void assert_failed(char *file, int line)
{
    //led_init(LED0);
    while (1)
    {

        DEBUG_PRINTF(ASSERT_FAILED_STR, file, line);      //ͨ��������ʾ����ʧ��

        //��ѭ���ȴ�����Ա���Ϊ�ζ���ʧ��
        led_turn(LED0);
        DELAY_MS(1000);

    }
}

/*!
 *  @brief      �ض���printf ������
 *  @param      ch      ��Ҫ��ӡ���ֽ�
 *  @param      stream  ������
 *  @since      v5.0
 *  @note       �˺����ɱ������Դ������printf������
 */
/*
int fputc(int ch, FILE *stream)
{
    uart_putchar(VCAN_PORT, (char)ch);
    return(ch);
} */


/*!
 *  @brief      �ض���printf ������
 *  @param      ch      ��Ҫ��ӡ���ֽ�
 *  @param      stream  ������
 *  @since      v5.0
 *  @note       �˺�����ɽ��FWD�����printf������
 */
int enter_fputc(char ch)
{
    uart_putchar(VCAN_PORT, (char)ch);
    return(ch);
}

/*!
 *  @brief      Ĭ���жϷ�����
 *  @since      v5.0
 *  @note       �˺���д���ж������������Ҫ�û�ִ��
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
