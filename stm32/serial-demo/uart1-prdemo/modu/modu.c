#include "modu.h"




void modu_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //ʹ�ܶ˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2;                                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO ���ٶ�Ϊ 50MHz	
    GPIO_Init(GPIOC, &GPIO_InitStructure); //��ʼ�� GPIO


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO ���ٶ�Ϊ 50MHz	
    GPIO_Init(GPIOC, &GPIO_InitStructure); //��ʼ�� GPIO



  
//|GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_5 |GPIO_Pin_7 |GPIO_Pin_8 |GPIO_Pin_9; //

  
    GPIO_SetBits(GPIOC,GPIO_Pin_0);
    GPIO_SetBits(GPIOC,GPIO_Pin_1);
    GPIO_SetBits(GPIOC,GPIO_Pin_2);
    GPIO_SetBits(GPIOC,GPIO_Pin_3);
    
//    GPIO_SetBits(GPIOC,GPIO_Pin_6);
//    GPIO_SetBits(GPIOC,GPIO_Pin_7);
//    GPIO_SetBits(GPIOC,GPIO_Pin_8);
//    GPIO_SetBits(GPIOC,GPIO_Pin_9);   

}

















