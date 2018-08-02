#ifndef	 __Attitude_Calculation_h__
#define	 __Attitude_Calculation_h__  

#ifndef  PI
#define  PI            3.1415926f
#endif
#define  PERIODHZ      (float)200       /////����Ƶ��
#define  PERIODS        0.005           ////��������

typedef struct{
  float W;
  float X;
  float Y;
  float Z;
}QuaternionTypedef;

typedef struct{ 
  float Pitch;  //������
  float Yaw;    //ƫ����
  float Roll;   //������
}EulerAngleTypedef;


typedef struct{
  float Xdata;
  float Ydata;
  float Zdata;
}AttitudeDatatypedef;

extern QuaternionTypedef    Quaternion;   //��Ԫ��
extern EulerAngleTypedef    EulerAngle;   //ŷ����
extern QuaternionTypedef    AxisAngle;    //���
extern EulerAngleTypedef    EulerAngleRate;//��ǰŷ�����ٶ�

extern QuaternionTypedef    MeaQuaternion;
extern EulerAngleTypedef    MeaEulerAngle;
extern QuaternionTypedef    MeaAxisAngle;

extern QuaternionTypedef    ErrQuaternion;
extern EulerAngleTypedef    ErrEulerAngle;
extern QuaternionTypedef    ErrAxisAngle;
extern AttitudeDatatypedef         Acc;
extern AttitudeDatatypedef         Gyro;


extern void Quaternion_init();

extern void Attitude_UpdateGyro(void);

extern void Attitude_UpdateAcc(void);

#endif