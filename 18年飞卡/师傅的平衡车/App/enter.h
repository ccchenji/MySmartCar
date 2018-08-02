#ifndef _ENTER_H_
#define _ENTER_H_
#include "stdint.h"

#define FWD_VER     601                     // �̼��汾�� �������޸ģ��������ϲ�ʶ��
#define FWD_FLAG    0x5AA5                  // �̼���� �������޸ģ�
#define FWD_ADDR   (0x1A0)                  // �̼���ַ �������޸ģ�

typedef struct
{
    uint16_t    flag;                   //���
    uint16_t    ver;                    //�汾

    //�ֿ�
    uint8_t    *ascii_6x12;             //Ӣ���ֿ�      ��6x12
    uint8_t    *ascii_8x16;             //Ӣ���ֿ�      ��8x16

    //�ַ��� ���� ת��
    void       *sprintf;                //int       sprintf         (char *buf, const char *fmt, ...) ;          //�ַ�����ʽ����������
    void       *printf;                 //void      printf          (fp,fmt, ...);                               //�ַ�����ʽ�������ָ���˿� fp ������Ϊ���ڣ�
    void       *atoi;                   //int       atoi            (char *str);                                //�ַ���ת������
    void       *itoa;                   //char *    itoa            (int n, char * chBuffer);                   //����ת��Ϊ�ַ���
    void       *ftoa;                   //char *    ftoa            (double dValue, char * chBuffer);           //����ת��Ϊ�ַ���
    void       *ftoan;                  //char *    ftoan            (double dValue, char * chBuffer,int ndigits);//����ת��Ϊ�ַ���(֧��ָ��С����λ��)

    //����С����
    void       *memcpy;                 //void *    memcpy  ( uint8_t *dst, uint8_t *src, uint32_t count);      //�ڴ渴��
    void       *memset;                 //void *    memset  (void *src, int c, int count);                      //�ڴ�������ֵ
    void       *strlen;                 //int       strlen(const char * str);                                   //���ַ����ĳ���

    //flash API
    void       *flash_init;             //void      flash_init          ();                                     //��ʼ��Flash
    void       *flash_erase_sector;     //uint8_t   flash_erase_sector  (uint16_t sectorNum);                     //����ָ��flash����
    void       *flash_write;            //uint8_t   flash_write         (uint16_t sectorNum, uint16_t offset, FLASH_WRITE_TYPE data);       //д��flash����
    void       *flash_write_buf;        //uint8_t   flash_write_buf     (uint16_t sectorNum, uint16_t offset, uint16_t cnt, uint8 buf[]);     //�ӻ�����д��flash����
    //����һ��flash API�ӿڣ�                        flash_read          (sectorNum,offset,type)                  //��ȡָ����ַ������

    //flash �洢����
    void       *flash_data_init;        //void      flash_data_init     (flash_data_t *d);                      //�Խṹ�����ݽ���Ԥ������flash�����ݻ�û��ʼ����������flash
    void       *flash_data_reset;       //void      flash_data_reset    (flash_data_t *d);                      //����flash�����ǶԴ洢���ݽ������
    void       *flash_data_load;        //uint8_t   flash_data_load     (flash_data_t *d);                      //�� flash ��������
    void       *flash_data_save;        //uint8_t   flash_data_save     (flash_data_t *d);                      //�������ݵ�flash


    //SPI ͨ��
    void       *spi_init;               //uint32_t  spi_init       (SPIn_e, PTXn_e pcs, SPI_CFG,uint32 baud,uint32 bus_khz,char use_pin_mode); //SPI��ʼ����ѡ��Ƭѡ�źţ�����ģʽ��������  (Ŀǰ��֧������ģʽ)
    void       *spi_set_baud;           //uint32_t  spi_set_baud   (SPIn_e,                     uint32 baud,uint32 bus_khz);
    void       *spi_mosi;               //void spi_mosi       (SPIn_e, PTXn_e pcs,                              uint8 *modata, uint8 *midata,               uint32 len);    //SPI���ͽ��պ���,����databuff���ݣ����ѽ��յ������ݴ����databuff��(ע�⣬�Ḳ��ԭ����databuff)
    void       *spi_mosi_cmd;           //void spi_mosi_cmd   (SPIn_e, PTXn_e pcs, uint8 *mocmd , uint8 *micmd , uint8 *modata, uint8 *midata, uint32 cmdlen , uint32 len); //SPI���ͽ��պ���,��spi_mosi��ȣ������ȷ���cmd �������Ĳ��裬���ֿ������ַ���

    //PWT�����Ȳ���
    void       *pwt_pulse_init;         //void     pwt_pulse_init     (PWT_INn_e INn,  uint32_t cfg);
    //Cycleʱ��ȡ���������
    void       *pwt_pulse_get;          //uint16_t pwt_pulse_get     (PWT_INn_e INn);

    //Dutyʱ��ȡ��������2�����ȶ��������־λ���ٶ���
    void       *pwt_pulse_pos_get;      //uint16_t pwt_pulse_pos_get(PWT_INn_e INn);  //������
    void       *pwt_pulse_neg_get;      //uint16_t pwt_pulse_neg_get(PWT_INn_e INn);  //������

    //KBI �����ж�
    void       *kbi_init;               //void kbi_init (PTXn_e ch, uint8_t cfg);           //chΪPTA0~D7ʱ��ΪKBI0ģ�飬PTE0~H7ʱ��ΪKBI1ģ�顣ͬһ��ģ�飬����Ҫ��ͬ�����ô�����ʽ�����ʱ���Ƽ��� kbi_allinit��
    void       *kbi_allinit;            //void kbi_allinit (uint64_t ch_mask, uint8_t cfg); // ch_mask Ϊ (1<<ch),���ͨ��ʱ���� | ����

    //irq �ⲿ�ж�
    void       *irq_init;               //void irq_init  (PTXn_e, uint8_t cfg);         //����Ϊ PTI0~I6 (ԭ����A5����Ϊ��λ�ڣ�������)��ͬһʱ�䣬ֻ������һ�������ܶ��ͬʱ�á�

    //FTM ��ʱ�жϣ����Ʋ������������ã��˷�FTM��
    void       *ftm_timing_init;        //void ftm_timing_init(FTMn_e ftmn,uint16_t counttime,FTM_PS_e ps);  //��timer_clk���ڼ�ʱ�Ķ�ʱ�жϺ���

    //FTM �����ж�(�����ã�һ�㳣�õ��Ƕ�ʱ����������)
    void       *ftm_pulsing_init;               //void ftm_pulsing_init(FTMn_e ftmn,uint16_t counttime,FTM_PS_e ps,PTXn_e tclk_ptxn);  //�������������Ķ��������жϺ���

    //ִ����APP API�ӿ� ������ͨ�� �������ò�ͬ������ĺ���������ջ��ַ��
    void       *jmp_app;                //void      jmp_app             (uint32_t sp, uint32_t pc);          //��ת���µ�APP
    void       *jmp_bin;                //void      jmp_bin             (uint32_t addr);                     //��ת���µ�APP BIN�ļ� ��bin�ļ��ĵ�1��32λ������ջ��ַ����2��32λ����������������ڣ�


} mydata_in_t;




//�ڲ��ã��û������ע
#define     OFFSET(type, member)                (uint32)(&(((type *)0)->member))
#define     IN_ADDR(member)                     (*((uint32_t *)(FWD_ADDR + OFFSET(mydata_in_t, member)) ))
#define     ENTER_FUN(func,...)                 (*(func##_t)(IN_ADDR(func)))(##__VA_ARGS__)
#define     ENTER_FUN_ADDR(func,...)       (*(func##_t)(func##_addr))(##__VA_ARGS__)
#define     ENTER_FUN_ADDR0(func,...)       (*(func##_t)(func##_addr))(##__VA_ARGS__)


#ifndef FWD_LIB
#define  enter_init()      (((uint16_t)IN_ADDR(flag)==FWD_FLAG) && (uint16_t)IN_ADDR(ver)==FWD_VER)      //�����жϹ̼��ļ��Ƿ���� ,APP��Ҫ��ʼ��ʱִ�� ASSERT(enter_init());

//ϵͳ����        ************************************************
extern int core_clk_khz;
extern int core_clk_mhz;
extern int bus_clk_khz;
extern int timer_clk_khz;

#define ASCII12        ((uint8_t *)(IN_ADDR(ascii_6x12)))
#define ASCII16        ((uint8_t *)(IN_ADDR(ascii_8x16)))

#include "KEA_port.h"
#include "KEA_ftm.h"


//Flash ͷ�ļ�     ************************************************
#define     FLASH_SECTOR_SIZE       (512)                //������С Ϊ 512 �ֽ�
#define     FLASH_SECTOR_NUM        (256)                   //������

#define     FLASH_ALIGN_ADDR        4                       //��ַ����������
typedef     uint32_t               FLASH_WRITE_TYPE;       //flash_write ����д�� ����������

#define     flash_read(sectorNo,offset,type)        (*(type *)((uint32)(((sectorNo)*FLASH_SECTOR_SIZE) + (offset))))          //��ȡ����
#define     flash_read_addr(addr,type)              (*(type *)((uint32)(addr)))          //��ȡָ����ַ


typedef struct
{
    uint16_t    sectornum_start;            //��ʼ������
    uint16_t    sectornum_end;              //����������
    void      *data_addr;                   //���ݵĵ�ַ
    uint16_t    data_size;                  //���ݵĳߴ�
    uint16_t    res1;                       //�������ײ�ʹ�� ����ɾ��
    uint32_t    res2[2];                    // �������ײ�ʹ�� ����ɾ��


} flash_data_t;

//SPI ͷ�ļ�     ************************************************
/**
 *  @brief ���ӻ�ģʽ
 */
typedef enum
{
    //����ģʽѡ������ 2ѡ1
    SLAVE = (0 << SPI_C1_MSTR_SHIFT),    //�ӻ�ģʽ  (��֧�ִ�ģʽ)
    MASTER = (1 << SPI_C1_MSTR_SHIFT) ,  //����ģʽ

    //ʱ��ģʽѡ������ 4 ѡ 1
    CPOL_CPHA_00  = (0 << SPI_C1_CPHA_SHIFT) ,
    CPOL_CPHA_01  = (1 << SPI_C1_CPHA_SHIFT) ,
    CPOL_CPHA_10  = (2 << SPI_C1_CPHA_SHIFT) ,
    CPOL_CPHA_11  = (3 << SPI_C1_CPHA_SHIFT) ,



} SPI_CFG;

/**
 *  @brief SPIģ���
 */
#define  SPI_MAX   2
typedef SPI_Type *SPIn_e ;


//PWT ͷ�ļ�     ************************************************

//���� PWT ͨ����
typedef enum
{
    PWT_IN0,
    PWT_IN1,

} PWT_INn_e;

//��Ƶϵ��
typedef enum
{
    PWT_PS_1,
    PWT_PS_2,
    PWT_PS_4,
    PWT_PS_8,
    PWT_PS_16,
    PWT_PS_32,
    PWT_PS_64,
    PWT_PS_128,

    PWT_PS_MAX,
} PWT_PS_e;

#define PWT_PS_CFG(ps)      PWT_R1_PRE(ps)


#define PWT_IS_OVER()     (PWT_R1_PWTOV_MASK & PWT_R1)
#define PWT_IS_READY()     (PWT_R1_PWTRDY_MASK & PWT_R1)


#define PWT_CLEAR_OVER()    PWT_R1 &= ~PWT_R1_PWTOV_MASK
#define PWT_CLEAR_READY()    PWT_R1 &= ~PWT_R1_PWTRDY_MASK

typedef enum
{
    Pwt_Null                = 0,
    Pwt_Disable             = 1,                //ͣ��PWT
    Pulse_Over_Enable_irq   = PWT_R1_POVIE_MASK | PWT_R1_PWTIE_MASK   ,       //���������������ж� ��0xFFFF to 0x0000.��
    Pulse_Width_Enable_irq  = PWT_R1_PRDYIE_MASK | PWT_R1_PWTIE_MASK   ,      //������Ȳ����ж�

    Cycle_Falling     = PWT_R1_EDGE(0)   ,  //���ڲ���������2���½���Ϊ�����Ŀ��
    Cycle_Rising     = PWT_R1_EDGE(3)   ,  //���ڲ���������2��������Ϊ�����Ŀ��

    Duty_Rising      = PWT_R1_EDGE(1)   , //ռ�ձȲ���������2��ֵ����һ�������ؿ�ʼ���������ȣ��ڶ������������ڣ�2��������֮��Ŀ�ȣ�
    Duty_Falling      = PWT_R1_EDGE(2)   , //ռ�ձȲ���������2��ֵ����һ���½��ؿ�ʼ�ĸ������ȣ��ڶ������������ڣ�2���½���֮��Ŀ�ȣ�

} PWT_CFG_e;

//KBI ͷ�ļ�     ************************************************

typedef enum
{
    //�����ֵ���ܸģ�����
    KBI_IRQ_DIS        = (0),   //����

    KBI_PULLUP_DIS  = (1 << 4),      //�����������
    KBI_PULLUP_EN   = (2 << 4),      //��������ʹ��

    KBI_FALLING     = (1 << 0),      //�½��� ����
    KBI_RISING      = (2 << 0),      //������ ����

    KBI_ZERO        = (1 << 2) ,     //�͵�ƽ ���� (���½���)
    KBI_ONE         = (2 << 2)       //�ߵ�ƽ ���� (��������)


} KBI_CFG;


static KBI_MemMapPtr KBIn[] = KBI_BASE_PTRS;        //???????����������⴦��

//�ж�ʹ�ܺͽ�ֹ
#define kbi_enable_irq(KBIx_Pn)         enable_irq((IRQn_t)(KBI0_IRQn + GPX(KBIx_Pn)))
#define kbi_disable_irq(KBIx_Pn)        disable_irq((IRQn_t)(KBI0_IRQn + GPX(KBIx_Pn)))

//���־λ
#define KBI0_CLEAN_FLAG()  (KBI0_SC |= KBI_SC_KBACK_MASK | KBI_SC_RSTKBSP_MASK )
#define KBI1_CLEAN_FLAG()  (KBI1_SC |= KBI_SC_KBACK_MASK | KBI_SC_RSTKBSP_MASK )

//�ж���ж��Ƿ񴥷� KBI �ж�
#define IS_KBI0_IRQ()    (KBI0_SC & KBI_SC_KBF_MASK )
#define IS_KBI1_IRQ()    (KBI1_SC & KBI_SC_KBF_MASK )

#define IS_KBI_CH_IRQ(ptxn)    (KBIn[GPX(ptxn)]->SP & (1<<GPn(ptxn)))

//IRQ ͷ�ļ�     ************************************************
typedef enum
{
    //�����ֵ���ܸģ�����
    IRQ_NULL        = (0),   //�������κ�����      ��Ĭ�������������ģ�����Ҫȡ������Ҫ�� | IRQ_PULLUP_DIS��

    IRQ_PULLUP_EN   = 0,                                                            //��������ʹ��
    IRQ_PULLUP_DIS  = (1 << IRQ_SC_IRQPDD_SHIFT),                                   //�����������

    IRQ_FALLING     = (0),                                                          //�½��� ����
    IRQ_RISING      = (1 << IRQ_SC_IRQEDG_SHIFT),                                   //������ ����

    IRQ_ZERO        = (0 | (1 << IRQ_SC_IRQMOD_SHIFT) ) ,                           //�͵�ƽ ����
    IRQ_ONE         = ((1 << IRQ_SC_IRQEDG_SHIFT) | (1 << IRQ_SC_IRQMOD_SHIFT) )    //�ߵ�ƽ ����


} IRQ_CFG;

#define     IRQ_CLEAN_FLAG()     (IRQ_SC |= IRQ_SC_IRQACK_MASK )                      //���־λ (д1��0)
#define     IS_IRQ_FLAG()       (IRQ_SC & IRQ_SC_IRQF_MASK )

//enter�����ĺ궨��     ************************************************

//�ַ��� ���� ת��                                   ************************************************
//�ַ�����ʽ����������
typedef int       (*sprintf_t)         (char *buf, const char *fmt, ...) ;
#define sprintf(...)                              ENTER_FUN(sprintf,##__VA_ARGS__)


//�ַ�����ʽ�������ָ���˿� fp ������Ϊ���ڣ�
extern int enter_fputc(char ch);                    //��Ҫ�û��Զ���ʵ�ִ˺���
typedef int fputc_t (char c);
typedef int (*printf_t)(fputc_t *fp, const char *fmt, ...);
#define printf(fmt,...)                               ENTER_FUN(printf,enter_fputc,fmt,##__VA_ARGS__)


//�ַ���ת������
typedef int       (*atoi_t)            (char *str);
#define atoi(...)                                 ENTER_FUN(atoi,##__VA_ARGS__)


//����ת��Ϊ�ַ���
typedef char *    (*itoa_t)            (int n, char *chBuffer);
#define itoa(...)                                 ENTER_FUN(itoa,##__VA_ARGS__)


//����ת��Ϊ�ַ���
typedef char *    (*ftoa_t)            (double dValue, char *chBuffer);
#define ftoa(...)                                 ENTER_FUN(ftoa,##__VA_ARGS__)


//����ת��Ϊ�ַ���(֧��ָ��С����λ��)
typedef char *    (*ftoan_t)            (double dValue, char *chBuffer, int ndigits);
#define ftoan(...)                                ENTER_FUN(ftoan,##__VA_ARGS__)



//����С����                                       ************************************************
//�ڴ渴��
//typedef void *    (*memcpy_t)  ( uint8_t *dst, uint8_t *src, uint32_t count);
//#define memcpy(...)                               ENTER_FUN(memcpy,##__VA_ARGS__)


//�ڴ�������ֵ
typedef void *    (*memset_t)  (void *src, int c, int count);
#define memset(...)                               ENTER_FUN(memset,##__VA_ARGS__)


//���ַ����ĳ���
typedef int       (*strlen_t)(const char *str);
#define strlen(...)                               ENTER_FUN(strlen,##__VA_ARGS__)



//flash API                                   ************************************************
//��ʼ��Flash
typedef void      (*flash_init_t)          (int);
#define flash_init()                           ENTER_FUN(flash_init,bus_clk_khz)


//����ָ��flash����
typedef uint8_t   (*flash_erase_sector_t)  (uint16_t sectorNum);
#define flash_erase_sector(...)                   ENTER_FUN(flash_erase_sector,##__VA_ARGS__)


//д��flash����
typedef uint8_t   (*flash_write_t)         (uint16_t sectorNum, uint16_t offset, FLASH_WRITE_TYPE data);
#define flash_write(...)                          ENTER_FUN(flash_write,##__VA_ARGS__)


//�ӻ�����д��flash����
typedef uint8_t   (*flash_write_buf_t)     (uint16_t sectorNum, uint16_t offset, uint16_t cnt, uint8 buf[]);
#define flash_write_buf(...)                      ENTER_FUN(flash_write_buf,##__VA_ARGS__)

//����һ��flash API�ӿڣ�                        flash_read          (sectorNum,offset,type)                  //��ȡָ����ַ������

//flash �洢����                                  ************************************************
//�Խṹ�����ݽ���Ԥ������flash�����ݻ�û��ʼ����������flash
typedef void      (*flash_data_init_t)     (flash_data_t *d, int bus_khz);
#define flash_data_init(d)                      ENTER_FUN(flash_data_init,d,bus_clk_khz)


//����flash�����ǶԴ洢���ݽ������
typedef void      (*flash_data_reset_t)    (flash_data_t *d);
#define flash_data_reset(...)                     ENTER_FUN(flash_data_reset,##__VA_ARGS__)


//�� flash ��������
typedef uint8_t   (*flash_data_load_t)     (flash_data_t *d);
#define flash_data_load(...)                      ENTER_FUN(flash_data_load,##__VA_ARGS__)


//�������ݵ�flash
typedef uint8_t   (*flash_data_save_t)     (flash_data_t *d);
#define flash_data_save(...)                      ENTER_FUN(flash_data_save,##__VA_ARGS__)




//SPI ͨ��                                      ************************************************
//SPI��ʼ����ѡ��Ƭѡ�źţ�����ģʽ��������  (Ŀǰ��֧������ģʽ)
typedef uint32_t  (*spi_init_t)       (SPIn_e spi, PTXn_e pcs, SPI_CFG, uint32 baud, uint32 bus_khz, char use_pin_mode);
#define spi_init(spi,pcs,cfg,baud,pin_mode)                ENTER_FUN(spi_init,spi,pcs,cfg,baud,bus_clk_khz,pin_mode)


typedef uint32_t  (*spi_set_baud_t)   (SPIn_e spi,                     uint32 baud, uint32 bus_khz);
#define spi_set_baud(...)                         ENTER_FUN(spi_set_baud,##__VA_ARGS__)


//SPI���ͽ��պ���,����databuff���ݣ����ѽ��յ������ݴ����databuff��(ע�⣬�Ḳ��ԭ����databuff)
typedef void (*spi_mosi_t)       (SPIn_e, PTXn_e pcs,                              uint8 *modata, uint8 *midata,               uint32 len);
#define spi_mosi(...)                             ENTER_FUN(spi_mosi,##__VA_ARGS__)


//SPI���ͽ��պ���,��spi_mosi��ȣ������ȷ���cmd �������Ĳ��裬���ֿ������ַ���
typedef void (*spi_mosi_cmd_t)   (SPIn_e, PTXn_e pcs, uint8 *mocmd , uint8 *micmd , uint8 *modata, uint8 *midata, uint32 cmdlen , uint32 len);
#define spi_mosi_cmd(...)                         ENTER_FUN(spi_mosi_cmd,##__VA_ARGS__)



//PWT�����Ȳ���                                   ************************************************
typedef void     (*pwt_pulse_init_t)     (PWT_INn_e INn,  uint32_t cfg);
#define pwt_pulse_init(...)                       ENTER_FUN(pwt_pulse_init,##__VA_ARGS__)


//Cycleʱ��ȡ���������************************************************
typedef uint16_t (*pwt_pulse_get_t)     (PWT_INn_e INn);
#define pwt_pulse_get(...)                        ENTER_FUN(pwt_pulse_get,##__VA_ARGS__)



//Dutyʱ��ȡ��������2�����ȶ��������־λ���ٶ���************************************************
//������
typedef uint16_t (*pwt_pulse_pos_get_t)(PWT_INn_e INn);
#define pwt_pulse_pos_get(...)                    ENTER_FUN(pwt_pulse_pos_get,##__VA_ARGS__)


//������
typedef uint16_t (*pwt_pulse_neg_get_t)(PWT_INn_e INn);
#define pwt_pulse_neg_get(...)                    ENTER_FUN(pwt_pulse_neg_get,##__VA_ARGS__)



//KBI �����ж�                                    ************************************************
//chΪPTA0~D7ʱ��ΪKBI0ģ�飬PTE0~H7ʱ��ΪKBI1ģ�顣ͬһ��ģ�飬����Ҫ��ͬ�����ô�����ʽ�����ʱ���Ƽ��� kbi_allinit��
typedef void (*kbi_init_t) (PTXn_e ch, uint8_t cfg);
#define kbi_init(...)                             ENTER_FUN(kbi_init,##__VA_ARGS__)


// ch_mask Ϊ (1<<ch),���ͨ��ʱ���� | ����
typedef void (*kbi_allinit_t) (uint64_t ch_mask, uint8_t cfg);
#define kbi_allinit(...)                          ENTER_FUN(kbi_allinit,##__VA_ARGS__)



//irq �ⲿ�ж�                                    ************************************************
//����Ϊ PTI0~I6 (ԭ����A5����Ϊ��λ�ڣ�������)��ͬһʱ�䣬ֻ������һ�������ܶ��ͬʱ�á�
typedef void (*irq_init_t)  (PTXn_e, uint8_t cfg);
#define irq_init(...)                             ENTER_FUN(irq_init,##__VA_ARGS__)



//FTM ��ʱ�жϣ����Ʋ������������ã��˷�FTM��                   ************************************************
//��timer_clk���ڼ�ʱ�Ķ�ʱ�жϺ���
typedef void (*ftm_timing_init_t)(FTMn_e ftmn, uint16_t counttime, FTM_PS_e ps);
#define ftm_timing_init(...)                      ENTER_FUN(ftm_timing_init,##__VA_ARGS__)



//FTM �����ж�(�����ã�һ�㳣�õ��Ƕ�ʱ����������)                 ************************************************
//�������������Ķ��������жϺ���
typedef void (*ftm_pulsing_init_t)(FTMn_e ftmn, uint16_t counttime, FTM_PS_e ps, PTXn_e tclk_ptxn);
#define ftm_pulsing_init(...)                     ENTER_FUN(ftm_pulsing_init,##__VA_ARGS__)



//ִ����APP API�ӿ� ������ͨ�� �������ò�ͬ������ĺ���������ջ��ַ��      ************************************************
//��ת���µ�APP
typedef void      (*jmp_app_t)             (uint32_t sp, uint32_t pc);
#define jmp_app(...)                              ENTER_FUN(jmp_app,##__VA_ARGS__)


//��ת���µ�APP BIN�ļ� ��bin�ļ��ĵ�1��32λ������ջ��ַ����2��32λ����������������ڣ�
typedef void      (*jmp_bin_t)             (uint32_t addr);
#define jmp_bin(...)                              ENTER_FUN(jmp_bin,##__VA_ARGS__)








#endif    //#ifndef FWD_LIB




#endif