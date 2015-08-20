/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1XX_SWITCHES_H
#define __STM32F1XX_SWITCHES_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
	 
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "stm32f1xx_hal.h"
 
	 
	 
	 

#define START_BUTTON											GPIO_PIN_0
#define STOP_BUTTON												GPIO_PIN_1
#define OK_BUTTON													GPIO_PIN_2
#define UP_BUTTON													GPIO_PIN_5
#define DOWN_BUTTON												GPIO_PIN_6

#define START_BUTTON_PORT            			GPIOB
#define START_BUTTON_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()
#define START_BUTTON_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOB_CLK_DISABLE()
	 
	 

uint32_t Button_GetState(uint16_t Button);
void Button_Init(void);

uint32_t Read_START_Button(void);
uint32_t Read_STOP_Button(void);
uint32_t Read_OK_Button(void);
uint32_t Read_UP_Button(void);
uint32_t Read_DOWN_Button(void);
	 
	 
	 
	 
	 #ifdef __cplusplus
}
#endif

#endif /* __STM32F1XX_NUCLEO_H */

	 