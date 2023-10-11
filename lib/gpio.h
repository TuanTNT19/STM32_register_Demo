#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
 void GPIO_Config_Port(char GPIOx);
 void GPIOA_Config_Pin(uint8_t Pinnum,char str);
 void GPIOB_Config_Pin(uint8_t Pinnum,char str);
 void GPIOC_Config_Pin(uint8_t Pinnum,char str);
 void GPIOA_Pin_On(uint8_t Pinnum);
 void GPIOA_Pin_Off(uint8_t Pinnum);
 void GPIOB_Pin_On(uint8_t Pinnum);
 void GPIOB_Pin_Off(uint8_t Pinnum);
 void GPIOC_Pin_On(uint8_t Pinnum);
 void GPIOC_Pin_Off(uint8_t Pinnum);


#endif