/******************************************************************************
*	Written by Yilmaz Eyidogan
*	TPL0401 functions
*	Created date: 2017.05.03
*******************************************************************************/
#ifndef _WIPER_H_
#define _WIPER_H_

#include <stm32f0xx.h>
#include "i2c.h"
#include "uart.h"
#include <stdbool.h>

/* define ------------------------------------------------------------*/
#define TPL0401_CHIP_ADDRESS 0x5C
#define MAX5395_CHIP_ADDRESS 0x50
#define WIPER_CHIP_ADDRESS TPL0401_CHIP_ADDRESS
#define WIPER_REGISTER_ADDRESS 0x00
/* macro -------------------------------------------------------------*/
/* typedef -----------------------------------------------------------*/
typedef struct{
	uint8_t addr;
	uint8_t data;
}ST_WIPER_WRITE_REGISTER;
/* functions ---------------------------------------------------------*/
extern void wiper_write(uint8_t data);
/* variables ---------------------------------------------------------*/

#endif
/* * * END OF FILE * * */
