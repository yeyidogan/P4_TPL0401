/******************************************************************************
*	Written by Yilmaz Eyidogan
*	Timer functions
*	Created date: 2016.12.10
*******************************************************************************/
#include "timer.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/**
  * @brief timer14 interrupt
  * @param  None
  * @retval None
  */
void TIM6_IRQHandler(void){
	/* Clear the IT pending Bit */
	TIM6->SR = (uint16_t)~0x0001;
	
	if (uiTimerI2C < 20000){ //max 20 seconds
		++uiTimerI2C;
	}
	if (uiTimerUart1 < 20000){ //max 20 seconds
		++uiTimerUart1;
	}
}
/**
  * @brief init timers
  * @param  None
  * @retval None
  */
void initTimers(void){
	//     TIMER 6              //
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN; //Enable Timer6 clock
	
	/* Enable Timer 6 reset state */
	RCC->APB1RSTR |= RCC_APB1ENR_TIM6EN;
	/* Release Timer 6 from reset state */
	RCC->APB1RSTR &= ~RCC_APB1ENR_TIM6EN;
	
	TIM6->CR1 = (uint16_t)0x0084;
	//bit15-8:0 reserved
	//bit7:1 ARPE auto reload preload enabled
	//bit6-4:0 Reserved
	//bit3:0 One pulse mode disabled
	//bit2:1 Update request source is only overflow/underflow or DMA
	//bit1:0 UEV update event is generated
	//bit0:0 Counter disabled

	/* Enable the Interrupt sources */
	TIM6->DIER = (uint16_t)0x0001;
	//TIM6->EGR = (uint16_t)0x0001;
	TIM6->PSC = (uint16_t)1199; //0.1 milisecond CNT counter
	TIM6->ARR = (uint16_t)39;  //1 milisecond timer
	
	TIM6->CR1 |= (uint16_t)0x0001; //counter enabled
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	NVIC_SetPriority(TIM6_DAC_IRQn, 0);
}

/* * * END OF FILE * * */
