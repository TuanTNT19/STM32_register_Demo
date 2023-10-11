#include "ADC.h"
#include "stm32f1xx.h"
void ADC1_Init()
{
		RCC->APB2ENR|=(1<<9);//enable clock fof ADC1
}
void ADC1_Config_Channel(uint8_t channel)
{
	if (channel <= 7)
	{
		RCC->APB2ENR|=(1<<2);//enable clock for GPIOA
		GPIOA->CRL &=(0x00000000);
		GPIOA->CRL |=(0<<(4*channel));
	}
	else if (channel ==8)
	{
		RCC->APB2ENR|=(1<<3);//enable clock for GPIOB
		GPIOB->CRL &=(0x00000000);
		GPIOB->CRL |=(0<<0);
	}
	else if (channel == 9)
	{
		RCC->APB2ENR|=(1<<3);//enable clock for GPIOB
		GPIOA->CRL &=(0x00000000);
		GPIOA->CRL |=(0<<4);
	}
	  ADC1->CR2 |=(1<<0); //enable A/D converter
		ADC1->CR2 |=(1<<1);//Turn on continuous mode 
		ADC1->SMPR2 |=(7<<(3*channel));//sample time =  239.5 cycles
		ADC1->SQR1 &=(0<<20); //only one channel
		ADC1->SQR3 |=(channel<<0);
	  ADC1->CR2 |= (1 << 2); // turn calibrate on 
	  while(!(ADC1->CR2 & (1 << 2)));//check calibrate
		ADC1->CR2 |=(1<<0);//enable ADC1
		ADC1->CR2 |=(1<<22);//Perform an initial conversion (discarded)
	
}

uint16_t ADC1_Read()
	{
		//ADC1->CR2 |= ADC_CR2_SWSTART;
		while(!(ADC1->SR &(1<<1)));
		uint16_t value=ADC1->DR;
		return value;
		
	}
	
	void ADC2_Init()
{
		RCC->APB2ENR|=(1<<10);//enable clock fof ADC2
}
void ADC2_Config_Channel(uint8_t channel)
{
	if (channel <= 7)
	{
		RCC->APB2ENR|=(1<<2);//enable clock for GPIOA
		GPIOA->CRL &=(0x00000000);
		GPIOA->CRL |=(0<<(4*channel));
	}
	else if (channel ==8)
	{
		RCC->APB2ENR|=(1<<3);//enable clock for GPIOB
		GPIOB->CRL &=(0x00000000);
		GPIOB->CRL |=(0<<0);
	}
	else if (channel == 9)
	{
		RCC->APB2ENR|=(1<<3);//enable clock for GPIOB
		GPIOA->CRL &=(0x00000000);
		GPIOA->CRL |=(0<<4);
	}
	  ADC2->CR2 |=(1<<0); //enable A/D converter
		ADC2->CR2 |=(1<<1);//Turn on continuous mode 
		ADC2->SMPR2 |=(7<<(3*channel));//sample time =  239.5 cycles
		ADC2->SQR1 &=(0<<20); //only one channel
		ADC2->SQR3 |=(channel<<0);
	  ADC2->CR2 |= (1 << 2); // turn calibrate on 
	  while(!(ADC2->CR2 & (1 << 2)));//check calibrate
		ADC2->CR2 |=(1<<0);//enable ADC1
		ADC2->CR2 |=(1<<22);//Perform an initial conversion (discarded)
	
}

uint16_t ADC2_Read()
	{
		//ADC1->CR2 |= ADC_CR2_SWSTART;
		while(!(ADC2->SR &(1<<1)));
		uint16_t value=ADC2->DR;
		return value;
		
	}
	
	