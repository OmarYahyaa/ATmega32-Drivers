/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 EXTI			***********************/
/*****************		File:	 Program        ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <BIT_MATH.h>
#include <INTERRUPT.h>
#include <MEXTI_register.h>
#include <MEXTI_private.h>
#include <MEXTI_config.h>
#include <MEXTI_interface.h>
#include <MDIO_interface.h>

static void (*MEXTI_voidISR[3])(void) = {NULL,NULL,NULL };

/******************************** Post-Build *********************************/
ErrorState_t MEXTI_enEnable(InterruptID_t copy_enINT, SenseControl_t copy_enSC) {
	ErrorState_t Local_enState = SUCCESS;
	/** Adjust Sense Control **/
	switch (copy_enINT) {
	case INT0:
		// 1- Apply Mask
		REG_MCUCR &= INT0_SC_MASK;
		// 2- Set Value
		REG_MCUCR |= copy_enSC;
		break;
	case INT1:
		REG_MCUCR &= INT1_SC_MASK;
		REG_MCUCR |= copy_enSC << INT1_SC_SHIFT;
		break;
	case INT2:
		CLR_BIT(REG_MCUCSR, MCUCSR_ISC2);
		REG_MCUCSR |= GET_BIT(copy_enSC,0) << MCUCSR_ISC2;
		break;
	default:
		Local_enState = OUT_OF_RANGE;
		break;
	}
	/** Enable SIE **/
	SET_BIT(REG_GICR, copy_enINT);
	return Local_enState;
}

ErrorState_t MEXTI_enDisable(InterruptID_t copy_enINT) {
	CLR_BIT(REG_GICR, copy_enINT);
	return SUCCESS;
}

ErrorState_t MEXTI_enSetCallBack(InterruptID_t copy_enINT, void (*ptrFn)(void)) {
	ErrorState_t Local_enState = SUCCESS;
	if (ptrFn == NULL) {
		Local_enState = NULL_POINTER;
	} else {
		switch (copy_enINT) {
		case INT0:
			MEXTI_voidISR[0] = ptrFn;
			break;
		case INT1:
			MEXTI_voidISR[1] = ptrFn;
			break;
		case INT2:
			MEXTI_voidISR[2] = ptrFn;
			break;
		default:
			Local_enState = OUT_OF_RANGE;
			break;
		}
	}
	return Local_enState;
}
/******************************** Post-Build *********************************/

/********************************* Pre-Build *********************************/
void MEXTI_voidInt0Enable(void) {
	/** Adjust Sense Control **/
#if(INT0_SC == SC_LOW_LEVEL)
	CLR_BIT(REG_MCUCR, MCUCR_ISC01);
	CLR_BIT(REG_MCUCR, MCUCR_ISC00);
#elif(INT0_SC == SC_ANY_LEVEL)
	CLR_BIT(REG_MCUCR, MCUCR_ISC01);
	SET_BIT(REG_MCUCR, MCUCR_ISC00);
#elif(INT0_SC == SC_FALL_EDGE)
	SET_BIT(REG_MCUCR, MCUCR_ISC01);
	CLR_BIT(REG_MCUCR, MCUCR_ISC00);
#elif(INT0_SC == SC_RISE_EDGE)
	SET_BIT(REG_MCUCR, MCUCR_ISC01);
	SET_BIT(REG_MCUCR, MCUCR_ISC00);
#else
#error("Wrong Sense Control Configuration for INT0")
#endif
	/** Enable SIE **/
	SET_BIT(REG_GICR, GICR_INT0);
}

void MEXTI_voidInt1Enable(void) {
	/** Adjust Sense Control **/
#if(INT1_SC == SC_LOW_LEVEL)
	CLR_BIT(REG_MCUCR, MCUCR_ISC11);
	CLR_BIT(REG_MCUCR, MCUCR_ISC10);
#elif(INT1_SC == SC_ANY_LEVEL)
	CLR_BIT(REG_MCUCR, MCUCR_ISC11);
	SET_BIT(REG_MCUCR, MCUCR_ISC10);
#elif(INT1_SC == SC_FALL_EDGE)
	SET_BIT(REG_MCUCR, MCUCR_ISC11);
	CLR_BIT(REG_MCUCR, MCUCR_ISC10);
#elif(INT1_SC == SC_RISE_EDGE)
	SET_BIT(REG_MCUCR, MCUCR_ISC11);
	SET_BIT(REG_MCUCR, MCUCR_ISC10);
#else
#error("Wrong Sense Control Configuration for INT1")
#endif
	/** Enable SIE **/
	SET_BIT(REG_GICR, GICR_INT1);
}

void MEXTI_voidInt2Enable(void) {
	/** Adjust Sense Control **/
#if(INT2_SC == SC_FALL_EDGE)
	CLR_BIT(REG_MCUCSR, MCUCSR_ISC2);
#elif(INT2_SC == SC_RISE_EDGE)
	SET_BIT(REG_MCUCSR, MCUCSR_ISC2);
#else
#error("Wrong Sense Control Configuration for INT2")
#endif
	/** Enable SIE **/
	SET_BIT(REG_GICR, GICR_INT2);
}
/********************************* Pre-Build *********************************/

/************************************ ISR ************************************/
ISR(INT0_vect) {
	if (MEXTI_voidISR[0] != NULL) {
		MEXTI_voidISR[0]();
	}
}

ISR(INT1_vect) {
	if (MEXTI_voidISR[1] != NULL) {
		MEXTI_voidISR[1]();
	}
}

ISR(INT2_vect) {
	if (MEXTI_voidISR[2] != NULL) {
		MEXTI_voidISR[2]();
	}
}
/************************************ ISR ************************************/


