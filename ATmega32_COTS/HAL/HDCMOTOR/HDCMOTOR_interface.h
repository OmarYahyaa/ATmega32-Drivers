/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 HAL			***********************/
/*****************		SWC:	 DC Motor	    ***********************/
/*****************		File:	 Interface      ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef HAL_HDCMOTOR_HDCMOTOR_INTERFACE_H_
#define HAL_HDCMOTOR_HDCMOTOR_INTERFACE_H_

typedef enum {
	CLK_WISE = 0, ANTI_CLK_WISE = 1
} DCMotorDirection_t;

typedef struct {
	Pin_t Motor_Pin1;
	Pin_t Motor_Pin2;
} DCMotor_t;

ErrorState_t HDCMOTOR_enInit(DCMotor_t *ptrMotor);
ErrorState_t HDCMOTOR_enMotorON(DCMotor_t *ptrMotor, DCMotorDirection_t copy_enDirection);
ErrorState_t HDCMOTOR_enMotorOFF(DCMotor_t *ptrMotor);

#endif
