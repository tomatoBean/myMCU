#include "stm32f10x.h"
#include "myusart.h"
#include "stdio.h"
#include "led.h"

int main(void)
{

	//NVIC_Configuration();
	serial_init(115200);
	//uart_init(115200);
	LED_GPIO_Configuration();
	
	printf("hello serial demo\r\n");
	
	while(1);
	
}
