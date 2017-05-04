/******************************************************************************
*	Written by Yilmaz Eyidogan
*	main application functions
*	Created date: 2017.05.04
*******************************************************************************/
#ifndef _MAIN_TASK_H_
#define _MAIN_TASK_H_

#include "cmsis_os2.h"
#include <stdbool.h>
#include <stdint.h>
#include "main.h"
#include "uart.h"
#include "tpl0401.h"

/* define ------------------------------------------------------------*/
/* macro -------------------------------------------------------------*/
/* typedef -----------------------------------------------------------*/
/* variables ---------------------------------------------------------*/
/* functions ---------------------------------------------------------*/
extern __NO_RETURN void task_main(void *argument);

#endif
/* * * END OF FILE * * */
