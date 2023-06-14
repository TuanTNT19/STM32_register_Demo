#ifndef GPIO_H_
#define GPIO_H_

#include "lib.h"
typedef struct
{
	uint8_t GPIO_pinnumber;
	uint8_t GPIO_Pinmode;
	uint8_t GPIO_Pinspeed;
	uint8_t GPIO_Pinpupdcontrol;
	uint8_t GPIO_pinoptype;
	uint8_t GPIO_pinaltfuncmode;
	
}GPIO_pinConfig_t;
typedef struct {
	
	GPIO_RegDef_t *pGPIOx;
	GPIO_pinConfig_t GPIO_PinConfig;
	
}GPIO_Handle_t;
 //peripheral clock setup
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
void config (GPIO_RegDef_t *pGPIOx);
//init and deinit
void GPIO_Init(void);
void GPIO_DeInit(void);
//data read and write
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);
void GPIO_ToggleOutputPin(void);

//IRQ config and ISR handling 
void GPIO_IQRConfig(void);
void GPIO_IQRHandling(void);

#endif
