/*********************************************************************************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库         
 * 硬件连接：-----------------
 *          |   PB12 - LED1     |
 *          |   PB13 - LED2     |
 *          |   PB14 - LED3     |
 *           ----------------- 
**********************************************************************************/
#include "led.h"

/*
 * 函数名：LED_GPIO_Config
 * 描述  ：配置LED用到的I/O口
 * 输入  ：无
 * 输出  ：无
 */
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);

  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;	
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_SetBits(GPIOB, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);	 // turn off all led
}


/*************************************************************************/
