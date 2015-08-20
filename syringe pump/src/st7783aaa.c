#include "st7783.h"


#define TFTWIDTH   240
#define TFTHEIGHT  320

#define TFTLCD_DELAY 0xFF



// Initialization commands
static const uint16_t ST7781_regValues[] = {
	0x0001,0x0100,
	0x0002,0x0700,
	0x0003,0x1030,
	0x0008,0x0302,
	0x0009,0x0000,
	0x000A,0x0008,
	//*******POWER CONTROL REGISTER INITIAL*******//
	0x0010,0x0790,
	0x0011,0x0005,
	0x0012,0x0000,
	0x0013,0x0000,
	//delayms(50,
	//********POWER SUPPPLY STARTUP 1 SETTING*******//
	0x0010,0x12B0,
	// delayms(50,
	0x0011,0x0007,
	//delayms(50,
	//********POWER SUPPLY STARTUP 2 SETTING******//
	0x0012,0x008C,
	0x0013,0x1700,
	0x0029,0x0022,
	// delayms(50,
	//******GAMMA CLUSTER SETTING******//
	0x0030,0x0000,
	0x0031,0x0505,
	0x0032,0x0205,
	0x0035,0x0206,
	0x0036,0x0408,
	0x0037,0x0000,
	0x0038,0x0504,
	0x0039,0x0206,
	0x003C,0x0206,
	0x003D,0x0408,
	// -----------DISPLAY WINDOWS 240*320-------------//
	0x0050,0x0000,
	0x0051,0x00EF,
	0x0052,0x0000,
	0x0053,0x013F,
	//-----FRAME RATE SETTING-------//
	0x0060,0xA700,
	0x0061,0x0001,
	0x0090,0x0033, //RTNI setting
	//-------DISPLAY ON------//
	0x0007,0x0133,    0x0001,0x0100,
	0x0002,0x0700,
	0x0003,0x1030,
	0x0008,0x0302,
	0x0009,0x0000,
	0x000A,0x0008,
	//*******POWER CONTROL REGISTER INITIAL*******//
	0x0010,0x0790,
	0x0011,0x0005,
	0x0012,0x0000,
	0x0013,0x0000,
	//delayms(50,
	//********POWER SUPPPLY STARTUP 1 SETTING*******//
	0x0010,0x12B0,
	// delayms(50,
	0x0011,0x0007,
	// delayms(50,
	//********POWER SUPPLY STARTUP 2 SETTING******//
	0x0012,0x008C,
	0x0013,0x1700,
	0x0029,0x0022,
	// delayms(50,
	//******GAMMA CLUSTER SETTING******//
	0x0030,0x0000,
	0x0031,0x0505,
	0x0032,0x0205,
	0x0035,0x0206,
	0x0036,0x0408,
	0x0037,0x0000,
	0x0038,0x0504,
	0x0039,0x0206,
	0x003C,0x0206,
	0x003D,0x0408,
	// -----------DISPLAY WINDOWS 240*320-------------//
	0x0050,0x0000,
	0x0051,0x00EF,
	0x0052,0x0000,
	0x0053,0x013F,
	//-----FRAME RATE SETTING-------//
	0x0060,0xA700,
	0x0061,0x0001,
	0x0090,0x0033, //RTNI setting
	//-------DISPLAY ON------//
	0x0007,0x0133,
};


void delay(unsigned int t)
{
	for (; t > 0; t-- )
	{
	__asm("nop");
	}
}


void st7783_Init(void)
{    
  uint16_t data = 0;
  
	m_width     = TFTWIDTH;
	m_height    = TFTHEIGHT;
	m_rotation  = 0;
	m_cursor_y  = m_cursor_x    = 0;
	m_textsize  = 4;
	m_textcolor = m_textbgcolor = 0xFFFF;
	m_wrap      = 1;
  /* Initialize st7783 low level bus layer -----------------------------------*/
  LCD_IO_Init();
	LCD_Reset();
	

	
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
  HAL_Delay(Delay);
}



void LCD_WriteRegister16(uint16_t LCDReg, uint16_t LCDRegValue)
{
  LCD_IO_WriteReg(LCDReg);
  LCD_IO_WriteMultipleData(&LCDRegValue, 1);
}

///////////

