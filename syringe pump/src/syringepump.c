/*Name : Syringepump.c
created on : 17-08-2015

file includes functions for display of syringpump and motor control for syringe pump

*/

#include "syringepump.h"

uint16_t PumpingRate = 200;
void PumpRate(void)
{
	
	//LCD_SetTextSize(4);
	
	LCD_SetTextColor(BLACK,WHITE);
	while(1)
	{
	if(!Read_UP_Button())
	{
		while(!Read_UP_Button);
		PumpingRate += 10;
		if(PumpingRate>300)
		PumpingRate=300;
	//	PWM_Freq(PumpingRate);
		
		
// 	Print_Text_On(Line4,Position4);
//   LCD_Printf("UP");
	//PrintDecimal(PumpingRate);
	PrintRate(PumpingRate);
	}
	else if(!Read_DOWN_Button())
	{
		while(!Read_DOWN_Button());
		PumpingRate -= 10;
		if(PumpingRate<10)
		PumpingRate=10;
	//	PWM_Freq(PumpingRate);
		
		
// 	Print_Text_On(Line4,Position4);
//   LCD_Printf("DN");
	//PrintDecimal(PumpingRate);
		
		PrintRate(PumpingRate);

	}
	
	else if(!Read_OK_Button())
	{	
		while(!Read_OK_Button());
		
			LCD_SetCursor(2,Line7);
			LCD_SetTextSize(1);
			LCD_SetTextColor(BLUE,BLACK);
			LCD_Printf("     ");
 		HAL_Delay(1000);
		//return;
		break;
	}
	
}
}

void PrintDecimal(uint16_t value,uint8_t Size)
{
 char digit[4]={0,0,0,0};
		digit[0] = (unsigned int)(value/100);									 // Calculate digit1 of ADC_value
		digit[1] = (unsigned int)((value - digit[0]*100)/10);						 // Calculate digit2 of ADC_value
		digit[2] = (unsigned int)((value - (digit[0]*100+digit[1]*10))/1);			 // Calculate digit3 of ADC_value
		//digit[3] = (unsigned int)((value - (digit[0]*1000+digit[1]*100+digit[2]*10))/1);	 // Calculate digit4 of ADC_value
		digit[0]=digit[0]+0x30;
		digit[1]=digit[1]+0x30;
		digit[2]=digit[2]+0x30;
		//digit[3]=digit[3]+0x30;
	if(Size==36)
      LCD_Printf36(digit);
	else if(Size==20)
	{
			LCD_Printf20(&digit[1]);
	}
		
		//LCD_Printf(digit2);
//LCD_Printf(digit3);
//LCD_Printf(digit4);
	
}


/*Print the Rate of injection in ml/hour*/
void PrintRate(uint16_t value)
{
	
	Print_Text_On(Line4,Position18);
	LCD_SetTextColor(WHITE,m_textbgcolor);	
  PrintDecimal(value,36);

}


/*Print the size of the syringe*/
void Print_Syringe_Size(uint16_t value)
{
	LCD_SetTextColor(GREEN,m_textbgcolor);
	Print_Text_On(Line1,Position32);	
  PrintDecimal(value,20);
	
}

void Motor_Speed(uint16_t Rate,uint16_t Size)
{

PWM_Freq(Rate*Size/10);
}


void Alarm_Syringe_Misplacement(void)
{
			PWM_OFF();
			Display_Clear(BLACK);
			Print_Text_On(Line3,Position18);
			LCD_SetTextColor(RED,m_textbgcolor);
			LCD_Printf20("ALERT...");
			Print_Text_On(Line6,Position2);	
			LCD_Printf20("Syringe Misplaced");	
	
			HAL_Delay(15000);
			Initial_Screen();

}

void Initial_Screen(void)
{

	Display_Clear(BLACK);	
	LCD_SetTextSize(1);
	LCD_SetTextColor(GRAY,m_textbgcolor);
	Print_Text_On(Line1,Position1);
  LCD_Printf20("ClassB ");
	
	LCD_SetTextColor(GREEN,BLACK);
  Print_Syringe_Size(Get_Syringe_Size());
	Print_Text_On(Line1,Position41);	
 	LCD_Printf20("ml");
	
	LCD_DrawFastHLine(1,38,319,RED);

	LCD_SetTextSize(1);
	Print_Text_On(Line3,Position14);
	LCD_SetTextColor(WHITE,m_textbgcolor);
  LCD_Printf10("RATE");
	LCD_SetTextSize(1);
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




}



