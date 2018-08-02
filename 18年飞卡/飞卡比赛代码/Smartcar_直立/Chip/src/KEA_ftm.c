/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_ftm.c
 * @brief      FTM定时器函数库
 * @author     山外科技
 * @version    v5.2
 * @date       2014-10-31
 */


/*
 * 包含头文件
 */
#include "common.h"
#include  "KEA_FTM.h"

#define FTMn(ftmn)     ( (uint32_t)(((ftmn)-FTM0)/(FTM1-FTM0) ) )



static uint32 ftm_mod[FTM_MAX];

/*!
 *  @brief      初始化FTM 的端口
 *  @param      FTMn_e    模块号（FTM0、  FTM1、  FTM2）
 *  @param      FTM_CHn_e     通道号（CH0~CH7）
 *  @since      v5.0
 */
static void ftm_port_mux(FTMn_e ftmn, FTM_CHn_e ch)
{
    /******************* 开启时钟 和 复用IO口*******************/
    switch((uint32_t)ftmn)
    {
    case (uint32_t)FTM0:
        SIM_SCGC |= SIM_SCGC_FTM0_MASK;     //使能FTM0时钟
        switch(ch)
        {
        case  FTM_CH0:
            if(FTM0_CH0_PIN == PTA0) BIT_CLEAN(SIM_PINSEL0, SIM_PINSEL_FTM0PS0_SHIFT);
            else if(FTM0_CH0_PIN == PTB2)BIT_SET(SIM_PINSEL0, SIM_PINSEL_FTM0PS0_SHIFT);

            break;
        case  FTM_CH1:
            if(FTM0_CH1_PIN == PTA1) BIT_CLEAN(SIM_PINSEL0, SIM_PINSEL_FTM0PS1_SHIFT);
            else if(FTM0_CH1_PIN == PTB3) BIT_SET(SIM_PINSEL0, SIM_PINSEL_FTM0PS1_SHIFT);
            break;

        }
        break;
    case (uint32_t)FTM1:
        SIM_SCGC |= SIM_SCGC_FTM1_MASK;       //使能FTM1时钟
        switch(ch)
        {
        case  FTM_CH0:
            if(FTM1_CH0_PIN == PTC4) BIT_CLEAN(SIM_PINSEL0, SIM_PINSEL_FTM1PS0_SHIFT);
            else if(FTM1_CH0_PIN == PTH2) BIT_SET(SIM_PINSEL0, SIM_PINSEL_FTM1PS0_SHIFT);
            break;
        case  FTM_CH1:
            if(FTM1_CH1_PIN == PTC5) BIT_CLEAN(SIM_PINSEL0, SIM_PINSEL_FTM1PS1_SHIFT);
            else if(FTM1_CH1_PIN == PTE7) BIT_SET(SIM_PINSEL0, SIM_PINSEL_FTM1PS1_SHIFT);
            break;

        }

        break;
    case (uint32_t)FTM2:
        SIM_SCGC |= SIM_SCGC_FTM2_MASK;           //使能FTM2时钟

        switch(ch)
        {
        case  FTM_CH0:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS0_MASK;     //先清空，再配置
            if(FTM2_CH0_PIN == PTC0) SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS0(0);
            else if(FTM2_CH0_PIN == PTF0) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(2);
            else if(FTM2_CH0_PIN == PTH0) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(1);

            break;
        case  FTM_CH1:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS1_MASK;     //先清空，再配置
            if(FTM2_CH1_PIN == PTC1) SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS1(0);
            else if(FTM2_CH1_PIN == PTF1) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(2);
            else if(FTM2_CH1_PIN == PTH1) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(1);
            break;
        case  FTM_CH2:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS2_MASK;     //先清空，再配置
            if(FTM2_CH2_PIN == PTC2) SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS2(0);
            else if(FTM2_CH2_PIN == PTD0) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(1);
            else if(FTM2_CH2_PIN == PTG4) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(2);
            break;
        case  FTM_CH3:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS3_MASK;     //先清空，再配置
            if(FTM2_CH3_PIN == PTC3) SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS3(0);
            else if(FTM2_CH3_PIN == PTD1) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(1);
            else if(FTM2_CH3_PIN == PTG5) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS3(2);
            break;
        case  FTM_CH4:
            if(FTM2_CH4_PIN == PTB4)
            {
                BIT_CLEAN(SIM_SOPT0, SIM_SOPT0_NMIE_SHIFT);
                BIT_CLEAN(SIM_PINSEL1, SIM_PINSEL1_FTM2PS4_SHIFT);
            }
            else if(FTM2_CH4_PIN == PTG6)   BIT_SET(SIM_PINSEL1, SIM_PINSEL1_FTM2PS4_SHIFT);
            break;
        case  FTM_CH5:
            if(FTM2_CH4_PIN == PTB5)        BIT_CLEAN(SIM_PINSEL1, SIM_PINSEL1_FTM2PS5_SHIFT);
            else if(FTM2_CH4_PIN == PTG7)   BIT_SET(SIM_PINSEL1, SIM_PINSEL1_FTM2PS5_SHIFT);
            break;
        }

    default:
        break;
    }
}

//使能对应模块的时钟
static inline void ftm_enable_clk(FTMn_e ftmn)
{
    /******************* 开启时钟*******************/
    BIT_SET(SIM_SCGC, (SIM_SCGC_FTM0_SHIFT + FTMn(ftmn)));
}

//使能对应模块的中断
void ftm_enable_irq(FTMn_e ftmn)
{
    enable_irq((IRQn_t)(FTM0_IRQn + FTMn(ftmn)));     //使能FTM0中断
}

//禁用对应模块的中断
void ftm_disable_irq(FTMn_e ftmn)
{
    disable_irq((IRQn_t)(FTM0_IRQn + FTMn(ftmn)));     //禁用FTM中断
}


void ftm_clear_overflag(FTMn_e ftmn)
{
    if(ftmn->SC  | FTM_SC_TOF_MASK)
    {
        ftmn->SC &=  ~FTM_SC_TOF_MASK;
    }
}

void  ftm_pwm_finit(FTMn_e ftmn, FTM_CHn_e ch, uint32 freq, float duty)  //初始化FTM的PWM功能并设置频率、占空比。设置通道输出占空比。同一个FTM，各通道的PWM频率是一样的，共3个FTM(FX有4个)
{
    uint32 clk_hz ;
    uint16 mod;
    uint8  ps;
    uint16 cv;


    /******************* 开启时钟 和 复用IO口*******************/
    ftm_port_mux(ftmn, ch);

    /*       计算频率设置        */
    //  若 CPWMS = 1 ，即双边捕捉脉冲，则 PMW频率 =  bus频率 /2 /(2^预分频因子)/模数
    //  若 CPWMS = 0 ，即单边捕捉脉冲，则 PMW频率 =  bus频率    /(2^预分频因子)/模数
    //  EPWM的周期 ：MOD - CNTIN + 0x0001   (CNTIN 设为0)
    //  脉冲宽度：CnV - CNTIN

    //  模数 MOD < 0x10000
    //  预分频因子 PS  < 0x07
    //  预分频因子 PS 越小时，模数 mod 就越大，计数就越精准，PWM输出更为准确
    //  MOD  = clk_hz/(freq*(1 << PS)) < 0x10000  ==>  clk_hz/(freq*0x10000) < (1<< PS)  ==>  (clk_hz/(freq*0x10000) >> PS) < 1
    //  即 (((clk_hz/0x10000 )/ freq ) >> PS ) < 1

    // 以 CPWMS = 0 ，即单边捕捉脉冲为例
    clk_hz = (bus_clk_khz * 1000) ;     // bus频率

    mod = (clk_hz >> 16 ) / freq ;      // 临时用 mod 缓存一下
    ps = 0;
    while((mod >> ps) >= 1)             // 等 (mod >> ps) < 1 才退出 while 循环 ，即求 PS 的最小值
    {
        ps++;
    }

    ASSERT(ps <= 0x07);                 // 断言， PS 最大为 0x07 ，超过此值，则 PWM频率设置过低，或 Bus 频率过高

    mod = (clk_hz >> ps) / freq;        // 求 MOD 的值
    ftm_mod[FTMn(ftmn) ] = mod;

    cv = (uint16)((duty * (float)(mod - 0 + 1)) / 100);


    /******************** 选择输出模式为 边沿对齐PWM *******************/
    //通道状态控制，根据模式来选择 边沿或电平
    FTM_CnSC_REG(ftmn, ch) &= ~FTM_CnSC_ELSA_MASK;
    FTM_CnSC_REG(ftmn, ch)  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;

    /******************** 配置时钟和分频 ********************/

    //MODE CNTIN 寄存器仅FTM2才有

    FTM_SC_REG(ftmn) = 0;

    FTM_MOD_REG(ftmn)   = mod;                        //模数, EPWM的周期为 ：MOD - CNTIN + 0x0001
    if(ftmn == FTM2)
    {
        FTM_CNTIN_REG(ftmn) = 0;                          //计数器初始化值。设置脉冲宽度：(CnV - CNTIN).
    }
    FTM_CnV_REG(ftmn, ch) = cv;
    FTM_CNT_REG(ftmn)   = 0;                          //计数器。只有低16位可用（写任何值到此寄存器，都会加载 CNTIN 的值）

    FTM_SC_REG(ftmn)    = ( 0
                            //| FTM_SC_CPWMS_MASK         //0：上升沿计数模式 ，1： 跳变沿计数模式选择 （注释了表示 0）
                            | FTM_SC_PS(ps)             //分频因子，分频系数 = 2^PS
                            | FTM_SC_CLKS(1)            //时钟选择，1是bus 时钟
                            //| FTM_SC_TOIE_MASK        //溢出中断使能（注释了表示 禁止溢出中断）
                          );

}

/*!
 *  @brief      初始化FTM 的PWM 功能
 *  @param      FTMn_e    模块号（FTM0、  FTM1、  FTM2）
 *  @param      FTM_CHn_e     通道号（CH0~CH7）
 *  @param      freq    频率（单位为Hz）
 *  @param      duty    占空比分子，占空比 = duty / FTMn_PRECISON
 *  @since      v5.0
 *  @note       同一个FTM，PWM频率是必须一样的，但占空比可不一样。共3个FTM，即可以输出3个不同频率PWM
 *  Sample usage:       ftm_pwm_init(FTM0, FTM_CH6,200, 10);    //初始化 FTM0_CH6 为 频率 200Hz 的PWM，占空比为 10/FTM0_PRECISON
 */
void ftm_pwm_init(FTMn_e ftmn, FTM_CHn_e ch, uint32 freq, uint32 duty)
{
    uint32 clk_hz ;
    uint16 mod;
    uint8  ps;
    uint16 cv;



    /******************* 开启时钟 和 复用IO口*******************/
    ftm_port_mux(ftmn, ch);

    /*       计算频率设置        */
    //  若 CPWMS = 1 ，即双边捕捉脉冲，则 PMW频率 =  bus频率 /2 /(2^预分频因子)/模数
    //  若 CPWMS = 0 ，即单边捕捉脉冲，则 PMW频率 =  bus频率    /(2^预分频因子)/模数
    //  EPWM的周期 ：MOD - CNTIN + 0x0001   (CNTIN 设为0)
    //  脉冲宽度：CnV - CNTIN

    //  模数 MOD < 0x10000
    //  预分频因子 PS  < 0x07
    //  预分频因子 PS 越小时，模数 mod 就越大，计数就越精准，PWM输出更为准确
    //  MOD  = clk_hz/(freq*(1 << PS)) < 0x10000  ==>  clk_hz/(freq*0x10000) < (1<< PS)  ==>  (clk_hz/(freq*0x10000) >> PS) < 1
    //  即 (((clk_hz/0x10000 )/ freq ) >> PS ) < 1

    // 以 CPWMS = 0 ，即单边捕捉脉冲为例
    clk_hz = (bus_clk_khz * 1000) ;     // bus频率

    mod = (clk_hz >> 16 ) / freq ;      // 临时用 mod 缓存一下
    ps = 0;
    while((mod >> ps) >= 1)             // 等 (mod >> ps) < 1 才退出 while 循环 ，即求 PS 的最小值
    {
        ps++;
    }

    ASSERT(ps <= 0x07);                 // 断言， PS 最大为 0x07 ，超过此值，则 PWM频率设置过低，或 Bus 频率过高

    mod = (clk_hz >> ps) / freq;        // 求 MOD 的值

    switch((uint32_t)ftmn)                        // 初值 CNTIN 设为0 ，脉冲宽度：CnV - CNTIN ，即 CnV 就是 脉冲宽度了。
    {
        // EPWM的周期 ： MOD - CNTIN + 0x0001 == MOD - 0 + 1
        // 则 CnV = (MOD - 0 + 1) * 占空比 = (MOD - 0 + 1) * duty/ FTM_PRECISON
    case (uint32_t)FTM0:
        ftm_mod[0] = mod;
        cv = (duty * (mod - 0 + 1)) / FTM0_PRECISON;
        break;

    case (uint32_t)FTM1:
        ftm_mod[1] = mod;
        cv = (duty * (mod - 0 + 1)) / FTM1_PRECISON;
        break;

    case (uint32_t)FTM2:
        ftm_mod[2] = mod;
        cv = (duty * (mod - 0 + 1)) / FTM2_PRECISON;
        break;


    default:
        break;
    }

    /******************** 选择输出模式为 边沿对齐PWM *******************/
    //通道状态控制，根据模式来选择 边沿或电平
    FTM_CnSC_REG(ftmn, ch) &= ~FTM_CnSC_ELSA_MASK;
    FTM_CnSC_REG(ftmn, ch)  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
    // MSnB:MSnA = 1x       边沿对齐PWM
    // ELSnB:ELSnA = 10     先高后低
    // ELSnB:ELSnA = 11     先低后高

    /******************** 配置时钟和分频 ********************/
    //FTM_FMS_REG(FTMN[ftmn]) |=FTM_FMS_WPEN_MASK;

    //MODE CNTIN 寄存器仅FTM2才有

    FTM_SC_REG(ftmn) = 0;

    FTM_MOD_REG(ftmn)   = mod;                        //模数, EPWM的周期为 ：MOD - CNTIN + 0x0001
    if(ftmn == FTM2)
    {
        FTM_CNTIN_REG(ftmn) = 0;                          //计数器初始化值。设置脉冲宽度：(CnV - CNTIN).
    }
    FTM_CnV_REG(ftmn, ch) = cv;
    FTM_CNT_REG(ftmn)   = 0;                          //计数器。只有低16位可用（写任何值到此寄存器，都会加载 CNTIN 的值）

    FTM_SC_REG(ftmn)    = ( 0
                            //| FTM_SC_CPWMS_MASK         //0：上升沿计数模式 ，1： 跳变沿计数模式选择 （注释了表示 0）
                            | FTM_SC_PS(ps)             //分频因子，分频系数 = 2^PS
                            | FTM_SC_CLKS(1)            //时钟选择，1是bus 时钟
                            //| FTM_SC_TOIE_MASK        //溢出中断使能（注释了表示 禁止溢出中断）
                          );


}

/*!
 *  @brief      设置FTM 的PWM 通道占空比
 *  @param      FTMn_e    模块号（FTM0、  FTM1、  FTM2）
 *  @param      FTM_CHn_e     通道号（CH0~CH7）
 *  @param      duty    占空比分子，占空比 = duty / FTMn_PRECISON
 *  @since      v5.0
 *  @note       同一个FTM，PWM频率是必须一样的，但占空比可不一样。共3个FTM，即可以输出3个不同频率PWM
 *  Sample usage:       ftm_pwm_duty(FTM0, FTM_CH6, 10);    //设置 FTM0_CH6占空比为 10/FTM0_PRECISON
 */
void ftm_pwm_duty(FTMn_e ftmn, FTM_CHn_e ch, uint32 duty)
{
    uint32 cv;
    uint32 mod = 0;
#ifdef DEBUG_MODE
    switch((uint32_t)ftmn)
    {
        //如果此处断言失败，说明占空比超过 100% ，务必自行检查是否出现这情况。
    case (uint32_t)FTM0:
        ASSERT(duty <= FTM0_PRECISON);     //用断言检测 占空比是否合理
        break;

    case (uint32_t)FTM1:
        ASSERT(duty <= FTM1_PRECISON);     //用断言检测 占空比是否合理
        break;
    case (uint32_t)FTM2:
        ASSERT(duty <= FTM2_PRECISON);     //用断言检测 占空比是否合理
        break;

    default:
        ASSERT(0);
        break;
    }

#else
    //防止非DEBUG模式下，出现占空比超过100%
    switch((uint32_t)ftmn)
    {
        //
    case (uint32_t)FTM0:
        if(duty > FTM0_PRECISON)
            duty = FTM0_PRECISON;
        break;

    case (uint32_t)FTM1:
        if(duty > FTM2_PRECISON)
            duty = FTM1_PRECISON;
        break;
    case (uint32_t)FTM2:
        if(duty > FTM2_PRECISON)
            duty = FTM2_PRECISON;
        break;

    default:
        ASSERT(0);
        break;
    }
#endif

    //占空比 = (CnV-CNTIN)/(MOD-CNTIN+1
    switch((uint32_t)ftmn)
    {
    case (uint32_t)FTM0:
        mod = ftm_mod[0];
        cv = (duty * (mod - 0 + 1)) / FTM0_PRECISON;
        break;

    case (uint32_t)FTM1:
        mod = ftm_mod[1];
        cv = (duty * (mod - 0 + 1)) / FTM1_PRECISON;
        break;

    case (uint32_t)FTM2:
        mod = ftm_mod[2];
        cv = (duty * (mod - 0 + 1)) / FTM2_PRECISON;
        break;

    default:
        ASSERT(0);
        break;
    }

    // 配置FTM通道值
    FTM_CnV_REG(ftmn, ch) = cv;

    //计数器。只有低16位可用（写任何值到此寄存器，都会加载 CNTIN 的值）
}
/*!
 *  @brief      设置FTM 的PWM 通道占空比
 *  @param      FTMn_e    模块号（FTM0、  FTM1、  FTM2）
 *  @param      FTM_CHn_e     通道号（CH0~CH7）
 *  @param      duty    占空比分子，占空比 = duty %
 *  @since      v5.0
 *  @note       同一个FTM，PWM频率是必须一样的，但占空比可不一样。共3个FTM，即可以输出3个不同频率PWM
 *  Sample usage:       ftm_pwm_fduty(FTM0, FTM_CH6, 10);    //设置 FTM0_CH6占空比为 10%
 */
void ftm_pwm_fduty(FTMn_e ftmn, FTM_CHn_e ch, float duty)
{
    uint32 cv;
    uint32 mod = 0;
#ifdef DEBUG_MODE

    ASSERT(duty <= 100.0);     //用断言检测 占空比是否合理


#else
    //防止非DEBUG模式下，出现占空比超过100%
    if(duty > 100.0)
    {
        duty = 100.0;
    }
#endif

    duty = duty/100.0;
    //占空比 = (CnV-CNTIN)/(MOD-CNTIN+1
    switch((uint32_t)ftmn)
    {
    case (uint32_t)FTM0:
        mod = ftm_mod[0];
        cv = (uint32_t)(duty * (mod - 0 + 1)) ;
        break;

    case (uint32_t)FTM1:
        mod = ftm_mod[1];
        cv = (uint32_t)(duty * (mod - 0 + 1)) ;
        break;

    case (uint32_t)FTM2:
        mod = ftm_mod[2];
        cv = (uint32_t)(duty * (mod - 0 + 1)) ;
        break;

    default:
        ASSERT(0);
        break;
    }

    // 配置FTM通道值
    FTM_CnV_REG(ftmn, ch) = cv;

    //计数器。只有低16位可用（写任何值到此寄存器，都会加载 CNTIN 的值）
}


/*!
 *  @brief      设置FTM的频率
 *  @param      freq    频率（单位为Hz）
 *  @since      v5.0
 *  @note       修改PWM频率后，必须调用 ftm_pwm_duty 重新配置占空比。同一个模块，PWM频率必须相同。
 *  Sample usage:       ftm_pwm_freq(FTM0,200);    //设置 FTM0 的 频率 为 200Hz
 */
void ftm_pwm_freq(FTMn_e ftmn, uint32 freq)             //设置FTM的频率
{
    uint32 clk_hz = (bus_clk_khz * 1000) >> 1;        //bus频率/2
    uint32 mod;
    uint8 ps;

    /*       计算频率设置        */
    // 以 CPWMS = 0 ，即单边捕捉脉冲为例
    clk_hz = (bus_clk_khz * 1000) ;     // bus频率

    mod = (clk_hz >> 16 ) / freq ;      // 临时用 mod 缓存一下
    ps = 0;
    while((mod >> ps) >= 1)             // 等 (mod >> ps) < 1 才退出 while 循环 ，即求 PS 的最小值
    {
        ps++;
    }

    ASSERT(ps <= 0x07);                 // 断言， PS 最大为 0x07 ，超过此值，则 PWM频率设置过低，或 Bus 频率过高

    mod = (clk_hz >> ps) / freq;        // 求 MOD 的值

    switch((uint32_t)ftmn)
    {
    case (uint32_t)FTM0:
        ftm_mod[0] = mod;
        break;

    case (uint32_t)FTM1:
        ftm_mod[1] = mod;
        break;

    case (uint32_t)FTM2:
        ftm_mod[2] = mod;
        break;

    default:
        ASSERT(0);
        break;
    }

    /******************** 配置时钟和分频 ********************/
    FTM_SC_REG(ftmn)    = ( 0
                            //| FTM_SC_CPWMS_MASK         //0：上升沿计数模式 ，1： 跳变沿计数模式选择 （注释了表示 0）
                            | FTM_SC_PS(ps)             //分频因子，分频系数 = 2^PS
                            | FTM_SC_CLKS(1)            //时钟选择， 0：没选择时钟，禁用； 1：bus 时钟； 2：MCGFFCLK； 3：EXTCLK（ 由SIM_SOPT4 选择输入管脚 FTM_CLKINx）
                            //| FTM_SC_TOIE_MASK        //溢出中断使能（注释了表示 禁止溢出中断）
                          );
    FTM_CNTIN_REG(ftmn) = 0;      //计数器初始化值。设置脉冲宽度：(CnV - CNTIN).
    FTM_MOD_REG(ftmn)   = mod;    //模数, EPWM的周期为 ：MOD - CNTIN + 0x0001
    FTM_CNT_REG(ftmn)   = 0;      //计数器。只有低16位可用（写任何值到此寄存器，都会加载 CNTIN 的值）
}

//////////////////////////////// 以上为输出PWM  //////////////////////////////////////////


//////////////////////////////// 以下为输入捕捉 //////////////////////////////////////////

/*!
 *  @brief      输入捕捉初始化函数
 *  @param      FTMn_e          模块号（FTM0、  FTM1、  FTM2）
 *  @param      FTM_CHn_e       通道号（CH0~CH7）
 *  @param      FTM_Input_cfg   输入捕捉触发条件配置
 *  @param      FTM_PS_e        分频因子
 *  @since      v5.0
 *  @note       同一个FTM，只能干一个活，用于输入捕捉后就不要再用于其他功能，例如PWM。
 *  Sample usage:       ftm_input_init(FTM0, FTM_CH0, FTM_Rising,FTM_PS_2);    //设置 FTM0_CH0上升沿触发输入捕捉，二分频
 */
void ftm_input_init(FTMn_e ftmn, FTM_CHn_e ch, FTM_Input_cfg cfg, FTM_PS_e ps)
{
    ASSERT(  (ftmn == FTM2) );  //检查传递进来的通道是否正确 (寄存器配置，貌似只有FTM2才能做输入捕捉的功能)

    /******************* 开启时钟 和 复用IO口*******************/
    ftm_port_mux(ftmn, ch);

    /******************* 设置为输入捕捉功能 *******************/
    switch(cfg)
    {
        //输入捕捉模式下：DECAPEN = 0 ， DECAPEN = 0 ，CPWMS = 0， MSnB:MSnA = 0

        // ELSnB:ELSnA         1          10          11
        // 配置             上升沿      下降沿      跳变沿

    case FTM_Rising:    //上升沿触发
        FTM_CnSC_REG(ftmn, ch) |=  ( FTM_CnSC_ELSA_MASK  | FTM_CnSC_CHIE_MASK );                   //置1
        FTM_CnSC_REG(ftmn, ch) &= ~( FTM_CnSC_ELSB_MASK  | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK); //清0
        break;

    case FTM_Falling:   //下降沿触发
        FTM_CnSC_REG(ftmn, ch) |= (FTM_CnSC_ELSB_MASK  | FTM_CnSC_CHIE_MASK );                    //置1
        FTM_CnSC_REG(ftmn, ch) &= ~( FTM_CnSC_ELSA_MASK | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK); //清0
        break;

    case FTM_Rising_or_Falling: //上升沿、下降沿都触发
        FTM_CnSC_REG(ftmn, ch) |=  ( FTM_CnSC_ELSB_MASK | FTM_CnSC_ELSA_MASK  | FTM_CnSC_CHIE_MASK ); //置1
        FTM_CnSC_REG(ftmn, ch) &= ~( FTM_CnSC_MSB_MASK  | FTM_CnSC_MSA_MASK); //清0
        break;
    }

    FTM_SC_REG(ftmn) = 0;
    FTM_MODE_REG(ftmn)  =    (0
                              | FTM_MODE_WPDIS_MASK  //写保护禁止
                              //| FTM_MODE_FTMEN_MASK   //使能 FTM
                             );


    FTM_COMBINE_REG(ftmn) = 0;
    //FTM_MODE_REG(FTMN[ftmn])    &= ~FTM_MODE_FTMEN_MASK;    //使能FTM
    FTM_CNTIN_REG(ftmn)   = 0;

    FTM_STATUS_REG(ftmn)  = 0x00;               //清中断标志位

    FTM_MOD_REG(ftmn)     = FTM_MOD_MOD_MASK;

    FTM_SC_REG(ftmn) = ( 0
                         | FTM_SC_CLKS(0x1)       //选择 bus 时钟
                         | FTM_SC_PS(ps)          //选择 分频系数
                       );

    FTM_MODE_REG(ftmn)  |=    (0
                               //| FTM_MODE_WPDIS_MASK  //写保护禁止
                               | FTM_MODE_FTMEN_MASK   //使能 FTM
                              );

    //开启输入捕捉中断
    //enable_irq(FTM0_IRQn + ftmn);
}

/*!
 *  @brief      输入捕捉初始化函数
 *  @param      FTMn_e          模块号（FTM0、  FTM1、  FTM2）
 *  @param      FTM_CHn_e       通道号（CH0~CH7）
 *  @param      FTM_Input_cfg   输入捕捉触发条件配置
 *  @return     获取捕捉事件发生时的计数器值 (根据两次捕捉之间的差值可判断周期频率)
 *  @since      v5.0
 *  Sample usage:       uint16 data = ftm_input_get (FTM0, FTM_CH0) ;   // 获取FTM0_CH0输入捕捉事件触发时的计数值
 */
uint16   ftm_input_get (FTMn_e ftmn, FTM_CHn_e ch)
{
    return (uint16)FTM_CnV_REG(ftmn, ch);   //保存
}

void     ftm_input_clean (FTMn_e ftmn)
{
    FTM_CNT_REG(ftmn) = 0;               //清 计数器计数值
}


/*!
 *  @brief      FTM测试中断服务函数
 *  @since      v5.0
 *  @warning    此函数需要用户根据自己需求完成，这里仅仅是提供一个模版
 *  Sample usage:       set_vector_handler(FTM0_IRQn , FTM1_Input_test_handler);    //把 FTM1_Input_test_handler 函数添加到中断向量表，不需要我们手动调用
 */
void ftm2_Input_test_handler(void)
{
    uint8 s = FTM2_STATUS;             //读取捕捉和比较状态  All CHnF bits can be checked using only one read of STATUS.
    uint8 CHn;

    FTM2_STATUS = 0x00;             //清中断标志位

    CHn = 0;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_DIS(FTM2, CHn);     //禁止输入捕捉中断
        /*     用户任务       */

        /*********************/
        //FTM_IRQ_EN(FTM2, CHn); //开启输入捕捉中断

    }

    /* 这里添加 n=1 的模版，根据模版来添加 */
    CHn = 1;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_EN(FTM2, CHn); //开启输入捕捉中断
        /*     用户任务       */


        /*********************/
        //不建议在这里开启输入捕捉中断
        //FTM_IRQ_EN(FTM2, CHn); //开启输入捕捉中断
    }
}

//////////////////////////////// 以上为输入捕捉  //////////////////////////////////////////

//////////////////////////////// 以下为外部引脚脉冲计数 //////////////////////////////////////////
//脉冲频率较高时，可用分频功能
//如果是欧姆龙那种开漏输出的，需要配置上拉：port_pull(FTM0_PULSE_PIN,PULLUP_ENBLE);
void ftm_pulse_mux(FTMn_e ftmn, PTXn_e ptxn)
{
    int n = FTMn(ftmn);

    ftm_enable_clk(ftmn);
    SIM->PINSEL &= ~(SIM_PINSEL_FTM0CLKPS_MASK << (n * 2) );
    switch(ptxn)
    {
    case  TCLK0:
        SIM->PINSEL |= (SIM_PINSEL_FTM0CLKPS(0) << (n * 2) );
        break;
    case  TCLK1:
        SIM->PINSEL |= (SIM_PINSEL_FTM0CLKPS(1) << (n * 2) );
        break;
    case  TCLK2:
        SIM->PINSEL |= (SIM_PINSEL_FTM0CLKPS(2) << (n * 2) );
        break;
    default:
        break;

    }
}

void ftm_pulse_init(FTMn_e ftmn, FTM_PS_e ps, PTXn_e ptxn)
{

    ftm_pulse_mux(ftmn, ptxn);


    ftmn->CNT = 0;
    ftmn->SC &=  ~(FTM_SC_PS_MASK | FTM_SC_CLKS_MASK);
    ftmn->SC |=   ( 0
                    | FTM_SC_PS(ps)
                    | FTM_SC_CLKS(3)      //外部时钟
                  );



}

uint16_t ftm_pulse_get(FTMn_e ftmn)
{
    return ftmn->CNT ;
}

void ftm_clean(FTMn_e ftmn)
{
    ftmn->CNT = 0 ;
}


