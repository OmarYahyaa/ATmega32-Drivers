/*
 * HMSSD_interface.h
 *
 *  Created on: Jul 17, 2023
 *      Author: OMAR YAHYA
 */

#ifndef HMSSD_HMSSD_INTERFACE_H_
#define HMSSD_HMSSD_INTERFACE_H_

typedef enum {
	C_ANODE = 1, C_CATHODE = 0
} SSD_Connection_t;

typedef struct {
	u8 MSSD_Type;
	u8 MSSD_Pin_A;
	u8 MSSD_Pin_B;
	u8 MSSD_Pin_C;
	u8 MSSD_Pin_D;
	u8 MSSD_Pin_E;
	u8 MSSD_Pin_F;
	u8 MSSD_Pin_G;
	u8 MSSD_Pin_DP;
	u8 MSSD_Pin_EN1;
	u8 MSSD_Pin_EN2;
	u16 MSSD_Duration;
} MSSD_t;

ErrorState_t HMSSD_enInit(MSSD_t *PtrMSSD);
ErrorState_t HMSSD_enDisplayIntegerNumber(u8 copy_u8Number, MSSD_t *PtrMSSD);
ErrorState_t HMSSD_enDisplayRealNumber(f32 copy_u8Number, MSSD_t *PtrMSSD);

#endif /* HMSSD_HMSSD_INTERFACE_H_ */
