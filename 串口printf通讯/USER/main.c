# include "stm32f10x.h"
# include "delay.h"
#include "sys.h"
#include "usart.h"

int main(void)
{
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //ÖÐ¶Ï·Ö×é
	
	USART1_Config(115200);
		
	while(1)
  {
		printf("¹þ¹þ¹þ\r\n");
		delay_s(1);
	}		
}
