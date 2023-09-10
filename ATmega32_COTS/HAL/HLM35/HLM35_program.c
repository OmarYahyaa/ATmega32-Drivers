/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 LCD	        ***********************/
/*****************		File:	 Program        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <ERROR_STATES.h>
#include <MDIO_interface.h>
#include <MADC_interface.h>
#include <HLM35_private.h>
#include <HLM35_config.h>
#include <HLM35_interface.h>

ErrorState_t HLM35_enInit(void) {
	MADC_enInit();
	return SUCCESS;
}

ErrorState_t HLM35_enReadTemp(u8 *ptrTempValue) {
	ErrorState_t Local_enState = SUCCESS;
	u16 Local_u16DigitalValue;
	u16 Local_u16AnalogValue;
	if (ptrTempValue == NULL) {
		Local_enState = NULL_POINTER;
	} else {
		MADC_enStartConversionSynch(HLM35_ADC_CHANNEL, &Local_u16DigitalValue);
#if(HLM35_ADC_RESOLUTION == _8BIT)
		// Analog Value in MilliVolt
		Local_u16AnalogValue = ((u32) Local_u16DigitalValue
				* HLM35_ADC_REFERENCE_VOLTAGE * 1000UL) / 256UL;
#elif(HLM35_ADC_RESOLUTION == _10BIT)
		// Analog Value in MilliVolt
		Local_u16AnalogValue = ((u32) Local_u16DigitalValue
				* HLM35_ADC_REFERENCE_VOLTAGE * 1000UL) / 1024UL;
#else
		#error("Wrong ADC Resolution for LM35")
		#endif
		*ptrTempValue = (Local_u16AnalogValue / 10);
	}
	return Local_enState;
}
