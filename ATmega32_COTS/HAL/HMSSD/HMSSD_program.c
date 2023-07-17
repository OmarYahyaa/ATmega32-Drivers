/*
 * HMSSD_program.c
 *
 *  Created on: Jul 17, 2023
 *      Author: OMAR YAHYA
 */

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <avr/delay.h>
#include <MDIO_interface.h>
#include <HMSSD_private.h>
#include <HMSSD_config.h>
#include <HMSSD_interface.h>

ErrorState_t HMSSD_enInit(MSSD_t *PtrMSSD) {
	ErrorState_t Local_enState = SUCCESS;
	if (PtrMSSD != NULL) {
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_A, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_B, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_C, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_D, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_E, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_F, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_G, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_DP, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_EN1, OUTPUT);
		MDIO_enSetPinDirection(PtrMSSD->MSSD_Pin_EN2, OUTPUT);
		if (PtrMSSD->MSSD_Type == C_CATHODE) {
			// Initial Value for Enable in CC --> High
			MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, HIGH);
			MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, HIGH);
			MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_DP, LOW);
		} else if (PtrMSSD->MSSD_Type == C_ANODE) {
			// Initial Value for Enable in CA --> Low
			MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, LOW);
			MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, LOW);
			MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_DP, HIGH);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
	} else {
		Local_enState = NULL_POINTER_ERR;
	}
	return Local_enState;
}

ErrorState_t HMSSD_enDisplayIntegerNumber(u8 copy_u8Number, MSSD_t *PtrMSSD) {
	ErrorState_t Local_enState = SUCCESS;
	if (copy_u8Number < 0 || copy_u8Number > 99) {
		Local_enState = OUT_OF_RANGE_ERR;
	} else {
		if (PtrMSSD != NULL) {
			u8 Local_u8Tens = copy_u8Number / 10;
			u8 Local_u8Units = copy_u8Number % 10;
			u16 i;
			if (PtrMSSD->MSSD_Type == C_CATHODE) {
				for (i = 0; i < PtrMSSD->MSSD_Duration; i++) {
					// Enable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, LOW);
					switch (Local_u8Tens) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					} // switch on Tens --> CC

					_delay_ms(10);
					// Disable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, HIGH);
					// Enable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, LOW);

					switch (Local_u8Units) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					} // switch on Units --> CC

					_delay_ms(10);
					// Disable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, HIGH);

				} // for
			} // Type = CC
			else if (PtrMSSD->MSSD_Type == C_ANODE) {
				for (i = 0; i < PtrMSSD->MSSD_Duration; i++) {
					// Enable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, HIGH);
					switch (Local_u8Tens) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					} // switch on Tens --> CA

					_delay_ms(10);
					// Disable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, LOW);
					// Enable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, HIGH);

					switch (Local_u8Units) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					} // switch on Units --> CA

					_delay_ms(10);
					// Disable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, LOW);

				} // for
			} // Type CA
			else {
				Local_enState = OUT_OF_RANGE_ERR;
			}
		} // if --> PtrSSD != NULL
		else {
			Local_enState = NULL_POINTER_ERR;
		} // else --> PtrSSD == NULL
	} // else --> Valid Number
	return Local_enState;
}

ErrorState_t HMSSD_enDisplayRealNumber(f32 copy_u8Number, MSSD_t *PtrMSSD) {
	ErrorState_t Local_enState = SUCCESS;
	if (copy_u8Number < 0 || copy_u8Number > 99) {
		Local_enState = OUT_OF_RANGE_ERR;
	} else {
		if (PtrMSSD != NULL) {
			u8 Local_u8Tens = (copy_u8Number * 10) / 10;
			u8 Local_u8Units = ((u8) (copy_u8Number * 10)) % 10;
			u16 i;
			if (PtrMSSD->MSSD_Type == C_CATHODE) {
				for (i = 0; i < PtrMSSD->MSSD_Duration; i++) {
					// Enable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, LOW);
					// Enable DP
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_DP, HIGH);
					switch (Local_u8Tens) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					} // switch on Tens --> CC

					_delay_ms(10);
					// Disable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, HIGH);
					// Disable DP
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_DP, LOW);
					// Enable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, LOW);

					switch (Local_u8Units) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					} // switch on Units --> CC

					_delay_ms(10);
					// Disable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, HIGH);

				} // for
			} // Type = CC
			else if (PtrMSSD->MSSD_Type == C_ANODE) {
				for (i = 0; i < PtrMSSD->MSSD_Duration; i++) {
					// Enable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, HIGH);
					// Enable DP
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_DP, LOW);
					switch (Local_u8Tens) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					} // switch on Tens --> CA

					_delay_ms(10);
					// Disable SSD1
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN1, LOW);
					// Disable DP
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_DP, HIGH);
					// Enable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, HIGH);

					switch (Local_u8Units) {
					case 0:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 1:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 2:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 3:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 4:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 5:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 6:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 7:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, HIGH);
						break;
					case 8:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					case 9:
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_A, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_B, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_C, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_D, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_E, HIGH);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_F, LOW);
						MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_G, LOW);
						break;
					} // switch on Units --> CA

					_delay_ms(10);
					// Disable SSD2
					MDIO_enSetPinValue(PtrMSSD->MSSD_Pin_EN2, LOW);

				} // for
			} // Type CA
			else {
				Local_enState = OUT_OF_RANGE_ERR;
			}
		} // if --> PtrSSD != NULL
		else {
			Local_enState = NULL_POINTER_ERR;
		} // else --> PtrSSD == NULL
	} // else --> Valid Number
	return Local_enState;
}
