#include "stm32f10x_it.h"
#include "key.h"

void KEY_GPIO_Configuration(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
   
	// key 1
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
   
   GPIO_Init(GPIOC,&GPIO_InitStructure);
    // key 2
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
   
   GPIO_Init(GPIOC,&GPIO_InitStructure);

	// key 3
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
   
   GPIO_Init(GPIOB,&GPIO_InitStructure);

}


void EXTI_Configuration(void)
{
	EXTI_InitTypeDef  EXTI_InitStructure;

	EXTI_ClearITPendingBit(GPIO_Pin_4);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource4);
	EXTI_InitStructure.EXTI_Line=GPIO_Pin_4;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void NVIC_Configuration(void)
{
	NVIC_InitTypeDef  NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

u8 key_scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin)
{
   if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==RESET)
   	return KEY_ON;
   else
   	return KEY_OFF;
}