/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 KeyPad         ***********************/
/*****************		File:	 Configuration  ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HKEYPAD_HKEYPAD_CONFIG_H_
#define HKEYPAD_HKEYPAD_CONFIG_H_

/**
 * Configure Pins for Keypad
 */

/** Rows **/
#define HKEYPAD_R1    PD0
#define HKEYPAD_R2    PD1
#define HKEYPAD_R3    PD2
#define HKEYPAD_R4    PD3
/** Columns **/
#define HKEYPAD_C1    PD4
#define HKEYPAD_C2    PD5
#define HKEYPAD_C3    PD6
#define HKEYPAD_C4    PD7

/**
 * Configure Keypad Keys (Key Mapping)
 */

#define HKEYPAD_KEYS {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'C',0,'=','+'}}

#endif
