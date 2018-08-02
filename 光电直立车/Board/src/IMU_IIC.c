#include "common.h"
#include "IMU_IIC.h"
#include "include.h"

/***************自定义软件IIC的数据时钟IO****************/
#define IMU_SDA PTE6//SDA IO 
#define IMU_SCL PTE7//SCL IO 
/***************IIC时序宏定义*************/
#define SDAIN   PTXn_T(IMU_SDA,IN)
#define SDA1    PTXn_T(IMU_SDA,OUT) = 1;
#define SCL1    PTXn_T(IMU_SCL,OUT) = 1;
#define DIR1    PTXn_T(IMU_SDA,DDR) = 1;
#define SDA0    PTXn_T(IMU_SDA,OUT) = 0;
#define SCL0    PTXn_T(IMU_SCL,OUT) = 0;
#define DIR0    PTXn_T(IMU_SDA,DDR) = 0;
 
//SA0必须接地

//内部数据定义
u8 IIC_ad_main; //器件从地址	    
u8 IIC_ad_sub;  //器件子地址	   
u8 *IIC_buf;    //发送|接收数据缓冲区	    
u8 IIC_num;     //发送|接收数据个数	     

#define ack 1      //主应答
#define no_ack 0   //从应答	 

/****************************IIC通信延时函数*****************************/
void nops()		 
{
   volatile uint16 n =15;     //注意，这个数据太小，会导致读取错误.试验过n=20  

    while(n--)
    {
        asm("nop");
        asm("nop");
   }
}
/****************************IIC通信初始化函数*****************************/
/*TIP；此处一定SCL  SDA  一定要上拉*********/
void IMU_IIC_Init()
{
    gpio_init  (IMU_SCL, GPO, 1); //初始化SCL
    gpio_init  (IMU_SDA, GPO, 1); //初始化SDA

    port_init_NoALT(IMU_SCL,PULLUP);
    port_init_NoALT(IMU_SDA,PULLUP); //上拉电阻 增加IO驱动能力  
} 


//************************************************
//IIC 通信开始
void IIC_start(void)
{
	SCL0;	
	nops();
	SDA1;
	nops();
	SCL1;
	nops();	
	nops();
	SDA0;
	nops();	
	nops();
	SCL0;
}
//************************************************
//送停止位 SDA=0->1
void IIC_stop(void)
{
	SCL0;
	nops();
	SDA0;
	nops();
	SCL1;
	nops();	
	nops();
	SDA1;
	nops();	
	nops();
	SCL0;
}
//************************************************
//主应答(包含ack:SDA=0和no_ack:SDA=0)
void IIC_ack_main(u8 ack_main)
{
	SCL0;	
	nops();
	if(ack_main)
	{
	  SDA0; //ack主应答
	}
	else 
	{
	  SDA1; //no_ack无需应答
	}
	nops();	
	nops();
	SCL1;
	nops();	
	nops();
	SCL0;
}
//*************************************************
//字节发送程序
//发送c(可以是数据也可是地址)，送完后接收从应答
//不考虑从应答位
void send_byte(u8 c)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		SCL0;	
		nops();
		if((c<<i) & 0x80)
		{
		  SDA1; //判断发送位
		}
		else 
		{
		  SDA0;
		}
		nops();
		SCL1;
		nops();	
		nops();
		SCL0;
	}
	nops();
	SDA1; //发送完8bit，释放总线准备接收应答位
	nops();
	SCL1;
	nops(); 	
	nops();//sda上数据即是从应答位              
	SCL0; //不考虑从应答位|但要控制好时序
}
//**************************************************
//字节接收程序
//接收器件传来的数据，此程序应配合|主应答函数|IIC_ack_main()使用
//return: uchar型1字节
u8 read_byte(void)
{
    u8 i;
    u8 c;
	c=0;
	SCL0;
	nops();
	SDA1; //置数据线为输入方式
	nops();
	DIR0;
	for(i=0;i<8;i++)
	{
		nops();
		SCL0; //置时钟线为低，准备接收数据位
		nops();
		SCL1; //置时钟线为高，使数据线上数据有效
		nops();
		c<<=1;
		if(SDAIN)
		  c+=1; //读数据位，将接收的数据存c
	}
	SCL0;	
	nops();
	DIR1;
	return c;
}
//***************************************************
//向无子地址器件发送单字节数据
void send_to_byte(u8 ad_main,u8 c)
{
	IIC_start();
	send_byte(ad_main); //发送器件地址
	send_byte(c); //发送数据c
	IIC_stop();
}
//***************************************************
//向有子地址器件发送多字节数据
void send_to_nbyte(u8 ad_main,u8 ad_sub,u8 *buf,u8 num)
{
	u8 i;
	IIC_start();
	send_byte(ad_main); //发送器件地址
	send_byte(ad_sub); //发送器件子地址
	for(i=0;i<num;i++)
	{
		send_byte(*buf); //发送数据*buf
		buf++;
	}
	IIC_stop();
}
//***************************************************
//从无子地址器件读单字节数据
//function:器件地址，所读数据存在接收缓冲区当前字节
void read_from_byte(u8 ad_main,u8 *buf)
{
	IIC_start();
	send_byte(ad_main); //发送器件地址
	*buf=read_byte();
	IIC_ack_main(no_ack); //无需应答<no_ack=0>
	IIC_stop();
}
//***************************************************
//从有子地址器件读多个字节数据
//function:
void read_from_nbyte(u8 ad_main,u8 ad_sub,u8 *buf,u8 num)
{
	u8 i;
	IIC_start();
	send_byte(ad_main);
	send_byte(ad_sub);
	for(i=0;i<num-1;i++)
	{
		*buf=read_byte();
		IIC_ack_main(ack); //主应答<ack=1>
		buf++;
	}
	*buf=read_byte();
	buf++; //本次指针调整无意义，目的是操作后buf指向下一地址
	IIC_ack_main(no_ack); //无需应答<no_ack=0>
	IIC_stop();
}






