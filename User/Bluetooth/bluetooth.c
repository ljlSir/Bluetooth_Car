#include "bluetooth.h"
#include "delay.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_it.h"
#include <stdio.h>
#include "motor.h"
 void My_USART2_Init(void)  

{  

    GPIO_InitTypeDef GPIO_InitStrue;  
    USART_InitTypeDef USART_InitStrue;  
    NVIC_InitTypeDef NVIC_InitStrue;        

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//GPIO�˿�ʹ��  
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//���ڶ˿�ʹ��  
      
    GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;  
    GPIO_InitStrue.GPIO_Pin=GPIO_Pin_2;  
    GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;  
    GPIO_Init(GPIOA,&GPIO_InitStrue);        
    GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;
  
    GPIO_InitStrue.GPIO_Pin=GPIO_Pin_3;  
    GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;  
    GPIO_Init(GPIOA,&GPIO_InitStrue);  

		 
    /* USARTx configured as follow:
       - BaudRate = 9600 baud  ������
       - Word Length = 8 Bits  ���ݳ���
       - One Stop Bit          ֹͣλ
       - No parity             У�鷽ʽ
       - Hardware flow control disabled (RTS and CTS signals) Ӳ��������
       - Receive and transmit enabled                         ʹ�ܷ��ͺͽ���
    */
      
    USART_InitStrue.USART_BaudRate=9600;  
    USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;  
    USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;  
    USART_InitStrue.USART_Parity=USART_Parity_No;  
    USART_InitStrue.USART_StopBits=USART_StopBits_1;  
    USART_InitStrue.USART_WordLength=USART_WordLength_8b;        
    USART_Init(USART2,&USART_InitStrue);
    USART_Cmd(USART2,ENABLE);//ʹ�ܴ���2  
    USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);//���������ж�  

      

    NVIC_InitStrue.NVIC_IRQChannel=USART2_IRQn;  
    NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;  
    NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;  
    NVIC_Init(&NVIC_InitStrue);       

}  

   //�жϷ�����  
u8 i;
extern u8 flag = 6;  //����һ����־λ
void USART2_IRQHandler(void)  
  
{  
     if(USART_GetITStatus(USART2, USART_IT_RXNE) == SET)      //���ָ���� USART2 �жϷ������
      { 
			USART_ClearITPendingBit(USART2, USART_IT_RXNE);   //��� USART2 ���жϴ�����λ
			i=  USART_ReceiveData(USART2);                    //���� USART2 ������յ�������
		//if�������ݲ��ֿ��Ա�֤�������յ���flag��������ȷ�ģ�������ӵĻ��ᵼ�½��ղ�����ȷ������
		  if(i=='0')
				{                 
					 flag=0;
				}
				
			if(i=='1')
				{
					 flag=1;
				}
				
			if(i=='2')
			   {
					 flag=2;
				}
			   
			if(i=='3')
			   {
								 
					flag=3;
			   }
			   
			if(i=='4')
			  {
					flag=4;
			  }
			  
			if(i=='5')
			  {
					flag=5;
			  }
			  
			if(i=='6')
			 {
					flag=6;
			 }

		  }
		  
//		  USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}

void App_Bluetooth(void)
{
		while(1){
				if(flag == 0)
				{
							 Car_Run(7200);
				}
				if(flag == 1)
				{
							 Car_Back(7200);
				}
				if(flag == 2)
				{
							Car_Right(7200);
				}
				if(flag == 3)
				{
							 Car_Left(7200);
				}
				if(flag == 4)
				{
							 Car_SpinRight(7200, 0);
				}
				if(flag == 5)
				{
							 Car_SpinLeft(7200, 7200);
				}
				if(flag == 6)
				{
							Car_Stop();
				}
		
		}
}
  



			
			