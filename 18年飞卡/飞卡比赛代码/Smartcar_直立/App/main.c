/**********************************************************************************************
*      +--+          +-+  + +
*      |  +          + +
*    + |       +  +
*  +-+ +-------+  +-+  +  +
*  |                +
*  |                        +
*  |            +--+        +
*  |                       +
*XXXXXXXX   XXXXXXXX   +   |  +-+   ++  +-+
*XXXXXXXX+--XXXXXXXX   | + +
*XXXXXXXX   XXXXXXXX   +
*  +                       +
*  |          +          + + +
*  |         -+-         |
*  |                     + +
*  |                  +    + ++
*  +---+          +---+
*      + +        +
*        |           +
*        |           |
*        |           |   ++  ++  ++
*        |           |
*        |           |
*        |           |   ++
*        |           |
*        |           |             Code is far away from bug with the animal protecting
*        |           |             神  兽  保   佑   代  码   无   bug
*        |           |
*        |           +  +
*        |              +----+  +-+
*        |                   |    +-+
*        |                        + |
*        |                          |
*        |                        +-+
*        |                    +   +
*        +--+ ++ +-----+-+  +-+
*           +  + +     + +  +     ++   +-+    +-+ +-+
*             + + +       +  + +
*             | | |       |  | |
*             +---+       +----+
*             + + +       +  + +  ++   +-+  +--+   +-+
*************************************************************************************************/

#include "common.h"
#include "include.h"
#define BALANCE

//自定义需要保存的数据，务必确保不能全为 0XFF ，否则会识别异常
//如果有这可能发生，那多加一个变量，值赋值为0即可
typedef struct
{
	uint16_t a;
	uint16_t b;
} my_data_t;

flash_data_t data;

int adc_value[4];
int key_value = 0;
char KEY_NUM;
float vcan_send_buff[4]; //山外上位机虚拟示波器
int ErrLoop = 0;
extern int enCircle;
int CircleTime = 0;
extern int bInCircle;
/*
* @brief      ADC滤波所需参数
* @author     陈济轩-->(今天刚发现ADC居然没滤波我去。。。。。)
* @date       2018-7-15
*/
int ADC_V[4][3] = { {0,0} };
int adcFirst[4][5] = { { 0,0 } };//用于保存初始的ADC值
int lastADC0 = 0;
int lastADC3 = 0;
int ADC_Sum[4] = { 0 };
int ADCFianlly[4] = { 0 };
/*
* @brief      定时器中断5ms(用于PID计算)
* @author     山外
* @date       。。。
*/
int flag_run = 0;
#ifdef BALANCE 
void pit0_irq(void)
{
	static int index = 0;//时序控制标志位
	GetAngle();//获取陀螺仪角度
	Dir_Control();//方向控制
	if (++index > 5)
	{
		led_turn(LED0); //闪烁 LED3
		if (++Flag_SpeedControl > 10)
		{
			Flag_SpeedControl = 0;
			Speed_calulate();
			SpeedControl();
		}
		if (flag_run != 0)
		{
			Right_Motor_Control(Balance_Out - SpeedOut - DirOut);
			Left_Motor_Control(Balance_Out - SpeedOut + DirOut);
		}
		else//停车
		{
			Right_Motor_Control(0);
			Left_Motor_Control(0);
		}
		if (Speed_Kp > 1)//速度环参数为0时速度开环
			SpeedControlOut();
		index = 6;
	}
	BalanceControl();//平衡控制
	if (enCircle == 0)
	{
		CircleTime++;
		if (CircleTime > 1000)
		{
			enCircle = 1;
			CircleTime = 0;
		}
	}
	PIT_Flag_Clear(PIT0); //清中断标志位
}
#else
void pit0_irq(void)
{
	PIT_Flag_Clear(PIT0); //清中断标志位
}

#endif // BALANCE

/*
* @brief      定时器中断(用于OLED刷新)
* @author     山外
* @date       。。。
*/

void pit1_irq(void)
{
	key_value = Key_Scan();
	SOLGUI_InputKey(key_value);
	SOLGUI_Menu_PageStage(); //
	SOLGUI_Refresh();        //OLED刷新
	if (bInCircle == 3 || bInCircle == 4)
	{
		gpio_turn(PTD4);
	}
	else
	{
		gpio_set(PTD4, 0);
	}
	PIT_Flag_Clear(PIT1);
}
/*
* @brief      ADC滤波部分代码
* @author     陈济轩-->(今天刚发现ADC居然没滤波我去。。。。。)
* @date       2018-7-15
*/
void filterAdc()
{
	int i, j, k, temp;
	/*----------------------得到初始的ADC的值----------------------------*/
	for (int i = 0; i < 5; i++)
	{
		adcFirst[0][i] = adc_once(ADC0_SE12, ADC_10bit);
		adcFirst[1][i] = adc_once(ADC0_SE13, ADC_10bit);
		adcFirst[2][i] = adc_once(ADC0_SE14, ADC_10bit);
		adcFirst[3][i] = adc_once(ADC0_SE15, ADC_10bit);
	}
	/*---------------------------冒泡排序升序---------------------------*/
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4 - j; k++)
			{
				if (adcFirst[i][k] > adcFirst[i][k + 1])
				{
					temp = adcFirst[i][k + 1];
					adcFirst[i][k + 1] = adcFirst[i][k];
					adcFirst[i][k] = temp;
				}
			}
		}
	}
	/*--------------------------中值滤波--------------------------------*/
	for (i = 0; i < 4; i++)
	{
		adc_value[i] = adcFirst[i][1] + adcFirst[i][2] + adcFirst[i][3];
		adc_value[i] = adc_value[i] / 3;
	}
	/*-------------------------滑动平均滤波----------------------------*/
	for (i = 0; i < 2; i++)
	{
		ADC_V[0][i] = ADC_V[0][i + 1];
		ADC_V[1][i] = ADC_V[1][i + 1];
		ADC_V[2][i] = ADC_V[2][i + 1];
		ADC_V[3][i] = ADC_V[3][i + 1];
	}
	for (i = 0; i < 4; i++)
	{
		ADC_V[i][2] = adc_value[i];
	}
	for (i = 0; i < 3; i++)
	{
		ADC_Sum[0] += ADC_V[0][i];
		ADC_Sum[1] += ADC_V[1][i];
		ADC_Sum[2] += ADC_V[2][i];
		ADC_Sum[3] += ADC_V[3][i];
	}
	for (i = 0; i < 4; i++)
	{
		ADCFianlly[i] = ADC_Sum[i] / 3;
		ADC_Sum[i] = 0;
	}
//        	ADCFianlly[0] = adc_once(ADC0_SE12, ADC_10bit);
//		ADCFianlly[1] = adc_once(ADC0_SE13, ADC_10bit);
//		ADCFianlly[2] = adc_once(ADC0_SE14, ADC_10bit);
//		ADCFianlly[3] = adc_once(ADC0_SE15, ADC_10bit);
}


void main(void)
{
	gpio_init(PTD4, GPO, 0); //初始化蜂鸣器
	gpio_init(PTH6, GPO, 0); //初始化LED0
	gpio_init(PTH7, GPO, 0); //初始化LED1
	key_init(KEY_MAX);

	OLED_Init();
	OLED_Fill(0x00);
	draw_cauc_logo();

	gpio_turn(PTD4);
	systick_delay_ms(50);
	gpio_turn(PTD4);
	systick_delay_ms(50);
	gpio_turn(PTD4);
	systick_delay_ms(50);
	gpio_turn(PTD4);

	DELAY_MS(500);

	/*PWM初始化：FTM2,CH0-CH3,频率2K,精度1000u*/
	ftm_pwm_init(FTM2, FTM_CH0, 2000, 0);
	ftm_pwm_init(FTM2, FTM_CH1, 2000, 0); //前进通道

	ftm_pwm_init(FTM2, FTM_CH2, 2000, 0); //前进通道
	ftm_pwm_init(FTM2, FTM_CH3, 2000, 0);


	/*oled初始化*/
	SOLGUI_Init(&UI_MENU);
	SOLGUI_Refresh();

	led_init(LED0);
	Encoder_init();
#ifdef BALANCE
	IIC_init_BMX();
	while (BMX055_init() == 0)
	{
		ErrLoop++;
		if (ErrLoop >= 20)
			while (1);
	};
#endif // BALANCE



	pit_init_ms(PIT0, 5);
	pit_init_ms(PIT1, 100);
	enable_irq(PIT_CH0_IRQn);
	enable_irq(PIT_CH1_IRQn);
	EnableInterrupts; //打开总的中断开关

	adc_init(ADC0_SE12);
	adc_init(ADC0_SE13);
	adc_init(ADC0_SE14);
	adc_init(ADC0_SE15);

	for (;;)
	{
		filterAdc();
		if (adc_value[0] == 0 && adc_value[1] == 0 && adc_value[2] == 0 && adc_value[3] == 0 && flag_run == 1)
			flag_run = 0;//出赛道停车判断
		if (SystemAttitude.Pitch > 34 || SystemAttitude.Pitch < -10) flag_run = 0;//超过一定角度停车(车倒保护)
	}
}

//if(g_AngleOfCar>300|| g_AngleOfCar<-800 )flag_run = 0;
//vcan_send_buff[0] = g_AngleOfCar;
//vcan_send_buff[0] = AccZAngle;
//vcan_send_buff[1] = SystemAttitude.Pitch;
//vcan_send_buff[2] = SystemAttitudeRate.Pitch;
//vcan_sendware((uint8_t *)vcan_send_buff, sizeof(vcan_send_buff));


/*!
*  @brief      main函数
*  @since      v6.0
*  @note       山外 flash data

本例程需要在线调试，看变量的值的变化。
把 md 加入watch，单步调试，逐步分析md的元素数据变化。
*/
/*void  main(void)
{
//这部分是用户自己的数据，不一定是结构体，也可以是数组，但数据必须连续，且大小确定
my_data_t  md;
md.a = 0;
md.b = 0;

//这部分是配置 flash 保存参数
data.sectornum_start    = FLASH_SECTOR_NUM - 3;     //起始扇区      用最后的3个扇区来作为保存参数
data.sectornum_end    = FLASH_SECTOR_NUM - 1;       //结束扇区

data.data_addr      = &md;                          //数据的地址
data.data_size      = sizeof(md);                  //数据的大小

//开始函数调用
flash_data_init(&data);

//重置flash(看个人需求)
//flash_data_reset(&data);

//一开始，不知道数据是否有效的
if(flash_data_load(&data))
{
//加载最后一次存储的数据成功

}
else
{
//加载数据无效。flash数据是空白的

flash_data_reset(&data);        //重置一下flash数据

md.a = 0x1234;                  //对变量初始化
md.b = 0x5678;

//写入初始化值
flash_data_save(&data) ;

//读回来测试
md.a = 0;
md.b = 0;
flash_data_load(&data) ;
}

//到了这里，我们可以设端点，看 md 的数据是否恢复了

//一般情况下，我们不需要调用 flash_data_reset 来清空，除非你不想要 flash的数据。

md.a = 0x3210;
md.b = 0x8765;
flash_data_save(&data) ;

//我们先清空 md 的数据，然后从 flash 恢复数据
md.a = 0;
md.b = 0;
flash_data_load(&data) ;


md.a = 0xabcd;
md.b = 0x3456;
flash_data_save(&data) ;

//我们先清空 md 的数据，然后从 flash 恢复数据
md.a = 0;
md.b = 0;
flash_data_load(&data) ;

}*/