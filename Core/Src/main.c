<<<<<<< HEAD
=======

#include "stm32f1xx.h"
#include <stdint.h>
uint16_t adc_value;
>>>>>>> fix
void TIM2_conf()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC=7999;
	TIM2->CR1 |=(1<<0);
	while (!(TIM2->SR & TIM_SR_UIF));
}
void delay_ms(uint16_t ms)
{
	TIM2->CNT=0;
	while(TIM2->CNT <= ms);
}
<<<<<<< HEAD
void TIM3_PWM_Init()
{
	// config GPIOA_PIN7 as a output
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  GPIOA->CRL &= 0x0FFFFFFF;
	GPIOA->CRL |= (10<<28);
	// set pwm
	// default duty set by CCR2 =0
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; 
	TIM3->PSC= 7;
	TIM3->ARR = 999;
	TIM3->CCER |= (1<<4);
	TIM3->CCMR1 |= (6<<12);
	TIM3->CCR2=0;
	TIM3->CR1 |=(1<<0);
	while (!(TIM3->SR & TIM_SR_UIF));
}
void setduty(uint16_t duty)
{
	TIM3->CCR2 = duty;
}
int main(void)
{
	
	TIM2_conf();
	TIM3_PWM_Init();
=======
void Tim1_PWM_Config()
{
	RCC->APB2ENR |=(1<<2);//enable clock for GPIOA
	GPIOA->CRH &=(0xFFFFFFF0);
	GPIOA->CRH |=(10<<0); //set gpioa pin 8 as output alternate function push pull for timer 1 channel 1
	GPIOA->CRH &=(0xFFFFFF0F);
	GPIOA->CRH |=(10<<4);//set gpioa pin 9 as output alternate function push pull for timer 1 channel 2
	RCC->APB2ENR |=(1<<11);
	TIM1->PSC=7;
	TIM1->ARR=999;
	TIM1->CCER|=((1<<0)|(1<<4));//enable caption / compare output for channel 1 vs 2
	TIM1->CCMR1 |=((6<<4) | (6<<12));//set mode 1 for channel 1 vs 2
	TIM1->CCR1=0;
	TIM1->CCR2=0;
	TIM1->BDTR |= TIM_BDTR_MOE;// Enable the main output
	TIM1->CR1|=(1<<0);
	while(!(TIM1->SR & TIM_SR_UIF));
}
void set_duty_channel1(uint16_t duty1)
{
	TIM1->CCR1=duty1;
}
void set_duty_channel2(uint16_t duty2)
{
	TIM1->CCR2=duty2;
}
int main()
{
	TIM2_conf();
	Tim1_PWM_Config();
	
>>>>>>> fix
	while(1)
	{
		for (int i=0;i<1000;i+=5)
		{
<<<<<<< HEAD
			setduty(i);
=======
			set_duty_channel1(i);
			set_duty_channel2(1000-i);
>>>>>>> fix
			delay_ms(10);
		}
		
	}
<<<<<<< HEAD
	
}
=======
}

>>>>>>> fix
