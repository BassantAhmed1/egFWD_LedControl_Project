/*
 * IntCtrl.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Bassant Ahmed
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/

#ifndef SRC_MCAL_INC_INTCTRL_H_
#define SRC_MCAL_INC_INTCTRL_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Mcu_Hw.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	IntCtrl_InterruptType 		InterruptPeripheralGates;

	IntCtrl_Group_SubGroup		IRGroup_SubGroup;

	IntCtrl_GroupPriority		IRGroupPriority;

	IntCtrl_SubGroupPriority	IRSubGroupPriority;

}IntCtrl_ConfigType;


//-----------------------------
//Macros Configuration References
//-----------------------------


//------------------------------------------------------------------------------------------------------------------



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern IntCtrl_ConfigType IntCtrlConfig;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void IntCtrl_Init (void);
void IntCtrl_Timer_init (void);

#endif /* SRC_MCAL_INC_INTCTRL_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
