/*
                 ██████╗ █████╗ ██╗   ██╗ ██████╗                   
                ██╔════╝██╔══██╗██║   ██║██╔════╝                   
                ██║     ███████║██║   ██║██║                        
                ██║     ██╔══██║██║   ██║██║                        
                ╚██████╗██║  ██║╚██████╔╝╚██████╗                   
                 ╚═════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝                   

*/ 
/*!
* @file       parameter.c
* @brief      全局参数
* @author     JassyLiu
* @date       2016-12-06
* @revision
* @note
*/
#include "common.h"
#include "include.h"
#include "parameter.h"
uint8 SD_Record_Buff[512];
uint8 SD_Send_Buff[512];
//uint16  Block_Index = 0;
uint16  Block_Index_send = 0;
extern uint8 imgbuff[CAMERA_SIZE];
//int fun(int k)
//{
//	int sum = 0, cnt = 0, j;
//	while ((k >= 12) && cnt < 10)
//	{
//		if ((k % 13 == 0) || (k % 17 == 0))
//		{
//			sum = sum + k; cnt++;
//		}
//		k--;
//	}
//	return sum;
//}
/****************全局变量定义******************/
uint8 Flag_SpeedControl = 0;
uint8 Flag_Stop = ON;			//=OFF停车
uint8 Flag_Speed = ON;			//=ON加速度控制
uint8 Flag_Direction = ON;		//=ON加方向控制
uint8 Flag_Out = 2;				//虚拟示波器显示标志
uint8 Flag_Buzz = OFF;			//=OFF蜂鸣器静音
/**************************摄像头接收解压数组******************************/
uint8  imgbuff1[CAMERA_SIZE];         //采集图像数组1
uint8  imgbuff2[CAMERA_SIZE];         //采集图像数组2
uint8 *  p_imgbuff1 = (uint8 *)((uint8 *)&imgbuff1);   //图像地址1
uint8 *  p_imgbuff2 = (uint8 *)((uint8 *)&imgbuff2);     //图像地址2
uint8  flag_imgbuff = 0;
uint8  img[CAMERA_H][CAMERA_W];							//解压之后图像

uint8  bmp_buff[1024] = { 0 };
uint8  compress_buff[120][128] = { 0 };
void parameter_init(void)
{
	load_config();      //更新联合体
	angle_offset = my_cnf[0].f;
	g_upstandControl_P = my_cnf[1].f;
	g_upstandControl_D = my_cnf[2].f;
	g_speedControl_P   = my_cnf[3].f;
	g_fExpectSpeed	   = my_cnf[4].f;
	g_dirControl_P = my_cnf[5].f;
	g_dirControl_D = my_cnf[6].f;
        g_dirControl_gyro_D = my_cnf[7].f;
//	String_Angle_D = my_cnf[7].f;
//	String_Gyro_P = my_cnf[8].f;
//	String_Gyro_I = my_cnf[9].f;
//	String_Gyro_D = my_cnf[10].f;
//	SPEED_CONTROL_P = my_cnf[11].f;
//	SPEED_CONTROL_I = my_cnf[12].f;
//	SPEED_CONTROL_D = my_cnf[13].f;
//	DIRECTION_CONTROL_P = my_cnf[14].f;
//	DIRECTION_CONTROL_D = my_cnf[15].f;
//	Begin_CarSpeed = my_cnf[16].f;
//	DIRECTION_CONTROL_DD = my_cnf[17].f;
//	DIRECTION_CONTROL_P_L = my_cnf[18].f;
//	DIRECTION_CONTROL_D_L = my_cnf[19].f;
}

void sdcard_record(void)
{
	//float temp;
	unsigned int i=0;
	unsigned int j=0;
	//unsigned int data_num = 600;
	SD_Record_Buff[j++] = 0x11;
	SD_Record_Buff[j++] = 0x22;
	SD_Record_Buff[j++] = 0x33;
	//SD_Record_Buff[j++] = data_num;
	for (i = 0;i < 300; i++)
	{
		//temp = data_num;
		//SD_Record_Buff[j++] = BYTE0(temp);
		//SD_Record_Buff[j++] = BYTE1(temp);
		//SD_Record_Buff[j++] = BYTE2(temp);
		//SD_Record_Buff[j++] = BYTE3(temp);
		SD_Record_Buff[j++] = 2;//imgbuff[i];
	}
	SD_Record_Buff[j++] = 0xdd;
	SD_Record_Buff[j++] = 0xbb;
	SD_Record_Buff[j++] = 0xcc;
	SD_WriteDisk(SD_Record_Buff, BLOCK_BEGIN + Block_Index);
	Block_Index++;

	j = 0;
	SD_Record_Buff[j++] = 0x44;
	SD_Record_Buff[j++] = 0x77;
	SD_Record_Buff[j++] = 0x66;
	for (i = 300;i < 600; i++)
	{
		//temp = data_num;
		//SD_Record_Buff[j++] = BYTE0(temp);
		//SD_Record_Buff[j++] = BYTE1(temp);
		//SD_Record_Buff[j++] = BYTE2(temp);
		//SD_Record_Buff[j++] = BYTE3(temp);
		SD_Record_Buff[j++] = 4;//imgbuff[i];
	}
	SD_Record_Buff[j++] = 0xaa;
	SD_Record_Buff[j++] = 0xbb;
	SD_Record_Buff[j++] = 0xcc;
	SD_WriteDisk(SD_Record_Buff, BLOCK_BEGIN + Block_Index);
	Block_Index++;

}

void sdcard_send(void)
{
	int i;
	SD_ReadDisk(SD_Send_Buff, Block_Index + BLOCK_BEGIN-1);
	for (i = 0;i < 512;i++)
	{
		uart_putchar(UART1, SD_Send_Buff[i]);
		if (i >= 3)
		{
			if (SD_Send_Buff[i - 2] == 0xaa)
			{
				if (SD_Send_Buff[i - 1] == 0xbb)
				{
					if (SD_Send_Buff[i] == 0xcc)
					{
						break; //后面的数据无效，没必要发送
					}
				}
			}
		}
	}

	SD_ReadDisk(SD_Send_Buff, Block_Index_send + BLOCK_BEGIN-1);
	for (i = 0;i < 512;i++)
	{
		uart_putchar(UART1, SD_Send_Buff[i]);
		if (i >= 3)
		{
			if (SD_Send_Buff[i - 2] == 0xaa)
			{
				if (SD_Send_Buff[i - 1] == 0xbb)
				{
					if (SD_Send_Buff[i] == 0xcc)
					{
						break; //后面的数据无效，没必要发送
					}
				}
			}
		}
	}
	Block_Index_send -= 2;
}