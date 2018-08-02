#ifndef __myiic_H__
#define __myiic_H__

#include "common.h"
#include "include.h"


#define IICDelay       8               //ʵ�� 5ʱ��Ȼ������ȷ��ȡ  �����Ϊ 6-8
#define IIC_GPIO       GPIOB_BASE_PTR ////////A12  A13��Ӧ����B4   B5����ϸ�������ֲᣬ���Ĺܽ�����IIC_init()����һ������
#define IIC_SCLpin     28
#define IIC_SDApin     27



#define IIC_SDA_OUT()   {IIC_GPIO->PIDR |= (1 << IIC_SDApin); IIC_GPIO->PDDR |= (1 << IIC_SDApin);}
#define IIC_SDA_IN()    {IIC_GPIO->PIDR &= ~(1 << IIC_SDApin); IIC_GPIO->PDDR &= ~(1 << IIC_SDApin);}
#define IIC_DATA        ((IIC_GPIO->PDIR >> IIC_SDApin) & 0x01)
#define IIC_SDA_H       (IIC_GPIO->PDOR |= (1 << IIC_SDApin))
#define IIC_SCL_H       (IIC_GPIO->PDOR |= (1 << IIC_SCLpin))
#define IIC_SDA_L       (IIC_GPIO->PDOR &= ~(1 << IIC_SDApin))
#define IIC_SCL_L       (IIC_GPIO->PDOR &= ~(1 << IIC_SCLpin))


uint8 IIC_Read_Reg(uint8 addr, uint8 offset);
unsigned char IIC_Write_Reg(uint8 addr, uint8 offset, uint8 data);
unsigned char IIC_Read_Buff(uint8 addr, uint8 offset, uint8* buff, uint8 size);
void IIC_init(void);
#endif