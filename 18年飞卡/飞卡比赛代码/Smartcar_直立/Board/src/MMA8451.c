#include "common.h"
#include "MMA8451.h"
#include "include.h"
/************************MMA8451.c*********************
*@采用模拟IIC 
*@陀螺仪参数  +-2g  14bit 没用到FIFO 和中断功能
*@更新日期：2016.1.26
*@更新人：  First Blood
**********************************************************/
//读取MMA8451的1个字节
u8 MMA8451_readbyte(u8 address)
{
	u8 ret;
	IIC_start();		//启动
	send_byte(MMA845x_IIC_ADDRESS<<1);	//写入设备ID及写信号
	send_byte(address);	//X地址
	IIC_start();		//重新发送开始
	send_byte((MMA845x_IIC_ADDRESS<<1)+1);	//写入设备ID及读信
	ret = read_byte();	//读取一字节
	IIC_stop();

	return ret;
}

//写入MMA8451的1个字节
void MMA8451_writebyte(u8 address, u8 thedata)
{
	IIC_start();		//启动
	send_byte(MMA845x_IIC_ADDRESS<<1);	//写入设备ID及写信号
	send_byte(address);	//X地址
	send_byte(thedata);	//写入设备ID及读信
	IIC_stop();
}

/*
 * 函数功能：加速度计转换成G值
 * 参数
 *       h--高八位值
 *       l--低八位值
 * 函数返回值：加速度g值
 */   

double mma_switch(unsigned char h,unsigned char l)
{
    double ret;
    unsigned short int V1,h_l;
    int sign;
    h_l=(h<<8u)+l;
    //14位
    if(h>0x7F)
    {
        sign=-1;        
        V1=(~(h_l>>2)+1)&0X3FFF;
    }
    else
    {
        sign=1;
        V1=(h_l>>2)&0X3FFF;
    }
    ret=sign*(((double)V1)/0xfff);

    //12位
//    if(h>0x7F)
//    {
//        sign=-1;         //****************我改了，应该是-1
//        V1=(~(h_l>>4)+1)&0X0FFF;
//    }
//    else
//    {
//        sign=1;
//        V1=(h_l>>4)&0X0FFF;
//    }
//    ret=sign*(((double)V1)/0x3ff);
    return ret;
}


/*
 * 函数功能：读MAA8451加速度输出g值
 * 参数
 *       Status - 数据寄存器状态
 *       Regs_Addr - 数据寄存器地址
 * 函数返回值：加速度值（int16）
   Example： ACC_X = MMA8451_GetResult(MMA8451_STATUS_X_READY, MMA8451_REG_OUTX_MSB);
             ACC_Y = MMA8451_GetResult(MMA8451_STATUS_Y_READY, MMA8451_REG_OUTY_MSB);
             ACC_Z = MMA8451_GetResult(MMA8451_STATUS_X_READY, MMA8451_REG_OUTZ_MSB);	
 */   
int16 MMA8451_GetResult(u8 Status, u8 Regs_Addr) 
{
    unsigned char h,l;
    uint16 temp = 0;
    u8 ret=0,cnt=0;
	int16 z_acc;
    if(Regs_Addr>MMA8451_REG_OUTZ_LSB)//防止形参带错
    return 0;
  
  // 等待转换完成并取出值 
   while(!(ret&Status)) 
   {
    ret = MMA8451_readbyte( MMA8451_REG_STATUS);
    if(++cnt>5)  //此处的cnt不必要过大  10    
   
     break;
   
   }
  
  h= MMA8451_readbyte( Regs_Addr);
  l= MMA8451_readbyte( Regs_Addr+1);
  //temp=mma_switch(h,l);
  temp = (h << 8u) + l;
  //实际最大量程为2G 反三角函数不过1  
//   if(temp>=0.9999)
//    {
//        temp=0.9999;//返回的是错误出错标志
//        //temp=temp/1.00;
//    }
//    else if(temp<=-0.9999)
//    {
//        temp=-0.9999;//返回的是错误出错标志
//        //temp=temp/1.00;			//加速度计的最大值为1.02
//    }
   if (temp & 0x8000)
   {
	   temp = (~(temp >> 2) + 1) & 0x3fff;     //求补码;移位,取反,加一
	   z_acc = -temp;
   }
   else
   {
	   z_acc = (temp >> 2) & 0x3fff;          //移位
   }
    return (z_acc);
}




/*********初始化MMA8451，根据需要请参考pdf进行修改************************/
void MMA8451_Init()
{	
        while(MMA8451_readbyte(MMA8451_REG_WHOAMI)!=0x1a);
	    mma_delay(20);
        MMA8451_writebyte(XYZ_DATA_CFG_REG,0x00);        //2g
        mma_delay(20);
        MMA8451_writebyte(HP_FILTER_CUTOFF_REG,0x10);   //低通滤波
        mma_delay(20);
        MMA8451_writebyte(MMA8451_REG_CTRL_REG1,0x01);  //激活模式
        mma_delay(20);
                                                
}

/***********传感器初始化写寄存器延时函数防止时序冲突*********/
void mma_delay(u16 k)		 //延时函数
{
    u8 i;	 //在函数中，必须先声明变量，然后才能调用
    while(--k)
    {
       for(i=0;i<100;i++); //延时时间长短，0--255可选
    }
}
















