/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       VCAN_LCD.c
 * @brief      LCD ������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-06-26
 */


#include "common.h"
#include "VCAN_LCD.h"



/*!
 *  @brief      LCD��ʼ��
 *  @since      v5.0
 */
void lcd_init(void)
{
    Site_t site = {0, 0};
    Size_t size ;

    LCD_INIT();                             //��ʼ��LCD

    //LCD_SET_DIR(LCD_DIR+1);

    //���ڳ�ʼ����ʱ����� ��Ļ���� ѡ�������ʼ����ɺ󣬲Ż�ȡ���
    size.W = LCD_W;
    size.H = LCD_H;

    lcd_rectangle(site, size, BCOLOUR);     //��ʼ������
}

/*!
 *  @brief      ��ʾʵ�ľ���
 *  @param      site    ���Ͻ�����
 *  @param      size    ���δ�С
 *  @param      rgb565  ��ɫ
 *  @since      v5.0
*  Sample usage:        Site_t site = {10,20};   //x = 10 ,y = 20
                        Size_t size = {50,60};  // W = 50 ,H = 60
                        lcd_rectangle(site, size, RED);
 */
void lcd_rectangle(Site_t site, Size_t size, uint16 rgb565)
{
    uint32 n, temp;

    LCD_PTLON(site, size);              //����

    temp = (uint32)size.W * size.H;
    LCD_RAMWR();                        //д�ڴ�
    for(n = 0; n < temp; n++)
    {
        LCD_WR_DATA( rgb565 );          //д����
    }
}

void lcd_clear(uint16 rgb565)     //����
{
    Site_t site = {0, 0};
    Size_t size;
    size.H = LCD_H;
    size.W = LCD_W;

    lcd_rectangle(site, size, rgb565);

}

//��ʮ����
void lcd_cross(Site_t site, uint16 len, uint16 Color)
{
    //������ֱ��
    Site_t sitetmp;
    Size_t size;
    int16  stmp, etmp;
    uint16 w = LCD_W, h = LCD_H;

    ASSERT((site.x < LCD_W) && (site.y < LCD_H));   //ʮ���ߵ����Ĳ��ܳ���Һ����Χ

    stmp = site.x - len / 2;                        //����ˮƽ�ߵ�x�����ͽ����㣬���Ʋ�����Һ����Χ
    if(stmp < 0)stmp = 0;
    etmp = site.x + len / 2;
    if(etmp >= w)etmp = w - 1;

    sitetmp.x = stmp;
    sitetmp.y = site.y;
    size.W = etmp - stmp + 1;
    size.H = 1;
    lcd_rectangle(sitetmp, size, Color);

    stmp = site.y - len / 2;                        //����ˮƽ�ߵ�x�����ͽ����㣬���Ʋ�����Һ����Χ
    if(stmp < 0)stmp = 0;
    etmp = site.y + len / 2;
    if(etmp >= h)etmp = h - 1;

    sitetmp.x = site.x;
    sitetmp.y = stmp;
    size.W = 1;
    size.H = etmp - stmp + 1;
    lcd_rectangle(sitetmp, size, Color);



}

/*!
 *  @brief      ����
 *  @param      site    ���Ͻ�����
 *  @param      rgb565  ��ɫ
 *  @since      v5.0
*  Sample usage:        Site_t site = {10,20};   //x = 10 ,y = 20
                        lcd_point(site, RED);
 */
void lcd_point(Site_t site, uint16 rgb565)
{
    Size_t size = {1, 1};
    LCD_PTLON(site, size);
    LCD_RAMWR();                        //д�ڴ�
    LCD_WR_DATA(rgb565);                //д����
}

/*!
 *  @brief      ��һ�ѵ�
 *  @param      site        ����������
 *  @param      point_num   �������
 *  @param      rgb565      ��ɫ
 *  @since      v5.0
*  Sample usage:        Site_t site[3] = {{10,20},{11,21},{12,22}};   //3���㣬����ֱ���  {10,20},{11,21},{12,22}
                        lcd_points(site,3, RED);
 */
void lcd_points          (Site_t *site, uint32 point_num, uint16 rgb565)                //��һ�ѵ�
{
    while(point_num--)
    {
        lcd_point(site[point_num], rgb565);                //����
    }
}

/*!
 *  @brief      ��ʾ�ַ�
 *  @param      site    ���Ͻ�����
 *  @param      ascii   �ַ�
 *  @param      Color   ������ɫ
 *  @param      bkColor ������ɫ
 *  @since      v5.0
*  Sample usage:        Site_t site = {10,20};   //x = 10 ,y = 20
                        lcd_char(site,'0', BLUE,RED);
 */
void lcd_char(Site_t site, uint8 ascii, uint16 Color, uint16 bkColor)
{
#define MAX_CHAR_POSX (LCD_W-LCD_EN_W)
#define MAX_CHAR_POSY (LCD_H-LCD_EN_H)

    uint8 temp, t, pos;
    Size_t size = {LCD_EN_W, LCD_EN_H};
    uint8 l = 0;

    if(site.x > MAX_CHAR_POSX || site.y > MAX_CHAR_POSY)
    {
        return;
    }

    LCD_PTLON(site, size);

    LCD_RAMWR();                    //д�ڴ�

    for (pos = 0; pos < LCD_EN_SIZE; pos++)
    {
        if(ascii < 0x20)
        {
            ascii = ' ';
        }

        temp = ASCII_FONT[((ascii-0x20)*LCD_EN_SIZE)+pos];

        for(t = 0; t < 8; t++)
        {

            if(temp & 0x80)
            {
                LCD_WR_DATA(Color);
            }
            else
            {
                LCD_WR_DATA(bkColor);
            }
            temp <<= 1;

            l++;

            if(l >= LCD_EN_W)
            {
                l = 0;
                break;
            }
        }
    }
    return;
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY
}

/*!
 *  @brief      ��ʾ�ַ���
 *  @param      site    ���Ͻ�����
 *  @param      Str     �ַ�����ַ
 *  @param      Color   ������ɫ
 *  @param      bkColor ������ɫ
 *  @since      v5.0
*  Sample usage:        Site_t site = {10,20};   //x = 10 ,y = 20
                        lcd_str(site,"www.vcan123.com", BLUE,RED);
 */
void lcd_str(Site_t site, uint8 *Str, uint16 Color, uint16 bkColor)
{
#define MAX_CHAR_POSX (LCD_W-LCD_EN_W)
#define MAX_CHAR_POSY (LCD_H-LCD_EN_H)
    while(*Str != '\0')
    {
        if(site.x > MAX_CHAR_POSX )
        {
            //����
            site.x = 0;
            site.y += LCD_EN_H;
        }
        if(site.y > MAX_CHAR_POSY )
        {
            //һ��
            site.y = 0;
            site.x = 0;
        }

        lcd_char(site, *Str, Color, bkColor);
        site.x += LCD_EN_W;
        Str ++ ;
    }
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY
}

/*!
 *  @brief      ��ʾ����
 *  @param      site    ���Ͻ�����
 *  @param      num     ����
 *  @param      Color   ������ɫ
 *  @param      bkColor ������ɫ
 *  @since      v5.0
*  Sample usage:        Site_t site = {10,20};   //x = 10 ,y = 20
                        lcd_num(site,123, BLUE,RED);
 */
void lcd_num(Site_t site, uint32 num, uint16 Color, uint16 bkColor)
{
    uint32 res = num;
    uint8 t = 0;
    Site_t sitetemp;
    sitetemp.y = site.y;

    if( num == 0 )
    {
        lcd_char(site, '0', Color, bkColor);
        return;
    }
    while( res )  /*�õ����ֳ���t*/
    {
        res /= 10;
        t++;
    }

    while(num)
    {
        sitetemp.x = site.x + (LCD_EN_W * (--t) );
        lcd_char(sitetemp, (num % 10) + '0', Color, bkColor);
        num /= 10 ;
    }
}

/*!
 *  @brief      ��ʾ���֣���ն����λ��
 *  @param      site            ���Ͻ�����
 *  @param      num             ����
 *  @param      max_num_bit     ����λ��
 *  @param      Color           ������ɫ
 *  @param      bkColor         ������ɫ
 *  @since      v5.0
*  Sample usage:        Site_t site = {10,20};   //x = 10 ,y = 20
                        lcd_num_bc(site,123,5, BLUE,RED);
 */
void lcd_num_bc(Site_t site, uint32 num, uint8 max_num_bit, uint16 Color, uint16 bkColor)
{
    uint32 res = num;
    uint8 t = 0;
    Site_t sitetemp;
    Size_t size;

    sitetemp.y = site.y;

    if( num == 0 )
    {
        lcd_char(site, '0', Color, bkColor);

        site.x += LCD_EN_W;
        size.H  = LCD_EN_H;
        size.W  = LCD_EN_W * (max_num_bit - 1);
        lcd_rectangle(site, size, bkColor);

        return;
    }
    while( res )            /*�õ����ֳ���t*/
    {
        res /= 10;
        t++;
    }
    if(t >= max_num_bit )    //������󳤶�
    {
        t = max_num_bit;
    }

    res = t;

    while( t != 0 )
    {
        sitetemp.x = site.x + (LCD_EN_W * (--t));
        lcd_char(sitetemp, (num % 10) + '0', Color, bkColor);
        num /= 10 ;
    }

    if(res != max_num_bit )
    {
        size.W = LCD_EN_W * (max_num_bit - res);
        site.x += (LCD_EN_W * res);
        size.H  = LCD_EN_H;
        lcd_rectangle(site, size, bkColor);
    }
}

/*!
 *  @brief      �Ҷ�ͼ����ʾ
 *  @param      site            ���Ͻ�����
 *  @param      size            ��ʾͼ���С
 *  @param      img             ͼ���ַ
 *  @since      v5.0
 *  Sample usage:       Site_t site = {10,20};      //x = 10 ,y = 20
                        Size_t size = {320,240};    //W = 320,H = 240
                        lcd_img_gray(site, size, img);
 */
void lcd_img_gray(Site_t site, Size_t size, uint8 *img)
{
    uint32     total = (size.H * size.W);
    uint16     imgtemp;
    uint8     *pimg = (uint8 *)img;

    LCD_PTLON(site, size);                      //����
    LCD_RAMWR();                                //д�ڴ�

    while(total--)
    {
        imgtemp     = (uint16) * (pimg++);
        imgtemp = GRAY_2_RGB565(imgtemp);
        LCD_WR_DATA( imgtemp );               //дͼ������
    }
}

/*!
 *  @brief      ���ŻҶ�ͼ����ʾ
 *  @param      site            ���Ͻ�����
 *  @param      size            ��ʾͼ���С
 *  @param      img             ͼ���ַ
 *  @param      imgsize         ͼ���С
 *  @since      v5.0
 *  Sample usage:       Site_t site = {10,20};          //x = 10 ,y = 20
                        Size_t size = {80,60};          //W = 80,H = 60
                        Size_t imgsize = {320,240};     //W = 320,H = 240
                        lcd_img_gray_z(site, size, img,imgsize);
 */
void lcd_img_gray_z(Site_t site, Size_t size, uint8 *img, Size_t imgsize)
{

    uint32 temp, tempY;
    uint16 x, y;
    uint16 X, Y;
    uint8 *pimg = (uint8 *)img;
    uint16 rgb;

    LCD_PTLON(site, size);                      //����

    LCD_RAMWR();                                //д�ڴ�

    for(y = 0; y < size.H; y++)
    {
        Y = ( (  y * imgsize.H   ) / size.H) ;
        tempY = Y * imgsize.W ;

        for(x = 0; x < size.W; x++)
        {
            X = ( x * imgsize.W  ) / size.W ;
            temp = tempY + X;
            rgb = GRAY_2_RGB565(pimg[temp]);    //
            LCD_WR_DATA(rgb);
        }
    }
}



void lcd_img_binary(Site_t site, Size_t size, uint8 *img)
{
    uint32     total = (size.H * size.W) / 8;
    uint8     imgtemp;
    uint8       bitindex;
    uint8     *pimg = (uint8 *)img;

    LCD_PTLON(site, size);                      //����

    LCD_RAMWR();                                //д�ڴ�

    while(total--)
    {
        imgtemp     = *(pimg++);
        bitindex    = 8;
        while(bitindex--)
        {
            if( imgtemp & (0x01 << bitindex) )
            {
                LCD_WR_DATA( BINARY_COLOR );      //дͼ������
            }
            else
            {
                LCD_WR_DATA(  BINARY_BGCOLOR  );      //дͼ������
            }
        }
    }
}

void lcd_img_binary_z(Site_t site, Size_t size, uint8 *img, Size_t imgsize)
{

    uint32 temp, tempY;
    uint16 x, y;
    uint16 X, Y;
    uint8 *pimg = (uint8 *)img;

    LCD_PTLON(site, size);                      //����

    LCD_RAMWR();                                //д�ڴ�

    for(y = 0; y < size.H; y++)
    {
        Y = ( (  y * imgsize.H  ) / size.H) ;
        tempY = Y * imgsize.W ;

        for(x = 0; x < size.W; x++)
        {
            X = (( x * imgsize.W  ) / size.W) ;
            temp = tempY + X;
            if( (pimg[temp>>3] & (1 << (7 - (temp & 0x07))) ) == 0  )
            {
                LCD_WR_DATA( BINARY_BGCOLOR );        //дͼ������
            }
            else
            {
                LCD_WR_DATA( BINARY_COLOR );      //дͼ������
            }
        }
    }
}

void lcd_wave(Site_t site, Size_t size, uint8 *img, uint8 maxval, uint16 Color , uint16 bkColor)
{

    uint8 h;
    uint16 y = site.y + size.H - 1;

    lcd_rectangle(site, size, bkColor);
    site.x += size.W;
    img  += (size.W - 1);
    while(size.W --)
    {
        if(*img >= maxval )
        {
            h = size.H - 1;
        }
        else
        {
            h = ((*img ) * size.H ) / maxval;
        }
        site.y = y - h ;
        site.x--;
        img --;
        lcd_point(site, Color);
    }
}

void lcd_wave_display(Site_t site, Size_t size, uint8 *img, uint8 maxval, uint16 Color)
{

    uint8 h;
    uint16 y = site.y + size.H - 1;

    site.x += size.W;
    img  += (size.W - 1);
    while(size.W --)
    {
        if(*img >= maxval )
        {
            h = size.H - 1;
        }
        else
        {
            h = ((*img ) * size.H ) / maxval;
        }
        site.y = y - h ;
        site.x--;
        img --;
        lcd_point(site, Color);
    }
}