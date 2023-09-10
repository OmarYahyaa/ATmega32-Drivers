/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 LED			***********************/
/*****************		File:	 Interface      ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HLED_HLED_INTERFACE_H_
#define HLED_HLED_INTERFACE_H_

typedef enum {
	SOURCE = 0, SINK = 1
} Connection_t;

typedef struct {
	u8 LED_Pin;
	u8 LED_Connection;
} Led_t;

ErrorState_t HLED_enInit(Led_t *PtrLed);
ErrorState_t HLED_enEnable(Led_t *PtrLed);
ErrorState_t HLED_enDisable(Led_t *PtrLed);
ErrorState_t HLED_enToggle(Led_t *PtrLed);

#endif
