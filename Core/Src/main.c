#include "stm32f10x.h"
#include <stdint.h>
//#include "main.h"

//void ADC_InitT(void);
//void GPIO_InitT(void);
//uint16_t ADC_Read(void);
// uint16_t adcValue;
//void GPIO_InitT()
//{
//	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;//enable Clock for GPIOC
// 	   GPIOC->CRH &= 0xFF0FFFFF;//reset bit
//	GPIOC->CRH |= (2 << 20);	//CNF: General purpose output push-pull. MOde: Output mode, max speed 2 MHz.
//}
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
//	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
//	 RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//	GPIOA->CRL |= (3<<28);
//		GPIOA->CRL &=~ (3<<30);
//		GPIOA->CRL |= (2<<30);
//		TIM3->PSC = 63;
//	TIM3->ARR = 999;
//	TIM3->CCER |= TIM_CCER_CC2E;
//	TIM3->CCMR1 |= (6<<12);
//	TIM3->CCR2=0;
//	TIM3->CR1 = TIM_CR1_CEN;
////	while (!(TIM3->SR & TIM_SR_UIF));
//	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//	GPIOA->CRL |= (3<<28);
//		GPIOA->CRL &=~ (3<<30);
//		GPIOA->CRL |= (2<<30);
		 RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

		//GPIOA->CRL |= (3<<28);
		GPIOA->CRL &= 0x0FFFFFFF;
		GPIOA->CRL |= (10<<28);
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
//    ADC_InitT();
    //GPIO_InitT();
	//GPIOC configure
	TIM2_config();
//	   RCC->APB2ENR = (1<<4);
//	   GPIOC->CRH &= 0xFF0FFFFF;
//     GPIOC->CRH |= (2<<20);	
//    
      	TIM3_PWM_Init();
//	 RCC->APB2ENR = (1<<4);
//	   GPIOC->CRH &= 0xFFF0FFFF;
//     GPIOC->CRH |= (10<<16);
	
    while (1)
    {
//			for (int i=0;i<10000;i++)
//			{
//         adcValue = ADC_Read();
//			}
        // Process the ADC value
        
        // Your code heref
//			for (int i=0;i<1000;i++)
//			{
//				GPIOC->ODR |= (1<<13);
//			}
//				for (int i=0;i<1000;i++)
//			{
//				GPIOC->ODR &= ~(1<<13);
//			}
//			GPIOC->ODR |= (1<<13);
//			delay_ms(100);
//				GPIOC->ODR &= ~(1<<13);
////			delay_ms(100);
//			for (uint16_t i=0;i<1000;i+=5)
//			{
//				TIM3_PWM_SetDuty(i);
//				//HAL_Delay(50);
//					delay_ms(100);
//			}
					for (uint16_t i=0;i<1000;i+=5)
			{
				TIM3_PWM_SetDuty(i);
				//HAL_Delay(50);
					delay_ms(10);
			}
			
    }
}