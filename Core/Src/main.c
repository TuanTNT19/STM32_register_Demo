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
	while(1)
	{
		for (int i=0;i<1000;i+=5)
		{
			setduty(i);
			delay_ms(10);
		}
		
	}
	
}