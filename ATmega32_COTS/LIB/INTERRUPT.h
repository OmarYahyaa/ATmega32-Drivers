/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 LIB			***********************/
/*****************		Name:	 Interrupt	    ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define INT0_vect __vector_1
#define INT1_vect __vector_2
#define INT2_vect __vector_3
#define ADC_vect  __vector_16

#define ISR(INT_vect)void INT_vect(void) __attribute__((signal));\
	void INT_vect (void)

#endif
