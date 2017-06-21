#include "led.h"
/*
 * 函数名：LED_GPIO_Config
 * 描述  ：配置LED用到的I/O口
 * 输入  ：无
 * 输出  ：无
 */
void LED_GPIO_Config(void)
{		
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*开启GPIOB的外设时钟*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB,ENABLE); 

	/*选择要控制的GPIOC引脚*/															   
  	GPIO_InitStructure    =  ;	

	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure    =   ;   

	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure    =   ; 

	/*调用库函数，初始化GPIOC*/
  	GPIO_Init( , &GPIO_InitStructure);		  

	/* 关闭led1灯	*/
	GPIO_SetBits( ,);	 
}


/***********************************************************************/
