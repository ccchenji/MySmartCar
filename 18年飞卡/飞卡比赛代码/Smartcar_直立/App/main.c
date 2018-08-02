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
*        |           |             ��  ��  ��   ��   ��  ��   ��   bug
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

//�Զ�����Ҫ��������ݣ����ȷ������ȫΪ 0XFF �������ʶ���쳣
//���������ܷ������Ƕ��һ��������ֵ��ֵΪ0����
typedef struct
{
	uint16_t a;
	uint16_t b;
} my_data_t;

flash_data_t data;

int adc_value[4];
int key_value = 0;
char KEY_NUM;
float vcan_send_buff[4]; //ɽ����λ������ʾ����
int ErrLoop = 0;
extern int enCircle;
int CircleTime = 0;
extern int bInCircle;
/*
* @brief      ADC�˲��������
* @author     �¼���-->(����շ���ADC��Ȼû�˲���ȥ����������)
* @date       2018-7-15
*/
int ADC_V[4][3] = { {0,0} };
int adcFirst[4][5] = { { 0,0 } };//���ڱ����ʼ��ADCֵ
int lastADC0 = 0;
int lastADC3 = 0;
int ADC_Sum[4] = { 0 };
int ADCFianlly[4] = { 0 };
/*
* @brief      ��ʱ���ж�5ms(����PID����)
* @author     ɽ��
* @date       ������
*/
int flag_run = 0;
#ifdef BALANCE 
void pit0_irq(void)
{
	static int index = 0;//ʱ����Ʊ�־λ
	GetAngle();//��ȡ�����ǽǶ�
	Dir_Control();//�������
	if (++index > 5)
	{
		led_turn(LED0); //��˸ LED3
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
		else//ͣ��
		{
			Right_Motor_Control(0);
			Left_Motor_Control(0);
		}
		if (Speed_Kp > 1)//�ٶȻ�����Ϊ0ʱ�ٶȿ���
			SpeedControlOut();
		index = 6;
	}
	BalanceControl();//ƽ�����
	if (enCircle == 0)
	{
		CircleTime++;
		if (CircleTime > 1000)
		{
			enCircle = 1;
			CircleTime = 0;
		}
	}
	PIT_Flag_Clear(PIT0); //���жϱ�־λ
}
#else
void pit0_irq(void)
{
	PIT_Flag_Clear(PIT0); //���жϱ�־λ
}

#endif // BALANCE

/*
* @brief      ��ʱ���ж�(����OLEDˢ��)
* @author     ɽ��
* @date       ������
*/

void pit1_irq(void)
{
	key_value = Key_Scan();
	SOLGUI_InputKey(key_value);
	SOLGUI_Menu_PageStage(); //
	SOLGUI_Refresh();        //OLEDˢ��
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
* @brief      ADC�˲����ִ���
* @author     �¼���-->(����շ���ADC��Ȼû�˲���ȥ����������)
* @date       2018-7-15
*/
void filterAdc()
{
	int i, j, k, temp;
	/*----------------------�õ���ʼ��ADC��ֵ----------------------------*/
	for (int i = 0; i < 5; i++)
	{
		adcFirst[0][i] = adc_once(ADC0_SE12, ADC_10bit);
		adcFirst[1][i] = adc_once(ADC0_SE13, ADC_10bit);
		adcFirst[2][i] = adc_once(ADC0_SE14, ADC_10bit);
		adcFirst[3][i] = adc_once(ADC0_SE15, ADC_10bit);
	}
	/*---------------------------ð����������---------------------------*/
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
	/*--------------------------��ֵ�˲�--------------------------------*/
	for (i = 0; i < 4; i++)
	{
		adc_value[i] = adcFirst[i][1] + adcFirst[i][2] + adcFirst[i][3];
		adc_value[i] = adc_value[i] / 3;
	}
	/*-------------------------����ƽ���˲�----------------------------*/
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
	gpio_init(PTD4, GPO, 0); //��ʼ��������
	gpio_init(PTH6, GPO, 0); //��ʼ��LED0
	gpio_init(PTH7, GPO, 0); //��ʼ��LED1
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

	/*PWM��ʼ����FTM2,CH0-CH3,Ƶ��2K,����1000u*/
	ftm_pwm_init(FTM2, FTM_CH0, 2000, 0);
	ftm_pwm_init(FTM2, FTM_CH1, 2000, 0); //ǰ��ͨ��

	ftm_pwm_init(FTM2, FTM_CH2, 2000, 0); //ǰ��ͨ��
	ftm_pwm_init(FTM2, FTM_CH3, 2000, 0);


	/*oled��ʼ��*/
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
	EnableInterrupts; //���ܵ��жϿ���

	adc_init(ADC0_SE12);
	adc_init(ADC0_SE13);
	adc_init(ADC0_SE14);
	adc_init(ADC0_SE15);

	for (;;)
	{
		filterAdc();
		if (adc_value[0] == 0 && adc_value[1] == 0 && adc_value[2] == 0 && adc_value[3] == 0 && flag_run == 1)
			flag_run = 0;//������ͣ���ж�
		if (SystemAttitude.Pitch > 34 || SystemAttitude.Pitch < -10) flag_run = 0;//����һ���Ƕ�ͣ��(��������)
	}
}

//if(g_AngleOfCar>300|| g_AngleOfCar<-800 )flag_run = 0;
//vcan_send_buff[0] = g_AngleOfCar;
//vcan_send_buff[0] = AccZAngle;
//vcan_send_buff[1] = SystemAttitude.Pitch;
//vcan_send_buff[2] = SystemAttitudeRate.Pitch;
//vcan_sendware((uint8_t *)vcan_send_buff, sizeof(vcan_send_buff));


/*!
*  @brief      main����
*  @since      v6.0
*  @note       ɽ�� flash data

��������Ҫ���ߵ��ԣ���������ֵ�ı仯��
�� md ����watch���������ԣ��𲽷���md��Ԫ�����ݱ仯��
*/
/*void  main(void)
{
//�ⲿ�����û��Լ������ݣ���һ���ǽṹ�壬Ҳ���������飬�����ݱ����������Ҵ�Сȷ��
my_data_t  md;
md.a = 0;
md.b = 0;

//�ⲿ�������� flash �������
data.sectornum_start    = FLASH_SECTOR_NUM - 3;     //��ʼ����      ������3����������Ϊ�������
data.sectornum_end    = FLASH_SECTOR_NUM - 1;       //��������

data.data_addr      = &md;                          //���ݵĵ�ַ
data.data_size      = sizeof(md);                  //���ݵĴ�С

//��ʼ��������
flash_data_init(&data);

//����flash(����������)
//flash_data_reset(&data);

//һ��ʼ����֪�������Ƿ���Ч��
if(flash_data_load(&data))
{
//�������һ�δ洢�����ݳɹ�

}
else
{
//����������Ч��flash�����ǿհ׵�

flash_data_reset(&data);        //����һ��flash����

md.a = 0x1234;                  //�Ա�����ʼ��
md.b = 0x5678;

//д���ʼ��ֵ
flash_data_save(&data) ;

//����������
md.a = 0;
md.b = 0;
flash_data_load(&data) ;
}

//����������ǿ�����˵㣬�� md �������Ƿ�ָ���

//һ������£����ǲ���Ҫ���� flash_data_reset ����գ������㲻��Ҫ flash�����ݡ�

md.a = 0x3210;
md.b = 0x8765;
flash_data_save(&data) ;

//��������� md �����ݣ�Ȼ��� flash �ָ�����
md.a = 0;
md.b = 0;
flash_data_load(&data) ;


md.a = 0xabcd;
md.b = 0x3456;
flash_data_save(&data) ;

//��������� md �����ݣ�Ȼ��� flash �ָ�����
md.a = 0;
md.b = 0;
flash_data_load(&data) ;

}*/