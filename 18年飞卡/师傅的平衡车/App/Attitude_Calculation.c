/*********************************************************************************************************************
 * @file       		Attitude_Calculation.c
 * @author     		Alex
 * @version    		v1.0
 * @Software 		IAR 8.1
 * @date       		2016-11-9
 ********************************************************************************************************************/

#include "include.h"
#include "common.h"


AttitudeDatatypedef         Acc;
AttitudeDatatypedef         Gyro;


#define  XA    (-Acc.Xdata)
#define  YA     (Acc.Zdata)  
#define  ZA    (-Acc.Ydata)

#define  XG    (Gyro.Xdata)
#define  YG   (-Gyro.Zdata)
#define  ZG   (Gyro.Ydata)


#define  ATTITUDE_COMPENSATE_LIMIT   ((float)1 / 180 * PI / PERIODHZ)


QuaternionTypedef    Quaternion;
EulerAngleTypedef    EulerAngle;
QuaternionTypedef    AxisAngle;
EulerAngleTypedef    EulerAngleRate;

QuaternionTypedef    MeaQuaternion;
EulerAngleTypedef    MeaEulerAngle;
QuaternionTypedef    MeaAxisAngle;

QuaternionTypedef    ErrQuaternion;
EulerAngleTypedef    ErrEulerAngle;
QuaternionTypedef    ErrAxisAngle;


float XN, XE, XD;
float YN, YE, YD;
float ZN, ZE, ZD;


void Quaternion_Normalize(QuaternionTypedef *Qu)       //四元数归一化
{
	float Normal = 0;
	Normal = sqrtf(Qu->W * Qu->W + Qu->X * Qu->X + Qu->Y * Qu->Y + Qu->Z * Qu->Z);
	if (isnan(Normal) || Normal <= 0)
	{
		Qu->W = 1;
		Qu->X = 0;
		Qu->Y = 0;
		Qu->Z = 0;
	}
	else
	{
		Qu->W /= Normal;
		Qu->X /= Normal;
		Qu->Y /= Normal;
		Qu->Z /= Normal;
	}
}


// 四元数求逆, p=q^-1=q*/(|q|^2), 原始四元数需为单位四元数
void Quaternion_Invert(QuaternionTypedef *p, const QuaternionTypedef *q)
{
	p->W = q->W;
	p->X = -q->X;
	p->Y = -q->Y;
	p->Z = -q->Z;
}


// 四元数乘法, result=pq
void Quaternion_Multi(QuaternionTypedef *result, const QuaternionTypedef *p, const QuaternionTypedef *q)
{
	result->W = p->W * q->W - p->X * q->X - p->Y * q->Y - p->Z * q->Z;
	result->X = p->W * q->X + p->X * q->W - p->Y * q->Z + p->Z * q->Y;
	result->Y = p->W * q->Y + p->X * q->Z + p->Y * q->W - p->Z * q->X;
	result->Z = p->W * q->Z - p->X * q->Y + p->Y * q->X + p->Z * q->W;
}



void Quaternion_ToEulerAngle(const QuaternionTypedef *q, EulerAngleTypedef *e)  //四元数转欧拉角
{
	e->Roll = atan2f(2 * (q->W * q->X + q->Y * q->Z), 1 - 2 * (q->X * q->X + q->Y * q->Y));
	float k = 2 * (q->W * q->Y - q->Z * q->X);
	if (k > 1) k = 1;
	else if (k < -1) k = -1;
	e->Pitch = asinf(k);
	e->Yaw = atan2f(2 * (q->W * q->Z + q->X * q->Y), 1 - 2 * (q->Y * q->Y + q->Z * q->Z));
}


void Quaternion_FromEulerAngle(QuaternionTypedef *q, const EulerAngleTypedef *e) //欧拉角转四元数
{
	float cosx = cosf(e->Roll / 2);
	float sinx = sinf(e->Roll / 2);
	float cosy = cosf(e->Pitch / 2);
	float siny = sinf(e->Pitch / 2);
	float cosz = cosf(e->Yaw / 2);
	float sinz = sinf(e->Yaw / 2);
	q->W = cosx * cosy * cosz + sinx * siny * sinz;
	q->X = sinx * cosy * cosz - cosx * siny * sinz;
	q->Y = cosx * siny * cosz + sinx * cosy * sinz;
	q->Z = cosx * cosy * sinz - sinx * siny * cosz;
}

void Quaternion_ToAxisAngle(const QuaternionTypedef *q, QuaternionTypedef *a) //四元数转轴角
{
	a->W = 0;
	a->X = q->X;
	a->Y = q->Y;
	a->Z = q->Z;
	Quaternion_Normalize(a);
	a->W = acosf(q->W) * 2;
}

// 轴角转换为四元数
void Quaternion_FromAxisAngle(QuaternionTypedef *q, const QuaternionTypedef *a)
{
	float c = cosf(a->W / 2);
	float s = sinf(a->W / 2);
	q->W = 0;
	q->X = a->X;
	q->Y = a->Y;
	q->Z = a->Z;
	Quaternion_Normalize(q);
	q->W = c;
	q->X *= s;
	q->Y *= s;
	q->Z *= s;
}



//角速度周期转化四元数增量
void Quaternion_FromGyro(QuaternionTypedef *q, float wx, float wy, float wz, float dt)
{
	q->W = 1;
	q->X = wx * dt / 2;
	q->Y = wy * dt / 2;
	q->Z = wz * dt / 2;
	Quaternion_Normalize(q);
}


// 使用角速度更新四元数(一阶龙哥库塔法Runge-Kunta, 等价于使用角度增量)
void Quaternion_UpdateFromGyro(QuaternionTypedef *q, float x, float y, float z, float dt)
{
	float dW = 0.5 * (-q->X * x - q->Y * y - q->Z * z) * dt;
	float dX = 0.5 * (q->W * x + q->Y * z - q->Z * y) * dt;
	float dY = 0.5 * (q->W * y - q->X * z + q->Z * x) * dt;
	float dZ = 0.5 * (q->W * z + q->X * y - q->Y * x) * dt;
	q->W += dW;
	q->X += dX;
	q->Y += dY;
	q->Z += dZ;
	Quaternion_Normalize(q);
}



void QuaternionFromAcc(QuaternionTypedef *Qu, float ax, float ay, float az, float mx, float my, float mz)//采集加速度计获得四元数
{
	float Normal = 0;
	XD = ax;
	YD = ay;
	ZD = az;      //取重力方向
	Normal = sqrtf(XD * XD + YD * YD + ZD * ZD);
	XD /= Normal;
	YD /= Normal;
	ZD /= Normal;                //归一化


	XN = -mx; YN = -my; ZN = -mz;              //取磁力反方向为北
	Normal = XD * XN + YD * YN + ZD * ZN;      //北
	XN -= Normal*XD;
	YN -= Normal*YD;
	ZN -= Normal*ZD;                       //正交化
	Normal = sqrtf(XN * XN + YN * YN + ZN * ZN);
	XN /= Normal;
	YN /= Normal;
	ZN /= Normal;                       //归一化

	XE = YD*ZN - YN*ZD;                     //东//正交化
	YE = ZD*XN - ZN*XD;
	ZE = XD*YN - XN*YD;
	Normal = sqrtf(XE*XE + YE*YE + ZE*ZE);
	XE /= Normal;
	XE /= Normal;
	XE /= Normal;                   //归一化

	Qu->W = 0.5 * sqrtf(XN + YE + ZD + 1);   //旋转矩阵转换四元数
	Qu->X = (YD - ZE) / (4 * Qu->W);
	Qu->Y = (ZN - XD) / (4 * Qu->W);
	Qu->Z = (XE - YN) / (4 * Qu->W);
	Quaternion_Normalize(Qu);
	return;
}


void Quaternion_init()
{
	if (XA != 0 || YA != 0 || ZA != 0)
	{
		QuaternionFromAcc(&Quaternion, XA, YA, ZA, -1, 0, 0);
	}
	else
	{
		Quaternion.W = 1;
		Quaternion.X = 0;
		Quaternion.Y = 0;
		Quaternion.Z = 0;
	}
	Quaternion_ToEulerAngle(&Quaternion, &EulerAngle);
	Quaternion_ToAxisAngle(&Quaternion, &AxisAngle);
	EulerAngleRate.Pitch = 0;
	EulerAngleRate.Roll = 0;
	EulerAngleRate.Yaw = 0;
}


void Attitude_UpdateAcc(void)//深度融合更新
{
	QuaternionTypedef    EstQuaternion;
	EulerAngleTypedef    EstEulerAngle;
	QuaternionTypedef    DivQuaternion;
	QuaternionTypedef    ComAxisangle;
	QuaternionTypedef    Compensate;
	QuaternionTypedef    Last;


	QuaternionFromAcc(&MeaQuaternion, 0, YA, ZA, -1, 0, 0);
	Quaternion_ToEulerAngle(&MeaQuaternion, &MeaEulerAngle);
	Quaternion_ToAxisAngle(&MeaQuaternion, &MeaAxisAngle); //计算当前加速度计姿态

	EstEulerAngle.Roll = EulerAngle.Roll;
	EstEulerAngle.Pitch = EulerAngle.Pitch;
	EstEulerAngle.Yaw = 0;

	Quaternion_FromEulerAngle(&EstQuaternion, &EstEulerAngle);  //估计欧拉角转四元数

	   //计算估计与测得四元数偏差
	Quaternion_Invert(&DivQuaternion, &EstQuaternion);
	Quaternion_Multi(&ErrQuaternion, &DivQuaternion, &MeaQuaternion);
	Quaternion_Normalize(&ErrQuaternion);
	Quaternion_ToEulerAngle(&ErrQuaternion, &ErrEulerAngle);
	Quaternion_ToAxisAngle(&ErrQuaternion, &ErrAxisAngle);


	//轴角校正限幅

	memcpy(&ComAxisangle, &ErrAxisAngle, sizeof(QuaternionTypedef));
	if (ComAxisangle.W > ATTITUDE_COMPENSATE_LIMIT)
	{
		ComAxisangle.W = ATTITUDE_COMPENSATE_LIMIT;
	}
	Quaternion_FromAxisAngle(&Compensate, &ComAxisangle);


	//执行校正

	memcpy(&Last, &EstQuaternion, sizeof(QuaternionTypedef));
	Quaternion_Multi(&EstQuaternion, &Last, &Compensate);


	Quaternion_ToEulerAngle(&EstQuaternion, &EstEulerAngle);
	EstEulerAngle.Yaw = EulerAngle.Yaw;//不使用加速度计测偏航角
	Quaternion_FromEulerAngle(&Quaternion, &EstEulerAngle);
	Quaternion_ToEulerAngle(&Quaternion, &EulerAngle);
	Quaternion_ToAxisAngle(&Quaternion, &AxisAngle);
}


void Attitude_UpdateGyro(void)  //快速更新
{

	QuaternionTypedef   g1, tmp;
	EulerAngleTypedef   LastEulerAngle;
	QuaternionTypedef   LastQuanternion;

	//保留上一次的欧拉角和四元数
	memcpy(&LastEulerAngle, &EulerAngle, sizeof(EulerAngleTypedef));
	memcpy(&LastQuanternion, &Quaternion, sizeof(QuaternionTypedef));

	//进行姿态更新
	float gx = XG / 180 * PI;
	float gy = YG / 180 * PI;
	float gz = ZG / 180 * PI;

	Quaternion_UpdateFromGyro(&Quaternion, gx, gy, gz, PERIODS);
	Quaternion_ToEulerAngle(&Quaternion, &EulerAngle);
	Quaternion_ToAxisAngle(&Quaternion, &AxisAngle);

	// 计算欧拉角速度
	// Yaw为偏航角速度,为绕NED中的D轴(Z轴)旋转的角速度,使用四元数计算

	g1.W = 0; g1.X = gx; g1.Y = gy; g1.Z = gz;

	Quaternion_Invert(&LastQuanternion, &LastQuanternion);
	Quaternion_Multi(&tmp, &LastQuanternion, &g1);
	Quaternion_Invert(&LastQuanternion, &LastQuanternion);
	Quaternion_Multi(&g1, &tmp, &LastQuanternion);

	EulerAngleRate.Yaw = g1.Z;
	//Pitch为俯仰角速度, 为绕Y轴旋转的角速度, 使用???计算
	if (fabs(LastEulerAngle.Pitch - EulerAngle.Pitch) < PI / 2)
	{
		EulerAngleRate.Pitch = EulerAngle.Pitch - LastEulerAngle.Pitch;
	}
	else if (EulerAngle.Pitch - LastEulerAngle.Pitch > PI / 2)
	{
		EulerAngleRate.Pitch = -PI + (EulerAngle.Pitch - LastEulerAngle.Pitch);
	}
	else if (EulerAngle.Pitch - LastEulerAngle.Pitch < -PI / 2)
	{
		EulerAngleRate.Pitch = PI + (EulerAngle.Pitch - LastEulerAngle.Pitch);
	}

	EulerAngleRate.Pitch /= PERIODS;
	//Roll为横滚角速度, 绕X''轴旋转的角速度, 直接使用陀螺仪数据
	EulerAngleRate.Roll = gx;
}

