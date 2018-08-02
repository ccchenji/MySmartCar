/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       system_MK66FX18.c
 * @brief      系统启动相关函数
 * @author     山外科技
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
 *  @brief      kinetis 启动函数
 *  @since      v5.0
 *  @author     飞思卡尔公司
 *  @note       此函数是系统启动初期由汇编函数调用，然后执行main函数
 */
void start(void)
{

    wdog_disable();     // 关闭看门狗


    common_startup();   // 复制中断向量表 和 必要的数据到 RAM里



    sysinit();          // 系统初始化，设置系统频率，初始化printf端口




    main();             // 执行用户主函数

    while(1);           // 死循环
}

void ics_init(void)
{
    // 初始化时钟配置（采用外部参考时钟）


    // 更新系统时钟分频值
    SIM->CLKDIV =   (0
                     | SIM_CLKDIV_OUTDIV1(0x00)                 // 将ICSOUTCLK作为系统时钟
                     | (BUS_ISDIV<<SIM_CLKDIV_OUTDIV2_SHIFT)   // 将系统时钟的1/2作为总线时钟
                     | (TIMER_ISDIV<<SIM_CLKDIV_OUTDIV3_SHIFT)    // 将系统时钟的1/2作为定时器时钟
                    );

    /* 切换到 FEE 模式 */
    ICS->C2 = (0
               |   ICS_C2_BDIV(0x0)
               //|   ICS_C2_LP_MASK
              );

    OSC->CR = (0
               | OSC_CR_OSCEN_MASK     //OSC 模块使能
               | OSC_CR_OSCOS_MASK     //OSC 输出选择      (0是 EXTAL 引脚的外部时钟源，1是振荡器时钟源)
               | OSC_CR_RANGE_MASK     //频率范围选择      (0是32 kHz 的低频范围。1是4–24 MHz 的高频范围。)
               | OSC_CR_HGO_MASK       //高增益振荡器选择  (0 低功耗模式,1 高增益模式)
              );

    ICS->C1 = ( 0
                //| ICS_C1_IREFS_MASK   // FLL 的基准时钟源。(0 选择外部基准时钟。1 选择内部基准时钟。)
                | ICS_C1_CLKS(0x00)     //进入 FLL 外部启用(FEE)模式 必须此值为 0
#if  (CORE_CLK == 80)
                | ICS_C1_RDIV(0x02)
#elif (CORE_CLK == 40)
                | ICS_C1_RDIV(0x03)
#elif  (CORE_CLK == 20)
                | ICS_C1_RDIV(0x04)
#else
#error "频率配置有误"
#endif
                | ICS_C1_IRCLKEN_MASK
              );

    while((ICS->S & ICS_S_IREFST_MASK) != 0x00U) {}      //等待时钟选择外部时钟
    while((ICS->S & ICS_S_CLKST_MASK) != 0x00U) {}       //等待时钟模式状态选择 FLL 的输出


    core_clk_khz = CORE_CLK*1000;
    core_clk_mhz = CORE_CLK;
    bus_clk_khz = core_clk_khz / (BUS_ISDIV+1);
    timer_clk_khz = core_clk_khz / (TIMER_ISDIV+1);

}

/*!
 *  @brief      系统初始化，设置系统频率，初始化printf端口
 *  @since      v5.0
 *  @note       此函数是系统启动初期由汇编函数调用，然后执行main函数
 */
void sysinit (void)
{
    //ICS 初始化超频
    ics_init();

    uart_init (VCAN_PORT, VCAN_BAUD);   //初始化printf用到的管脚
}



/*!
 *  @brief      复制中断向量表 和 必要的数据到 RAM里
 *  @since      v5.0
 *  @author     飞思卡尔公司
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


    /*  VECTOR_TABLE 和 VECTOR_RAM 的地址从  linker 文件里获得 （*.icf） */
    extern uint32 __VECTOR_TABLE[];

    /* 指定新的中断向量表地址为  */
    write_vtor((uint32)__VECTOR_TABLE);

    /* 把已赋初值的变量从ROM里复制数据到RAM里 */
    data_ram = __section_begin(".data");            //已赋初值的变量的地址在RAM里
    data_rom = __section_begin(".data_init");       //已赋初值的变量的数据存放在ROM里，需要赋值到RAM里
    data_rom_end = __section_end(".data_init");
    n = data_rom_end - data_rom;

    /* 复制初始化数据到RAM里 */
    while (n--)
        *data_ram++ = *data_rom++;

    /* 没赋初值或者初值为0的变量，需要清除其RAM里的数据，确保值为0 */
    bss_start = __section_begin(".bss");
    bss_end = __section_end(".bss");

    /* 清除没赋初值或者初值为0的变量数据值 */
    n = bss_end - bss_start;
    while(n--)
        *bss_start++ = 0;

    /* 赋值用 __ramfunc 声明的函数的的代码段到 RAM，可以加快代码的运行        */
    uint8 *code_relocate_ram = __section_begin("CodeRelocateRam");
    uint8 *code_relocate = __section_begin("CodeRelocate");
    uint8 *code_relocate_end = __section_end("CodeRelocate");

    /* 从ROM里复制函数代码到RAM里 */
    n = code_relocate_end - code_relocate;
    while (n--)
        *code_relocate_ram++ = *code_relocate++;

}
