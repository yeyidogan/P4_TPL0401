/******************************************************************************
*	Written by Yilmaz Eyidogan
*	main application functions
*	Created date: 2017.05.04
*******************************************************************************/
#include "main_task.h"

/* define ------------------------------------------------------------*/
#define WIPER_MIN_VAL 0x32
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
		osDelay(100);
		++wiper_value;
		if (wiper_value < WIPER_MIN_VAL){
			wiper_value = WIPER_MIN_VAL;
		}
		tpl0401_write(wiper_value);
	}
}

/* * * END OF FILE * * */
