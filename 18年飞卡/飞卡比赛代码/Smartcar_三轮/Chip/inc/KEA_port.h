/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_port.h
 * @brief      port�������ú͸��ֹ�������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-06-29
 */

#ifndef __KEA_PORT_H__
#define __KEA_PORT_H__


/*! ö�ٹܽű�� */
typedef enum
{
    /*  PTA�˿�    */
    PTA0,  PTA1,  PTA2,  PTA3,  PTA4,  PTA5,  PTA6,  PTA7,

    /*  PTB�˿�    */
    PTB0,  PTB1,  PTB2,  PTB3,  PTB4,  PTB5,  PTB6,  PTB7,

    /*  PTC�˿�    */
    PTC0,  PTC1,  PTC2,  PTC3,  PTC4,  PTC5,  PTC6,  PTC7,

    /*  PTD�˿�    */
    PTD0,  PTD1,  PTD2,  PTD3,  PTD4,  PTD5,  PTD6,  PTD7,

    /*  PTE�˿�    */
    PTE0,  PTE1,  PTE2,  PTE3,  PTE4,  PTE5,  PTE6,  PTE7,

    /*  PTF�˿�    */
    PTF0,  PTF1,  PTF2,  PTF3,  PTF4,  PTF5,  PTF6,  PTF7,

    /*  PTG�˿�    */
    PTG0,  PTG1,  PTG2,  PTG3,  PTG4,  PTG5,  PTG6,  PTG7,

    /*  PTH�˿�    */
    PTH0,  PTH1,  PTH2,  PTH3,  PTH4,  PTH5,  PTH6,  PTH7,

    /*  PTI�˿�    */
    PTI0,  PTI1,  PTI2,  PTI3,  PTI4,  PTI5,  PTI6,  PTI7,

    PTXn_MAX

} PTXn_e;

/*! ö�ٶ˿�ģ�� */
typedef enum
{
    PTA, PTB, PTC, PTD, PTE, PTF, PTG, PTH, PTI,

    PTX_MAX,
} PTX_e;

/*! ö�ٱ�� */
typedef enum
{
    PT0 , PT1 , PT2 , PT3 , PT4 , PT5 , PT6 , PT7 ,
} PTn_e;

//�������ϵĶ��壬���Եó���PTx = PTxn / 8 ; PTn = PTxn & 7
#define PTX(PTxn)           ((PTxn)>>3)
#define PTn(PTxn)           ((PTxn)&0x7)
#define PORTX_BASE(PTxn)     PORTX[PTX(PTxn)]       //PORTģ��ĵ�ַ

//���в��֣���������������ͬ�ģ�ר�����PORT��GPIO�Ĵ���
#define GPX(PTxn)           ((PTxn)>>5)
#define GPn(PTxn)           ((PTxn)&0x1f)
#define GPIOX_BASE(PTxn)     GPIOX[GPX(PTxn)]       //PORTģ��ĵ�ַ


/*! ö��PORT ���� */
typedef enum
{
    PULLUP_DISBLE ,     //����ʹ��
    PULLUP_ENBLE ,     //����ʹ��

} port_pullup_cfg;



extern void port_pull   (PTXn_e ptxn, char  cfg);
extern char port_hdrve  (PTXn_e ptxn, char  cfg);



#endif      //__KEA_PORT_H__
