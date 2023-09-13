void TIM2_conf()
{
<<<<<<< HEAD
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC=7999;
	TIM2->CR1 |=(1<<0);
=======
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Enable TIMEeR2 clock
	TIM2->PSC = 7;
	TIM2->ARR = 65535;
	TIM2->CR1 = (1<<0);//enable counter
>>>>>>> USART
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
<<<<<<< HEAD
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
	
=======
void GPIO_config()
{
	RCC->APB2ENR |= (1<<2);//enable clock for gpioa
	// config gpioa pin 2 as alternative function TX
	GPIOA->CRL &= (0xFFFFF0FF);
	GPIOA-> CRL |= (10<<8);
		// config gpioa pin 3 as alternative function RX
	GPIOA->CRL &= (0xFFFF0FFF);
	GPIOA->CRL |= (4<<12);
	

}
void USART2_config()
{
	RCC->APB1ENR |= (1<<17);//enable clock for USART2
	USART2->BRR |= 833;
	USART2->CR1 |= (1<<13);
	USART2->CR1 |=(1<<3);
	
}
void USART2_Send_char(char str)
{
	while (!(USART2->SR & USART_SR_TXE));
	USART2->DR=str;
}
void USART2_Send_String(char *ch)
{
	while (*ch)
	{
		 USART2_Send_char(*ch++);
	}
}
//void USART2_Receive_data(char *k)
//{
//		while (!(USART2->SR & USART_SR_RXNE));
//	  *k = USART2->DR;
//	  *k++;
//}
int main(void)
{
	GPIO_config();
	USART2_config();
	TIM2_config();
	while(1)
	{
//	  char Rstring[30];
//		USART_Receive_data(&Rstring);
		USART2_Send_String("Stringabcd ");
		delay_ms(1000);
		
	}
>>>>>>> USART
}