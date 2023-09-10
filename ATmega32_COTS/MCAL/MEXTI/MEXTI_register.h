/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 EXTI			***********************/
/*****************		File:	 Register       ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MEXTI_MEXTI_REGISTER_H_
#define MEXTI_MEXTI_REGISTER_H_

#define REG_MCUCR  *((volatile u8 *)0x55)

#define MCUCR_ISC11 3 // Interrupt Sense Control 1
#define MCUCR_ISC10 2 // Interrupt Sense Control 1
#define MCUCR_ISC01 1 // Interrupt Sense Control 0
#define MCUCR_ISC00 0 // Interrupt Sense Control 0

#define REG_MCUCSR *((volatile u8 *)0x54)

#define MCUCSR_ISC2 6 // Interrupt Sense Control 2

#define REG_GICR   *((volatile u8 *)0x5B)

#define GICR_INT1   7 // External Interrupt Request 1 Enable
#define GICR_INT0   6 // External Interrupt Request 0 Enable
#define GICR_INT2   5 // External Interrupt Request 2 Enable

#define REG_GIFR   *((volatile u8 *)0x5A)

#define GIFR_INTF1  7 // External Interrupt Flag 1
#define GIFR_INTF0  6 // External Interrupt Flag 0
#define GIFR_INTF2  5 // External Interrupt Flag 2

#endif
