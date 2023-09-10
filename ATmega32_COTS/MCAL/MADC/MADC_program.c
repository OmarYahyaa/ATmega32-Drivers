/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 ADC			***********************/
/*****************		File:	 Program        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <BIT_MATH.h>
#include <INTERRUPT.h>
#include <MADC_register.h>
#include <MADC_private.h>
#include <MADC_config.h>
#include <MADC_interface.h>

static void (*MADC_voidNotificationFn)(void) = NULL;
static u16 *MADC_u16ReadVal = NULL;
static ADC_Chain_t *MADC_enChainStruct = NULL;
static u8 MADC_u8FunState = IDLE;
static u8 MADC_u8SelectISR = NONE;
static u8 MADC_u8ChainChannelIndex;
ErrorState_t MADC_enInit() {
	/******************** Adjust Reference Voltage ********************/
#if(MADC_REFERENCE_SELECTION == AREF)
	CLR_BIT(REG_ADMUX, ADMUX_REFS1);
	CLR_BIT(REG_ADMUX, ADMUX_REFS0);
#elif(MADC_REFERENCE_SELECTION == AVCC)
	CLR_BIT(REG_ADMUX, ADMUX_REFS1);
	SET_BIT(REG_ADMUX, ADMUX_REFS0);
#elif(MADC_REFERENCE_SELECTION == INTERNAL)
	SET_BIT(REG_ADMUX, ADMUX_REFS1);
	SET_BIT(REG_ADMUX, ADMUX_REFS0);
#else
#error ("Wrong Reference Voltage Configuration")
#endif
	/******************** Adjust Reference Voltage ********************/

	/************************** Adjust ADLAR **************************/
#if(MADC_RESOLUTION == _10BIT)
	/** Right Adjust **/
	CLR_BIT(REG_ADMUX, ADMUX_ADLAR);
#elif(MADC_RESOLUTION == _8BIT)
	/** Left Adjust **/
	SET_BIT(REG_ADMUX, ADMUX_ADLAR);
#else
#error ("Wrong Resolution Configuration")
#endif
	/************************** Adjust ADLAR **************************/

	/********************** Adjust Auto Trigger ***********************/
#if(MADC_AUTO_TRIGGER == AUTO_TRIGGER_ENABLE)
	SET_BIT(REG_ADCSRA, ADCSRA_ADATE);
#elif(MADC_AUTO_TRIGGER == AUTO_TRIGGER_DISABLE)
	CLR_BIT(REG_ADCSRA, ADCSRA_ADATE);
#else
#error("Wrong Auto Trigger Status Configuration")
#endif
	/********************** Adjust Auto Trigger ***********************/

	/************************ Adjust Interrupt ************************/
#if(MADC_INTERRUPT == INTERRUPT_ENABLE)
	SET_BIT(REG_ADCSRA, ADCSRA_ADIE);
#elif(MADC_INTERRUPT == INTERRUPT_DISABLE)
	CLR_BIT(REG_ADCSRA, ADCSRA_ADIE);
#else
#error("Wrong Interrupt Status Configuration")
#endif
	/************************ Adjust Interrupt ************************/

	/************************ Adjust Prescaler ************************/
#if(MADC_PRESCALER == PRESCALER_128)
	REG_ADCSRA &= ADPS_MASK;
	REG_ADCSRA |= PRESCALER_128;
#elif(MADC_PRESCALER == PRESCALER_64)
	REG_ADCSRA &= ADPS_MASK;
	REG_ADCSRA |= PRESCALER_64;
#elif(MADC_PRESCALER == PRESCALER_32)
	REG_ADCSRA &= ADPS_MASK;
	REG_ADCSRA |= PRESCALER_32;
#elif(MADC_PRESCALER == PRESCALER_16)
	REG_ADCSRA &= ADPS_MASK;
	REG_ADCSRA |= PRESCALER_16;
#elif(MADC_PRESCALER == PRESCALER_8)
	REG_ADCSRA &= ADPS_MASK;
	REG_ADCSRA |= PRESCALER_8;
#elif(MADC_PRESCALER == PRESCALER_4)
	REG_ADCSRA &= ADPS_MASK;
	REG_ADCSRA |= PRESCALER_4;
#elif(MADC_PRESCALER == PRESCALER_2)
	REG_ADCSRA &= ADPS_MASK;
	REG_ADCSRA |= PRESCALER_2;
#else
#error("Wrong Prescaler Configuration")
#endif
	/************************ Adjust Prescaler ************************/

	/*************************** Enable ADC ***************************/
	SET_BIT(REG_ADCSRA, ADCSRA_ADEN);
	/*************************** Enable ADC ***************************/
	return SUCCESS;
}

ErrorState_t MADC_enStartConversionSynch(Channel_t copy_enChannel,
		u16 *PtrReadValue) {
	ErrorState_t Local_enState = SUCCESS;
	if (MADC_u8FunState == BUSY) {
		Local_enState = BUSY_FUNCTION;
	} else {
		u32 Local_u32Counter = 0;
		if (PtrReadValue == NULL) {
			Local_enState = NULL_POINTER;
		} else {
			if (copy_enChannel < 0 || copy_enChannel > 7) {
				Local_enState = OUT_OF_RANGE;
			} else {
				/************************ ADC is Busy Now *************************/
				MADC_u8FunState = BUSY;
				/************************ ADC is Busy Now *************************/

				/************************* Select Channel *************************/
				REG_ADMUX &= MUX_MASK;
				REG_ADMUX |= copy_enChannel;
				/************************* Select Channel *************************/

				/************************ Start Conversion ************************/
				SET_BIT(REG_ADCSRA, ADCSRA_ADSC);
				/************************ Start Conversion ************************/

				/****** Busy Waiting Until Flag Raised or Exceeded Time Out ******/
				while (((GET_BIT(REG_ADCSRA, ADCSRA_ADIF)) == 0)
						&& (Local_u32Counter < MADC_TIME_OUT)) {
					Local_u32Counter++;
				} // while
				/****** Busy Waiting Until Flag Raised or Exceeded Time Out ******/
				if (Local_u32Counter == MADC_TIME_OUT) {
					Local_enState = TIME_OUT;
				} else {
					/************************** Clear Flag ***************************/
					SET_BIT(REG_ADCSRA, ADCSRA_ADIF);
					/************************** Clear Flag ***************************/

					/************************** Read Value ***************************/
#if(MADC_RESOLUTION == _10BIT)
					*PtrReadValue = (REG_ADC);
#elif(MADC_RESOLUTION == _8BIT)
					*PtrReadValue = (REG_ADCH);
#else
				#error("Wrong Resolution Configuration")
				#endif
					/************************** Read Value ***************************/

					/****************** Return ADC State to Idle *********************/
					MADC_u8FunState = IDLE;
					/****************** Return ADC State to Idle *********************/
				} // else flag is Raised
			} // else In Range
		} // else PtrReadValue != NULL
	} // else Function Not Busy
	return Local_enState;
}

ErrorState_t MADC_enStartSingleConversionAsynch(Channel_t copy_enChannel,
		u16 *PtrReadValue, void (*ptrNotificationFn)(void)) {
	ErrorState_t Local_enState = SUCCESS;
	if (MADC_u8FunState == BUSY) {
		Local_enState = BUSY_FUNCTION;
	} else {
		if (PtrReadValue == NULL || ptrNotificationFn == NULL) {
			Local_enState = NULL_POINTER;
		} else {
			if (copy_enChannel < 0 || copy_enChannel > 7) {
				Local_enState = OUT_OF_RANGE;
			} else {
				/******************* ADC is Busy Now ********************/
				MADC_u8FunState = BUSY;
				/******************* ADC is Busy Now ********************/

				/****************** Select ISR Source *******************/
				MADC_u8SelectISR = SINGLE_CONVERSION;
				/****************** Select ISR Source *******************/

				/******************** Select Channel ********************/
				REG_ADMUX &= MUX_MASK;
				REG_ADMUX |= copy_enChannel;
				/******************** Select Channel ********************/

				/******************* Enable Interrupt *******************/
				SET_BIT(REG_ADCSRA, ADCSRA_ADIE);
				/******************* Enable Interrupt *******************/

				/***** Setting Notification Function and Read Value *****/
				MADC_voidNotificationFn = ptrNotificationFn;
				MADC_u16ReadVal = PtrReadValue;
				/***** Setting Notification Function and Read Value *****/

				/******************* Start Conversion *******************/
				SET_BIT(REG_ADCSRA, ADCSRA_ADSC);
				/******************* Start Conversion *******************/
			} // else In Range
		} // else PtrReadValue != NULL || ptrNotificationFn != NULL
	} // else Function Not Busy
	return Local_enState;
}

ErrorState_t MADC_enStartChainConversionAsynch(ADC_Chain_t *PtrChain) {
	ErrorState_t Local_enState = SUCCESS;
	if (MADC_u8FunState == BUSY) {
		Local_enState = BUSY_FUNCTION;
	} else {
		if (PtrChain == NULL || PtrChain->Ptr_Chain_Channels == NULL
				|| PtrChain->Ptr_Chain_Readings == NULL
				|| PtrChain->Ptr_Chain_Channels == NULL) {
			Local_enState = NULL_POINTER;
		} else {
			/******************* ADC is Busy Now ********************/
			MADC_u8FunState = BUSY;
			/******************* ADC is Busy Now ********************/

			/****************** Select ISR Source *******************/
			MADC_u8SelectISR = CHAIN_CONVERSION;
			/****************** Select ISR Source *******************/

			/****************** Set Index to Zero *******************/
			MADC_u8ChainChannelIndex = 0;
			/****************** Set Index to Zero *******************/

			/*************** Passing Struct Globally ****************/
			MADC_enChainStruct = PtrChain;
			/*************** Passing Struct Globally ****************/

			/******************** Select Channel ********************/
			REG_ADMUX &= MUX_MASK;
			REG_ADMUX |= PtrChain->Ptr_Chain_Channels[MADC_u8ChainChannelIndex];
			/******************** Select Channel ********************/

			/******************* Enable Interrupt *******************/
			SET_BIT(REG_ADCSRA, ADCSRA_ADIE);
			/******************* Enable Interrupt *******************/

			/******************* Start Conversion *******************/
			SET_BIT(REG_ADCSRA, ADCSRA_ADSC);
			/******************* Start Conversion *******************/
		} // else No Pointer == NULL
	} // else Function Not Busy
	return Local_enState;
}
/******************************************** ISR ********************************************/
ISR(ADC_vect) {
	if (MADC_u8SelectISR == SINGLE_CONVERSION) {
		/********************** Read Value **********************/
#if(MADC_RESOLUTION == _10BIT)
		*MADC_u16ReadVal = REG_ADC;
#elif(MADC_RESOLUTION == _8BIT)
		*MADC_u16ReadVal = REG_ADCH;
#else
	#error("Wrong Resolution Configuration")
	#endif
		/********************** Read Value **********************/

		/************** Return ADC State to Idle ****************/
		MADC_u8FunState = IDLE;
		/************** Return ADC State to Idle ****************/

		/************ Return ISR Selection to None **************/
		MADC_u8SelectISR = NONE;
		/************ Return ISR Selection to None **************/

		/************** Call Notification Function **************/
		MADC_voidNotificationFn();
		/************** Call Notification Function **************/

		/******************* Disable Interrupt ******************/
		CLR_BIT(REG_ADCSRA, ADCSRA_ADIE);
		/******************* Disable Interrupt ******************/

	} else if (MADC_u8SelectISR == CHAIN_CONVERSION) {
		/********************** Read Value **********************/
#if(MADC_RESOLUTION == _10BIT)
		MADC_enChainStruct->Ptr_Chain_Readings[MADC_u8ChainChannelIndex] =
		REG_ADC;
#elif(MADC_RESOLUTION == _8BIT)
		MADC_enChainStruct->Ptr_Chain_Readings[MADC_u8ChainChannelIndex] =
		REG_ADCH;
#else
#error("Wrong Resolution Configuration")
#endif
		/********************** Read Value **********************/

		/******************** Increment Index *******************/
		MADC_u8ChainChannelIndex++;
		/******************** Increment Index *******************/

		if (MADC_u8ChainChannelIndex == MADC_enChainStruct->Chain_Size) {
			/************** Return ADC State to Idle ****************/
			MADC_u8FunState = IDLE;
			/************** Return ADC State to Idle ****************/

			/************ Return ISR Selection to None **************/
			MADC_u8SelectISR = NONE;
			/************ Return ISR Selection to None **************/

			/************** Call Notification Function **************/
			MADC_enChainStruct->PtrNotificationFN();
			/************** Call Notification Function **************/

			/******************* Disable Interrupt ******************/
			CLR_BIT(REG_ADCSRA, ADCSRA_ADIE);
			/******************* Disable Interrupt ******************/
		} else {
			/***************** Select Next Channel ******************/
			REG_ADMUX &= MUX_MASK;
			REG_ADMUX |=
					MADC_enChainStruct->Ptr_Chain_Channels[MADC_u8ChainChannelIndex];
			/***************** Select Next Channel ******************/

			/******************* Start Conversion *******************/
			SET_BIT(REG_ADCSRA, ADCSRA_ADSC);
			/******************* Start Conversion *******************/
		}
	} else {
		// Do Nothing
	}
}
/******************************************** ISR ********************************************/
