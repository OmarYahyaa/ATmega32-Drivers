/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 ADC			***********************/
/*****************		File:	 Configuration  ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MADC_MADC_CONFIG_H_
#define MADC_MADC_CONFIG_H_

/**
 *  Select Reference Selection:
 *   AREF
 *   AVCC
 *   INTERNAL
 **/

#define MADC_REFERENCE_SELECTION AREF

/**
 * Select Resolution:
 *  _8BIT
 *  _10BIT
 **/
#define MADC_RESOLUTION _10BIT

/**
 *  Select Auto Trigger Status:
 *   AUTO_TRIGGER_ENABLE
 *   AUTO_TRIGGER_DISABLE
 **/

#define MADC_AUTO_TRIGGER AUTO_TRIGGER_DISABLE

/**
 *  Adjust Interrupt Enable:
 *   INTERRUPT_ENABLE
 *   INTERRUPT_DISABLE
 **/

#define MADC_INTERRUPT INTERRUPT_DISABLE

/**
 *  Select Prescaler:
 *   PRESCALER_128
 *   PRESCALER_64
 *   PRESCALER_32
 *   PRESCALER_16
 *   PRESCALER_8
 *   PRESCALER_4
 *   PRESCALER_2
 **/

#define MADC_PRESCALER PRESCALER_128

/**
 * Define Time Out for Synchronous Function:
 **/

#define MADC_TIME_OUT 50000

#endif
