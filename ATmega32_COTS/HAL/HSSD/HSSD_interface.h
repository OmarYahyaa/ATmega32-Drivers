/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 SSD			***********************/
/*****************		File:	 Interface      ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HSSD_HSSD_INTERFACE_H_
#define HSSD_HSSD_INTERFACE_H_

typedef enum {
	CA = 1, CC = 0
} COM_SSD_t;

typedef struct {
	COM_SSD_t SSD_Type;
	Pin_t SSD_Pin_A;
	Pin_t SSD_Pin_B;
	Pin_t SSD_Pin_C;
	Pin_t SSD_Pin_D;
	Pin_t SSD_Pin_E;
	Pin_t SSD_Pin_F;
	Pin_t SSD_Pin_G;
	Pin_t SSD_Pin_EN;
} SSD_t;

ErrorState_t HSSD_enInit(SSD_t *PtrSSD);
ErrorState_t HSSD_enEnable(SSD_t *PtrSSD);
ErrorState_t HSSD_enDisable(SSD_t *PtrSSD);
ErrorState_t HSSD_enDisplayNumber(u8 copy_u8Number, SSD_t *PtrSSD);

#endif
