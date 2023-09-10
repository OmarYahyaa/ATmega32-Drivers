/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 Push Button	***********************/
/*****************		File:	 Program        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <MDIO_interface.h>
#include <HPB_private.h>
#include <HPB_config.h>
#include <HPB_interface.h>
#include <avr/delay.h>

ErrorState_t HPB_enInit(PB_t *PtrPB) {
	ErrorState_t Local_enState = SUCCESS;
	if (NULL != PtrPB) {
		MDIO_enSetPinDirection(PtrPB->PB_Pin, INPUT);
		if (PtrPB->PB_Connection == PULL_UP) {
			MDIO_enSetPinValue(PtrPB->PB_Pin, HIGH); // Activation for Internal Pull-Up
		}
	} else {
		Local_enState = NULL_POINTER;
	}
	return Local_enState;
}

ErrorState_t HPB_enGetState(PB_t *PtrPB, PB_STATE_t *PtrState) {
	ErrorState_t Local_enState = SUCCESS;
	if ((NULL != PtrPB) && (NULL != PtrState)) {
		u8 Local_u8PBState;
		MDIO_enGetPinValue(PtrPB->PB_Pin, &Local_u8PBState);
		switch (PtrPB->PB_Connection) {
		case PULL_UP:
			if (0 == Local_u8PBState) {
				*PtrState = PRESSED;
				if (PtrPB->PB_Type == TEMP_PB) {
					_delay_ms(200); // De-Bouncing
				}
			} else {
				*PtrState = NOT_PRESSED;
			}
			break;
		case PULL_DOWN:
			if (1 == Local_u8PBState) {
				*PtrState = PRESSED;
				if (PtrPB->PB_Type == TEMP_PB) {
					_delay_ms(200); // De-Bouncing
				}
			} else {
				*PtrState = NOT_PRESSED;
			}
			break;
		default:
			Local_enState = OUT_OF_RANGE;
			break;
		}
	} else {
		Local_enState = NULL_POINTER;
	}
	return Local_enState;
}
