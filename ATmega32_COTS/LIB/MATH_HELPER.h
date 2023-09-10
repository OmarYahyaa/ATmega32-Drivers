/**********************************************************************/
/**********************************************************************/
/*****************		Author:  Omar Yahya		***********************/
/*****************		Layer:	 LIB			***********************/
/*****************		Name:	 Math Helper	***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef LIB_MATH_HELPER_H_
#define LIB_MATH_HELPER_H_

s32 MATH_s32Map(s32 Copy_s32InputMin, s32 Copy_s32InputMax, s32 Copy_s32OutputMin, s32 Copy_s32OutputMax, s32 Copy_s32InputVal);
u32 MATH_u32ReverseNum(u32 copy_u32Num);
void MATH_voidConcatNum(u8 copy_u8Num, u32 *PtrConcatedNum);

#endif
