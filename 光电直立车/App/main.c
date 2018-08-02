/*
				 �������������[ �����������[ �����[   �����[ �������������[
				�����X�T�T�T�T�a�����X�T�T�����[�����U   �����U�����X�T�T�T�T�a
				�����U     ���������������U�����U   �����U�����U
				�����U     �����X�T�T�����U�����U   �����U�����U
				�^�������������[�����U  �����U�^�������������X�a�^�������������[
				 �^�T�T�T�T�T�a�^�T�a  �^�T�a �^�T�T�T�T�T�a  �^�T�T�T�T�T�a
*/
/*!
 * @file       main.c
 * @brief      2017�����ֱ����ܳ�������
 * @author     Jassy
 * @date       2016-12-01
 * @note	   2017-04-23��д 
 */
#include "common.h"
#include "include.h"
#include "../SOLGUI/SOLGUI_Menu.h"
#include "../SOLGUI/SOLGUI_Common.h"
#define SECTOR_NUM  (FLASH_SECTOR_NUM-1)         //������������������ȷ����ȫ 
#define Bet     ADC1_SE6a                        //�����ص�ѹ����AD����
#define FloatFillStr(x,y)   ((*(float *)&y)=x)   //������תchar������
#define StrFillFloat(x,y)   (y=(*(float *)&x))   //char������ת������ 
#define SW_1_carflag		PTE3	
#define SW_2_undef			PTE4
#define SW_3_OLEDreflash	PTE5
#define Test_IO				PTE9
#define Beep				PTC1
//====================��������========================
//�ڲ������ǵü�static 
//ʹ�ö��Խ��а�ȫ��� 
void PIT0_IRQHandler(void);
void PIT1_IRQHandler(void);
void PORTA_IRQHandler(void);
void DMA0_IRQHandler(void);
void UsartSendnum(char ID, float num);
//====================��������========================
//�ж����ñ����ǵü�volatile
//ֻ�������ǵü�constant 
//����ȫ�ֱ������� ��static���� ������ʿɹ��캯��
uint8 key_value = 0;
uint8 imgbuff[CAMERA_SIZE]; //����洢����ͼ�������
float bet_value = 0;
float vcan_send_buff[8]; //ɽ����λ������ʾ����
KEY_MSG_t keymsg;        
int img_send_cnt = 0; //����ͼ���������
char img_send_flag = 0; //����ͼ���־λ  
char num_send_flag = 0; //���Ͳ�����־λ
char vcan_send_flag = 0; //ɽ����λ�����ͱ�־λ
char car_1or2_flag = 0; //��1��2��־
int beep_time = 0;    //��������ʱ��
int beep_cnt = 0;      //���������ʱ
int stop_flag_cnt = 0;
//++++++++++++++++++++++++++++++++++++++++++++++++++++
/*!
 *  @brief      main����
 *  @note       
 */
//system_MK60DZ10.c main����֮ǰstart�����ڿ���Ӳ������
void main()
{
	DisableInterrupts; //�����ж�
	printf("Init......begin\n");
	printf("**************************\n");
	/*		���԰�����ʼ��
	*KEYӲ��������VCAN_key.c�ļ��޸� 
	*ö������KEY_e 
	*/
	printf("Key Init......");
	key_init(KEY_MAX);					 //��ʼ��ȫ������
	gpio_init(SW_1_carflag, GPI, 1);	 //e3Ϊ����ʶ���־
	gpio_init(SW_2_undef  , GPI, 1);
	gpio_init(SW_3_OLEDreflash, GPI, 1); //��ʼ�����뿪�� 
	gpio_init(Test_IO, GPO, 1);			 //����ʱ���� 
	printf("OK\n");
	printf("Car flag Read......");
	if (gpio_get(SW_1_carflag) == 0)
	{
		car_1or2_flag = 1;
	} //2��
	else
	{
		car_1or2_flag = 0;
	} //1��
	printf("OK\n");
	/*��ʼ����ѹ����ADC*/
	printf("ADC_bet Init......");
	adc_init(Bet);
	printf("OK\n");
	/*��������ʼ��*/
	printf("Beep Init......");
	gpio_init(Beep, GPO, 0); //��������
	printf("OK\n");
	/*OLED��ʼ��*/
	printf("OLED Init......");
	OLED_Init(); //��ʼ��OLED
	OLED_Fill(0x00); //����
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
	/*UI�����ʼ��*/
	printf("UI Init......");
	SOLGUI_Init(&UI_List);		    //UI��ʼ������
	SOLGUI_Refresh();		    	//UIˢ�� 
	printf("OK\n");
	/*		FTMģ���ʼ�� 
	*Ƶ�� 8K ���� 1000 
	*�����޸�  MK60_FTM.H -> FTM0_PRECISON
	*/
	printf("PWM Init......");
	MotorInit();
	printf("OK\n");
	/*		���I2C��ʼ��      */
	printf("I2C Init......");
	IMU_IIC_Init();
	printf("OK\n");
	/*		��̬��������ʼ��      */
	printf("8451&3050 Init......");
	UpstandInit();
	printf("OK\n");
	/*       ���������ʼ��      */
	printf("Encoder Init......");
	Encoder_Init();
	port_init_NoALT(PTA12, PF | PULLUP);//�ڲ���������
	port_init_NoALT(PTA13, PF | PULLUP);
	port_init_NoALT(PTA10, PF | PULLUP);
	port_init_NoALT(PTA11, PF | PULLUP);
	printf("OK\n");
	/*       FLASH��ʼ��         */
	printf("Flash Init......");
	flash_init(); //��ʼ��flash
	parameter_init(); //��ʼ������  �˴�װ�����е��粻��ʧ����  
	printf("OK\n");
	/*       ����ͷ��ʼ��        */
	printf("Camera Init......");
	camera_init(p_imgbuff1);
	printf("OK\n");
	/*        �����ж�����       */
	printf("Interrupt Init......");
	NVIC_SetPriorityGrouping(4);		//�����жϷ���
	set_irq_priority(DMA0_IRQn, 2);
	set_irq_priority(PORTA_IRQn, 2);
	//NVIC_SetPriority(PIT0_VECTORn, 2); //����1ms�жϸ����ȼ�
	NVIC_SetPriority(PIT1_VECTORn, 3);	 //����5ms�жϵ����ȼ�
	set_vector_handler(PORTA_VECTORn, PORTA_IRQHandler); 
	set_vector_handler(DMA0_VECTORn, DMA0_IRQHandler); 
	/*    ��ʼ��PIT��ʱ���ж�    */
	//pit_init_ms(PIT0, 5); //��ʼ��PIT0����ʱʱ��Ϊ�� 1ms
	//set_vector_handler(PIT0_VECTORn, PIT0_IRQHandler); //����PIT0���жϷ�����Ϊ PIT0_IRQHandler
	//enable_irq(PIT0_IRQn); //ʹ��PIT0�ж�  
	pit_init_ms(PIT1, 80);
	set_vector_handler(PIT1_VECTORn, PIT1_IRQHandler);
	enable_irq(PIT1_IRQn);
	ov7725_eagle_img_flag = IMG_START;      //��ʼ�ɼ�ͼ��
	enable_irq(PORTA_IRQn);                 //����PTA���ж�
	printf("OK\n");
	printf("**************************\n");
	printf("Init...Over\n");
	EnableInterrupts; //�����ж�
	while (1)
	{
		//����ͼ��		
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
			//��β
			uart_putchar(UART1, 0xcc);
			uart_putchar(UART1, 0xdd);
			uart_putchar(UART1, 0xee);
		}
		//���Ͳ���
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
			//��β
			uart_putchar(UART1, 0xcc);
			uart_putchar(UART1, 0xdd);
			uart_putchar(UART1, 0xee);
		}
		vcan_send_buff[0] = g_fRealSpeed;
		//����ɽ����λ������
		if (vcan_send_flag == 1)
		{
			vcan_sendware((uint8_t *)vcan_send_buff, sizeof(vcan_send_buff));
		}
		//��������	
		if (gpio_get(SW_3_OLEDreflash) == 0)
		{
			OLED_Init();
			OLED_Fill(0x00);
		}								
		bet_value = (float)(ad_ave(Bet, ADC_12bit, 10)) / 4096 * 3.3 * 3; //������ص�ѹ                                 
	}
}



/*!
*  @brief      PIT0�жϷ�����
*  @author	   Jassy
*  @date	   20161201
*  @note       
*/
void PIT0_IRQHandler(void)
{
	PIT_Flag_Clear(PIT0); //���жϱ�־λ
}

void PIT1_IRQHandler(void)
{
	key_value = key_scan();
	SOLGUI_InputKey(key_value);//����GUI 
    SOLGUI_Menu_PageStage();
	SOLGUI_Refresh(); //OLEDǰ̨ˢ��
	PIT_Flag_Clear(PIT1);
}

/*!
*  @brief      PORTA�жϷ�����
*  @since      v5.0
*/
void PORTA_IRQHandler()
{
	uint8 n; //���ź�
	uint32 flag;

	while (!PORTA_ISFR);
	flag = PORTA_ISFR;
	PORTA_ISFR = ~0; //���жϱ�־λ

	n = 29; //���ж�
	if (flag & (1 << n)) //PTA29�����ж�
	{
			//gpio_set(Test_IO, 1);
			camera_vsync();   //��ʼ�ɼ�ͼ��(����ͼ���ַ)
			flag_imgbuff != 0 ? img_extract(img, p_imgbuff1, CAMERA_SIZE) : img_extract(img, p_imgbuff2, CAMERA_SIZE);
			//��ѹ��һ��ͼ��													 800us
			DirectionControl();		//����������							 1.8ms
			GalAcceAndGyroY();		//�ɼ�������ٶȼƺ�������					 1ms
			KalmanFilter();			//�������˲����ó��Ƕ� ʱ��				 40us
			BalanceControl();		//ֱ���������
			PWMOut();				//����PWM�������������εķ��������ֱ��������ϴε��ٶ�������ӣ�
			Flag_SpeedControl++;
			if (Flag_SpeedControl >= 20)
			{
				SpeedControl();		//�ٶȿ�������20*(1/150)s
				Flag_SpeedControl = 0;
			}
			SpeedControlOut();		//�ٶ�������ڣ�1/150��s��Ҳ����ÿ�ε��ٶȿ��Ʒ�20�����
			stop_flag_cnt++;
			if(stop_flag_cnt>=1500)
			{
				stop_flag_cnt = 1500;
			}
			if(beep_time>0)
			{
				gpio_init(Beep, GPO, 0); //�������� 
				beep_time--;
			}
			else
			{
				gpio_init(Beep, GPO, 1); //�ط�����
				beep_time = 0;
			}
	}
}

/*!
*  @brief      DMA0�жϷ�����
*  @since      v5.0
*/
void DMA0_IRQHandler()
{
	camera_dma();
	camera_get_img();	//�ȴ�ͼ������ϣ���ɱ�־��Ϊ��ʼ��־��
	flag_imgbuff = !flag_imgbuff;
	ov7725_eagle_img_buff = (flag_imgbuff == 0 ? p_imgbuff1 : p_imgbuff2);//�����ʼ��ͼ���ַ
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
