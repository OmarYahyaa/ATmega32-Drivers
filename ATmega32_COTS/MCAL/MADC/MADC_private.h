/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 ADC			***********************/
/*****************		File:	 Private        ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MADC_MADC_PRIVATE_H_
#define MADC_MADC_PRIVATE_H_

#define REFS_MASK 0b00111111
#define MUX_MASK  0b11100000
#define ADPS_MASK 0b11111000
#define ADTS_MASK 0b00011111

#define AREF 			     1
#define AVCC 			     2
#define INTERNAL             3

#define _8BIT                1
#define _10BIT               2

#define PRESCALER_128        7
#define PRESCALER_64         6
#define PRESCALER_32         5
#define PRESCALER_16         4
#define PRESCALER_8          3
#define PRESCALER_4          2
#define PRESCALER_2          1

#define AUTO_TRIGGER_ENABLE  1
#define AUTO_TRIGGER_DISABLE 2

#define INTERRUPT_ENABLE     1
#define INTERRUPT_DISABLE    2

#define IDLE                 0
#define BUSY                 1


#define NONE                 0
#define SINGLE_CONVERSION    1
#define CHAIN_CONVERSION     2

#endif /* MADC_MADC_PRIVATE_H_ */
