





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




































































 

#include<stdarg.h> 						




extern const u8 _Font6x8[][8];



extern const u8 _Font4x6[][6];










extern const u8 _Font8x8[][8];



extern const u8 _Font8x10[][10];





FontInfo _fontInfo_6x8={0x01,6,8,(u8*)_Font6x8};	   	

FontInfo _fontInfo_8x10={0x08,8,10,(u8*)_Font8x10};	   	


FontInfo SOLGUI_SwitchFont(u8 mode)
{
	switch(mode)
	{
		case 0x01:
		case 0:
		case 0xfe:	return(_fontInfo_6x8);
		case 0x08:
		case 0xf7:	return(_fontInfo_8x10);
		default: 	return(_fontInfo_6x8);
	}
}




void SOLGUI_PutChar(u32 x,u32 y,u8 ch,u8 mode)
{
	u8 temp,m=1,tl,x0=x;
	s8 t;
	FontInfo fi=SOLGUI_SwitchFont(mode);
	m=mode&fi.FontMask;

	ch=ch-' ';
	for(t=fi.FontHeight-1;t>=0;t--)								
	{	
		 temp=*(fi.Fontp+ch*fi.FontHeight+t);
		 for(tl=0;tl<8;tl++)
		 {
		 	if(temp&0x80) SOLGUI_DrawPoint(x,y,m);
			else SOLGUI_DrawPoint(x,y,!m);
			temp<<=1;
			x++;
			if((x-x0)==8)
			{ 
				x=x0;
				y++;
				break;
			}
		 }
	}
}



void SOLGUI_PutString(u32 x,u32 y,const u8 *str,u8 mode)	
{
	u8 j=0;
	FontInfo fi=SOLGUI_SwitchFont(mode);

	while (str[j]!='\0')
	{		
		SOLGUI_PutChar(x,y,str[j],mode);
		x+=fi.FontWidth;										
		j++;
	}
}




void __SOLGUI_printf(u32 x,u32 y,u8 mode,const u8* str,va_list arp)		
{
	u8 xpp=x;
	u8 f,r,fl=0,l=3,lt;		
	u8 i,j,w,lp;
	u32 v;
	s8 c, d, s[16], *p;
	s16 res, chc, cc,ll;
	s16 kh,kl,pow=1;
	double k;
	FontInfo fi=SOLGUI_SwitchFont(mode);

	for (cc=res=0;cc!=-1;res+=cc) 		   			
	{
		c = *str++;						   			

		if (c == 0) break;					

		if (c != '%') {						
			
			SOLGUI_PutChar(xpp,y,c,mode);
			xpp+=fi.FontWidth;									
			continue;
		}

		w=f=0;
		k=0;
		lp=0;
		c=*str++;				   					
		if (c == '0') {								
			f = 1; c = *str++;						
		} 
		else if (c == '-') {							
				f = 2; c = *str++;					
			}
		else if (c == '.') {						
			fl=1;c=*str++;
		}

		while (((c)>='0')&&((c)<='9')) {			
			if(fl==1){
				lp=lp*10+c-'0';		
				c=*str++;
			}
			else{
				w=w*10+c-'0';		
				c=*str++;
			}								
		}
		if(fl==1) l=(lp>7)? 7:lp;
		if (c == 'l' || c == 'L') {					
			f |= 4; c = *str++;		 				
		}
		if (!c) break;								

		d = c;						
		if (((c)>='a')&&((c)<='z')) d -= 0x20;		
		switch (d) {								

		case 'S' :					 
			p = va_arg(arp,s8*);					
			for(j=0;p[j];j++);						
			ll=j;
			chc = 0;
			if (!(f&2)) {							
				while (j++ < w) 
				{
					SOLGUI_PutChar(xpp,y,' ',mode);
					chc+=1;
					xpp+=fi.FontWidth;						
				}
			}
			SOLGUI_PutString(xpp,y,(unsigned char *)p,mode);
			xpp=xpp+fi.FontWidth*ll;						
			chc+=ll;
			while (j++ < w) 						
			{
				SOLGUI_PutChar(xpp,y,' ',mode);
				chc+=1;
				xpp+=fi.FontWidth;						
			}	 
			cc = chc;
			continue;

		case 'C' :
		{					 
		
			SOLGUI_PutChar(xpp,y,(char)va_arg(arp,int),mode);
			xpp+=fi.FontWidth;								
			continue;
		}

		case 'F' :											
		{													 												
			k=va_arg(arp,double);
			if(k<0){
				l|=8;
				k*=-1;										
			}
			kh=(int)k;										
			pow=1;
			lt=l&7;
			while((lt-1)>=0){
				pow*=10;
				lt--;
			}
			kl=(int)(pow*(k-kh));				
			i=0;

			lt=l&7;
			while(lt--){												
				if(kl){
					d=(char)(kl%10);							
					kl/=10;										
					s[i++]='0'+d;								
				}
				else s[i++]='0';
			}

			s[i++]='.';										
			do{												
				d=(char)(kh%10);								
				kh/=10;										
				s[i++]='0'+d;								
			}while(kh && i<sizeof s /sizeof s[0]);
			if (l&8)s[i++]='-';								
			fl=0;	
			goto PRT;
		}
		case 'B' :					 
			r = 2; break;
		case 'O' :					 
			r = 8; break;
		case 'D' :					 
		case 'U' :					 
			r = 10; break;
		case 'X' :					 
			r = 16; break;
		default:{					 
				SOLGUI_PutChar(xpp,y,c,mode);
				xpp+=fi.FontWidth;								
				cc=1;
				continue;
			}
		}

		 
 
		v =(f&4)?(unsigned long)va_arg(arp, long):((d=='D')?(unsigned long)(long)va_arg(arp, int):(unsigned long)va_arg(arp, unsigned int));
		if (d == 'D' && (v & 0x80000000)) {					
			v = 0 - v;										
			f |= 8;											
		}
		i = 0;
		do {												
			d=(char)(v%r);									
			v/=r;											
			if(d>9)d+=(c=='x')?0x27:0x07;					
			s[i++]=d+'0';									
		} while (v && i<sizeof s /sizeof s[0]);				
		if (f & 8) s[i++] = '-';							
PRT:		
		j=i;
		d=(f&1)?'0':' ';									
		while (!(f&2)&&j++<w)
		{
			
			SOLGUI_PutChar(xpp,y,d,mode);
			xpp+=fi.FontWidth;									
		}
		do 
		{
			
			SOLGUI_PutChar(xpp,y,s[--i],mode);
			xpp+=fi.FontWidth;									
		}while(i);

		while (j++ < w) 
		{
			
			SOLGUI_PutChar(xpp,y,d,mode);
			xpp+=fi.FontWidth;										
		}
	}
}



void SOLGUI_printf(u32 x,u32 y,u8 mode,const u8* str,...)			
{
	va_list arp;
	va_start(arp,str);								
	__SOLGUI_printf(x,y,mode,str,arp);				
	va_end(arp);
}


