#include "stm32f10x.h"
#include "led.h"
#include "key.h"

int main(void)
{
	u8 key;
	
	LED_GPIO_Configuration();
	KEY_GPIO_Configuration();
	EXTI_Configuration();
	NVIC_Configuration();

/*	
	while(1)
	{
		// KEY 1
		if(key_scan(GPIOC,GPIO_Pin_4)==KEY_ON)
		{
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)==SET)
				GPIO_ResetBits(GPIOB,GPIO_Pin_12); // to turn on LED1
			else
				GPIO_SetBits(GPIOB,GPIO_Pin_12);
		}

		// KEY 2
		if(key_scan(GPIOC,GPIO_Pin_5)==KEY_ON)
		{
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==SET)
				GPIO_ResetBits(GPIOB,GPIO_Pin_13); // to turn on LED2
			else
				GPIO_SetBits(GPIOB,GPIO_Pin_13);
		}

		// KEY 3
		if(key_scan(GPIOB,GPIO_Pin_0)==KEY_ON)
		{
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)==SET)
				GPIO_ResetBits(GPIOB,GPIO_Pin_14); // to turn on LED3
			else
				GPIO_SetBits(GPIOB,GPIO_Pin_14);
		}
		
	}
*/
	
	
}