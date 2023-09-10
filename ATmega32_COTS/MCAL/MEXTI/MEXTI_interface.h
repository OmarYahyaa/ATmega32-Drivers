/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 EXTI			***********************/
/*****************		File:	 Interface      ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MEXTI_MEXTI_INTERFACE_H_
#define MEXTI_MEXTI_INTERFACE_H_

typedef enum {
	INT0 = 6, INT1 = 7, INT2 = 5
} InterruptID_t;

typedef enum {
	LOW_LEVEL  = 0, // 00
	ANY_CHANGE = 1, // 01
	FALL_EDGE  = 2, // 10
	RISE_EDGE  = 3, // 11
} SenseControl_t;

/** Post-Build **/
ErrorState_t MEXTI_enEnable(InterruptID_t copy_enINT, SenseControl_t copy_enSC);
ErrorState_t MEXTI_enDisable(InterruptID_t copy_enINT);
ErrorState_t MEXTI_enSetCallBack(InterruptID_t copy_enINT, void (*ptrFn)(void));
/** Pre-Build **/
void MEXTI_voidInt0Enable(void);
void MEXTI_voidInt1Enable(void);
void MEXTI_voidInt2Enable(void);

#endif 
