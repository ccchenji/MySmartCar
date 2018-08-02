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
 * @version    v5.1
 * @date       2014-04-25
 */


#ifndef _KEA_FTM_H_
#define _KEA_FTM_H_

#define  FTM_MAX   3
typedef FTM_Type    *FTMn_e;



//����FTM ͨ����
typedef enum
{

    FTM_CH0,
    FTM_CH1,
    FTM_CH2,
    FTM_CH3,
    FTM_CH4,
    FTM_CH5,
    FTM_CH6,
    FTM_CH7,

} FTM_CHn_e;

//��Ƶϵ��
typedef enum
{
    FTM_PS_1,
    FTM_PS_2,
    FTM_PS_4,
    FTM_PS_8,
    FTM_PS_16,
    FTM_PS_32,
    FTM_PS_64,
    FTM_PS_128,

    FTM_PS_MAX,
} FTM_PS_e;     //��Ƶֵ =  (1<< FTM_PS_e) ,����  FTM_PS_2  ��Ӧ�� ��Ƶֵ = (1<<FTM_PS_2) = (1<<1) = 2

extern FTM_MemMapPtr FTMN[FTM_MAX];

/*********************** PWM **************************/

//���ȣ����������ڵķ�ĸ��ֻҪ�������Ҫ�� mod ����ϡ�͵��Ϳ�����
#define FTM0_PRECISON 1000u     //����ռ�ձȾ��ȣ�100������Ϊ1%��1000u�򾫶�Ϊ0.1%������ռ�ձ� duty �βδ��룬��ռ�ձ�Ϊ duty/FTM_PRECISON
#define FTM1_PRECISON 1000u     //����ռ�ձȾ��ȣ�100������Ϊ1%��1000u�򾫶�Ϊ0.1%������ռ�ձ� duty �βδ��룬��ռ�ձ�Ϊ duty/FTM_PRECISON
#define FTM2_PRECISON 1000u     //����ռ�ձȾ��ȣ�100������Ϊ1%��1000u�򾫶�Ϊ0.1%������ռ�ձ� duty �βδ��룬��ռ�ձ�Ϊ duty/FTM_PRECISON

extern void  ftm_pwm_init (FTMn_e, FTM_CHn_e, uint32 freq, uint32 duty);  //��ʼ��FTM��PWM���ܲ�����Ƶ�ʡ�ռ�ձȡ�����ͨ�����ռ�ձȡ�ͬһ��FTM����ͨ����PWMƵ����һ���ģ���3��FTM(FX��4��)
extern void  ftm_pwm_duty (FTMn_e, FTM_CHn_e,              uint32 duty);  //����ͨ��ռ�ձ�,ռ�ձ�Ϊ ��duty * ���ȣ� % ����� FTM_PRECISON ����Ϊ 1000 ��duty = 100 ����ռ�ձ� 100*0.1%=10%

//�·��Ǹ������ģ����Ա��⿼�Ǿ������õ�����
extern void  ftm_pwm_finit(FTMn_e, FTM_CHn_e, uint32 freq, float duty) ;
extern void  ftm_pwm_fduty(FTMn_e, FTM_CHn_e,              float duty);  //����ͨ��ռ�ձ�,ռ�ձ�Ϊ duty%

extern void  ftm_pwm_freq (FTMn_e,            uint32 freq);               //����FTM��Ƶ�ʣ���Ƶ�ʺ���Ҫ��������ռ�ձȣ�


/*********************** ���벶׽ **************************/
//FTM ���벶׽����
typedef enum
{
    FTM_Rising,               //�����ز�׽
    FTM_Falling,              //�½��ز�׽
    FTM_Rising_or_Falling     //�����ز�׽
} FTM_Input_cfg;


extern void     ftm_input_init  (FTMn_e, FTM_CHn_e, FTM_Input_cfg, FTM_PS_e ps);    //���벶׽��ʼ������
extern uint16   ftm_input_get   (FTMn_e, FTM_CHn_e);                                //���벶׽ģʽ�£���ȡ��׽�¼�����ʱ�ļ�����ֵ(�������β�׽֮��Ĳ�ֵ���ж�����Ƶ��)
extern void     ftm_input_clean (FTMn_e );                                          //��ռ�������ֵ

extern void     FTM1_Input_test_handler(void);                      //�ɹ��ο��� FTM1 ���벶׽�жϷ�����

#define FTM_IRQ_EN(FTMn,CHn)        FTM_CnSC_REG(FTMN[FTMn],CHn) |= FTM_CnSC_CHIE_MASK       //���� FTMn_CHn �ж�
#define FTM_IRQ_DIS(FTMn,CHn)       FTM_CnSC_REG(FTMN[FTMn],CHn) &= ~FTM_CnSC_CHIE_MASK      //�ر� FTMn_CHn �ж�

void ftm_enable_irq(FTMn_e ftmn);
void ftm_clear_overflag(FTMn_e ftmn);
void ftm_clean(FTMn_e ftmn);

void     ftm_pulse_init(FTMn_e ftmn, FTM_PS_e ps, PTXn_e tclk_ptxn);
uint16_t ftm_pulse_get(FTMn_e ftmn);

void    ftm_pulse_mux(FTMn_e ftmn, PTXn_e ptxn);

#define ftm_pulse_clean(ftmn)       ftm_clean(ftmn)

#define ftm_pulsing_clean(ftmn)       ftm_clean(ftmn)
#define ftm_timing_clean(ftmn)       ftm_clean(ftmn)



#endif  //_KEA_FTM_H_



