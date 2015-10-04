/*Name : Syringepump.c
created on : 17-08-2015

file includes functions for display of syringpump and motor control for syringe pump

*/

#include "syringepump.h"

uint16_t PumpingRate = 200;
void PumpRate(void)
{
	
	LCD_SetTextSize(4);
	
	LCD_SetTextColor(BLACK,WHITE);
	while(1)
	{
	if(!Read_UP_Button())
	{
		while(!Read_UP_Button);
		PumpingRate += 10;
		if(PumpingRate>300)
		PumpingRate=300;
		PWM_Freq(PumpingRate);
		
		
	Print_Text_On(Line4,Position4);
  //LCD_Printf("UP");
	//PrintDecimal(PumpingRate);
PrintRate(PumpingRate);
	}
	else if(!Read_DOWN_Button())
	{
		while(!Read_DOWN_Button());
		PumpingRate -= 10;
		if(PumpingRate<10)
		PumpingRate=10;
		PWM_Freq(PumpingRate);
		
		
			Print_Text_On(Line4,Position4);
  //LCD_Printf("DN");
	//PrintDecimal(PumpingRate);
		
		PrintRate(PumpingRate);

	}
	
	else if(!Read_OK_Button())
	{	
		while(!Read_OK_Button());
		
			LCD_SetCursor(2,Line7);
	LCD_SetTextSize(2);
	LCD_SetTextColor(BLUE,WHITE);
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
	
	Print_Text_On(Line4,Position14);
	LCD_SetTextColor(BLACK,WHITE);	
  PrintDecimal(value,36);

}


/*Print the size of the syringe*/
void Print_Syringe_Size(uint16_t value)
{
	LCD_SetTextColor(BLUE,WHITE);
	Print_Text_On(Line1,Position26);	
  PrintDecimal(value,20);
	
}



