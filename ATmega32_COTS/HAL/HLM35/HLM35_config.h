/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 LM35	        ***********************/
/*****************		File:	 Configuration  ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HLM35_HLM35_CONFIG_H_
#define HLM35_HLM35_CONFIG_H_

/**
 *  Select ADC Channel:
 *   channel0
 *   channel1
 *   channel2
 *   channel3
 *   channel4
 *   channel5
 *   channel6
 *   channel7
 **/

#define HLM35_ADC_CHANNEL channel0

/**
 * Select ADC Resolution:
 *  _8BIT
 *  _10BIT
 **/

#define HLM35_ADC_RESOLUTION _10BIT

/**
 *  Select Your Reference Voltage
 **/

#define HLM35_ADC_REFERENCE_VOLTAGE 5

#endif
