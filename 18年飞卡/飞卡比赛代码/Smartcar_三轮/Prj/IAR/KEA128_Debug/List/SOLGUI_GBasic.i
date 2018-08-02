





typedef enum {False=0,True=!False} boolean;

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef signed long  s32;
typedef signed short s16;
typedef signed char  s8;









 
 







 


 
										 	






 


 












typedef struct __MENU_PAGE{									
	const u8 *pageTitle;									
	struct __MENU_PAGE *parentPage;							
	void (*pageFunc)();										
}MENU_PAGE;






extern MENU_PAGE UI_MENU;
























 




typedef struct __GUI_FIFO{
	u8 FIFOBuffer[5];	   						
	u8 Read;												
	u8 Write;												
}GUI_FIFO;													


void SOLGUI_Menu_SetHomePage(MENU_PAGE *home_page);	


void SOLGUI_InputKey(u8 key_value); 				
u8 	 SOLGUI_GetCurrentKey(void); 					
void SOLGUI_Menu_PageStage(void);					










	void SOLGUI_Init(MENU_PAGE *home_page); 		
 
void SOLGUI_Refresh(void);		
void SOLGUI_Clean(void);		
void SOLGUI_DrawPoint(u32 x,u32 y,u8 t);			



#include<stdarg.h> 						










 

typedef struct _FontInfo{
	u8 FontMask;		
	u8 FontWidth;		
	u8 FontHeight;		
	const u8 *Fontp;	
}FontInfo;


void __SOLGUI_printf(u32 x,u32 y,u8 mode,const u8* str,va_list arp);		




void SOLGUI_printf(u32 x,u32 y,u8 mode,const u8* str,...);	











 





void SOLGUI_GBasic_Line(u32 x0,u32 y0,u32 xEnd,u32 yEnd,u8 mode);	
void SOLGUI_GBasic_Rectangle(u32 x0,u32 y0,u32 x1,u32 y1,u8 mode);		
void SOLGUI_GBasic_MultiLine(const u32 *points,u8 num,u8 mode);		
void SOLGUI_GBasic_Circle(u32 x0,u32 y0,u32 r,u8 mode);			







void SOLGUI_Pictrue(u32 x0,u32 y0,const u8 *pic,u32 x_len,u32 y_len,u8 mode);		

u8 SOLGUI_GetPixel(u32 x,u32 y,const u8 *pic,u32 x_len,u32 y_len);				



















typedef struct _CURSOR{
	u8 cursor_rel_offset;	
	u8 viewport_offset;		
	u8 row_start;			
	u8 viewport_width;		
	u32 y_t;				
	u32	y_b;				
}CURSOR;					




typedef struct _IME_CLUSTER{ 
			u8 	finger;		
	const 	u8 	*name;		
	const 	u8 	size;		
	const 	u8	*table;		
}IME_CLUSTER;				


typedef struct _EDIT_IME{
			u8 	finger;		
	const 	u8 	size;	 	
	IME_CLUSTER *cluster[5];	
}EDIT_IME;					



typedef struct _WaveMemBlk{
	u16 size;				
	s32	*mem; 				
}WaveMemBlk;				








 




void SOLGUI_Cursor(u8 rowBorder_Top,u8 rowBorder_Bottom,u8 option_num);				


void SOLGUI_Widget_GotoPage(u8 USN,MENU_PAGE *page);								
void SOLGUI_Widget_Spin(u8 USN,const u8 *name,u8 type,double max,double min,void* value);	
void SOLGUI_Widget_OptionText(u8 USN,const u8* str,...);							
void SOLGUI_Widget_Button(u8 USN,const u8 *name,void (*func)(void));				
void SOLGUI_Widget_Switch(u8 USN,const u8 *name,u32 *mem_value,u8 L_shift);			
void SOLGUI_Widget_Edit(u8 USN,const u8 *name,u16 char_num,u8 *buf);				


void SOLGUI_Widget_Text(u32 x0,u32 y0,u8 mode,const u8* str,...);			
void SOLGUI_Widget_Bar(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,s32 value,u8 mode);		
void SOLGUI_Widget_Spectrum(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,u16 val_num,s32 value[]);	
void SOLGUI_Widget_Oscillogram(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,WaveMemBlk *wmb);  
void SOLGUI_Widget_Picture(u32 x0,u32 y0,u32 xsize,u32 ysize,const u8 *pic,u32 x_len,u32 y_len,u8 mode); 


void SOLGUI_Oscillogram_Probe(WaveMemBlk *wmb,s32 value);											




































































 




void _LineModes(s16 x,s16 y,u8 mode,u32 cnt)  		
{
	switch(mode&0x03)
	{
		case 0:SOLGUI_DrawPoint(x,y,0);break;  			
		case 2:
		{
			if(cnt%2>=1) SOLGUI_DrawPoint(x,y,1); 	
			else	SOLGUI_DrawPoint(x,y,0);break;	
		}
		case 3:
		{
			if(cnt%4>=2) SOLGUI_DrawPoint(x,y,1);  		
			else	SOLGUI_DrawPoint(x,y,0);break;		
		}
		case 1:;										
		default:SOLGUI_DrawPoint(x,y,1);	   			
	}	
}

void SOLGUI_GBasic_Line(u32 x0,u32 y0,u32 xEnd,u32 yEnd,u8 mode)		
{
	s16 dx=xEnd-x0;
	s16 dy=yEnd-y0;
	s16 ux=((dx>0)<<1)-1;
	s16 uy=((dy>0)<<1)-1;
	s16 x=x0,y=y0,eps;
	u32 cnt=0;
	
	eps=0;
	dx=(dx<0)?-dx:dx;
	dy=(dy<0)?-dy:dy; 
	if(dx>dy) 
	{
		for(x=x0;x!=xEnd+ux;x+=ux)
		{
			cnt++;
			_LineModes(x,y,mode,cnt);
			eps+=dy;
			if((eps<<1)>=dx)
			{
				y+=uy;
				eps-=dx;
			}
		}
	}
	else
	{
		for(y=y0;y!=yEnd+uy;y+=uy)
		{
			cnt++;
			_LineModes(x,y,mode,cnt);
			eps+=dx;
			if((eps<<1)>=dy)
			{
				x+=ux; 
				eps-=dy;
			}
		}
	}   
}

void SOLGUI_GBasic_MultiLine(const u32 *points,u8 num,u8 mode)
{
	u32 x0,y0;
	u32 x1,y1;
	u8 i=0;
	if(num<=0) return;		
	if(1==num)				
	{  
		x0=*points++;
		y0=*points;
		SOLGUI_DrawPoint(x0,y0,1);
	}
    
	x0=*points++;					
	y0=*points++;
	for(i=1;i<num;i++)
	{  
		x1=*points++;				
		y1=*points++;
		SOLGUI_GBasic_Line(x0,y0,x1,y1,mode);
		x0=x1;					
		y0=y1;
	}

}




void  SOLGUI_GBasic_Rectangle(u32 x0,u32 y0,u32 x1,u32 y1,u8 mode)		
{
	u32 i=0;
	u8 m=0;
	if(((mode&(1<<2)) != 0)||(mode==0x00))	
	{
		if(x0>x1) {i=x0;x0=x1;x1=i;}	
		if(y0>y1) {i=y0;y0=y1;y1=i;}	
		if(mode==0x00) m=0x00;
		else m=0x01;
		if(y0==y1) 
		{  
			SOLGUI_GBasic_Line(x0,y0,x1,y0,m);
			return;
		}
		if(x0==x1) 
		{  
			SOLGUI_GBasic_Line(x0,y0,x0,y1,m);
			return;
		}						
		while(y0<=y1)						
		{  
			SOLGUI_GBasic_Line(x0,y0,x1,y0,m);
			y0++;				
		}
	}
	else			   
	{
		SOLGUI_GBasic_Line(x0,y0,x0,y1,mode);
		SOLGUI_GBasic_Line(x0,y1,x1,y1,mode);
		SOLGUI_GBasic_Line(x1,y0,x1,y1,mode);
		SOLGUI_GBasic_Line(x0,y0,x1,y0,mode);
	}
}



						                        
void SOLGUI_GBasic_Circle(u32 x0,u32 y0,u32 r,u8 mode)
{
	u16 x=0,y=r;
	s16 delta,temp;
	
	delta = 3-(r<<1);  
	while(y>x)
	{
		if(mode==0x04)
		{
			SOLGUI_GBasic_Line(x0+x,y0+y,x0-x,y0+y,0x01);
			SOLGUI_GBasic_Line(x0+x,y0-y,x0-x,y0-y,0x01);
			SOLGUI_GBasic_Line(x0+y,y0+x,x0-y,y0+x,0x01);
			SOLGUI_GBasic_Line(x0+y,y0-x,x0-y,y0-x,0x01);
		}
		else
		{
			SOLGUI_DrawPoint(x0+x,y0+y,mode);
			SOLGUI_DrawPoint(x0-x,y0+y,mode);
			SOLGUI_DrawPoint(x0+x,y0-y,mode);
			SOLGUI_DrawPoint(x0-x,y0-y,mode);
			SOLGUI_DrawPoint(x0+y,y0+x,mode);
			SOLGUI_DrawPoint(x0-y,y0+x,mode);
			SOLGUI_DrawPoint(x0+y,y0-x,mode);
			SOLGUI_DrawPoint(x0-y,y0-x,mode);
		}
		x++;
		if(delta >= 0)
		{
			y--;
			temp= (x<<2); 
			temp-=(y<<2); 
			delta += (temp+10);
		}
		else
		{
			delta += ((x<<2)+6); 
		}
	}
}


