/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 MSSD			***********************/
/*****************		File:	 Interface      **********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HMSSD_HMSSD_INTERFACE_H_
#define HMSSD_HMSSD_INTERFACE_H_

typedef enum {
	C_ANODE = 1, C_CATHODE = 0
} MSSD_COM_t;

typedef struct {
	MSSD_COM_t MSSD_Type;
	Pin_t MSSD_Pin_A;
	Pin_t MSSD_Pin_B;
	Pin_t MSSD_Pin_C;
	Pin_t MSSD_Pin_D;
	Pin_t MSSD_Pin_E;
	Pin_t MSSD_Pin_F;
	Pin_t MSSD_Pin_G;
	Pin_t MSSD_Pin_DP;
	Pin_t MSSD_Pin_EN1;
	Pin_t MSSD_Pin_EN2;
	u16 MSSD_Duration;
} MSSD_t;

ErrorState_t HMSSD_enInit(MSSD_t *PtrMSSD);
ErrorState_t HMSSD_enDisplayIntegerNumber(u8 copy_u8Number, MSSD_t *PtrMSSD);
ErrorState_t HMSSD_enDisplayRealNumber(f32 copy_u8Number, MSSD_t *PtrMSSD);

#endif 
