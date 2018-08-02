#ifndef _PARAMETER_H_
#define _PARAMETER_H_

/**************全局变量外部申明*****************/
extern uint8 Flag_SpeedControl;
extern uint8 Flag_Stop;			//=1停车
extern uint8 Flag_Speed;			//=0加速度控制
extern uint8 Flag_Direction;		//=0加速度控制
extern uint8 Flag_Out;				//虚拟示波器显示标志
extern uint8 Flag_Buzz;			//=1蜂鸣器静音

extern uint8 debug_flag;
extern uint8 display_flag;
extern uint8 picture_already_flag;
/**************************摄像头接收解压数组******************************/
extern uint8  imgbuff1[CAMERA_SIZE];         //采集图像数组1
extern uint8  imgbuff2[CAMERA_SIZE];         //采集图像数组2
extern uint8 *  p_imgbuff1;   //图像地址1
extern uint8 *  p_imgbuff2;   //图像地址2
extern uint8  flag_imgbuff;
extern uint8  img[CAMERA_H][CAMERA_W];

extern uint8  bmp_buff[1024];
extern uint8  compress_buff[120][128];

/************************图像处理******************************************/
extern uint8 find;  //图像寻线标志位，两种寻线方式,默认跟踪搜索

extern int16 left_line[120];      //左边线
extern int16 right_line[120];     //右边线

extern int16 left_deal[120];      //左边线处理数组
extern int16 right_deal[120];     //右边线处理数组

extern int16 center_line[120];    //中心线存放数组

extern int16 last_start;

extern uint8 steer_run_flag;

extern int16 time_count;

extern int8 pit0_flag;

extern int16 lost_count;

extern int16 far_line;
/******************************************/
extern Site_t site;                           //显示图像左上角位置
extern Size_t imgsize;             //图像大小
extern Size_t size;                   //显示区域图像大小
extern Site_t site1;

extern uint8 SD_Record_Buff[512];
extern uint8 SD_Send_Buff[512];
extern uint16  Block_Index;
extern uint16  Block_Index_send;
extern void parameter_init(void);
extern void sdcard_record(void);
extern void sdcard_send(void);
#endif