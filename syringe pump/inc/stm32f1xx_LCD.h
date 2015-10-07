/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1XX_LCD_H
#define __STM32F1XX_LCD_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
	 
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "stm32f1xx_hal.h"
//#include "st7783.h"	 
#include "glcdfont.h"
 
 
 
 


// #define LCD_COLOR_BLACK         0x0000
// #define LCD_COLOR_GREY          0xF7DE          
// #define LCD_COLOR_BLUE          0x001F
// #define LCD_COLOR_RED           0xF800
// #define LCD_COLOR_GREEN         0x07E0
// #define LCD_COLOR_CYAN          0x07FF
// #define LCD_COLOR_MAGENTA       0xF81F
// #define LCD_COLOR_YELLOW        0xFFE0
// #define LCD_COLOR_WHITE         0xFFFF


#define	BLACK   		0x0000
#define	BLUE    		0x001F
#define	RED     		0xF800
#define	GREEN   		0x07E0
#define CYAN   			0x07FF
#define MAGENTA 		0xF81F
#define YELLOW  		0xFFE0
#define WHITE   		0xFFFF
#define LIGHTGRAY 	0xCDB6
#define GRAY   			0xE79C


// LCD height and width

#define TFTWIDTH   240
#define TFTHEIGHT  320
//#define TFTWIDTH   320
//#define TFTHEIGHT  240


#define Line1				10
#define Line2				41
#define Line3				61
#define Line4				91
#define Line5				101
#define Line6				121
#define Line7				151
#define Line8				181
#define Line9				211

#define Position1		1
#define Position2		7
#define Position3		13
#define Position4		19
#define Position5		25
#define Position6		31
#define Position7		37
#define Position8		43
#define Position9		49
#define Position10		55
#define Position11		61
#define Position12		67
#define Position13		73
#define Position14		79
#define Position15		85
#define Position16		91
#define Position17		97
#define Position18		103
#define Position19		109
#define Position20		115
#define Position21		121
#define Position22		127
#define Position23		133
#define Position24		139
#define Position25		141
#define Position26		147
#define Position27		153
#define Position28		159
#define Position29		165
#define Position30		171
#define Position31		177
#define Position32		183
#define Position33		189
#define Position34		195
#define Position35		201
#define Position36		207
#define Position37		213
#define Position38		219
#define Position39		225
#define Position40		231
#define Position41		237
#define Position42		243
#define Position43		249
#define Position44		255
#define Position45		261
#define Position46		267
#define Position47		273
#define Position48		279
#define Position49		285
#define Position50		291
#define Position51		297
#define Position52		303
#define Position53		309
#define Position54		315
#define Position55		321
#define Position56		327
#define Position57		333
	 
	 


/**
  * @brief  LCD RW,RD Interface pins
  */
#define LCD_RW_PIN                                 GPIO_PIN_7
#define LCD_RD_PIN                                 GPIO_PIN_6
#define LCD_RW_GPIO_PORT                           GPIOA
#define LCD_RD_GPIO_PORT                           GPIOA
#define LCD_RW_GPIO_CLK_ENABLE()                   __HAL_RCC_GPIOA_CLK_ENABLE()
#define LCD_RW_GPIO_CLK_DISABLE()                  __HAL_RCC_GPIOA_CLK_DISABLE()


/**
  * @brief  LCD Control Interface pins
  */
#define LCD_CS_PIN                                 GPIO_PIN_8
#define LCD_CS_GPIO_PORT                           GPIOA
#define LCD_CS_GPIO_CLK_ENABLE()                   __HAL_RCC_GPIOB_CLK_ENABLE()
#define LCD_CS_GPIO_CLK_DISABLE()                  __HAL_RCC_GPIOB_CLK_DISABLE()

/**
  * @brief  LCD Data/Command Interface pins
  */
#define LCD_DC_PIN                                 GPIO_PIN_9
#define LCD_DC_GPIO_PORT                           GPIOA
#define LCD_DC_GPIO_CLK_ENABLE()                   __HAL_RCC_GPIOA_CLK_ENABLE()
#define LCD_DC_GPIO_CLK_DISABLE()                  __HAL_RCC_GPIOA_CLK_DISABLE()

/**
  * @brief  LCD Reset pins
  */
#define LCD_RST_PIN                                 GPIO_PIN_5
#define LCD_RST_GPIO_PORT                           GPIOA
#define LCD_RST_GPIO_CLK_ENABLE()                   __HAL_RCC_GPIOA_CLK_ENABLE()
#define LCD_RST_GPIO_CLK_DISABLE()                  __HAL_RCC_GPIOA_CLK_DISABLE()



/**
  * @brief  LCD data pins
  */

#define LCD_DATA_PIN_0												GPIO_PIN_8	
#define LCD_DATA_PIN_1												GPIO_PIN_9	
#define LCD_DATA_PIN_2												GPIO_PIN_10	
#define LCD_DATA_PIN_3												GPIO_PIN_11
#define LCD_DATA_PIN_4												GPIO_PIN_12
#define LCD_DATA_PIN_5												GPIO_PIN_13	
#define LCD_DATA_PIN_6												GPIO_PIN_14
#define LCD_DATA_PIN_7												GPIO_PIN_15


#define LCD_GPIO_PORT                           GPIOB
#define LCD_GPIO_CLK_ENABLE()           			__HAL_RCC_GPIOB_CLK_ENABLE()
#define LCD_GPIO_CLK_DISABLE()           			__HAL_RCC_GPIOB_CLK_DISABLE()
	
	

/**
  * @brief  LCD Control Lines management
  */
#define LCD_CS_LOW()      HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_RESET)
#define LCD_CS_HIGH()     HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_SET)
#define LCD_DC_LOW()      HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_RESET)
#define LCD_DC_HIGH()     HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_SET)
#define LCD_RW_LOW()      HAL_GPIO_WritePin(LCD_RW_GPIO_PORT, LCD_RW_PIN, GPIO_PIN_RESET)
#define LCD_RW_HIGH()     HAL_GPIO_WritePin(LCD_RW_GPIO_PORT, LCD_RW_PIN, GPIO_PIN_SET)
#define LCD_RD_LOW()      HAL_GPIO_WritePin(LCD_RD_GPIO_PORT, LCD_RD_PIN, GPIO_PIN_RESET)
#define LCD_RD_HIGH()     HAL_GPIO_WritePin(LCD_RD_GPIO_PORT, LCD_RD_PIN, GPIO_PIN_SET)

#define LCD_RST_LOW()      HAL_GPIO_WritePin(LCD_RST_GPIO_PORT, LCD_RST_PIN, GPIO_PIN_RESET)
#define LCD_RST_HIGH()     HAL_GPIO_WritePin(LCD_RST_GPIO_PORT, LCD_RST_PIN, GPIO_PIN_SET)



//copy from st8873.h
void delay(unsigned int t);
	 
	 
	 
	 ///////////////////////////////////////////////////////////////
	 
	 /* LCD IO functions */
void     LCD_Delay(uint32_t delay);
void     st7783_Init(void);
void     LCD_WriteRegister16(uint16_t LCDReg, uint16_t LCDRegValue);




//



void LCD_IO_Init(void);
void LCD_IO_WriteReg(uint16_t LCDReg);
void LCD_IO_WriteData(uint16_t LCDData);
void LCD_IO_WriteMultipleData(uint16_t *pData, uint32_t Size);
void LCD_Delay(uint32_t Delay);
void LCD_PORT_Value(uint16_t value);
void Toggle_LCD_RW(void);

void Display_Clear(uint16_t color) ;
void Display_Reset(uint16_t color) ;
void LCD_SetRotation(uint8_t x);

static int16_t m_width;
static int16_t m_height;
static uint8_t m_rotation;
void LCD_SetAddrWindow(int x1, int y1, int x2, int y2);
uint16_t LCD_Color565(uint8_t r, uint8_t g, uint8_t b);

void LCD_DrawPixel(int16_t x, int16_t y, uint16_t color);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
//void LCD_DrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void LCD_DrawFastHLine(int16_t x, int16_t y, int16_t length, uint16_t color);
void LCD_DrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void LCD_DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void LCD_DrawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void LCD_DrawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
void LCD_DrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void LCD_DrawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);


//font size test
void LCD_DrawChar10(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
void LCD_Printf10(const char *fmt, ...);
void LCD_DrawChar20(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
void LCD_Printf20( char *fmt, ...);
void LCD_DrawChar36(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
void LCD_Printf36(const char *fmt, ...);


void LCD_Flood(uint16_t color, uint32_t len);
void LCD_FillScreen(uint16_t color);
void LCD_FillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void LCD_FillRect(int16_t x, int16_t y1, int16_t w, int16_t h, uint16_t fillcolor);
void LCD_FillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
void LCD_FillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void LCD_DrawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);

void LCD_Reset(void);
void LCD_SetCursor(unsigned int x, unsigned int y);
void LCD_SetTextSize(uint8_t s);
void LCD_SetTextColor(uint16_t c, uint16_t b);
void LCD_SetTextWrap(uint8_t w) ;
void LCD_Printf(const char *fmt, ...);
void Print_Text_On(uint8_t line, uint8_t position);



//static int16_t m_width;
//static int16_t m_height;
static int16_t m_cursor_x;
static int16_t m_cursor_y;
static uint16_t m_textcolor;
static uint16_t m_textbgcolor;
static uint8_t m_textsize;
static uint8_t m_rotation;
static uint8_t m_wrap;



#ifdef __cplusplus
}
#endif

#endif /* __STM32F1XX_NUCLEO_H */
