/**********************************************************************************
 * �ļ���  ��main.c
 * ����    ���������Ժ���������Ϊɨ��ģʽ        
 * ��汾  ��ST3.5.0
**********************************************************************************/
#include "stm32f10x.h" 
#include "led.h"
#include "key.h"  

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	/* config the led */
	LED_GPIO_Config();
	LED1( ON );
  LED2( OFF );
	LED3( ON );

	/*config key*/
	Key_GPIO_Config();	
	
	while(1)                            
	{	   
		/* key 1 */
		if( Key_Scan(GPIOC,GPIO_Pin_4) == KEY_ON  )
		{
			/*LED1��ת*/
			GPIO_WriteBit(GPIOB, GPIO_Pin_12, 
				(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12))));
			
			/*LED2��ת*/
			GPIO_WriteBit(GPIOB, GPIO_Pin_13, 
				(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_13))));
			
			/*LED3��ת*/
			GPIO_WriteBit(GPIOB, GPIO_Pin_14, 
				(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_14))));
		}
			/* key 2 */
	  if( Key_Scan(GPIOC,GPIO_Pin_5) == KEY_ON  )
		{		
			/*LED2��ת*/
			GPIO_WriteBit(GPIOB, GPIO_Pin_13, 
				(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_13))));
		}
		
				/* key 3 */
	  if( Key_Scan(GPIOB,GPIO_Pin_0) == KEY_ON  )
		{		
				/*LED3��ת*/
			GPIO_WriteBit(GPIOB, GPIO_Pin_14, 
				(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_14))));
		}
	}
}


/*********************************************************************************/
