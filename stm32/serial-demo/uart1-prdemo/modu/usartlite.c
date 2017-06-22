#include "usartlite.h"
#include "led.h"
#include "delay.h"
#include "modu.h"


void USART1_Lite_Init(u32 buad_rate)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//①
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_Init(GPIOA,&GPIO_InitStrue);//②
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_Init(GPIOA,&GPIO_InitStrue);//②
	
	USART_InitStrue.USART_BaudRate=buad_rate;
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStrue.USART_Parity=USART_Parity_No;
	USART_InitStrue.USART_StopBits=USART_StopBits_1;
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;
	
	USART_Init(USART1,&USART_InitStrue);//③
	USART_Cmd(USART1,ENABLE);//使能串口1
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//开启接收中断
	
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=3;    //抢占优先级
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=3;    //响应优先级
    NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStrue);
}

void USART1_IRQHandler(void)
{
    u8 res;
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
         EXTI_ClearITPendingBit(USART1_IRQn);
         res= USART_ReceiveData(USART1); 
         if(res == '1')
            {
               // RELAY1_ON;  //家电
                delay_ms(300);
            }
         if(res == '2')
         {
            //RELAY1_OFF; //家电
            delay_ms(300);
         }
         
         if(res == '3')
            {
              //  RELAY0_ON;  //开窗
                delay_ms(300);
            }
         if(res == '4')
         {
            //RELAY0_OFF; //关窗
            delay_ms(300);
         }  
			}
}



void USART_SendChar(USART_TypeDef* USARTx, u8 Data)
{
        USART_SendData(USARTx,Data);  
        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束        
 
}

void USART_SendStr(USART_TypeDef* USARTx, u8* str)
{
    while('\0' != *str)
    {
        USART_SendChar(USARTx,*str);
        str++;
    }
}

void USART_SendArr(USART_TypeDef* USARTx, u8 *buf,u8 nlen)
{
    u8 i;
    for(i=0; i<nlen; i++)
    {
        USART_SendChar(USARTx,buf[i]);
        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束        

    }
}














