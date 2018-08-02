#ifndef _PARAMETER_H_
#define _PARAMETER_H_

/**************ȫ�ֱ����ⲿ����*****************/
extern uint8 Flag_SpeedControl;
extern uint8 Flag_Stop;			//=1ͣ��
extern uint8 Flag_Speed;			//=0���ٶȿ���
extern uint8 Flag_Direction;		//=0���ٶȿ���
extern uint8 Flag_Out;				//����ʾ������ʾ��־
extern uint8 Flag_Buzz;			//=1����������

extern uint8 debug_flag;
extern uint8 display_flag;
extern uint8 picture_already_flag;
/**************************����ͷ���ս�ѹ����******************************/
extern uint8  imgbuff1[CAMERA_SIZE];         //�ɼ�ͼ������1
extern uint8  imgbuff2[CAMERA_SIZE];         //�ɼ�ͼ������2
extern uint8 *  p_imgbuff1;   //ͼ���ַ1
extern uint8 *  p_imgbuff2;   //ͼ���ַ2
extern uint8  flag_imgbuff;
extern uint8  img[CAMERA_H][CAMERA_W];

extern uint8  bmp_buff[1024];
extern uint8  compress_buff[120][128];

/************************ͼ����******************************************/
extern uint8 find;  //ͼ��Ѱ�߱�־λ������Ѱ�߷�ʽ,Ĭ�ϸ�������

extern int16 left_line[120];      //�����
extern int16 right_line[120];     //�ұ���

extern int16 left_deal[120];      //����ߴ�������
extern int16 right_deal[120];     //�ұ��ߴ�������

extern int16 center_line[120];    //�����ߴ������

extern int16 last_start;

extern uint8 steer_run_flag;

extern int16 time_count;

extern int8 pit0_flag;

extern int16 lost_count;

extern int16 far_line;
/******************************************/
extern Site_t site;                           //��ʾͼ�����Ͻ�λ��
extern Size_t imgsize;             //ͼ���С
extern Size_t size;                   //��ʾ����ͼ���С
extern Site_t site1;

extern uint8 SD_Record_Buff[512];
extern uint8 SD_Send_Buff[512];
extern uint16  Block_Index;
extern uint16  Block_Index_send;
extern void parameter_init(void);
extern void sdcard_record(void);
extern void sdcard_send(void);
#endif