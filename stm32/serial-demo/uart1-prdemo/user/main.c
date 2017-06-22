#include "stm32f10x.h"

#include "delay.h"
#include "led.h"
#include "usartlite.h"

#define N 128

int main(void)
{
		u8 msg[N];
	
    delay_init();  // necessary
		USART1_Lite_Init(115200);

    while(1)
    {
				msg[0] = '\n';
				msg[1] = 'H';  //'T' = 0x54 
				msg[2] = 'E';  //'H' = 0x48
				msg[3] = 'L';  
				msg[4] = 'L';  
				msg[5] = 'O';  
				msg[6] = '!'; 
				msg[7] = '\t';
				USART_SendArr(USART1,msg,8);
			
			  // to test SendChar()
				msg[0] = 'T';  //'T' = 0x54 
				msg[1] = 'o';  //'H' = 0x48
				msg[2] = ' ';
				msg[3] = 't';
				msg[4] = 'e';
				msg[5] = 's';
				msg[6] = 't';
				msg[7] = '\t';
				msg[8] = 'S';
				msg[9] = 'e';
				msg[10] = 'n';
				msg[11] = 'd';
				msg[12] = 'C';
				msg[13] = 'h';
				msg[14] = 'a';
				msg[15] = 'r';
				msg[16] = ':';
				msg[17] = ' ';
				USART_SendArr(USART1,msg,18);
				USART_SendChar(USART1, 'S');
			  USART_SendChar(USART1, 'E');
				USART_SendChar(USART1, 'N');
				USART_SendChar(USART1, 'D');
				USART_SendChar(USART1, 'C');
				USART_SendChar(USART1, 'H');
				USART_SendChar(USART1, 'A');
				USART_SendChar(USART1, 'R');
				USART_SendChar(USART1, '\n');
				
				 // to test SendStr()
				msg[0] = 'T';  //'T' = 0x54 
				msg[1] = 'o';  //'H' = 0x48
				msg[2] = ' ';
				msg[3] = 't';
				msg[4] = 'e';
				msg[5] = 's';
				msg[6] = 't';
				msg[7] = '\t';
				msg[8] = 'S';
				msg[9] = 'e';
				msg[10] = 'n';
				msg[11] = 'd';
				msg[12] = 'S';
				msg[13] = 't';
				msg[14] = 'r';
				msg[15] = ':';
				msg[16] = ' ';
				USART_SendArr(USART1,msg,17);
				USART_SendStr(USART1, "string\n");

				delay_ms(1000);
    }
}
