#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

/* the macro definition to trigger the led on or off 
 * 1 - off
 - 0 - on
 */
#define ON  0
#define OFF 1

//带参宏，可以像内联函数一样使用
#define LED1(a)	if (a)	\
					GPIO_SetBits();\
					else		\
					GPIO_ResetBits()

#define LED2(a)	if (a)	\
					GPIO_SetBits(,);\
					else		\
					GPIO_ResetBits(,)

#define LED3(a)	if (a)	\
					GPIO_SetBits(,);\
					else		\
					GPIO_ResetBits(,)

void LED_GPIO_Config(void);

#endif /* __LED_H */
