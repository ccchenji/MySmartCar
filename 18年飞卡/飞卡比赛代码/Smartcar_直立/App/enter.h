#ifndef _ENTER_H_
#define _ENTER_H_
#include "stdint.h"

#define FWD_VER     601                     // 固件版本号 （请勿修改，仅作给上层识别）
#define FWD_FLAG    0x5AA5                  // 固件标记 （请勿修改）
#define FWD_ADDR   (0x1A0)                  // 固件地址 （请勿修改）

typedef struct
{
    uint16_t    flag;                   //标记
    uint16_t    ver;                    //版本

    //字库
    uint8_t    *ascii_6x12;             //英文字库      ，6x12
    uint8_t    *ascii_8x16;             //英文字库      ，8x16

    //字符串 变量 转换
    void       *sprintf;                //int       sprintf         (char *buf, const char *fmt, ...) ;          //字符串格式化到缓冲区
    void       *printf;                 //void      printf          (fp,fmt, ...);                               //字符串格式化输出到指定端口 fp （常用为串口）
    void       *atoi;                   //int       atoi            (char *str);                                //字符串转成整型
    void       *itoa;                   //char *    itoa            (int n, char * chBuffer);                   //整型转换为字符串
    void       *ftoa;                   //char *    ftoa            (double dValue, char * chBuffer);           //浮点转换为字符串
    void       *ftoan;                  //char *    ftoan            (double dValue, char * chBuffer,int ndigits);//浮点转换为字符串(支持指定小数点位数)

    //常用小功能
    void       *memcpy;                 //void *    memcpy  ( uint8_t *dst, uint8_t *src, uint32_t count);      //内存复制
    void       *memset;                 //void *    memset  (void *src, int c, int count);                      //内存设置数值
    void       *strlen;                 //int       strlen(const char * str);                                   //求字符串的长度

    //flash API
    void       *flash_init;             //void      flash_init          ();                                     //初始化Flash
    void       *flash_erase_sector;     //uint8_t   flash_erase_sector  (uint16_t sectorNum);                     //擦除指定flash扇区
    void       *flash_write;            //uint8_t   flash_write         (uint16_t sectorNum, uint16_t offset, FLASH_WRITE_TYPE data);       //写入flash操作
    void       *flash_write_buf;        //uint8_t   flash_write_buf     (uint16_t sectorNum, uint16_t offset, uint16_t cnt, uint8 buf[]);     //从缓存区写入flash操作
    //还有一个flash API接口：                        flash_read          (sectorNum,offset,type)                  //读取指定地址的数据

    //flash 存储数据
    void       *flash_data_init;        //void      flash_data_init     (flash_data_t *d);                      //对结构体数据进行预处理，若flash的数据还没初始化，则重置flash
    void       *flash_data_reset;       //void      flash_data_reset    (flash_data_t *d);                      //重置flash，就是对存储数据进行清空
    void       *flash_data_load;        //uint8_t   flash_data_load     (flash_data_t *d);                      //从 flash 加载数据
    void       *flash_data_save;        //uint8_t   flash_data_save     (flash_data_t *d);                      //保存数据到flash


    //SPI 通信
    void       *spi_init;               //uint32_t  spi_init       (SPIn_e, PTXn_e pcs, SPI_CFG,uint32 baud,uint32 bus_khz,char use_pin_mode); //SPI初始化，选择片选信号，设置模式，波特率  (目前仅支持主机模式)
    void       *spi_set_baud;           //uint32_t  spi_set_baud   (SPIn_e,                     uint32 baud,uint32 bus_khz);
    void       *spi_mosi;               //void spi_mosi       (SPIn_e, PTXn_e pcs,                              uint8 *modata, uint8 *midata,               uint32 len);    //SPI发送接收函数,发送databuff数据，并把接收到的数据存放在databuff里(注意，会覆盖原来的databuff)
    void       *spi_mosi_cmd;           //void spi_mosi_cmd   (SPIn_e, PTXn_e pcs, uint8 *mocmd , uint8 *micmd , uint8 *modata, uint8 *midata, uint32 cmdlen , uint32 len); //SPI发送接收函数,与spi_mosi相比，多了先发送cmd 缓冲区的步骤，即分开两部分发送

    //PWT脉冲宽度测量
    void       *pwt_pulse_init;         //void     pwt_pulse_init     (PWT_INn_e INn,  uint32_t cfg);
    //Cycle时获取用下面这个
    void       *pwt_pulse_get;          //uint16_t pwt_pulse_get     (PWT_INn_e INn);

    //Duty时获取用下面这2个。先读负，清标志位，再读正
    void       *pwt_pulse_pos_get;      //uint16_t pwt_pulse_pos_get(PWT_INn_e INn);  //正脉冲
    void       *pwt_pulse_neg_get;      //uint16_t pwt_pulse_neg_get(PWT_INn_e INn);  //负脉冲

    //KBI 按键中断
    void       *kbi_init;               //void kbi_init (PTXn_e ch, uint8_t cfg);           //ch为PTA0~D7时，为KBI0模块，PTE0~H7时，为KBI1模块。同一个模块，必须要相同的配置触发方式。多个时，推荐用 kbi_allinit。
    void       *kbi_allinit;            //void kbi_allinit (uint64_t ch_mask, uint8_t cfg); // ch_mask 为 (1<<ch),多个通道时，用 | 并接

    //irq 外部中断
    void       *irq_init;               //void irq_init  (PTXn_e, uint8_t cfg);         //引脚为 PTI0~I6 (原本有A5，但为复位口，不能用)。同一时间，只能配置一个，不能多个同时用。

    //FTM 定时中断（估计不会有人这样用，浪费FTM）
    void       *ftm_timing_init;        //void ftm_timing_init(FTMn_e ftmn,uint16_t counttime,FTM_PS_e ps);  //以timer_clk周期计时的定时中断函数

    //FTM 脉冲中断(较少用，一般常用的是定时测量脉冲数)
    void       *ftm_pulsing_init;               //void ftm_pulsing_init(FTMn_e ftmn,uint16_t counttime,FTM_PS_e ps,PTXn_e tclk_ptxn);  //以脉冲数计数的定脉冲数中断函数

    //执行新APP API接口 （和普通的 函数调用不同，下面的函数都重置栈地址）
    void       *jmp_app;                //void      jmp_app             (uint32_t sp, uint32_t pc);          //跳转到新的APP
    void       *jmp_bin;                //void      jmp_bin             (uint32_t addr);                     //跳转到新的APP BIN文件 （bin文件的第1个32位数据是栈地址，第2个32位数据是启动函数入口）


} mydata_in_t;




//内部用，用户无需关注
#define     OFFSET(type, member)                (uint32)(&(((type *)0)->member))
#define     IN_ADDR(member)                     (*((uint32_t *)(FWD_ADDR + OFFSET(mydata_in_t, member)) ))
#define     ENTER_FUN(func,...)                 (*(func##_t)(IN_ADDR(func)))(##__VA_ARGS__)
#define     ENTER_FUN_ADDR(func,...)       (*(func##_t)(func##_addr))(##__VA_ARGS__)
#define     ENTER_FUN_ADDR0(func,...)       (*(func##_t)(func##_addr))(##__VA_ARGS__)


#ifndef FWD_LIB
#define  enter_init()      (((uint16_t)IN_ADDR(flag)==FWD_FLAG) && (uint16_t)IN_ADDR(ver)==FWD_VER)      //用于判断固件文件是否存在 ,APP需要初始化时执行 ASSERT(enter_init());

//系统参数        ************************************************
extern int core_clk_khz;
extern int core_clk_mhz;
extern int bus_clk_khz;
extern int timer_clk_khz;

#define ASCII12        ((uint8_t *)(IN_ADDR(ascii_6x12)))
#define ASCII16        ((uint8_t *)(IN_ADDR(ascii_8x16)))

#include "KEA_port.h"
#include "KEA_ftm.h"


//Flash 头文件     ************************************************
#define     FLASH_SECTOR_SIZE       (512)                //扇区大小 为 512 字节
#define     FLASH_SECTOR_NUM        (256)                   //扇区数

#define     FLASH_ALIGN_ADDR        4                       //地址对齐整数倍
typedef     uint32_t               FLASH_WRITE_TYPE;       //flash_write 函数写入 的数据类型

#define     flash_read(sectorNo,offset,type)        (*(type *)((uint32)(((sectorNo)*FLASH_SECTOR_SIZE) + (offset))))          //读取扇区
#define     flash_read_addr(addr,type)              (*(type *)((uint32)(addr)))          //读取指定地址


typedef struct
{
    uint16_t    sectornum_start;            //开始的扇区
    uint16_t    sectornum_end;              //结束的扇区
    void      *data_addr;                   //数据的地址
    uint16_t    data_size;                  //数据的尺寸
    uint16_t    res1;                       //保留，底层使用 （勿删）
    uint32_t    res2[2];                    // 保留，底层使用 （勿删）


} flash_data_t;

//SPI 头文件     ************************************************
/**
 *  @brief 主从机模式
 */
typedef enum
{
    //主从模式选择。下列 2选1
    SLAVE = (0 << SPI_C1_MSTR_SHIFT),    //从机模式  (不支持此模式)
    MASTER = (1 << SPI_C1_MSTR_SHIFT) ,  //主机模式

    //时钟模式选择，下列 4 选 1
    CPOL_CPHA_00  = (0 << SPI_C1_CPHA_SHIFT) ,
    CPOL_CPHA_01  = (1 << SPI_C1_CPHA_SHIFT) ,
    CPOL_CPHA_10  = (2 << SPI_C1_CPHA_SHIFT) ,
    CPOL_CPHA_11  = (3 << SPI_C1_CPHA_SHIFT) ,



} SPI_CFG;

/**
 *  @brief SPI模块号
 */
#define  SPI_MAX   2
typedef SPI_Type *SPIn_e ;


//PWT 头文件     ************************************************

//定义 PWT 通道号
typedef enum
{
    PWT_IN0,
    PWT_IN1,

} PWT_INn_e;

//分频系数
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
    Pwt_Disable             = 1,                //停用PWT
    Pulse_Over_Enable_irq   = PWT_R1_POVIE_MASK | PWT_R1_PWTIE_MASK   ,       //开启脉冲计数溢出中断 （0xFFFF to 0x0000.）
    Pulse_Width_Enable_irq  = PWT_R1_PRDYIE_MASK | PWT_R1_PWTIE_MASK   ,      //开启宽度测量中断

    Cycle_Falling     = PWT_R1_EDGE(0)   ,  //周期测量，后续2个下降沿为测量的宽度
    Cycle_Rising     = PWT_R1_EDGE(3)   ,  //周期测量，后续2个上升沿为测量的宽度

    Duty_Rising      = PWT_R1_EDGE(1)   , //占空比测量，测量2个值，第一个上升沿开始的正脉冲宽度，第二个是整个周期（2个上升沿之间的宽度）
    Duty_Falling      = PWT_R1_EDGE(2)   , //占空比测量，测量2个值，第一个下降沿开始的负脉冲宽度，第二个是整个周期（2个下降沿之间的宽度）

} PWT_CFG_e;

//KBI 头文件     ************************************************

typedef enum
{
    //这里的值不能改！！！
    KBI_IRQ_DIS        = (0),   //禁用

    KBI_PULLUP_DIS  = (1 << 4),      //上拉电阻禁用
    KBI_PULLUP_EN   = (2 << 4),      //上拉电阻使能

    KBI_FALLING     = (1 << 0),      //下降沿 触发
    KBI_RISING      = (2 << 0),      //上升沿 触发

    KBI_ZERO        = (1 << 2) ,     //低电平 触发 (含下降沿)
    KBI_ONE         = (2 << 2)       //高电平 触发 (含上升沿)


} KBI_CFG;


static KBI_MemMapPtr KBIn[] = KBI_BASE_PTRS;        //???????这个估计特殊处理

//中断使能和禁止
#define kbi_enable_irq(KBIx_Pn)         enable_irq((IRQn_t)(KBI0_IRQn + GPX(KBIx_Pn)))
#define kbi_disable_irq(KBIx_Pn)        disable_irq((IRQn_t)(KBI0_IRQn + GPX(KBIx_Pn)))

//清标志位
#define KBI0_CLEAN_FLAG()  (KBI0_SC |= KBI_SC_KBACK_MASK | KBI_SC_RSTKBSP_MASK )
#define KBI1_CLEAN_FLAG()  (KBI1_SC |= KBI_SC_KBACK_MASK | KBI_SC_RSTKBSP_MASK )

//中断里，判断是否触发 KBI 中断
#define IS_KBI0_IRQ()    (KBI0_SC & KBI_SC_KBF_MASK )
#define IS_KBI1_IRQ()    (KBI1_SC & KBI_SC_KBF_MASK )

#define IS_KBI_CH_IRQ(ptxn)    (KBIn[GPX(ptxn)]->SP & (1<<GPn(ptxn)))

//IRQ 头文件     ************************************************
typedef enum
{
    //这里的值不能改！！！
    IRQ_NULL        = (0),   //不进行任何配置      （默认是配置上拉的，若需要取消，需要加 | IRQ_PULLUP_DIS）

    IRQ_PULLUP_EN   = 0,                                                            //上拉电阻使能
    IRQ_PULLUP_DIS  = (1 << IRQ_SC_IRQPDD_SHIFT),                                   //上拉电阻禁用

    IRQ_FALLING     = (0),                                                          //下降沿 触发
    IRQ_RISING      = (1 << IRQ_SC_IRQEDG_SHIFT),                                   //上升沿 触发

    IRQ_ZERO        = (0 | (1 << IRQ_SC_IRQMOD_SHIFT) ) ,                           //低电平 触发
    IRQ_ONE         = ((1 << IRQ_SC_IRQEDG_SHIFT) | (1 << IRQ_SC_IRQMOD_SHIFT) )    //高电平 触发


} IRQ_CFG;

#define     IRQ_CLEAN_FLAG()     (IRQ_SC |= IRQ_SC_IRQACK_MASK )                      //清标志位 (写1清0)
#define     IS_IRQ_FLAG()       (IRQ_SC & IRQ_SC_IRQF_MASK )

//enter函数的宏定义     ************************************************

//字符串 变量 转换                                   ************************************************
//字符串格式化到缓冲区
typedef int       (*sprintf_t)         (char *buf, const char *fmt, ...) ;
#define sprintf(...)                              ENTER_FUN(sprintf,##__VA_ARGS__)


//字符串格式化输出到指定端口 fp （常用为串口）
extern int enter_fputc(char ch);                    //需要用户自定义实现此函数
typedef int fputc_t (char c);
typedef int (*printf_t)(fputc_t *fp, const char *fmt, ...);
#define printf(fmt,...)                               ENTER_FUN(printf,enter_fputc,fmt,##__VA_ARGS__)


//字符串转成整型
typedef int       (*atoi_t)            (char *str);
#define atoi(...)                                 ENTER_FUN(atoi,##__VA_ARGS__)


//整型转换为字符串
typedef char *    (*itoa_t)            (int n, char *chBuffer);
#define itoa(...)                                 ENTER_FUN(itoa,##__VA_ARGS__)


//浮点转换为字符串
typedef char *    (*ftoa_t)            (double dValue, char *chBuffer);
#define ftoa(...)                                 ENTER_FUN(ftoa,##__VA_ARGS__)


//浮点转换为字符串(支持指定小数点位数)
typedef char *    (*ftoan_t)            (double dValue, char *chBuffer, int ndigits);
#define ftoan(...)                                ENTER_FUN(ftoan,##__VA_ARGS__)



//常用小功能                                       ************************************************
//内存复制
typedef void *    (*memcpy_t)  ( uint8_t *dst, uint8_t *src, uint32_t count);
//#define memcpy(...)                               ENTER_FUN(memcpy,##__VA_ARGS__)


//内存设置数值
typedef void *    (*memset_t)  (void *src, int c, int count);
#define memset(...)                               ENTER_FUN(memset,##__VA_ARGS__)


//求字符串的长度
typedef int       (*strlen_t)(const char *str);
#define strlen(...)                               ENTER_FUN(strlen,##__VA_ARGS__)



//flash API                                   ************************************************
//初始化Flash
typedef void      (*flash_init_t)          (int);
#define flash_init()                           ENTER_FUN(flash_init,bus_clk_khz)


//擦除指定flash扇区
typedef uint8_t   (*flash_erase_sector_t)  (uint16_t sectorNum);
#define flash_erase_sector(...)                   ENTER_FUN(flash_erase_sector,##__VA_ARGS__)


//写入flash操作
typedef uint8_t   (*flash_write_t)         (uint16_t sectorNum, uint16_t offset, FLASH_WRITE_TYPE data);
#define flash_write(...)                          ENTER_FUN(flash_write,##__VA_ARGS__)


//从缓存区写入flash操作
typedef uint8_t   (*flash_write_buf_t)     (uint16_t sectorNum, uint16_t offset, uint16_t cnt, uint8 buf[]);
#define flash_write_buf(...)                      ENTER_FUN(flash_write_buf,##__VA_ARGS__)

//还有一个flash API接口：                        flash_read          (sectorNum,offset,type)                  //读取指定地址的数据

//flash 存储数据                                  ************************************************
//对结构体数据进行预处理，若flash的数据还没初始化，则重置flash
typedef void      (*flash_data_init_t)     (flash_data_t *d, int bus_khz);
#define flash_data_init(d)                      ENTER_FUN(flash_data_init,d,bus_clk_khz)


//重置flash，就是对存储数据进行清空
typedef void      (*flash_data_reset_t)    (flash_data_t *d);
#define flash_data_reset(...)                     ENTER_FUN(flash_data_reset,##__VA_ARGS__)


//从 flash 加载数据
typedef uint8_t   (*flash_data_load_t)     (flash_data_t *d);
#define flash_data_load(...)                      ENTER_FUN(flash_data_load,##__VA_ARGS__)


//保存数据到flash
typedef uint8_t   (*flash_data_save_t)     (flash_data_t *d);
#define flash_data_save(...)                      ENTER_FUN(flash_data_save,##__VA_ARGS__)




//SPI 通信                                      ************************************************
//SPI初始化，选择片选信号，设置模式，波特率  (目前仅支持主机模式)
typedef uint32_t  (*spi_init_t)       (SPIn_e spi, PTXn_e pcs, SPI_CFG, uint32 baud, uint32 bus_khz, char use_pin_mode);
#define spi_init(spi,pcs,cfg,baud,pin_mode)                ENTER_FUN(spi_init,spi,pcs,cfg,baud,bus_clk_khz,pin_mode)


typedef uint32_t  (*spi_set_baud_t)   (SPIn_e spi,                     uint32 baud, uint32 bus_khz);
#define spi_set_baud(...)                         ENTER_FUN(spi_set_baud,##__VA_ARGS__)


//SPI发送接收函数,发送databuff数据，并把接收到的数据存放在databuff里(注意，会覆盖原来的databuff)
typedef void (*spi_mosi_t)       (SPIn_e, PTXn_e pcs,                              uint8 *modata, uint8 *midata,               uint32 len);
#define spi_mosi(...)                             ENTER_FUN(spi_mosi,##__VA_ARGS__)


//SPI发送接收函数,与spi_mosi相比，多了先发送cmd 缓冲区的步骤，即分开两部分发送
typedef void (*spi_mosi_cmd_t)   (SPIn_e, PTXn_e pcs, uint8 *mocmd , uint8 *micmd , uint8 *modata, uint8 *midata, uint32 cmdlen , uint32 len);
#define spi_mosi_cmd(...)                         ENTER_FUN(spi_mosi_cmd,##__VA_ARGS__)



//PWT脉冲宽度测量                                   ************************************************
typedef void     (*pwt_pulse_init_t)     (PWT_INn_e INn,  uint32_t cfg);
#define pwt_pulse_init(...)                       ENTER_FUN(pwt_pulse_init,##__VA_ARGS__)


//Cycle时获取用下面这个************************************************
typedef uint16_t (*pwt_pulse_get_t)     (PWT_INn_e INn);
#define pwt_pulse_get(...)                        ENTER_FUN(pwt_pulse_get,##__VA_ARGS__)



//Duty时获取用下面这2个。先读负，清标志位，再读正************************************************
//正脉冲
typedef uint16_t (*pwt_pulse_pos_get_t)(PWT_INn_e INn);
#define pwt_pulse_pos_get(...)                    ENTER_FUN(pwt_pulse_pos_get,##__VA_ARGS__)


//负脉冲
typedef uint16_t (*pwt_pulse_neg_get_t)(PWT_INn_e INn);
#define pwt_pulse_neg_get(...)                    ENTER_FUN(pwt_pulse_neg_get,##__VA_ARGS__)



//KBI 按键中断                                    ************************************************
//ch为PTA0~D7时，为KBI0模块，PTE0~H7时，为KBI1模块。同一个模块，必须要相同的配置触发方式。多个时，推荐用 kbi_allinit。
typedef void (*kbi_init_t) (PTXn_e ch, uint8_t cfg);
#define kbi_init(...)                             ENTER_FUN(kbi_init,##__VA_ARGS__)


// ch_mask 为 (1<<ch),多个通道时，用 | 并接
typedef void (*kbi_allinit_t) (uint64_t ch_mask, uint8_t cfg);
#define kbi_allinit(...)                          ENTER_FUN(kbi_allinit,##__VA_ARGS__)



//irq 外部中断                                    ************************************************
//引脚为 PTI0~I6 (原本有A5，但为复位口，不能用)。同一时间，只能配置一个，不能多个同时用。
typedef void (*irq_init_t)  (PTXn_e, uint8_t cfg);
#define irq_init(...)                             ENTER_FUN(irq_init,##__VA_ARGS__)



//FTM 定时中断（估计不会有人这样用，浪费FTM）                   ************************************************
//以timer_clk周期计时的定时中断函数
typedef void (*ftm_timing_init_t)(FTMn_e ftmn, uint16_t counttime, FTM_PS_e ps);
#define ftm_timing_init(...)                      ENTER_FUN(ftm_timing_init,##__VA_ARGS__)



//FTM 脉冲中断(较少用，一般常用的是定时测量脉冲数)                 ************************************************
//以脉冲数计数的定脉冲数中断函数
typedef void (*ftm_pulsing_init_t)(FTMn_e ftmn, uint16_t counttime, FTM_PS_e ps, PTXn_e tclk_ptxn);
#define ftm_pulsing_init(...)                     ENTER_FUN(ftm_pulsing_init,##__VA_ARGS__)



//执行新APP API接口 （和普通的 函数调用不同，下面的函数都重置栈地址）      ************************************************
//跳转到新的APP
typedef void      (*jmp_app_t)             (uint32_t sp, uint32_t pc);
#define jmp_app(...)                              ENTER_FUN(jmp_app,##__VA_ARGS__)


//跳转到新的APP BIN文件 （bin文件的第1个32位数据是栈地址，第2个32位数据是启动函数入口）
typedef void      (*jmp_bin_t)             (uint32_t addr);
#define jmp_bin(...)                              ENTER_FUN(jmp_bin,##__VA_ARGS__)








#endif    //#ifndef FWD_LIB




#endif