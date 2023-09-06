#include "stm32f1xx.h"
#include <stdint.h>
void ADC_Configuration(void);
void GPIO_Configuration(void);
uint16_t data=0;

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
void ADC_Configuration(void)
{
    // Enable the ADC1 clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // ADC configuration
    ADC1->CR1 = 0; // Default configuration (continuous mode, right alignment, etc.)
    
    // Set the ADC prescaler (optional, depends on your clock source)
    // ADCCLK = PCLK2 / (prescaler + 1)
    RCC->CFGR |= 0<<14; // ADCCLK = PCLK2 / 6 = 12 MHz

    // Configure the ADC for single conversion mode
    ADC1->CR2 |= 1<<1; //  continuous conversion
    ADC1->CR2 |= 1<<0;  // Turn on the ADC
    
    // Select the ADC channel (channel 0 in this example)
    ADC1->SQR3 = 0; // Clear the channel selection
   // ADC1->SQR3 |= 0; // Set the first conversion in the sequence to channel 0
    
    // Enable the ADC
    ADC1->CR2 |=1<<0;
    
    // Perform an initial conversion (discarded)
    ADC1->CR2 |= 1<<22;

}
uint16_t Read_ADC()
{
    while (!(ADC1->SR & ADC_SR_EOC));
	uint16_t a = ADC1->DR;
	return a;
	}
void GPIO_Configuration(void)
{
    // Enable GPIOA clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Configure PA0 as analog input (channel 0)
    GPIOA->CRL &= (0xFFFFFFF0); // Clear mode bits
    GPIOA->CRL |= (0<<0);// Input analog
}
int main(void)
{
    // Initialize the system
    SystemInit();
    
    // Configure GPIO and ADC
    GPIO_Configuration();
    ADC_Configuration();

    while (1)
    {


        // Read the ADC value
         data = Read_ADC();
        
    }
}