#include "include.h"

#define Variable_ADDR   2
#define Para_ADDR   102
#define CCD_ADDR   212
uint8   SD_Buff[512]; 
uint8   SD_OK=0;
uint8   SaveData=0;
uint16  Block_Index=0;
uint8   Zone_Index=0;
uint8   Zone_Read_Index=0;
uint8   Block_Index_Receiving;
uint8   SD_Type = 0;
void   SD_DisSelect();
uint8   SD_GetResponse(uint8 Response);
uint8   SD_RecvData(uint8*buf,uint16 len);
uint8   SD_Select();
void   SD_SPI_HighSpeed();
void   SD_SPI_LowSpeed();
uint8   SD_WaitReady();
uint8  SD_WriteDisk(uint8*buf,uint32 sector);
uint8  SPI_SendReceiveData(uint8 TxData);


//�����ڵ�һ��ҳ��洢һ���ж���ҳ��������
void  Write_Information()
{
  SD_Buff[0]=BYTE0(Block_Index);  
  SD_Buff[1]=BYTE1(Block_Index);
  SD_WriteDisk(SD_Buff,BLOCK_BEGIN);//��һ������������¼��Ҫ����Ϣ
  Block_Index=1;                       //��������ֻ�ܴӵڶ�������д
}
//�����洢��������
void Record()
{
//�������»��棬ÿ10msִ��һ��
  float temp;
  uint8 i;
  SD_Buff[0]=BYTE0(Block_Index);         
  SD_Buff[1]=BYTE1(Block_Index); 
 
   SD_WriteDisk(SD_Buff,BLOCK_BEGIN+Block_Index);
   //LED_BLUE_TURN;                          //LED��ָʾ
   Block_Index++;
}

void SD_SPI_LowSpeed()
{
  
   spi_init(SPI1,SPI_PCS0, MASTER,200*1000);
}

void SD_SPI_HighSpeed()
{
  spi_init(SPI1,SPI_PCS0, MASTER,10000*1000);
}

void SD_DisSelect()
{
  SD_CS_HIGH;
  SPI_SendReceiveData(0xff);   //�ṩ�����8��ʱ��
}
uint8 SD_WaitReady()
{
  uint32 t = 0;
  do
  {
    if(SPI_SendReceiveData(0xff) == 0xff) return 0;
    t++;
  }while(t < 0xffffff);
  return 1;
}

uint8 SD_GetResponse(uint8 Response)
{
  uint16 Count=0xFFFF;//�ȴ�����	   						  
  while((SPI_SendReceiveData(0XFF)!=Response)&&Count) Count--;//�ȴ��õ�׼ȷ�Ļ�Ӧ  	  
  if(Count==0)return MSD_RESPONSE_FAILURE;//�õ���Ӧʧ��   
  else return MSD_RESPONSE_NO_ERROR;//��ȷ��Ӧ	
}
//��sd����ȡһ�����ݰ�������
//buf:���ݻ�����
//len:Ҫ��ȡ�����ݳ���.
//����ֵ:0,�ɹ�;����,ʧ��;	
uint8 SD_RecvData(uint8*buf,uint16 len)
{			  	  
   if(SD_GetResponse(0xFE)) return 1;//�ȴ�SD������������ʼ����0xFE
    while(len--)//��ʼ��������
    {
      *buf=SPI_SendReceiveData(0xFF);
       buf++;
    }
    //������2��αCRC��dummy CRC��
    SPI_SendReceiveData(0xFF);
    SPI_SendReceiveData(0xFF);									  					    
    return 0;//��ȡ�ɹ�
}
//��SD������һ������
//����: uint8 cmd   ���� 
//      u32 arg  �������
//      uint8 crc   crcУ��ֵ	   
//����ֵ:SD�����ص���Ӧ															  
uint8 SD_SendCmd(uint8 cmd, uint32 arg, uint8 crc) 
{
    uint8 r1;	
    uint8 Retry=0;
    SD_DisSelect();//ȡ��Ƭѡ
    SD_CS_LOW; //Ƭѡ
    SPI_SendReceiveData(cmd | 0x40);//�ֱ�д������
    SPI_SendReceiveData(arg >> 24);
    SPI_SendReceiveData(arg >> 16);
    SPI_SendReceiveData(arg >> 8);
    SPI_SendReceiveData(arg);	  
    SPI_SendReceiveData(crc); 
    Retry=0X1F;
    do
    {
     r1=SPI_SendReceiveData(0xFF);
    }
    while((r1&0X80)&&Retry--);
    //����״ֵ̬;
    return r1;
}
uint8 SD_Initialize(void)
{
    uint8 r1;           //���SD���ķ���ֵ
    uint16 retry;       //�������г�ʱ����
    uint16 i;
    uint8 buff[4];
    uint8 success=0;
    
     gpio_init (SD_CS, GPO,0);
    
    SD_SPI_LowSpeed();	//���õ�����ģʽ 
    SD_DisSelect();
    for(i=0;i<10;i++)SPI_SendReceiveData(0XFF);//��������74������
    retry=20;
    do
    {
       r1=SD_SendCmd(CMD0,0,0x95);//����IDLE״̬
       SD_DisSelect();            //ȡ��Ƭѡ
    }
    while((r1!=0X01)&&retry--);
    SD_Type=0;//Ĭ���޿�
    if(r1==0X01)
    {
      if(SD_SendCmd(CMD8,0x1AA,0x87)==1)//SD V2.0
      {
        retry=0XFFFE;
        do
        {
            SD_SendCmd(CMD55,0,1);	       //����CMD55
            r1=SD_SendCmd(CMD41,0x40000000,1);//����CMD41
        }while(r1&&retry--);
        if(r1==0)success=1;  //��ʼ���ɹ���
       
      }
    }
    SD_DisSelect();
    SD_SPI_HighSpeed();//����	
    return success;//��������
}
//��SD��
//buf:���ݻ�����
//sector:����
//cnt:������
//����ֵ:0,ok;����,ʧ��.
uint8 SD_ReadDisk(uint8*buf,uint32 sector)
{
  uint8 r1;
  if(SD_Type!=SD_TYPE_V2HC)sector<<= 9;//ת��Ϊ�ֽڵ�ַ
  r1=SD_SendCmd(CMD17,sector,0X01);//������
  if(r1==0)//ָ��ͳɹ�
  {
    r1=SD_RecvData(buf,512);//����512���ֽ�	   
  }
  SD_DisSelect();//ȡ��Ƭѡ
  return r1;
}



//дSD��
//buf:���ݻ�����
//sector:��ʼ����
//cnt:������
//����ֵ:0,ok;����,ʧ��.
uint8 SD_WriteDisk(uint8*buf,uint32 sector)
{
  uint8 r1;
  uint16 t;
  uint16 retry;
  if(SD_Type!=SD_TYPE_V2HC)sector <<= 9;//ת��Ϊ�ֽڵ�ַ
  if(SD_Type!=SD_TYPE_MMC)
  {
    SD_SendCmd(CMD55,0,0X01);	
    SD_SendCmd(CMD23,1,0X01);//����ָ��	
  }
  r1=SD_SendCmd(CMD24,sector,0X01);//���������
  if(r1==0)
  {
    
    SD_CS_LOW;
    
    SPI_SendReceiveData(0XFF);
    SPI_SendReceiveData(0XFF);
    SPI_SendReceiveData(0XFF);
    
    SPI_SendReceiveData(0XFE);//��ʼд

    for(t=0;t<512;t++)SPI_SendReceiveData(buf[t]);//����ٶ�,���ٺ�������ʱ��
    
    SPI_SendReceiveData(0xFF);//����crc
    SPI_SendReceiveData(0xFF);
    t=SPI_SendReceiveData(0xFF);//������Ӧ
    if((t&0x1F)!=0x05)return 2;//��Ӧ����	
    
   }						 	 
    retry = 0;
    while(!SPI_SendReceiveData(0xff))
    {
      retry++;
      if(retry>0xfffe) //�����ʱ��д��û����ɣ������˳�
      {
          SD_CS_HIGH;
          return 1; //д�볬ʱ����1
      }
    }
  SD_DisSelect();//ȡ��Ƭѡ
  return 1;//
}
uint8 SPI_SendReceiveData(uint8 TxData)
{
  

  uint8 temp;
  SPI_PUSHR_REG(SD_SPI)  = 0
               |SPI_PUSHR_CTAS(0)
               |TxData;
  
  while(!(SPI_SR_REG(SD_SPI)& SPI_SR_TCF_MASK));
  SPI_SR_REG(SD_SPI) |= SPI_SR_TCF_MASK ;               
  
  while(!(SPI_SR_REG(SD_SPI)& SPI_SR_RFDF_MASK)); 
  temp = (uint8)(SPI_POPR_REG(SD_SPI) & 0xff);    
  
  
  SPI_SR_REG(SD_SPI)|= SPI_SR_RFDF_MASK;                
  return temp;
 
 
 
}

      