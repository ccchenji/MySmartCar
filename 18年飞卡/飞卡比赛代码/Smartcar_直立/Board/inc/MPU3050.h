#ifndef _MPU3050_H_
#define _MPU3050_H_

#include "common.h"

#define	I2C_MPU3050_ADR  0x68 //定义器件在IIC总线中的从地址,根据ALT  ADDRESS地址引脚不同修改


#define	SMPL	0x15
#define DLPF	0x16
#define INT_C	0x17
#define INT_S	0x1A
#define	TMP_H	0x1B
#define	TMP_L	0x1C
#define PWR_M	0x3E


#define	MPU3050_OUT_X_H	   0x1D
#define	MPU3050_OUT_X_L	   0x1E
#define	MPU3050_OUT_Y_H	   0x1F
#define	MPU3050_OUT_Y_L	   0x20
#define MPU3050_OUT_Z_H	   0x21
#define MPU3050_OUT_Z_L	   0x22


u8 MPU3050_readbyte(u8 address);
void tly_delay(u16 k);	
void MPU3050_writebyte(u8 address, u8 thedata);


/*****************L3G4200D可能用到的外部申明*******************/
extern int16 MPU3050_GetResult(u8 n, u8 Regs_Addr); 
extern void MPU3050_Init();
#endif