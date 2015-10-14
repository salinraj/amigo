/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_LCD.h"


//***********************************************************************************


// // Initialization commands
// static const uint16_t ST7781_regValues[] = {
// 	0x0001,0x0100,
// 	0x0002,0x0700,
// 	0x0003,0x1030,
// 	0x0008,0x0302,
// 	0x0009,0x0000,
// 	0x000A,0x0008,
// 	//*******POWER CONTROL REGISTER INITIAL*******//
// 	0x0010,0x0790,
// 	0x0011,0x0005,
// 	0x0012,0x0000,
// 	0x0013,0x0000,
// 	//delayms(50,
// 	//********POWER SUPPPLY STARTUP 1 SETTING*******//
// 	0x0010,0x12B0,
// 	// delayms(50,
// 	0x0011,0x0007,
// 	//delayms(50,
// 	//********POWER SUPPLY STARTUP 2 SETTING******//
// 	0x0012,0x008C,
// 	0x0013,0x1700,
// 	0x0029,0x0022,
// 	// delayms(50,
// 	//******GAMMA CLUSTER SETTING******//
// 	0x0030,0x0000,
// 	0x0031,0x0505,
// 	0x0032,0x0205,
// 	0x0035,0x0206,
// 	0x0036,0x0408,
// 	0x0037,0x0000,
// 	0x0038,0x0504,
// 	0x0039,0x0206,
// 	0x003C,0x0206,
// 	0x003D,0x0408,
// 	// -----------DISPLAY WINDOWS 240*320-------------//
// 	0x0050,0x0000,
// 	0x0051,0x00EF,
// 	0x0052,0x0000,
// 	0x0053,0x013F,
// 	//-----FRAME RATE SETTING-------//
// 	0x0060,0xA700,
// 	0x0061,0x0001,
// 	0x0090,0x0033, //RTNI setting
// 	//-------DISPLAY ON------//
// 	0x0007,0x0133,    0x0001,0x0100,
// 	0x0002,0x0700,
// 	0x0003,0x1030,
// 	0x0008,0x0302,
// 	0x0009,0x0000,
// 	0x000A,0x0008,
// 	//*******POWER CONTROL REGISTER INITIAL*******//
// 	0x0010,0x0790,
// 	0x0011,0x0005,
// 	0x0012,0x0000,
// 	0x0013,0x0000,
// 	//delayms(50,
// 	//********POWER SUPPPLY STARTUP 1 SETTING*******//
// 	0x0010,0x12B0,
// 	// delayms(50,
// 	0x0011,0x0007,
// 	// delayms(50,
// 	//********POWER SUPPLY STARTUP 2 SETTING******//
// 	0x0012,0x008C,
// 	0x0013,0x1700,
// 	0x0029,0x0022,
// 	// delayms(50,
// 	//******GAMMA CLUSTER SETTING******//
// 	0x0030,0x0000,
// 	0x0031,0x0505,
// 	0x0032,0x0205,
// 	0x0035,0x0206,
// 	0x0036,0x0408,
// 	0x0037,0x0000,
// 	0x0038,0x0504,
// 	0x0039,0x0206,
// 	0x003C,0x0206,
// 	0x003D,0x0408,
// 	// -----------DISPLAY WINDOWS 240*320-------------//
// 	0x0050,0x0000,
// 	0x0051,0x00EF,
// 	0x0052,0x0000,
// 	0x0053,0x013F,
// 	//-----FRAME RATE SETTING-------//
// 	0x0060,0xA700,
// 	0x0061,0x0001,
// 	0x0090,0x0033, //RTNI setting
// 	//-------DISPLAY ON------//
// 	0x0007,0x0133,
// };


void delay(unsigned int t)
{
	for (; t > 0; t-- )
	{
	__asm("nop");
	}
}


void st7783_Init(void)
{    
//  uint16_t data = 0;
  
//	m_width     = TFTWIDTH;
//	m_height    = TFTHEIGHT;
    m_height    = TFTWIDTH;
		m_width     = TFTHEIGHT;
	
	//m_rotation  = 0;
	m_rotation  = 1;
	m_cursor_y  = m_cursor_x    = 0;
	m_textsize  = 4;
	m_textcolor = m_textbgcolor = 0xFFFF;
	m_wrap      = 1;
  /* Initialize st7783 low level bus layer -----------------------------------*/
  LCD_IO_Init();
	LCD_Reset();
	
//LCD_WriteRegister16(0xff00, 0x8844);            //test data
	
  LCD_WriteRegister16(0x0001, 0x0100); 
	LCD_WriteRegister16(0x0002, 0x0700);
	LCD_WriteRegister16(0x0003, 0x1030);
	LCD_WriteRegister16(0x0008, 0x0302);
	LCD_WriteRegister16(0x0009, 0x0000);
	LCD_WriteRegister16(0x000A, 0x0008);
	
	//*******POWER CONTROL REGISTER INITIAL*******//
	LCD_WriteRegister16(0x0010, 0x0790);
	LCD_WriteRegister16(0x0011, 0x0005);
	LCD_WriteRegister16(0x0012, 0x0000);
	LCD_WriteRegister16(0x0013, 0x0000);
	//delay
	//HAL_Delay(10);
	//********POWER SUPPPLY STARTUP 1 SETTING*******//
	LCD_WriteRegister16(0x0010, 0x12B0);
	LCD_WriteRegister16(0x0011, 0x0007);
	//delay
	//HAL_Delay(10);
	//********POWER SUPPLY STARTUP 2 SETTING******//
	LCD_WriteRegister16(0x0012, 0x008c);
	LCD_WriteRegister16(0x0013, 0x1700);
	LCD_WriteRegister16(0x0029, 0x0022);
	//delay
	//HAL_Delay(10);
	//******GAMMA CLUSTER SETTING******//
	//LCD_WriteRegister16(0x0020, 0x0000);
	//LCD_WriteRegister16(0x0021, 0x0000);
	
	LCD_WriteRegister16(0x0030, 0x0000);
	LCD_WriteRegister16(0x0031, 0x0505);
	LCD_WriteRegister16(0x0032, 0x0205);
	LCD_WriteRegister16(0x0035, 0x0206);
	LCD_WriteRegister16(0x0036, 0x0408);
	LCD_WriteRegister16(0x0037, 0x0000);
	LCD_WriteRegister16(0x0038, 0x0504);
	LCD_WriteRegister16(0x0039, 0x0206);
	LCD_WriteRegister16(0x003C, 0x0206);
	LCD_WriteRegister16(0x003D, 0x0408);
	
	// -----------DISPLAY WINDOWS 240*320-------------//
	LCD_WriteRegister16(0x0050, 0x0000);
	LCD_WriteRegister16(0x0051, 0x00EF);
	LCD_WriteRegister16(0x0052, 0x0000);
	LCD_WriteRegister16(0x0053, 0x013F);
	//-----FRAME RATE SETTING-------//
	LCD_WriteRegister16(0x0060, 0xA700);
	LCD_WriteRegister16(0x0061, 0x0001);
	LCD_WriteRegister16(0x0090, 0x0033);//RTNI setting
	//-------DISPLAY ON------//
	LCD_WriteRegister16(0x0007, 0x0133);

	LCD_WriteRegister16(0x0001, 0x0100); 
	LCD_WriteRegister16(0x0002, 0x0700);
	LCD_WriteRegister16(0x0003, 0x1030);
	LCD_WriteRegister16(0x0008, 0x0302);
	LCD_WriteRegister16(0x0009, 0x0000);
	LCD_WriteRegister16(0x000A, 0x0008);
	
	//*******POWER CONTROL REGISTER INITIAL*******//
// 	LCD_WriteRegister16(0x0010, 0x0790);
// 	LCD_WriteRegister16(0x0011, 0x0005);
// 	LCD_WriteRegister16(0x0012, 0x0000);
// 	LCD_WriteRegister16(0x0013, 0x0000);
// 	//delay
	//HAL_Delay(10);
	//********POWER SUPPPLY STARTUP 1 SETTING*******//
	LCD_WriteRegister16(0x0010, 0x12B0);
	LCD_WriteRegister16(0x0011, 0x0007);
	//delay
	//HAL_Delay(10);
	//********POWER SUPPLY STARTUP 2 SETTING******//
	LCD_WriteRegister16(0x0012, 0x008c);
	LCD_WriteRegister16(0x0013, 0x1700);
	LCD_WriteRegister16(0x0029, 0x0022);
	
	//************* frame rate control ******//
	LCD_WriteRegister16(0x002b, 0x000E);
	
	
	//delay
	//HAL_Delay(10);
	//******GAMMA CLUSTER SETTING******//
	//LCD_WriteRegister16(0x0020, 0x0000);
	//LCD_WriteRegister16(0x0021, 0x0000);
	
	LCD_WriteRegister16(0x0030, 0x0000);
	LCD_WriteRegister16(0x0031, 0x0505);
	LCD_WriteRegister16(0x0032, 0x0205);
	LCD_WriteRegister16(0x0035, 0x0206);
	LCD_WriteRegister16(0x0036, 0x0408);
	LCD_WriteRegister16(0x0037, 0x0000);
	LCD_WriteRegister16(0x0038, 0x0504);
	LCD_WriteRegister16(0x0039, 0x0206);
	LCD_WriteRegister16(0x003C, 0x0206);
	LCD_WriteRegister16(0x003D, 0x0408);
	
	// -----------DISPLAY WINDOWS 240*320-------------//
	LCD_WriteRegister16(0x0050, 0x0000);
	LCD_WriteRegister16(0x0051, 0x00EF);
	LCD_WriteRegister16(0x0052, 0x0000);
	LCD_WriteRegister16(0x0053, 0x013F);
	//-----FRAME RATE SETTING-------//
	LCD_WriteRegister16(0x0060, 0xA700);
	LCD_WriteRegister16(0x0061, 0x0001);
	LCD_WriteRegister16(0x0090, 0x0033);//RTNI setting
	//-------DISPLAY ON------//
	LCD_WriteRegister16(0x0007, 0x0133);
	
	LCD_WriteRegister16(0x0020, 0x0000);
	LCD_WriteRegister16(0x0021, 0x0000);

	
}
void LCD_Delay(uint32_t Delay)
{
  //HAL_Delay(Delay);
		for (; Delay > 0; Delay-- )
	{
	__asm("nop");
	}
}



void LCD_WriteRegister16(uint16_t LCDReg, uint16_t LCDRegValue)
{
  LCD_IO_WriteReg(LCDReg);
  LCD_IO_WriteMultipleData(&LCDRegValue, 1);
}








//**************************************************************************************

/********************************* LINK LCD ***********************************/
/**
  * @brief  Initializes the LCD
  * @retval None
  */
void LCD_IO_Init(void)
{ 

	GPIO_InitTypeDef  gpioinitstruct = {0};

  /* LCD_CS_GPIO and LCD_DC_GPIO Periph clock enable */
  LCD_CS_GPIO_CLK_ENABLE();
  LCD_DC_GPIO_CLK_ENABLE();
	LCD_RW_GPIO_CLK_ENABLE() ;
  
  /* Configure LCD_CS_PIN pin: LCD Card CS pin */
  gpioinitstruct.Pin    = LCD_CS_PIN;
  gpioinitstruct.Mode   = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Speed  = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LCD_CS_GPIO_PORT, &gpioinitstruct);
      
  /* Configure LCD_DC_PIN pin: LCD Card DC pin */
  gpioinitstruct.Pin    = LCD_DC_PIN;
  HAL_GPIO_Init(LCD_DC_GPIO_PORT, &gpioinitstruct);
  /* Configure LCD_RW_PIN pin: LCD Card DC pin */
  gpioinitstruct.Pin = LCD_RW_PIN;
  HAL_GPIO_Init(LCD_RW_GPIO_PORT, &gpioinitstruct);

  /* Configure LCD_RW_PIN pin: LCD Card DC pin */
  gpioinitstruct.Pin = LCD_RD_PIN;
  HAL_GPIO_Init(LCD_RW_GPIO_PORT, &gpioinitstruct);

  /* Configure LCD_RST PIN pin:*/
  gpioinitstruct.Pin = LCD_RST_PIN;
  HAL_GPIO_Init(LCD_RST_GPIO_PORT, &gpioinitstruct);



  /* LCD chip select high */


  /*LCD_GPIO_PORT config */
	 gpioinitstruct.Pin = LCD_DATA_PIN_7;
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
   gpioinitstruct.Pin = LCD_DATA_PIN_6;
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
	 gpioinitstruct.Pin = LCD_DATA_PIN_5;
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
	 gpioinitstruct.Pin = LCD_DATA_PIN_4;                             //10
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
	 gpioinitstruct.Pin = LCD_DATA_PIN_3;                                 //9
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
	 gpioinitstruct.Pin = LCD_DATA_PIN_2;
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
	 gpioinitstruct.Pin = LCD_DATA_PIN_1;
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
	 gpioinitstruct.Pin = LCD_DATA_PIN_0;
  HAL_GPIO_Init(LCD_GPIO_PORT,  &gpioinitstruct);
////

  LCD_CS_HIGH();


  /* LCD SPI Config */
 // SPIx_Init();
}



/**
  * @brief  Writes command to select the LCD register.
  * @param  LCDReg: Address of the selected register.
  * @retval None
  */
void LCD_IO_WriteReg(uint16_t LCDReg)
{
  /* Reset LCD control line CS */
  LCD_CS_LOW();
  
  /* Set LCD data/command line DC to Low */
  LCD_DC_LOW();
	 //LCD_RW_LOW();  
  /* Send Command */
  //SPIx_Write(LCDReg);

	 LCD_PORT_Value(LCDReg >> 8);
   Toggle_LCD_RW();
	//LCD_RW_HIGH();
  //LCD_RW_LOW();  
  /* Send Command */
  //SPIx_Write(LCDReg);

	 LCD_PORT_Value(LCDReg);
   Toggle_LCD_RW();
	//LCD_RW_HIGH();
  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}


void LCD_IO_WriteData(uint16_t LCDData)
{
  /* Reset LCD control line CS */
  LCD_CS_LOW();
  
  /* Set LCD data/command line DC to Low */
  LCD_DC_HIGH();
	 //LCD_RW_LOW();  
  /* Send Command */
  //SPIx_Write(LCDReg);

	 LCD_PORT_Value(LCDData >> 8);
   Toggle_LCD_RW();
	//LCD_RW_HIGH();
  //LCD_RW_LOW();  
  /* Send Command */
  //SPIx_Write(LCDReg);

	 LCD_PORT_Value(LCDData);
   Toggle_LCD_RW();
	//LCD_RW_HIGH();
  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}



/**
* @brief  Write register value.
* @param  pData Pointer on the register value
* @param  Size Size of byte to transmit to the register
* @retval None
*/
//void LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size)
void LCD_IO_WriteMultipleData(uint16_t *pData, uint32_t Size)
{
  uint32_t counter = 0;
  
  /* Reset LCD control line CS */
  LCD_CS_LOW();
  
  /* Set LCD data/command line DC to High */
  LCD_DC_HIGH();

  if (Size == 1)
  {
    /* Only 1 byte to be sent to LCD - general interface can be used */
    /* Send Data */
   // SPIx_Write(*pData);
	//	LCD_RW_LOW();
	LCD_PORT_Value((*pData)>>8);
	//	LCD_RW_HIGH();
  Toggle_LCD_RW();
	//	LCD_RW_LOW();
		  LCD_PORT_Value(*pData);
	//	LCD_RW_HIGH();
  Toggle_LCD_RW();
  }
  else
{
    /* Several data should be sent in a raw */
    /* Direct SPI accesses for optimization */
    for (counter = Size; counter != 0; counter--)
  {
//       while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
//   {
// }
//       /* Need to invert bytes for LCD*/
//       *((__IO uint8_t*)&hnucleo_Spi.Instance->DR) = *(pData+1);

//       while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
// {
// }
//       *((__IO uint8_t*)&hnucleo_Spi.Instance->DR) = *pData;
//       counter--;
//       pData += 2;
  
		
  //Toggle_LCD_RW();
		LCD_RW_LOW();
					LCD_PORT_Value((*pData)>>8);
		LCD_RW_HIGH();
					//Toggle_LCD_RW();
		LCD_RW_LOW();
					LCD_PORT_Value(*pData);
		LCD_RW_HIGH();
					//Toggle_LCD_RW();
					pData += 1;
		  

}  
  
    /* Wait until the bus is ready before releasing Chip select */ 
//    while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_BSY) != RESET)
  
  } 
  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}






////////////////////////////////////////////lcd parallel 8 bit 


void LCD_PORT_Value(uint16_t value)
{
//uint8_t Mask;

// if(value & 0x80) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_7, GPIO_PIN_SET);
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_7, GPIO_PIN_RESET);

// 	if(value & 0x40) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_6, GPIO_PIN_SET);
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_6, GPIO_PIN_RESET);
// 	
// 	if(value & 0x20) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_5, GPIO_PIN_SET);
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_5, GPIO_PIN_RESET);
// 	
// 	if(value & 0x10) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_4, GPIO_PIN_SET);       //10
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_4, GPIO_PIN_RESET);

// 	if(value & 0x08) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_3, GPIO_PIN_SET);       //9
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_3, GPIO_PIN_RESET);

// 	if(value & 0x04) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_2, GPIO_PIN_SET);
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_2, GPIO_PIN_RESET);
// 	
// 		if(value & 0x02) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_1, GPIO_PIN_SET);
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_1, GPIO_PIN_RESET);
// 	
// 	if(value & 0x01) HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_0, GPIO_PIN_SET);
// else 	HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_DATA_PIN_0, GPIO_PIN_RESET);

value=value&0x00ff;
GPIOB->ODR =(GPIOB->ODR & 0x00ff);
GPIOB->ODR =(GPIOB->ODR |(value<<8));

//LCD_Delay(50);

}



void Toggle_LCD_RW(void)
{ LCD_Delay(1);
	LCD_RD_HIGH();
	LCD_RW_LOW();
	LCD_Delay(2);
	LCD_RW_HIGH();
	//LCD_Delay(10);
}




void LCD_Flood1(uint16_t color, uint32_t len)
{
	uint32_t  i, hi = color >> 8, lo = color;
	LCD_IO_WriteReg(0x0022); // Write data to GRAM

	// Write first pixel normally, decrement counter by 1
	LCD_CS_LOW();
	LCD_DC_HIGH();
	for(i=0;i<len;i++)
	{
	//LCD_RW_LOW();
	LCD_PORT_Value(hi);
	//	LCD_RW_HIGH();
  Toggle_LCD_RW();
	//	LCD_RW_LOW();
		  LCD_PORT_Value(lo);
	//	LCD_RW_HIGH();	
		Toggle_LCD_RW();
		
	}

	
	}
	
	
	
	   
void Display_Clear(uint16_t color)   
{   
    int x = 0,y = 0;//,hiByte,lowByte;   
//  printf("Color = %u\r\n", color);   
	
	              LCD_WriteRegister16(0x20, 0x0000);    
                LCD_WriteRegister16(0x21, 0x0000);
								LCD_WriteRegister16(0x22, color); 
	
        while(y<320)   
        {   
            while(x<240)   
            {   
							  //LCD_WriteRegister16(0x20, x);    
               // LCD_WriteRegister16(0x21, y);
	
                LCD_IO_WriteData(color);   
                x++;   
            }   
            x = 0;   
            y++;   
        }   
} 


void Display_Reset(uint16_t color)   
{   
   LCD_CS_HIGH();
   LCD_DC_HIGH();
	 LCD_RW_HIGH();
	
	
	  LCD_CS_LOW();
  
  /* Set LCD data/command line DC to Low for command */
  LCD_DC_LOW();
	 LCD_RW_LOW();
	LCD_PORT_Value(0x00);
	Toggle_LCD_RW();
	Toggle_LCD_RW();
	Toggle_LCD_RW();
	Toggle_LCD_RW();
  LCD_CS_HIGH();     
} 

void LCD_SetRotation(uint8_t x)
{
	
	m_rotation = (x & 3);
	switch(m_rotation) {
	case 0:
	case 2:
		m_width  = TFTWIDTH;
		m_height = TFTHEIGHT;
		break;
	case 1:
	case 3:
		m_width  = TFTHEIGHT;
		m_height = TFTWIDTH;
		break;
	
	}
}


void LCD_SetAddrWindow(int x1, int y1, int x2, int y2)
{

	int x, y, t;
	LCD_CS_LOW();

	// Values passed are in current (possibly rotated) coordinate
	// system.  932X requires hardware-native coords regardless of
	// MADCTL, so rotate inputs as needed.  The address counter is
	// set to the top-left corner -- although fill operations can be
	// done in any direction, the current screen rotation is applied
	// because some users find it disconcerting when a fill does not
	// occur top-to-bottom.
	
	switch(m_rotation) {
	default:
		x  = x1;
		y  = y1;
		break;
	case 1:
		t  = y1;
		y1 = x1;
		x1 = TFTWIDTH  - 1 - y2;
		y2 = x2;
		x2 = TFTWIDTH  - 1 - t;
		x  = x2;
		y  = y1;
		break;
	case 2:
		t  = x1;
		x1 = TFTWIDTH  - 1 - x2;
		x2 = TFTWIDTH  - 1 - t;
		t  = y1;
		y1 = TFTHEIGHT - 1 - y2;
		y2 = TFTHEIGHT - 1 - t;
		x  = x2;
		y  = y2;
		break;
	case 3:
		t  = x1;
		x1 = y1;
		y1 = TFTHEIGHT - 1 - x2;
		x2 = y2;
		y2 = TFTHEIGHT - 1 - t;
		x  = x1;
		y  = y2;
		break;
	}
		
	LCD_WriteRegister16(0x0050, x1); // Set address window
	LCD_WriteRegister16(0x0051, x2);
	LCD_WriteRegister16(0x0052, y1);
	LCD_WriteRegister16(0x0053, y2);
	LCD_WriteRegister16(0x0020, x ); // Set address counter to top left
	LCD_WriteRegister16(0x0021, y );

	LCD_CS_HIGH();
	
}


uint16_t LCD_Color565(uint8_t r, uint8_t g, uint8_t b)
{
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}




void LCD_DrawPixel(int16_t x, int16_t y, uint16_t color)
{
	// Clip	
	int16_t t;
	if((x < 0) || (y < 0) || (x >= m_width) || (y >= m_height)) return;
	//if((x < 0) || (y < 0) || (y >= TFTWIDTH) || (x >= TFTHEIGHT)) return;

	LCD_CS_LOW();


	switch(m_rotation) {
	case 1:
		t = x;
		x = TFTWIDTH  - 1 - y;
		y = t;
		break;
	case 2:
		x = TFTWIDTH  - 1 - x;
		y = TFTHEIGHT - 1 - y;
		break;
	case 3:
		t = x;
		x = y;
		y = TFTHEIGHT - 1 - t;
		break;
	}


///////////////////////////////////////////////////////

// 	switch(m_rotation) {
// 	case 1:
// 		t = x;
// 		x = TFTHEIGHT  - 1 - y;
// 		y = t;
// 		break;
// 	case 2:
// 		x = TFTWIDTH  - 1 - x;
// 		y = TFTHEIGHT - 1 - y;
// 		break;
// 	case 3:
// 		t = x;
// 		x = y;
// 		y = TFTHEIGHT - 1 - t;
// 		break;
// 	}



//////////////////////////////////////////////////////
	LCD_WriteRegister16(0x0020, x);
	LCD_WriteRegister16(0x0021, y);
	LCD_WriteRegister16(0x0022, color);

	LCD_CS_HIGH();
}




// void LCD_DrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
// {
// 	// Bresenham's algorithm - thx wikpedia
// 	int16_t swap;
// 	int16_t steep;
// 	int16_t dx, dy;
// 	int16_t err ;
// 	int16_t ystep;
// 	err= dx / 2;
// 	dx = abs(x2 - x1);
// 	
// 	dy = abs(y2 - y1);
// 	
// 	/*

// 	 steep = abs(y2 - y1) > abs(x2 - x1);
// 	
// 	if (steep) {
// 		//swap(x1, y1);
// 		//swap(x2, y2);
// 	swap=x1;
// 	x1=y1;
// 	y1=swap;
// 		
// 	swap=x2;
// 	x2=y2;
// 	y2=swap;


// }

// 	if (x1 > x2) {
// 		//swap(x1, x2);
// 		//swap(y1, y2);
// 			swap=x1;
// 			x1=x2;
// 			x2=swap;
// 			swap=y1;
// 			y1=y2;
// 			y2=swap;
// 		
// 		
// 	}

// */

// 	if (y1 < y2) {
// 		ystep = 1;
// 	} else {
// 		ystep = -1;
// 	}

// 	for (; x1<=x2; x1++) {
// 		if (steep) {
// 			LCD_DrawPixel(y1, x1, color);
// 		} else {
// 			LCD_DrawPixel(x1, y1, color);
// 		}
// 		err -= dy;
// 		if (err < 0) {
// 			y1 += ystep;
// 		err += dx;
// 		}
// 	}
// }





void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0, 
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0, 
  curpixel = 0;
  
  deltax = abs(x2 - x1);        /* The difference between the x's */
  deltay = abs(y2 - y1);        /* The difference between the y's */
  x = x1;                       /* Start x off at the first pixel */
  y = y1;                       /* Start y off at the first pixel */
  
  if (x2 >= x1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }
  
  if (y2 >= y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }
  
  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    numadd = deltay;
    numpixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    numadd = deltax;
    numpixels = deltay;         /* There are more y-values than x-values */
  }
  
  for (curpixel = 0; curpixel <= numpixels; curpixel++)
  {
    LCD_DrawPixel(x, y, color);						  /* Draw the current pixel */
    num += numadd;                            /* Increase the numerator by the top of the fraction */
    if (num >= den)                           /* Check if numerator >= denominator */
    {
      num -= den;                             /* Calculate the new numerator value */
      x += xinc1;                             /* Change the x as appropriate */
      y += yinc1;                             /* Change the y as appropriate */
    }
    x += xinc2;                               /* Change the x as appropriate */
    y += yinc2;                               /* Change the y as appropriate */
  }
}





/**
 * \brief Draws a horizontal line
 *
 * \param x			The x-coordinate of the first point
 * \param y			The y-coordinate of the first point
 * \param length	Length of the line
 * \param color	Color
 * 
 * \return void
 */
void LCD_DrawFastHLine(int16_t x, int16_t y, int16_t length, uint16_t color)
{
	int16_t x2;
//	int16_t t;
	
	////////////////////////////////////////test
	
// 		switch(m_rotation) {
// 	case 1:
// 		t = x;
// 		x = TFTHEIGHT  - 1 - y;
// 		y = t;
// 		break;
// 	case 2:
// 		x = TFTWIDTH  - 1 - x;
// 		y = TFTHEIGHT - 1 - y;
// 		break;
// 	case 3:
// 		t = x;
// 		x = y;
// 		y = TFTHEIGHT - 1 - t;
// 		break;
// 	}

	////////////////////////////////////////////

	// Initial off-screen clipping
	if((length <= 0) || (y <  0) || (y >= m_height) ||
			(x >= m_width) || ((x2 = (x+length-1)) <  0))
		return;

	if(x < 0) { // Clip left
		length += x;
		x = 0;
	}

	if(x2 >= m_width) { // Clip right
		x2      = m_width - 1;
		length  = x2 - x + 1;
	}

	LCD_SetAddrWindow(x, y, x2, y);
	LCD_Flood(color, length);
	LCD_SetAddrWindow(0, 0, m_width - 1, m_height - 1);

}

/**
 * \brief Draws a vertical line
 *
 * \param x		The x-coordinate of the first point
 * \param y		The y-coordinate of the first point
 * \param h		High of the line
 * \param color	Color
 * 
 * \return void
 */
void LCD_DrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
	// Update in subclasses if desired!
	LCD_DrawLine(x, y, x, y+h-1, color);
}

/**
 * \brief Draws a rectangle specified by a coordinate pair, a width, and a height.
 * 
 * \param x			The x-coordinate of the upper-left corner of the rectangle to draw
 * \param y			The y-coordinate of the upper-left corner of the rectangle to draw
 * \param w			Width of the rectangle to draw
 * \param h			Height of the rectangle to draw
 * \param color		Color
 * 
 * \return void
 */
void LCD_DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	LCD_DrawFastHLine(x, y, w, color);
	LCD_DrawFastHLine(x, y+h-1, w, color);
	LCD_DrawFastVLine(x, y, h, color);
	LCD_DrawFastVLine(x+w-1, y, h, color);
}


/**
 * \brief Draws a rectangle with rounded corners specified by a coordinate pair, a width, and a height.
 * 
 * \param x			The x-coordinate of the upper-left corner of the rectangle to draw
 * \param y			The y-coordinate of the upper-left corner of the rectangle to draw
 * \param w			Width of the rectangle to draw
 * \param h			Height of the rectangle to draw
 * \param r			Radius
 * \param color		Color
 * 
 * \return void
 */
void LCD_DrawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color)
{
	// smarter version
	LCD_DrawFastHLine(x+r  , y    , w-2*r, color); // Top
	LCD_DrawFastHLine(x+r  , y+h-1, w-2*r, color); // Bottom
	LCD_DrawFastVLine(x    , y+r  , h-2*r, color); // Left
	LCD_DrawFastVLine(x+w-1, y+r  , h-2*r, color); // Right
	// draw four corners
	LCD_DrawCircleHelper(x+r    , y+r    , r, 1, color);
	LCD_DrawCircleHelper(x+w-r-1, y+r    , r, 2, color);
	LCD_DrawCircleHelper(x+w-r-1, y+h-r-1, r, 4, color);
	LCD_DrawCircleHelper(x+r    , y+h-r-1, r, 8, color);
}

/**
 * \brief Helper function drawing rounded corners
 * 
 * \param x0			The x-coordinate
 * \param y0			The y-coordinate
 * \param r				Radius
 * \param cornername	Corner (1, 2, 3, 4)
 * \param color			Color
 * 
 * \return void
 */
void LCD_DrawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color)
{
	int16_t f     = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x     = 0;
	int16_t y     = r;

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f     += ddF_y;
		}
		x++;
		ddF_x += 2;
		f     += ddF_x;
		if (cornername & 0x4) {
			LCD_DrawPixel(x0 + x, y0 + y, color);
			LCD_DrawPixel(x0 + y, y0 + x, color);
		}
		if (cornername & 0x2) {
			LCD_DrawPixel(x0 + x, y0 - y, color);
			LCD_DrawPixel(x0 + y, y0 - x, color);
		}
		if (cornername & 0x8) {
			LCD_DrawPixel(x0 - y, y0 + x, color);
			LCD_DrawPixel(x0 - x, y0 + y, color);
		}
		if (cornername & 0x1) {
			LCD_DrawPixel(x0 - y, y0 - x, color);
			LCD_DrawPixel(x0 - x, y0 - y, color);
		}
	}
}

/**
 * \brief Draws an circle defined by a pair of coordinates and radius
 * 
 * \param x0		The x-coordinate
 * \param y0		The y-coordinate
 * \param r			Radius
 * \param color		Color
 * 
 * \return void
 */
void LCD_DrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	LCD_DrawPixel(x0  , y0+r, color);
	LCD_DrawPixel(x0  , y0-r, color);
	LCD_DrawPixel(x0+r, y0  , color);
	LCD_DrawPixel(x0-r, y0  , color);

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		LCD_DrawPixel(x0 + x, y0 + y, color);
		LCD_DrawPixel(x0 - x, y0 + y, color);
		LCD_DrawPixel(x0 + x, y0 - y, color);
		LCD_DrawPixel(x0 - x, y0 - y, color);
		LCD_DrawPixel(x0 + y, y0 + x, color);
		LCD_DrawPixel(x0 - y, y0 + x, color);
		LCD_DrawPixel(x0 + y, y0 - x, color);
		LCD_DrawPixel(x0 - y, y0 - x, color);
	}
}



void LCD_DrawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size)
{
	
	int8_t i=0;
	int8_t j = 0;
	if((x >= m_width)            || // Clip right
		(y >= m_height)          || // Clip bottom
		((x + 6 * size - 1) < 0) || // Clip left
		((y + 8 * size - 1) < 0))   // Clip top
			return;

	for (i=0; i<6; i++ ) {
		uint8_t line;
		if (i == 5) {
			line = 0x0;
		} else {
			line = font[c*5 + i];//pgm_read_byte(font+(c*5)+i);
			for (j = 0; j<8; j++) {
				if (line & 0x1) {
					if (size == 1) { // default size
						LCD_DrawPixel(x+i, y+j, color);
					} else {  // big size
						LCD_FillRect(x+(i*size), y+(j*size), size, size, color);
					}
				} else if (bg != color) {
					if (size == 1) { // default size
						LCD_DrawPixel(x+i, y+j, bg);
					} else {  // big size
						LCD_FillRect(x+i*size, y+j*size, size, size, bg);
					}
				}
				line >>= 1;
			}
		}
	}
}


//////////////////////////////////////////////



void LCD_DrawChar10(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size)
{
	uint8_t x_max;
	uint8_t x_temp;
	uint8_t line;
	int8_t Byte_1=0;
	uint16_t GetByte=0;
	uint8_t Byte_multiplied=0;
	int8_t i=0;
	int8_t j = 0;
	size=1;
	if((x >= m_width)            || // Clip right
		(y >= m_height)          || // Clip bottom
		((x + 6 * size - 1) < 0) || // Clip left
		((y + 8 * size - 1) < 0))   // Clip top
			return;
		Byte_1=0;
	for (i=0; i<14; i++ ) {
		
		
		if (i == 13) {
			line = 0x0;
			
		} else {
			
			for(Byte_1=0;Byte_1<2;Byte_1++)
			{
			
			if(Byte_1==0)
			{
				Byte_multiplied=i*2;
				GetByte= ((c-33)*28 )+ Byte_multiplied;
			line = font10[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=8;
				x_temp=0;
			}
			else if(Byte_1==1)
			{
				Byte_multiplied=i*2;
				GetByte= ((c-33)*28 )+ Byte_multiplied+1;
			line = font10[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=16;
				x_temp=8;
			}

			
			for (j = x_temp; j<x_max; j++) {
				if (line & 0x80) {
					
						LCD_DrawPixel(x+j, y+i, color);
					
				} else if (bg != color) {
					
						LCD_DrawPixel(x+j, y+i, bg);
					 
				}
				line <<= 1;
			}
		}
// 						if(Byte_1==0)
// 			{
// 			Byte_1=1;
// 			}
// 					else
// 			{
// 			Byte_1=0;
// 			}	

			
			
// 			for (j = x_temp; j<x_max; j++) {
// 				if (line & 0x1) {
// 					
// 						LCD_DrawPixel(x+j, y+i, color);
// 					
// 				} else if (bg != color) {
// 					
// 						LCD_DrawPixel(x+j, y+i, bg);
// 					 
// 				}
// 				line >>= 1;
// 			}


			
			
		}
	}
}



/////////////////////////////////////////////////////////////////



void LCD_DrawChar20(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size)
{
	uint8_t x_max;
	uint8_t x_temp;
	uint8_t line;
	int8_t Byte_1=0;
	uint16_t GetByte=0;
	uint8_t Byte_multiplied=0;
	int8_t i=0;
	int8_t j = 0;
	size=1;
	if((y >= m_height)            || // Clip right
		(x >= m_width )          || // Clip bottom
		((x + 6 * size - 1) < 0) || // Clip left
		((y + 8 * size - 1) < 0))   // Clip top
			return;
		Byte_1=0;
	for (i=0; i<27; i++ ) {
		
		
		if (i == 26) {
			line = 0x0;
			
		} else {
			
			for(Byte_1=0;Byte_1<5;Byte_1++)
			{
			
			if(Byte_1==0)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-32)*104 )+ Byte_multiplied;
			line = font20[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=8;
				x_temp=0;
			}
			else if(Byte_1==1)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-32)*104 )+ Byte_multiplied+1;
			line = font20[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=16;
				x_temp=8;
			}
						if(Byte_1==2)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-32)*104 )+ Byte_multiplied+2;
			line = font20[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=24;
				x_temp=16;
			}
			else if(Byte_1==3)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-32)*104 )+ Byte_multiplied+3;
			line = font20[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=30;
				x_temp=24;
			}

			
			for (j = x_temp; j<x_max; j++) {
				if (line & 0x80) {
					
						LCD_DrawPixel(x+j, y+i, color);
					
				} else if (bg != color) {
					
						LCD_DrawPixel(x+j, y+i, bg);
					 
				}
				line <<= 1;
			}
		}
// 						if(Byte_1==0)
// 			{
// 			Byte_1=1;
// 			}
// 					else
// 			{
// 			Byte_1=0;
// 			}	

			
			
// 			for (j = x_temp; j<x_max; j++) {
// 				if (line & 0x1) {
// 					
// 						LCD_DrawPixel(x+j, y+i, color);
// 					
// 				} else if (bg != color) {
// 					
// 						LCD_DrawPixel(x+j, y+i, bg);
// 					 
// 				}
// 				line >>= 1;
// 			}


			
			
		}
	}
}


////////////////////////////////////////////////////////////font36



void LCD_DrawChar36(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size)
{
	uint8_t x_max;
	uint8_t x_temp;
	uint8_t line;
	int8_t Byte_1=0;
	uint16_t GetByte=0;
	uint8_t Byte_multiplied=0;
	int8_t i=0;
	int8_t j = 0;
//	size=1;
	if((x >= m_width)            || // Clip right
		(y >= m_height)          || // Clip bottom
		((x + 6 * size - 1) < 0) || // Clip left
		((y + 8 * size - 1) < 0))   // Clip top
			return;
		Byte_1=0;
	for (i=0; i<37; i++ ) {
		
		
		if (i == 36) {
			line = 0x0;
			
		} else {
			
			for(Byte_1=0;Byte_1<4;Byte_1++)
			{
			
			if(Byte_1==0)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-48)*144 )+ Byte_multiplied;
			line = font36[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=8;
				x_temp=0;
			}
			else if(Byte_1==1)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-48)*144 )+ Byte_multiplied+1;
			line = font36[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=16;
				x_temp=8;
			}
						if(Byte_1==2)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-48)*144 )+ Byte_multiplied+2;
			line = font36[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=24;
				x_temp=16;
			}
			else if(Byte_1==3)
			{
				Byte_multiplied=i*4;
				GetByte= ((c-48)*144 )+ Byte_multiplied+3;
			  line = font36[GetByte];//pgm_read_byte(font+(c*5)+i);
				x_max=28;
				x_temp=24;
			}

			
			for (j = x_temp; j<x_max; j++) {
				if (line & 0x80) {
					
						LCD_DrawPixel(x+j, y+i, color);
// 					if (size == 1) { // default size
// 						LCD_DrawPixel(x+j, y+i, color);
// 					} else {  // big size
// 						LCD_FillRect(x+(j*size), y+(i*size), size, size, color);
// 					}
					
				} else if (bg != color) {
					
						LCD_DrawPixel(x+j, y+i, bg);
// 										if (size == 1) { // default size
// 						LCD_DrawPixel(x+j, y+i, bg);
// 					} else {  // big size
// 						LCD_FillRect(x+j*size, y+i*size, size, size, bg);
// 					}
					 
				}
				line <<= 1;
			}
		}
		
		}
	}
}





////////////////////////////////////////////////


/**
 * \brief Draws a filled circle defined by a pair of coordinates and radius
 * 
 * \param x0		The x-coordinate
 * \param y0		The y-coordinate
 * \param r			Radius
 * \param color		Color
 * 
 * \return void
 */
void LCD_FillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
  LCD_DrawFastVLine(x0, y0-r, 2*r+1, color);
  LCD_FillCircleHelper(x0, y0, r, 3, 0, color);
}


/**
 * \brief Helper function to draw a filled circle
 * 
 * \param x0			The x-coordinate
 * \param y0			The y-coordinate
 * \param r				Radius
 * \param cornername	Corner (1, 2, 3, 4)
 * \param delta			Delta
 * \param color			Color
 * 
 * \return void
 */
void LCD_FillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color)
{
	int16_t f     = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x     = 0;
	int16_t y     = r;

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f     += ddF_y;
		}
		x++;
		ddF_x += 2;
		f     += ddF_x;

		if (cornername & 0x1) {
			LCD_DrawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
			LCD_DrawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
		}
		if (cornername & 0x2) {
			LCD_DrawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
			LCD_DrawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
		}
	}
}

/**
 * \brief Draws a filled rectangle specified by a coordinate pair, a width, and a height.
 * 
 * \param x				The x-coordinate of the upper-left corner of the rectangle to draw
 * \param y				The y-coordinate of the upper-left corner of the rectangle to draw
 * \param w				Width of the rectangle to draw
 * \param h				Height of the rectangle to draw
 * \param fillcolor		Color
 * 
 * \return void
 */
void LCD_FillRect(int16_t x, int16_t y1, int16_t w, int16_t h, uint16_t fillcolor)
{
	int16_t  x2, y2;

	// Initial off-screen clipping
	if( (w <= 0) || (h <= 0) ||
		(x >= m_width) || (y1 >= m_height) ||
		((x2 = x+w-1) <  0) || ((y2  = y1+h-1) <  0))
			return;
	if(x < 0) { // Clip left
		w += x;
		x = 0;
	}
	if(y1 < 0) { // Clip top
		h += y1;
		y1 = 0;
	}
	if(x2 >= m_width) { // Clip right
		x2 = m_width - 1;
		w  = x2 - x + 1;
	}
	if(y2 >= m_height) { // Clip bottom
		y2 = m_height - 1;
		h  = y2 - y1 + 1;
	}

	LCD_SetAddrWindow(x, y1, x2, y2);
	LCD_Flood(fillcolor, (uint32_t)w * (uint32_t)h);
	LCD_SetAddrWindow(0, 0, m_width - 1, m_height - 1);
}

/**
 * \brief Draws a filled rounded rectangle specified by a coordinate pair, a width, and a height.
 * 
 * \param x				The x-coordinate of the upper-left corner of the rectangle to draw
 * \param y				The y-coordinate of the upper-left corner of the rectangle to draw
 * \param w				Width of the rectangle to draw
 * \param h				Height of the rectangle to draw
 * \param r				Radius
 * \param fillcolor		Color
 * 
 * \return void
 */
void LCD_FillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color)
{
	// smarter version
	LCD_FillRect(x+r, y, w-2*r, h, color);

	// draw four corners
	LCD_FillCircleHelper(x+w-r-1, y+r, r, 1, h-2*r-1, color);
	LCD_FillCircleHelper(x+r    , y+r, r, 2, h-2*r-1, color);
}

/**
 * \brief Fills the screen with the specified color
 * 
 * \param color	Color
 * 
 * \return void
 */
void LCD_FillScreen(uint16_t color)
{
	// For the 932X, a full-screen address window is already the default
	// state, just need to set the address pointer to the top-left corner.
	// Although we could fill in any direction, the code uses the current
	// screen rotation because some users find it disconcerting when a
	// fill does not occur top-to-bottom.
	uint16_t x, y;
	switch(m_rotation) {
		default: x = 0            ; y = 0            ; break;
		case 1 : x = TFTWIDTH  - 1; y = 0            ; break;
		case 2 : x = TFTWIDTH  - 1; y = TFTHEIGHT - 1; break;
		case 3 : x = 0            ; y = TFTHEIGHT - 1; break;
	}
	LCD_CS_LOW();
	LCD_WriteRegister16(0x0020, x);
	LCD_WriteRegister16(0x0021, y);

	LCD_Flood(color, (long)TFTWIDTH * (long)TFTHEIGHT);
}



void LCD_Flood(uint16_t color, uint32_t len)
{
	uint16_t blocks;
	uint8_t  i, hi = color >> 8, lo = color;

	LCD_CS_LOW();
	LCD_DC_LOW();
	LCD_IO_WriteReg(0x0022);

	// Write first pixel normally, decrement counter by 1
	LCD_CS_LOW();
	LCD_DC_HIGH();
	LCD_IO_WriteData(color);
	len--;
	LCD_CS_LOW();
	LCD_DC_HIGH();
	blocks = (uint16_t)(len / 64); // 64 pixels/block
	if(hi == lo) {
		// High and low bytes are identical.  Leave prior data
		// on the port(s) and just toggle the write strobe.
		while(blocks--) {
			i = 16; // 64 pixels/block / 4 pixels/pass
			do {
				Toggle_LCD_RW(); Toggle_LCD_RW(); Toggle_LCD_RW(); Toggle_LCD_RW(); // 2 bytes/pixel
				Toggle_LCD_RW(); Toggle_LCD_RW(); Toggle_LCD_RW(); Toggle_LCD_RW(); // x 4 pixels
			} while(--i);
		}
				// Fill any remaining pixels (1 to 64)
		for(i = (uint8_t)len & 63; i--; ) {
			Toggle_LCD_RW();
			Toggle_LCD_RW();
		}
	} else {
		while(blocks--) {
				i = 16; // 64 pixels/block / 4 pixels/pass
			do {
				LCD_IO_WriteData(color); LCD_IO_WriteData(color);
				LCD_IO_WriteData(color); LCD_IO_WriteData(color);
			} while(--i);
		}
		for(i = (uint8_t)len & 63; i--; ) {
				LCD_IO_WriteData(color);
		}
	}
	LCD_CS_HIGH();
}



/**
 * \brief Print the specified Text
 * 
 * \param fmt	Format text
 * \param 
 * 
 * \return void
 */
void LCD_Printf(const char *fmt, ...)
{
	static char buf[256];
	char *p;
	va_list lst;

	va_start(lst, fmt);
	vsprintf(buf, fmt, lst);
	va_end(lst);

	p = buf;
	while(*p) {
		if (*p == '\n') {
			m_cursor_y += m_textsize*8;
			m_cursor_x  = 0;
		} else if (*p == '\r') {
			// skip em
		} else {
			LCD_DrawChar(m_cursor_x, m_cursor_y, *p, m_textcolor, m_textbgcolor, m_textsize);
			m_cursor_x += m_textsize*6;
			if (m_wrap && (m_cursor_x > (m_width - m_textsize*6))) {
				m_cursor_y += m_textsize*8;
				m_cursor_x = 0;
			}
		}
		p++;
	}
}

/////////////////////////////////////////////////////////////// font size test



void LCD_Printf10(const char *fmt, ...)
{
	static char buf[256];
	char *p;
	va_list lst;

	va_start(lst, fmt);
	vsprintf(buf, fmt, lst);
	va_end(lst);

	p = buf;
	while(*p) {
		if (*p == '\n') {
			m_cursor_y += m_textsize*8;
			m_cursor_x  = 0;
		} else if (*p == '\r') {
			// skip em
		} else {
			LCD_DrawChar10(m_cursor_x, m_cursor_y, *p, m_textcolor, m_textbgcolor, m_textsize);
			m_cursor_x += m_textsize*12;
			if (m_wrap && (m_cursor_x > (m_width - m_textsize*6))) {
				m_cursor_y += m_textsize*8;
				m_cursor_x = 0;
			}
		}
		p++;
	}
}
////////////////////////////////////////////////////////////////////


void LCD_Printf20( char *fmt, ...)
{
//	static char buf[256];
	char *p;
// 	va_list lst;

// 	va_start(lst, fmt);
// 	vsprintf(buf, fmt, lst);
// 	va_end(lst);

// 	p = buf;
	p=fmt;
	while(*p) {
		if (*p == '\n') {
			m_cursor_y += m_textsize*8;
			m_cursor_x  = 0;
		} else if (*p == '\r') {
			// skip em
		} else {
			LCD_DrawChar20(m_cursor_x, m_cursor_y, *p, m_textcolor, m_textbgcolor, m_textsize);
			m_cursor_x += m_textsize*25;
			if (m_wrap && (m_cursor_x > (324 - m_textsize*6))) {
				m_cursor_y += m_textsize*52;
				m_cursor_x = 0;
			}
		}
		p++;
	}
}



/////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////


void LCD_Printf36(const char *fmt, ...)
{
	static char buf[256];
	char *p;
	va_list lst;

	va_start(lst, fmt);
	vsprintf(buf, fmt, lst);
	va_end(lst);

	p = buf;
	while(*p) {
		if (*p == '\n') {
			m_cursor_y += m_textsize*8;
			m_cursor_x  = 0;
		} else if (*p == '\r') {
			// skip em
		}
		
		/////////////////////test exiting
		else if (*p ==' ') {
			break;
		}
		
		///////////////////////

		else {
			LCD_DrawChar36(m_cursor_x, m_cursor_y, *p, m_textcolor, m_textbgcolor, m_textsize);
			m_cursor_x += m_textsize*28;
			if (m_wrap && (m_cursor_x > (m_width - m_textsize*6))) {
				m_cursor_y += m_textsize*40;
				m_cursor_x = 0;
			}
		}
		p++;
	}
}








////////////////////////////////////////////////////////////  font size test ends

/**
 * \brief Resets the Display
 * 
 * \param 
 * 
 * \return void
 */
void LCD_Reset(void)
{
	
	uint8_t i;
	LCD_CS_HIGH();
	LCD_RW_HIGH();
	LCD_RD_HIGH();

	LCD_RST_LOW();
	delay(100);
	LCD_RST_HIGH();

	// Data transfer sync
	LCD_CS_LOW();

	LCD_DC_LOW();
	LCD_IO_WriteReg(0x0000);
	for(i=0; i<2; i++) Toggle_LCD_RW(); // Three extra 0x00s
	LCD_CS_HIGH();
}







/**
 * \brief Sets the cursor coordinates
 * 
 * \param x		The x-coordinate
 * \param y		The y-coordinate
 * 
 * \return void
 */
void LCD_SetCursor(unsigned int x, unsigned int y)
{
	m_cursor_x = x;
	m_cursor_y = y;
}

/**
 * \brief Sets the text size
 * 
 * \param s	Size
 * 
 * \return void
 */
void LCD_SetTextSize(uint8_t s)
{
	m_textsize = (s > 0) ? s : 1;
}

/**
 * \brief Sets the text color
 * 
 * \param c		Text color
 * \param b		Background color
 * 
 * \return void
 */
void LCD_SetTextColor(uint16_t c, uint16_t b)
{
	m_textcolor   = c;
	m_textbgcolor = b;
}

/**
 * \brief Set Text wrap
 * 
 * \param w 
 * 
 * \return void
 */
void LCD_SetTextWrap(uint8_t w)
{
	m_wrap = w;
}

/**
 * \brief Set display rotation
 * 
 * \param x	rotation
 * 
 * \return void
 */



void Print_Text_On(uint8_t line, uint8_t position)
{

LCD_SetCursor(position*m_textsize,line);


}

/////////////////////////////////////////////////////////



