/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_spi.c
 * @brief      SPI��������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-07-16
 */

#include "common.h"
#include "KEA_gpio.h"
#include "KEA_spi.h"


SPI_MemMapPtr SPIN[2] = {SPI0_BASE_PTR, SPI1_BASE_PTR,}; //��������ָ�����鱣�� SPIx �ĵ�ַ



#define SPI_TX_WAIT(SPIn)     while(  ( SPI_SR_REG(SPIN[SPIn]) & SPI_SR_TXRXS_MASK ) == 1 ) //�ȴ����� ���
#define SPI_RX_WAIT(SPIn)     while(  ( SPI_SR_REG(SPIN[SPIn]) & SPI_SR_RFDF_MASK ) == 0 )  //�ȴ����� FIFOΪ�ǿ�
#define SPI_EOQF_WAIT(SPIn)   while(  (SPI_SR_REG(SPIN[SPIn]) & SPI_SR_EOQF_MASK ) == 0 )   //�ȴ��������


uint32 spi_set_baud (SPIn_e spin,                      uint32 baud, uint32 bus_khz)
{
    uint8  SPPR, SPR;
    uint32 clk = bus_khz * 1000 / baud;
    uint32 Scaler[] = {2, 4, 6, 8, 16, 32, 64, 128, 256, 512};
    uint32 fit_SPPR = 0, fit_SPR, min_diff = ~0, diff;
    uint32 tmp;

    //���㲨���� BaudRate �����¹�ϵ��
    //��Ƶϵ����BusClock/ BaudRate =(SPPR + 1) * ( 1<<(SPR + 1) )
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
                //��ס �������
                min_diff = diff;
                fit_SPR = SPR;
                fit_SPPR = SPPR;

                if(min_diff == 0)
                {
                    //�պ�ƥ��

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
 *  @brief      SPI��ʼ��������ģʽ
 *  @param      SPIn_e          SPIģ��(SPI0��SPI1��SPI2)
 *  @param      SPIn_PCSn_e     Ƭѡ�ܽű��
 *  @param      SPI_CFG         SPI���ӻ�ģʽѡ��
 *  @since      v5.0
 *  Sample usage:       uint32 baud = spi_init(SPI0,SPIn_PCS0, MASTER,10*1000*1000);              //��ʼ��SPI,ѡ��CS0,����ģʽ, ������Ϊ1M ,������ʵ�����ʵ�baud����
 */
uint32 spi_init(SPIn_e spin, PTXn_e pcs, SPI_CFG cfg, uint32 baud, uint32 bus_khz, char use_pin_mode)
{





    //ʹ��SPIģ��ʱ�ӣ�����SPI���Ź���
    if(spin == SPI0)
    {
        SIM_SCGC |= SIM_SCGC_SPI0_MASK;

        //���йܽŸ���
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
        //���ݽ����� spi ģ������ֱ���ж϶���ʧ��
        ASSERT(0);

        return 0;
    }

    if(cfg & MASTER)
    {
        SPI_C1_REG(spin) = ( 0
                             | SPI_C1_SPE_MASK   //SPI ʹ��
                             | cfg
                             | SPI_C1_SSOE_MASK  // �� C2[MODFEN] ��ͬȷ�Ϲ��ܡ�������1��Ȼ�� C2[MODFEN] Ϊ1 ���Զ����PCS��Ϊ0��ͨ��IO��
                           );

        SPI_C2_REG(spin) = ( 0
                             //| SPI_C2_MODFEN_MASK    //1 Ϊ�Զ�PCS ��0Ϊ ͨ��IO
                           );

        baud = spi_set_baud(spin, baud, bus_khz) ;

        gpio_init(pcs, GPO, 1);
    }
    else
    {
        //�ݲ�֧�ִӻ�ģʽ
        ASSERT(0);

        return 0;
    }



    return  baud;

}

/*!
 *  @brief      SPI���ͽ��պ���
 *  @param      SPIn_e          SPIģ��(SPI0��SPI1��SPI2)
 *  @param      SPIn_PCSn_e     Ƭѡ�ܽű��
 *  @param      modata          ���͵����ݻ�������ַ(����Ҫ������ NULL)
 *  @param      midata          ��������ʱ���յ������ݵĴ洢��ַ(����Ҫ������ NULL)
 *  @since      v5.0
 *  Sample usage:           spi_mosi(SPI0,SPIn_PCS0,buff,buff,2);    //����buff�����ݣ������յ�buff�����Ϊ2�ֽ�
 */
void spi_mosi(SPIn_e spin, PTXn_e pcs, uint8 *modata, uint8 *midata, uint32 len)
{
    uint32 i = 0;

    gpio_set(pcs, 0);
    /***************** ����len������ *******************/                                                ;
    for(i = 0; i < len; i++)
    {

        while(!(SPI_S_REG(spin) & SPI_S_SPTEF_MASK));        //�ȴ�����Ϊ��
        if(modata != NULL)
        {
            SPI_D_REG(spin) = modata[i];
        }
        else
        {
            SPI_D_REG(spin) = 0xFF;
        }

        while(!(SPI_S_REG(spin) & SPI_S_SPRF_MASK));        //�ȴ��������
        if(midata != NULL)
        {
            midata[i] = (uint8)SPI_D_REG(spin);                  //������յ�������
        }
        else
        {
            SPI_D_REG(spin);
        }

    }
    gpio_set(pcs, 1);
}

/*!
 *  @brief      SPI���ͽ��պ���
 *  @param      SPIn_e          SPIģ��(SPI0��SPI1��SPI2)
 *  @param      SPIn_PCSn_e     Ƭѡ�ܽű��
 *  @param      mocmd           ���͵����������ַ(����Ҫ������ NULL)
 *  @param      micmd           ��������ʱ���յ������ݵĴ洢��ַ(����Ҫ������ NULL)
 *  @param      modata          ���͵����ݻ�������ַ(����Ҫ������ NULL)
 *  @param      midata          ��������ʱ���յ������ݵĴ洢��ַ(����Ҫ������ NULL)
 *  @since      v5.0
 *  Sample usage:           spi_mosi_cmd(SPI0,SPIn_PCS0,cmd,NULL,buff,buff,1,2);    //����cmd/buff�����ݣ�������cmd����ʱ�����ݣ�����buff����ʱ�����ݵ�buff����ȷֱ�Ϊ1��2�ֽ�
 */
void spi_mosi_cmd(SPIn_e spin, PTXn_e pcs, uint8 *mocmd , uint8 *micmd , uint8 *modata , uint8 *midata, uint32 cmdlen , uint32 len)
{
    uint32 i = 0;

    gpio_set(pcs, 0);
    /***************** ���� cmdlen ������ *******************/                                                ;
    for(i = 0; i < cmdlen; i++)
    {

        while(!(SPI_S_REG(spin) & SPI_S_SPTEF_MASK));        //�ȴ�����Ϊ��
        if(mocmd != NULL)
        {
            SPI_D_REG(spin) = mocmd[i];
        }
        else
        {
            SPI_D_REG(spin) = 0xFF;
        }

        while(!(SPI_S_REG(spin) & SPI_S_SPRF_MASK));        //�ȴ��������
        if(micmd != NULL)
        {
            micmd[i] = (uint8)SPI_D_REG(spin);                  //������յ�������
        }
        else
        {
            SPI_D_REG(spin);
        }

    }

    /***************** ����len������ *******************/                                                ;
    for(i = 0; i < len; i++)
    {

        while(!(SPI_S_REG(spin) & SPI_S_SPTEF_MASK));        //�ȴ�����Ϊ��
        if(modata != NULL)
        {
            SPI_D_REG(spin) = modata[i];
        }
        else
        {
            SPI_D_REG(spin) = 0xFF;
        }

        while(!(SPI_S_REG(spin) & SPI_S_SPRF_MASK));        //�ȴ��������
        if(midata != NULL)
        {
            midata[i] = (uint8)SPI_D_REG(spin);                  //������յ�������
        }
        else
        {
            SPI_D_REG(spin);
        }

    }
    gpio_set(pcs, 1);

}


