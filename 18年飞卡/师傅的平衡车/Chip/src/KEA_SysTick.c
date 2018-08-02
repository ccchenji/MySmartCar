/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_SysTick.c
 * @brief      SysTick ����������������ʱ
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-10-08
 */


#include "common.h"
#include "KEA_SysTick.h"
/*
Cortex-M4 ���ں��а���һ�� SysTick ʱ�ӡ�SysTick?Ϊһ��?24?λ�ݼ���������
SysTick �趨��ֵ��ʹ�ܺ�ÿ���� 1 ��ϵͳʱ�����ڣ�����ֵ�ͼ� 1��
������ 0 ʱ��SysTick �������Զ���װ��ֵ������������
ͬʱ�ڲ��� COUNTFLAG ��־����λ�������ж�(����ж�ʹ�������)��
*/



/* ----------------------------------------------------------------------------
   -- SysTick
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Peripheral SysTick
 * @{
 */

/** SysTick - Peripheral register structure */
typedef struct SysTick_MemMap {
  uint32_t CSR;                                    /**< SysTick Control and Status Register, offset: 0x0 */
  uint32_t RVR;                                    /**< SysTick Reload Value Register, offset: 0x4 */
  uint32_t CVR;                                    /**< SysTick Current Value Register, offset: 0x8 */
  uint32_t CALIB;                                  /**< SysTick Calibration Value Register, offset: 0xC */
} volatile *SysTick_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register accessors */
#define SysTick_CSR_REG(base)                    ((base)->CSR)
#define SysTick_RVR_REG(base)                    ((base)->RVR)
#define SysTick_CVR_REG(base)                    ((base)->CVR)
#define SysTick_CALIB_REG(base)                  ((base)->CALIB)

/*!
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SysTick Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Register_Masks SysTick Register Masks
 * @{
 */

/* CSR Bit Fields */
#define SysTick_CSR_ENABLE_MASK                  0x1u
#define SysTick_CSR_ENABLE_SHIFT                 0
#define SysTick_CSR_TICKINT_MASK                 0x2u
#define SysTick_CSR_TICKINT_SHIFT                1
#define SysTick_CSR_CLKSOURCE_MASK               0x4u
#define SysTick_CSR_CLKSOURCE_SHIFT              2
#define SysTick_CSR_COUNTFLAG_MASK               0x10000u
#define SysTick_CSR_COUNTFLAG_SHIFT              16
/* RVR Bit Fields */
#define SysTick_RVR_RELOAD_MASK                  0xFFFFFFu
#define SysTick_RVR_RELOAD_SHIFT                 0
#define SysTick_RVR_RELOAD(x)                    (((uint32_t)(((uint32_t)(x))<<SysTick_RVR_RELOAD_SHIFT))&SysTick_RVR_RELOAD_MASK)
/* CVR Bit Fields */
#define SysTick_CVR_CURRENT_MASK                 0xFFFFFFu
#define SysTick_CVR_CURRENT_SHIFT                0
#define SysTick_CVR_CURRENT(x)                   (((uint32_t)(((uint32_t)(x))<<SysTick_CVR_CURRENT_SHIFT))&SysTick_CVR_CURRENT_MASK)
/* CALIB Bit Fields */
#define SysTick_CALIB_TENMS_MASK                 0xFFFFFFu
#define SysTick_CALIB_TENMS_SHIFT                0
#define SysTick_CALIB_TENMS(x)                   (((uint32_t)(((uint32_t)(x))<<SysTick_CALIB_TENMS_SHIFT))&SysTick_CALIB_TENMS_MASK)
#define SysTick_CALIB_SKEW_MASK                  0x40000000u
#define SysTick_CALIB_SKEW_SHIFT                 30
#define SysTick_CALIB_NOREF_MASK                 0x80000000u
#define SysTick_CALIB_NOREF_SHIFT                31

/*!
 * @}
 */ /* end of group SysTick_Register_Masks */


/* SysTick - Peripheral instance base addresses */
/** Peripheral SysTick base pointer */
#define SysTick_BASE_PTR                         ((SysTick_MemMapPtr)0xE000E010u)
/** Array initializer of SysTick peripheral base pointers */
#define SysTick_BASE_PTRS                        { SysTick_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register instance definitions */
/* SysTick */
#define SYST_CSR                                 SysTick_CSR_REG(SysTick_BASE_PTR)
#define SYST_RVR                                 SysTick_RVR_REG(SysTick_BASE_PTR)
#define SYST_CVR                                 SysTick_CVR_REG(SysTick_BASE_PTR)
#define SYST_CALIB                               SysTick_CALIB_REG(SysTick_BASE_PTR)

/*!
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SysTick_Peripheral */



/*!
 *  @brief      SysTick��ʱ����
 *  @param      time          LPTMR��ʱʱ��(0~65535)
 *  @since      v5.0
 *  Sample usage:       systick_delay(32);     // systick ��ʱ32 ��ϵͳ����
 */
void systick_delay(uint32 time)
{
    if(time == 0)
    {
        return;
    }

    ASSERT(time <= (SysTick_RVR_RELOAD_MASK >> SysTick_RVR_RELOAD_SHIFT));  //24λ

    SYST_CSR = 0x00;                        //�ȹ��� systick ,���־λ

    SYST_RVR = time;                        //������ʱʱ��

    SYST_CVR = 0x00;                        //��ռ�����

    SYST_CSR = ( 0
                 | SysTick_CSR_ENABLE_MASK       //ʹ�� systick
                 //| SysTick_CSR_TICKINT_MASK    //ʹ���ж� (ע���˱�ʾ�ر��ж�)
                 | SysTick_CSR_CLKSOURCE_MASK    //ʱ��Դѡ�� ( core clk)
               );

    while( !(SYST_CSR & SysTick_CSR_COUNTFLAG_MASK));   //�ȴ�ʱ�䵽
}

/*!
 *  @brief      SysTick��ʱ����
 *  @param      ms          ��ʱʱ��
 *  @since      v5.0
 *  Sample usage:       systick_delay_ms(32);     // systick ��ʱ32 ms
 */
void systick_delay_ms(uint32 ms)
{
    while(ms--)
    {
        systick_delay(SYSTICK_CLK_KHZ);
    }
}

/*!
 *  @brief      SysTick��ʱ����
 *  @param      time          ��ʱʱ��(0~65535)
 *  @since      v5.0
 *  Sample usage:       systick_timing(32);     // systick ��ʱ 32 ��ϵͳ����
 */
void systick_timing(uint32 time)
{

    ASSERT(time <= (SysTick_RVR_RELOAD_MASK >> SysTick_RVR_RELOAD_SHIFT));  //24λ

    SYST_RVR = time;                        //������ʱʱ��

    //�������ȼ�
    NVIC_SetPriority (SysTick_IRQn, (1 << __NVIC_PRIO_BITS) - 1); /* set Priority for Cortex-M4 System Interrupts */

    SYST_CVR = 0x00;                        //��ռ�����

    SYST_CSR = ( 0
                 | SysTick_CSR_ENABLE_MASK       //ʹ�� systick
                 | SysTick_CSR_TICKINT_MASK      //ʹ���ж� (ע���˱�ʾ�ر��ж�)
                 | SysTick_CSR_CLKSOURCE_MASK    //ʱ��Դѡ�� ( core clk)
               );
}




