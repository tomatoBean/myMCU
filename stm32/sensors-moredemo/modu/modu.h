#ifndef __MODU_H
#define __MODU_H	

#include "sys.h" 
#include "delay.h"

#define LSENS_READ GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)  //光敏 pull-up
    
#define FIRE_READ GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)   //火焰 pull-up

#define MQ_READ GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2) //MQ-9   pull-up

#define PERSON_READ GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)//人体红外  pull-down


#define LENSE 1

#define FIRE 2

#define MQ 3

#define PERSON 4



void modu_init(void);

#endif 




