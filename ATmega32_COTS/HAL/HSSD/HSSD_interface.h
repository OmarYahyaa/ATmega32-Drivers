/*
 * HSSD_interface.h
 *
 *  Created on: Jul 17, 2023
 *      Author: OMAR YAHYA
 */

#ifndef HSSD_HSSD_INTERFACE_H_
#define HSSD_HSSD_INTERFACE_H_

typedef enum {
	CA = 1, CC = 0
} COM_SSD_t;

typedef struct {
	u8 SSD_Type;
	u8 SSD_Pin_A;
	u8 SSD_Pin_B;
	u8 SSD_Pin_C;
	u8 SSD_Pin_D;
	u8 SSD_Pin_E;
	u8 SSD_Pin_F;
	u8 SSD_Pin_G;
	u8 SSD_Pin_EN;
} SSD_t;

ErrorState_t HSSD_enInit(SSD_t *PtrSSD);
ErrorState_t HSSD_enEnable(SSD_t *PtrSSD);
ErrorState_t HSSD_enDisable(SSD_t *PtrSSD);
ErrorState_t HSSD_enDisplayNumber(u8 copy_u8Number, SSD_t *PtrSSD);

#endif /* HSSD_HSSD_INTERFACE_H_ */
