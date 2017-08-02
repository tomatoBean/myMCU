#ifndef __MY_USART_H__
#define __MY_USART_H__

#include "stm32f10x.h"
#include "stdio.h"

void serial_init(u32 baud_rate);
void NVIC_Configuration(void);
void uart_init(u32 bound);

#endif
