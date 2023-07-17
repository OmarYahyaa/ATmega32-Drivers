/*
 * HSSD_program.c
 *
 *  Created on: Jul 17, 2023
 *      Author: OMAR YAHYA
 */
#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <MDIO_interface.h>
#include <HSSD_private.h>
#include <HSSD_config.h>
#include <HSSD_interface.h>

ErrorState_t HSSD_enInit(SSD_t *PtrSSD) {
	ErrorState_t Local_enState = SUCCESS;
	if (PtrSSD != NULL) {
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_A, OUTPUT);
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_B, OUTPUT);
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_C, OUTPUT);
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_D, OUTPUT);
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_E, OUTPUT);
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_F, OUTPUT);
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_G, OUTPUT);
		MDIO_enSetPinDirection(PtrSSD->SSD_Pin_EN, OUTPUT);
		if (PtrSSD->SSD_Type == CC) {
			// Initial Value for Enable in CC --> High
			MDIO_enSetPinValue(PtrSSD->SSD_Pin_EN, HIGH);
		} else if (PtrSSD->SSD_Type == CA) {
			// Initial Value for Enable in CA --> Low
			MDIO_enSetPinValue(PtrSSD->SSD_Pin_EN, LOW);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
	} else {
		Local_enState = NULL_POINTER_ERR;
	}
	return Local_enState;
}

ErrorState_t HSSD_enEnable(SSD_t *PtrSSD) {
	ErrorState_t Local_enState = SUCCESS;
	if (PtrSSD != NULL) {
		if (PtrSSD->SSD_Type == CC) {
			MDIO_enSetPinValue(PtrSSD->SSD_Pin_EN, LOW);
		} else if (PtrSSD->SSD_Type == CA) {
			MDIO_enSetPinValue(PtrSSD->SSD_Pin_EN, HIGH);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
	} // if --> PtrSSD != NULL
	else {
		Local_enState = NULL_POINTER_ERR;
	} // else --> PtrSSD == NULL
	return Local_enState;
}

ErrorState_t HSSD_enDisable(SSD_t *PtrSSD) {
	ErrorState_t Local_enState = SUCCESS;
	if (PtrSSD != NULL) {
		if (PtrSSD->SSD_Type == CC) {
			MDIO_enSetPinValue(PtrSSD->SSD_Pin_EN, HIGH);
		} else if (PtrSSD->SSD_Type == CA) {
			MDIO_enSetPinValue(PtrSSD->SSD_Pin_EN, LOW);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
	} // if --> PtrSSD != NULL
	else {
		Local_enState = NULL_POINTER_ERR;
	} // else --> PtrSSD == NULL
	return Local_enState;
}

ErrorState_t HSSD_enDisplayNumber(u8 copy_u8Number, SSD_t *PtrSSD) {
	ErrorState_t Local_enState = SUCCESS;
	if (copy_u8Number < 0 || copy_u8Number > 9) {
		Local_enState = OUT_OF_RANGE_ERR;
	} else {
		if (PtrSSD != NULL) {
			switch (PtrSSD->SSD_Type) {
			case CC:
				switch (copy_u8Number) {
				case 0:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 1:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 2:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 3:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 4:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 5:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 6:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 7:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 8:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 9:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				} // switch --> CC
				break;
			case CA:
				switch (copy_u8Number) {
				case 0:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 1:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 2:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 3:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 4:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 5:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 6:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 7:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, HIGH);
					break;
				case 8:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				case 9:
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_A, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_B, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_C, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_D, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_E, HIGH);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_F, LOW);
					MDIO_enSetPinValue(PtrSSD->SSD_Pin_G, LOW);
					break;
				} // switch --> CA
				break;
			default:
				Local_enState = OUT_OF_RANGE_ERR;
				break;
			} // switch --> SSD Type
		} // if --> PtrSSD != NULL
		else {
			Local_enState = NULL_POINTER_ERR;
		} // else --> PtrSSD == NULL
	}
	return Local_enState;
}
