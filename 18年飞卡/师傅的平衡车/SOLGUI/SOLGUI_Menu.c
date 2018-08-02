#include"SOLGUI_Include.h"
#include<string.h>




extern unsigned char g_nKeyValue;


extern int16 PwmSet0;
extern int16 PwmSet1;
extern int16 PwmSet2;
extern int16 PwmSet3;

extern uint16 AD_Value0 ;
extern uint16 AD_Value1 ;
extern uint16 AD_Value2 ;
extern uint16 AD_Value3 ;

extern float g_fBalance_P;
extern float g_fBalance_D;


extern BMX055Datatypedef      BMX055_data;
extern EulerAngleTypedef      SystemAttitude;            /////姿态角
extern EulerAngleTypedef      SystemAttitudeRate;        /////姿态角速度

extern float g_fAngleOffset;

extern int32 g_nLeftSpeed;
extern int32 g_nRighSpeed;

extern float g_speedControl_P;

extern float distance_m;
extern float g_fSpeedControlOut;

extern char Flag_Speed ;
extern char Flag_Direction ;
extern char Flag_Stop ;

#if MENU_FRAME_EN==1
 

//##############################【自定义页面】##############################
MENU_PAGE UI_List;  MENU_PAGE UI_Dataview; MENU_PAGE UI_Debug;
__M_PAGE(UI_List,"CAUC-2018",PAGE_NULL,
{	
  	SOLGUI_Cursor(6,0,16);
	SOLGUI_Widget_GotoPage(0, &UI_Dataview);
	SOLGUI_Widget_GotoPage(1, &UI_Debug);
    SOLGUI_Widget_OptionText(2, "CarAngle: %f", SystemAttitude.Pitch);	
	SOLGUI_Widget_OptionText(3, "Meter:   %f ", distance_m);		
	SOLGUI_Widget_Spin(4, "CarStop", INT8, 0, 1, &Flag_Stop);
	SOLGUI_Widget_Spin(5, "SpeedEN", INT8, 0, 1, &Flag_Speed);
	SOLGUI_Widget_Spin(6, "DirecEN", INT8, 0, 1, &Flag_Direction);
	//SOLGUI_Widget_Spin(11, "img_send", INT8, 0, 1, &img_send_flag);
	//SOLGUI_Widget_Spin(12, "num_send", INT8, 0, 1, &num_send_flag);
	//SOLGUI_Widget_Spin(13, "vcan_send", INT8, 0, 1, &vcan_send_flag);
	//SOLGUI_Widget_Spin(15, "st_t", INT16, 0, 10000, &za_start);
});
//-----------------------

__M_PAGE(UI_Dataview, "Dataview", &UI_List,
{
	SOLGUI_Cursor(6,0,15);
	//SOLGUI_Widget_OptionText(0,"+----[ACC Value]----+");
	SOLGUI_Widget_OptionText(0, "CarAngle: %f", SystemAttitude.Pitch);
	SOLGUI_Widget_OptionText(1, "LeftSpeed:  %d ", g_nLeftSpeed);
	SOLGUI_Widget_OptionText(2, "RightSpeed: %d ", g_nRighSpeed);
	SOLGUI_Widget_OptionText(3, "AD0:   %d ", AD_Value0);
	SOLGUI_Widget_OptionText(4, "AD1:   %d ", AD_Value1);
	SOLGUI_Widget_OptionText(5, "AD2:   %d ", AD_Value2);
	SOLGUI_Widget_OptionText(6, "AD3:   %d ", AD_Value3); 
	SOLGUI_Widget_OptionText(7, "SpdOut: %f", g_fSpeedControlOut);
	SOLGUI_Widget_OptionText(8, "DirOut: %f", g_fDirectionControlOut);	
	});
//-----------------------
__M_PAGE(UI_Debug, "Debug", &UI_List,
{
	SOLGUI_Cursor(6,0,15);
	SOLGUI_Widget_Spin(0, "Blan_P:", FLT16, -10000, 10000, &g_fBalance_P);
	SOLGUI_Widget_Spin(1, "Blan_D:", FLT16, -10000, 10000, &g_fBalance_D);
	SOLGUI_Widget_Spin(2, "AngleOff", FLT16, -10000, 10000, &g_fAngleOffset);
	SOLGUI_Widget_Spin(3, "SpdSet", FLT16, -10000, 10000, &g_fExpectSpeed);
	SOLGUI_Widget_Spin(4, "SpeedP", FLT16, -10000, 10000, &g_speedControl_P);
	SOLGUI_Widget_Spin(5, "DirP", FLT16, -10000, 10000, &g_dirControl_P);
	SOLGUI_Widget_Spin(6, "DirD", FLT16, -10000, 10000, &g_dirControl_D);

	SOLGUI_Widget_Spin(7, "0", INT16, 0, 1000, &PwmSet0);
	SOLGUI_Widget_Spin(8, "1", INT16, 0, 1000, &PwmSet1);
	SOLGUI_Widget_Spin(9, "2", INT16, 0, 1000, &PwmSet2);
	SOLGUI_Widget_Spin(10, "3", INT16, 0, 1000, &PwmSet3);
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
