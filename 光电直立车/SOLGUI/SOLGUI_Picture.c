#include"SOLGUI_Include.h"

void SOLGUI_Pictrue(u32 x0,u32 y0,const u8 *pic,u32 x_len,u32 y_len,u8 mode)		//原尺寸直出
{
	//s16 y_i=0,x_i=0;
	//y0+=y_len; 	//将原点改为左下角（原本原点为右上角）
	//for(x_i=0;x_i<x_len;x_i++)
	//{
	//	for(y_i=0;y_i<y_len;y_i++)
	//	{
	//	   if(SOLGUI_GetPixel(x_i,y_i,pic,x_len,y_len)) LGUI_DrawPoint(x0+x_i,y0-y_i,mode);
	//	   else SOLGUI_DrawPoint(x0+x_i,y0-y_i,!mode);
	//	}SO
	//}
	s16 y_i = 0, x_i = 0;
        y0+=y_len;
        y0-=4;
	for (y_i = 0; y_i<(y_len-4); y_i+=2)
	{
		for (x_i = 0; x_i < x_len; x_i+=2)
		{
			if(((*(pic+y_i*(x_len>>3)+(x_i>>3)))&(1<<(7-x_i%8)))!=((1<<(7-x_i%8))))SOLGUI_DrawPoint(x0 + x_i, y0 - y_i, mode);
			else SOLGUI_DrawPoint(x0 + x_i, y0 + y_i, !mode);
		}
	}
//  SOLGUI_DrawPoint(32, 32, mode);
}

u8 SOLGUI_GetPixel(u32 x,u32 y,const u8 *pic,u32 x_len,u32 y_len)		//获取像素点值（原点为左上角为）
{     
	return bit_istrue(*(pic+(y>>3)*x_len+x),bit((7-y%8)));
}
