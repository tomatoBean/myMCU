#include "stm32f10x.h"

#include "delay.h"
#include "led.h"
#include "DHT11.h"
#include "modu.h"
#include "usartlite.h"

#define N 8

int main(void)
{
    unsigned char temperature;  	    
    unsigned char humidity;
    u8 flag = 0;
    u8 bit = 0;  // send only once
    u8 flagl = 0;
    u8 flagp = 0; // flag for proximity
    u8 relay = 0;
    
    delay_init();
	
	  //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   
	
    delay_init();
    led_init();
    DHT11_Init();
		USART1_Lite_Init(115200);
    modu_init();
	
 
    while(1)
    {
        u8 msg[N]={0};
        u8 t; 
        temperature = 0;
        humidity = 0;
        
        // works
				if(t%100==0)	// per 100ms
				{									  
								DHT11_Read_Data(&temperature,&humidity);	//��ȡ��ʪ��ֵ	
								msg[0] = 'T';  //'T' = 0x54 
								msg[1] = temperature;
								msg[2] = 'H';  //'H' = 0x48
								msg[3] = humidity;
								USART_SendArr(USART1,msg,4);
								t = 0;
				}				   
				delay_ms(10);
				t++;
        // works
        if(FIRE_READ == 0)//����1
				{ // just power-up ?
						delay_ms(10);
						if(FIRE_READ == 0)
						{ 
								if(flag == 0)
								{
										USART_SendData(USART1,'F');  //70
										while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ��� 
										flag = 1; // mark for already sending
								}
							
								LED1_ON;
								delay_ms(300);
								LED1_OFF;               
						}           
				}//else flag = 0;
				else
				{
						if(flag == 1) // jump even power-up
						{
								USART_SendData(USART1,'f');  //70
								while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ��� 
								flag = 0;
						
						}					
				}
				
				// works
				// to test relay0
				RELAY0_ON;  //��
				LED3_ON;
				delay_ms(3000);
				RELAY0_OFF;
				LED3_OFF;
				
				// works
        // M:  emergency;  m: recover already       
				if(MQ_READ == 0)//MQ2  it becomes lowlevel from pull-up
				{   
						delay_ms(10);
						if(MQ_READ == 0)
						{  
							 if(bit == 0)
							 {
										//USART_SendData(USART1,'M');  //77
								    USART_SendChar(USART1,'M');  //77
										while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ��� 
										bit = 1;  // mark to send only once
										
										if(relay == 0) //emergency
										{
												RELAY0_ON;  //����
												delay_ms(300);
												relay = 1; // mark for relay control
										}
								 }
							 
								LED2_ON;  // flashing due to keeping low
								delay_ms(300);
								LED2_OFF;
							}
				 }//else bit = 0;
				 else  // it keeps high
				 {
						if(bit == 1)
						{
								//USART_SendData(USART1,'m');  //70
							  USART_SendChar(USART1,'m');  //70
								while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ��� 
								bit = 0;  // recover mark due to health  
								if(relay == 1)  //recover
								{
										RELAY0_OFF;
										delay_ms(300);                    
										relay = 0;
								}							
						}	
				 }
        
				// works				
        if(LSENS_READ == 1) //���ˣ��޹� ,led3��
        {
            delay_ms(10);
            if(LSENS_READ == 1) 
            {   
                if(PERSON_READ == 1)
                {   
                    if(flagl == 0)
                    {
                        LED3_ON;
                        delay_ms(300);
                        flagl = 1;  // mark for already sending
                    }                
                }
            }
        }else flagl = 0;
        
        // works       
        if(LSENS_READ == 0)  //���ˣ��й� led3�� 
        {
            delay_ms(10);
            if(LSENS_READ == 0) 
            {   
                if(PERSON_READ == 0)
                {   
                    if(flagp == 0)
                    {
                        LED3_OFF;
                        delay_ms(300);
                        flagp = 1;  // mark for already sending
                    }
                }
            }
        }else flagp = 0;
        
    }
}
