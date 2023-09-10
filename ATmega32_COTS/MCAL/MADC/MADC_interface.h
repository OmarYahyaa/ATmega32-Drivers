/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 MCAL			***********************/
/*****************		SWC:	 ADC			***********************/
/*****************		File:	 Interface      ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef MADC_MADC_INTERFACE_H_
#define MADC_MADC_INTERFACE_H_

typedef enum {
	channel0 = 0,
	channel1 = 1,
	channel2 = 2,
	channel3 = 3,
	channel4 = 4,
	channel5 = 5,
	channel6 = 6,
	channel7 = 7,
} Channel_t;

typedef struct {
	u8 Chain_Size;
	Channel_t *Ptr_Chain_Channels;
	u16 *Ptr_Chain_Readings;
	void (*PtrNotificationFN)(void);
} ADC_Chain_t;

ErrorState_t MADC_enInit(void);
ErrorState_t MADC_enStartConversionSynch(Channel_t copy_enChannel,u16 *PtrReadValue);
ErrorState_t MADC_enStartSingleConversionAsynch(Channel_t copy_enChannel,u16 *PtrReadValue, void (*ptrNotificationFn)(void));
ErrorState_t MADC_enStartChainConversionAsynch(ADC_Chain_t *PtrChain);

#endif
