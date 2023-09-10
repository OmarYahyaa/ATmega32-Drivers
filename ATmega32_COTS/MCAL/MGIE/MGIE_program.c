/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 GIE			***********************/
/*****************		File:	 Program        ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <BIT_MATH.h>
#include <MGIE_register.h>
#include <MGIE_private.h>
#include <MGIE_config.h>
#include <MGIE_Interface.h>

ErrorState_t MGIE_enEnable(void) {
	SET_BIT(REG_SREG, SREG_I);
	//asm("SEI"); // Assembly
	return SUCCESS;
}

ErrorState_t MGIE_enDisable(void) {
	CLR_BIT(REG_SREG, SREG_I);
	//asm("CLI"); // Assembly
	return SUCCESS;
}
