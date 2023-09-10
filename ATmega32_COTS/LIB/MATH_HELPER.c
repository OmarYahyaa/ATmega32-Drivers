/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 LIB			***********************/
/*****************		Name:	 Math Helper	***********************/
/*****************		Version: 1.00	        ***********************/
/**********************************************************************/
/**********************************************************************/

#include <STD_TYPES.h>
#include <MATH_HELPER.h>

s32 MATH_s32Map(s32 Copy_s32InputMin, s32 Copy_s32InputMax, s32 Copy_s32OutputMin, s32 Copy_s32OutputMax, s32 Copy_s32InputVal) {
	return ((((Copy_s32OutputMax - Copy_s32OutputMin)
			* (Copy_s32InputVal - Copy_s32InputMin))
			/ (Copy_s32InputMax - Copy_s32InputMin)) + Copy_s32OutputMin);
}

u32 MATH_u32ReverseNum(u32 copy_u32Num) {
	u32 Local_u32ReversedNum = 0;
	while (copy_u32Num != 0) {
		Local_u32ReversedNum *= 10;
		Local_u32ReversedNum += copy_u32Num % 10;
		copy_u32Num /= 10;
	}
	return Local_u32ReversedNum;
}

void MATH_voidConcatNum(u8 copy_u8Num, u32 *PtrConcatedNum) {
	(*PtrConcatedNum) *= 10;
	(*PtrConcatedNum) += copy_u8Num;
}

