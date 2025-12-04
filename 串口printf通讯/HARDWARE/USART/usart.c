#include "stm32f10x.h"
#include "usart.h"
#include "stdio.h"

u8 num=0;

#pragma import(__use_no_semihosting)
//标准库需要的支持函数
struct __FILE
{
    int handle;
};
 
FILE __stdout;

/**
 * @brief 定义_sys_exit()以避免使用半主机模式
 * @param void
 * @return  void
 */

void _sys_exit(int x)
{
    x = x;
}
 
int fputc(int ch, FILE *f)
{

	USART_SendData(USART1, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	return ch;
}


void USART1_IRQHandler(void)
{
	if(USART_GetFlagStatus(USART1,USART_IT_RXNE)!=RESET)
	{
		num=USART_ReceiveData(USART1);
	}
}


void USART1_Config(u32 x)
{
	GPIO_InitTypeDef GPIO_xxx;
	
	USART_InitTypeDef USART_xxx;
	
	NVIC_InitTypeDef NVIC_xxx;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1|RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_xxx.GPIO_Pin=GPIO_Pin_9;
	GPIO_xxx.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_xxx.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_xxx);
	
		GPIO_xxx.GPIO_Pin=GPIO_Pin_10;
	GPIO_xxx.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_xxx);
	
	USART_xxx.USART_BaudRate=x;
	USART_xxx.USART_WordLength=USART_WordLength_8b;
	USART_xxx.USART_StopBits=USART_StopBits_1;
	USART_xxx.USART_Parity=USART_Parity_No;
	
	USART_xxx.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_xxx.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	
	USART_Init(USART1,&USART_xxx);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);
	
	NVIC_xxx.NVIC_IRQChannel=USART1_IRQn;
	NVIC_xxx.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_xxx.NVIC_IRQChannelSubPriority=0;
	NVIC_xxx.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_Init(&NVIC_xxx);
}



