/**********************************************
 * �ļ���  ��main.c
 * ����    ��LED��ˮ�ƣ�Ƶ�ʿɵ�����         
 * ��汾  ��ST3.5.0
************************************************/

#include "stm32f10x.h"
/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	

/*
    LED1--PB12;
		LED2--PB13;
		LED3--PB14	
*/
   /* to lighten led2 */
   GPIO_InitTypeDef GPIO_InitStruct;
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_13;
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init( GPIOB,&GPIO_InitStruct);


	 GPIO_ResetBits(GPIOC,GPIO_Pin_12);


	 
}



