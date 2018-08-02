#ifndef _image_deal_new_
#define _image_deal_new_

#include "common.h"
#include "include.h"

#define PP(i,j)    img[(i)][(j)]	//图像中一点，坐标（i，j）
#define LL(i)      left_line[(i)]	//左边线点
#define RL(i)      right_line[(i)]	//右边线点
#define CL(i)      center_line[(i)]	//中心线点
#define SL(i)      start_line[(i)]	//起始搜线点

#define BLACK_P    (0)	//定义黑点
#define WHITE_P    (1)	//定义白点

#define LEFT       (0)
#define RIGH       (1)

typedef enum
{
	normal = 0,				//初始化状态
	bef_in_circle_left,	//进入环岛之前
	mid_in_circle_left,	//进入环岛之中
	aft_in_circle_left,	//进入环岛之后
	bef_out_circle_left,	//出环岛之前
	mid_out_circle_left,	//出环岛之中
	aft_out_circle_left,	//出环岛之后  
	bef_in_circle_righ,	//右进入环岛之前
	mid_in_circle_righ,	//右进入环岛之中
	aft_in_circle_righ,	//右进入环岛之后
	bef_out_circle_righ,	//左进入环岛之前
	mid_out_circle_righ,	//左进入环岛之中
	aft_out_circle_righ, 	//左进入环岛之后   
}position;		//车在环岛位子标志结构体

typedef enum
{
	normal_ten = 0,	//初始化状态
	bef_ten,		//十字弯前
	mid_ten,		//十字弯中
	aft_ten,		//十字弯后

}ten_status;	//车在十字弯位子标志结构体

typedef enum
{
	running = 0,	//运行
	stop = 1,		//停车
}status;	//车启停状态结构体（用在识别斑马线停车）

			/**************picture_deal_global_var******/
extern position car_position;
extern status   car_status;
extern char obstacle ;
extern ten_status car_ten_status;
extern int16 left_line[120];
extern int16 right_line[120];
extern int16 center_line[120];
extern int16 start_line[120];
extern int16 compensation_line[10];
extern int16 near_lost_count_left;
extern int16 near_lost_count_righ;
extern int16 lost_to_have_flag;
extern int16 turn_flag;
extern int16 lost_count;
extern int16 circle_offset;

extern float direc_err_1;
extern float direc_err_2;
extern float direc_err_3;
extern int ob_left;
extern int ob_right;
extern int ob_err;
extern int ob_cnter;
extern int ttt_cnt;
/**************function*********************/
extern float get_picture_diff(int16 sline, int16 eline);

void param_reset(void);
status check_end_line(int16 sline, int16 eline);
char check_obstacle(int16 sline, int16 eline);
int16 search_start(int16 sline, int16 eline);
int16 gb_recursion(int16 start, int16 end, int16 line);
void find_line(int16 line, int16 start);
void judge_init_start(int16 line);
float get_average_diff(int16 i, int16 j, int16* arry);
int16 partition(int16 arr[], int16 low, int16 high);
void quick_sort(int16 arr[], int16 start, int16 end);
int16 judge_next_line(int16 sline, int16 eline, int16 start);
int16 search_black_line(int16 line, int16 start);
int16 search_white_line(int16 line, int16 start);
int16 judge_column(int16 line);
void judge_position(void);
void ProgressCircle();
void GetBlackEndParam();
#endif /*_picture_deal_*/
