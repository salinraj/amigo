


#include "main.h"

int main()
{
	uint8_t Running=0;
	
	uint32_t  buttonstate;
		uint32_t  buttonstate2;
	
	
	
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
st7783_Init();
Button_Init();
TIM4_Init ();
LCD_SetRotation(1);
//Display_Clear(CYAN);

	//LCD_DrawFastHLine(40,40,30,BLACK);


	Display_Clear(GREEN);
	LCD_Delay(8000);
		Display_Clear(RED);
	LCD_Delay(8000);
		Display_Clear(BLUE);
	LCD_Delay(8000);
		Display_Clear(YELLOW);
	LCD_Delay(8000);
		Display_Clear(MAGENTA);
	LCD_Delay(8000);
			Display_Clear(WHITE);
	LCD_Delay(8000);
	
	
	//LCD_FillRect(1,1,319,32,LIGHTGRAY);
		
	LCD_SetTextSize(2);
	LCD_SetTextColor(GREEN,WHITE);
	Print_Text_On(Line1,Position1);
  LCD_Printf("ClassB     ");
	//Print_Text_On(Line1,Position8);
	//LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,WHITE);
  LCD_Printf("10ml     ");
	LCD_SetTextColor(GREEN,WHITE);
  LCD_Printf("OCCL:H");
	LCD_DrawFastHLine(1,30,319,RED);
	
	LCD_FillRect(Position2,Line2,90,28,LIGHTGRAY);
	LCD_SetTextSize(3);
	Print_Text_On(Line2,Position2);
	LCD_SetTextColor(BLACK,LIGHTGRAY);
  LCD_Printf("RATE");
	
	
	LCD_SetTextSize(4);
	Print_Text_On(Line4,Position4);
	LCD_SetTextColor(BLACK,WHITE);
  //LCD_Printf("300.0");
	PrintDecimal(200);
	
		LCD_SetTextSize(3);
	
	LCD_SetTextColor(BLACK,WHITE);
  LCD_Printf(" ml/h");
	
	LCD_DrawFastHLine(1,200,319,RED);
	LCD_SetCursor(2,Line8);
	LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,WHITE);
  LCD_Printf("Limit");
	//LCD_Delay(4000);
	//LCD_Delay(8000);
	PWM_Freq(200);
	Syringe_Size();



	while(1)
	{
if(!Read_OK_Button())
{
		while(!Read_OK_Button());
	if(Running==0)
	{
	LCD_SetCursor(2,Line7);
	LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,WHITE);
  LCD_Printf("Rate ");
	PumpRate();
	}

}
if(!Read_START_Button())
{
	LCD_SetCursor(2,Line7);
	LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,WHITE);
  LCD_Printf("start");
	PWM_ON();
	Running=1;
}
	
if(!Read_STOP_Button())
{
	LCD_SetCursor(2,Line7);
	LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,WHITE);
  LCD_Printf("stop ");
	PWM_OFF();
	Running=0;
}
	

	
	
				
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