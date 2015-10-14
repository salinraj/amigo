/*Name : Syringepump.c
created on : 17-08-2015

file includes functions for display of syringpump and motor control for syringe pump

*/

#include "syringepump.h"

uint16_t PumpingRate = 200;
uint8_t Current_Screen=0;
void PumpRate(void)
{
	
	//LCD_SetTextSize(4);
	
	LCD_SetTextColor(BLACK,WHITE);
	while(1)
	{
	if(!Read_UP_Button())
	{
		while(!Read_UP_Button());
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
	LCD_SetTextColor(YELLOW,m_textbgcolor);	
  PrintDecimal(value,36);

}


/*Print the size of the syringe*/
void Print_Syringe_Size(uint16_t value)
{
	if(Current_Screen!=1)
	{
		Initial_Screen();
	}
	
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
			if(Current_Screen==0)
			{
				Lock_Image();
			}
			else
			{
			PWM_OFF();
			Display_Clear(LIGHTGRAY);
			Print_Text_On(Line1,Position2);
			LCD_SetTextColor(BLACK,LIGHTGRAY);
			LCD_Printf20("Lock Syringe");
			Syringe_Image();
	
// 			LCD_DrawLine(110,110,140,160,BLACK);
// 			LCD_DrawLine(111,110,141,160,BLACK);
// 			LCD_DrawLine(140,110,110,160,BLACK);	
// 			LCD_DrawLine(141,110,111,160,BLACK);	
	
	//		HAL_Delay(5000);
			Current_Screen=0;
			}


}

///******lcd display when the machine is idle state

void Initial_Screen(void)
{
if(Current_Screen!=1)
{
	Display_Clear(BLACK);	
	LCD_SetTextSize(1);
	LCD_SetTextColor(GRAY,m_textbgcolor);
	Print_Text_On(Line1,Position1);
  LCD_Printf20("ClassB ");
	
	LCD_SetTextColor(GREEN,BLACK);
 
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
	LCD_SetTextColor(GREEN,m_textbgcolor);
  LCD_Printf20("ml/h");
	
	
	LCD_DrawFastHLine(1,200,319,RED);
	LCD_SetCursor(2,Line9);
	LCD_SetTextSize(1);
	LCD_SetTextColor(GRAY,m_textbgcolor);
  LCD_Printf20("Limit");
	Current_Screen=1;
	Print_Syringe_Size(Get_Syringe_Size());
}

}


void Running_Screen(void)
{
	
	if(Current_Screen!= 2 )
	{
// 	Print_Text_On(Line1,Position14);
// 	LCD_SetTextColor(WHITE,m_textbgcolor);
//   LCD_Printf10("RATE");
	Display_Clear(BLACK);	
	LCD_SetTextSize(1);
	Print_Text_On(Line2,Position2);
	LCD_SetTextColor(LCD_Color565(255,10,255),m_textbgcolor);
  LCD_Printf20(" ~~RUNNING~~");	
	Print_Text_On(Line9,Position2);
	LCD_SetTextColor(WHITE,m_textbgcolor);
	LCD_DrawFastHLine(1,188,319,RED);
	LCD_DrawFastHLine(1,189,319,RED);
  LCD_Printf10("RATE");
	LCD_SetTextSize(1);
	//PrintRate(PumpingRate);
	Print_Text_On(195,Position18);
	LCD_SetTextColor(YELLOW,m_textbgcolor);	
  PrintDecimal(PumpingRate,36);
	Print_Text_On(Line9,Position33);
	LCD_SetTextColor(GREEN,m_textbgcolor);
  LCD_Printf20("ml/h");
	Current_Screen=2;	
	}
	
}

void Finishing_Screen(void)
{
	uint8_t i;
		Display_Clear(BLACK);	
	PWM_OFF();
	for(i=0;i<4;i++)
	{
	Print_Text_On(Line2,Position2);
	LCD_SetTextColor(LCD_Color565(52,255,67),m_textbgcolor);
  LCD_Printf20("  INJECTION  ");
	Print_Text_On(Line4,Position2);	
	LCD_Printf20("  FINISHED  ");	
	HAL_Delay(800);
	}

}





void Syringe_Image(void)
{
	uint16_t x=60;
	uint16_t y=100;	
	uint8_t width = 50;
	uint8_t length = 150;
//	uint8_t i;
	
	
	LCD_FillRoundRect(2,50,315,150,20,BLUE);  //main tube
			LCD_FillRect(x-20,y+22,20,6,RED);        //needle
			LCD_FillRoundRect(x,y,length,width,20,RED);  //main tube
//			LCD_FillRect(x+12,y+1,length-10,5,LCD_Color565(79,79,79));
			LCD_FillRect(x+140,y-15,10,80,RED);  //maintube end
			LCD_FillRect(x+150,y+16,35,18,RED);		// piston
			LCD_FillRect(x+185,y-10,15,70,RED);	  //piston end
			
			LCD_DrawFastVLine(x+25,y,25,BLACK);
			LCD_DrawFastVLine(x+35,y,15,BLACK);
			LCD_DrawFastVLine(x+45,y,25,BLACK);
			LCD_DrawFastVLine(x+55,y,15,BLACK);

	
			LCD_DrawFastVLine(x+26,y,25,BLACK);
			LCD_DrawFastVLine(x+36,y,15,BLACK);
			LCD_DrawFastVLine(x+46,y,25,BLACK);
			LCD_DrawFastVLine(x+56,y,15,BLACK);
	
	
}


void Lock_Image(void)
{
	
	uint16_t x=60;
	uint16_t y=100;	
	uint8_t i;
	
	
	LCD_FillRect(x+70,y+15,50,35,RED);
	for(i=0;i<50;i++)
	{
		LCD_DrawFastHLine(x+20+i,y+30+i,50,BLACK);
		if(i>20)
		{
			LCD_DrawFastHLine(x+70+i,y+30+i,25,BLUE);

		}
	
	}
	
	HAL_Delay(200);
	
		for(i=0;i<35;i++)
	{
		if(i<24)	LCD_DrawLine(x+20+i,y+30,x+30+i,y+49,RED);
		else			LCD_DrawLine(x+18+i,y+50,x+32+i,y+77,BLUE);
		

	}
	

	//	LCD_FillRect(x+40,y+50,30,30,BLUE);
	//LCD_FillRect(x+40,y+22,50,35,RED);


	for(i=0;i<50;i++)
	{
	LCD_DrawLine(x+40+i,y+22,x+70+i,y+80,BLACK);
				
	}
// 		for(i=0;i<50;i++)
// 	{
// 		LCD_DrawFastHLine(x+20+i,y+30+i,30,RED);
// 	}
// 	
//	LCD_FillCircle(x+95,y+63,6,YELLOW);
HAL_Delay(200);
	
		LCD_FillRect(x+40,y+22,30,27,RED);
		LCD_FillRect(x+40,y+50,30,30,BLUE);	
	  LCD_FillRect(x+70,y+15,50,85,BLACK);
//	LCD_FillCircle(x+95,y+63,6,YELLOW);	
	
HAL_Delay(1000);	

}

void Piston_Lock_Image(void)
{
	uint16_t x=60;
	uint16_t y=100;	
	
	
// 			LCD_FillRect(x+150,y+16,35,18,RED);		// piston
// 			LCD_FillRect(x+185,y-10,15,70,RED);	  //piston end
// 			HAL_Delay(300);	
			LCD_FillRect(x+150,y+16,35,18,WHITE);		// piston
			LCD_FillRect(x+185,y-10,15,70,WHITE);	  //piston end
			HAL_Delay(300);
			LCD_FillRect(x+150,y+16,35,18,BLACK);		// piston
			LCD_FillRect(x+185,y-10,15,70,BLACK);	  //piston end
			HAL_Delay(300);			

}


void Alarm_Piston_Lock(void)
{
	uint16_t x=60;
	uint16_t y=100;	
	uint8_t width = 50;
	uint8_t length = 150;
//	uint8_t i;
				if(Current_Screen==3)
			{
				Piston_Lock_Image();
			}
			else
			{
			PWM_OFF();
			Display_Clear(LCD_Color565(111,235,249));
			Print_Text_On(Line1,Position2);
			LCD_SetTextColor(BLACK,LCD_Color565(111,235,249));
			LCD_Printf20("Lock Piston!!");

				

	
	
			LCD_FillRoundRect(2,50,315,150,20,LCD_Color565(170,181,136));  //main tube
			LCD_FillRect(x-20,y+22,20,6,RED);        //needle
			LCD_FillRoundRect(x,y,length,width,20,RED);  //main tube
//			LCD_FillRect(x+12,y+1,length-10,5,LCD_Color565(79,79,79));
			LCD_FillRect(x+130,y,10,50,RED);	
			LCD_FillRect(x+140,y-15,10,80,RED);  //maintube end
			LCD_FillRect(x+150,y+16,35,18,RED);		// piston
			LCD_FillRect(x+185,y-10,15,70,RED);	  //piston end
			
			LCD_DrawFastVLine(x+25,y,25,BLACK);
			LCD_DrawFastVLine(x+35,y,15,BLACK);
			LCD_DrawFastVLine(x+45,y,25,BLACK);
			LCD_DrawFastVLine(x+55,y,15,BLACK);
			LCD_DrawFastVLine(x+65,y,25,BLACK);
			LCD_DrawFastVLine(x+75,y,15,BLACK);
			LCD_DrawFastVLine(x+85,y,25,BLACK);
			LCD_DrawFastVLine(x+95,y,15,BLACK);


			LCD_DrawFastVLine(x+26,y,25,BLACK);
			LCD_DrawFastVLine(x+36,y,15,BLACK);
			LCD_DrawFastVLine(x+46,y,25,BLACK);
			LCD_DrawFastVLine(x+56,y,15,BLACK);
			LCD_DrawFastVLine(x+66,y,25,BLACK);
			LCD_DrawFastVLine(x+76,y,15,BLACK);
			LCD_DrawFastVLine(x+86,y,25,BLACK);
			LCD_DrawFastVLine(x+96,y,15,BLACK);
		
				
				
				
				
				
// 			LCD_DrawLine(110,110,140,160,BLACK);
// 			LCD_DrawLine(111,110,141,160,BLACK);
// 			LCD_DrawLine(140,110,110,160,BLACK);	
// 			LCD_DrawLine(141,110,111,160,BLACK);	
	
		
			Current_Screen=3;
			}
	
	
}






