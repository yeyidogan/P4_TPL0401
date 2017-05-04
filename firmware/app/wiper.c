/******************************************************************************
*	Written by Yilmaz Eyidogan
*	TPL0401 functions
*	Created date: 2017.05.03
*******************************************************************************/
#include "tpl0401.h"

/* define ------------------------------------------------------------*/
/* macro -------------------------------------------------------------*/
/* typedef -----------------------------------------------------------*/
/* functions ---------------------------------------------------------*/
void tpl0401_write(uint8_t data){
	osStatus_t statusT;
	
	statusT = osMutexAcquire(mutex_i2c, 1000); //wait for 1 second
	if (statusT == osOK){
		i2c_tx_buf[0] = TPL0401_REGISTER_ADDRESS;
		i2c_master_send_start_stop = I2C_MASTER_SEND_START;
		i2c_msg_tx_s.length_wr = sizeof(ST_TPL0401_WRITE_REGISTER);
		i2c_msg_tx_s.chip_add = TPL0401_CHIP_ADDRESS;
		i2c_master_process(I2C_MASTER_WRITE);
		//START_HDC1080_TIMER;
		//while (i2c_status_s.byte == 0x00){
		//	if (CHECK_HDC1080_TIMER_REACH_TO(HDC1080_COMM_TIMEOUT)){
		//		stHDC1080Status.ok = false;
		//		break;
		//	}
		//}
		//if (i2c_status_s.bits.completed_flag == false){
		//		stHDC1080Status.ok = false;
		//}
	}
	//else{
	//	stHDC1080Status.ok = false;
	//}
	osMutexRelease(mutex_i2c);
}
/* variables ---------------------------------------------------------*/

/* * * END OF FILE * * */
