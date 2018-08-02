





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




































































 




void SOLGUI_Hardware_Init(void);											
void SOLGUI_Hardware_FillScreen(u8 GRAM[128][(64/8)]);	
void SOLGUI_Hardware_ClearScreen(void);										

 
 

  #pragma system_include

 
 

 

  #pragma system_include














 


 
 


  #pragma system_include

 



  

 

 

 
#pragma rtmodel = "__dlib_version", "6"

 


 



























 


  #pragma system_include

 
 
 


  #pragma system_include

 

 

 

 

   

 
 


   #pragma system_include






 




 


 


 


 

 


 

 

 

 

 

 

 

 

 















 



















 











 























 





 



 










 














 













 








 













 













 















 











 








 








 






 





 












 





 













 






 


   


  







 





 






 




 




 













 

   




 







 







 







 










 




 



















 


 



 














 

   


 



 



 

 

 
  typedef unsigned int _Wchart;
    typedef unsigned int _Wintt;

 

 
typedef unsigned int     _Sizet;

 
typedef struct _Mbstatet
{  
    unsigned int _Wchar;   
    unsigned int _State;   

} _Mbstatet;

 

 
  typedef struct __va_list __Va_list;


    typedef struct __FILE _Filet;

 
typedef struct
{       
    long long _Off;     
  _Mbstatet _Wstate;
} _Fpost;


 

 
  
    
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);

      _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockfilelock(_Filet *);
      _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockfilelock(_Filet *);

  typedef void *__iar_Rmtx;

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamiclock(__iar_Rmtx *);

  






 
 
 


  #pragma system_include

 
 

 

  #pragma system_include














 



 
  typedef _Sizet size_t;

typedef unsigned int __data_size_t;











 


  #pragma system_include


  





 


  




 


  


 


  #pragma inline=forced_no_body
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void * memcpy(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memcpy(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void * memmove(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memmove(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  _Pragma("function_effects = no_state, no_read(1), returns 1, always_returns") __intrinsic __nounwind void * memset(void * _D, int _C, size_t _N)
  {
    __aeabi_memset(_D, _N, _C);
    return _D;
  }




 

 

 

  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   int       memcmp(const void *, const void *,
                                                   size_t);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind void *    memcpy(void *restrict, 
                                                   const void *restrict,
                                                   size_t);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind void *    memmove(void *, const void *,
                                                    size_t);
  _Pragma("function_effects = no_state, no_read(1), returns 1, always_returns")     __intrinsic __nounwind void *    memset(void *, int, size_t);
  _Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")     __intrinsic __nounwind char *    strcat(char *restrict, 
                                                   const char *restrict);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   int       strcmp(const char *, const char *);
  _Pragma("function_effects = no_write(1,2), always_returns")     __intrinsic __nounwind   int       strcoll(const char *, const char *);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind char *    strcpy(char *restrict, 
                                                   const char *restrict);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   size_t    strcspn(const char *, const char *);
                    __intrinsic __nounwind char *    strerror(int);
  _Pragma("function_effects = no_state, no_write(1), always_returns")      __intrinsic __nounwind   size_t    strlen(const char *);
  _Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")     __intrinsic __nounwind char *    strncat(char *restrict, 
                                                    const char *restrict,
                                                    size_t);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   int       strncmp(const char *, const char *, 
                                                    size_t);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind char *    strncpy(char *restrict, 
                                                    const char *restrict,
                                                    size_t);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   size_t    strspn(const char *, const char *);
  _Pragma("function_effects = no_write(2), always_returns")         __intrinsic __nounwind char *    strtok(char *restrict, 
                                                   const char *restrict);
  _Pragma("function_effects = no_write(2), always_returns")        __intrinsic __nounwind   size_t    strxfrm(char *restrict, 
                                                    const char *restrict,
                                                    size_t);
    _Pragma("function_effects = no_write(1), always_returns")      __intrinsic __nounwind   char *    strdup(const char *);
    _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind   int       strcasecmp(const char *,
                                                       const char *);
    _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind   int       strncasecmp(const char *,
                                                        const char *, size_t);
    _Pragma("function_effects = no_state, no_write(2), always_returns")    __intrinsic __nounwind   char *    strtok_r(char *, const char *,
                                                     char **);
    _Pragma("function_effects = no_state, no_write(1), always_returns")     __intrinsic __nounwind size_t    strnlen(char const *, size_t);


  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind void *memchr(const void *_S, int _C, size_t _N);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strpbrk(const char *_S, const char *_P);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strrchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strstr(const char *_S, const char *_P);






 


 
u8 SOLGUI_GRAM[128][(64/8)];




void SOLGUI_Init(MENU_PAGE *home_page) 		
{
	SOLGUI_Hardware_Init();
	memset(SOLGUI_GRAM,0,sizeof(SOLGUI_GRAM));			
	SOLGUI_Menu_SetHomePage(home_page);
}



void SOLGUI_Refresh(void)		
{
	SOLGUI_Hardware_FillScreen(SOLGUI_GRAM);
	SOLGUI_Clean();
}

void SOLGUI_Clean(void)			
{
	memset(SOLGUI_GRAM,0,sizeof(SOLGUI_GRAM));			
}

void SOLGUI_DrawPoint(u32 x,u32 y,u8 t)			
{
	unsigned char pos,bx,temp=0;
	if(x>=(128)||y>=(64))	
	{
		return;
	}
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)
	{
		SOLGUI_GRAM[x][pos]|=temp;
	}
	else 
	{
		SOLGUI_GRAM[x][pos]&=~temp;
	}

}



