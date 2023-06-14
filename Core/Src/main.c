#include "stm32f10x.h"
#include <stdint.h>

void TIM2_config()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Enable TIMEeR2 clock
	TIM2->PSC = 63;
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
void TIM3_PWM_Init()
{
  // set GPIOA_PIN13 as output
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
        GPIOA->CRL &= 0x0FFFFFFF;
		GPIOA->CRL |= (10<<28);
		//set pwm
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 63;
	TIM3->ARR = 999;
	TIM3->CCER |= (1<<4);
	TIM3->CCMR1 |= (6<<12);
	TIM3->CCR2=0;
	TIM3->CR1 = (1<<0);
	while (!(TIM3->SR & TIM_SR_UIF));
}
void TIM3_PWM_SetDuty(uint16_t duty)
{
	TIM3->CCR2=duty;
}


int main(void)
{
	TIM2_config();
    TIM3_PWM_Init();
 while (1)
    {

			for (uint16_t i=0;i<1000;i+=5)
			{
				TIM3_PWM_SetDuty(i);
				delay_ms(10);
			}
			
    }
}