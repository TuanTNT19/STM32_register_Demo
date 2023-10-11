#include "stm32f1xx.h"
#include <stdint.h>
#include "ADC.h"
#include "Timer.h"
#include "GPIO.h"
uint16_t adc_value;

int main()
{
	    ADC1_Init();
	    ADC1_Config_Channel(2);
			while(1)
			{
       adc_value = ADC1_Read();
			}
}