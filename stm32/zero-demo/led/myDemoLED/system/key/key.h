#ifndef __SYS_KEY_H
#define __SYS_KEY_H

#define KEY_ON 	0
#define KEY_OFF 1

void KEY_GPIO_Configuration(void);
void EXTI_Configuration(void);
void NVIC_Configuration(void);

u8 key_scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin);

#endif