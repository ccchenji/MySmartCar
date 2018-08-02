/*
* @file         Sensor.c
  * @brief      �������ɼ���غ���ʵ��
  * @author     xiao_fang
  * @version    v1.0
  * @date       2017-3-12
*/

#include "common.h"
#include "Sensor.h"
#include "KEA_adc.h"
#include "VCAN_LED.H"
#include "KEA_gpio.h"

//                              ��1����2����3����3����2����1
uint16 sensor_value[6] =        {0,   0,   0,   0,   0,   0};  //���洫����ֵ
uint16 normalization_threshold[6] = {0,0,0,0,0,0};              ///���洫������һ��ֵ
extern uint8 loss_line;                 //����ָʾ��1�󶪣�2�Ҷ���0����
extern uint8 loss_line_lock;            //�����������ߺ��Զ�����
extern uint8 circle_sign;
float position_accumulative[15] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}; 
/*
 *  @brief      ��ʼ��������
 *  @since      v1.0
*/
void Sensor_init(void)
{
  adc_init(ADC_CH0);
  adc_init(ADC_CH1);
  adc_init(ADC_CH2);
  adc_init(ADC_CH3);
}

/*
 *  @brief      ��ȡһ�δ�����ֵ����������
 *  @since      v1.0
 * sensor_value         ���ݱ���λ��
*/
//void Sensor_value_get(uint16 * sensor_value)
//{
//      sensor_value[3] = adc_once( ADC0_SE0, ADC_ACCURACY);   //AD5 ��2 PTE20
//      sensor_value[2] = adc_once( ADC0_SE6a, ADC_ACCURACY);   //AD6 ��1 PTE22
//      sensor_value[1] = adc_once( ADC0_SE2, ADC_ACCURACY);   //AD2 ��3 PTE19
//  
//      sensor_value[5] = adc_once( ADC0_SE1, ADC_ACCURACY);  //AD1 ��3 PTE17
//      sensor_value[4] = adc_once( ADC0_SE3, ADC_ACCURACY);   //AD4 ��2 PTE18
//      sensor_value[0] = adc_once( ADC0_SE5a, ADC_ACCURACY);   //AD3 ��1 PTE16  
//}

/*
 *  @brief      ���������ݹ�һ��
 *  @since      v1.0
 *   sensor_value_normal   ��һ��������
 *   sensor_value       ��һ��ǰ����
*/
void Senser_normalization(uint16 * sensor_value)
{
  sensor_value[0] = (int)((sensor_value[0] / (float)(normalization_threshold[0])) * 100);
  sensor_value[1] = (int)((sensor_value[1] / (float)(normalization_threshold[1])) * 100);
  sensor_value[2] = (int)((sensor_value[2] / (float)(normalization_threshold[2])) * 100);
  sensor_value[3] = (int)((sensor_value[3] / (float)(normalization_threshold[3])) * 100);
  sensor_value[4] = (int)((sensor_value[4] / (float)(normalization_threshold[4])) * 100);
  sensor_value[5] = (int)((sensor_value[5] / (float)(normalization_threshold[5])) * 100);
  if(sensor_value[1]>100)
    sensor_value[1]=100;
  if(sensor_value[4]>100)
    sensor_value[4]=100;
}

/*
 *  @brief      ƫ�����
 *  @since      v1.0
 *  ad_normal   ��һ��ǰ����
*/
float cal_deviation(uint16 * sensor_value)
{
	float amp = 10000.0f;		//�Ŵ���
	float pwr_total = 0.0f;
	float position = 0.0f;
	float ad_sum = 0.0f;
	float sensor_value_copy[6] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};  
	float ad_cal[4] = {0.0f,0.0f,0.0f,0.0f};
	float minus[3] = {0.0f,0.0f,0.0f};
	float multiply[3] = {0.0f,0.0f,0.0f};
	float line[3] = {0.0f,0.0f,0.0f};
	float pwr[3] = {0.0f,0.0f,0.0f};
	float kp[3] = {0.0f,0.0f,0.0f};
	
	for(uint8 i = 0 ; i<6 ; i++)
	{
		sensor_value_copy[i] = (float)(sensor_value[i]);		//��ԭ���鸴��һ�ݣ��Ա㴦�� 
	}
	 
	sensor_value_copy[0] += 2.5f;		//������ֵΪ0ʱ�ᷢ�������������ÿ��ֵ������1 
	sensor_value_copy[1] += 2.5f;
	sensor_value_copy[2] += 2.5f;
	sensor_value_copy[3] += 2.5f;
	sensor_value_copy[4] += 2.5f;
	sensor_value_copy[5] += 2.5f;
	
	ad_cal[0] = sensor_value_copy[0];
        ad_cal[1] = sensor_value_copy[2];
	ad_cal[2] = sensor_value_copy[3];
        ad_cal[3] = sensor_value_copy[5];		

//        ad_sum = ad_cal[0] + ad_cal[1] + ad_cal[2] + ad_cal[3];
        
//	ad_cal[0] = (ad_cal[0] / ad_sum) * 295.0f ;		//�������
//	ad_cal[1] = (ad_cal[1] / ad_sum) * 295.0f ;
//	ad_cal[2] = (ad_cal[2] / ad_sum) * 295.0f ;
//	ad_cal[3] = (ad_cal[3] / ad_sum) * 295.0f ;
	
	minus[0] = (int)((ad_cal[1] - ad_cal[0]) * amp);		//���������������
	minus[1] = (int)((ad_cal[2] - ad_cal[1]) * amp);
	minus[2] = (int)((ad_cal[3] - ad_cal[2]) * amp);

	multiply[0] =((int)(ad_cal[0] + 10.0f)) * ((int)(ad_cal[1] + 10.0f));			//��������������
	multiply[1] =((int)(ad_cal[1] + 10.0f)) * ((int)(ad_cal[2] + 10.0f));
	multiply[2] =((int)(ad_cal[2] + 10.0f)) * ((int)(ad_cal[3] + 10.0f));

	line[0] = minus[0] / multiply[0];			//��Ȼ������������
	line[1] = minus[1] / multiply[1];
	line[2] = minus[2] / multiply[2];
        
//        printf("%5d %5d %5d\r\n",(int)(line[0]*100),(int)(line[1]*100),(int)(line[2]*100));
        
	line[0] = line[0] - 48.77;				//�Եڶ�������Ϊ��׼������Ư�ƣ����ߺ�һ
	line[1] = line[1];
	line[2] = line[2] + 45.60f;

	pwr[0] = (int)(ad_cal[0] + ad_cal[1]);			//���������������
	pwr[1] = (int)(ad_cal[1] + ad_cal[2]);
	pwr[2] = (int)(ad_cal[2] + ad_cal[3]);

	pwr[0] = pwr[0] * pwr[0];				//��һ�������ĺ�ֵ��ƽ��
	pwr[1] = pwr[1] * pwr[1];
	pwr[2] = pwr[2] * pwr[2];

	pwr_total = pwr[0] +pwr[1] + pwr[2];		//�����һ������ƽ���ĺ�

	kp[0] =((float)(pwr[0])) / ((float)(pwr_total));			//������ֱ�����ܺ͵ó���������
	kp[1] =((float)(pwr[1])) / ((float)(pwr_total));			//����������ڶ�̬������յ�����
	kp[2] =((float)(pwr[2])) / ((float)(pwr_total));			//Ϊɶ��ô����Ҳ��֪��

	position = ((kp[0] * line[0]) + (kp[1] * line[1]) + (kp[2] * line[2])) * 1;
        
	return position;
}

/*
 *  @brief         ���ߴ���
 *  @since         v1.0
 *  sensor_value   ������ֵ
 *��position       ƫ��ֵ       
*/
void loss_line_deal(uint16 * sensor_value , float position ,uint16 left_lose_threshold ,uint16 right_lose_threshold)
{
        static int32 error_add[3];
        int32 error_total = 0;
        uint16 sensor_value_total = 0;
        static uint8 loss_line_inc;
        
        for(uint8 i = 2 ; i>0 ; i--)
        {
            error_add[i] = error_add[i-1];              //����ѭ������
        }
        error_add[0] = (int)(position * 100);           //�����ε�ƫ��ŵ�����ͷ��
        error_total = error_add[0]  + error_add[1] + error_add[2];      //�������ƫ����ͣ������ж����ı߶���
        sensor_value_total = sensor_value[0] + sensor_value[2] + sensor_value[3] + sensor_value[5];                        //6��������ֵ��� 
        
        if((sensor_value_total < left_lose_threshold) || (sensor_value_total < right_lose_threshold))            //����6�������������ֵ�ж϶���
        {
            if((error_total > 0) && (loss_line == 0) && (sensor_value_total < left_lose_threshold))
            {
              loss_line = 1;  
              loss_line_lock=1;                   //����ʱ����1
            }
            else if((error_total < 0) && (loss_line == 0) && (sensor_value_total < right_lose_threshold)) 
            {
              loss_line = 2;  
              loss_line_lock=1;                   //�Ҷ���ʱ����2
            }
            else
            {;;}
        }
        else
        {
            if(loss_line_lock == 1)             //�˲�
            {
                loss_line_inc ++;
                if(loss_line_inc > 7)
                {
                    loss_line_lock = 0;
                    loss_line_inc =0;
                }
            }
            if(loss_line_lock == 0)
            {
                loss_line = 0;
            }
        }
}

/*
 *  @brief         �ܵ�����
 *  @note          ʵ�麯����Ч��δ֪
 *  @since         v1.0
 *��position       ƫ��ֵ
*/
uint8 out_line_deal(uint16 * sensor_value , float position)
{
    uint16 sensor_value_add[3];
    int16 sensor_value_minus;
    sensor_value_add[0] = sensor_value[0] + sensor_value[2] + sensor_value[3] + sensor_value[5];
    sensor_value_add[1] = sensor_value[0] + sensor_value[2];
    sensor_value_add[2] = sensor_value[3] + sensor_value[5];
    sensor_value_minus = sensor_value_add[1] - sensor_value_add[2];
    if((int)(position) > 0)
    {
        if(sensor_value_add[0] < 10)
        {
            if(ABS(sensor_value_minus) < 2)
            {
                return 1;                       //���߷���1
            }
        }
    }
    if((int)(position) < 0)
    {
        if(sensor_value_add[0] < 10)
        {
            if(ABS(sensor_value_minus) < 2)
            {
                return 2;                       //�Ҷ��߷���2
            }
        }
    } 
    return 0 ;                                   //�����߷���0
}

/*
 *  @brief         ƫ���˲�
 *  @since         v1.0
 *��position       ƫ��ֵ
*/
float position_filter(float position)
{
        static float position_add[10];
        float position_add_copy[10];
        int32 position_total = 0;
        float position_average;
        float temp = 0.0f;
        uint8 i = 0;
        uint8 j = 0;
        
        for( i = 9 ; i>0 ; i--)
        {
            position_add[i] = position_add[i-1];              //����ѭ������
        }
        position_add[0] = position;                           //�����ε�ƫ��ŵ�����ͷ�� 
        
        for(i=0;i<10;i++)
        {
            position_add_copy[i] = position_add[i];
        }  
        
        for( i=0;i<9;i++)                   //ð������
        {
            for( j=0;j<(9-i);j++)
            {
                    if(position_add_copy[j] > position_add_copy[j+1])
                    {
                            temp = position_add_copy[j];
                            position_add_copy[j] = position_add_copy[j+1];
                            position_add_copy[j+1] = temp;
                    }
            }
        }
        
        for( i=3 ; i<7 ;i++) 
        {
            position_total += position_add_copy[i];                        //ȥ����С��3��������3��������ֵ���
        } 
        position_average = position_total / 4.0f;
        
        if(position_average > 0.0f)                              //������ƫ����е�ƽ
        {
          position_average *= LEFT_PISITION_GAIN;
        }
        if(position_average < 0.0f)
        {
          position_average *= RIGHT_PISITION_GAIN;
        }
        
        if(position_average > POSITION_BOUND)                              //��ƫ������޷�
        {
          position_average = POSITION_BOUND;
        }
        if(position_average < (-(POSITION_BOUND)))
        {
          position_average = (-(POSITION_BOUND));
        }
        return position_average;  
}



/*
 *  @brief      ��������һ����ֵ�ɼ�
 *  @since      v1.0
*/
void Senser_normalization_threshold_get(void)
{
  uint8 collect_sign = 0;
  uint16 sensor_value_now[6] = {0,0,0,0,0,0};
  uint16 sensor_value_last[6] = {0,0,0,0,0,0};
  uint16 sensor_value_max[6] = {0,0,0,0,0,0};
  
  while(((switch_read())&(0x01)) == 0)
  {
    if(collect_sign == 0)
    {
      led(LED0,LED_ON);
      led(LED1,LED_ON);
      systick_delay_ms(200);
      led(LED0,LED_OFF);
      led(LED1,LED_OFF);
    }
    collect_sign = 1;
    
    Sensor_value_get(sensor_value_now);
    for(uint8 i = 0 ; i<6 ; i++)
    {
      if(sensor_value_max[i] < MAX(sensor_value_now[i] , sensor_value_last[i]))
      {
        sensor_value_max[i] = MAX(sensor_value_now[i] , sensor_value_last[i]);
      }
    }
    for(uint8 i = 0 ; i<6 ; i++)
    {
      sensor_value_last[i] = sensor_value_now[i];
    }      
   }
    if(collect_sign == 1)
    {
      flash_24c02_write_byte((uint8)sensor_value_max[0], 0);
      flash_24c02_write_byte((uint8)sensor_value_max[1], 1);
      flash_24c02_write_byte((uint8)sensor_value_max[2], 2);
      flash_24c02_write_byte((uint8)sensor_value_max[3], 3);
      flash_24c02_write_byte((uint8)sensor_value_max[4], 4);
      flash_24c02_write_byte((uint8)sensor_value_max[5], 5);
      led(LED0,LED_ON);
      led(LED1,LED_ON);
      systick_delay_ms(200);
      led(LED0,LED_OFF);
      led(LED1,LED_OFF);
    }    
}
/*
 *  @brief      ��������һ����ֵ��ȡ
 *  @since      v1.0
*/
void Senser_normalization_threshold_read(uint16 * normalization_threshold)
{
  for(uint8 i=0;i<6;i++)
  {
    normalization_threshold[i] = (uint16)flash_24c02_read_byte(i);
  }
  printf("%5d %5d %5d %5d %5d %5d\r\n",normalization_threshold[0],normalization_threshold[1],normalization_threshold[2],normalization_threshold[3],normalization_threshold[4],normalization_threshold[5]);
}

/*
 *  @brief      ƫ���¼
 *  @since      v1.0
 *  ��¼��ƫ�����ݴ���������position_accumulative[]��
*/
float position_record(float position)
{
    uint8 i = 0;
    float position_weighted = 0.0f;    
    for( i = 14 ; i>0 ; i--)
    {
        position_accumulative[i] = position_accumulative[i-1];              //����ѭ������
    }
    position_accumulative[0] = position;
    position_weighted = (0.6*position_accumulative[0]) + (0.25*position_accumulative[1]) + (0.15*position_accumulative[2]);
    return position_weighted;
}