/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_port.c
 * @brief      port�������ú͸��ֹ�������
 * @author     ɽ��Ƽ�
 * @version    v5.1
 * @date       2014-04-25
 */

#include "common.h"
#include "KEA_port.h"

//����ʹ��
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

//���������
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