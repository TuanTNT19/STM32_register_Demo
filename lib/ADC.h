#ifndef ADC_H
#define ADC_H
#include <stdint.h>
void ADC1_Init();
void ADC1_Config_Channel(uint8_t channel);
uint16_t ADC1_Read();
void ADC2_Init();
void ADC2_Config_Channel(uint8_t channel);
uint16_t ADC2_Read();
	
#endif