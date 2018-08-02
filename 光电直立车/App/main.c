/*
				 ██████╗ █████╗ ██╗   ██╗ ██████╗
				██╔════╝██╔══██╗██║   ██║██╔════╝
				██║     ███████║██║   ██║██║
				██║     ██╔══██║██║   ██║██║
				╚██████╗██║  ██║╚██████╔╝╚██████╗
				 ╚═════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝
*/
/*!
 * @file       main.c
 * @brief      2017恩智浦杯智能车主程序
 * @author     Jassy
 * @date       2016-12-01
 * @note	   2017-04-23重写 
 */
#include "common.h"
#include "include.h"
#include "../SOLGUI/SOLGUI_Menu.h"
#include "../SOLGUI/SOLGUI_Common.h"
#define SECTOR_NUM  (FLASH_SECTOR_NUM-1)         //尽量用最后面的扇区，确保安全 
#define Bet     ADC1_SE6a                        //定义电池电压测量AD引脚
#define FloatFillStr(x,y)   ((*(float *)&y)=x)   //浮点数转char型数组
#define StrFillFloat(x,y)   (y=(*(float *)&x))   //char型数组转浮点数 
#define SW_1_carflag		PTE3	
#define SW_2_undef			PTE4
#define SW_3_OLEDreflash	PTE5
#define Test_IO				PTE9
#define Beep				PTC1
//====================函数声明========================
//内部函数记得加static 
//使用断言进行安全检查 
void PIT0_IRQHandler(void);
void PIT1_IRQHandler(void);
void PORTA_IRQHandler(void);
void DMA0_IRQHandler(void);
void UsartSendnum(char ID, float num);
//====================参数定义========================
//中断引用变量记得加volatile
//只读变量记得加constant 
//减少全局变量定义 加static修饰 如需访问可构造函数
uint8 key_value = 0;
uint8 imgbuff[CAMERA_SIZE]; //定义存储接收图像的数组
float bet_value = 0;
float vcan_send_buff[8]; //山外上位机虚拟示波器
KEY_MSG_t keymsg;        
int img_send_cnt = 0; //发送图像数组计数
char img_send_flag = 0; //发送图像标志位  
char num_send_flag = 0; //发送参数标志位
char vcan_send_flag = 0; //山外上位机发送标志位
char car_1or2_flag = 0; //车1车2标志
int beep_time = 0;    //蜂鸣器响时间
int beep_cnt = 0;      //蜂鸣器响计时
int stop_flag_cnt = 0;
//++++++++++++++++++++++++++++++++++++++++++++++++++++
/*!
 *  @brief      main函数
 *  @note       
 */
//system_MK60DZ10.c main函数之前start函数内开启硬件浮点
void main()
{
	DisableInterrupts; //关总中断
	printf("Init......begin\n");
	printf("**************************\n");
	/*		调试按键初始化
	*KEY硬件定义在VCAN_key.c文件修改 
	*枚举类型KEY_e 
	*/
	printf("Key Init......");
	key_init(KEY_MAX);					 //初始化全部按键
	gpio_init(SW_1_carflag, GPI, 1);	 //e3为车辆识别标志
	gpio_init(SW_2_undef  , GPI, 1);
	gpio_init(SW_3_OLEDreflash, GPI, 1); //初始化拨码开关 
	gpio_init(Test_IO, GPO, 1);			 //测试时序用 
	printf("OK\n");
	printf("Car flag Read......");
	if (gpio_get(SW_1_carflag) == 0)
	{
		car_1or2_flag = 1;
	} //2车
	else
	{
		car_1or2_flag = 0;
	} //1车
	printf("OK\n");
	/*初始化电压测量ADC*/
	printf("ADC_bet Init......");
	adc_init(Bet);
	printf("OK\n");
	/*蜂鸣器初始化*/
	printf("Beep Init......");
	gpio_init(Beep, GPO, 0); //开蜂鸣器
	printf("OK\n");
	/*OLED初始化*/
	printf("OLED Init......");
	OLED_Init(); //初始化OLED
	OLED_Fill(0x00); //黑屏
	draw_cauc_logo();
	if (car_1or2_flag == 1)
	{
		DELAY_MS(200);
		gpio_set(Beep, 1);
		DELAY_MS(100);
		gpio_set(Beep, 0);
		DELAY_MS(200);
		gpio_set(Beep, 1);
	}
	else
	{
		DELAY_MS(300);
		gpio_set(Beep, 1);
		DELAY_MS(200);
	}
	DELAY_MS(300);
	printf("OK\n");
	/*UI界面初始化*/
	printf("UI Init......");
	SOLGUI_Init(&UI_List);		    //UI初始化界面
	SOLGUI_Refresh();		    	//UI刷新 
	printf("OK\n");
	/*		FTM模块初始化 
	*频率 8K 精度 1000 
	*精度修改  MK60_FTM.H -> FTM0_PRECISON
	*/
	printf("PWM Init......");
	MotorInit();
	printf("OK\n");
	/*		软件I2C初始化      */
	printf("I2C Init......");
	IMU_IIC_Init();
	printf("OK\n");
	/*		姿态传感器初始化      */
	printf("8451&3050 Init......");
	UpstandInit();
	printf("OK\n");
	/*       正交解码初始化      */
	printf("Encoder Init......");
	Encoder_Init();
	port_init_NoALT(PTA12, PF | PULLUP);//内部配置上拉
	port_init_NoALT(PTA13, PF | PULLUP);
	port_init_NoALT(PTA10, PF | PULLUP);
	port_init_NoALT(PTA11, PF | PULLUP);
	printf("OK\n");
	/*       FLASH初始化         */
	printf("Flash Init......");
	flash_init(); //初始化flash
	parameter_init(); //初始化参数  此处装载所有掉电不丢失参数  
	printf("OK\n");
	/*       摄像头初始化        */
	printf("Camera Init......");
	camera_init(p_imgbuff1);
	printf("OK\n");
	/*        设置中断向量       */
	printf("Interrupt Init......");
	NVIC_SetPriorityGrouping(4);		//设置中断分组
	set_irq_priority(DMA0_IRQn, 2);
	set_irq_priority(PORTA_IRQn, 2);
	//NVIC_SetPriority(PIT0_VECTORn, 2); //配置1ms中断高优先级
	NVIC_SetPriority(PIT1_VECTORn, 3);	 //配置5ms中断低优先级
	set_vector_handler(PORTA_VECTORn, PORTA_IRQHandler); 
	set_vector_handler(DMA0_VECTORn, DMA0_IRQHandler); 
	/*    初始化PIT定时器中断    */
	//pit_init_ms(PIT0, 5); //初始化PIT0，定时时间为： 1ms
	//set_vector_handler(PIT0_VECTORn, PIT0_IRQHandler); //设置PIT0的中断服务函数为 PIT0_IRQHandler
	//enable_irq(PIT0_IRQn); //使能PIT0中断  
	pit_init_ms(PIT1, 80);
	set_vector_handler(PIT1_VECTORn, PIT1_IRQHandler);
	enable_irq(PIT1_IRQn);
	ov7725_eagle_img_flag = IMG_START;      //开始采集图像
	enable_irq(PORTA_IRQn);                 //允许PTA的中断
	printf("OK\n");
	printf("**************************\n");
	printf("Init...Over\n");
	EnableInterrupts; //开总中断
	while (1)
	{
		//发送图像		
		if (img_send_flag == 1)			
		{
			//FloatFillStr(f1, cfdata[0]);
			uart_putchar(UART1, 0xaa);
			uart_putchar(UART1, 0xbb);
			uart_putchar(UART1, 0xcc);
			uart_putchar(UART1, 0xcd);
			uart_putchar(UART1, 0xdc);
			
			for (img_send_cnt = 0; img_send_cnt <2400; img_send_cnt++)
			{
				uart_putchar(UART1, imgbuff[img_send_cnt]);
			}
			//包尾
			uart_putchar(UART1, 0xcc);
			uart_putchar(UART1, 0xdd);
			uart_putchar(UART1, 0xee);
		}
		//发送参数
		if (num_send_flag == 1)
		{
			//if (img_send_flag == 1)
			uart_putchar(UART1, 0xaa);
			uart_putchar(UART1, 0xbb);
		//	UsartSendnum(20, DIRECTION_CONTROL_P);
		//	UsartSendnum(21, DIRECTION_CONTROL_D);
			UsartSendnum(22, g_fRealSpeed);
		//	UsartSendnum(23, Speed_err - Speed_errlast);
		//	UsartSendnum(24, ke * 100);
		//	UsartSendnum(25, RoadType);
			//包尾
			uart_putchar(UART1, 0xcc);
			uart_putchar(UART1, 0xdd);
			uart_putchar(UART1, 0xee);
		}
		vcan_send_buff[0] = g_fRealSpeed;
		//发送山外上位机参数
		if (vcan_send_flag == 1)
		{
			vcan_sendware((uint8_t *)vcan_send_buff, sizeof(vcan_send_buff));
		}
		//花屏处理	
		if (gpio_get(SW_3_OLEDreflash) == 0)
		{
			OLED_Init();
			OLED_Fill(0x00);
		}								
		bet_value = (float)(ad_ave(Bet, ADC_12bit, 10)) / 4096 * 3.3 * 3; //测量电池电压                                 
	}
}



/*!
*  @brief      PIT0中断服务函数
*  @author	   Jassy
*  @date	   20161201
*  @note       
*/
void PIT0_IRQHandler(void)
{
	PIT_Flag_Clear(PIT0); //清中断标志位
}

void PIT1_IRQHandler(void)
{
	key_value = key_scan();
	SOLGUI_InputKey(key_value);//传入GUI 
    SOLGUI_Menu_PageStage();
	SOLGUI_Refresh(); //OLED前台刷新
	PIT_Flag_Clear(PIT1);
}

/*!
*  @brief      PORTA中断服务函数
*  @since      v5.0
*/
void PORTA_IRQHandler()
{
	uint8 n; //引脚号
	uint32 flag;

	while (!PORTA_ISFR);
	flag = PORTA_ISFR;
	PORTA_ISFR = ~0; //清中断标志位

	n = 29; //场中断
	if (flag & (1 << n)) //PTA29触发中断
	{
			//gpio_set(Test_IO, 1);
			camera_vsync();   //开始采集图像(设置图像地址)
			flag_imgbuff != 0 ? img_extract(img, p_imgbuff1, CAMERA_SIZE) : img_extract(img, p_imgbuff2, CAMERA_SIZE);
			//解压上一次图像													 800us
			DirectionControl();		//方向控制输出							 1.8ms
			GalAcceAndGyroY();		//采集计算加速度计和陀螺仪					 1ms
			KalmanFilter();			//卡尔曼滤波，得出角度 时间				 40us
			BalanceControl();		//直立控制输出
			PWMOut();				//最终PWM输出给电机（本次的方向输出、直立输出和上次的速度输出叠加）
			Flag_SpeedControl++;
			if (Flag_SpeedControl >= 20)
			{
				SpeedControl();		//速度控制周期20*(1/150)s
				Flag_SpeedControl = 0;
			}
			SpeedControlOut();		//速度输出周期（1/150）s，也就是每次的速度控制分20次输出
			stop_flag_cnt++;
			if(stop_flag_cnt>=1500)
			{
				stop_flag_cnt = 1500;
			}
			if(beep_time>0)
			{
				gpio_init(Beep, GPO, 0); //开蜂鸣器 
				beep_time--;
			}
			else
			{
				gpio_init(Beep, GPO, 1); //关蜂鸣器
				beep_time = 0;
			}
	}
}

/*!
*  @brief      DMA0中断服务函数
*  @since      v5.0
*/
void DMA0_IRQHandler()
{
	camera_dma();
	camera_get_img();	//等待图像传输完毕（完成标志变为开始标志）
	flag_imgbuff = !flag_imgbuff;
	ov7725_eagle_img_buff = (flag_imgbuff == 0 ? p_imgbuff1 : p_imgbuff2);//交替初始化图像地址
}
void UsartSendnum(char ID,float num)
{
	char str[4];
	FloatFillStr(num, str[0]);
	uart_putchar(UART1, 0xab);
	uart_putchar(UART1, 0xba);
	//ID
	uart_putchar(UART1, ID);
	for (img_send_cnt = 0; img_send_cnt < 4; img_send_cnt++)
	{
		uart_putchar(UART1, str[img_send_cnt]);
	}
}
