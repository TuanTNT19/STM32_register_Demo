
#include "stm32f1xx.h"
#include <stdint.h>
uint16_t adc_value;
void ADC_Config()
{
	RCC->APB2ENR|=(1<<2);//enable clock for GPIOA
	RCC->APB2ENR|=(1<<9);//enable clock fof ADC1
	GPIOA->CRL &=(0xFFFF0FFF);
	GPIOA->CRL |=(0<<3);// set GPIOA_PIN3 as ADC1_Channel 3
	ADC1->CR2 |= (1<<1);//turn on ADC continuous mode
	ADC1->CR2 |=(1<<0);//enable ADC
	ADC1->SMPR2|=(4<<9);//set up sample time
	ADC1->SQR1 |=(0<<20);//total number of channel : 1
	ADC1->SQR3 |=(3<<0); // set channel 3 in first conversation
	ADC1->CR2 |= (1 << 2); // turn calibrate on 
	while(!(ADC1->CR2 & (1 << 2)));//check calibrate
	ADC1->CR2|=(1<<0);//enable ADC1
	ADC1->CR2 |=(1<<22);//Perform an initial conversion (discarded)
}
uint16_t Read_ADC()
	{
		ADC1->CR2 |= ADC_CR2_SWSTART;
		while(!(ADC1->SR &(1<<1)));
		uint16_t value=ADC1->DR;
		return value;
		
		}
int main()
{
			ADC_Config();
			while(1)
			{
				adc_value=Read_ADC();
				
			}
}
