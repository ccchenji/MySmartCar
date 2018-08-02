/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_uart.c
 * @brief      uart串口函数
 * @author     山外科技
 * @version    v5.2
 * @date       2014-10-09
 */


#include "common.h"
#include "KEA_uart.h"
#include "KEA_port.h"

UART_MemMapPtr UARTN[UART_MAX] = UART_BASE_PTRS; //定义五个指针数组保存 UARTN 的地址


/*!
 *  @brief      初始化串口，设置波特率
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      baud        波特率，如9600、19200、56000、115200等
 *  @since      v5.0
 *  @note       UART所用的管脚在 App\Inc\PORT_cfg.h 里进行配置，
                printf所用的管脚和波特率在 App\Inc\MK60_conf.h 里进行配置
 *  Sample usage:       uart_init (UART3, 9600);        //初始化串口3，波特率为9600
 */
void uart_init (UARTn_e uratn, uint32 baud)
{
    register uint16 sbr;
    uint8 temp;
    uint32 sysclk;     //时钟

    /* 配置 UART功能的 复用管脚 */
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

        SIM_SCGC |= SIM_SCGC_UART0_MASK;      //使能 UART0 时钟
        break;

    case (uint32_t)UART1:
#if (USE_UART1_MODE == 0)
        BIT_CLEAN(SIM_PINSEL1, SIM_PINSEL1_UART1PS_SHIFT) ;
#elif (USE_UART1_MODE == 1)
        BIT_SET(SIM_PINSEL1, SIM_PINSEL1_UART1PS_SHIFT) ;
#endif

        SIM_SCGC |= SIM_SCGC_UART1_MASK;      //使能 UART1 时钟
        break;


    case (uint32_t)UART2:
#if (USE_UART2_MODE == 0)
        BIT_CLEAN(SIM_PINSEL1, SIM_PINSEL1_UART2PS_SHIFT) ;
#elif (USE_UART2_MODE == 1)
        BIT_SET(SIM_PINSEL1, SIM_PINSEL1_UART2PS_SHIFT) ;
#endif

        SIM_SCGC |= SIM_SCGC_UART2_MASK;      //使能 UART2 时钟
        break;

    default:
        return;

    }

    //设置的时候，应该禁止发送接收
    uratn->C2 &= ~(0
                   | UART_C2_TE_MASK
                   | UART_C2_RE_MASK
                  );


    //配置成8位无校验模式
    //设置 UART 数据格式、校验方式和停止位位数。通过设置 UART 模块控制寄存器 C1 实现；
    uratn->C1 = (0
                 //| UART_C1_M_MASK                    //9 位或 8 位模式选择 : 0 为 8位 ，1 为 9位（注释了表示0，即8位） （如果是9位，位8在UARTx_C3里）
                 //| UART_C1_PE_MASK                   //奇偶校验使能（注释了表示禁用）
                 //| UART_C1_PT_MASK                   //校验位类型 : 0 为 偶校验 ，1 为 奇校验
                );

    //计算波特率
    sysclk = bus_clk_khz * 1000;                                    //bus时钟

    //UART 波特率 = UART 模块时钟 / (16 × (SBR[12:0] ))
    sbr = (uint16)((sysclk / 16 + baud / 2 ) / (baud ));                 //  baud/2  的作用是没微调寄存器，误差较大，只能四舍五入取最接近的
    if(sbr > 0x1FFF)sbr = 0x1FFF;                                       //SBR 是 13bit，最大为 0x1FFF


    //写 SBR
    temp = uratn->BDH  & (~UART_BDH_SBR_MASK);           //缓存 清空 SBR 的 UARTx_BDH的值
    uratn->BDH = temp |  UART_BDH_SBR(sbr >> 8) /*| UART_BDH_SBNS_MASK*/;        //先写入SBR高位
    uratn->BDL = UART_BDL_SBR(sbr);                     //再写入SBR低位


    /* 允许发送和接收 */
    uratn->C2 |= (0
                  | UART_C2_TE_MASK                     //发送使能
                  | UART_C2_RE_MASK                     //接收使能
                  //| UART_C2_TIE_MASK                  //发送中断或DMA传输请求使能（注释了表示禁用）
                  //| UART_C2_TCIE_MASK                 //发送完成中断使能（注释了表示禁用）
                  //| UART_C2_RIE_MASK                  //接收满中断或DMA传输请求使能（注释了表示禁用）
                 );

    //设置是否允许接收和发送中断。通过设置 UART 模块的 C2 寄存器的
    //RIE 和 TIE 位实现。如果使能中断，必须首先实现中断服务程序；
}

/*!
 *  @brief      等待接受1个字节
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      ch          接收地址
 *  @since      v5.0
 *  @note       如果需要查询接收状态，可用 uart_query ，
                如果需要查询接收数据，可用 uart_querychar
 *  Sample usage:
                        char ch;
                        uart_getchar (UART3,&ch);   //等待接受1个字节，保存到 ch里
 */
void uart_getchar (UARTn_e uratn, char *ch)
{
    while (!(uratn->S1 & UART_S1_RDRF_MASK));       //等待接收满了

    // 获取接收到的8位数据
    *ch =  uratn->D;

    // 获取 9位数据，应该是（需要修改函数的返回类型）：
    // *ch =   ((( UARTx_C3_REG(UARTN[uratn]) & UART_C3_R8_MASK ) >> UART_C3_R8_SHIFT ) << 8)   |   UART_D_REG(UARTN[uratn]);  //返回9bit

}


/*!
 *  @brief      查询接收1个字符
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      ch          接收地址
 *  @return     1为接收成功，0为接收失败
 *  @since      v5.0
 *  @note       如果需要等待接收，可用 uart_getchar
 *  Sample usage:       char ch ;
                        if( uart_querychar (UART3,&ch) == 1)     //查询接收1个字符，保存到 ch里
                        {
                            printf("成功接收到一个字节");
                        }
 */
char uart_querychar (UARTn_e uratn, char *ch)
{
    if(uratn->S1 & UART_S1_RDRF_MASK )         //查询是否接受到数据
    {
        *ch  =   uratn->D;      //接受到8位的数据
        return  1;                              //返回 1 表示接收成功
    }

    *ch = 0;                                    //接收不到，应该清空了接收区
    return 0;                                   //返回0表示接收失败
}

/*!
 *  @brief      查询接收字符串
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      str         接收地址
 *  @param      max_len     最大接收长度
 *  @return     接收到的字节数目
 *  @since      v5.0
 *  Sample usage:       char str[100];
                        uint32 num;
                        num = uart_querystr (UART3,&str,100);
                        if( num != 0 )
                        {
                            printf("成功接收到%d个字节:%s",num,str);
                        }
 */
uint32 uart_querystr (UARTn_e uratn, char *str, uint32 max_len)
{
    uint32 i = 0, j;

    for(j = 0; j < 10000; j++)           // 10000 的作用是延时，可自行根据情况修改
    {
        while(uart_querychar(uratn, str + i)  )
        {
            j = 0;
            if( *(str + i) == NULL )    //接收到字符串结束符
            {
                return i;
            }

            i++;
            if(i >= max_len)            //超过设定的最大值，退出
            {
                *(str + i) = 0;     //确保字符串结尾是0x00
                return i;
            }
        }
    }

    *(str + i) = 0;                     //确保字符串结尾是0x00
    return i;
}


/*!
 *  @brief      查询接收buff
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      str         接收地址
 *  @param      max_len     最大接收长度
 *  @return     接收到的字节数目
 *  @since      v5.0
 *  Sample usage:       char buff[100];
                        uint32 num;
                        num = uart_querybuff (UART3,&buff,100);
                        if( num != 0 )
                        {
                            printf("成功接收到%d个字节:%s",num,buff);
                        }
 */
uint32 uart_querybuff (UARTn_e uratn, char *buff, uint32 max_len)
{
    uint32 i = 0, j;
    for(j = 0; j < 10000; j++)           // 10000 的作用是延时，可自行根据情况修改
    {
        while(uart_querychar(uratn, buff + i)  )
        {
            i++;
            if(i >= max_len)            //超过设定的最大值，退出
            {
                return i;
            }
        }
    }

    return i;
}


/*!
 *  @brief      串口发送一个字节
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      ch          需要发送的字节
 *  @since      v5.0
 *  @note       printf需要用到此函数
 *  @see        fputc
 *  Sample usage:       uart_putchar (UART3, 'A');  //发送字节'A'
 */
void uart_putchar (UARTn_e uratn, char ch)
{
    //等待发送缓冲区空
    while(!(uratn->S1 & UART_S1_TDRE_MASK));

    //发送数据
    uratn->D = (uint8)ch;
}

/*!
 *  @brief      查询是否接受到一个字节
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @return     接收到数据返回1，没接收到数据返回0
 *  @since      v5.0
 *  Sample usage:       char ch;
                        if(uart_query (UART3) == 1)     //查询是否接收到数据
                        {
                            ch = uart_getchar (UART3);  //等待接收一个数据，保存到 ch里
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
 *  @brief      发送指定len个字节长度数组 （包括 NULL 也会发送）
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      buff        数组地址
 *  @param      len         发送数组的长度
 *  @since      v5.0
 *  Sample usage:       uart_putbuff (UART3,"1234567", 3); //实际发送了3个字节'1','2','3'
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
 *  @brief      发送字符串(遇 NULL 停止发送)
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @param      str         字符串地址
 *  @since      v5.0
 *  Sample usage:       uart_putstr (UART3,"1234567"); //实际发送了7个字节
 */
void uart_putstr (UARTn_e uratn, const uint8 *str)
{
    while(*str)
    {
        uart_putchar(uratn, *str++);
    }
}

/*!
 *  @brief      开串口接收中断
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_en(UART3);         //开串口3接收中断
 */
void uart_rx_irq_en(UARTn_e uratn)
{
    uratn->C2 |= UART_C2_RIE_MASK;                          //使能UART接收中断
    if(uratn == UART0)
    {
        enable_irq(UART0_IRQn);                  //使能IRQ中断
    }
    else if(uratn == UART1)
    {
        enable_irq(UART1_IRQn);                  //使能IRQ中断
    }
    else if(uratn == UART2)
    {
        enable_irq(UART2_IRQn);                  //使能IRQ中断
    }
}

/*!
 *  @brief      开串口发送中断
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART3);         //开串口3发送中断
 */
void uart_tx_irq_en(UARTn_e uratn)
{
    uratn->C2  |= UART_C2_TIE_MASK;                          //使能UART发送中断
    if(uratn == UART0)
    {
        enable_irq(UART0_IRQn);                  //使能IRQ中断
    }
    else if(uratn == UART1)
    {
        enable_irq(UART1_IRQn);                  //使能IRQ中断
    }
    else if(uratn == UART2)
    {
        enable_irq(UART2_IRQn);                  //使能IRQ中断
    }
}

/*!
 *  @brief      开串口发送完成中断
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART3);         //开串口3发送中断
 */
void uart_txc_irq_en(UARTn_e uratn)
{
    uratn->C2 |= UART_C2_TCIE_MASK;                         //使能UART发送中断
    if(uratn == UART0)
    {
        enable_irq(UART0_IRQn);                  //使能IRQ中断
    }
    else if(uratn == UART1)
    {
        enable_irq(UART1_IRQn);                  //使能IRQ中断
    }
    else if(uratn == UART2)
    {
        enable_irq(UART2_IRQn);                  //使能IRQ中断
    }
}

/*!
 *  @brief      关串口接收中断
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_dis(UART3);         //关串口3接收中断
 */
void uart_rx_irq_dis(UARTn_e uratn)
{
    uratn->C2 &= ~UART_C2_RIE_MASK;                         //禁止UART接收中断

    //如果发送中断还没有关，则不关闭IRQ
    if(!(uratn->C2 & (UART_C2_TIE_MASK | UART_C2_TCIE_MASK)) )
    {
        if(uratn == UART0)
        {
            disable_irq(UART0_IRQn);                  //使能IRQ中断
        }
        else if(uratn == UART1)
        {
            disable_irq(UART1_IRQn);                  //使能IRQ中断
        }
        else if(uratn == UART2)
        {
            disable_irq(UART2_IRQn);                  //使能IRQ中断
        }
    }
}

/*!
 *  @brief      关串口发送中断
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART3);         //关串口3发送中断
 */
void uart_txc_irq_dis(UARTn_e uratn)
{
    uratn->C2 &= ~UART_C2_TCIE_MASK;                        //禁止UART发送完成中断

    //如果接收中断还没有关，则不关闭IRQ
    if(!(uratn->C2 & UART_C2_RIE_MASK) )
    {
        if(uratn == UART0)
        {
            disable_irq(UART0_IRQn);                  //使能IRQ中断
        }
        else if(uratn == UART1)
        {
            disable_irq(UART1_IRQn);                  //使能IRQ中断
        }
        else if(uratn == UART2)
        {
            disable_irq(UART2_IRQn);                  //使能IRQ中断
        }
    }
}

/*!
 *  @brief      关串口发送中断
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART3);         //关串口3发送中断
 */
void uart_tx_irq_dis(UARTn_e uratn)
{
    uratn->C2 &= ~UART_C2_TIE_MASK;                         //禁止UART发送中断

    //如果接收中断还没有关，则不关闭IRQ
    if(!(uratn->C2 & UART_C2_RIE_MASK) )
    {
        if(uratn == UART0)
        {
            disable_irq(UART0_IRQn);                  //使能IRQ中断
        }
        else if(uratn == UART1)
        {
            disable_irq(UART1_IRQn);                  //使能IRQ中断
        }
        else if(uratn == UART2)
        {
            disable_irq(UART2_IRQn);                  //使能IRQ中断
        }
    }
}

/*!
 *  @brief      UART3测试中断服务函数
 *  @since      v5.0
 *  @warning    此函数需要用户根据自己需求完成，这里仅仅是提供一个模版
 *  Sample usage:       set_vector_handler(UART3_RX_TX_VECTORn , uart3_test_handler);    //把 uart3_handler 函数添加到中断向量表，不需要我们手动调用
 */
void uart0_test_handler(void)
{
    UARTn_e uratn = UART0;

    if(uratn->S1 & UART_S1_RDRF_MASK)   //接收数据寄存器满
    {
        //用户需要处理接收数据

    }

    if(uratn->S1  & UART_S1_TDRE_MASK )  //发送数据寄存器空
    {
        //用户需要处理发送数据

    }
}