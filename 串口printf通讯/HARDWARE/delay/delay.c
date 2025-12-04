#include"stm32f10x.h"
#include"delay.h"
void delay_us(u32 n)
{
	SysTick->LOAD=72*n;
	SysTick->VAL=0x00;
	SysTick->CTRL=0X00000005;
	while(!(SysTick->CTRL&0X00010000));
	SysTick->CTRL=0X00000004;
}
void delay_ms(u16 ms)
{ 
while(ms--)
{
	delay_us(1000);
}
}

void delay_s(u16 s)
{ 
	while(s--)
	{
		delay_ms(1000);
}
}

void delayms(u32 n)
{
u32 i;
while(n--)
{
i=12000;
while(i--);
}
}
