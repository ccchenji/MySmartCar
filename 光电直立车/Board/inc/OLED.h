/*
 * File:		nokia.h
 * Purpose:		Serial Input/Output routines
 *
 */

#ifndef _OELD_H
#define _OELD_H

#include "include.h"
/********************************************************************/
/*-----------------------------------------------------------------------
LCD_init          : OLED初始化

编写日期          ：2012-11-01
最后修改日期      ：2016-11-30
-----------------------------------------------------------------------*/

 extern  u8 cauc_logo[1024];
 void OLED_Init(void);
 void OLED_CLS(void);
 void OLED_P6x8Str(u8 x,u8 y,u8 ch[]);
 void OLED_P8x16Str(u8 x,u8 y,u8 t,u8 ch[]);
 //void OLED_P14x16Str(u8 x,u8 y,u8 t,u8 ch[]);
 //void OLED_Print(u8 x, u8 y,u8 mode,u8 ch[]);
 void OLED_PutPixel(u8 x,u8 y);
 void OLED_Rectangle(u8 x1,u8 y1,u8 x2,u8 y2,u8 gif);
 void OLED_Set_Pos(u8 x, u8 y);
 void OLED_WrDat(u8 data);
 void Draw_LibLogo(void);
 void Draw_BMP(u8 x0,u8 y0,u8 x1,u8 y1,u8 bmp[]);
 void OLED_Fill(u8 dat);
 void Dly_ms(u16 ms);
 void pixelC_HW_OLED_FillScreen(u8 bmp[128][8]);  //移植 
 void draw_cauc_logo(void);
extern void ToSting(float Value,u8 Array[]);
extern void Display_Value(u8 x,u8 y,u8 t,float Value);  


/********************************************************************/

#endif
