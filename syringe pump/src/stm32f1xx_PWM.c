


#include "stm32f1xx_PWM.h"

extern uint16_t PumpingRate;

void TIM4_Init (void)

{
	GPIO_InitTypeDef  gpioinitstruct = {0};
	
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;             /* enable clock for TIM4    */
	
	
	gpioinitstruct.Pin    = GPIO_PIN_7;
  gpioinitstruct.Mode   = GPIO_MODE_AF_PP;
  gpioinitstruct.Speed  = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioinitstruct);
	
	
	

	
}


void PWM_ON(void)
{
TIM4->CR1  |= TIM_CR1_CEN;                      /* timer enable             */
}

void PWM_OFF(void)
{
TIM4->CR1  &= ~TIM_CR1_CEN;                      /* timer enable             */
}


void PWM_Freq(uint16_t rate)
{
		
	
		TIM4->PSC   = ( 720 - 1);                      /* set prescaler   = 10 KHz */
		TIM4->ARR   = (350 - rate);                      /* set auto-reload =  1 s   */          

	
	
		TIM4->CCR2  = 35;                             /* Duty cicle channel 3     */
		
		TIM4->CCMR1 = (6 <<  12);// |                      /* PWM mode 1 channel 2     */
                 
		TIM4->CCER  = (1 <<  4);// |                      /* CCE channel 3            */
                

		


}
