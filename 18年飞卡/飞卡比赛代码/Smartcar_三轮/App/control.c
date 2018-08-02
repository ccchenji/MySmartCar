#include "control.h"
#include "include.h"


#define ADC_CH0 ADC0_SE12
#define ADC_CH1 ADC0_SE13
#define ADC_CH2 ADC0_SE14
#define ADC_CH3 ADC0_SE15

int motorEncorderL=0,motorEncorderR=0;
int g_base_speed=10,g_real_speed=0,g_set_speed=40,speedMax=200,dutyMax=600;
int g_leftThrottle=80,g_rightThrottle=80,loss_line=0;
extern char KEY_NUM;
extern int adc_value[4];

struct pid speed = {10,0.1,10,0,0,0,0};
struct pid dir = {13,50,0,0,0,0,0};

void Key_init(void)
{
	/*????§?????????????é?*/
	gpio_init(PTI5, GPI, 1);
	gpio_init(PTI6, GPI, 1);
	gpio_init(PTD5, GPI, 1);
	gpio_init(PTD6, GPI, 1);
	gpio_init(PTD7, GPI, 1);
	gpio_init(PTC2, GPI, 1);
	/*????§??????¨????????*/
	gpio_init(PTC3, GPI, 1);
	gpio_init(PTB4, GPI, 1);
	gpio_init(PTB5, GPI, 1);
	gpio_init(PTE5, GPI, 1);

}unsigned char Key_Scan(void)
{
	uint8 num = 0x00;
	if (key_get(KEY_A) == KEY_DOWN)
		KEY_NUM = 1;
	else if (key_get(KEY_B) == KEY_DOWN)
		KEY_NUM = 2;
	else if (key_get(KEY_D) == KEY_DOWN)
		KEY_NUM = 3;
	else if (key_get(KEY_U) == KEY_DOWN)
		KEY_NUM = 4;
	else if (key_get(KEY_L) == KEY_DOWN)
		KEY_NUM = 5;
	else if (key_get(KEY_R) == KEY_DOWN)
		KEY_NUM = 6;

	if (key_get(KEY_A) == KEY_DOWN) { num = SOLGUI_KEY_BACK; }
	if (key_get(KEY_B) == KEY_DOWN) { num = SOLGUI_KEY_OK; }
	if (key_get(KEY_D) == KEY_DOWN) { num = SOLGUI_KEY_DOWN; }
	if (key_get(KEY_U) == KEY_DOWN) { num = SOLGUI_KEY_UP; }
	if (key_get(KEY_L) == KEY_DOWN) { num = SOLGUI_KEY_LEFT; }
	if (key_get(KEY_R) == KEY_DOWN) { num = SOLGUI_KEY_RIGHT; }
	
	return num;
}


/*
 *  @brief      ????????¨???????????????
 *  @since      v1.0
*/
uint8 switch_read(void)
{
  uint8 data = 0x00;
  data = (gpio_get(PTC3)) + (gpio_get(PTB4)<<1) + (gpio_get(PTB5)<<2) + (gpio_get(PTE5)<<3);
  return data;
}

void Speed_calulate(void)
{
	motorEncorderL = ftm_pulse_get(FTM1);
	ftm_clean(FTM1);
	if (gpio_get(PTD2) == 0)
		motorEncorderL = - motorEncorderL;
        
	motorEncorderR = ftm_pulse_get(FTM0);
	ftm_clean(FTM0);
	if (gpio_get(PTD3) == 1)
		motorEncorderR = - motorEncorderR;
        
	g_real_speed=(motorEncorderL+motorEncorderR)/2.0;
}

void Encoder_init(void)
{
    gpio_init(PTD2, GPI, 0);
    gpio_init(PTD3, GPI, 0);
    ftm_pulse_init(FTM0,FTM_PS_4,PTE7);
    ftm_pulse_init(FTM1,FTM_PS_4,PTE0);
}

void Motor_control(void)
{
	float dutyL = 0, dutyR = 0;
	if (dir.pidout >= 0)
	{
		if ((g_base_speed + speed.pidout - dir.pidout) <= 0)
		{
			dutyR = 0;
			dutyL = g_base_speed + speed.pidout + dir.pidout;
		}
		else
		{
			dutyR = g_base_speed + speed.pidout - dir.pidout;
			dutyL = 0;
		}
	}
	else
	{
		if ((g_base_speed + speed.pidout + dir.pidout) <= 0)
		{
			dutyL = 0;
			dutyR = g_base_speed + speed.pidout - dir.pidout;
		}
		else
		{
			dutyL = g_base_speed + speed.pidout + dir.pidout;
			dutyR = 0;
		}
	}
	    //     if (dir.pidout >= 0)
	    //     {
	    //     dutyR = g_base_speed + speed.pidout - dir.pidout;
		// dutyL = g_base_speed + speed.pidout + dir.pidout;
	    //     }
	    //     else
	    //     {
	    //     dutyR = g_base_speed + speed.pidout + dir.pidout;
		// dutyL = g_base_speed + speed.pidout - dir.pidout;
	    //     }
	

	if (dutyL > dutyMax)
		dutyL = dutyMax;
	if (dutyL < -dutyMax)
		dutyL = -dutyMax;
        
	if (dutyR > dutyMax)
		dutyR = dutyMax;
	if (dutyR < -dutyMax)
		dutyR = -dutyMax;

	if (loss_line == 1)
	{
		dutyL = -250;
		dutyR = dutyMax - 100;
	}
	if (loss_line == 2)
	{
		dutyL = dutyMax - 100;
		dutyR = -250;
	}

	if (dutyL < 0)
	{
		ftm_pwm_duty(FTM2, FTM_CH0, 250);
		ftm_pwm_duty(FTM2, FTM_CH1, 0);
	}
	else if (dutyL >= 0)
	{

		ftm_pwm_duty(FTM2, FTM_CH0, 0);
		ftm_pwm_duty(FTM2, FTM_CH1, dutyL);
	}

	if (dutyR < 0)
	{
		ftm_pwm_duty(FTM2, FTM_CH2, 0);
		ftm_pwm_duty(FTM2, FTM_CH3, 250);
	}
	else if (dutyR >= 0)
	{
		ftm_pwm_duty(FTM2, FTM_CH2, dutyR);
		ftm_pwm_duty(FTM2, FTM_CH3, 0);
	}
}

void Speed_PidControl(int set_speed,int real_speed)
{
	uint16 SpeedMax = 500;
	static int real_speed_old = 0 ;
	int speed_stand = 0;
	real_speed_old = real_speed;
	speed_stand = real_speed * 0.7 + real_speed_old *0.3;
	speed.err = set_speed - speed_stand;
	speed.pidout = speed.Kp * speed.err + speed.Kd * (speed.err - speed.err_last) + speed.Ki * speed.i;
	speed.err_last = speed.err;
	speed.i += speed.err;
	if (speed.err > 50)
		speed.i = 0;
	if (speed.pidout > SpeedMax)
		speed.pidout = SpeedMax;
}
void Dir_PdControl(void)
{
	dir.err = adc_value[0]-adc_value[3];//ADC_deal(adc_value);
	dir.pidout = dir.Kp * dir.err + dir.Kd * (dir.err - dir.err_last);
	dir.err_last = dir.err;
}

void Sensor_init(void)
{
  adc_init(ADC_CH0);
  adc_init(ADC_CH1);
  adc_init(ADC_CH2);
  adc_init(ADC_CH3);
}

int ADC_deal(int * adcValue)
{
	int ValueCopy[4],adc_cal[4],position=0;
	u8 i;
	for (i = 0; i < 4; i++)
		ValueCopy[i] = adcValue[i];
	adc_cal[0]=ValueCopy[0]-ValueCopy[1];//右减右中
	adc_cal[1]=ValueCopy[1]-ValueCopy[2];//右中减左中
	adc_cal[2]=ValueCopy[2]-ValueCopy[3];//左中减左
	adc_cal[3]=ValueCopy[0]-ValueCopy[3];//右减左

	position= adc_cal[3] + adc_cal[1];
	return position;
}

void lose_line_deal(int *adc_Value, int position, int leftRange, int rightRange)
{
	static int error_add[3] = {0, 0, 0}, loss_line_inc;
	int loss_line_lock=0;
	int error_tatal = 0, sensor_value_all = 0;

	for (int i = 0; i < 2; i++) //误差数组循环移动
	{
		error_add[i + 1] = error_add[i];
	}
	error_add[0] = position;								  //数组首位为处理后误差
	error_tatal = error_add[0] + error_add[1] + error_add[2]; //三次误差值的和
	sensor_value_all = adc_value[0] + adc_value[1] + adc_value[2] + adc_value[3];
	if ((g_leftThrottle > sensor_value_all) || (g_rightThrottle < fabs(sensor_value_all)) && (adc_value[0]<10||adc_value[3]<10))//判断电感值是否小于丢线阈值
	{
		if ((error_tatal > 0) && (loss_line == 0) && (g_leftThrottle > sensor_value_all))
			{
				loss_line = 2;
                                loss_line_lock=1;
			}
		else if ((error_tatal < 0) && (loss_line == 0) && (g_rightThrottle < fabs(sensor_value_all) ))
			{
				loss_line = 1;
                                loss_line_lock=1;
			}
		else
		{
			;;
		}
	}
	else
	{
		if (loss_line_lock == 1) //滤波
		{
			loss_line_inc++;
			if (loss_line_inc > 5)
			{
				loss_line_lock = 0;
				loss_line_inc = 0;
			}
		}
		if (loss_line_lock == 0)
		{
			loss_line = 0;
		}
	}
}

int get_sensor_threshold_normalization(void)
{
	int sensor_value_now[4] = { 0,0,0,0 };
	int sensor_value_last[4] = { 0,0,0,0 };
	int sensor_value_max[4] = { 0,0,0,0 };
	sensorValue_get(sensor_value_now);
	for (int i = 0; i < 4; i++)
	{
		if (sensor_value_max[i] < MAX(sensor_value_now[i], sensor_value_last[i]))
		{
			sensor_value_max[i] = MAX(sensor_value_now[i], sensor_value_last[i]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		sensor_value_last[i] = sensor_value_now[i];
	}

}

void sensorValue_get(int * sensor_value)
{
	sensor_value[0] = adc_once(ADC_CH0, ADC_10bit);
	sensor_value[1] = adc_once(ADC_CH1, ADC_10bit);
	sensor_value[2] = adc_once(ADC_CH2, ADC_10bit);
	sensor_value[3] = adc_once(ADC_CH3, ADC_10bit);
}
//
////自定义需要保存的数据，务必确保不能全为 0XFF ，否则会识别异常
////如果有这可能发生，那多加一个变量，值赋值为0即可
//typedef struct
//{
//	uint16_t a;
//	uint16_t b;
//} my_data_t;
//
//flash_data_t data;
//
////这部分是配置 flash 保存参数
//data.sectornum_start = FLASH_SECTOR_NUM - 3;     //起始扇区      用最后的3个扇区来作为保存参数
//data.sectornum_end = FLASH_SECTOR_NUM - 1;       //结束扇区
//
//data.data_addr = &md;                          //数据的地址
//data.data_size = sizeof(md);                  //数据的大小
//
//












































































