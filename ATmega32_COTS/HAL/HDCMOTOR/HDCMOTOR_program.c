/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 DC Motor	    ***********************/
/*****************		File:	 Program        ***********************/
/**********************************************************************/
/**********************************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "MDIO_interface.h"
#include "HDCMOTOR_private.h"
#include "HDCMOTOR_config.h"
#include "HDCMOTOR_interface.h"

ErrorState_t HDCMOTOR_enInit(DCMotor_t *ptrMotor) {
	ErrorState_t Local_enState = SUCCESS;
	if (NULL == ptrMotor) {
		Local_enState = NULL_POINTER;
	} else {
		MDIO_enSetPinDirection(ptrMotor->Motor_Pin1, OUTPUT);
		MDIO_enSetPinDirection(ptrMotor->Motor_Pin2, OUTPUT);
	}
	return Local_enState;
}

ErrorState_t HDCMOTOR_enMotorON(DCMotor_t *ptrMotor, DCMotorDirection_t copy_enDirection) {
	ErrorState_t Local_enState = SUCCESS;
	if (NULL == ptrMotor) {
		Local_enState = NULL_POINTER;
	} else {
		switch (copy_enDirection) {
		case CLK_WISE:
			MDIO_enSetPinValue(ptrMotor->Motor_Pin1, LOW);
			MDIO_enSetPinValue(ptrMotor->Motor_Pin2, HIGH);
			break;
		case ANTI_CLK_WISE:
			MDIO_enSetPinValue(ptrMotor->Motor_Pin2, LOW);
			MDIO_enSetPinValue(ptrMotor->Motor_Pin1, HIGH);
			break;
		default:
			Local_enState = OUT_OF_RANGE;
			break;
		}
	}
	return Local_enState;
}

ErrorState_t HDCMOTOR_enMotorOFF(DCMotor_t *ptrMotor) {
	ErrorState_t Local_enState = SUCCESS;
	if (NULL == ptrMotor) {
		Local_enState = NULL_POINTER;
	} else {
		MDIO_enSetPinValue(ptrMotor->Motor_Pin1, LOW);
		MDIO_enSetPinValue(ptrMotor->Motor_Pin2, LOW);
	}
	return Local_enState;
}
