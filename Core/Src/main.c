#include "stm32f10x.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
uint8_t buffer[30];

uint8_t datareceive[8];
//void TIM2_config()
//{
//	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Enable TIMEeR2 clock
//	TIM2->PSC = 7;
//	TIM2->ARR = 65535;
//	TIM2->CR1 = (1<<0);//enable counter
//	while (!(TIM2->SR & TIM_SR_UIF));
//}
//void delay_us(uint16_t us)
//{
//	TIM2->CNT=0;
//	while (TIM2->CNT < us);
//}
//void delay_ms(uint16_t ms)
//{
//	while (ms--)
//	{
//		delay_us(1000);
//	}
//}
void GPIO_config()
{
	RCC->APB2ENR |= (1<<2);//enable clock for gpioa
	// config gpioa pin 2 as alternative function TX
	GPIOA->CRL &= (0xFFFFF0FF);
	GPIOA-> CRL |= (10<<8);
		// config gpioa pin 3 as alternative function RX
	GPIOA->CRL &= (0xFFFF0FFF);
	GPIOA->CRL |= (8<<12);//in push pull up/down
	GPIOA->ODR |= (1<<3);// pull up
	RCC->APB2ENR |= (1<<4); // enable clock for gpioc
	GPIOC-> CRH &= (0xF0FFFFFF);
	GPIOC-> CRH |= (2<<24);// set gpioc pin 14 as a led

}
void USART2_config()
{
	RCC->APB1ENR |= (1<<17);//enable clock for USART2
	USART2->BRR |= 833;
	USART2->CR1 |= (1<<13);
	USART2->CR1 |= (1<<2); // RE=1.. Enable the Receiver
  USART2->CR1 |= (1<<3);  // TE=1.. Enable Transmitter
	
}
void USART2_Send_char(char str)
{
	while (!(USART2->SR & USART_SR_TXE));
	USART2->DR=str;
}
void USART2_Send_String(char *ch)
{
	while (*ch)
	{
		 USART2_Send_char(*ch++);
	}
}

uint8_t USART_Getchar(void)
{
	
	uint8_t Temp;
	while (!(USART2->SR & USART_SR_RXNE));
	Temp = USART2->DR;
	return Temp;
}
void UART_Getstring(uint8_t *str, uint8_t len)
{
	for (uint8_t i=0;i<len;i++)
	{
		*str=USART_Getchar();
				if (*str=='n')
			{
				*(str+1)=NULL;
				break;
				}
		str++;
  }
}
int main(void)
{
	GPIO_config();
	USART2_config();
	//TIM2_config();
	GPIOC->ODR |= (1<<13);
	while(1)
	{

	UART_Getstring(datareceive,7);
		USART2_Send_String(datareceive);
		if (strcmp(datareceive, "led_on")==0 )
			{
				GPIOC->ODR |= (1<<14);
				 
				}
		else 
			{
					GPIOC->ODR &=~ (1<<14);
				}
	 }
}