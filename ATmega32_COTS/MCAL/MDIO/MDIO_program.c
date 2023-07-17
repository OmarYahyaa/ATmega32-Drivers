/*
 * MDIO_program.c
 *
 *  Created on: Jul 15, 2023
 *      Author: OMAR YAHYA
 */

#include <STD_TYPES.h>
#include <BIT_MATH.h>
#include <ERROR_STATES.h>
#include <MDIO_register.h>
#include <MDIO_private.h>
#include <MDIO_config.h>
#include <MDIO_interface.h>

ErrorState_t MDIO_enSetPinDirection(Pin_t copy_enPin,
		Direction_t copy_enDirection) {
	ErrorState_t Local_enState = SUCCESS;
	u8 Local_u8Port = copy_enPin / 10;
	u8 Local_u8Pin  = copy_enPin % 10;
	switch (Local_u8Port) {
	case PA: // PORTA
		if (OUTPUT == copy_enDirection) {
			SET_BIT(DDRA, Local_u8Pin);
		} else if (INPUT == copy_enDirection) {
			CLR_BIT(DDRA, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	case PB: // PORTB
		if (OUTPUT == copy_enDirection) {
			SET_BIT(DDRB, Local_u8Pin);
		} else if (INPUT == copy_enDirection) {
			CLR_BIT(DDRB, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	case PC: // PORTC
		if (OUTPUT == copy_enDirection) {
			SET_BIT(DDRC, Local_u8Pin);
		} else if (INPUT == copy_enDirection) {
			CLR_BIT(DDRC, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	case PD: // PORTD
		if (OUTPUT == copy_enDirection) {
			SET_BIT(DDRD, Local_u8Pin);
		} else if (INPUT == copy_enDirection) {
			CLR_BIT(DDRD, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	default:
		Local_enState = OUT_OF_RANGE_ERR;
		break;
	} // switch
	return Local_enState;
}

ErrorState_t MDIO_enSetPortDirection(Port_t copy_enPort, u8 copy_u8Value) {
	ErrorState_t Local_enState = SUCCESS;
	if ((0 > copy_u8Value) || (255 < copy_u8Value)) {
		Local_enState = OUT_OF_RANGE_ERR;
	} else {
		switch (copy_enPort) {
		case PA: // PORTA
			DDRA = copy_u8Value;
			break;
		case PB: // PORTB
			DDRB = copy_u8Value;
			break;
		case PC: // PORTC
			DDRC = copy_u8Value;
			break;
		case PD: // PORTD
			DDRD = copy_u8Value;
			break;
		default:
			Local_enState = OUT_OF_RANGE_ERR;
			break;
		} // switch
	} // else
	return Local_enState;
}

ErrorState_t MDIO_enSetPinValue(Pin_t copy_enPin, Value_t copy_enValue) {
	ErrorState_t Local_enState = SUCCESS;
	u8 Local_u8Port = copy_enPin / 10;
	u8 Local_u8Pin  = copy_enPin % 10;
	switch (Local_u8Port) {
	case PA: // PORTA
		if (HIGH == copy_enValue) {
			SET_BIT(PORTA, Local_u8Pin);
		} else if (LOW == copy_enValue) {
			CLR_BIT(PORTA, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	case PB: // PORTB
		if (HIGH == copy_enValue) {
			SET_BIT(PORTB, Local_u8Pin);
		} else if (LOW == copy_enValue) {
			CLR_BIT(PORTB, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	case PC: // PORTC
		if (HIGH == copy_enValue) {
			SET_BIT(PORTC, Local_u8Pin);
		} else if (LOW == copy_enValue) {
			CLR_BIT(PORTC, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	case PD: // PORTD
		if (HIGH == copy_enValue) {
			SET_BIT(PORTD, Local_u8Pin);
		} else if (LOW == copy_enValue) {
			CLR_BIT(PORTD, Local_u8Pin);
		} else {
			Local_enState = OUT_OF_RANGE_ERR;
		}
		break;
	default:
		Local_enState = OUT_OF_RANGE_ERR;
		break;
	} // switch
	return Local_enState;
}

ErrorState_t MDIO_enSetPortValue(Port_t copy_enPort, u8 copy_u8Value) {
	ErrorState_t Local_enState = SUCCESS;
	if ((0 > copy_u8Value) || (255 < copy_u8Value)) {
		Local_enState = OUT_OF_RANGE_ERR;
	} else {
		switch (copy_enPort) {
		case PA: // PORTA
			PORTA = copy_u8Value;
			break;
		case PB: // PORTB
			PORTB = copy_u8Value;
			break;
		case PC: // PORTC
			PORTC = copy_u8Value;
			break;
		case PD: // PORTD
			PORTD = copy_u8Value;
			break;
		default:
			Local_enState = OUT_OF_RANGE_ERR;
			break;
		} // switch
	} // else
	return Local_enState;
}

ErrorState_t MDIO_enGetPinValue(Pin_t copy_enPin, Value_t *ptrPinValue) {
	ErrorState_t Local_enState = SUCCESS;
	u8 Local_u8Port = copy_enPin / 10;
	u8 Local_u8Pin  = copy_enPin % 10;
	if (NULL != ptrPinValue) {
		switch (Local_u8Port) {
		case PA: // PORTA
			*ptrPinValue = GET_BIT(PINA, Local_u8Pin);
			break;
		case PB: // PORTB
			*ptrPinValue = GET_BIT(PINB, Local_u8Pin);
			break;
		case PC: // PORTC
			*ptrPinValue = GET_BIT(PINC, Local_u8Pin);
			break;
		case PD: // PORTD
			*ptrPinValue = GET_BIT(PIND, Local_u8Pin);
			break;
		default:
			Local_enState = OUT_OF_RANGE_ERR;
			break;
		} // switch
	} // if
	else {
		Local_enState = NULL_POINTER_ERR;
	}
	return Local_enState;
}

ErrorState_t MDIO_enGetPortValue(Port_t copy_enPort, u8 *ptrPortValue) {
	ErrorState_t Local_enState = SUCCESS;
	if (NULL != ptrPortValue) {
		switch (copy_enPort) {
		case PA: // PORTA
			*ptrPortValue = PINA;
			break;
		case PB: // PORTB
			*ptrPortValue = PINB;
			break;
		case PC: // PORTC
			*ptrPortValue = PINC;
			break;
		case PD: // PORTD
			*ptrPortValue = PIND;
			break;
		default:
			Local_enState = OUT_OF_RANGE_ERR;
			break;
		} // switch
	} // if
	else {
		Local_enState = NULL_POINTER_ERR;
	}
	return Local_enState;
}

ErrorState_t MDIO_enTogglePinValue(Pin_t copy_enPin) {
	ErrorState_t Local_enState = SUCCESS;
	u8 Local_u8Port = copy_enPin / 10;
	u8 Local_u8Pin  = copy_enPin % 10;
	switch (Local_u8Port) {
	case PA: // PORTA
		TOGG_BIT(PORTA, Local_u8Pin);
		break;
	case PB: // PORTB
		TOGG_BIT(PORTB, Local_u8Pin);
		break;
	case PC: // PORTC
		TOGG_BIT(PORTC, Local_u8Pin);
		break;
	case PD: // PORTD
		TOGG_BIT(PORTD, Local_u8Pin);
		break;
	default:
		Local_enState = OUT_OF_RANGE_ERR;
		break;
	} // switch
	return Local_enState;
}

ErrorState_t MDIO_enTogglePortValue(Port_t copy_enPort)
{
	ErrorState_t Local_enState = SUCCESS;
	switch (copy_enPort) {
	case PA: // PORTA
		TOGG_REG(PORTA);
		break;
	case PB: // PORTB
		TOGG_REG(PORTB);
		break;
	case PC: // PORTC
		TOGG_REG(PORTC);
		break;
	case PD: // PORTD
		TOGG_REG(PORTD);
		break;
	default:
		Local_enState = OUT_OF_RANGE_ERR;
		break;
	} // switch
	return Local_enState;
}


