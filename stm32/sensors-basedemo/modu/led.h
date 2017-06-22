#ifndef  __LED_H_
#define  __LED_H_
#include "stm32f10x.h"
#include "sys.h"

#define LED1 PBout(12)
#define LED2 PBout(13)	
#define LED3 PBout(14)

#define RELAY0_ON    GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define RELAY1_ON    GPIO_ResetBits(GPIOB,GPIO_Pin_11)   //继电器闭合  设置为低
#define LED1_ON     GPIO_ResetBits(GPIOB,GPIO_Pin_12)   //LED亮
#define LED2_ON     GPIO_ResetBits(GPIOB,GPIO_Pin_13)   //
#define LED3_ON     GPIO_ResetBits(GPIOB,GPIO_Pin_14)   //

#define RELAY0_OFF   GPIO_SetBits(GPIOB,GPIO_Pin_10)
#define RELAY1_OFF   GPIO_SetBits(GPIOB,GPIO_Pin_11)  //继电器断开    设置为高 
#define LED1_OFF    GPIO_SetBits(GPIOB,GPIO_Pin_12)   //LED1灭
#define LED2_OFF    GPIO_SetBits(GPIOB,GPIO_Pin_13)   //LED2灭
#define LED3_OFF    GPIO_SetBits(GPIOB,GPIO_Pin_14)   //LED3灭


void led_init(void);

#endif

