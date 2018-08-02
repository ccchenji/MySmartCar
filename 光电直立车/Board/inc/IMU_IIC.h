#ifndef _IMU_IIC_H_
#define _IMU_IIC_H_

#include "common.h"

extern void IIC_start(void);
extern void IIC_stop(void);
extern void IIC_ack_main(u8 ack_main);
extern void send_byte(u8 c);
extern u8 read_byte(void);
extern void send_to_byte(u8 ad_main,u8 c);
extern void send_to_nbyte(u8 ad_main,u8 ad_sub,u8 *buf,u8 num);
extern void read_from_byte(u8 ad_main,u8 *buf);
extern void read_from_nbyte(u8 ad_main,u8 ad_sub,u8 *buf,u8 num);
extern void IMU_IIC_Init();

#endif