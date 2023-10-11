#ifndef UART_H
#define UART_H
#include <stdint.h>

void USART2_Init();
void USART2_Config();
void USART2_Send_char(char str);
void USART2_Send_String(char *ch);
uint8_t USART2_Getchar(void);
void USART3_Init();
void USART3_Config();
void USART3_Send_char(char str);
void USART3_Send_String(char *ch);
uint8_t USART3_Getchar(void);
void USART1_Init();
void USART1_Config();
void USART1_Send_char(char str);
void USART1_Send_String(char *ch);
uint8_t USART1_Getchar(void);
#endif