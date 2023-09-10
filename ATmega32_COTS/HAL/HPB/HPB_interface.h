/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 Push Button	***********************/
/*****************		File:	 Interface      **********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HPB_HPB_INTERFACE_H_
#define HPB_HPB_INTERFACE_H_

typedef enum {
	PRESSED = 0, NOT_PRESSED = 1
} PB_STATE_t;

typedef enum {
	TEMP_PB = 0, PERM_PB = 1
} PB_Type_t;

typedef enum {
	PULL_UP = 0, PULL_DOWN = 1
} PB_Connection_t;

typedef struct {
	Pin_t PB_Pin;
	PB_Type_t PB_Type;
	PB_Connection_t PB_Connection;
} PB_t;

ErrorState_t HPB_enInit(PB_t *PtrPB);
ErrorState_t HPB_enGetState(PB_t *PtrPB, PB_STATE_t *PtrState);

#endif 
