/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_gpio_cfg.h
 * @brief      gpio的端口定义头文件
 * @author     山外
 * @version    v5.1
 * @date       2014-04-25
 */
#ifndef __MK60_GPIO_CFG_H__
#define __MK60_GPIO_CFG_H__

#include "common.h"



//1位操作
#define     _PTXn_T(ptxn,type)   (ptxn##_##type)
#define     PTXn_T(ptxn,type)    _PTXn_T(ptxn,type)






//定义PTA的输入端口
#define PTA0_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b0)
#define PTA1_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b1)
#define PTA2_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b2)
#define PTA3_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b3)
#define PTA4_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b4)
#define PTA5_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b5)
#define PTA6_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b6)
#define PTA7_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b7)

//定义PTB的输入端口
#define PTB0_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b8)
#define PTB1_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b9)
#define PTB2_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b10)
#define PTB3_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b11)
#define PTB4_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b12)
#define PTB5_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b13)
#define PTB6_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b14)
#define PTB7_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b15)

//定义PTC的输入端口
#define PTC0_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b16)
#define PTC1_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b17)
#define PTC2_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b18)
#define PTC3_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b19)
#define PTC4_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b20)
#define PTC5_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b21)
#define PTC6_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b22)
#define PTC7_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b23)

//定义PTD的输入端口
#define PTD0_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b24)
#define PTD1_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b25)
#define PTD2_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b26)
#define PTD3_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b27)
#define PTD4_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b28)
#define PTD5_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b29)
#define PTD6_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b30)
#define PTD7_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->b31)

//定义PTE的输入端口
#define PTE0_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b0)
#define PTE1_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b1)
#define PTE2_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b2)
#define PTE3_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b3)
#define PTE4_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b4)
#define PTE5_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b5)
#define PTE6_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b6)
#define PTE7_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b7)

//定义PTF的输入端口
#define PTF0_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b8)
#define PTF1_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b9)
#define PTF2_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b10)
#define PTF3_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b11)
#define PTF4_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b12)
#define PTF5_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b13)
#define PTF6_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b14)
#define PTF7_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b15)

//定义PTG的输入端口
#define PTG0_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b16)
#define PTG1_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b17)
#define PTG2_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b18)
#define PTG3_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b19)
#define PTG4_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b20)
#define PTG5_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b21)
#define PTG6_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b22)
#define PTG7_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b23)

//定义PTH的输入端口
#define PTH0_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b24)
#define PTH1_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b25)
#define PTH2_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b26)
#define PTH3_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b27)
#define PTH4_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b28)
#define PTH5_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b29)
#define PTH6_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b30)
#define PTH7_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->b31)

//定义PTI的输入端口
#define PTI0_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b0)
#define PTI1_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b1)
#define PTI2_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b2)
#define PTI3_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b3)
#define PTI4_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b4)
#define PTI5_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b5)
#define PTI6_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b6)
#define PTI7_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->b7)

//定义PTA的输入端口
#define PTA0_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b0)
#define PTA1_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b1)
#define PTA2_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b2)
#define PTA3_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b3)
#define PTA4_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b4)
#define PTA5_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b5)
#define PTA6_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b6)
#define PTA7_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b7)

//定义PTB的输入端口
#define PTB0_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b8)
#define PTB1_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b9)
#define PTB2_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b10)
#define PTB3_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b11)
#define PTB4_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b12)
#define PTB5_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b13)
#define PTB6_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b14)
#define PTB7_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b15)

//定义PTC的输入端口
#define PTC0_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b16)
#define PTC1_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b17)
#define PTC2_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b18)
#define PTC3_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b19)
#define PTC4_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b20)
#define PTC5_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b21)
#define PTC6_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b22)
#define PTC7_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b23)

//定义PTD的输入端口
#define PTD0_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b24)
#define PTD1_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b25)
#define PTD2_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b26)
#define PTD3_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b27)
#define PTD4_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b28)
#define PTD5_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b29)
#define PTD6_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b30)
#define PTD7_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->b31)

//定义PTE的输入端口
#define PTE0_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b0)
#define PTE1_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b1)
#define PTE2_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b2)
#define PTE3_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b3)
#define PTE4_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b4)
#define PTE5_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b5)
#define PTE6_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b6)
#define PTE7_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b7)

//定义PTF的输入端口
#define PTF0_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b8)
#define PTF1_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b9)
#define PTF2_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b10)
#define PTF3_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b11)
#define PTF4_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b12)
#define PTF5_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b13)
#define PTF6_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b14)
#define PTF7_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b15)

//定义PTG的输入端口
#define PTG0_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b16)
#define PTG1_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b17)
#define PTG2_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b18)
#define PTG3_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b19)
#define PTG4_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b20)
#define PTG5_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b21)
#define PTG6_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b22)
#define PTG7_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b23)

//定义PTH的输入端口
#define PTH0_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b24)
#define PTH1_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b25)
#define PTH2_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b26)
#define PTH3_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b27)
#define PTH4_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b28)
#define PTH5_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b29)
#define PTH6_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b30)
#define PTH7_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->b31)

//定义PTI的输入端口
#define PTI0_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b0)
#define PTI1_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b1)
#define PTI2_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b2)
#define PTI3_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b3)
#define PTI4_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b4)
#define PTI5_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b5)
#define PTI6_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b6)
#define PTI7_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->b7)

//定义PTA的输入端口
#define PTA0_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b0)
#define PTA1_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b1)
#define PTA2_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b2)
#define PTA3_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b3)
#define PTA4_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b4)
#define PTA5_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b5)
#define PTA6_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b6)
#define PTA7_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b7)

//定义PTB的输入端口
#define PTB0_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b8)
#define PTB1_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b9)
#define PTB2_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b10)
#define PTB3_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b11)
#define PTB4_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b12)
#define PTB5_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b13)
#define PTB6_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b14)
#define PTB7_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b15)

//定义PTC的输入端口
#define PTC0_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b16)
#define PTC1_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b17)
#define PTC2_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b18)
#define PTC3_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b19)
#define PTC4_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b20)
#define PTC5_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b21)
#define PTC6_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b22)
#define PTC7_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b23)

//定义PTD的输入端口
#define PTD0_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b24)
#define PTD1_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b25)
#define PTD2_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b26)
#define PTD3_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b27)
#define PTD4_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b28)
#define PTD5_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b29)
#define PTD6_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b30)
#define PTD7_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->b31)

//定义PTE的输入端口
#define PTE0_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b0)
#define PTE1_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b1)
#define PTE2_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b2)
#define PTE3_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b3)
#define PTE4_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b4)
#define PTE5_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b5)
#define PTE6_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b6)
#define PTE7_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b7)

//定义PTF的输入端口
#define PTF0_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b8)
#define PTF1_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b9)
#define PTF2_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b10)
#define PTF3_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b11)
#define PTF4_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b12)
#define PTF5_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b13)
#define PTF6_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b14)
#define PTF7_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b15)

//定义PTG的输入端口
#define PTG0_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b16)
#define PTG1_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b17)
#define PTG2_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b18)
#define PTG3_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b19)
#define PTG4_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b20)
#define PTG5_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b21)
#define PTG6_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b22)
#define PTG7_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b23)

//定义PTH的输入端口
#define PTH0_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b24)
#define PTH1_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b25)
#define PTH2_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b26)
#define PTH3_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b27)
#define PTH4_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b28)
#define PTH5_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b29)
#define PTH6_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b30)
#define PTH7_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->b31)

//定义PTI的输入端口
#define PTI0_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b0)
#define PTI1_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b1)
#define PTI2_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b2)
#define PTI3_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b3)
#define PTI4_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b4)
#define PTI5_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b5)
#define PTI6_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b6)
#define PTI7_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->b7)

//定义PTA的输入端口
#define PTA0_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b0)
#define PTA1_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b1)
#define PTA2_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b2)
#define PTA3_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b3)
#define PTA4_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b4)
#define PTA5_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b5)
#define PTA6_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b6)
#define PTA7_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b7)

//定义PTB的输入端口
#define PTB0_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b8)
#define PTB1_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b9)
#define PTB2_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b10)
#define PTB3_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b11)
#define PTB4_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b12)
#define PTB5_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b13)
#define PTB6_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b14)
#define PTB7_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b15)

//定义PTC的输入端口
#define PTC0_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b16)
#define PTC1_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b17)
#define PTC2_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b18)
#define PTC3_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b19)
#define PTC4_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b20)
#define PTC5_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b21)
#define PTC6_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b22)
#define PTC7_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b23)

//定义PTD的输入端口
#define PTD0_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b24)
#define PTD1_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b25)
#define PTD2_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b26)
#define PTD3_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b27)
#define PTD4_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b28)
#define PTD5_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b29)
#define PTD6_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b30)
#define PTD7_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->b31)

//定义PTE的输入端口
#define PTE0_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b0)
#define PTE1_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b1)
#define PTE2_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b2)
#define PTE3_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b3)
#define PTE4_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b4)
#define PTE5_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b5)
#define PTE6_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b6)
#define PTE7_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b7)

//定义PTF的输入端口
#define PTF0_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b8)
#define PTF1_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b9)
#define PTF2_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b10)
#define PTF3_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b11)
#define PTF4_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b12)
#define PTF5_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b13)
#define PTF6_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b14)
#define PTF7_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b15)

//定义PTG的输入端口
#define PTG0_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b16)
#define PTG1_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b17)
#define PTG2_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b18)
#define PTG3_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b19)
#define PTG4_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b20)
#define PTG5_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b21)
#define PTG6_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b22)
#define PTG7_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b23)

//定义PTH的输入端口
#define PTH0_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b24)
#define PTH1_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b25)
#define PTH2_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b26)
#define PTH3_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b27)
#define PTH4_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b28)
#define PTH5_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b29)
#define PTH6_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b30)
#define PTH7_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->b31)

//定义PTI的输入端口
#define PTI0_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b0)
#define PTI1_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b1)
#define PTI2_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b2)
#define PTI3_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b3)
#define PTI4_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b4)
#define PTI5_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b5)
#define PTI6_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b6)
#define PTI7_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->b7)





//定义8位端口的输出
#define PTA_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->B[0])
#define PTB_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->B[1])
#define PTC_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->B[2])
#define PTD_OUT            (((Dtype *)(&(GPIOX[0]->PDOR )))->B[3])
#define PTE_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->B[0])
#define PTF_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->B[1])
#define PTG_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])
#define PTH_OUT            (((Dtype *)(&(GPIOX[1]->PDOR )))->B[3])
#define PTI_OUT            (((Dtype *)(&(GPIOX[2]->PDOR )))->B[0])

//定义8位端口的输出输入方向
#define PTA_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->B[0])
#define PTB_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->B[1])
#define PTC_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->B[2])
#define PTD_DDR            (((Dtype *)(&(GPIOX[0]->PDDR )))->B[3])
#define PTE_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->B[0])
#define PTF_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->B[1])
#define PTG_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->B[2])
#define PTH_DDR            (((Dtype *)(&(GPIOX[1]->PDDR )))->B[3])
#define PTI_DDR            (((Dtype *)(&(GPIOX[2]->PDDR )))->B[0])

//定义8位端口的输入端口
#define PTA_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->B[0])
#define PTB_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->B[1])
#define PTC_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->B[2])
#define PTD_IN            (((Dtype *)(&(GPIOX[0]->PDIR )))->B[3])
#define PTE_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->B[0])
#define PTF_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->B[1])
#define PTG_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->B[2])
#define PTH_IN            (((Dtype *)(&(GPIOX[1]->PDIR )))->B[3])
#define PTI_IN            (((Dtype *)(&(GPIOX[2]->PDIR )))->B[0])

//定义8位端口的翻转电平输出端口
#define PTA_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->B[0])
#define PTB_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->B[1])
#define PTC_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->B[2])
#define PTD_T             (((Dtype *)(&(GPIOX[0]->PTOR )))->B[3])
#define PTE_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->B[0])
#define PTF_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->B[1])
#define PTG_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->B[2])
#define PTH_T             (((Dtype *)(&(GPIOX[1]->PTOR )))->B[3])
#define PTI_T             (((Dtype *)(&(GPIOX[2]->PTOR )))->B[0])




#endif     //__MK60_GPIO_CFG_H__
