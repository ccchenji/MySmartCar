#include "include.h"
#include "BMX055.h"

uint8 testid = 0;
uint8 BMX055_init(void)
{
	/************************************/
	/*加速度计配置*/
	/************************************/
	uint8 ErrCount = 0;
	  while(IIC_Read_Reg(IIC_BMX055_ACC_ADR, BMX055_ACC_ID) != 0xFA)   /////确认芯片ID
	  {
	     ErrCount++;
	    //if(ErrCount > 5)
	    //  return 0;
	  }
	if (IIC_Write_Reg(IIC_BMX055_ACC_ADR, BMX055_ACC_PMURANGE, 0x05) == 0)return 0;   ///4G 
	DELAY_MS(10);
	if (IIC_Write_Reg(IIC_BMX055_ACC_ADR, BMX055_ACC_PMUBW, 0x0F) == 0)return 0;     ///1000HZ 
	DELAY_MS(10);
	if (IIC_Write_Reg(IIC_BMX055_ACC_ADR, BMX055_ACC_PMULPM, 0x00) == 0)return 0;   ///Normal MODE  



	ErrCount = 0;
	while (IIC_Read_Reg(IIC_BMX055_GYRO_ADR, BMX055_GYRO_ID) != 0x0F)   /////确认芯片ID
	{
		ErrCount++;
		if (ErrCount > 5)
			return 0;
	}
	if (IIC_Write_Reg(IIC_BMX055_GYRO_ADR, BMX055_GYRO_RANGE, 0x01) == 0)return 0;   ///+-1000    
	DELAY_MS(10);
	if (IIC_Write_Reg(IIC_BMX055_GYRO_ADR, BMX055_GYRO_BW, 0x02) == 0)return 0;     ///1000HZ  
	DELAY_MS(10);
	if (IIC_Write_Reg(IIC_BMX055_GYRO_ADR, BMX055_GYRO_LPM, 0x00) == 0)return 0;   ///Normal MODE     
	DELAY_MS(10);
	if (IIC_Write_Reg(IIC_BMX055_GYRO_ADR, BMX055_GYRO_RATEHBW, 0x08) == 0)return 0;   ///高通滤波 ，可以不要   
	DELAY_MS(10);


	ErrCount = 0;
	IIC_Write_Reg(IIC_BMX055_MAG_ADR, BMX055_MAG_POM, 0x81);
	DELAY_MS(10);
	while (IIC_Read_Reg(IIC_BMX055_MAG_ADR, BMX055_MAG_ID) != 0x32)   /////确认芯片ID
	{
		ErrCount++;
		if (ErrCount > 5)
			return 0;
	}
	if (IIC_Write_Reg(IIC_BMX055_MAG_ADR, BMX055_MAG_DATARATE, 0x38) == 0)return 0;   ///输出速率30HZ  
	DELAY_MS(10);
	if (IIC_Write_Reg(IIC_BMX055_MAG_ADR, BMX055_MAG_INTEN, 0x00) == 0)return 0;      ///不使能中断 
	DELAY_MS(10);
	return 1;
}

//////错误读取将返回0
uint8 BMX055_DataRead(BMX055Datatypedef *Q, uint8 type)
{
	uint8 datatemp[6] = { 0 };

	if (IIC_Read_Buff(IIC_BMX055_GYRO_ADR, BMX055_GYRO_XDATALSB, datatemp, 6) == 0)return 0;
	Q->GYROXdata = (float)((int16)((datatemp[1] << 8) | datatemp[0]));
	Q->GYROYdata = (float)((int16)((datatemp[3] << 8) | datatemp[2]));
	Q->GYROZdata = (float)((int16)((datatemp[5] << 8) | datatemp[4]));
	if (IIC_Read_Buff(IIC_BMX055_ACC_ADR, BMX055_ACC_XDATALSB, datatemp, 6) == 0)return 0;
	Q->ACCXdata = (float)((int16)((datatemp[1] << 8) | datatemp[0]) >> 4);
	Q->ACCYdata = (float)((int16)((datatemp[3] << 8) | datatemp[2]) >> 4);
	Q->ACCZdata = (float)((int16)((datatemp[5] << 8) | datatemp[4]) >> 4);
	/************************************/
	/*磁力计数据读取*/
	/************************************/
	if (type)
	{
		if (IIC_Read_Buff(IIC_BMX055_MAG_ADR, BMX055_MAG_XDATALSB, datatemp, 6) == 0)return 0;
		Q->MAGXdata = (float)((int16)((datatemp[1] << 8) | datatemp[0]) >> 3);
		Q->MAGYdata = (float)((int16)((datatemp[3] << 8) | datatemp[2]) >> 3);
		Q->MAGZdata = (float)((int16)((datatemp[5] << 8) | datatemp[4]) >> 1);
	}
	return 1;
}