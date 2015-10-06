


#include "main.h"

extern __IO uint16_t   aADCxConvertedValues[ADCCONVERTEDVALUES_BUFFER_SIZE];
extern uint16_t PumpingRate;

uint32_t ad_value;

int main()
{
	  uint8_t Running=0;
	  uint32_t  buttonstate;
		uint32_t  buttonstate2;
	
	uint16_t test1=0;
	
	uint16_t x;
	uint16_t y;
	
	
	/* STM32F103xB HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */

HAL_Init(); 
	
	  /* Configure the system clock = 64 MHz */
  SystemClock_Config();

Button_Init();
//TIM4_Init ();
LCD_Delay(8000);
st7783_Init();
	ad_value=Syringe_Size();
	//aADCxConvertedValues[10]=0;
m_textbgcolor=BLACK;	


LCD_SetRotation(1);
//Display_Clear(CYAN);

	//LCD_DrawFastHLine(40,40,30,BLACK);


// 	Display_Clear(GREEN);
// 	LCD_Delay(8000);
// 		Display_Clear(RED);
// 	LCD_Delay(8000);
// 		Display_Clear(BLUE);
// 	LCD_Delay(8000);
		Display_Clear(YELLOW);
	LCD_Delay(8000);
		Display_Clear(MAGENTA);
	LCD_Delay(8000);
		Display_Clear(BLACK);
	LCD_Delay(2000);
 //Syringe_Size_stop();	
	
	//LCD_FillRect(1,1,319,32,LIGHTGRAY);

// 	LCD_SetTextSize(1);
// 	LCD_SetTextColor(RED,WHITE);
// 	Print_Text_On(Line3,Position10);
//   LCD_Printf3("1");
// 	Print_Text_On(Line4,Position10);
//   LCD_Printf20("RATE");
// 	LCD_SetTextColor(BLUE,WHITE);
// 	Print_Text_On(Line4,Position25);
//   LCD_Printf36("321");
// 	Print_Text_On(Line8,Position10);
//   LCD_Printf("K");
// 	while(1)
// 	{
// }
// 	




///////////////////////////////////////////////////////

//	LCD_SetAddrWindow(50, 10, 200, 10);
//	LCD_Flood(RED, 319);
	//while(1);



//////////////////////////////////////////////////////////
		
		/////////////////////////////////////////test
// 		for(test1=0;test1<319;test1++)
// 		{
// 		LCD_DrawPixel(test1,100,RED);
// 		
// 		LCD_DrawPixel(test1,150,BLUE);
// 		
// 		}
// 		
// 		while(1);
// 		LCD_DrawPixel(300,200,GREEN);
// 		
		//////////////////////////////////////////////
//	LCD_FillRoundRect(50,50,150,100,20,RED);	
	LCD_SetTextSize(1);
	LCD_SetTextColor(GRAY,m_textbgcolor);
	Print_Text_On(Line1,Position1);
  LCD_Printf20("ClassB ");
	//while(1);
	//Print_Text_On(Line1,Position8);
	//LCD_SetTextSize(2);
	LCD_SetTextColor(GREEN,BLACK);
  //LCD_Printf20("10ml");
	Print_Syringe_Size(10);
	Print_Text_On(Line1,Position41);	
 	LCD_Printf20("ml");
// 	LCD_SetTextColor(GREEN,WHITE);
//   LCD_Printf20("OCCL:H");
	LCD_DrawFastHLine(1,38,319,RED);
	//LCD_FillRect(1,39,319,160,GRAY);
	LCD_DrawRoundRect(20,50,280,130,10,BLACK);
	
	LCD_SetTextSize(1);
	Print_Text_On(Line3,Position14);
	LCD_SetTextColor(WHITE,m_textbgcolor);
  LCD_Printf3("RATE");
	
	
	LCD_SetTextSize(1);
	  //LCD_Printf36("300");
	//PrintDecimal(200);
	PrintRate(PumpingRate);
	
	
		LCD_SetTextSize(1);
	Print_Text_On(Line5,Position33);
	LCD_SetTextColor(WHITE,m_textbgcolor);
  LCD_Printf20("ml/h");
	
	LCD_DrawFastHLine(1,200,319,RED);
	LCD_SetCursor(2,Line9);
	LCD_SetTextSize(1);
	LCD_SetTextColor(YELLOW,m_textbgcolor);
  LCD_Printf20("Limit");
	//LCD_Delay(4000);
	//LCD_Delay(8000);
	PWM_Freq(200);


////////////////////////////////////////////////////////test adc


// while(1)
// {
// 	LCD_SetTextSize(1);
// 	Print_Text_On(Line1,Position5);
//   //LCD_Printf("ClassB     ");
// 	Print_Text_On(Line1,Position12);
// 	//LCD_SetTextSize(2);
// 	LCD_SetTextColor(BLUE,WHITE);
//   //PrintDecimal(Syringe_Size());
// 	Print_Syringe_Size(Syringe_Size());
// 	//LCD_Printf20("ml");
// 			
// }




/////////////////////////////////////////////////////////

	while(1)
	{

		
if(!Read_OK_Button())
{
		while(!Read_OK_Button());
	if(Running==0)
	{
	LCD_SetCursor(2,Line7);
	LCD_SetTextSize(1);
	LCD_SetTextColor(BLUE,m_textbgcolor);
  LCD_Printf("Rate ");
	PumpRate();
	}

}
if(!Read_START_Button())
{
	LCD_SetCursor(2,Line7);
	LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,m_textbgcolor);
  LCD_Printf("start");
	PWM_ON();
	Running=1;
}
	
if(!Read_STOP_Button())
{
	LCD_SetCursor(2,Line7);
	LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,m_textbgcolor);
  LCD_Printf("stop ");
	PWM_OFF();
	Running=0;
}
	

	
	//test=aADCxConvertedValues[10];

// 	LCD_SetTextSize(2);
// 	Print_Text_On(Line1,Position5);
//   //LCD_Printf("ClassB     ");
// 	//Print_Text_On(Line1,Position8);
// 	//LCD_SetTextSize(2);
// 	LCD_SetTextColor(BLUE,WHITE);
//   //PrintDecimal(aADCxConvertedValues[10]);
// 		PrintRate(aADCxConvertedValues[10]);		
}


}


void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef clkinitstruct = {0};
  RCC_OscInitTypeDef oscinitstruct = {0};
  
  /* Configure PLL ------------------------------------------------------*/
  /* PLL configuration: PLLCLK = (HSI / 2) * PLLMUL = (8 / 2) * 16 = 64 MHz */
  /* PREDIV1 configuration: PREDIV1CLK = PLLCLK / HSEPredivValue = 64 / 1 = 64 MHz */
  /* Enable HSI and activate PLL with HSi_DIV2 as source */
  oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSI;
  oscinitstruct.HSEState        = RCC_HSE_OFF;
  oscinitstruct.LSEState        = RCC_LSE_OFF;
  oscinitstruct.HSIState        = RCC_HSI_ON;
  oscinitstruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  oscinitstruct.HSEPredivValue    = RCC_HSE_PREDIV_DIV1;
  oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
  oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSI_DIV2;
  oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
  clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
}