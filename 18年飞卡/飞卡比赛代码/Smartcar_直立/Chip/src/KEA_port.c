/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_port.c
 * @brief      port复用配置和各种功能配置
 * @author     山外科技
 * @version    v5.1
 * @date       2014-04-25
 */

#include "common.h"
#include "KEA_port.h"

//上拉使能
void port_pull(PTXn_e ptxn, char  cfg)
{
    uint32_t volatile *port_pue[] = {&PORT_PUE0, &PORT_PUE1, &PORT_PUE2};

    if(DISABLE  == cfg)
    {
        *port_pue[GPX(ptxn)] &= ~(1 << GPn(ptxn));
    }
    else if(ENABLE  == cfg)
    {
        *port_pue[GPX(ptxn)] |= (1 << GPn(ptxn));
    }

}

//大电流驱动
char port_hdrve(PTXn_e ptxn, char  cfg)
{
    char ptxns[] = {PTB4, PTB5, PTD0 , PTD1, PTE0 , PTE1 , PTH0 , PTH1};

    char i = 0;

    for(i = 0; i < sizeof(ptxns); i++)
    {
        if(ptxns[i] == ptxn)
        {
            if(DISABLE  == cfg)
            {
                PORT_HDRVE &= ~(1 << i);
            }
            else
            {
                PORT_HDRVE |= (1 << i);
            }
            return TRUE;
        }

    }

    return FALSE;


}