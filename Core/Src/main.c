#include "stm32f10x.h"                  // Device header
#include "stdio.h"
uint16_t adc_value[2];
void TIM2_config()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Enable TIMEeR2 clock
	TIM2->PSC = 7999;
	TIM2->ARR = 65535;
	TIM2->CR1 = (1<<0);//enable counter
	while (!(TIM2->SR & TIM_SR_UIF));
}
void delay_ms(uint16_t ms)
{
	TIM2->CNT=0;
	while (TIM2->CNT < ms);
}
void ADC1_Config()
{
	RCC->APB2ENR |= 1<<9;  // enable ADC1 clock
	RCC->APB2ENR |= (1<<2);  // enable GPIOA clock
	GPIOA->CRL &=(0xFFFFFF0F);
	GPIOA->CRL &=(0xFFF0FFFF);
	ADC1->CR1 |=(1<<8);//enable scan mode
	ADC1->CR2|=(1<<1);//enable continous mode
	ADC1->CR2|=(1<<8);//enble DMA
	ADC1->CR2 &=~(1<<11); //right alignment
	ADC1->CR2 |=(7<<17);//SWSTART in EXTSEL bit
	ADC1->CR2|=(1<<20);//Conversion on external event enabled
	ADC1->SMPR2 &= ~((7<<3) | (7<<12));  // Sampling time of 1.5 cycles for channel 1 and channel 4
	ADC1->SQR1|=(1<<20);//2 conversions
	ADC1->SQR3|=((1<<0)|(4<<5));//set up ADC channel for channel 1 and 4
	ADC1->CR2 |= (1 << 2); // turn calibrate on 
	while(!(ADC1->CR2 & (1 << 2)));//check calibrate
	ADC1->CR2|=(1<<0);//enable ADC1
	ADC1->CR2 |=(1<<22);//enable conversion
}
void DMA_Init()
{
	RCC->AHBENR |= 1<<0;//enable clock for DMA1
	DMA1_Channel1->CCR &=~ (1<<4);//read from peripheral
	DMA1_Channel1->CCR |=(1<<5);//enable circular mode
	DMA1_Channel1->CCR |=(1<<7);//enable memory increment
	DMA1_Channel1->CCR|=(1<<8);//peripheral size : 16 bit
	DMA1_Channel1->CCR|=(1<<10);//memory size : 16 bit
	
}
void DMA1_Config(uint32_t srcAdd, uint32_t destAdd, uint16_t size)
{
	DMA1_Channel1->CNDTR = size;
	DMA1_Channel1->CPAR = srcAdd;
	DMA1_Channel1->CMAR=destAdd;
	DMA1_Channel1->CCR |=(1<<0);//enable channel DMA
}
int main()
{
		TIM2_config();
		ADC1_Config();
		DMA_Init();
  	DMA1_Config((uint32_t)&ADC1->DR, (uint32_t)adc_value, 2);
	while(1)
	{
	
	delay_ms(100);	
	}
	
}