


#include "main.h"

extern __IO uint16_t   aADCxConvertedValues[ADCCONVERTEDVALUES_BUFFER_SIZE];
extern uint16_t PumpingRate;
extern uint8_t Current_Screen;
uint16_t Syringe_Size_Current=0;
uint16_t Injected_Volume=0;

int main()
{
	  uint8_t Running=0;
//	  uint32_t  buttonstate;
//		uint32_t  buttonstate2;
		uint8_t Misplace_alarm_ON=0;
	
	uint32_t test1=0;
	
//	uint16_t x;
//	uint16_t y;
	
	
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
IR_SENSOR_Init();
TIM4_Init ();
ADC_Config();
HAL_Delay(500);
st7783_Init();
//TIM3_init();
	//ad_value=Get_Syringe_Size();
	//aADCxConvertedValues[10]=0;
m_textbgcolor=BLACK;	
// while(1)
// {
// HAL_GPIO_WritePin(LCD_GPIO_PORT, GPIO_PIN_7, GPIO_PIN_SET);
// HAL_Delay(500);
// HAL_GPIO_WritePin(LCD_GPIO_PORT, GPIO_PIN_7, GPIO_PIN_RESET);
// HAL_Delay(500);	

// }

// PWM_Freq(100);
// 	
// PWM_ON();
// while(1)
// {
// }

// LCD_SetRotation(1);
// Display_Clear(WHITE);
// LCD_SetAddrWindow(0,0,320,240);
// LCD_Flood1(RED,(320*250*2));

// while(1);
//Display_Clear(CYAN);

	//LCD_DrawFastHLine(40,40,30,BLACK);


// 	Display_Clear(GREEN);
// 	LCD_Delay(8000);
// 		Display_Clear(RED);
// 	LCD_Delay(8000);
// 		Display_Clear(BLUE);
// 	LCD_Delay(8000);
		Display_Clear(YELLOW);


Initial_Screen();

/////////////////////////////////////////////////////////

	while(1)
	{
		
		if(Syringe_Size_Current!=Get_Syringe_Size())
		{
			while((Syringe_Size_Current=Get_Syringe_Size())==99)
			{

			Alarm_Syringe_Misplacement();
			Misplace_alarm_ON=1;
				//Alarm_Piston_Lock();
			Running=0;	
			
			}
			
			if(Syringe_Size_Current!=99)
			{
			//Initial_Screen();
			Print_Syringe_Size(Syringe_Size_Current);
			Misplace_alarm_ON=0;
			Running=0;

			}
			
		}
		
	if(!Read_PISTON_SENSOR())	
	{
		
		if(Misplace_alarm_ON==0)	
		{
			Alarm_Piston_Lock();
			Running=0;
		}
	}
	else if(Running==1)
	{
		
			if(!Read_STOP_SENSOR())
			{
					Finishing_Screen();
					Running=0;

			}
		
			if(	Current_Screen!=2)
					Running_Screen();
	
	}	

	else Initial_Screen();
		
		
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
	LCD_SetTextSize(1);
	LCD_SetTextColor(BLUE,m_textbgcolor);
  LCD_Printf("start");
	Motor_Speed(PumpingRate,Get_Syringe_Size());
	PWM_ON();
	Running=1;
}
	
if(!Read_STOP_Button())
{
	LCD_SetCursor(2,Line7);
	LCD_SetTextSize(1);
	LCD_SetTextColor(BLUE,m_textbgcolor);
  LCD_Printf("stop ");
	PWM_OFF();
	Running=0;
	Initial_Screen();
	
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



