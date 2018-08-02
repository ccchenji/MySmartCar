





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




































































 

 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 
















 






 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 





                 



  

                 













 

   



                 



























 


  #pragma system_include

 
 
 


  #pragma system_include

 

 

 

 

   

 

   #pragma system_include






 




 

 


 


 

 

 

 

 

 

 

 

 

 














 












 




















 










 




















































































































 


 










 





















 















 













 








 












 











 










 









 











 









 









 









 









 














 














 
















 












 








 











 










 









 









 









 









 









 









 









 









 







 




 









 




 





 
















































 













 






 


   

  







 





 





 




 



 





 




 



 












 
   






 
  #pragma language = save 
  #pragma language = extended
  #pragma language = restore






 





 




 





 








                 




















 


                 

 

 
 

 

 

 

 



                 






 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 





 

                                 













                 

                 

                 

                 
                 



                 
                                 


  #pragma language=save
  #pragma language=extended
  typedef long long _Longlong;
  typedef unsigned long long _ULonglong;
  #pragma language=restore

  typedef unsigned short int _Wchart;
  typedef unsigned short int _Wintt;



                 

typedef signed int  _Ptrdifft;
typedef unsigned int     _Sizet;

 

                 
  typedef struct __va_list __Va_list;


__intrinsic __nounwind void __iar_Atexit(void (*)(void));


  typedef struct
  {        
    unsigned int _Wchar;
    unsigned int _State;
  } _Mbstatet;



  typedef struct __FILE _Filet;


typedef struct
{        
  _Longlong _Off;     
  _Mbstatet _Wstate;
} _Fpost;




                 














 


  #pragma system_include





 






















































































 

 


  
 

   


  





  #pragma language=save 
  #pragma language=extended
  __intrinsic __nounwind void __iar_dlib_perthread_initialize(void  *);
  __intrinsic __nounwind void  *__iar_dlib_perthread_allocate(void);
  __intrinsic __nounwind void __iar_dlib_perthread_destroy(void);
  __intrinsic __nounwind void __iar_dlib_perthread_deallocate(void  *);



  #pragma segment = "__DLIB_PERTHREAD" 
  #pragma segment = "__DLIB_PERTHREAD_init" 









   
  void  *__iar_dlib_perthread_access(void  *);
  #pragma language=restore








     
  



   
    __intrinsic __nounwind void __iar_Locale_lconv_init(void);

  


  
  typedef void *__iar_Rmtx;
  
  
  __intrinsic __nounwind void __iar_system_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxunlock(__iar_Rmtx *m);

  __intrinsic __nounwind void __iar_file_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxunlock(__iar_Rmtx *m);

  
 
  __intrinsic __nounwind void __iar_clearlocks(void);



  



  


  typedef unsigned _Once_t;

  








                 


                 
  
  
    
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock(unsigned int);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock(unsigned int);

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamicfilelock(__iar_Rmtx *);
  
  

                 


                 







 
 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 






                 
typedef _Sizet size_t;

typedef unsigned int __data_size_t;













 


  #pragma system_include


  
  

  





 


  




 


  


 

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memcpy(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memcpy(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memmove(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memmove(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memset(void * _D, int _C, size_t _N)
  {
    __aeabi_memset(_D, _N, _C);
    return _D;
  }

  
  




                 

                 

_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind int        memcmp(const void *, const void *,
                                                size_t);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void *     memcpy(void *, 
                                                const void *, size_t);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void *     memmove(void *, const void *, size_t);
_Pragma("function_effects = no_state, no_read(1), returns 1, always_returns")    __intrinsic __nounwind void *     memset(void *, int, size_t);
_Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")    __intrinsic __nounwind char *     strcat(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind int        strcmp(const char *, const char *);
_Pragma("function_effects = no_write(1,2), always_returns")     __intrinsic __nounwind int        strcoll(const char *, const char *);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind char *     strcpy(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind size_t     strcspn(const char *, const char *);
                 __intrinsic __nounwind char *     strerror(int);
_Pragma("function_effects = no_state, no_write(1), always_returns")      __intrinsic __nounwind size_t     strlen(const char *);
_Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")    __intrinsic __nounwind char *     strncat(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind int        strncmp(const char *, const char *, 
                                                 size_t);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind char *     strncpy(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind size_t     strspn(const char *, const char *);
_Pragma("function_effects = no_write(2), always_returns")        __intrinsic __nounwind char *     strtok(char *, 
                                                const char *);
_Pragma("function_effects = no_write(2), always_returns")        __intrinsic __nounwind size_t     strxfrm(char *, 
                                                 const char *, size_t);

  _Pragma("function_effects = no_write(1), always_returns")      __intrinsic __nounwind char *   strdup(const char *);
  _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind int      strcasecmp(const char *, const char *);
  _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind int      strncasecmp(const char *, const char *, 
                                                   size_t);
  _Pragma("function_effects = no_state, no_write(2), always_returns")    __intrinsic __nounwind char *   strtok_r(char *, const char *, char **);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind size_t   strnlen(char const *, size_t);



  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind void *memchr(const void *_S, int _C, size_t _N);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strpbrk(const char *_S, const char *_P);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strrchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strstr(const char *_S, const char *_P);


                 

                 

_Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind void *__iar_Memchr(const void *, int, size_t);
_Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *__iar_Strchr(const char *, int);
               __intrinsic __nounwind char *__iar_Strerror(int, char *);
_Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *__iar_Strpbrk(const char *, const char *);
_Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *__iar_Strrchr(const char *, int);
_Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *__iar_Strstr(const char *, const char *);


                 
                 
    #pragma inline
    void *memchr(const void *_S, int _C, size_t _N)
    {
      return (__iar_Memchr(_S, _C, _N));
    }

    #pragma inline
    char *strchr(const char *_S, int _C)
    {
      return (__iar_Strchr(_S, _C));
    }

    #pragma inline
    char *strpbrk(const char *_S, const char *_P)
    {
      return (__iar_Strpbrk(_S, _P));
    }

    #pragma inline
    char *strrchr(const char *_S, int _C)
    {
      return (__iar_Strrchr(_S, _C));
    }

    #pragma inline
    char *strstr(const char *_S, const char *_P)
    {
      return (__iar_Strstr(_S, _P));
    }

  #pragma inline
  char *strerror(int _Err)
  {
    return (__iar_Strerror(_Err, 0));
  }









 
#include <stdarg.h> 						






const u8 SOL_ASCII_IME_lowerchar[]	="abcdefghijklmnopqrstuvwxyz";
const u8 SOL_ASCII_IME_upperchar[]	="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const u8 SOL_ASCII_IME_Number[]		="0123456789+-*/=%()[]{}<>&|~^";
const u8 SOL_ASCII_IME_symbol[]		=" .,:;_?!@#$'\"\\";
const u8 SOL_ASCII_IME_CRLchar[]	={0x00,0x0a,0x0d};	

IME_CLUSTER IME_CLUSTER_LC={0,"LOWER",26,SOL_ASCII_IME_lowerchar};		
IME_CLUSTER IME_CLUSTER_UC={0,"UPPER",26,SOL_ASCII_IME_upperchar};		
IME_CLUSTER IME_CLUSTER_NU={0,"NUMBER",28,SOL_ASCII_IME_Number};		
IME_CLUSTER IME_CLUSTER_SY={0,"SYMBOL",14,SOL_ASCII_IME_symbol};		
IME_CLUSTER IME_CLUSTER_CR={0,"CTRL",3,SOL_ASCII_IME_CRLchar};			

EDIT_IME SOL_ASCII_IME_REG={		
	0,								
	5,				
   {&IME_CLUSTER_LC,
	&IME_CLUSTER_UC,
	&IME_CLUSTER_NU,
	&IME_CLUSTER_SY,
	&IME_CLUSTER_CR}
};

EDIT_IME *SOL_ASCII_IME=&SOL_ASCII_IME_REG;








 

CURSOR cursor_reg={0,0,0,0,0,0};
CURSOR *cursor=&cursor_reg;			


u8 option_enable_list[16];	


extern MENU_PAGE *current_page;		


extern u8 SOLGUI_CSR;		



boolean _OptionsDisplay_Judge(u8 USN)
{
	if((USN-cursor->viewport_offset)>=0&&((USN-cursor->viewport_offset)<=cursor->viewport_width))	
		return(True);	
	else return(False);	 
}

u32 _OptionsDisplay_coorY(u8 USN)
{
	return((cursor->row_start-USN+cursor->viewport_offset)*8);
}



void SOLGUI_Cursor(u8 rowBorder_Top,u8 rowBorder_Bottom,u8 option_num)		
{
	u8 i=0;
	u8 temp=0;
	u8 cur_key=0;
	u8 cursor_row=0;
	u8 cursor_abs_offset=0;	

	double s_h=0;			
	u32 s_y=0;				

	if(rowBorder_Top<rowBorder_Bottom)		
	{
		temp=rowBorder_Top;
		rowBorder_Top=rowBorder_Bottom;
		rowBorder_Bottom=temp;
	}
	if(option_num>16) option_num=16;		

	cursor->row_start=rowBorder_Top;	
	cursor->viewport_width=rowBorder_Top-rowBorder_Bottom; 
	if(option_num<=cursor->viewport_width) cursor->viewport_width=option_num-1;		

	cur_key=SOLGUI_GetCurrentKey();										
	if(cur_key==0x50){											
		if(cursor->cursor_rel_offset>0&&SOLGUI_CSR==0) cursor->cursor_rel_offset--;		
		else if(cursor->viewport_offset>0&&SOLGUI_CSR==0) cursor->viewport_offset--;	 	
	}
	else if(cur_key==0x20){								    
		if((cursor->cursor_rel_offset<cursor->viewport_width)&&SOLGUI_CSR==0) cursor->cursor_rel_offset++; 
		else if((cursor->viewport_offset<option_num-cursor->viewport_width-1)&&SOLGUI_CSR==0) cursor->viewport_offset++;	 
	}
	cursor_abs_offset=cursor->viewport_offset+cursor->cursor_rel_offset;	

	cursor->y_t=rowBorder_Top*8;									
	cursor->y_b=rowBorder_Bottom*8;									

	cursor_row=cursor->y_t-cursor->cursor_rel_offset*8;	 		
	SOLGUI_printf(0,cursor_row,0x01,"%c",0x86);		

	if(rowBorder_Top!=6) SOLGUI_GBasic_Line(0,cursor->y_t+8,128-1,cursor->y_t+8,0x02);		
	if(rowBorder_Top!=0) SOLGUI_GBasic_Line(0,cursor->y_b-1,128-1,cursor->y_b-1,0x02);		

	s_h=(double)(cursor->y_t-cursor->y_b+8)/(double)option_num;									
	s_y=cursor->y_t+7-s_h*(cursor_abs_offset+1);										
	SOLGUI_GBasic_Rectangle(128-4,s_y,128-1,s_y+s_h,0x04);	
	SOLGUI_GBasic_Rectangle(128-4,cursor->y_b,128-1,cursor->y_t+7,0x01);	

	for(i=0;i<=option_num;i++){
		option_enable_list[i]=(cursor_abs_offset==i)?1:0;	
	}
}






void SOLGUI_Widget_GotoPage(u8 USN,MENU_PAGE *page)		
{
	u32 y_disp=0;	
	u8 cur_key=0;	
	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	if(USN>=16) return;		

	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{

			cur_key=SOLGUI_GetCurrentKey();				
			if(cur_key==0x40){					
				current_page=page;						
				cursor->cursor_rel_offset=0;					
				cursor->viewport_offset=0;											
			}					
		}

		SOLGUI_printf(6,y_disp,0x01,"%s",page->pageTitle);		
		SOLGUI_printf(128-13,y_disp,0x01,"%c",0x87);	

		if((cursor->viewport_offset+cursor->cursor_rel_offset)==USN)
		SOLGUI_printf(128-6,56,0x01,"%c",0x84);	
	}
}




double _Pow_10(s8 n) 	
{
	s16 i=0;
	s8 m=(n>=0)?n:-n;
	double p=1;

	for(i=0;i<m;i++)
	{
		if(n>=0) p*=10;
		else p*=0.1;
	}
	return(p);
}

void SOLGUI_Widget_Spin(u8 USN,const u8 *name,u8 type,double max,double min,void* value)		
{
	double swap;	
	u32 y_disp=0;	
	u8 cur_key=0;	

	static s8 spin_pos=0;	
	double dat_step=0;

	s8		*v_i8=0;
	u8		*v_u8=0;
	s16		*v_i16=0;
	s32		*v_i32=0;
	float 	*v_f16=0;
	double	*v_f32=0;

	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	if(max<min)
	{
		swap=max;
		max=min;
		min=swap;
	}
	if(USN>=16) return;		

	switch(type)
	{
		case 0x00:	v_i8=(s8 *)value;break;
		case 0x01:	v_u8=(u8 *)value;break;  
		case 0x03: v_i32=(s32 *)value; break;
		case 0x04: v_f16=(float *)value; break;
		case 0x05: v_f32=(double *)value; break;
		case 0x02: ;	
		default:	v_i16=(s16 *)value; break;
	}

	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{

			cur_key=SOLGUI_GetCurrentKey();				
			if(cur_key==0x40){					
				SOLGUI_CSR^=(1<<0);						
			}
			if(((SOLGUI_CSR&(1<<0)) != 0))			
			{
				dat_step=_Pow_10(spin_pos);				

				if(cur_key==0x50)														
				{
					switch(type)
					{
						case 0x00:	{if(((*v_i8)+dat_step)<=max)(*v_i8)+=(s8)dat_step;}break;
						case 0x01:	{if(((*v_u8)+dat_step)<=max)(*v_u8)+=(u8)dat_step;}break;  
						case 0x03: {if(((*v_i32)+dat_step)<=max)(*v_i32)+=(s32)dat_step;}break;
						case 0x04: {if(((*v_f16)+dat_step)<=max)(*v_f16)+=(float)dat_step;}break;
						case 0x05: {if(((*v_f32)+dat_step)<=max)(*v_f32)+=(double)dat_step;}break;
						case 0x02: ;	
						default:	{if(((*v_i16)+dat_step)<=max)(*v_i16)+=(s16)dat_step;}break;
					}	
				}
				else if(cur_key==0x20)												
				{
					switch(type)
					{
						case 0x00:	{if(((*v_i8)-dat_step)>=min)(*v_i8)-=(s8)dat_step;}break;
						case 0x01:	{if(((*v_u8)-dat_step)>=min)(*v_u8)-=(u8)dat_step;}break;  
						case 0x03: {if(((*v_i32)-dat_step)>=min)(*v_i32)-=(s32)dat_step;}break;
						case 0x04: {if(((*v_f16)-dat_step)>=min)(*v_f16)-=(float)dat_step;}break;
						case 0x05: {if(((*v_f32)-dat_step)>=min)(*v_f32)-=(double)dat_step;}break;
						case 0x02: ;	
						default:	{if(((*v_i16)-dat_step)>=min)(*v_i16)-=(s16)dat_step;}break;
					}	
				}
				else if(cur_key==0x30)												
				{
					if(spin_pos<5-1) spin_pos++;						
				}
				else if(cur_key==0x10)												
				{
					if((type==0x04)||(type==0x05)) { if(spin_pos>(-3)) spin_pos--; }	 
					else { if(spin_pos>0) spin_pos--; }		
				}
			}				
		}

		switch(type)
		{
			case 0x00:	SOLGUI_printf(68,y_disp,0x01,"%d",*v_i8);break;
			case 0x01:	SOLGUI_printf(68,y_disp,0x01,"%d",*v_u8);break; 
			case 0x03: SOLGUI_printf(68,y_disp,0x01,"%d",*v_i32);break;
			case 0x04: SOLGUI_printf(68,y_disp,0x01,"%f",*v_f16);break;
			case 0x05: SOLGUI_printf(68,y_disp,0x01,"%f",*v_f32);break;
			case 0x02: ;	
			default:	SOLGUI_printf(68,y_disp,0x01,"%d",*v_i16);break;
		}

								

		if(((SOLGUI_CSR&(1<<0)) != 0)&&(option_enable_list[USN]==1)) 
		SOLGUI_printf(0,y_disp,~0x01,"%c%f%c",0x82,dat_step,0x83);	   	
		else SOLGUI_printf(6,y_disp,0x01,"%s",name);		

		if((cursor->viewport_offset+cursor->cursor_rel_offset)==USN)
		SOLGUI_printf(128-6,56,0x01,"%c",0x84);			
	}	
}





void SOLGUI_Widget_OptionText(u8 USN,const u8* str,...)					
{
	va_list ap;
	u32 y_disp=0;	

	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	if(USN>=16) return;		


	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);

		va_start(ap,str);
		__SOLGUI_printf(6,y_disp,0x01,str,ap);		
               
		va_end(ap);
	}
}




void SOLGUI_Widget_Button(u8 USN,const u8 *name,void (*func)(void))				
{
	u32 y_disp=0;	
	u8 cur_key=0;	
	u8 run_f=0;		
	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	if(USN>=16) return;		

	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{

			cur_key=SOLGUI_GetCurrentKey();				
			if(cur_key==0x40){					
				run_f=1;								
			}					
		}

		SOLGUI_printf(6,y_disp,0x01,"%s",name);					
		SOLGUI_printf(68,y_disp,0x01,"->");						

		if(run_f==1) 											
		{
			run_f=0;											
			func();	
		}

		if((cursor->viewport_offset+cursor->cursor_rel_offset)==USN)
		SOLGUI_printf(128-6,56,0x01,"%c",0x84);			
	}
}





void SOLGUI_Widget_Switch(u8 USN,const u8 *name,u32 *mem_value,u8 L_shift)		
{
	u32 y_disp=0;	
	u8 cur_key=0;	
	u32 temp=(1<<L_shift);
	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	if((L_shift<1)||(L_shift>32)) L_shift=1;	
	if(USN>=16) return;		

	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{

			cur_key=SOLGUI_GetCurrentKey();				
			if(cur_key==0x40){					
				(*mem_value)^=temp;			
			}					
		}

		SOLGUI_printf(6,y_disp,0x01,"%s",name);						

		if((((*mem_value)&temp) != 0)) SOLGUI_printf(68,y_disp,0x01,"[ON ]");				
		else SOLGUI_printf(68,y_disp,0x01,"[OFF]");												

		if((cursor->viewport_offset+cursor->cursor_rel_offset)==USN)
		SOLGUI_printf(128-6,56,0x01,"%c",0x84);			
	}	
}




void _String_LenCtrlCpy(u16 dest_size,u8 *dest,u8 *sour)		  	
{
	if(strlen((const char *)sour)>dest_size) strncpy((char *)dest,(char *)sour,dest_size);	 
	else strcpy((char *)dest,(char *)sour);	
}

void SOLGUI_Widget_Edit(u8 USN,const u8 *name,u16 char_num,u8 *buf)			
{	
	u32 y_disp=0;	
	u8 cur_key=0;	
	u16 i=0,j=0,buf_i=0;
	u8 edit_thumbnail_buf[7];	
	static u8 edit_buf[(40+1)];			
	static u16 edit_cursor_row=0;				
	static u16 edit_cursor_col=0;				
	u16 edit_buf_size_temp=char_num<(40+1)?(char_num+1):(40+1);

	if(USN>=16) return;		
	

	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{

			cur_key=SOLGUI_GetCurrentKey();				
			if(cur_key==0x40){					

				if((edit_cursor_row==0)&&(edit_cursor_col==0)) 	 
				{
					if(((SOLGUI_CSR&(1<<1)) != 0))	
					{
						SOLGUI_CSR&=(~(1<<1));					
						_String_LenCtrlCpy(char_num,buf,edit_buf);	
					}
					else
					{
						SOLGUI_CSR|=(1<<1);					
						memset(edit_buf,0,sizeof(edit_buf));			
						_String_LenCtrlCpy(edit_buf_size_temp,edit_buf,buf);
					}
				}										
				else
				{

					SOLGUI_CSR^=(1<<2);						
				}
			}
			if(((SOLGUI_CSR&(1<<1)) != 0))			
			{
				buf_i=((128/6)-2)*edit_cursor_col+edit_cursor_row;	

				if(cur_key==0x50)								
				{
					if(((SOLGUI_CSR&(1<<2)) != 0) && (SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger
					< SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->size-1))
						SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger++;
					else if(((SOLGUI_CSR&(1<<2)) == 0)&&edit_cursor_col>0) 
						edit_cursor_col--;										
				}
				else if(cur_key==0x20)								
				{
					if(((SOLGUI_CSR&(1<<2)) != 0) && (SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger>0))
						SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger--;
					else if(((SOLGUI_CSR&(1<<2)) == 0)&&edit_cursor_col<((64/8)-4)
					&& ((buf_i+((128/6)-2))<edit_buf_size_temp)) 
						edit_cursor_col++;										
				}
				else if(cur_key==0x30)						
				{
					if(((SOLGUI_CSR&(1<<2)) != 0)&&(SOL_ASCII_IME->finger>0)) SOL_ASCII_IME->finger--;	 
					else if(((SOLGUI_CSR&(1<<2)) == 0)&&edit_cursor_row>0) edit_cursor_row--;			
				}
				else if(cur_key==0x10)						
				{
					if(((SOLGUI_CSR&(1<<2)) != 0)&&(SOL_ASCII_IME->finger<SOL_ASCII_IME->size-1)) SOL_ASCII_IME->finger++; 
					else if(((SOLGUI_CSR&(1<<2)) == 0)&&edit_cursor_row<((128/6)-3)&&((buf_i+1)<edit_buf_size_temp)) 
						edit_cursor_row++;
				}
			}				
		}

		if(((SOLGUI_CSR&(1<<1)) != 0))
		{


			SOLGUI_Clean();					
			SOLGUI_GBasic_Rectangle(0,0,128-1,64-1,0x01);		
			SOLGUI_GBasic_Line(0,9,128-1,9,0x01);						
			if(((SOLGUI_CSR&(1<<2)) != 0))										
			{
				edit_buf[buf_i-1]=SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->table[SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger];	
				SOLGUI_printf(2,1,0x01,"%s",SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->name);	   
				SOLGUI_printf(64,1,0x01,"[ %c ]",SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->table[SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger]);
			}
			else if((edit_cursor_col==0)&&(edit_cursor_row==0))		 	
			{
				SOLGUI_printf(2,1,0x01,"BACK");							
			}
			else
			{
				SOLGUI_printf(2,1,0x01,"L:%d C:%d",edit_cursor_col+1,edit_cursor_row+1); 
			}

			for(i=0;i<((64/8)-3);i++)
			{
				for(j=0;j<((128/6)-2);j++)
				{
					if(i==0&&j==0)
					{

						if((edit_cursor_row==0)&&(edit_cursor_col==0)) 
							SOLGUI_printf(6,48,~0x01,"%c",0x85);			
						else SOLGUI_printf(6,48,0x01,"%c",0x85);			
					}
					else
					{

						buf_i=((128/6)-2)*i+j-1;			
						if(buf_i<edit_buf_size_temp)
						{
							if((edit_cursor_row==j)&&(edit_cursor_col==i))					
							{
								if(edit_buf[buf_i]=='\0') SOLGUI_printf(6+j*6,48-i*8,~0x01,"%c",0x89);	
								else SOLGUI_printf(6+j*6,48-i*8,~0x01,"%c",edit_buf[buf_i]);			
							}
							else 
							{	
								if(edit_buf[buf_i]=='\0') SOLGUI_printf(6+j*6,48-i*8,0x01,"%c",0x89);   
								else SOLGUI_printf(6+j*6,48-i*8,0x01,"%c",edit_buf[buf_i]);
							}
						}
						else 
						{
							i=(64/8); j=(128/6);	
						}
					}
				}
			}												
		}
		else
		{

			SOLGUI_printf(6,y_disp,0x01,"%s",name);		
			_String_LenCtrlCpy(7,edit_thumbnail_buf,buf);	
			SOLGUI_printf(68,y_disp,0x01,"%s",edit_thumbnail_buf);			
			if(strlen((const char *)buf)>((128/6)-14))SOLGUI_printf(128-19,y_disp,0x01,"%c",0x89);	
			SOLGUI_printf(128-13,y_disp,0x01,"%c",0x88);	
		}

		if((cursor->viewport_offset+cursor->cursor_rel_offset)==USN)
		SOLGUI_printf(128-6,56,0x01,"%c",0x84);			
	}	
}





void SOLGUI_Widget_Text(u32 x0,u32 y0,u8 mode,const u8* str,...)
{
	va_list ap;

	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	va_start(ap,str);
	__SOLGUI_printf(x0,y0,mode,str,ap); 		
	va_end(ap);	
}




void SOLGUI_Widget_Bar(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,s32 value,u8 mode)		
{
	s32 swap=0;
	double f=0;
	u32 d=0;


	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	if(max<min)
	{
		swap=max;
		max=min;
		min=swap;
	}
	value=(value<max)?value:max;
	value=(value>min)?value:min;


	f=(double)(value-min)/(double)(max-min);

	if((mode&0x01)==0x00)				
	{
		d=f*xsize;
		if((mode&0x06)==0x00) 			
		{
			SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,0x01);
			SOLGUI_GBasic_Rectangle(x0,y0,x0+d,y0+ysize,0x04);		
		}
		else if((mode&0x06)==0x02)		
		{
			SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,0x01);
			SOLGUI_GBasic_Rectangle(x0,y0,x0+d,y0+ysize,0x01);
			SOLGUI_GBasic_Line(x0,y0+ysize,x0+xsize,y0+ysize,0x00);
		}
	}
	else									
	{

		d=f*ysize;
		if((mode&0x06)==0x00) 			
		{
			SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,0x01);
			SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+d,0x04);
		}
		else if((mode&0x06)==0x02)		
		{
			SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,0x01);
			SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+d,0x01);
			SOLGUI_GBasic_Line(x0,y0,x0,y0+ysize,0x00);
		}
	}
}




void SOLGUI_Widget_Spectrum(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,u16 val_num,s32 value[])
{
	s32 swap=0;
	u16 i=0;
	double delta_x=0,delta_y=0;
	double x_p=0;
	u32 x_last=x0,y_last=y0,y_zero=0;
	s32 val_now=0;

	u32 x_now=0,y_now=0;


	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	if(max<min)
	{
		swap=max;
		max=min;
		min=swap;
	}

	delta_x=(double)(val_num)/(double)(xsize);		
	delta_y=(double)(ysize)/(double)(max-min);		

	for(i=0;i<xsize;i++)
	{
		x_p+=delta_x;
		val_now=value[(int)x_p];
		x_now=x0+i;
		if((val_now>=min)&&(val_now<max)) y_now=y0+(u32)((val_now-min)*delta_y);
		else if(val_now<min) y_now=y0;
		else y_now=y0+ysize-1;
		SOLGUI_GBasic_Line(x_last,y_last,x_now,y_now,0x01);
		x_last=x_now;
		y_last=y_now;	
	}

	SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize-1,y0+ysize-1,0x01);

	if(min<0)
	{
		y_zero=y0+(u32)((-min)*delta_y);
		SOLGUI_DrawPoint(x0+1,y_zero,1);
	}	
}




void SOLGUI_Widget_Oscillogram(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,WaveMemBlk *wmb)	  
{

	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	

	SOLGUI_Widget_Spectrum(x0,y0,xsize,ysize,max,min,wmb->size,wmb->mem);	
}

void SOLGUI_Oscillogram_Probe(WaveMemBlk *wmb,s32 value)									
{
	u16 f=0,b=1;

	for(f=0,b=1;b<wmb->size;f++,b++){
		wmb->mem[f]=wmb->mem[b];				
	}
	wmb->mem[wmb->size-1]=value;				
}




void SOLGUI_Widget_Picture(u32 x0,u32 y0,u32 xsize,u32 ysize,const u8 *pic,u32 x_len,u32 y_len,u8 mode)	
{
	float fw=0,fh=0;
	u16 temp_x=0,temp_y=0;
	u16 y_i=0,x_i=0;
	u32 y0_t=y0+ysize;	
	u8 m1=0;

	if(((SOLGUI_CSR&(1<<1)) != 0)) return;	
	m1=((mode&(1<<7)) == 0);				

	if((xsize>=x_len)&&(ysize>=y_len)) 
		SOLGUI_Pictrue(x0,y0,pic,x_len,y_len,m1);
	else {

		fw=(float)x_len/xsize; fh=(float)y_len/ysize;	
		for(x_i=0;x_i<xsize;x_i++)
		{
			temp_x=(u16)(fw*x_i);		 
			for(y_i=0;y_i<ysize;y_i++)
			{
				temp_y=(u16)(fh*y_i);		  
			   	if(SOLGUI_GetPixel(temp_x,temp_y,pic,x_len,y_len)) SOLGUI_DrawPoint(x0+x_i,y0_t-y_i,m1);
			   	else SOLGUI_DrawPoint(x0+x_i,y0_t-y_i,!m1);
			}
		}
	};	

	if(((mode&(1<<6)) != 0)) SOLGUI_GBasic_Rectangle(x0,y0,x0+xsize-1,y0+ysize-1,0x01);
}





