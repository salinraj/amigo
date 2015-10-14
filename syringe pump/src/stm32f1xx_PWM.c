


#include "stm32f1xx_PWM.h"

extern uint16_t PumpingRate;
extern uint16_t Injected_Volume;


/* TIM handle declaration */
TIM_HandleTypeDef    TimHandle;

/* Prescaler declaration */
uint32_t uwPrescalerValue = 0;



void TIM4_Init (void)

{
	GPIO_InitTypeDef  gpioinitstruct = {0};
	
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;             /* enable clock for TIM4    */
	
	
	gpioinitstruct.Pin    = GPIO_PIN_7;
  gpioinitstruct.Mode   = GPIO_MODE_AF_PP;
//gpioinitstruct.Mode   = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Speed  = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioinitstruct);
	
	
	

	
}


void PWM_ON(void)
{
TIM4->CR1  |= TIM_CR1_CEN;                      /* timer enable             */
}

void PWM_OFF(void)
{
TIM4->CR1  &= ~TIM_CR1_CEN;                      /* timer disable             */
}


void PWM_Freq(uint16_t rate)
{
	
	
	/*
	timer input clock is internel clock= 64mhz
	
	
	
	
	*/
		
	
		TIM4->PSC   = ( 640 - 1);                      /* set prescaler   = 100 KHz */
		TIM4->ARR   = (3000 - rate);                      /* set auto-reload =  1 s   */          

	
	
		TIM4->CCR2  = ((1500 - rate)/2);                             /* Duty cicle channel 3     */
//			TIM4->CCR2  = 0x65;                             /* Duty cicle channel 3     */
	
		TIM4->CCMR1 = (6 <<  12);// |                      /* PWM mode 1 channel 2     */
                 
		TIM4->CCER  = (1 <<  4);// |                      /* CCE channel 3            */
                

		
}

void TIM3_init(void)
{

  
  /* Compute the prescaler value to have TIMx counter clock equal to 10000 Hz */
  uwPrescalerValue = (uint32_t)(SystemCoreClock / 10000) - 1;

  /* Set TIMx instance */
  TimHandle.Instance = TIMx;

  /* Initialize TIMx peripheral as follows:
       + Period = 10000 - 1
       + Prescaler = (SystemCoreClock/10000) - 1
       + ClockDivision = 0
       + Counter direction = Up
  */
  TimHandle.Init.Period            = 10000 - 1;
  TimHandle.Init.Prescaler         = uwPrescalerValue;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;

	
	  if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-2- Start the TIM Base generation in interrupt mode ####################*/
  /* Start Channel1 */
  if (HAL_TIM_Base_Start_IT(&TimHandle) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }


}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  Injected_Volume ++;
	if(Injected_Volume>=1000) Injected_Volume=0;

}


	static void Error_Handler(void)

{
  /* User may add here some code to deal with a potential error */
  
  /* In case of error, LED2 is toggling at a frequency of 1Hz */
 // while(1)
  {
    /* Toggle LED2 */
//    BSP_LED_Toggle(LED2);
    HAL_Delay(500);
  }
}




