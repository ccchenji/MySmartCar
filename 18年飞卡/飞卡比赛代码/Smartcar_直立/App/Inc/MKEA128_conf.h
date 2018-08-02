/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MKEA128_conf.h
 * @brief      ɽ��K60 ƽ̨�����ļ�
 * @author     ɽ��Ƽ�
 * @version    v5.1
 * @date       2013-06-26
 */

#ifndef __MK66_CONF_H__
#define __MK66_CONF_H__

/*
 * ����ƽ̨[���ڹ���ѡ���ﶨ��]
 */
//#define MK60DZ10
//#define MK60F15
//#define  MK66F18
//#define  MKEA128

/*
 * ����LCD�ͺ�
 */
#define LCD_ST7735S     2       //LCD_ST7735S �� LCD_ST7735R ���һ�����Ĵ����������в�ͬ
#define LCD_ST7735R     3       //

#define USE_LCD         LCD_ST7735S             //ѡ��ʹ�õ� LCD

/*
 * ѡ���Ƿ����������Ϣ���������ע������ĺ궨��
 */
#define DEBUG_PRINT

/*
 * ���徧��ʱ�ӣ���λΪMHz
 */
#define EXTAL_IN_MHz            (8)


/*
 * ���� ICS ��Ƶ Ƶ�� (��ͬ��ƽ̨���в�ͬ�ĳ�Ƶ����)
 */
#define CORE_CLK                80      // 20��40 �� 80

#define BUS_ISDIV               1       // bus�Ƿ��CORE����Ƶ��1Ϊ��Ƶ��0Ϊ����Ƶ
#define TIMER_ISDIV             1       // timer�Ƿ��CORE����Ƶ��1Ϊ��Ƶ��0Ϊ����Ƶ


/*
 * ���� printf���� �� ��������˿� �� ������Ϣ
 */
#define VCAN_PORT           UART0
#define VCAN_BAUD           115200

/*
 * ������ʱ����
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
 * ���ö��Ժ���ʵ�ֺ���
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
 * ���õ����������
 */
#if( defined(DEBUG_MODE) && defined(DEBUG_PRINT))
#define DEBUG_PRINTF(FORMAT,...)        do{printf(FORMAT,##__VA_ARGS__);}while(0)	/*�����ӡ������Ϣʱ���뽫������ע�͵�*/
#else
#define DEBUG_PRINTF(FORMAT,...)
#endif


#endif /* __MK66_CONF_H__  */
