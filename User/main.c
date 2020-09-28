#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "delay.h"
#include "bluetooth.h"
#include "timer.h"
#include "gpio.h"
#include "motor.h"
#include "sys.h"



int main (void)
{
	delay_init();
	MOTOR_GPIO_Init();  
	My_USART2_Init();  
	Motor_PWM_Init(7200,0,7200,0);


	App_Bluetooth();
}

