#include "common.h"
#include "MPU3050.h"
#include "include.h"
/*************************MPU3050.c*********************
*@����ģ��IIC 
*@�����ǲ���  +-2000DPS  16bit  û�õ�FIFO ���жϹ���
*@�������ڣ�2016.5.27
*@�����ˣ�  First Blood
**********************************************************/
//��ȡMPU3050��1���ֽ�
u8 MPU3050_readbyte(u8 address)
{
	u8 ret;
	IIC_start();		//����
	send_byte(I2C_MPU3050_ADR<<1 );	//д���豸ID��д�ź�
	send_byte(address);	//X��ַ
	IIC_start();		//���·��Ϳ�ʼ
	send_byte((I2C_MPU3050_ADR<<1) +1);	//д���豸ID������
	ret = read_byte();	//��ȡһ�ֽ�
	IIC_stop();

	return ret;
}

//д��MPU3050��1���ֽ�
void MPU3050_writebyte(u8 address, u8 thedata)
{
	IIC_start();		//����
	send_byte(I2C_MPU3050_ADR<<1);  //д���豸ID��д�ź�
	send_byte(address);	//X��ַ
	send_byte(thedata);	//д���豸ID������
	IIC_stop();
}

/*
 * �������ܣ���MPU3050���ٶ����
 * �����w
 *      
 *       Regs_Addr - ���ݼĴ�����ַ
 * ��������ֵ��ת�������ʵ���ٶ�ֵ��int16��
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
	  result = (~result + 1) & 0x3fff;     //����;��λ,ȡ��,��һ
	  result = -result;
  }
  else
  {
	  result = result & 0x3fff;          //��λ
  }
 /***********�˴��õ�����msdps/digit  ת������ʵ���ٶȻ�Ҫ����16.4 ����������ֲ�**************/ 
//  result=(int)(result/16.4);
//  sum += result;
 } 
  return (result);
}



/*********��ʼ��MPU3050��������Ҫ��ο������ֲ�����޸�************************/

void MPU3050_Init()
{
  
   MPU3050_writebyte(PWR_M , 0X80);  //���üĴ���ǰ������
   tly_delay(10);
   MPU3050_writebyte(SMPL,  0X00);   //��������Ƶ    Ƶ��=����Ƶ��*��SMPL+1��;
   tly_delay(10);
   MPU3050_writebyte(DLPF , 0x11);   //+-2000dps ������ 16.4 mdps/digit  ��ͨ����256HZ ����Ƶ��8KHZ 
   tly_delay(10);
   MPU3050_writebyte(INT_C , 0X00);  //�жϹر�  
   tly_delay(10);
   MPU3050_writebyte(PWR_M , 0X00);  //���� 
   tly_delay(10);
}

/***********��������ʼ��д�Ĵ�����ʱ������ֹʱ���ͻ*********/
void tly_delay(u16 k)		 
{
    u8 i;	 

    while(--k)
    {
        for(i=0;i<100;i++); //��ʱʱ�䳤�̣�0--255��ѡ
    }
}

