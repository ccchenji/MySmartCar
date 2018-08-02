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
extern EulerAngleTypedef      SystemAttitude;            /////��̬��
extern EulerAngleTypedef      SystemAttitudeRate;        /////��̬���ٶ�

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
 

//##############################���Զ���ҳ�桿##############################
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


//##############################��ȫ�ֱ������塿##############################
MENU_PAGE *current_page;//��ǰҳ��
GUI_FIFO _key_cache;	//��ֵFIFO
u8 cur_key=0;			//ȫ�ּ�ֵ

u8 SOLGUI_CSR=0;		//ռ�ñ�־�Ĵ����������㼴��ʾռ�ã������˳���ǰҳ�棩
/*----------------��ռ�ñ�־�Ĵ�����------------------	
	SOLGUI_CSR[0]��	OK[���1]ռ��1������0
	SOLGUI_CSR[1]��	ȫ��ռ��1������0��Ҫռ��ȫ����
	SOLGUI_CSR[2]�� OK[���2]ռ��1���ر�0
-----------------------------------------------------*/

extern CURSOR *cursor;	//������

//##############################���ڲ�ʹ�á�##############################

void FIFO_Init(void)
{
//------------��FIFO�������㡿
	memset(_key_cache.FIFOBuffer,0,sizeof(_key_cache.FIFOBuffer));
//------------��FIFO��дָ�����㡿
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
	if(_key_cache.Read==_key_cache.Write) return(FIFO_NONE); 	//FIFO��
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

	title_len=6*(strlen((const char*)page->pageTitle)+4);					//����������ؿ�� 
	left_len=(SCREEN_X_WIDTH-title_len)>>1;									//�������ƫ������

//---------�����⡿
	SOLGUI_printf(left_len+2,56,F6X8,"[ %s ]",page->pageTitle);				//page.pageTitle  ҳ��������
	SOLGUI_GBasic_Line(6,57,left_len+2,57,ACTUAL);							//��������
	SOLGUI_GBasic_Line(left_len+title_len-2,57,SCREEN_X_WIDTH-7,57,ACTUAL);	//��������
//---------������ͼ�꡿
	if((page->parentPage!=PAGE_NULL)&&(SOLGUI_CSR==0)) SOLGUI_printf(0,56,F6X8,"%c",ICON_BACK);	//�и�ҳ�����ڷ�ռ��ģʽ�����������ͼ��

}

//##############################��API��##############################
void SOLGUI_Menu_SetHomePage(MENU_PAGE *home_page)	//��ҳ����
{
	current_page=home_page;
	FIFO_Init();
}

void SOLGUI_InputKey(u8 key_value) 					//������������ϵͳ�л�ȡ��ǰ������ֵ�������
{
	FIFO_EnQueue(key_value);
}

u8 SOLGUI_GetCurrentKey(void) 						//������������ȡGUI��ǰ��ȫ�ּ�ֵ
{
  	return(cur_key); 	
}

void SOLGUI_Menu_PageStage(void)					//����������SOLGUIǰ̨ҳ���л���
{
//------------------����ֵ��ȡ��
	cur_key=FIFO_DeQueue();							//�ӳ���ȡһ����ֵ��Ϊ��ǰGUI��ȫ�ּ�ֵ
//------------------��������ơ�
	SOLGUI_Menu_Title(current_page);				//����
//------------------��ִ��ҳ�溯����
	current_page->pageFunc();						//ִ��ҳ�溯��
	if(cur_key==SOLGUI_KEY_BACK&&SOLGUI_CSR==0){	//����Ƿ�Ϊ���ؼ�ֵ��CSR��ռ��
		if(current_page->parentPage!=PAGE_NULL)		//�и�ҳ��ſ�ʹ�÷��ؼ�
		{
			current_page=current_page->parentPage;	//�´�ִ�и�ҳ�溯��
			cursor->cursor_rel_offset=0;			//��չ��ƫ�Ƽ�����
			cursor->viewport_offset=0;
		}
	}
}

#endif
