/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 PORT			***********************/
/*****************		File:	 Register       ***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MPORT_MPORT_REGISTER_H_
#define MPORT_MPORT_REGISTER_H_

#define REG_DDRA  *((volatile u8 *)0x3A)
#define REG_PORTA *((volatile u8 *)0x3B)

#define REG_DDRB  *((volatile u8 *)0x37)
#define REG_PORTB *((volatile u8 *)0x38)

#define REG_DDRC  *((volatile u8 *)0x34)
#define REG_PORTC *((volatile u8 *)0x35)

#define REG_DDRD  *((volatile u8 *)0x31)
#define REG_PORTD *((volatile u8 *)0x32)

#endif 
