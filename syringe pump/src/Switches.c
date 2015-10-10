
#include "Switches.h"



/**
  * @brief  Initializes the LCD
  * @retval None
  */
void Button_Init(void)
{
		GPIO_InitTypeDef gpioinitstruct = {0};

		/* Enable the BUTTON Clock */
		START_BUTTON_GPIO_CLK_ENABLE();
/* Configure Button pin as input */


    gpioinitstruct.Pin    = START_BUTTON ;
    gpioinitstruct.Mode   = GPIO_MODE_INPUT;
    gpioinitstruct.Pull   = GPIO_NOPULL;
    gpioinitstruct.Speed  = GPIO_SPEED_MEDIUM;

    HAL_GPIO_Init(START_BUTTON_PORT, &gpioinitstruct);
  
gpioinitstruct.Pin    = STOP_BUTTON ;
HAL_GPIO_Init(START_BUTTON_PORT, &gpioinitstruct);
gpioinitstruct.Pin    = OK_BUTTON ;
HAL_GPIO_Init(START_BUTTON_PORT, &gpioinitstruct);
gpioinitstruct.Pin    = UP_BUTTON ;
HAL_GPIO_Init(START_BUTTON_PORT, &gpioinitstruct);
gpioinitstruct.Pin    = DOWN_BUTTON ;
HAL_GPIO_Init(START_BUTTON_PORT, &gpioinitstruct);

 
 }

/**
  * @brief  Reads the specified input port pin.
  * @param  START_BUTTON_PORT: where x can be (A..G depending on device used) to select the GPIO peripheral
  * @param  Button: specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  * @retval The input port pin value.
*/

uint32_t Button_GetState(uint16_t Button)
{
  return HAL_GPIO_ReadPin(START_BUTTON_PORT, Button);
}

uint32_t Read_START_Button(void)
{

return Button_GetState(START_BUTTON);
	
}
uint32_t Read_STOP_Button(void)
{

return Button_GetState(STOP_BUTTON);
	
}

uint32_t Read_OK_Button(void)
{

return Button_GetState(OK_BUTTON);
	
}

uint32_t Read_UP_Button(void)
{

return Button_GetState(UP_BUTTON);
	
}


uint32_t Read_DOWN_Button(void)
{

return Button_GetState(DOWN_BUTTON);
	
}





void IR_SENSOR_Init(void)
{
		GPIO_InitTypeDef gpioinitstruct = {0};

		/* Enable the BUTTON Clock */
		IR_SENSOR_GPIO_CLK_ENABLE();
/* Configure Button pin as input */


    gpioinitstruct.Pin    =  PISTON_SENSOR;
    gpioinitstruct.Mode   = GPIO_MODE_INPUT;
    gpioinitstruct.Pull   = GPIO_PULLUP ;
    gpioinitstruct.Speed  = GPIO_SPEED_MEDIUM;

    HAL_GPIO_Init(IR_SENSOR_PORT, &gpioinitstruct);
  
gpioinitstruct.Pin    = STOP_SENSOR	 ;
HAL_GPIO_Init(IR_SENSOR_PORT, &gpioinitstruct);

 }

uint32_t Read_PISTON_SENSOR(void)
{
return IR_SENSOR_GetState(PISTON_SENSOR);
}


uint32_t Read_STOP_SENSOR(void)
{
return IR_SENSOR_GetState(STOP_SENSOR);
}


uint32_t IR_SENSOR_GetState(uint16_t Button)
{
  return HAL_GPIO_ReadPin(IR_SENSOR_PORT, Button);
}









