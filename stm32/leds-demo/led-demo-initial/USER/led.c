#include "led.h"
/*
 * ��������LED_GPIO_Config
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
void LED_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*����GPIOB������ʱ��*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB,ENABLE); 

	/*ѡ��Ҫ���Ƶ�GPIOC����*/															   
  	GPIO_InitStructure    =  ;	

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure    =   ;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure    =   ; 

	/*���ÿ⺯������ʼ��GPIOC*/
  	GPIO_Init( , &GPIO_InitStructure);		  

	/* �ر�led1��	*/
	GPIO_SetBits( ,);	 
}


/***********************************************************************/
