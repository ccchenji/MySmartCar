/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       system_MK66FX18.c
 * @brief      ϵͳ������غ���
 * @author     ɽ��Ƽ�
 * @version    v5.2
 * @date       2014-10-09
 */

#include "common.h"
#include "system_SKEAZ1284.h"
#include "MKEA128_conf.h"
#include "KEA_gpio.h"
#include "KEA_uart.h"
#include "KEA_wdog.h"

int core_clk_khz;
int core_clk_mhz;
int bus_clk_khz;
int timer_clk_khz;

extern void main(void);

/*!
 *  @brief      kinetis ��������
 *  @since      v5.0
 *  @author     ��˼������˾
 *  @note       �˺�����ϵͳ���������ɻ�ຯ�����ã�Ȼ��ִ��main����
 */
void start(void)
{

    wdog_disable();     // �رտ��Ź�


    common_startup();   // �����ж������� �� ��Ҫ�����ݵ� RAM��



    sysinit();          // ϵͳ��ʼ��������ϵͳƵ�ʣ���ʼ��printf�˿�




    main();             // ִ���û�������

    while(1);           // ��ѭ��
}

void ics_init(void)
{
    // ��ʼ��ʱ�����ã������ⲿ�ο�ʱ�ӣ�


    // ����ϵͳʱ�ӷ�Ƶֵ
    SIM->CLKDIV =   (0
                     | SIM_CLKDIV_OUTDIV1(0x00)                 // ��ICSOUTCLK��Ϊϵͳʱ��
                     | (BUS_ISDIV<<SIM_CLKDIV_OUTDIV2_SHIFT)   // ��ϵͳʱ�ӵ�1/2��Ϊ����ʱ��
                     | (TIMER_ISDIV<<SIM_CLKDIV_OUTDIV3_SHIFT)    // ��ϵͳʱ�ӵ�1/2��Ϊ��ʱ��ʱ��
                    );

    /* �л��� FEE ģʽ */
    ICS->C2 = (0
               |   ICS_C2_BDIV(0x0)
               //|   ICS_C2_LP_MASK
              );

    OSC->CR = (0
               | OSC_CR_OSCEN_MASK     //OSC ģ��ʹ��
               | OSC_CR_OSCOS_MASK     //OSC ���ѡ��      (0�� EXTAL ���ŵ��ⲿʱ��Դ��1������ʱ��Դ)
               | OSC_CR_RANGE_MASK     //Ƶ�ʷ�Χѡ��      (0��32 kHz �ĵ�Ƶ��Χ��1��4�C24 MHz �ĸ�Ƶ��Χ��)
               | OSC_CR_HGO_MASK       //����������ѡ��  (0 �͹���ģʽ,1 ������ģʽ)
              );

    ICS->C1 = ( 0
                //| ICS_C1_IREFS_MASK   // FLL �Ļ�׼ʱ��Դ��(0 ѡ���ⲿ��׼ʱ�ӡ�1 ѡ���ڲ���׼ʱ�ӡ�)
                | ICS_C1_CLKS(0x00)     //���� FLL �ⲿ����(FEE)ģʽ �����ֵΪ 0
#if  (CORE_CLK == 80)
                | ICS_C1_RDIV(0x02)
#elif (CORE_CLK == 40)
                | ICS_C1_RDIV(0x03)
#elif  (CORE_CLK == 20)
                | ICS_C1_RDIV(0x04)
#else
#error "Ƶ����������"
#endif
                | ICS_C1_IRCLKEN_MASK
              );

    while((ICS->S & ICS_S_IREFST_MASK) != 0x00U) {}      //�ȴ�ʱ��ѡ���ⲿʱ��
    while((ICS->S & ICS_S_CLKST_MASK) != 0x00U) {}       //�ȴ�ʱ��ģʽ״̬ѡ�� FLL �����


    core_clk_khz = CORE_CLK*1000;
    core_clk_mhz = CORE_CLK;
    bus_clk_khz = core_clk_khz / (BUS_ISDIV+1);
    timer_clk_khz = core_clk_khz / (TIMER_ISDIV+1);

}

/*!
 *  @brief      ϵͳ��ʼ��������ϵͳƵ�ʣ���ʼ��printf�˿�
 *  @since      v5.0
 *  @note       �˺�����ϵͳ���������ɻ�ຯ�����ã�Ȼ��ִ��main����
 */
void sysinit (void)
{
    //ICS ��ʼ����Ƶ
    ics_init();

    uart_init (VCAN_PORT, VCAN_BAUD);   //��ʼ��printf�õ��Ĺܽ�
}



/*!
 *  @brief      �����ж������� �� ��Ҫ�����ݵ� RAM��
 *  @since      v5.0
 *  @author     ��˼������˾
 */
#pragma section = ".data"
#pragma section = ".data_init"
#pragma section = ".bss"
#pragma section = "CodeRelocate"
#pragma section = "CodeRelocateRam"

void common_startup(void)
{
    /* Declare a counter we'll use in all of the copy loops */
    uint32 n;

    /* Declare pointers for various data sections. These pointers
     * are initialized using values pulled in from the linker file
     */
    uint8 *data_ram, * data_rom, * data_rom_end;
    uint8 *bss_start, * bss_end;


    /*  VECTOR_TABLE �� VECTOR_RAM �ĵ�ַ��  linker �ļ����� ��*.icf�� */
    extern uint32 __VECTOR_TABLE[];

    /* ָ���µ��ж��������ַΪ  */
    write_vtor((uint32)__VECTOR_TABLE);

    /* ���Ѹ���ֵ�ı�����ROM�︴�����ݵ�RAM�� */
    data_ram = __section_begin(".data");            //�Ѹ���ֵ�ı����ĵ�ַ��RAM��
    data_rom = __section_begin(".data_init");       //�Ѹ���ֵ�ı��������ݴ����ROM���Ҫ��ֵ��RAM��
    data_rom_end = __section_end(".data_init");
    n = data_rom_end - data_rom;

    /* ���Ƴ�ʼ�����ݵ�RAM�� */
    while (n--)
        *data_ram++ = *data_rom++;

    /* û����ֵ���߳�ֵΪ0�ı�������Ҫ�����RAM������ݣ�ȷ��ֵΪ0 */
    bss_start = __section_begin(".bss");
    bss_end = __section_end(".bss");

    /* ���û����ֵ���߳�ֵΪ0�ı�������ֵ */
    n = bss_end - bss_start;
    while(n--)
        *bss_start++ = 0;

    /* ��ֵ�� __ramfunc �����ĺ����ĵĴ���ε� RAM�����Լӿ���������        */
    uint8 *code_relocate_ram = __section_begin("CodeRelocateRam");
    uint8 *code_relocate = __section_begin("CodeRelocate");
    uint8 *code_relocate_end = __section_end("CodeRelocate");

    /* ��ROM�︴�ƺ������뵽RAM�� */
    n = code_relocate_end - code_relocate;
    while (n--)
        *code_relocate_ram++ = *code_relocate++;

}
