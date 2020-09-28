/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_timer.h	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        定时器初始化
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#ifndef __TIMER_H__
#define __TIMER_H__

#include "stm32f10x.h"


void TIM1_Int_Init(u16 arr,u16 psc);


#endif
