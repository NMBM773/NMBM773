# include "stm32f10x.h"
# include "delay.h"
#include "sys.h"
#include "24cxx.h"
#include "myiic.h"

#define admin_ip 0x01
#define user_ip 0x09

u8 ADMIN[]={"38361200"};
u8 USER[]={"88888888"};

u8 ADMIN_DQ[9]={"\0"};
u8 USER_DQ[9]={"\0"};
int main(void)
{
	
	    AT24CXX_Init();           //IIC初始化
	
			//向指定地址写入一个数字，用于检测AT24CXX是否成功连接
    if (AT24CXX_Check()) 
    {
			//检测不到24cxx
    }
    else
    {
			//检测AT24C02正常
    }

/**********************写入****************************/		
		AT24CXX_Write(admin_ip,ADMIN,sizeof(ADMIN));
		delay_ms(20);
		AT24CXX_Write(user_ip,USER,sizeof(USER));
		delay_ms(20);

/**********************读取****************************/			

				delay_ms(500);
		
		AT24CXX_Read(admin_ip,ADMIN_DQ,sizeof(ADMIN));delay_ms(50);		
		AT24CXX_Read(user_ip,USER_DQ,sizeof(USER));delay_ms(50);	

/***************************

//			//下面的for循环用于第一次将芯片原始数据清零
//				for(i=0;i<255;i++)//此处255更改为使用芯片型号的实际存储大小
//				{
//					AT24CXX_WriteOneByte(i, 0);
//					delay_ms(20);
//				}
****************************/

	while(1)
  ;		
}
