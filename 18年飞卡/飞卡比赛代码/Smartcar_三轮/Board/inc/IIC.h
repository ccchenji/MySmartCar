
#ifndef _IIC_h
#define _IIC_h



#include "include.h"



#define SEEKFREE_SCL    PTH4                           //定义SCL引脚  可任意更改为其他IO
#define SEEKFREE_SDA    PTH3                           //定义SDA引脚  可任意更改为其他IO

typedef enum IIC       //DAC模块
{
    IIC,
    SCCB
} IIC_type;



void  IIC_start(void);
void  IIC_stop(void);
void  IIC_ack_main(uint8 ack_main);
void  send_ch(uint8 c);
uint8 read_ch(uint8 ack);
void  simiic_write_reg(uint8 dev_add, uint8 reg, uint8 dat);
uint8 simiic_read_reg(uint8 dev_add, uint8 reg, IIC_type type);
void simiic_read_regs(uint8 dev_add, uint8 reg, uint8 *dat_add, uint8 num, IIC_type type);
void  IIC_init(void);











#endif

