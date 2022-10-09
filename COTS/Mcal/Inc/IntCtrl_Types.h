/*
 * IntCtrl_Types.h
 *
 *  Created on: Aug 14, 2022
 *      Author: Bassant Ahmed
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  IntCtrl_Types.h
 *  Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/

#ifndef SRC_MCAL_INC_INTCTRL_TYPES_H_
#define SRC_MCAL_INC_INTCTRL_TYPES_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum {
	GPIOA_IRQ,
	GPIOB_IRQ,
	GPIOC_IRQ,
	GPIOD_IRQ,
	GPIOE_IRQ,
	Timer0A_16_IRQ =19,
	Timer0B_16_IRQ ,
	Timer1A_16_IRQ ,
	Timer1B_16_IRQ ,
	Timer2A_16_IRQ ,
	Timer2B_16_IRQ,
	Timer3A_16_IRQ =35,
	Timer3B_16_IRQ,
	Timer4A_16_IRQ =70,
	Timer4B_16_IRQ,
	Timer5A_16_IRQ =92,
	Timer5B_16_IRQ,
	Timer0A_32_IRQ=94,
	Timer0B_32_IRQ,
	Timer1A_32_IRQ,
	Timer1B_32_IRQ,
	Timer2A_32_IRQ,
	Timer2B_32_IRQ,
	Timer3A_32_IRQ,
	Timer3B_32_IRQ,
	Timer4A_32_IRQ,
	Timer4B_32_IRQ,
	Timer5A_32_IRQ,
	Timer5B_32_IRQ
}IntCtrl_InterruptType;


typedef enum {
	Group0_SubGroup0,
	Group1_SubGroup0,
	Group2_SubGroup0,
	Group3_SubGroup0,
	Group4_SubGroup0,
	Group5_SubGroup0,
	Group6_SubGroup0,
	Group7_SubGroup0,

	Group1_SubGroup1,
	Group2_SubGroup1,
	Group3_SubGroup1,

	Group0_SubGroup1=16,
	Group0_SubGroup2,
	Group0_SubGroup3,
	Group1_SubGroup2,
	Group1_SubGroup3,

	Group0_SubGroup4=24,
	Group0_SubGroup5,
	Group0_SubGroup6,
	Group0_SubGroup7

}IntCtrl_Group_SubGroup;

typedef enum {
	Group_Priority0,
	Group_Priority1,
	Group_Priority2,
	Group_Priority3,
	Group_Priority4,
	Group_Priority5,
	Group_Priority6,
	Group_Priority7

}IntCtrl_GroupPriority;

typedef enum {
	SubGroup_Priority0,
	SubGroup_Priority1,
	SubGroup_Priority2,
	SubGroup_Priority3,
	SubGroup_Priority4,
	SubGroup_Priority5,
	SubGroup_Priority6,
	SubGroup_Priority7

}IntCtrl_SubGroupPriority;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* SRC_MCAL_INC_INTCTRL_TYPES_H_ */


/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
