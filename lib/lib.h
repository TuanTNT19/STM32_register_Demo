#ifndef LIB_H_
#define LIB_H_

#define __vo volatile
#include <stdint.h>

#define FLASH_BASEADR   0x08000000U
#define SRAM1_BASEADR   0x20000000U

#define SRAM            SRAM1_BASEADR
 
 
#define PERIGH_BASEADR        0x40000000U 
#define APB1PERIGH_BASEADR    PERIGH_BASEADR
#define APB2PERIGH_BASEADR    0x40010000U
#define AHBPERIGH_BASEADR     0x40018000U


#define GPIOA_BASEADR         (APB2PERIGH_BASEADR+0x0800)
#define GPIOB_BASEADR         (APB2PERIGH_BASEADR+0x0C00)
#define GPIOC_BASEADR         (APB2PERIGH_BASEADR+0x1000)
#define GPIOD_BASEADR         (APB2PERIGH_BASEADR+0x1400)
#define GPIOE_BASEADR         (APB2PERIGH_BASEADR+0x1800)
#define GPIOF_BASEADR         (APB2PERIGH_BASEADR+0x1C00)
#define GPIOG_BASEADR         (APB2PERIGH_BASEADR+0x2000)

#define RCC_BASEADR           (AHBPERIGH_BASEADR + 0x1000)

#define __vo volatile
//define struct of GPIO
typedef struct
{
	__vo uint32_t CRL;
	__vo uint32_t CRH;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t BRR;
	__vo uint32_t LCKR;
	
}GPIO_RegDef_t;

typedef struct
{
		__vo uint32_t CR;
		__vo uint32_t CFGR;
	 	__vo uint32_t CIR;
		__vo uint32_t APB2RSTR;
	  __vo uint32_t APB1SRTR;
	  __vo uint32_t AHBENR;
	  __vo uint32_t APB2ENR;
	  __vo uint32_t APB1ENR;
	  __vo uint32_t BDCR;
	  __vo uint32_t CSR;
	  __vo uint32_t AHBSTR;
	
	 
}RCC_RegDef_t;

#define GPIOC  ((GPIO_RegDef_t*)GPIOC_BASEADR)
#define GPIOA  ((GPIO_RegDef_t*)GPIOA_BASEADR)
#define GPIOB  ((GPIO_RegDef_t*)GPIOB_BASEADR)
#define GPIOD  ((GPIO_RegDef_t*)GPIOD_BASEADR)
#define GPIOE  ((GPIO_RegDef_t*)GPIOE_BASEADR)
#define GPIOF  ((GPIO_RegDef_t*)GPIOF_BASEADR)
#define RCC    ((RCC_RegDef_t*)RCC_BASEADR) 

//enable macro for GPIO peripherals
#define GPIOC_PCLK_EN()   (RCC->APB2ENR |= (1<<4))
#define GPIOA_PCLK_EN()   (RCC->APB2ENR |= (1<<2))
#define GPIOB_PCLK_EN()   (RCC->APB2ENR |= (1<<3))
#define GPIOD_PCLK_EN()   (RCC->APB2ENR |= (1<<5))
#define GPIOE_PCLK_EN()   (RCC->APB2ENR |= (1<<6))

//disable macro for GPIO peripherals
#define GPIOC_PCLK_DI()   (RCC->APB2ENR &= ~(1<<4))
#define GPIOA_PCLK_DI()   (RCC->APB2ENR &= ~(1<<2))
#define GPIOB_PCLK_DI()   (RCC->APB2ENR &= ~(1<<3))
#define GPIOD_PCLK_DI()   (RCC->APB2ENR &= ~(1<<5))
#define GPIOE_PCLK_DI()   (RCC->APB2ENR &= ~(1<<6))


//some Generic Macro
#define ENABLE  1
#define DISABLE 0
#define SET           ENABLE
#define RESET         DISABLE

#endif