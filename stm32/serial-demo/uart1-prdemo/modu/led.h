#ifndef  __LED_H_
#define  __LED_H_
#include "stm32f10x.h"
#include "sys.h"

#define LED1 PBout(12)
#define LED2 PBout(13)	
#define LED3 PBout(14)

#define LED1_ON     GPIO_ResetBits(GPIOB,GPIO_Pin_12)   //LEDÁÁ
#define LED2_ON     GPIO_ResetBits(GPIOB,GPIO_Pin_13)   //
#define LED3_ON     GPIO_ResetBits(GPIOB,GPIO_Pin_14)   //


#define LED1_OFF    GPIO_SetBits(GPIOB,GPIO_Pin_12)   //LEDÃð
#define LED2_OFF    GPIO_SetBits(GPIOB,GPIO_Pin_13)   
#define LED3_OFF    GPIO_SetBits(GPIOB,GPIO_Pin_14)   


void led_init(void);

#endif

