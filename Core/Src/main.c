#include "stm32f10x.h"                  // Device header
#include "stdio.h"
#include "Timer.h"
#include "ADC.h"
uint16_t adc_value[3];
uint8_t channel[3]={1,3,4};



int main()
{
		TIM2_config();
		ADC1_Config_Multi(3,channel);
		DMA_Init();
  	ADC1_Read_DMA((uint32_t)&ADC1->DR, (uint32_t)adc_value, 3);
	while(1)
	{
	
	delay_ms(100);	
	}
	
}