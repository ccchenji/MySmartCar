#include "Inc/Fuzzy_control.h"
#include "common.h"
#include "include.h"

/*!
*  @brief      ��С���˷�����б��
*  @param	   ��ʼ���� �������� ��������
*  @return     б��
*  @author	   Jassy
*  @date	   20170416
*  @note
*/
float Least_squares(int start, int end, float X[10])
{
	int sumX = 0, sumY = 0, avrX = 0, avrY = 0;
	int num = 0, B_up1 = 0, B_up2 = 0, B_up = 0, B_down = 0;
	float slope = 0;//б��
	int i;
	for (i = start; i <= end; i++)
	{
		if (X[i])
		{
			num++;
			sumX += i;
			sumY += X[i];
		}
	}
	avrX = sumX / num;
	avrY = sumY / num;
	B_up = 0;
	B_down = 0;
	for (i = start; i <= end; i++)
	{
		if (X[i])
		{
			B_up1 = (int)X[i] - (int)avrY;
			B_up2 = i - avrX;
			B_up += (int)B_up1 * (int)B_up2;
			//B_up=B_up/100*100;
			B_down += (int)(i - avrX) * (int)(i - avrX);
		}
	}
	if (B_down == 0) slope = 0;
	else slope = B_up * 10 / B_down;
	return slope;
}

/*!
*  @brief      ģ������KP����
*  @param	   P����ֵ  D����ֵ 
*  @return     ����kp���
*  @author	   Jassy
*  @date	   20170416
*  @note
*/
float fuzzy_caculate_dirkp(float P, float D)
{
	/*������P����ֵ������ ����PΪ�ٶ�*/
	float PFF[7] = { 2000,2500,3000,3500,4000,4500,5000, };
	/*������D����ֵ������ ����DΪ�ٶȱ仯��*/
	float DFF[5] = { -15,-10,5,10,15 };
	/*�����U����ֵ������ �������kP��С*/
	float UFF[7] = { 25,35,45,55,65,75,90 };
	int rule[7][5] =
	{

		{ 0, 1, 2, 2, 3 }, //  0
		{ 1, 2, 2, 3, 3 }, //  1
		{ 2, 2, 3, 3, 4 }, //  2
		{ 2, 2, 3, 4, 5 }, //  3
		{ 2, 3, 4, 5, 5 }, //  4
		{ 3, 4, 5, 6, 6 }, //  5
		{ 4, 5, 5, 6, 6 } //  6
	};
	float U = 0;
	/*ƫ��,ƫ��΢���Լ����ֵ�ľ�ȷ��*/
	float PF[2] = { 0 }, DF[2] = { 0 }, UF[4] = { 0 };
	/*ƫ��,ƫ��΢���Լ����ֵ��������*/
	int Pn = 0, Dn = 0, Un[4] = { 0 };
	float t1 = 0, t2 = 0, t3 = 0, t4 = 0, temp1 = 0, temp2 = 0;
	/*ȷ��P������*/
	/*PF[0]�������� PF[1]��������*/
	if (P > PFF[0] && P < PFF[6])
	{
		if (P <= PFF[1])
		{
			Pn = 1;
			PF[0] = (PFF[1] - P) / (PFF[1] - PFF[0]);
		}
		else if (P <= PFF[2])
		{
			Pn = 2;
			PF[0] = (PFF[2] - P) / (PFF[2] - PFF[1]);
		}
		else if (P <= PFF[3])
		{
			Pn = 3;
			PF[0] = (PFF[3] - P) / (PFF[3] - PFF[2]);
		}
		else if (P <= PFF[4])
		{
			Pn = 4;
			PF[0] = (PFF[4] - P) / (PFF[4] - PFF[3]);
		}
		else if (P <= PFF[5])
		{
			Pn = 5;
			PF[0] = (PFF[5] - P) / (PFF[5] - PFF[4]);
		}
		else if (P <= PFF[6])
		{
			Pn = 6;
			PF[0] = (PFF[6] - P) / (PFF[6] - PFF[5]);
		}
	}
	else if (P <= PFF[0]) //С������
	{
		Pn = 0;
		PF[0] = 1;
	}
	else if (P >= PFF[6]) //��������
	{
		Pn = 6;
		PF[0] = 0;
	}
	PF[1] = 1 - PF[0];

	/*�ж�D��������*/
	if (D > DFF[0] && D < DFF[4])
	{
		if (D <= DFF[1])
		{
			Dn = -2;
			DF[0] = (DFF[1] - D) / (DFF[1] - DFF[0]);
		}
		else if (D <= DFF[2])
		{
			Dn = -1;
			DF[0] = (DFF[2] - D) / (DFF[2] - DFF[1]);
		}
		else if (D <= DFF[3])
		{
			Dn = 0;
			DF[0] = (DFF[3] - D) / (DFF[3] - DFF[2]);
		}
		else if (D <= DFF[4])
		{
			Dn = 1;
			DF[0] = (DFF[4] - D) / (DFF[4] - DFF[3]);
		}
	}
	//���ڸ�����������
	else if (D <= DFF[0])
	{
		Dn = -2;
		DF[0] = 1;
	}
	else if (D >= DFF[4])
	{
		Dn = 2;
		DF[0] = 0;
	}
	DF[1] = 1 - DF[0];
	/*ȷ��U������*/
	/*һ�㶼���ĸ�������Ч*/
	if (Pn >= 6 && Dn <= 1)
	{
		Un[0] = rule[Pn - 1][Dn + 2];
		Un[1] = rule[Pn][Dn + 2];
		Un[2] = rule[Pn - 1][Dn + 1 + 2];
		Un[3] = rule[Pn][Dn + 1 + 2];
	}
	else if (Dn >= 2 && Pn <= 5)
	{
		Un[0] = rule[Pn][Dn - 1 + 2];
		Un[1] = rule[Pn + 1][Dn - 1 + 2];
		Un[2] = rule[Pn][Dn + 2];
		Un[3] = rule[Pn + 1][Dn + 2];
	}
	else if (Pn == 6 && Dn == 2)
	{
		Un[0] = rule[Pn - 1][Dn - 1 + 2];
		Un[1] = rule[Pn][Dn - 1 + 2];
		Un[2] = rule[Pn - 1][Dn + 2];
		Un[3] = rule[Pn][Dn + 2];
	}
	else
	{
		Un[0] = rule[Pn][Dn + 2];
		Un[1] = rule[Pn + 1][Dn + 2];
		Un[2] = rule[Pn][Dn + 1 + 2];
		Un[3] = rule[Pn + 1][Dn + 1 + 2];
	}
	//���Ӧ�õ�ֵģ������ö�Ӧ�������������
	if (PF[0] <= DF[0]) //��С ����U�������ȣ�
		UF[0] = PF[0];
	else
		UF[0] = DF[0];
	if (PF[1] <= DF[0])
		UF[1] = PF[1];
	else
		UF[1] = DF[0];
	if (PF[0] <= DF[1])
		UF[2] = PF[0];
	else
		UF[2] = DF[1];
	if (PF[1] <= DF[1])
		UF[3] = PF[1];
	else
		UF[3] = DF[1];


	/*ͬ���������������ֵ���*/
	if (Un[0] == Un[1]) //����ȵ�����ֵ�������Ƚ��д���
	{
		if (UF[0] > UF[1])
			UF[1] = 0;
		else
			UF[0] = 0;
	}
	if (Un[0] == Un[2])
	{
		if (UF[0] > UF[2])
			UF[2] = 0;
		else
			UF[0] = 0;
	}
	if (Un[0] == Un[3])
	{
		if (UF[0] > UF[3])
			UF[3] = 0;
		else
			UF[0] = 0;
	}
	if (Un[1] == Un[2])
	{
		if (UF[1] > UF[2])
			UF[2] = 0;
		else
			UF[1] = 0;
	}
	if (Un[1] == Un[3])
	{
		if (UF[1] > UF[3])
			UF[3] = 0;
		else
			UF[1] = 0;
	}
	if (Un[2] == Un[3])
	{
		if (UF[2] > UF[3])
			UF[3] = 0;
		else
			UF[2] = 0;
	}

	t1 = UF[0] * UFF[Un[0]];
	t2 = UF[1] * UFF[Un[1]];
	t3 = UF[2] * UFF[Un[2]];
	t4 = UF[3] * UFF[Un[3]];

	temp1 = t1 + t2 + t3 + t4;
	temp2 = UF[0] + UF[1] + UF[2] + UF[3];//ģ�������
	U = temp1 / temp2;
	return U;

}
