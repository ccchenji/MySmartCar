/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_wdog.c
 * @brief      ���Ź���������
 * @author     ɽ��Ƽ�
 * @version    v5.1
 * @date       2014-04-25
 */

#include "common.h"
#include "KEA_wdog.h"

//�ڲ���������
static void wdog_unlock(void);          //���Ź�����

/*!
 *  @brief      ��ʼ�����Ź�������ι��ʱ��
 *  @param      cnt     ι��ʱ�䣨��λΪ ms��
 *  @since      v5.0
 */
void wdog_init_ms(uint16 ms)
{
    ASSERT(ms > 0);                                //���ԣ�����ʱ����СΪ4��ʱ�����ڣ�WDOG_TOVALL��˵����

    wdog_unlock();                                  //�������Ź��������������ÿ��Ź�

    WDOG_TOVALH = ms >> 8;                         //����ι��ʱ��
    WDOG_TOVALL = (uint8)ms;

    WDOG_CS2 = ( 0
                 //| WDOG_CS2_PRES_MASK    //�Ƿ� 256��Ƶ
                 | WDOG_CS2_CLK(1)   //���Ź�ʱ��ѡ��0Ϊ bus ��1 Ϊ 1 kHz �ڲ��͹�������(LPOCLK)��2Ϊ 32 kHz �ڲ�����(ICSIRCLK)����

               );
    WDOG_CS1 = (0
                | WDOG_CS1_EN_MASK          //WDOG ʹ��
                | WDOG_CS1_UPDATE_MASK      //�������
                | WDOG_CS1_DBG_MASK         //Debug ģʽʹ��
                | WDOG_CS1_WAIT_MASK        //Wait ģʽʹ��
                | WDOG_CS1_STOP_MASK        //Stop ģʽʹ��
               );

}


/*!
 *  @brief      ���ÿ��Ź�
 *  @since      v5.0
 */
void wdog_enable(void)
{
    wdog_unlock();                                  //�������Ź��������������ÿ��Ź�

    WDOG_CS1 = (0
                | WDOG_CS1_EN_MASK          //WDOG ʹ��
                | WDOG_CS1_UPDATE_MASK      //�������
                | WDOG_CS1_DBG_MASK         //Debug ģʽʹ��
                | WDOG_CS1_WAIT_MASK        //Wait ģʽʹ��
                | WDOG_CS1_STOP_MASK        //Stop ģʽʹ��
               );
}


/*!
 *  @brief      ���ÿ��Ź�
 *  @since      v5.0
 */
void wdog_disable(void)
{
    wdog_unlock();                                  //�������Ź��������������ÿ��Ź�

    WDOG_TOVAL = WDOG_TOVAL_TOVAL(0xE803);

    WDOG_CS2 = WDOG_CS2_CLK(0x01);
    WDOG_CS1 = (0
                | WDOG_CS1_UPDATE_MASK
                | WDOG_CS1_TST(0x00)
                | WDOG_CS1_WAIT_MASK
                | WDOG_CS1_STOP_MASK
               );

}

/*!
 *  @brief      ι��
 *  @since      v5.0
 */
void wdog_feed(void)
{
    //�˺������ܵ���ִ��

    //WDOG_REFRESH �Ĵ�����������������˼Ĵ���д��0xA602 ��0xB480���ɽ�����
    //�м䲻�ó���20��ʱ�����ڣ������Ҫ�ȹ����ж�

    unsigned long   tmp = __get_PRIMASK();    //���ڷ��ؼĴ��� PRIMASK ��ֵ(1bit)
    //1��ʾ���жϣ�0��ʾ���ж�

    //�ر����жϣ������п���û���� 20������������д�� WDOG_UNLOCK
    __set_PRIMASK(1);

    //���� ���Ź���ι����
    WDOG_CNT = 0x02A6;
    WDOG_CNT = 0x80B4;

    __set_PRIMASK(tmp) ;
}

/*!
 *  @brief      �������Ź�
 *  @since      v5.0
 */
void wdog_unlock(void)
{
    //�˺������ܵ���ִ��

    //WDOG_UNLOCK �Ĵ�����������������˼Ĵ���д��0xC520��0xD928���ɽ�����
    //�м䲻�ó���20��ʱ�����ڣ������Ҫ�ȹ����ж�

    unsigned long   tmp = __get_PRIMASK();    //���ڷ��ؼĴ��� PRIMASK ��ֵ(1bit)
    //1��ʾ���жϣ�0��ʾ���ж�

    //�ر����жϣ������п���û���� 20������������д�� WDOG_UNLOCK
    __set_PRIMASK(1);

    //���� ���Ź�
    WDOG_CNT  = 0x20C5;
    WDOG_CNT  = 0x28D9;

    __set_PRIMASK(tmp) ;
}

