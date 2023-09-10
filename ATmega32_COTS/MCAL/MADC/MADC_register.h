/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 ADC			***********************/
/*****************		File:	 Register       ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MADC_MADC_REGISTER_H_
#define MADC_MADC_REGISTER_H_

#define REG_ADMUX  *((volatile u8  *)0x27) // ADC Multiplexer Selection Register

#define ADMUX_REFS1 7 // Reference Selection Bit 1
#define ADMUX_REFS0 6 // Reference Selection Bit 2
#define ADMUX_ADLAR 5 // ADC Left Adjust Result
#define ADMUX_MUX4  4 // Analog Channel and Gain Selection Bit 1
#define ADMUX_MUX3  3 // Analog Channel and Gain Selection Bit 2
#define ADMUX_MUX2  2 // Analog Channel and Gain Selection Bit 3
#define ADMUX_MUX1  1 // Analog Channel and Gain Selection Bit 4
#define ADMUX_MUX0  0 // Analog Channel and Gain Selection Bit 5

#define REG_ADCSRA *((volatile u8  *)0x26) // ADC Control and Status Register A

#define ADCSRA_ADEN  7 // ADC Enable
#define ADCSRA_ADSC  6 // ADC Start Conversion
#define ADCSRA_ADATE 5 // ADC Auto Trigger Enable
#define ADCSRA_ADIF  4 // ADC Interrupt Flag
#define ADCSRA_ADIE  3 // ADC Interrupt Enable
#define ADCSRA_ADPS2 2 // ADC Prescaler Select Bit 1
#define ADCSRA_ADPS1 1 // ADC Prescaler Select Bit 2
#define ADCSRA_ADPS0 0 // ADC Prescaler Select Bit 3

#define REG_ADC    *((volatile u16 *)0x24) // ADC Data Register
#define REG_ADCH   *((volatile u8 *)0x25)  // ADC High

#define REG_SFIOR  *((volatile u8  *)0x50) // Special FunctionIO Register

#define SFIOR_ADTS2 7 // ADC Auto Trigger Source Bit 1
#define SFIOR_ADTS1 6 // ADC Auto Trigger Source Bit 2
#define SFIOR_ADTS0 5 // ADC Auto Trigger Source Bit 3

#endif
