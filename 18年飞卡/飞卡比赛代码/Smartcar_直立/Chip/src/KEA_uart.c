/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_uart.c
 * @brief      uart���ں���
 * @author     ɽ��Ƽ�
 * @version    v5.2
 * @date       2014-10-09
 */


#include "common.h"
#include "KEA_uart.h"
#include "KEA_port.h"

UART_MemMapPtr UARTN[UART_MAX] = UART_BASE_PTRS; //�������ָ�����鱣�� UARTN �ĵ�ַ


/*!
 *  @brief      ��ʼ�����ڣ����ò�����
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      baud        �����ʣ���9600��19200��56000��115200��
 *  @since      v5.0
 *  @note       UART���õĹܽ��� App\Inc\PORT_cfg.h ��������ã�
                printf���õĹܽźͲ������� App\Inc\MK60_conf.h ���������
 *  Sample usage:       uart_init (UART3, 9600);        //��ʼ������3��������Ϊ9600
 */
void uart_init (UARTn_e uratn, uint32 baud)
{
    register uint16 sbr;
    uint8 temp;
    uint32 sysclk;     //ʱ��

    /* ���� UART���ܵ� ���ùܽ� */
    switch((uint32_t)uratn)
    {
    case (uint32_t)UART0:

#if (USE_UART0_MODE == 0)
        BIT_CLEAN(SIM_PINSEL0, SIM_PINSEL_UART0PS_SHIFT) ;
#elif (USE_UART0_MODE == 1)
        port_pull(PTA3, ENABLE);
        port_pull(PTA2, ENABLE);
        BIT_SET(SIM_PINSEL0, SIM_PINSEL_UART0PS_SHIFT) ;
#endif

        SIM_SCGC |= SIM_SCGC_UART0_MASK;      //ʹ�� UART0 ʱ��
        break;

    case (uint32_t)UART1:
#if (USE_UART1_MODE == 0)
        BIT_CLEAN(SIM_PINSEL1, SIM_PINSEL1_UART1PS_SHIFT) ;
#elif (USE_UART1_MODE == 1)
        BIT_SET(SIM_PINSEL1, SIM_PINSEL1_UART1PS_SHIFT) ;
#endif

        SIM_SCGC |= SIM_SCGC_UART1_MASK;      //ʹ�� UART1 ʱ��
        break;


    case (uint32_t)UART2:
#if (USE_UART2_MODE == 0)
        BIT_CLEAN(SIM_PINSEL1, SIM_PINSEL1_UART2PS_SHIFT) ;
#elif (USE_UART2_MODE == 1)
        BIT_SET(SIM_PINSEL1, SIM_PINSEL1_UART2PS_SHIFT) ;
#endif

        SIM_SCGC |= SIM_SCGC_UART2_MASK;      //ʹ�� UART2 ʱ��
        break;

    default:
        return;

    }

    //���õ�ʱ��Ӧ�ý�ֹ���ͽ���
    uratn->C2 &= ~(0
                   | UART_C2_TE_MASK
                   | UART_C2_RE_MASK
                  );


    //���ó�8λ��У��ģʽ
    //���� UART ���ݸ�ʽ��У�鷽ʽ��ֹͣλλ����ͨ������ UART ģ����ƼĴ��� C1 ʵ�֣�
    uratn->C1 = (0
                 //| UART_C1_M_MASK                    //9 λ�� 8 λģʽѡ�� : 0 Ϊ 8λ ��1 Ϊ 9λ��ע���˱�ʾ0����8λ�� �������9λ��λ8��UARTx_C3�
                 //| UART_C1_PE_MASK                   //��żУ��ʹ�ܣ�ע���˱�ʾ���ã�
                 //| UART_C1_PT_MASK                   //У��λ���� : 0 Ϊ żУ�� ��1 Ϊ ��У��
                );

    //���㲨����
    sysclk = bus_clk_khz * 1000;                                    //busʱ��

    //UART ������ = UART ģ��ʱ�� / (16 �� (SBR[12:0] ))
    sbr = (uint16)((sysclk / 16 + baud / 2 ) / (baud ));                 //  baud/2  ��������û΢���Ĵ��������ϴ�ֻ����������ȡ��ӽ���
    if(sbr > 0x1FFF)sbr = 0x1FFF;                                       //SBR �� 13bit�����Ϊ 0x1FFF


    //д SBR
    temp = uratn->BDH  & (~UART_BDH_SBR_MASK);           //���� ��� SBR �� UARTx_BDH��ֵ
    uratn->BDH = temp |  UART_BDH_SBR(sbr >> 8) /*| UART_BDH_SBNS_MASK*/;        //��д��SBR��λ
    uratn->BDL = UART_BDL_SBR(sbr);                     //��д��SBR��λ


    /* �����ͺͽ��� */
    uratn->C2 |= (0
                  | UART_C2_TE_MASK                     //����ʹ��
                  | UART_C2_RE_MASK                     //����ʹ��
                  //| UART_C2_TIE_MASK                  //�����жϻ�DMA��������ʹ�ܣ�ע���˱�ʾ���ã�
                  //| UART_C2_TCIE_MASK                 //��������ж�ʹ�ܣ�ע���˱�ʾ���ã�
                  //| UART_C2_RIE_MASK                  //�������жϻ�DMA��������ʹ�ܣ�ע���˱�ʾ���ã�
                 );

    //�����Ƿ�������պͷ����жϡ�ͨ������ UART ģ��� C2 �Ĵ�����
    //RIE �� TIE λʵ�֡����ʹ���жϣ���������ʵ���жϷ������
}

/*!
 *  @brief      �ȴ�����1���ֽ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      ch          ���յ�ַ
 *  @since      v5.0
 *  @note       �����Ҫ��ѯ����״̬������ uart_query ��
                �����Ҫ��ѯ�������ݣ����� uart_querychar
 *  Sample usage:
                        char ch;
                        uart_getchar (UART3,&ch);   //�ȴ�����1���ֽڣ����浽 ch��
 */
void uart_getchar (UARTn_e uratn, char *ch)
{
    while (!(uratn->S1 & UART_S1_RDRF_MASK));       //�ȴ���������

    // ��ȡ���յ���8λ����
    *ch =  uratn->D;

    // ��ȡ 9λ���ݣ�Ӧ���ǣ���Ҫ�޸ĺ����ķ������ͣ���
    // *ch =   ((( UARTx_C3_REG(UARTN[uratn]) & UART_C3_R8_MASK ) >> UART_C3_R8_SHIFT ) << 8)   |   UART_D_REG(UARTN[uratn]);  //����9bit

}


/*!
 *  @brief      ��ѯ����1���ַ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      ch          ���յ�ַ
 *  @return     1Ϊ���ճɹ���0Ϊ����ʧ��
 *  @since      v5.0
 *  @note       �����Ҫ�ȴ����գ����� uart_getchar
 *  Sample usage:       char ch ;
                        if( uart_querychar (UART3,&ch) == 1)     //��ѯ����1���ַ������浽 ch��
                        {
                            printf("�ɹ����յ�һ���ֽ�");
                        }
 */
char uart_querychar (UARTn_e uratn, char *ch)
{
    if(uratn->S1 & UART_S1_RDRF_MASK )         //��ѯ�Ƿ���ܵ�����
    {
        *ch  =   uratn->D;      //���ܵ�8λ������
        return  1;                              //���� 1 ��ʾ���ճɹ�
    }

    *ch = 0;                                    //���ղ�����Ӧ������˽�����
    return 0;                                   //����0��ʾ����ʧ��
}

/*!
 *  @brief      ��ѯ�����ַ���
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      str         ���յ�ַ
 *  @param      max_len     �����ճ���
 *  @return     ���յ����ֽ���Ŀ
 *  @since      v5.0
 *  Sample usage:       char str[100];
                        uint32 num;
                        num = uart_querystr (UART3,&str,100);
                        if( num != 0 )
                        {
                            printf("�ɹ����յ�%d���ֽ�:%s",num,str);
                        }
 */
uint32 uart_querystr (UARTn_e uratn, char *str, uint32 max_len)
{
    uint32 i = 0, j;

    for(j = 0; j < 10000; j++)           // 10000 ����������ʱ�������и�������޸�
    {
        while(uart_querychar(uratn, str + i)  )
        {
            j = 0;
            if( *(str + i) == NULL )    //���յ��ַ���������
            {
                return i;
            }

            i++;
            if(i >= max_len)            //�����趨�����ֵ���˳�
            {
                *(str + i) = 0;     //ȷ���ַ�����β��0x00
                return i;
            }
        }
    }

    *(str + i) = 0;                     //ȷ���ַ�����β��0x00
    return i;
}


/*!
 *  @brief      ��ѯ����buff
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      str         ���յ�ַ
 *  @param      max_len     �����ճ���
 *  @return     ���յ����ֽ���Ŀ
 *  @since      v5.0
 *  Sample usage:       char buff[100];
                        uint32 num;
                        num = uart_querybuff (UART3,&buff,100);
                        if( num != 0 )
                        {
                            printf("�ɹ����յ�%d���ֽ�:%s",num,buff);
                        }
 */
uint32 uart_querybuff (UARTn_e uratn, char *buff, uint32 max_len)
{
    uint32 i = 0, j;
    for(j = 0; j < 10000; j++)           // 10000 ����������ʱ�������и�������޸�
    {
        while(uart_querychar(uratn, buff + i)  )
        {
            i++;
            if(i >= max_len)            //�����趨�����ֵ���˳�
            {
                return i;
            }
        }
    }

    return i;
}


/*!
 *  @brief      ���ڷ���һ���ֽ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      ch          ��Ҫ���͵��ֽ�
 *  @since      v5.0
 *  @note       printf��Ҫ�õ��˺���
 *  @see        fputc
 *  Sample usage:       uart_putchar (UART3, 'A');  //�����ֽ�'A'
 */
void uart_putchar (UARTn_e uratn, char ch)
{
    //�ȴ����ͻ�������
    while(!(uratn->S1 & UART_S1_TDRE_MASK));

    //��������
    uratn->D = (uint8)ch;
}

/*!
 *  @brief      ��ѯ�Ƿ���ܵ�һ���ֽ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @return     ���յ����ݷ���1��û���յ����ݷ���0
 *  @since      v5.0
 *  Sample usage:       char ch;
                        if(uart_query (UART3) == 1)     //��ѯ�Ƿ���յ�����
                        {
                            ch = uart_getchar (UART3);  //�ȴ�����һ�����ݣ����浽 ch��
                        }
 */
char uart_query (UARTn_e uratn)
{
    if(uratn->S1 & UART_S1_RDRF_MASK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    //return UART_RCFIFO_REG(UARTN[uratn]);
}

/*!
 *  @brief      ����ָ��len���ֽڳ������� ������ NULL Ҳ�ᷢ�ͣ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      buff        �����ַ
 *  @param      len         ��������ĳ���
 *  @since      v5.0
 *  Sample usage:       uart_putbuff (UART3,"1234567", 3); //ʵ�ʷ�����3���ֽ�'1','2','3'
 */
void uart_putbuff (UARTn_e uratn, uint8 *buff, uint32 len)
{
    while(len--)
    {
        uart_putchar(uratn, *buff);
        buff++;
    }
}


/*!
 *  @brief      �����ַ���(�� NULL ֹͣ����)
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @param      str         �ַ�����ַ
 *  @since      v5.0
 *  Sample usage:       uart_putstr (UART3,"1234567"); //ʵ�ʷ�����7���ֽ�
 */
void uart_putstr (UARTn_e uratn, const uint8 *str)
{
    while(*str)
    {
        uart_putchar(uratn, *str++);
    }
}

/*!
 *  @brief      �����ڽ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_en(UART3);         //������3�����ж�
 */
void uart_rx_irq_en(UARTn_e uratn)
{
    uratn->C2 |= UART_C2_RIE_MASK;                          //ʹ��UART�����ж�
    if(uratn == UART0)
    {
        enable_irq(UART0_IRQn);                  //ʹ��IRQ�ж�
    }
    else if(uratn == UART1)
    {
        enable_irq(UART1_IRQn);                  //ʹ��IRQ�ж�
    }
    else if(uratn == UART2)
    {
        enable_irq(UART2_IRQn);                  //ʹ��IRQ�ж�
    }
}

/*!
 *  @brief      �����ڷ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART3);         //������3�����ж�
 */
void uart_tx_irq_en(UARTn_e uratn)
{
    uratn->C2  |= UART_C2_TIE_MASK;                          //ʹ��UART�����ж�
    if(uratn == UART0)
    {
        enable_irq(UART0_IRQn);                  //ʹ��IRQ�ж�
    }
    else if(uratn == UART1)
    {
        enable_irq(UART1_IRQn);                  //ʹ��IRQ�ж�
    }
    else if(uratn == UART2)
    {
        enable_irq(UART2_IRQn);                  //ʹ��IRQ�ж�
    }
}

/*!
 *  @brief      �����ڷ�������ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART3);         //������3�����ж�
 */
void uart_txc_irq_en(UARTn_e uratn)
{
    uratn->C2 |= UART_C2_TCIE_MASK;                         //ʹ��UART�����ж�
    if(uratn == UART0)
    {
        enable_irq(UART0_IRQn);                  //ʹ��IRQ�ж�
    }
    else if(uratn == UART1)
    {
        enable_irq(UART1_IRQn);                  //ʹ��IRQ�ж�
    }
    else if(uratn == UART2)
    {
        enable_irq(UART2_IRQn);                  //ʹ��IRQ�ж�
    }
}

/*!
 *  @brief      �ش��ڽ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_dis(UART3);         //�ش���3�����ж�
 */
void uart_rx_irq_dis(UARTn_e uratn)
{
    uratn->C2 &= ~UART_C2_RIE_MASK;                         //��ֹUART�����ж�

    //��������жϻ�û�йأ��򲻹ر�IRQ
    if(!(uratn->C2 & (UART_C2_TIE_MASK | UART_C2_TCIE_MASK)) )
    {
        if(uratn == UART0)
        {
            disable_irq(UART0_IRQn);                  //ʹ��IRQ�ж�
        }
        else if(uratn == UART1)
        {
            disable_irq(UART1_IRQn);                  //ʹ��IRQ�ж�
        }
        else if(uratn == UART2)
        {
            disable_irq(UART2_IRQn);                  //ʹ��IRQ�ж�
        }
    }
}

/*!
 *  @brief      �ش��ڷ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART3);         //�ش���3�����ж�
 */
void uart_txc_irq_dis(UARTn_e uratn)
{
    uratn->C2 &= ~UART_C2_TCIE_MASK;                        //��ֹUART��������ж�

    //��������жϻ�û�йأ��򲻹ر�IRQ
    if(!(uratn->C2 & UART_C2_RIE_MASK) )
    {
        if(uratn == UART0)
        {
            disable_irq(UART0_IRQn);                  //ʹ��IRQ�ж�
        }
        else if(uratn == UART1)
        {
            disable_irq(UART1_IRQn);                  //ʹ��IRQ�ж�
        }
        else if(uratn == UART2)
        {
            disable_irq(UART2_IRQn);                  //ʹ��IRQ�ж�
        }
    }
}

/*!
 *  @brief      �ش��ڷ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART3);         //�ش���3�����ж�
 */
void uart_tx_irq_dis(UARTn_e uratn)
{
    uratn->C2 &= ~UART_C2_TIE_MASK;                         //��ֹUART�����ж�

    //��������жϻ�û�йأ��򲻹ر�IRQ
    if(!(uratn->C2 & UART_C2_RIE_MASK) )
    {
        if(uratn == UART0)
        {
            disable_irq(UART0_IRQn);                  //ʹ��IRQ�ж�
        }
        else if(uratn == UART1)
        {
            disable_irq(UART1_IRQn);                  //ʹ��IRQ�ж�
        }
        else if(uratn == UART2)
        {
            disable_irq(UART2_IRQn);                  //ʹ��IRQ�ж�
        }
    }
}

/*!
 *  @brief      UART3�����жϷ�����
 *  @since      v5.0
 *  @warning    �˺�����Ҫ�û������Լ�������ɣ�����������ṩһ��ģ��
 *  Sample usage:       set_vector_handler(UART3_RX_TX_VECTORn , uart3_test_handler);    //�� uart3_handler ������ӵ��ж�����������Ҫ�����ֶ�����
 */
void uart0_test_handler(void)
{
    UARTn_e uratn = UART0;

    if(uratn->S1 & UART_S1_RDRF_MASK)   //�������ݼĴ�����
    {
        //�û���Ҫ�����������

    }

    if(uratn->S1  & UART_S1_TDRE_MASK )  //�������ݼĴ�����
    {
        //�û���Ҫ����������

    }
}