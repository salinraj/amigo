

#include "stm32f1xx_hal.h"
#include "stm32f1xx_LCD.h"
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ST7783_H
#define __ST7783_H


#ifdef __cplusplus
 extern "C" {
#endif 

	 
	 /** 
  * @brief  ST7783 Size  
  */  
#define  ST7783_LCD_PIXEL_WIDTH    ((uint16_t)240)
#define  ST7783_LCD_PIXEL_HEIGHT   ((uint16_t)320)

	 
	 
	 
	 //////////////////////////////////////////////////////////////
	 
	 void delay(unsigned int t);
	 
	 
	 
	 ///////////////////////////////////////////////////////////////
	 
	 /* LCD IO functions */
void     LCD_Delay(uint32_t delay);
void     st7783_Init(void);
void     LCD_WriteRegister16(uint16_t LCDReg, uint16_t LCDRegValue);
	
	 //uint8_t  st7783_ReadReg(uint8_t LCDReg);

	 

#ifdef __cplusplus
}
#endif

#endif 