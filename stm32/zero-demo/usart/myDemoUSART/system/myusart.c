#include "myusart.h"

void serial_init(u32 baud_rate)
{
	GPIO_InitTypeDef   GPIO_InitStructure;
	USART_InitTypeDef  USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;

	// CLOCK
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

   // GPIO TX/PA.9
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
   GPIO_Init(GPIOA,&GPIO_InitStructure);

   // GPIO RX/PA.10
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
   GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitStructure);
	
	// USART
	USART_InitStructure.USART_BaudRate=baud_rate;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
   USART_Init(USART1,&USART_InitStructure);

//   USART_ITConfig(USART1,USART_IT_TC | USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART1,USART_IT_RXNE, ENABLE);
   USART_Cmd(USART1,ENABLE);
   	
}


void uart_init(u32 bound){
    //GPIO???????
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	//'??USART1??GPIOA?????????ù??????
     //USART1_TX   PA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//???????????
    GPIO_Init(GPIOA, &GPIO_InitStructure);
   
    //USART1_RX	  PA.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//????????
    GPIO_Init(GPIOA, &GPIO_InitStructure);  

   //Usart1 NVIC ????
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//????????3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//???????3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ???'??
	NVIC_Init(&NVIC_InitStructure);	//??????????????'??VIC?J???


   //USART ??'??????

	USART_InitStructure.USART_BaudRate = bound;//h???????9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//????8???????
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//h?????
	USART_InitStructure.USART_Parity = USART_Parity_No;//????z????
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//???????????????
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//???g?

    USART_Init(USART1, &USART_InitStructure); //??'??????
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//???????
    USART_Cmd(USART1, ENABLE);                    //'????? 

}


void NVIC_Configuration(void)
{
	NVIC_InitTypeDef  NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitStructure);
}

void USART1_IRQHandler(void)
{
	u8 result;

	//// to debug 
	if(SET == USART_GetITStatus(USART1, USART_IT_RXNE))
	{
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==Bit_RESET)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_12); // off
			USART_SendData(USART1,'M');
	  	}		
		else
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_12); // on
			USART_SendData(USART1,'L');
		}		
	}

	result=USART_ReceiveData(USART1);
	if(result=='U')
		USART_SendData(USART1,'Y');
	else
		USART_SendData(USART1,'N');
	
}

int fputc(int ch, FILE *f)
{  
	USART_SendData(USART1,(u8)ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
}

