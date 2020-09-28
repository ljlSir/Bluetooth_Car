/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_timer.h	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        定时器
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#include "timer.h"


/**
* Function       TIM1_Int_Init
* @author        liusen
* @date          2015.01.03    
* @brief         定时器1初始化接口
* @param[in]     arr：自动重装值。psc：时钟预分频数
* @param[out]    void
* @retval        void
* @par History   这里时钟选择为APB1的2倍，而APB1为36M
*/
void TIM1_Int_Init(u16 arr,u16 psc)
{
	
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);// 
 
 
	
	//定时器TIM1初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1); //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim   //36Mhz
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;    //重复计数关闭
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE 主输出使能	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位

	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH1预装载使能	 
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH4预装载使能	 
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH1预装载使能	 
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH4预装载使能	
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE ); //使能指定的TIM1中断,允许更新中断
	TIM_ARRPreloadConfig(TIM1, ENABLE); //使能TIMx在ARR上的预装载寄存器
	
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //TIM1中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器


	TIM_Cmd(TIM1, ENABLE);  //使能TIMx					 
}
/**
* Function       TIM1_Int_Init
* @author        liusen
* @date          2015.01.03    
* @brief         定时器1中断服务程序: 
* @param[in]     arr：自动重装值。psc：时钟预分频数
* @param[out]    void
* @retval        void
* @par History   这里时钟选择为APB1的2倍，而APB1为36M
*/
int num = 0;


void TIM1_UP_IRQHandler(void)   //TIM1中断
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)  //检查TIM1更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  //清除TIM1更新中断标志 
		num++;
	

		if(num == 2000) //2000*10=20ms  20ms一个周期
		{
			num = 0;
		}
		
	}
}
