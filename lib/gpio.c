#include "gpio.h"
#include "lib.h"
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (pGPIOx==GPIOA)
		{
			GPIOA_PCLK_EN();
	}
				if (pGPIOx==GPIOB)
		{
			GPIOB_PCLK_EN();
	}
				if (pGPIOx==GPIOC)
		{
			GPIOC_PCLK_EN();
	}
				if (pGPIOx==GPIOD)
		{
			GPIOD_PCLK_EN();
	}
				if (pGPIOx==GPIOE)
		{
			GPIOE_PCLK_EN();
	}
}
	else if (EnorDi == DISABLE)
	{
			if (pGPIOx==GPIOA)
		{
			GPIOA_PCLK_DI();
	}
				if (pGPIOx==GPIOB)
		{
			GPIOB_PCLK_DI();
	}
				if (pGPIOx==GPIOC)
		{
			GPIOC_PCLK_DI();
	}
				if (pGPIOx==GPIOD)
		{
			GPIOD_PCLK_DI();
	}
				if (pGPIOx==GPIOE)
		{
			GPIOE_PCLK_DI();
	}
	}
}
void GPIO_Init(void)
{
// config the mode of GPIO_PIN
	
	
	//config speed 
	
	//config pupd settings
	
	//config output
	}
void config (GPIO_RegDef_t *pGPIOx)
{
	pGPIOx->CRH&=~(0xFUL << 20);
	pGPIOx->CRH |=(0x3UL << 20);
}
//void turnonled13C()
//{
//	GPIOC->ODR |= (1UL<<13);
//	//GPIOC->BSRR
//}
