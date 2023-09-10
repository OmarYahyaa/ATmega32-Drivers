/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 PORT			***********************/
/*****************		File:	 Program        ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <MDIO_private.h>
#include <MPORT_register.h>
#include <MPORT_private.h>
#include <MPORT_config.h>
#include <MPORT_interface.h>

ErrorState_t MPORT_enInit(void) {
	REG_DDRA = MPORT_PORTA_DIR;
	REG_DDRB = MPORT_PORTB_DIR;
	REG_DDRC = MPORT_PORTC_DIR;
	REG_DDRD = MPORT_PORTD_DIR;

	REG_PORTA = MPORT_PORTA_INITIAL_VAL;
	REG_PORTB = MPORT_PORTB_INITIAL_VAL;
	REG_PORTC = MPORT_PORTC_INITIAL_VAL;
	REG_PORTD = MPORT_PORTD_INITIAL_VAL;
	return SUCCESS;
}
