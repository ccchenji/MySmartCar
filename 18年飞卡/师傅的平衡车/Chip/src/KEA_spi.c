/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_spi.c
 * @brief      SPI驱动函数
 * @author     山外科技
 * @version    v5.0
 * @date       2013-07-16
 */

#include "common.h"
#include "KEA_gpio.h"
#include "KEA_spi.h"


SPI_MemMapPtr SPIN[2] = {SPI0_BASE_PTR, SPI1_BASE_PTR,}; //定义三个指针数组保存 SPIx 的地址



#define SPI_TX_WAIT(SPIn)     while(  ( SPI_SR_REG(SPIN[SPIn]) & SPI_SR_TXRXS_MASK ) == 1 ) //等待发送 完成
#define SPI_RX_WAIT(SPIn)     while(  ( SPI_SR_REG(SPIN[SPIn]) & SPI_SR_RFDF_MASK ) == 0 )  //等待发送 FIFO为非空
#define SPI_EOQF_WAIT(SPIn)   while(  (SPI_SR_REG(SPIN[SPIn]) & SPI_SR_EOQF_MASK ) == 0 )   //等待传输完成


uint32 spi_set_baud (SPIn_e spin,                      uint32 baud, uint32 bus_khz)
{
    uint8  SPPR, SPR;
    uint32 clk = bus_khz * 1000 / baud;
    uint32 Scaler[] = {2, 4, 6, 8, 16, 32, 64, 128, 256, 512};
    uint32 fit_SPPR = 0, fit_SPR, min_diff = ~0, diff;
    uint32 tmp;

    //计算波特率 BaudRate 有如下关系：
    //分频系数：BusClock/ BaudRate =(SPPR + 1) * ( 1<<(SPR + 1) )
    // SPPR (0~7)
    // SPR  (0~8)
    for(SPPR = 0; SPPR <= 7; SPPR++)
    {
        for(SPR = 0; SPR <= 8; SPR++)
        {
            tmp = (SPPR + 1) * Scaler[SPR];
            diff = abs(tmp - clk);
            if(min_diff > diff && clk <= tmp)
            {
                //记住 最佳配置
                min_diff = diff;
                fit_SPR = SPR;
                fit_SPPR = SPPR;

                if(min_diff == 0)
                {
                    //刚好匹配

                    goto SPI_CLK_EXIT;
                }

            }

        }
    }
SPI_CLK_EXIT:
    SPI_BR_REG(spin) = ( 0
                         |  SPI_BR_SPR(SPR)
                         |  SPI_BR_SPPR(SPPR)

                       );

    return  ((fit_SPPR + 1) * Scaler[fit_SPR]);

}

/*!
 *  @brief      SPI初始化，设置模式
 *  @param      SPIn_e          SPI模块(SPI0、SPI1、SPI2)
 *  @param      SPIn_PCSn_e     片选管脚编号
 *  @param      SPI_CFG         SPI主从机模式选择
 *  @since      v5.0
 *  Sample usage:       uint32 baud = spi_init(SPI0,SPIn_PCS0, MASTER,10*1000*1000);              //初始化SPI,选择CS0,主机模式, 波特率为1M ,返回真实波特率到baud变量
 */
uint32 spi_init(SPIn_e spin, PTXn_e pcs, SPI_CFG cfg, uint32 baud, uint32 bus_khz, char use_pin_mode)
{





    //使能SPI模块时钟，配置SPI引脚功能
    if(spin == SPI0)
    {
        SIM_SCGC |= SIM_SCGC_SPI0_MASK;

        //进行管脚复用
        if (use_pin_mode == 0)
            SIM_PINSEL0 &= ~SIM_PINSEL_SPI0PS_MASK;
        else if(use_pin_mode == 1)
            SIM_PINSEL0 |= SIM_PINSEL_SPI0PS_MASK;
        else
            return 0;
    }
    else if(spin == SPI1)
    {
        SIM_SCGC |= SIM_SCGC_SPI1_MASK;
        if (use_pin_mode == 0)
            SIM_PINSEL1 &= ~SIM_PINSEL1_SPI1PS_MASK;
        else if (use_pin_mode == 1)
            SIM_PINSEL1 |= SIM_PINSEL1_SPI1PS_MASK;
        else
            return 0;
    }
    else
    {
        //传递进来的 spi 模块有误，直接判断断言失败
        ASSERT(0);

        return 0;
    }

    if(cfg & MASTER)
    {
        SPI_C1_REG(spin) = ( 0
                             | SPI_C1_SPE_MASK   //SPI 使能
                             | cfg
                             | SPI_C1_SSOE_MASK  // 和 C2[MODFEN] 共同确认功能。这里置1，然后 C2[MODFEN] 为1 则自动输出PCS，为0则通用IO。
                           );

        SPI_C2_REG(spin) = ( 0
                             //| SPI_C2_MODFEN_MASK    //1 为自动PCS ，0为 通用IO
                           );

        baud = spi_set_baud(spin, baud, bus_khz) ;

        gpio_init(pcs, GPO, 1);
    }
    else
    {
        //暂不支持从机模式
        ASSERT(0);

        return 0;
    }



    return  baud;

}

/*!
 *  @brief      SPI发送接收函数
 *  @param      SPIn_e          SPI模块(SPI0、SPI1、SPI2)
 *  @param      SPIn_PCSn_e     片选管脚编号
 *  @param      modata          发送的数据缓冲区地址(不需要接收则传 NULL)
 *  @param      midata          发送数据时接收到的数据的存储地址(不需要接收则传 NULL)
 *  @since      v5.0
 *  Sample usage:           spi_mosi(SPI0,SPIn_PCS0,buff,buff,2);    //发送buff的内容，并接收到buff里，长度为2字节
 */
void spi_mosi(SPIn_e spin, PTXn_e pcs, uint8 *modata, uint8 *midata, uint32 len)
{
    uint32 i = 0;

    gpio_set(pcs, 0);
    /***************** 发送len个数据 *******************/                                                ;
    for(i = 0; i < len; i++)
    {

        while(!(SPI_S_REG(spin) & SPI_S_SPTEF_MASK));        //等待传输为空
        if(modata != NULL)
        {
            SPI_D_REG(spin) = modata[i];
        }
        else
        {
            SPI_D_REG(spin) = 0xFF;
        }

        while(!(SPI_S_REG(spin) & SPI_S_SPRF_MASK));        //等待接收完成
        if(midata != NULL)
        {
            midata[i] = (uint8)SPI_D_REG(spin);                  //保存接收到的数据
        }
        else
        {
            SPI_D_REG(spin);
        }

    }
    gpio_set(pcs, 1);
}

/*!
 *  @brief      SPI发送接收函数
 *  @param      SPIn_e          SPI模块(SPI0、SPI1、SPI2)
 *  @param      SPIn_PCSn_e     片选管脚编号
 *  @param      mocmd           发送的命令缓冲区地址(不需要接收则传 NULL)
 *  @param      micmd           发送命令时接收到的数据的存储地址(不需要接收则传 NULL)
 *  @param      modata          发送的数据缓冲区地址(不需要接收则传 NULL)
 *  @param      midata          发送数据时接收到的数据的存储地址(不需要接收则传 NULL)
 *  @since      v5.0
 *  Sample usage:           spi_mosi_cmd(SPI0,SPIn_PCS0,cmd,NULL,buff,buff,1,2);    //发送cmd/buff的内容，不接收cmd发送时的数据，接收buff发送时的数据到buff里，长度分别为1、2字节
 */
void spi_mosi_cmd(SPIn_e spin, PTXn_e pcs, uint8 *mocmd , uint8 *micmd , uint8 *modata , uint8 *midata, uint32 cmdlen , uint32 len)
{
    uint32 i = 0;

    gpio_set(pcs, 0);
    /***************** 发送 cmdlen 个数据 *******************/                                                ;
    for(i = 0; i < cmdlen; i++)
    {

        while(!(SPI_S_REG(spin) & SPI_S_SPTEF_MASK));        //等待传输为空
        if(mocmd != NULL)
        {
            SPI_D_REG(spin) = mocmd[i];
        }
        else
        {
            SPI_D_REG(spin) = 0xFF;
        }

        while(!(SPI_S_REG(spin) & SPI_S_SPRF_MASK));        //等待接收完成
        if(micmd != NULL)
        {
            micmd[i] = (uint8)SPI_D_REG(spin);                  //保存接收到的数据
        }
        else
        {
            SPI_D_REG(spin);
        }

    }

    /***************** 发送len个数据 *******************/                                                ;
    for(i = 0; i < len; i++)
    {

        while(!(SPI_S_REG(spin) & SPI_S_SPTEF_MASK));        //等待传输为空
        if(modata != NULL)
        {
            SPI_D_REG(spin) = modata[i];
        }
        else
        {
            SPI_D_REG(spin) = 0xFF;
        }

        while(!(SPI_S_REG(spin) & SPI_S_SPRF_MASK));        //等待接收完成
        if(midata != NULL)
        {
            midata[i] = (uint8)SPI_D_REG(spin);                  //保存接收到的数据
        }
        else
        {
            SPI_D_REG(spin);
        }

    }
    gpio_set(pcs, 1);

}


