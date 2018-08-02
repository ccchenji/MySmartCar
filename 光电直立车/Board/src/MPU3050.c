#include "common.h"
#include "MPU3050.h"
#include "include.h"
/*************************MPU3050.c*********************
*@采用模拟IIC 
*@陀螺仪参数  +-2000DPS  16bit  没用到FIFO 和中断功能
*@更新日期：2016.5.27
*@更新人：  First Blood
**********************************************************/
//读取MPU3050的1个字节
u8 MPU3050_readbyte(u8 address)
{
	u8 ret;
	IIC_start();		//启动
	send_byte(I2C_MPU3050_ADR<<1 );	//写入设备ID及写信号
	send_byte(address);	//X地址
	IIC_start();		//重新发送开始
	send_byte((I2C_MPU3050_ADR<<1) +1);	//写入设备ID及读信
	ret = read_byte();	//读取一字节
	IIC_stop();

	return ret;
}

//写入MPU3050的1个字节
void MPU3050_writebyte(u8 address, u8 thedata)
{
	IIC_start();		//启动
	send_byte(I2C_MPU3050_ADR<<1);  //写入设备ID及写信号
	send_byte(address);	//X地址
	send_byte(thedata);	//写入设备ID及读信
	IIC_stop();
}

/*
 * 函数功能：读MPU3050角速度输出
 * 参数
 *      
 *       Regs_Addr - 数据寄存器地址
 * 函数返回值：转换后的真实角速度值（int16）
  Example:  Gyro_X = MPU3050_GetResult(1, MPU3050_OUT_X_H);
            Gyro_Y = MPU3050_GetResult(1, MPU3050_OUT_Y_H);
            Gyro_Z = MPU3050_GetResult(1, MPU3050_OUT_Z_H);	
 */   
int16 MPU3050_GetResult(u8 n, u8 Regs_Addr) 
{
   u8  i=0;
  int16 result,temp,sum=0;

 for(i=0;i<n;i++)
 {
    
  result= MPU3050_readbyte( Regs_Addr);
  temp  = MPU3050_readbyte( Regs_Addr+1);
  result=result<<8;
  result=result|temp;
  if (result & 0x8000)
  {
	  result = (~result + 1) & 0x3fff;     //求补码;移位,取反,加一
	  result = -result;
  }
  else
  {
	  result = result & 0x3fff;          //移位
  }
 /***********此处得到的是msdps/digit  转化成真实角速度还要除以16.4 具体见数据手册**************/ 
//  result=(int)(result/16.4);
//  sum += result;
 } 
  return (result);
}



/*********初始化MPU3050，根据需要请参考数据手册进行修改************************/

void MPU3050_Init()
{
  
   MPU3050_writebyte(PWR_M , 0X80);  //配置寄存器前不工作
   tly_delay(10);
   MPU3050_writebyte(SMPL,  0X00);   //采样不分频    频率=采样频率*（SMPL+1）;
   tly_delay(10);
   MPU3050_writebyte(DLPF , 0x11);   //+-2000dps 灵敏度 16.4 mdps/digit  低通上限256HZ 采样频率8KHZ 
   tly_delay(10);
   MPU3050_writebyte(INT_C , 0X00);  //中断关闭  
   tly_delay(10);
   MPU3050_writebyte(PWR_M , 0X00);  //开启 
   tly_delay(10);
}

/***********传感器初始化写寄存器延时函数防止时序冲突*********/
void tly_delay(u16 k)		 
{
    u8 i;	 

    while(--k)
    {
        for(i=0;i<100;i++); //延时时间长短，0--255可选
    }
}

