#ifndef _control_h
#define _control_h
#include "include.h"

extern int motorEncorderL,motorEncorderR;
struct pid
{
	float Kp;
	float Ki;
	float Kd;
	float i;
	float err;
	float err_last;
	float pidout;
};
extern struct pid speed,dir;

/*FTMÕ¼¿Õ±È*/
//#define CH0_Duty
unsigned char Key_check (unsigned char key);
unsigned char Key_Scan(void);
void Key_init(void);
void Speed_calulate(void);
void Encoder_init(void);
void Speed_PidControl(int set_speed,int real_speed);
void Dir_PdControl(void);
void Adc_Init(void);
uint8 switch_read(void);
void Motor_control(void);
void Speed_PidControl(int set_speed,int real_speed);
void Dir_PdControl(void);
int ADC_deal(int *adcValue);

void lose_line_deal(int *adc_Value, int position, int leftRange, int rightRange);
int get_sensor_threshold_normalization(void);
void sensorValue_get(int * sensor_value);
void Sensor_init(void);
#endif
