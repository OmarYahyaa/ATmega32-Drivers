/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 Buzzer	        ***********************/
/*****************		File:	 Interface      ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HBUZZER_HBUZZER_INTERFACE_H_
#define HBUZZER_HBUZZER_INTERFACE_H_

typedef enum {
	MS = 1, US = 2
} Delay_Unit_t;

ErrorState_t HBUZZER_enInit(Pin_t copy_enPin);
ErrorState_t HBUZZER_enBuzzON(Pin_t copy_enPin);
ErrorState_t HBUZZER_enBuzzOFF(Pin_t copy_enPin);
ErrorState_t HBUZZER_enBuzzMusic(Pin_t copy_enPin, Delay_Unit_t copy_enDelayUnit, u32 copy_u32DelayVal, u32 copy_u32Duration);

#endif
