#include "stm32f10x.h"
#include "led.h"
#include "key.h"

int main(void)
{
	LED_GPIO_Configuration();
	KEY_GPIO_Configuration();
	while(1);
}
