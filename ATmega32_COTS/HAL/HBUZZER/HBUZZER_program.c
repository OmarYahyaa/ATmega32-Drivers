/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 Buzzer	        ***********************/
/*****************		File:	 Program        ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <MDIO_interface.h>
#include <HBUZZER_private.h>
#include <HBUZZER_config.h>
#include <HBUZZER_interface.h>
#include <avr/delay.h>

ErrorState_t HBUZZER_enInit(Pin_t copy_enPin) {
	MDIO_enSetPinDirection(copy_enPin, OUTPUT);
	return SUCCESS;
}
ErrorState_t HBUZZER_enBuzzON(Pin_t copy_enPin) {
	MDIO_enSetPinValue(copy_enPin, HIGH);
	return SUCCESS;
}
ErrorState_t HBUZZER_enBuzzOFF(Pin_t copy_enPin) {
	MDIO_enSetPinValue(copy_enPin, LOW);
	return SUCCESS;
}

ErrorState_t HBUZZER_enBuzzMusic(Pin_t copy_enPin, Delay_Unit_t copy_enDelayUnit, u32 copy_u32DelayVal, u32 copy_u32Duration) {
	ErrorState_t Local_enState = SUCCESS;
	u8 Local_u8Counter;
	if (copy_enDelayUnit == MS) {
		for (Local_u8Counter = 0; Local_u8Counter < copy_u32Duration;
				Local_u8Counter++) {
			HBUZZER_enBuzzON(copy_enPin);
			_delay_ms(copy_u32DelayVal);
			HBUZZER_enBuzzOFF(copy_enPin);
			_delay_ms(copy_u32DelayVal);
		}
	} else if (copy_enDelayUnit == US) {
		for (Local_u8Counter = 0; Local_u8Counter < copy_u32Duration;
				Local_u8Counter++) {
			HBUZZER_enBuzzON(copy_enPin);
			_delay_us(copy_u32DelayVal);
			HBUZZER_enBuzzOFF(copy_enPin);
			_delay_us(copy_u32DelayVal);
		}
	} else {
		Local_enState = OUT_OF_RANGE;
	}
	return Local_enState;
}
