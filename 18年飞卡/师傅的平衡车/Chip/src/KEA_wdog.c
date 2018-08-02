/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_wdog.c
 * @brief      看门狗驱动函数
 * @author     山外科技
 * @version    v5.1
 * @date       2014-04-25
 */

#include "common.h"
#include "KEA_wdog.h"

//内部函数声明
static void wdog_unlock(void);          //看门狗解锁

/*!
 *  @brief      初始化看门狗，设置喂狗时间
 *  @param      cnt     喂狗时间（单位为 ms）
 *  @since      v5.0
 */
void wdog_init_ms(uint16 ms)
{
    ASSERT(ms > 0);                                //断言，计数时间最小为4个时钟周期（WDOG_TOVALL里说明）

    wdog_unlock();                                  //解锁看门狗，这样才能配置看门狗

    WDOG_TOVALH = ms >> 8;                         //设置喂狗时间
    WDOG_TOVALL = (uint8)ms;

    WDOG_CS2 = ( 0
                 //| WDOG_CS2_PRES_MASK    //是否 256分频
                 | WDOG_CS2_CLK(1)   //看门狗时钟选择（0为 bus ，1 为 1 kHz 内部低功耗振荡器(LPOCLK)。2为 32 kHz 内部振荡器(ICSIRCLK)。）

               );
    WDOG_CS1 = (0
                | WDOG_CS1_EN_MASK          //WDOG 使能
                | WDOG_CS1_UPDATE_MASK      //允许更新
                | WDOG_CS1_DBG_MASK         //Debug 模式使能
                | WDOG_CS1_WAIT_MASK        //Wait 模式使能
                | WDOG_CS1_STOP_MASK        //Stop 模式使能
               );

}


/*!
 *  @brief      启用看门狗
 *  @since      v5.0
 */
void wdog_enable(void)
{
    wdog_unlock();                                  //解锁看门狗，这样才能配置看门狗

    WDOG_CS1 = (0
                | WDOG_CS1_EN_MASK          //WDOG 使能
                | WDOG_CS1_UPDATE_MASK      //允许更新
                | WDOG_CS1_DBG_MASK         //Debug 模式使能
                | WDOG_CS1_WAIT_MASK        //Wait 模式使能
                | WDOG_CS1_STOP_MASK        //Stop 模式使能
               );
}


/*!
 *  @brief      禁用看门狗
 *  @since      v5.0
 */
void wdog_disable(void)
{
    wdog_unlock();                                  //解锁看门狗，这样才能配置看门狗

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
 *  @brief      喂狗
 *  @since      v5.0
 */
void wdog_feed(void)
{
    //此函数不能单步执行

    //WDOG_REFRESH 寄存器里描述，连续向此寄存器写入0xA602 、0xB480即可解锁，
    //中间不得超过20个时钟周期，因此需要先关总中断

    unsigned long   tmp = __get_PRIMASK();    //用于返回寄存器 PRIMASK 的值(1bit)
    //1表示关中断，0表示开中断

    //关闭总中断，否则有可能没法在 20个周期内连续写入 WDOG_UNLOCK
    __set_PRIMASK(1);

    //更新 看门狗（喂狗）
    WDOG_CNT = 0x02A6;
    WDOG_CNT = 0x80B4;

    __set_PRIMASK(tmp) ;
}

/*!
 *  @brief      解锁看门狗
 *  @since      v5.0
 */
void wdog_unlock(void)
{
    //此函数不能单步执行

    //WDOG_UNLOCK 寄存器里描述，连续向此寄存器写入0xC520、0xD928即可解锁，
    //中间不得超过20个时钟周期，因此需要先关总中断

    unsigned long   tmp = __get_PRIMASK();    //用于返回寄存器 PRIMASK 的值(1bit)
    //1表示关中断，0表示开中断

    //关闭总中断，否则有可能没法在 20个周期内连续写入 WDOG_UNLOCK
    __set_PRIMASK(1);

    //解锁 看门狗
    WDOG_CNT  = 0x20C5;
    WDOG_CNT  = 0x28D9;

    __set_PRIMASK(tmp) ;
}

