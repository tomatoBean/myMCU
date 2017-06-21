/**********************************************
 * 文件名  ：main.c
 * 描述    ：LED流水灯，频率可调……         
 * 库版本  ：ST3.5.0
************************************************/

#include "stm32f10x.h"
/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	

/* led2  */
   GPIO_InitTypeDef GPIO_InitStruct;
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_13;
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 
	 GPIO_Init( GPIOB,&GPIO_InitStruct);


//	 GPIO_ResetBits(GPIOC,GPIO_Pin_12);


	
/* led3  */	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

	  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_14;
	 
	 GPIO_Init( GPIOB,&GPIO_InitStruct);


//	 GPIO_ResetBits(GPIOC,GPIO_Pin_14);
	 
}



