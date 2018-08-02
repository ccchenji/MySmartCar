#include"SOLGUI_Include.h"
#include<string.h>

char show_ok = 0;
extern uint8 imgbuff[CAMERA_SIZE];
extern float bet_value;					//电池电压
extern char img_send_flag;			    //发送图像标志位  
extern char num_send_flag;				//发送参数标志位
extern char vcan_send_flag;				//上外上位机标志位
extern float g_AngleOfCar;				//小车角度
extern float g_BlanceControlOut;		//平衡输出
extern float g_fDirectionControlOut;	//方向输出
extern float g_fExpectSpeed;			//期望速度
extern  uint8  img[CAMERA_H][CAMERA_W]; //图像数组
extern float g_dirControl_P ;			//方向P	
extern float g_dirControl_D ;			//方向
extern float g_dirControl_gyro_D;
extern float g_speedControl_P;			//速度P
extern char img_send_flag ;			 //发送图像标志位  
extern char num_send_flag ;			 //发送参数标志位
extern char vcan_send_flag ;			 //山外上位机发送标志位
extern int stop_flag_cnt;
#if MENU_FRAME_EN==1
//绘制摄像头图像  
void Draw_PIC(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char bmp[])
{
	int32 i, j, k;
	for (i = 0; i <= 119; i++)
	{
		for (j = 0; j <= 159; j++)
		{compress_buff[i][j * 127 / 159] = img[i][j];}
	}
	for (i = 0; i <= 119; i++)
	{
		for (j = 0; j <= 127; j++)
		{compress_buff[i * 63 / 119][j] = compress_buff[i][j];}
	}
	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 127; j++)
		{
			for (k = 0; k <= 7; k++)
			{bmp_buff[i * 128 + j] += (((*(compress_buff + i * 8 + k))[j]) << k);}
		}
	}
	for (i = 0; i <= 7; i++)
	{
		bmp_buff[63 + i * 128] = ~bmp_buff[63 + i * 128];
		bmp_buff[64 + i * 128] = ~bmp_buff[63 + i * 128];
	}
	for (i = 0; i <= 127; i++)
	{
		bmp_buff[384 + i] ^= (1 << 7);
		bmp_buff[512 + i] ^= (1 << 0);
	}
	unsigned int ii = 0;
	unsigned char x, y;
	if (y1 % 8 == 0) y = y1 / 8;
	else y = y1 / 8 + 1;
	for (y = y0; y <= y1; y++)
	{
		for (x = x0; x <= x1; x++)
		{
			SOLGUI_DrawPoint(x, 63-y,  bmp[ii]);
			bmp[ii] = 0;
			ii++;
		}
	}
}
void CarStart(void)
{
  DELAY_MS(1000);
}
void SaveParameter(void)
{
	my_cnf[0].f = angle_offset;
	my_cnf[1].f = g_upstandControl_P;
	my_cnf[2].f = g_upstandControl_D;
	my_cnf[3].f = g_speedControl_P;           
	my_cnf[4].f = g_fExpectSpeed;
	my_cnf[5].f = g_dirControl_P;
	my_cnf[6].f = g_dirControl_D;
        my_cnf[7].f = g_dirControl_gyro_D;
//	my_cnf[7].f = String_Angle_D;
//	my_cnf[8].f = String_Gyro_P;
//    my_cnf[9].f = String_Gyro_I;
//	my_cnf[10].f = String_Gyro_D;
//	my_cnf[11].f = SPEED_CONTROL_P;
//	my_cnf[12].f = SPEED_CONTROL_I;
//	my_cnf[13].f = SPEED_CONTROL_D;
//	my_cnf[14].f = DIRECTION_CONTROL_P;
//	my_cnf[15].f = DIRECTION_CONTROL_D;
//	my_cnf[16].f = Begin_CarSpeed;
//	my_cnf[17].f = DIRECTION_CONTROL_DD;
//	my_cnf[18].f = DIRECTION_CONTROL_P_L;
//	my_cnf[19].f = DIRECTION_CONTROL_D_L;
	Write_config();
	
	SOLGUI_Widget_OptionText(3, "SAVE OK!");
	DELAY_MS(500);
	show_ok = 0; 

}
void run(void)
{
	stop_flag_cnt = 0;
	Flag_Stop = ON;
}
//##############################【自定义页面】##############################
MENU_PAGE UI_List;MENU_PAGE UI_image_show;MENU_PAGE UI_Dataview;MENU_PAGE UI_Debug;                    
__M_PAGE(UI_List,"CAUC-Readme",PAGE_NULL,
{
  	SOLGUI_Cursor(6,0,16);
	SOLGUI_Widget_GotoPage(0,&UI_image_show);
    SOLGUI_Widget_GotoPage(1, &UI_Debug);
    SOLGUI_Widget_GotoPage(2,&UI_Dataview);
	SOLGUI_Widget_Button(3, "SavePara", SaveParameter);
	SOLGUI_Widget_Button(4, "Run", run);
	//SOLGUI_Widget_OptionText(5, " %d ", stop_flag_cnt);
	SOLGUI_Widget_OptionText(5, "Voltage: %f v", bet_value);  //显示电压

	//SOLGUI_Widget_OptionText(5, "Voltage:  %d", img[80][20]);
	SOLGUI_Widget_Spin(6, "Speed_Set", FLT16, -10000, 10000, &g_fExpectSpeed);
	SOLGUI_Widget_OptionText(7, "Angle:   %f ", g_AngleOfCar);
	SOLGUI_Widget_Spin(8, "CarStop", INT8, 0, 1, &Flag_Stop);			
	SOLGUI_Widget_Spin(9, "SpeedEN", INT8, 0, 1, &Flag_Speed);		
	SOLGUI_Widget_Spin(10, "DirecEN", INT8, 0, 1, &Flag_Direction);		
	SOLGUI_Widget_Spin(11, "img_send", INT8, 0, 1, &img_send_flag);
	SOLGUI_Widget_Spin(12, "num_send", INT8, 0, 1, &num_send_flag);
	SOLGUI_Widget_Spin(13, "vcan_send", INT8, 0, 1, &vcan_send_flag);
});

//-----------------------

__M_PAGE(UI_image_show,"Image",&UI_List,
{
	Draw_PIC(0,0,127,63,bmp_buff);
SOLGUI_Widget_OptionText(1, "ERR %d ", ttt_cnt);
});

//-----------------------

__M_PAGE(UI_Dataview,"Dataview",&UI_List,
{
  	SOLGUI_Cursor(6,0,14); 	
        SOLGUI_Widget_OptionText(1, "L:   %f ",g_fLeftRealSpeed);
        SOLGUI_Widget_OptionText(2, "R:   %f ",g_fRighRealSpeed);
         SOLGUI_Widget_OptionText(3, "1:   %f ",direc_err_1);
         SOLGUI_Widget_OptionText(4, "2:   %f ",direc_err_2);
         SOLGUI_Widget_OptionText(5, "3:   %f ",direc_err_3);
});
//-----------------------
__M_PAGE(UI_Debug,"Debug",&UI_List,
{
		SOLGUI_Cursor(6,0,16);
		SOLGUI_Widget_Spin(0, "angel_P", FLT16, -800, 800, &g_upstandControl_P);
		SOLGUI_Widget_Spin(1, "angel_D",FLT16, -2000, 2000, &g_upstandControl_D);
		SOLGUI_Widget_Spin(2, "speed_P", FLT16, -2000, 2000, &g_speedControl_P);	
		SOLGUI_Widget_Spin(3, "direc_P", FLT16, -2000, 2000, &g_dirControl_P);
		SOLGUI_Widget_Spin(4, "direc_D", FLT16, -2000, 2000, &g_dirControl_D);
                SOLGUI_Widget_Spin(5, "direc_GD", FLT16, -2000, 2000, &g_dirControl_gyro_D);
                SOLGUI_Widget_Spin(6, "AngOffset", FLT16, -2000, 2000, &angle_offset);
                SOLGUI_Widget_Spin(7, "CirOffset", INT16, -2000, 2000, &circle_offset);
});

//##############################【全局变量定义】##############################
MENU_PAGE *current_page;//当前页面
GUI_FIFO _key_cache;	//键值FIFO
u8 cur_key=0;			//全局键值

u8 SOLGUI_CSR=0;		//占用标志寄存器（若非零即表示占用，不能退出当前页面）
/*----------------【占用标志寄存器】------------------	
	SOLGUI_CSR[0]：	OK[深度1]占用1，空闲0
	SOLGUI_CSR[1]：	全屏占用1，空闲0（要占用全屏）
	SOLGUI_CSR[2]： OK[深度2]占用1，关闭0
-----------------------------------------------------*/

extern CURSOR *cursor;	//光标记载

//##############################【内部使用】##############################

void FIFO_Init(void)
{
//------------【FIFO缓存清零】
	memset(_key_cache.FIFOBuffer,0,sizeof(_key_cache.FIFOBuffer));
//------------【FIFO读写指针清零】
	_key_cache.Read=0;
	_key_cache.Write=0;
}

void FIFO_EnQueue(u8 KeyCode)
{
	_key_cache.FIFOBuffer[_key_cache.Write]=KeyCode;
	if(++_key_cache.Write>=FIFOBUF_SIZE) _key_cache.Write=0;
}

u8 FIFO_DeQueue(void)
{
	u8 ret;
	if(_key_cache.Read==_key_cache.Write) return(FIFO_NONE); 	//FIFO空
	else
	{
		ret=_key_cache.FIFOBuffer[_key_cache.Read];
		if (++_key_cache.Read>=FIFOBUF_SIZE) _key_cache.Read=0;
		return(ret);
	}
} 

void SOLGUI_Menu_Title(MENU_PAGE *page)
{
	u8 left_len=0,title_len=0;

	title_len=6*(strlen((const char*)page->pageTitle)+4);					//计算标题像素宽度 
	left_len=(SCREEN_X_WIDTH-title_len)>>1;									//计算居中偏移像素

//---------【标题】
	SOLGUI_printf(left_len+2,56,F6X8,"[ %s ]",page->pageTitle);				//page.pageTitle  页面标题居中
	SOLGUI_GBasic_Line(6,57,left_len+2,57,ACTUAL);							//标题线左
	SOLGUI_GBasic_Line(left_len+title_len-2,57,SCREEN_X_WIDTH-7,57,ACTUAL);	//标题线右
//---------【返回图标】
	if((page->parentPage!=PAGE_NULL)&&(SOLGUI_CSR==0)) SOLGUI_printf(0,56,F6X8,"%c",ICON_BACK);	//有父页面且在非占用模式下则输出返回图标

}

//##############################【API】##############################
void SOLGUI_Menu_SetHomePage(MENU_PAGE *home_page)	//首页定义
{
	current_page=home_page;
	FIFO_Init();
}

void SOLGUI_InputKey(u8 key_value) 					//【非阻塞】从系统中获取当前按键键值存入键池
{
	FIFO_EnQueue(key_value);
}

u8 SOLGUI_GetCurrentKey(void) 						//【非阻塞】获取GUI当前的全局键值
{
  	return(cur_key); 	
}

void SOLGUI_Menu_PageStage(void)					//【非阻塞】SOLGUI前台页面切换器
{
//------------------【键值获取】
	cur_key=FIFO_DeQueue();							//从池中取一个键值作为当前GUI的全局键值
//------------------【界面绘制】
	SOLGUI_Menu_Title(current_page);				//标题
//------------------【执行页面函数】
	current_page->pageFunc();						//执行页面函数
	if(cur_key==SOLGUI_KEY_BACK&&SOLGUI_CSR==0){	//检查是否为返回键值且CSR无占用
		if(current_page->parentPage!=PAGE_NULL)		//有父页面才可使用返回键
		{
			current_page=current_page->parentPage;	//下次执行父页面函数
			cursor->cursor_rel_offset=0;			//清空光标偏移计数器
			cursor->viewport_offset=0;
		}
	}
}

#endif
