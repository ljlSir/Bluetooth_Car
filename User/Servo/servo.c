#include "servo.h"
#include "delay.h"
int Angle_J1;
int Angle_J2;
/**
* Function       Servo_J1
* @author        liusen
* @date          2017.07.17    
* @brief         舵机1控制函数
* @param[in]     v_iAngle 角度：0~180°
* @param[out]    void
* @retval        void
* @par History   无
*/
void Servo_J1(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J1_PORT, Servo_J1_PIN );		//将舵机接口电平置高
	delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J1_PORT, Servo_J1_PIN );	//将舵机接口电平置低
	delay_us(20000 - pulsewidth);			//延时周期内剩余时间
}

/**
* Function       Servo_J2
* @author        liusen
* @date          2017.07.17    
* @brief         舵机2控制函数
* @param[in]     v_iAngle 角度：0~180°
* @param[out]    void
* @retval        void
* @par History   无
*/
void Servo_J2(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J2_PORT, Servo_J2_PIN );		//将舵机接口电平置高
	delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J2_PORT, Servo_J2_PIN );	//将舵机接口电平置低
	delay_us(20000 - pulsewidth);			//延时周期内剩余时间
}




