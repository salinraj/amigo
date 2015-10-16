/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYRINGEPUMP_H
#define __SYRINGEPUMP_H





#include "stm32f1xx_LCD.h"
#include "Switches.h"
#include "stm32f1xx_PWM.h"
#include "Syringe_Size.h"



void PumpRate(void);
void PrintDecimal(uint16_t value,uint8_t Size);
void PrintRate(uint16_t value);
void Print_Syringe_Size(uint16_t value);
void Motor_Speed(uint16_t Rate,uint16_t Size);
void Alarm_Syringe_Misplacement(void);
void Initial_Screen(void);
void Running_Screen(void);
void Finishing_Screen(void);
void Syringe_Image(void);
void Lock_Image(void);
void Alarm_Piston_Lock(void);
void Piston_Lock_Image(void);
void Print_Injected_Volume(void);

char *ConvertToDecimal(uint16_t value);



#endif /* __STM32F1XX_NUCLEO_H */
