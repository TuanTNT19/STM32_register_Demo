#include "stm32f1xx.h"
#include <stdint.h>

void GPIOC_config()
{
	RCC->APB2ENR |= (1<<4);
	GPIOC-> CRH &= (0xF0FFFFFF);
	GPIOC-> CRH |= (2<<24);
}
int main(void)
{
	GPIOC_config();
	while(1)
	{
     GPIOC->ODR |= (1<<14);
		//GPIOC->ODR &=~(1<<14);
	}
}