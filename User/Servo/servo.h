#ifndef __SERVO_H
#define __SERVO_H


#include "stm32f10x.h"

/*������Ҫ��ʼ���Ķ���궨�忪��*/

#define USE_SERVO_J1
#define USE_SERVO_J2


extern int Angle_J1;
extern int Angle_J2;


#define Servo_J1_PIN	GPIO_Pin_8  
#define Servo_J2_PIN	GPIO_Pin_9


#define Servo_J1_PORT	GPIOA
#define Servo_J2_PORT	GPIOA


#define Servo_J1_RCC	RCC_APB2Periph_GPIOA
#define Servo_J2_RCC	RCC_APB2Periph_GPIOA

void Servo_J1(int v_iAngle);/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
void Servo_J2(int v_iAngle);/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/


#endif 
