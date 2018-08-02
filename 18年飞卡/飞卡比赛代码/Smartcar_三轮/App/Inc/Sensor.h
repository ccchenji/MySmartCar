/*
* @file         Sensor.h
  * @brief      �������ɼ���غ���ʵ��
  * @author     xiao_fang
  * @version    v1.0
  * @date       2017-3-12
*/
#ifndef __SENSOR_H__
#define __SENSOR_H__

#define ADC_ACCURACY ADC_8bit   //����AD��ֵ����

#define LEFT_LOSE_LINE_THRESHOLD    35  //�����󴫸���������ֵ
#define RIGHT_LOSE_LINE_THRESHOLD    35  //�����Ҵ�����������ֵ

#define LEFT_PISITION_GAIN           1.0        //������ƫ���ƽֵ
#define RIGHT_PISITION_GAIN           1.0       //������ƫ���ƽֵ

#define POSITION_BOUND               200        //����ƫ���޷�ֵ

#define ADC_CH0 ADC0_SE12
#define ADC_CH1 ADC0_SE13
#define ADC_CH2 ADC0_SE14
#define ADC_CH3 ADC0_SE15


void Sensor_init(void);         //��ʼ��������
void Sensor_value_get(uint16 * sensor_value);   //��ȡһ�δ�����ֵ����������
void Senser_normalization(uint16 * sensor_value);        // ���������ݹ�һ��
float cal_deviation(uint16 * sensor_value);           //ƫ�����
void loss_line_deal(uint16 * sensor_value , float position ,uint16 left_lose_threshold ,uint16 right_lose_threshold);        //���ߴ���
uint8 out_line_deal(uint16 * sensor_value , float position);         //�ܵ�����
float position_filter(float position);                          //ƫ���˲�
void Senser_normalization_threshold_get(void);                   //��������һ����ֵ�ɼ�
void Senser_normalization_threshold_read(uint16 * normalization_threshold);       //��������һ����ֵ��ȡ
float position_record(float position);                                           //ƫ���¼
#endif
