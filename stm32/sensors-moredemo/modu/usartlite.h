#ifndef  __USARTLITE_H_
#define  __USARTLITE_H_

#include "stm32f10x.h"
#include "sys.h"

#define  len 8

extern u8  rbuf[len];

void USART1_Lite_Init(u32 buad_rate);
void USART1_IRQHandler(void);
void USART_SendChar(USART_TypeDef* USARTx, u8 Data);
void USART_SendStr(USART_TypeDef* USARTx, u8* str);
void USART_SendArr(USART_TypeDef* USARTx, u8 *buf,u8 nlen);


#endif

