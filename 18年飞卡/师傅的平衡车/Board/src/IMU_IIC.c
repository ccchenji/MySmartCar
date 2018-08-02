#include "common.h"
#include "IMU_IIC.h"
#include "include.h"

/***************�Զ������IIC������ʱ��IO****************/
#define IMU_SDA PTH3//SDA IO 
#define IMU_SCL PTH4//SCL IO 
/***************IICʱ��궨��*************/
#define SDAIN   PTXn_T(IMU_SDA,IN)
#define SDA1    PTXn_T(IMU_SDA,OUT) = 1;
#define SCL1    PTXn_T(IMU_SCL,OUT) = 1;
#define DIR1    PTXn_T(IMU_SDA,DDR) = 1;
#define SDA0    PTXn_T(IMU_SDA,OUT) = 0;
#define SCL0    PTXn_T(IMU_SCL,OUT) = 0;
#define DIR0    PTXn_T(IMU_SDA,DDR) = 0;
 
//SA0����ӵ�

//�ڲ����ݶ���
u8 IIC_ad_main; //�����ӵ�ַ	    
u8 IIC_ad_sub;  //�����ӵ�ַ	   
u8 *IIC_buf;    //����|�������ݻ�����	    
u8 IIC_num;     //����|�������ݸ���	     

#define ack 1      //��Ӧ��
#define no_ack 0   //��Ӧ��	 

/****************************IICͨ����ʱ����*****************************/
void nops()		 
{
   volatile uint16 n =2;     //ע�⣬�������̫С���ᵼ�¶�ȡ����.�����n=20  

//    while(n--)
//    {
////        asm("nop");
//
//   }
}
/****************************IICͨ�ų�ʼ������*****************************/
/*TIP���˴�һ��SCL  SDA  һ��Ҫ����*********/
void IMU_IIC_Init()
{
    gpio_init  (IMU_SCL, GPO, 1); //��ʼ��SCL
    gpio_init  (IMU_SDA, GPO, 1); //��ʼ��SDA

    port_pull(IMU_SCL,ENABLE) ;
    port_pull(IMU_SDA,ENABLE) ;
} 


//************************************************
//IIC ͨ�ſ�ʼ
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
//��ֹͣλ SDA=0->1
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
//��Ӧ��(����ack:SDA=0��no_ack:SDA=0)
void IIC_ack_main(u8 ack_main)
{
	SCL0;	
	nops();
	if(ack_main)
	{
	  SDA0; //ack��Ӧ��
	}
	else 
	{
	  SDA1; //no_ack����Ӧ��
	}
	nops();	
	nops();
	SCL1;
	nops();	
	nops();
	SCL0;
}
//*************************************************
//�ֽڷ��ͳ���
//����c(����������Ҳ���ǵ�ַ)���������մ�Ӧ��
//�����Ǵ�Ӧ��λ
void send_byte(u8 c)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		SCL0;	
		nops();
		if((c<<i) & 0x80)
		{
		  SDA1; //�жϷ���λ
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
	SDA1; //������8bit���ͷ�����׼������Ӧ��λ
	nops();
	SCL1;
	nops(); 	
	nops();//sda�����ݼ��Ǵ�Ӧ��λ              
	SCL0; //�����Ǵ�Ӧ��λ|��Ҫ���ƺ�ʱ��
}
//**************************************************
//�ֽڽ��ճ���
//�����������������ݣ��˳���Ӧ���|��Ӧ����|IIC_ack_main()ʹ��
//return: uchar��1�ֽ�
u8 read_byte(void)
{
    u8 i;
    u8 c;
	c=0;
	SCL0;
	nops();
	SDA1; //��������Ϊ���뷽ʽ
	nops();
	DIR0;
	for(i=0;i<8;i++)
	{
		nops();
		SCL0; //��ʱ����Ϊ�ͣ�׼����������λ
		nops();
		SCL1; //��ʱ����Ϊ�ߣ�ʹ��������������Ч
		nops();
		c<<=1;
		if(SDAIN)
		  c+=1; //������λ�������յ����ݴ�c
	}
	SCL0;	
	nops();
	DIR1;
	return c;
}
//***************************************************
//�����ӵ�ַ�������͵��ֽ�����
void send_to_byte(u8 ad_main,u8 c)
{
	IIC_start();
	send_byte(ad_main); //����������ַ
	send_byte(c); //��������c
	IIC_stop();
}
//***************************************************
//�����ӵ�ַ�������Ͷ��ֽ�����
void send_to_nbyte(u8 ad_main,u8 ad_sub,u8 *buf,u8 num)
{
	u8 i;
	IIC_start();
	send_byte(ad_main); //����������ַ
	send_byte(ad_sub); //���������ӵ�ַ
	for(i=0;i<num;i++)
	{
		send_byte(*buf); //��������*buf
		buf++;
	}
	IIC_stop();
}
//***************************************************
//�����ӵ�ַ���������ֽ�����
//function:������ַ���������ݴ��ڽ��ջ�������ǰ�ֽ�
void read_from_byte(u8 ad_main,u8 *buf)
{
	IIC_start();
	send_byte(ad_main); //����������ַ
	*buf=read_byte();
	IIC_ack_main(no_ack); //����Ӧ��<no_ack=0>
	IIC_stop();
}
//***************************************************
//�����ӵ�ַ����������ֽ�����
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
		IIC_ack_main(ack); //��Ӧ��<ack=1>
		buf++;
	}
	*buf=read_byte();
	buf++; //����ָ����������壬Ŀ���ǲ�����bufָ����һ��ַ
	IIC_ack_main(no_ack); //����Ӧ��<no_ack=0>
	IIC_stop();
}






