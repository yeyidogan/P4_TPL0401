/******************************************************************************
*	Written by Yilmaz Eyidogan
*	main application functions
*	Created date: 2017.05.04
*******************************************************************************/
#include "main_task.h"

/* define ------------------------------------------------------------*/
#define WIPER_MIN_VAL 0x20
#define WIPER_MAX_VAL 0x7F
/* macro -------------------------------------------------------------*/
/* typedef -----------------------------------------------------------*/
/* variables ---------------------------------------------------------*/
uint8_t wiper_value = WIPER_MIN_VAL;
/* functions ---------------------------------------------------------*/

/**
*******************************************************************************
* @brief main task that controls the device
* @param[in] 
* @param[out] 
*******************************************************************************
*/
__NO_RETURN void task_main(void *argument){
	
	while (1){
		osDelay(1000);
		if (wiper_value < WIPER_MIN_VAL){
			wiper_value = WIPER_MAX_VAL;
		}
		if (wiper_value > WIPER_MAX_VAL){
			wiper_value = WIPER_MIN_VAL;
		}
		wiper_write(wiper_value);
		if (wiper_value == WIPER_MIN_VAL){
			osDelay(5000);
		}
		if (wiper_value == WIPER_MAX_VAL){
			osDelay(5000);
		}
		//--wiper_value;
	}
}

/* * * END OF FILE * * */
