#include "stm32f1xx.h"
#include <stdint.h>

void IWDG_Init() {
    // Enable the IWDG by writing the unlock sequence to the Key register (IWDG_KR)
    IWDG->KR = 0x5555; // Unlock access to the IWDG_PR and IWDG_RLR registers

    // Set the prescaler value to divide the watchdog clock (40 kHz by default)
    IWDG->PR = 7; // Prescaler set to 256

    // Set the reload value to determine the watchdog's timeout period
    IWDG->RLR = 312; // 12-bit value; max timeout

    // Refresh the watchdog to apply the new settings
   IWDG->KR = 0xAAAA; // Refresh the watchdog counter
 //IWDG->KR = 0xCCCC;
}

void IWDG_Refresh() {
    // Refresh the watchdog by writing the unlock sequence to the Key register (IWDG_KR)
	IWDG->KR = 0xCCCC;
    //IWDG->KR = 0xAAAA; // Refresh the watchdog counter
}
void TIM2_config()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Enable TIMEeR2 clock
	TIM2->PSC = 7;
	TIM2->ARR = 65535;
	TIM2->CR1 = (1<<0);//enable counter
	while (!(TIM2->SR & TIM_SR_UIF));
}
void delay_us(uint16_t us)
{
	TIM2->CNT=0;
	while (TIM2->CNT < us);
}
void delay_ms(uint16_t ms)
{
	while (ms--)
	{
		delay_us(1000);
	}
}
void GPIOC_config()
{
	RCC->APB2ENR |= (1<<4);
	GPIOC-> CRH &= (0xFF0FFFFF);
	GPIOC-> CRH |= (2<<20);
}
int main(void)
{
	GPIOC_config();
	TIM2_config();
	IWDG_Init();
	 //delay_ms(5000);
	GPIOC->ODR &= (0<<13);
	IWDG_Init();
	while(1)
	{
		IWDG_Refresh();
		GPIOC->ODR |= (1<<13);
     delay_ms(3000);
	   //IWDG_Refresh();
	}
}