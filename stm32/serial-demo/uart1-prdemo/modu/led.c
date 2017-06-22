
#include "led.h"





//包含继电器、LED引脚
void led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14; //继电器 LED1 LED2 LED3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOB, &GPIO_InitStructure); 
	 
    GPIO_SetBits(GPIOB,GPIO_Pin_10); 
    GPIO_SetBits(GPIOB,GPIO_Pin_11);  //设置为高
    
    GPIO_SetBits(GPIOB,GPIO_Pin_12);   //LED灭
    GPIO_SetBits(GPIOB,GPIO_Pin_13);
    GPIO_SetBits(GPIOB,GPIO_Pin_14);


//    GPIO_ResetBits(GPIOB,GPIO_Pin_11);
//    GPIO_ResetBits(GPIOB,GPIO_Pin_12);
//    GPIO_ResetBits(GPIOB,GPIO_Pin_13);
//    GPIO_ResetBits(GPIOB,GPIO_Pin_14); 



}







