#include "servo.h"
#include "delay.h"
int Angle_J1;
int Angle_J2;
/**
* Function       Servo_J1
* @author        liusen
* @date          2017.07.17    
* @brief         ���1���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J1(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J1_PORT, Servo_J1_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J1_PORT, Servo_J1_PIN );	//������ӿڵ�ƽ�õ�
	delay_us(20000 - pulsewidth);			//��ʱ������ʣ��ʱ��
}

/**
* Function       Servo_J2
* @author        liusen
* @date          2017.07.17    
* @brief         ���2���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J2(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J2_PORT, Servo_J2_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J2_PORT, Servo_J2_PIN );	//������ӿڵ�ƽ�õ�
	delay_us(20000 - pulsewidth);			//��ʱ������ʣ��ʱ��
}




