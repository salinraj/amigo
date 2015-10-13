
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1XX_LCD_H
#define __STM32F1XX_LCD_H


#ifdef __cplusplus
 extern "C" {
#endif


#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "stm32f1xx_hal.h"
//#include "Syringe_Size.h"

#define TIMx                           TIM3
#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM3_CLK_ENABLE()
#define TIMx_IRQn                      TIM3_IRQn
#define TIMx_IRQHandler                TIM3_IRQHandler


void TIM4_Init (void);
void TIM3_init(void);


void PWM_ON(void);
void PWM_OFF(void);	 
void PWM_Freq(uint16_t rate);

	 
static void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif /* __STM32F1XX_NUCLEO_H */
