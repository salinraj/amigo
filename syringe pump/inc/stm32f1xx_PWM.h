
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



void TIM4_Init (void);


void PWM_ON(void);
void PWM_OFF(void);	 
void PWM_Freq(uint16_t rate);



#ifdef __cplusplus
}
#endif

#endif /* __STM32F1XX_NUCLEO_H */
