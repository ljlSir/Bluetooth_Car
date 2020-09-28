#ifndef __SERVO_H
#define __SERVO_H


#include "stm32f10x.h"

/*定义需要初始化的舵机宏定义开关*/

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

void Servo_J1(int v_iAngle);/*定义一个脉冲函数，用来模拟方式产生PWM值*/
void Servo_J2(int v_iAngle);/*定义一个脉冲函数，用来模拟方式产生PWM值*/


#endif 
