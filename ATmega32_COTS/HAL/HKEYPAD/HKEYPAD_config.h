/*
 * HKEYPAD_config.h
 *
 *  Created on: Jul 30, 2023
 *      Author: OMAR YAHYA
 */

#ifndef HKEYPAD_HKEYPAD_CONFIG_H_
#define HKEYPAD_HKEYPAD_CONFIG_H_

/**
 * Configure Pins for Keypad
 */

/** Rows **/
#define HKEYPAD_R1    PC0
#define HKEYPAD_R2    PC1
#define HKEYPAD_R3    PC2
#define HKEYPAD_R4    PC3
/** Columns **/
#define HKEYPAD_C1    PC4
#define HKEYPAD_C2    PC5
#define HKEYPAD_C3    PC6
#define HKEYPAD_C4    PC7

/**
 * Configure Keypad Keys (Key Mapping)
 */

#define HKEYPAD_KEYS    {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#endif /* HKEYPAD_HKEYPAD_CONFIG_H_ */
