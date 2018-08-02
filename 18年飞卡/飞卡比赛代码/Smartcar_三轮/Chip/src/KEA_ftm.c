/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_ftm.c
 * @brief      FTM��ʱ��������
 * @author     ɽ��Ƽ�
 * @version    v5.2
 * @date       2014-10-31
 */


/*
 * ����ͷ�ļ�
 */
#include "common.h"
#include  "KEA_FTM.h"

#define FTMn(ftmn)     ( (uint32_t)(((ftmn)-FTM0)/(FTM1-FTM0) ) )



static uint32 ftm_mod[FTM_MAX];

/*!
 *  @brief      ��ʼ��FTM �Ķ˿�
 *  @param      FTMn_e    ģ��ţ�FTM0��  FTM1��  FTM2��
 *  @param      FTM_CHn_e     ͨ���ţ�CH0~CH7��
 *  @since      v5.0
 */
static void ftm_port_mux(FTMn_e ftmn, FTM_CHn_e ch)
{
    /******************* ����ʱ�� �� ����IO��*******************/
    switch((uint32_t)ftmn)
    {
    case (uint32_t)FTM0:
        SIM_SCGC |= SIM_SCGC_FTM0_MASK;     //ʹ��FTM0ʱ��
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
        SIM_SCGC |= SIM_SCGC_FTM1_MASK;       //ʹ��FTM1ʱ��
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
        SIM_SCGC |= SIM_SCGC_FTM2_MASK;           //ʹ��FTM2ʱ��

        switch(ch)
        {
        case  FTM_CH0:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS0_MASK;     //����գ�������
            if(FTM2_CH0_PIN == PTC0) SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS0(0);
            else if(FTM2_CH0_PIN == PTF0) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(2);
            else if(FTM2_CH0_PIN == PTH0) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS0(1);

            break;
        case  FTM_CH1:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS1_MASK;     //����գ�������
            if(FTM2_CH1_PIN == PTC1) SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS1(0);
            else if(FTM2_CH1_PIN == PTF1) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(2);
            else if(FTM2_CH1_PIN == PTH1) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS1(1);
            break;
        case  FTM_CH2:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS2_MASK;     //����գ�������
            if(FTM2_CH2_PIN == PTC2) SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS2(0);
            else if(FTM2_CH2_PIN == PTD0) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(1);
            else if(FTM2_CH2_PIN == PTG4) SIM->PINSEL1 |= SIM_PINSEL1_FTM2PS2(2);
            break;
        case  FTM_CH3:
            SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS3_MASK;     //����գ�������
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

//ʹ�ܶ�Ӧģ���ʱ��
static inline void ftm_enable_clk(FTMn_e ftmn)
{
    /******************* ����ʱ��*******************/
    BIT_SET(SIM_SCGC, (SIM_SCGC_FTM0_SHIFT + FTMn(ftmn)));
}

//ʹ�ܶ�Ӧģ����ж�
void ftm_enable_irq(FTMn_e ftmn)
{
    enable_irq((IRQn_t)(FTM0_IRQn + FTMn(ftmn)));     //ʹ��FTM0�ж�
}

//���ö�Ӧģ����ж�
void ftm_disable_irq(FTMn_e ftmn)
{
    disable_irq((IRQn_t)(FTM0_IRQn + FTMn(ftmn)));     //����FTM�ж�
}


void ftm_clear_overflag(FTMn_e ftmn)
{
    if(ftmn->SC  | FTM_SC_TOF_MASK)
    {
        ftmn->SC &=  ~FTM_SC_TOF_MASK;
    }
}

void  ftm_pwm_finit(FTMn_e ftmn, FTM_CHn_e ch, uint32 freq, float duty)  //��ʼ��FTM��PWM���ܲ�����Ƶ�ʡ�ռ�ձȡ�����ͨ�����ռ�ձȡ�ͬһ��FTM����ͨ����PWMƵ����һ���ģ���3��FTM(FX��4��)
{
    uint32 clk_hz ;
    uint16 mod;
    uint8  ps;
    uint16 cv;


    /******************* ����ʱ�� �� ����IO��*******************/
    ftm_port_mux(ftmn, ch);

    /*       ����Ƶ������        */
    //  �� CPWMS = 1 ����˫�߲�׽���壬�� PMWƵ�� =  busƵ�� /2 /(2^Ԥ��Ƶ����)/ģ��
    //  �� CPWMS = 0 �������߲�׽���壬�� PMWƵ�� =  busƵ��    /(2^Ԥ��Ƶ����)/ģ��
    //  EPWM������ ��MOD - CNTIN + 0x0001   (CNTIN ��Ϊ0)
    //  �����ȣ�CnV - CNTIN

    //  ģ�� MOD < 0x10000
    //  Ԥ��Ƶ���� PS  < 0x07
    //  Ԥ��Ƶ���� PS ԽСʱ��ģ�� mod ��Խ�󣬼�����Խ��׼��PWM�����Ϊ׼ȷ
    //  MOD  = clk_hz/(freq*(1 << PS)) < 0x10000  ==>  clk_hz/(freq*0x10000) < (1<< PS)  ==>  (clk_hz/(freq*0x10000) >> PS) < 1
    //  �� (((clk_hz/0x10000 )/ freq ) >> PS ) < 1

    // �� CPWMS = 0 �������߲�׽����Ϊ��
    clk_hz = (bus_clk_khz * 1000) ;     // busƵ��

    mod = (clk_hz >> 16 ) / freq ;      // ��ʱ�� mod ����һ��
    ps = 0;
    while((mod >> ps) >= 1)             // �� (mod >> ps) < 1 ���˳� while ѭ�� ������ PS ����Сֵ
    {
        ps++;
    }

    ASSERT(ps <= 0x07);                 // ���ԣ� PS ���Ϊ 0x07 ��������ֵ���� PWMƵ�����ù��ͣ��� Bus Ƶ�ʹ���

    mod = (clk_hz >> ps) / freq;        // �� MOD ��ֵ
    ftm_mod[FTMn(ftmn) ] = mod;

    cv = (uint16)((duty * (float)(mod - 0 + 1)) / 100);


    /******************** ѡ�����ģʽΪ ���ض���PWM *******************/
    //ͨ��״̬���ƣ�����ģʽ��ѡ�� ���ػ��ƽ
    FTM_CnSC_REG(ftmn, ch) &= ~FTM_CnSC_ELSA_MASK;
    FTM_CnSC_REG(ftmn, ch)  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;

    /******************** ����ʱ�Ӻͷ�Ƶ ********************/

    //MODE CNTIN �Ĵ�����FTM2����

    FTM_SC_REG(ftmn) = 0;

    FTM_MOD_REG(ftmn)   = mod;                        //ģ��, EPWM������Ϊ ��MOD - CNTIN + 0x0001
    if(ftmn == FTM2)
    {
        FTM_CNTIN_REG(ftmn) = 0;                          //��������ʼ��ֵ�����������ȣ�(CnV - CNTIN).
    }
    FTM_CnV_REG(ftmn, ch) = cv;
    FTM_CNT_REG(ftmn)   = 0;                          //��������ֻ�е�16λ���ã�д�κ�ֵ���˼Ĵ������������ CNTIN ��ֵ��

    FTM_SC_REG(ftmn)    = ( 0
                            //| FTM_SC_CPWMS_MASK         //0�������ؼ���ģʽ ��1�� �����ؼ���ģʽѡ�� ��ע���˱�ʾ 0��
                            | FTM_SC_PS(ps)             //��Ƶ���ӣ���Ƶϵ�� = 2^PS
                            | FTM_SC_CLKS(1)            //ʱ��ѡ��1��bus ʱ��
                            //| FTM_SC_TOIE_MASK        //����ж�ʹ�ܣ�ע���˱�ʾ ��ֹ����жϣ�
                          );

}

/*!
 *  @brief      ��ʼ��FTM ��PWM ����
 *  @param      FTMn_e    ģ��ţ�FTM0��  FTM1��  FTM2��
 *  @param      FTM_CHn_e     ͨ���ţ�CH0~CH7��
 *  @param      freq    Ƶ�ʣ���λΪHz��
 *  @param      duty    ռ�ձȷ��ӣ�ռ�ձ� = duty / FTMn_PRECISON
 *  @since      v5.0
 *  @note       ͬһ��FTM��PWMƵ���Ǳ���һ���ģ���ռ�ձȿɲ�һ������3��FTM�����������3����ͬƵ��PWM
 *  Sample usage:       ftm_pwm_init(FTM0, FTM_CH6,200, 10);    //��ʼ�� FTM0_CH6 Ϊ Ƶ�� 200Hz ��PWM��ռ�ձ�Ϊ 10/FTM0_PRECISON
 */
void ftm_pwm_init(FTMn_e ftmn, FTM_CHn_e ch, uint32 freq, uint32 duty)
{
    uint32 clk_hz ;
    uint16 mod;
    uint8  ps;
    uint16 cv;



    /******************* ����ʱ�� �� ����IO��*******************/
    ftm_port_mux(ftmn, ch);

    /*       ����Ƶ������        */
    //  �� CPWMS = 1 ����˫�߲�׽���壬�� PMWƵ�� =  busƵ�� /2 /(2^Ԥ��Ƶ����)/ģ��
    //  �� CPWMS = 0 �������߲�׽���壬�� PMWƵ�� =  busƵ��    /(2^Ԥ��Ƶ����)/ģ��
    //  EPWM������ ��MOD - CNTIN + 0x0001   (CNTIN ��Ϊ0)
    //  �����ȣ�CnV - CNTIN

    //  ģ�� MOD < 0x10000
    //  Ԥ��Ƶ���� PS  < 0x07
    //  Ԥ��Ƶ���� PS ԽСʱ��ģ�� mod ��Խ�󣬼�����Խ��׼��PWM�����Ϊ׼ȷ
    //  MOD  = clk_hz/(freq*(1 << PS)) < 0x10000  ==>  clk_hz/(freq*0x10000) < (1<< PS)  ==>  (clk_hz/(freq*0x10000) >> PS) < 1
    //  �� (((clk_hz/0x10000 )/ freq ) >> PS ) < 1

    // �� CPWMS = 0 �������߲�׽����Ϊ��
    clk_hz = (bus_clk_khz * 1000) ;     // busƵ��

    mod = (clk_hz >> 16 ) / freq ;      // ��ʱ�� mod ����һ��
    ps = 0;
    while((mod >> ps) >= 1)             // �� (mod >> ps) < 1 ���˳� while ѭ�� ������ PS ����Сֵ
    {
        ps++;
    }

    ASSERT(ps <= 0x07);                 // ���ԣ� PS ���Ϊ 0x07 ��������ֵ���� PWMƵ�����ù��ͣ��� Bus Ƶ�ʹ���

    mod = (clk_hz >> ps) / freq;        // �� MOD ��ֵ

    switch((uint32_t)ftmn)                        // ��ֵ CNTIN ��Ϊ0 �������ȣ�CnV - CNTIN ���� CnV ���� �������ˡ�
    {
        // EPWM������ �� MOD - CNTIN + 0x0001 == MOD - 0 + 1
        // �� CnV = (MOD - 0 + 1) * ռ�ձ� = (MOD - 0 + 1) * duty/ FTM_PRECISON
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

    /******************** ѡ�����ģʽΪ ���ض���PWM *******************/
    //ͨ��״̬���ƣ�����ģʽ��ѡ�� ���ػ��ƽ
    FTM_CnSC_REG(ftmn, ch) &= ~FTM_CnSC_ELSA_MASK;
    FTM_CnSC_REG(ftmn, ch)  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
    // MSnB:MSnA = 1x       ���ض���PWM
    // ELSnB:ELSnA = 10     �ȸߺ��
    // ELSnB:ELSnA = 11     �ȵͺ��

    /******************** ����ʱ�Ӻͷ�Ƶ ********************/
    //FTM_FMS_REG(FTMN[ftmn]) |=FTM_FMS_WPEN_MASK;

    //MODE CNTIN �Ĵ�����FTM2����

    FTM_SC_REG(ftmn) = 0;

    FTM_MOD_REG(ftmn)   = mod;                        //ģ��, EPWM������Ϊ ��MOD - CNTIN + 0x0001
    if(ftmn == FTM2)
    {
        FTM_CNTIN_REG(ftmn) = 0;                          //��������ʼ��ֵ�����������ȣ�(CnV - CNTIN).
    }
    FTM_CnV_REG(ftmn, ch) = cv;
    FTM_CNT_REG(ftmn)   = 0;                          //��������ֻ�е�16λ���ã�д�κ�ֵ���˼Ĵ������������ CNTIN ��ֵ��

    FTM_SC_REG(ftmn)    = ( 0
                            //| FTM_SC_CPWMS_MASK         //0�������ؼ���ģʽ ��1�� �����ؼ���ģʽѡ�� ��ע���˱�ʾ 0��
                            | FTM_SC_PS(ps)             //��Ƶ���ӣ���Ƶϵ�� = 2^PS
                            | FTM_SC_CLKS(1)            //ʱ��ѡ��1��bus ʱ��
                            //| FTM_SC_TOIE_MASK        //����ж�ʹ�ܣ�ע���˱�ʾ ��ֹ����жϣ�
                          );


}

/*!
 *  @brief      ����FTM ��PWM ͨ��ռ�ձ�
 *  @param      FTMn_e    ģ��ţ�FTM0��  FTM1��  FTM2��
 *  @param      FTM_CHn_e     ͨ���ţ�CH0~CH7��
 *  @param      duty    ռ�ձȷ��ӣ�ռ�ձ� = duty / FTMn_PRECISON
 *  @since      v5.0
 *  @note       ͬһ��FTM��PWMƵ���Ǳ���һ���ģ���ռ�ձȿɲ�һ������3��FTM�����������3����ͬƵ��PWM
 *  Sample usage:       ftm_pwm_duty(FTM0, FTM_CH6, 10);    //���� FTM0_CH6ռ�ձ�Ϊ 10/FTM0_PRECISON
 */
void ftm_pwm_duty(FTMn_e ftmn, FTM_CHn_e ch, uint32 duty)
{
    uint32 cv;
    uint32 mod = 0;
#ifdef DEBUG_MODE
    switch((uint32_t)ftmn)
    {
        //����˴�����ʧ�ܣ�˵��ռ�ձȳ��� 100% ��������м���Ƿ�����������
    case (uint32_t)FTM0:
        ASSERT(duty <= FTM0_PRECISON);     //�ö��Լ�� ռ�ձ��Ƿ����
        break;

    case (uint32_t)FTM1:
        ASSERT(duty <= FTM1_PRECISON);     //�ö��Լ�� ռ�ձ��Ƿ����
        break;
    case (uint32_t)FTM2:
        ASSERT(duty <= FTM2_PRECISON);     //�ö��Լ�� ռ�ձ��Ƿ����
        break;

    default:
        ASSERT(0);
        break;
    }

#else
    //��ֹ��DEBUGģʽ�£�����ռ�ձȳ���100%
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

    //ռ�ձ� = (CnV-CNTIN)/(MOD-CNTIN+1
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

    // ����FTMͨ��ֵ
    FTM_CnV_REG(ftmn, ch) = cv;

    //��������ֻ�е�16λ���ã�д�κ�ֵ���˼Ĵ������������ CNTIN ��ֵ��
}
/*!
 *  @brief      ����FTM ��PWM ͨ��ռ�ձ�
 *  @param      FTMn_e    ģ��ţ�FTM0��  FTM1��  FTM2��
 *  @param      FTM_CHn_e     ͨ���ţ�CH0~CH7��
 *  @param      duty    ռ�ձȷ��ӣ�ռ�ձ� = duty %
 *  @since      v5.0
 *  @note       ͬһ��FTM��PWMƵ���Ǳ���һ���ģ���ռ�ձȿɲ�һ������3��FTM�����������3����ͬƵ��PWM
 *  Sample usage:       ftm_pwm_fduty(FTM0, FTM_CH6, 10);    //���� FTM0_CH6ռ�ձ�Ϊ 10%
 */
void ftm_pwm_fduty(FTMn_e ftmn, FTM_CHn_e ch, float duty)
{
    uint32 cv;
    uint32 mod = 0;
#ifdef DEBUG_MODE

    ASSERT(duty <= 100.0);     //�ö��Լ�� ռ�ձ��Ƿ����


#else
    //��ֹ��DEBUGģʽ�£�����ռ�ձȳ���100%
    if(duty > 100.0)
    {
        duty = 100.0;
    }
#endif

    duty = duty/100.0;
    //ռ�ձ� = (CnV-CNTIN)/(MOD-CNTIN+1
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

    // ����FTMͨ��ֵ
    FTM_CnV_REG(ftmn, ch) = cv;

    //��������ֻ�е�16λ���ã�д�κ�ֵ���˼Ĵ������������ CNTIN ��ֵ��
}


/*!
 *  @brief      ����FTM��Ƶ��
 *  @param      freq    Ƶ�ʣ���λΪHz��
 *  @since      v5.0
 *  @note       �޸�PWMƵ�ʺ󣬱������ ftm_pwm_duty ��������ռ�ձȡ�ͬһ��ģ�飬PWMƵ�ʱ�����ͬ��
 *  Sample usage:       ftm_pwm_freq(FTM0,200);    //���� FTM0 �� Ƶ�� Ϊ 200Hz
 */
void ftm_pwm_freq(FTMn_e ftmn, uint32 freq)             //����FTM��Ƶ��
{
    uint32 clk_hz = (bus_clk_khz * 1000) >> 1;        //busƵ��/2
    uint32 mod;
    uint8 ps;

    /*       ����Ƶ������        */
    // �� CPWMS = 0 �������߲�׽����Ϊ��
    clk_hz = (bus_clk_khz * 1000) ;     // busƵ��

    mod = (clk_hz >> 16 ) / freq ;      // ��ʱ�� mod ����һ��
    ps = 0;
    while((mod >> ps) >= 1)             // �� (mod >> ps) < 1 ���˳� while ѭ�� ������ PS ����Сֵ
    {
        ps++;
    }

    ASSERT(ps <= 0x07);                 // ���ԣ� PS ���Ϊ 0x07 ��������ֵ���� PWMƵ�����ù��ͣ��� Bus Ƶ�ʹ���

    mod = (clk_hz >> ps) / freq;        // �� MOD ��ֵ

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

    /******************** ����ʱ�Ӻͷ�Ƶ ********************/
    FTM_SC_REG(ftmn)    = ( 0
                            //| FTM_SC_CPWMS_MASK         //0�������ؼ���ģʽ ��1�� �����ؼ���ģʽѡ�� ��ע���˱�ʾ 0��
                            | FTM_SC_PS(ps)             //��Ƶ���ӣ���Ƶϵ�� = 2^PS
                            | FTM_SC_CLKS(1)            //ʱ��ѡ�� 0��ûѡ��ʱ�ӣ����ã� 1��bus ʱ�ӣ� 2��MCGFFCLK�� 3��EXTCLK�� ��SIM_SOPT4 ѡ������ܽ� FTM_CLKINx��
                            //| FTM_SC_TOIE_MASK        //����ж�ʹ�ܣ�ע���˱�ʾ ��ֹ����жϣ�
                          );
    FTM_CNTIN_REG(ftmn) = 0;      //��������ʼ��ֵ�����������ȣ�(CnV - CNTIN).
    FTM_MOD_REG(ftmn)   = mod;    //ģ��, EPWM������Ϊ ��MOD - CNTIN + 0x0001
    FTM_CNT_REG(ftmn)   = 0;      //��������ֻ�е�16λ���ã�д�κ�ֵ���˼Ĵ������������ CNTIN ��ֵ��
}

//////////////////////////////// ����Ϊ���PWM  //////////////////////////////////////////


//////////////////////////////// ����Ϊ���벶׽ //////////////////////////////////////////

/*!
 *  @brief      ���벶׽��ʼ������
 *  @param      FTMn_e          ģ��ţ�FTM0��  FTM1��  FTM2��
 *  @param      FTM_CHn_e       ͨ���ţ�CH0~CH7��
 *  @param      FTM_Input_cfg   ���벶׽������������
 *  @param      FTM_PS_e        ��Ƶ����
 *  @since      v5.0
 *  @note       ͬһ��FTM��ֻ�ܸ�һ����������벶׽��Ͳ�Ҫ�������������ܣ�����PWM��
 *  Sample usage:       ftm_input_init(FTM0, FTM_CH0, FTM_Rising,FTM_PS_2);    //���� FTM0_CH0�����ش������벶׽������Ƶ
 */
void ftm_input_init(FTMn_e ftmn, FTM_CHn_e ch, FTM_Input_cfg cfg, FTM_PS_e ps)
{
    ASSERT(  (ftmn == FTM2) );  //��鴫�ݽ�����ͨ���Ƿ���ȷ (�Ĵ������ã�ò��ֻ��FTM2���������벶׽�Ĺ���)

    /******************* ����ʱ�� �� ����IO��*******************/
    ftm_port_mux(ftmn, ch);

    /******************* ����Ϊ���벶׽���� *******************/
    switch(cfg)
    {
        //���벶׽ģʽ�£�DECAPEN = 0 �� DECAPEN = 0 ��CPWMS = 0�� MSnB:MSnA = 0

        // ELSnB:ELSnA         1          10          11
        // ����             ������      �½���      ������

    case FTM_Rising:    //�����ش���
        FTM_CnSC_REG(ftmn, ch) |=  ( FTM_CnSC_ELSA_MASK  | FTM_CnSC_CHIE_MASK );                   //��1
        FTM_CnSC_REG(ftmn, ch) &= ~( FTM_CnSC_ELSB_MASK  | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK); //��0
        break;

    case FTM_Falling:   //�½��ش���
        FTM_CnSC_REG(ftmn, ch) |= (FTM_CnSC_ELSB_MASK  | FTM_CnSC_CHIE_MASK );                    //��1
        FTM_CnSC_REG(ftmn, ch) &= ~( FTM_CnSC_ELSA_MASK | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK); //��0
        break;

    case FTM_Rising_or_Falling: //�����ء��½��ض�����
        FTM_CnSC_REG(ftmn, ch) |=  ( FTM_CnSC_ELSB_MASK | FTM_CnSC_ELSA_MASK  | FTM_CnSC_CHIE_MASK ); //��1
        FTM_CnSC_REG(ftmn, ch) &= ~( FTM_CnSC_MSB_MASK  | FTM_CnSC_MSA_MASK); //��0
        break;
    }

    FTM_SC_REG(ftmn) = 0;
    FTM_MODE_REG(ftmn)  =    (0
                              | FTM_MODE_WPDIS_MASK  //д������ֹ
                              //| FTM_MODE_FTMEN_MASK   //ʹ�� FTM
                             );


    FTM_COMBINE_REG(ftmn) = 0;
    //FTM_MODE_REG(FTMN[ftmn])    &= ~FTM_MODE_FTMEN_MASK;    //ʹ��FTM
    FTM_CNTIN_REG(ftmn)   = 0;

    FTM_STATUS_REG(ftmn)  = 0x00;               //���жϱ�־λ

    FTM_MOD_REG(ftmn)     = FTM_MOD_MOD_MASK;

    FTM_SC_REG(ftmn) = ( 0
                         | FTM_SC_CLKS(0x1)       //ѡ�� bus ʱ��
                         | FTM_SC_PS(ps)          //ѡ�� ��Ƶϵ��
                       );

    FTM_MODE_REG(ftmn)  |=    (0
                               //| FTM_MODE_WPDIS_MASK  //д������ֹ
                               | FTM_MODE_FTMEN_MASK   //ʹ�� FTM
                              );

    //�������벶׽�ж�
    //enable_irq(FTM0_IRQn + ftmn);
}

/*!
 *  @brief      ���벶׽��ʼ������
 *  @param      FTMn_e          ģ��ţ�FTM0��  FTM1��  FTM2��
 *  @param      FTM_CHn_e       ͨ���ţ�CH0~CH7��
 *  @param      FTM_Input_cfg   ���벶׽������������
 *  @return     ��ȡ��׽�¼�����ʱ�ļ�����ֵ (�������β�׽֮��Ĳ�ֵ���ж�����Ƶ��)
 *  @since      v5.0
 *  Sample usage:       uint16 data = ftm_input_get (FTM0, FTM_CH0) ;   // ��ȡFTM0_CH0���벶׽�¼�����ʱ�ļ���ֵ
 */
uint16   ftm_input_get (FTMn_e ftmn, FTM_CHn_e ch)
{
    return (uint16)FTM_CnV_REG(ftmn, ch);   //����
}

void     ftm_input_clean (FTMn_e ftmn)
{
    FTM_CNT_REG(ftmn) = 0;               //�� ����������ֵ
}


/*!
 *  @brief      FTM�����жϷ�����
 *  @since      v5.0
 *  @warning    �˺�����Ҫ�û������Լ�������ɣ�����������ṩһ��ģ��
 *  Sample usage:       set_vector_handler(FTM0_IRQn , FTM1_Input_test_handler);    //�� FTM1_Input_test_handler ������ӵ��ж�����������Ҫ�����ֶ�����
 */
void ftm2_Input_test_handler(void)
{
    uint8 s = FTM2_STATUS;             //��ȡ��׽�ͱȽ�״̬  All CHnF bits can be checked using only one read of STATUS.
    uint8 CHn;

    FTM2_STATUS = 0x00;             //���жϱ�־λ

    CHn = 0;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_DIS(FTM2, CHn);     //��ֹ���벶׽�ж�
        /*     �û�����       */

        /*********************/
        //FTM_IRQ_EN(FTM2, CHn); //�������벶׽�ж�

    }

    /* ������� n=1 ��ģ�棬����ģ������� */
    CHn = 1;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_EN(FTM2, CHn); //�������벶׽�ж�
        /*     �û�����       */


        /*********************/
        //�����������￪�����벶׽�ж�
        //FTM_IRQ_EN(FTM2, CHn); //�������벶׽�ж�
    }
}

//////////////////////////////// ����Ϊ���벶׽  //////////////////////////////////////////

//////////////////////////////// ����Ϊ�ⲿ����������� //////////////////////////////////////////
//����Ƶ�ʽϸ�ʱ�����÷�Ƶ����
//�����ŷķ�����ֿ�©����ģ���Ҫ����������port_pull(FTM0_PULSE_PIN,PULLUP_ENBLE);
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
                    | FTM_SC_CLKS(3)      //�ⲿʱ��
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


