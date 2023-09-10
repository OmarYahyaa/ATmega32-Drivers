/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 EXTI			***********************/
/*****************		File:	 Configuration  ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MEXTI_MEXTI_CONFIG_H_
#define MEXTI_MEXTI_CONFIG_H_

/**
 *  Select Sense Control:
 *      SC_LOW_LEVEL
 *      SC_ANY_LEVEL
 *      SC_FALL_EDGE
 *      SC_RISE_EDGE
 **/

#define INT0_SC SC_RISE_EDGE
#define INT1_SC SC_RISE_EDGE
#define INT2_SC SC_RISE_EDGE

/**
 * Note: INT2 Support Only: SC_FALL_EDGE
 *                          SC_RISE_EDGE
 **/

#endif
