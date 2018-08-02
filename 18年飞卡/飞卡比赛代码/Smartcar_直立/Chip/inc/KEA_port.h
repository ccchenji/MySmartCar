/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_port.h
 * @brief      port复用配置和各种功能配置
 * @author     山外科技
 * @version    v5.0
 * @date       2013-06-29
 */

#ifndef __KEA_PORT_H__
#define __KEA_PORT_H__


/*! 枚举管脚编号 */
typedef enum
{
    /*  PTA端口    */
    PTA0,  PTA1,  PTA2,  PTA3,  PTA4,  PTA5,  PTA6,  PTA7,

    /*  PTB端口    */
    PTB0,  PTB1,  PTB2,  PTB3,  PTB4,  PTB5,  PTB6,  PTB7,

    /*  PTC端口    */
    PTC0,  PTC1,  PTC2,  PTC3,  PTC4,  PTC5,  PTC6,  PTC7,

    /*  PTD端口    */
    PTD0,  PTD1,  PTD2,  PTD3,  PTD4,  PTD5,  PTD6,  PTD7,

    /*  PTE端口    */
    PTE0,  PTE1,  PTE2,  PTE3,  PTE4,  PTE5,  PTE6,  PTE7,

    /*  PTF端口    */
    PTF0,  PTF1,  PTF2,  PTF3,  PTF4,  PTF5,  PTF6,  PTF7,

    /*  PTG端口    */
    PTG0,  PTG1,  PTG2,  PTG3,  PTG4,  PTG5,  PTG6,  PTG7,

    /*  PTH端口    */
    PTH0,  PTH1,  PTH2,  PTH3,  PTH4,  PTH5,  PTH6,  PTH7,

    /*  PTI端口    */
    PTI0,  PTI1,  PTI2,  PTI3,  PTI4,  PTI5,  PTI6,  PTI7,

    PTXn_MAX

} PTXn_e;

/*! 枚举端口模块 */
typedef enum
{
    PTA, PTB, PTC, PTD, PTE, PTF, PTG, PTH, PTI,

    PTX_MAX,
} PTX_e;

/*! 枚举编号 */
typedef enum
{
    PT0 , PT1 , PT2 , PT3 , PT4 , PT5 , PT6 , PT7 ,
} PTn_e;

//根据以上的定义，可以得出：PTx = PTxn / 8 ; PTn = PTxn & 7
#define PTX(PTxn)           ((PTxn)>>3)
#define PTn(PTxn)           ((PTxn)&0x7)
#define PORTX_BASE(PTxn)     PORTX[PTX(PTxn)]       //PORT模块的地址

//下列部分，和上面是有所不同的，专门针对PORT、GPIO寄存器
#define GPX(PTxn)           ((PTxn)>>5)
#define GPn(PTxn)           ((PTxn)&0x1f)
#define GPIOX_BASE(PTxn)     GPIOX[GPX(PTxn)]       //PORT模块的地址


/*! 枚举PORT 配置 */
typedef enum
{
    PULLUP_DISBLE ,     //上拉使能
    PULLUP_ENBLE ,     //上拉使能

} port_pullup_cfg;



extern void port_pull   (PTXn_e ptxn, char  cfg);
extern char port_hdrve  (PTXn_e ptxn, char  cfg);



#endif      //__KEA_PORT_H__
