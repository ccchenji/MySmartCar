#include "SOLGUI_Include.h"
#include <string.h>
#include "include.h"

#if MENU_FRAME_EN==1

//##############################【全局变量定义】##############################
MENU_PAGE *current_page;//当前页面
GUI_FIFO _key_cache;	//键值FIFO
u8 cur_key = 0;			//全局键值

u8 SOLGUI_CSR = 0;		//占用标志寄存器（若非零即表示占用，不能退出当前页面）
/*----------------【占用标志寄存器】------------------
	SOLGUI_CSR[0]：	OK[深度1]占用1，空闲0
	SOLGUI_CSR[1]：	全屏占用1，空闲0（要占用全屏）
	SOLGUI_CSR[2]： OK[深度2]占用1，关闭0
-----------------------------------------------------*/

extern CURSOR *cursor;	//光标记载
extern char KEY_NUM;
extern int adc_value[4];
extern int flag_run;
extern int bInCircle;
extern int enCircle;
extern float Mvalue[4];
extern float RealSpeed;
extern float turnKp;
extern int theGroung;
extern int bInCircle;
extern int turnNum;
extern int cirControl;//进环控制
extern int timeToCircle;
extern int timeOutCircle;
MENU_PAGE UI_MENU, UI_Debug, UI_Cir;
__M_PAGE(UI_MENU, "SmartCar", PAGE_NULL,
	{
		SOLGUI_Cursor(6,0,13);
		SOLGUI_Widget_GotoPage(0,&UI_Debug);
		SOLGUI_Widget_OptionText(1, "keynum:%d" , bInCircle);
		SOLGUI_Widget_OptionText(2, "ADC0:%f"   , Mvalue[0]);
		SOLGUI_Widget_OptionText(3, "ADC1:%f"   , Mvalue[1]);
		SOLGUI_Widget_OptionText(4, "ADC2:%f"   , Mvalue[2]);
		SOLGUI_Widget_OptionText(5, "ADC3:%f"   , Mvalue[3]);
		SOLGUI_Widget_OptionText(6, "DirOut:%f", DirOut);
		SOLGUI_Widget_Spin(7, "Speed", FLT16, -100, 1000, &ExpectSpeed);
		SOLGUI_Widget_Spin(8, "SpeedOut", FLT16, 0, 2000, &RealSpeed);
		SOLGUI_Widget_OptionText(9, "Angle=%f", SystemAttitude.Pitch);
		SOLGUI_Widget_Spin(10, "offset", FLT16, -10000, 10000, &angle_offset);
		SOLGUI_Widget_Spin(11, "run", INT16, 0, 2, &flag_run);
		SOLGUI_Widget_GotoPage(12, &UI_Cir);
	});


__M_PAGE(UI_Debug, "Debug", &UI_MENU,
	{
		SOLGUI_Cursor(6,0,7);
		SOLGUI_Widget_Spin(0, "SKp", FLT16, -100, 100, &Speed_Kp);
		SOLGUI_Widget_Spin(1, "SKi", FLT16, -100, 100, &Speed_Ki);
		SOLGUI_Widget_Spin(2, "BKp", FLT16, -100, 100, &Balance_Kp);
		SOLGUI_Widget_Spin(3, "BKd", FLT16, -100, 100, &Balance_Kd);
		SOLGUI_Widget_Spin(4, "DKp", FLT16, -10000, 10000, &DirKp);
		SOLGUI_Widget_Spin(5, "DKd", FLT16, -10000, 10000, &DirKd);
		SOLGUI_Widget_OptionText(6, "DirOut:%f", DirOut);
	});

__M_PAGE(UI_Cir, "CirNum", &UI_MENU,
	{
		SOLGUI_Cursor(6,0,8);
		SOLGUI_Widget_Spin(0, "enCircle", INT16, 0, 1, &enCircle);//ExpectSpeed
                SOLGUI_Widget_Spin(1, "turnKp", FLT16, -100, 100, &turnKp);
                SOLGUI_Widget_Spin(2, "theGroung", INT16, 0, 400, &theGroung);
                SOLGUI_Widget_OptionText(3, "bInCircle:%d", bInCircle);
                SOLGUI_Widget_Spin(4, "turnNum", INT16, -200, 200, &turnNum);
		SOLGUI_Widget_Spin(5, "cirControl:", INT16, 0,1, &cirControl);
                SOLGUI_Widget_Spin(6, "ToCircle", INT16, -200, 200, &timeToCircle);
                SOLGUI_Widget_Spin(7, "OutCircle", INT16, -200, 200, &timeOutCircle);
	});
//##############################【内部使用】##############################

void FIFO_Init(void)
{
	//------------【FIFO缓存清零】
	memset(_key_cache.FIFOBuffer, 0, sizeof(_key_cache.FIFOBuffer));
	//------------【FIFO读写指针清零】
	_key_cache.Read = 0;
	_key_cache.Write = 0;
}

void FIFO_EnQueue(u8 KeyCode)
{
	_key_cache.FIFOBuffer[_key_cache.Write] = KeyCode;
	if (++_key_cache.Write >= FIFOBUF_SIZE) _key_cache.Write = 0;
}

u8 FIFO_DeQueue(void)
{
	u8 ret;
	if (_key_cache.Read == _key_cache.Write) return(FIFO_NONE); 	//FIFO空
	else
	{
		ret = _key_cache.FIFOBuffer[_key_cache.Read];
		if (++_key_cache.Read >= FIFOBUF_SIZE) _key_cache.Read = 0;
		return(ret);
	}
}

void SOLGUI_Menu_Title(MENU_PAGE *page)
{
	u8 left_len = 0, title_len = 0;

	title_len = 6 * (strlen((const char*)page->pageTitle) + 4);					//计算标题像素宽度 
	left_len = (SCREEN_X_WIDTH - title_len) >> 1;									//计算居中偏移像素

//---------【标题】
	SOLGUI_printf(left_len + 2, 56, F6X8, "[ %s ]", page->pageTitle);				//page.pageTitle  页面标题居中
	SOLGUI_GBasic_Line(6, 57, left_len + 2, 57, ACTUAL);							//标题线左
	SOLGUI_GBasic_Line(left_len + title_len - 2, 57, SCREEN_X_WIDTH - 7, 57, ACTUAL);	//标题线右
//---------【返回图标】
	if ((page->parentPage != PAGE_NULL) && (SOLGUI_CSR == 0)) SOLGUI_printf(0, 56, F6X8, "%c", ICON_BACK);	//有父页面且在非占用模式下则输出返回图标

}

//##############################【API】##############################
void SOLGUI_Menu_SetHomePage(MENU_PAGE *home_page)	//首页定义
{
	current_page = home_page;
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
	cur_key = FIFO_DeQueue();							//从池中取一个键值作为当前GUI的全局键值
//------------------【界面绘制】
	SOLGUI_Menu_Title(current_page);				//标题
//------------------【执行页面函数】
	current_page->pageFunc();						//执行页面函数
	if (cur_key == SOLGUI_KEY_BACK && SOLGUI_CSR == 0) {	//检查是否为返回键值且CSR无占用
		if (current_page->parentPage != PAGE_NULL)		//有父页面才可使用返回键
		{
			current_page = current_page->parentPage;	//下次执行父页面函数
			cursor->cursor_rel_offset = 0;			//清空光标偏移计数器
			cursor->viewport_offset = 0;
		}
	}
}

#endif
