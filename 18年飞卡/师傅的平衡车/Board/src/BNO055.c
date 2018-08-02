/*
******************************************************************************
* @file    BNO055.c
* @author  liujunqi
* @date    07-April-2018
* @brief   BNO055 driver 
******************************************************************************
*/
#include "BNO055.h"

/* 
* @brief    BNO055 串口初始化
* @param    None
* @retval   None
* @date     07-April-2018
*/
void BNO055UartInit(void)
{
	uart_init(BNO055PORT, 115200);  	
}
/*
* @brief    BNO055 初始化
* @param    None
* @retval   status 
* @date     07-April-2018
*/
int BNO055Init(void)
{
	char i = 0;
	BNO055UartInit();
      //  unsigned char a = 0;
       // a = BNO055Read(BNO055_REGISTER_CHIP_ID);
	if (BNO055Read(BNO055_REGISTER_CHIP_ID) != BNO055_ID)
	{
		while (BNO055Read(BNO055_REGISTER_CHIP_ID) != BNO055_ID)
		{  
                 // a = BNO055Read(BNO055_REGISTER_CHIP_ID);
			DELAY_MS(5);
			//i++;
			//if (i >= 10)return -1;				//初始化失败返回
		}
	}
	BNO055Write(BNO055_REGISTER_OPR_MODE, CONFIGMODE); //配置模式
	DELAY_MS(20);   //模式转换延时 
	BNO055Write(BNO055_REGISTER_SYS_TRIGGER, 0x20); //重启传感器
	while (BNO055Read(BNO055_REGISTER_CHIP_ID) != BNO055_ID) //等待重启
	{
		DELAY_MS(5);
	}
	DELAY_MS(20);
	/* set a base mode (normal power mode, fastest/NDOF, manually packed for now) and start! */
	BNO055Write(BNO055_REGISTER_PWR_MODE, NORMAL_POWER_MODE);
	DELAY_MS(1);
	BNO055Write(BNO055_REGISTER_OPR_MODE, NDOF | FASTEST_MODE);
	DELAY_MS(20);

	return 0;
}
/*
* @brief    BNO055 读取欧拉角
* @param    MyEuler  BNO055EulerData *型指针 存放欧拉角
* @retval   None
* @date     07-April-2018
*/
void BNO055ReadEuler(BNO055EulerData *MyEuler)
{
	char EulerBuff[8] = { 0 };
	uart_putchar(BNO055PORT, 0xAA);
	uart_putchar(BNO055PORT, 0x01);
	
	
	uart_putchar(BNO055PORT, (char)BNO055_REGISTER_EUL_DATA_X_LSB); 
	uart_putchar(BNO055PORT, 0x06);
	//DisableInterrupts;
	uart_getchar(BNO055PORT, EulerBuff);
	uart_getchar(BNO055PORT, (EulerBuff + 1));
	uart_getchar(BNO055PORT, (EulerBuff + 2));
	uart_getchar(BNO055PORT, (EulerBuff + 3));
	uart_getchar(BNO055PORT, (EulerBuff + 4));
	uart_getchar(BNO055PORT, (EulerBuff + 5));
	uart_getchar(BNO055PORT, (EulerBuff + 6));
	uart_getchar(BNO055PORT, (EulerBuff + 7));
	

	//uart_querybuff(BNO055PORT, EulerBuff, 8);		//查询接收6字节
	//EnableInterrupts;
	MyEuler->x = (EulerBuff[2] | (EulerBuff[3] << 8));
	MyEuler->y = (EulerBuff[4] | (EulerBuff[5] << 8));
	MyEuler->z = (EulerBuff[6] | (EulerBuff[7] << 8));
}
/*
* @brief    BNO055 读取角速度
* @param    MyEuler  BNO055EulerData *型指针 存放欧拉角
* @retval   None
* @date     07-April-2018
*/
void BNO055ReadLinAcc(BNO055LinAccData *MyLinAcc)
{
	char AccBuff[8] = { 0 };
	uart_putchar(BNO055PORT, 0xAA);
	uart_putchar(BNO055PORT, 0x01);
	uart_putchar(BNO055PORT, (char)BNO055_REGISTER_LIA_DATA_X_LSB);
	uart_putchar(BNO055PORT, 0x06);
	uart_querybuff(BNO055PORT, AccBuff, 8);		//查询接收6字节

	MyLinAcc->x = (AccBuff[2] | (AccBuff[3] << 8));
	MyLinAcc->y = (AccBuff[4] | (AccBuff[5] << 8));
	MyLinAcc->z = (AccBuff[6] | (AccBuff[7] << 8));
}
/*
* @brief    BNO055 读取角速度
* @param    MyEuler  BNO055EulerData *型指针 存放欧拉角
* @retval   None
* @date     07-April-2018
*/
void BNO055ReadQua(BNO055QuaData *MyQua)
{
	char QuaBuff[10] = { 0 };
	uart_putchar(BNO055PORT, 0xAA);
	uart_putchar(BNO055PORT, 0x01);
	uart_putchar(BNO055PORT, (char)BNO055_REGISTER_QUA_DATA_W_LSB);
	uart_putchar(BNO055PORT, 0x08);
	uart_querybuff(BNO055PORT, QuaBuff, 10);		//查询接收6字节

	MyQua->w = (QuaBuff[2] | (QuaBuff[3] << 8));
	MyQua->x = (QuaBuff[4] | (QuaBuff[5] << 8));
	MyQua->y = (QuaBuff[6] | (QuaBuff[7] << 8));
	MyQua->z = (QuaBuff[8] | (QuaBuff[9] << 8));


}
void BNO055CalcAbsLinAcc(BNO055QuaData *MyQua, BNO055LinAccData *MyLinAcc, BNO055AbsLinAccData *MyALA)  //uses last loaded QuaData and LinAccData.  ie, make sure reads for those have been called...
{
	float a1, b1, c1, d1, a2, b2, c2, d2, ra, rb, rc, rd, den; //RAM waste, but helps make it look cleaner

															   //stuff my quaternions and acceleration vectors into some variables to operate on them
															   //specifically calc q^-1.  Note, sensor seems to send the inverse.
	den = pow(MyQua->w, 2) + pow(MyQua->x, 2) + pow(MyQua->y, 2) + pow(MyQua->z, 2); // the passed quaternion 'should' be good, but just in case check

	if (den<1.01 && den>.99)  //close enough lets save some processing 
	{
		a1 = MyQua->w;
		b1 = MyQua->x;   //not negative because of how sensor sends the values
		c1 = MyQua->y;   //not negative because of how sensor sends the values
		d1 = MyQua->z;   //not negative because of how sensor sends the values

	}
	else { //oh well, time to divide some floats
		a1 = MyQua->w / den;
		b1 = MyQua->x / den;   //not negative because of how sensor sends the values
		c1 = MyQua->y / den;   //not negative because of how sensor sends the values
		d1 = MyQua->z / den;   //not negative because of how sensor sends the values
	}
	//load accel vector V
	a2 = 0;
	b2 = MyLinAcc->x;
	c2 = MyLinAcc->y;
	d2 = MyLinAcc->z;

	// time to Hamilton it up! (q^-1 * V)
	ra = a1 * a2 - b1 * b2 - c1 * c2 - d1 * d2;
	rb = a1 * b2 + b1 * a2 + c1 * d2 - d1 * c2;
	rc = a1 * c2 - b1 * d2 + c1 * a2 + d1 * b2;
	rd = a1 * d2 + b1 * c2 - c1 * b2 + d1 * a2;

	//swap some vars
	//first invert q
	a2 = a1;
	b2 = -b1;
	c2 = -c1;
	d2 = -d1;
	//now move the result
	a1 = ra;
	b1 = rb;
	c1 = rc;
	d1 = rd;


	//Hamilton it up again! (result*q)
	ra = a1 * a2 - b1 * b2 - c1 * c2 - d1 * d2;
	rb = a1 * b2 + b1 * a2 + c1 * d2 - d1 * c2;
	rc = a1 * c2 - b1 * d2 + c1 * a2 + d1 * b2;
	rd = a1 * d2 + b1 * c2 - c1 * b2 + d1 * a2;


	//finally (probably many clock cycles later) set the final values
	MyALA->x = rb;
	MyALA->y = rc;
	MyALA->z = rd;


}
/*
* @brief	BNO055 写数据
* @param reg 寄存器地址
* @param value 写入的值
* @retval	 None
* @date     07-April-2018
*/
void BNO055Write(BNO055Registers_t reg, char value)
{
	uart_putchar(BNO055PORT, 0xAA);
	uart_putchar(BNO055PORT, 0x00);
	uart_putchar(BNO055PORT, (char)reg); 
	uart_putchar(BNO055PORT, 0x01);
	uart_putchar(BNO055PORT, (char)value);
}
/*
* @brief	BNO055 读数据
* @param reg 寄存器地址
* @retval value 读出的值
* @date     07-April-2018
*/
unsigned char BNO055Read(BNO055Registers_t reg)
{
	char value[6];
	uart_putchar(BNO055PORT, 0xAA);
	uart_putchar(BNO055PORT, 0x01);
	uart_putchar(BNO055PORT, (char)reg);
	uart_putchar(BNO055PORT, 0x01);
	uart_querybuff(BNO055PORT, value, 6);
	//uart_querybuff(BNO055PORT, value, 3);
	return value[2];
}