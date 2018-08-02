#include "common.h"
#include "MMA8451.h"
#include "include.h"
/************************MMA8451.c*********************
*@����ģ��IIC 
*@�����ǲ���  +-2g  14bit û�õ�FIFO ���жϹ���
*@�������ڣ�2016.1.26
*@�����ˣ�  First Blood
**********************************************************/
//��ȡMMA8451��1���ֽ�
u8 MMA8451_readbyte(u8 address)
{
	u8 ret;
	IIC_start();		//����
	send_byte(MMA845x_IIC_ADDRESS<<1);	//д���豸ID��д�ź�
	send_byte(address);	//X��ַ
	IIC_start();		//���·��Ϳ�ʼ
	send_byte((MMA845x_IIC_ADDRESS<<1)+1);	//д���豸ID������
	ret = read_byte();	//��ȡһ�ֽ�
	IIC_stop();

	return ret;
}

//д��MMA8451��1���ֽ�
void MMA8451_writebyte(u8 address, u8 thedata)
{
	IIC_start();		//����
	send_byte(MMA845x_IIC_ADDRESS<<1);	//д���豸ID��д�ź�
	send_byte(address);	//X��ַ
	send_byte(thedata);	//д���豸ID������
	IIC_stop();
}

/*
 * �������ܣ����ٶȼ�ת����Gֵ
 * �����w
 *       h--�߰�λֵ
 *       l--�Ͱ�λֵ
 * ��������ֵ�����ٶ�gֵ
 */   

double mma_switch(unsigned char h,unsigned char l)
{
    double ret;
    unsigned short int V1,h_l;
    int sign;
    h_l=(h<<8u)+l;
    //14λ
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

    //12λ
//    if(h>0x7F)
//    {
//        sign=-1;         //****************�Ҹ��ˣ�Ӧ����-1
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
 * �������ܣ���MAA8451���ٶ����gֵ
 * �����w
 *       Status - ���ݼĴ���״̬
 *       Regs_Addr - ���ݼĴ�����ַ
 * ��������ֵ�����ٶ�ֵ��int16��
   Example�� ACC_X = MMA8451_GetResult(MMA8451_STATUS_X_READY, MMA8451_REG_OUTX_MSB);
             ACC_Y = MMA8451_GetResult(MMA8451_STATUS_Y_READY, MMA8451_REG_OUTY_MSB);
             ACC_Z = MMA8451_GetResult(MMA8451_STATUS_X_READY, MMA8451_REG_OUTZ_MSB);	
 */   
int16 MMA8451_GetResult(u8 Status, u8 Regs_Addr) 
{
    unsigned char h,l;
    int16 temp = 0;
    u8 ret=0,cnt=0;
	int16 z_acc;
    if(Regs_Addr>MMA8451_REG_OUTZ_LSB)//��ֹ�βδ���
    return 0;
  
  // �ȴ�ת����ɲ�ȡ��ֵ 
   while(!(ret&Status)) 
   {
    ret = MMA8451_readbyte( MMA8451_REG_STATUS);
    if(++cnt>5)  //�˴���cnt����Ҫ����  10    
   
     break;
   
   }
  
  h= MMA8451_readbyte( Regs_Addr);
  l= MMA8451_readbyte( Regs_Addr+1);
//temp=mma_switch(h,l);
  temp = (int16)((h << 8u)|l);
//ʵ���������Ϊ2G �����Ǻ�������1  
//   if(temp>=0.9999)
//    {
//        temp=0.9999;//���ص��Ǵ�������־
//        //temp=temp/1.00;
//    }
//    else if(temp<=-0.9999)
//    {
//        temp=-0.9999;//���ص��Ǵ�������־
//        //temp=temp/1.00;			//���ٶȼƵ����ֵΪ1.02
//    }
  //if (h > 0x7f)           //��ֵ
  //{
	 // temp = (~(temp >> 2) + 1) & 0x3fff;     //����;��λ,ȡ��,��һ

	 // temp = -temp;
  //}
  //else
  //{
	 // temp = (temp >> 2) & 0x3fff;            //��λ
	 // temp = temp;
  //}
   if (temp & 0x8000)
   {
	   temp = (~(temp >> 2) + 1) & 0x3fff;     //����;��λ,ȡ��,��һ
	   z_acc = -temp;
   }
   else
   {
	   z_acc = (temp >> 2) & 0x3fff;          //��λ
   }
    return (z_acc);
}




/*********��ʼ��MMA8451��������Ҫ��ο�pdf�����޸�************************/
void MMA8451_Init()
{	
        while(MMA8451_readbyte(MMA8451_REG_WHOAMI)!=0x1a);
	    mma_delay(20);
        MMA8451_writebyte(XYZ_DATA_CFG_REG,0x01);        //4g
        mma_delay(20);
        MMA8451_writebyte(HP_FILTER_CUTOFF_REG,0x10);   //��ͨ�˲�
        mma_delay(20);
        MMA8451_writebyte(MMA8451_REG_CTRL_REG1,0x01);  //����ģʽ
        mma_delay(20);
                                                
}

/***********��������ʼ��д�Ĵ�����ʱ������ֹʱ���ͻ*********/
void mma_delay(u16 k)		 //��ʱ����
{
    u8 i;	 //�ں����У�����������������Ȼ����ܵ���
    while(--k)
    {
       for(i=0;i<100;i++); //��ʱʱ�䳤�̣�0--255��ѡ
    }
}
















