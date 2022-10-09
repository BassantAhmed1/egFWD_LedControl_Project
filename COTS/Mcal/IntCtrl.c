/*
 * IntCtrl.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Bassant Ahmed
 */


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**     \file  IntCtrl.c
 *      \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Common/Std_Types.h"
#include "../Common/Mcu_Hw.h"
#include "Inc/IntCtrl.h"
#include "Inc/IntCtrl_Types.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
uint32 * Get_PRIx(IntCtrl_InterruptType IRPeripheralGates)
{
	switch (IRPeripheralGates / 4)
	{
	case 0:
		return (uint32*)NVIC_PRI0;
		break;
	case 1:
		return (uint32*)NVIC_PRI1;
		break;
	case 2:
		return (uint32*)NVIC_PRI2;
		break;
	case 3:
		return (uint32*)NVIC_PRI3;
		break;
	case 4:
		return (uint32*)NVIC_PRI4;
		break;
	case 5:
		return (uint32*)NVIC_PRI5;
		break;
	case 6:
		return (uint32*)NVIC_PRI6;
		break;
	case 7:
		return (uint32*)NVIC_PRI7;
		break;
	case 8:
		return (uint32*)NVIC_PRI8;
		break;
	case 9:
		return (uint32*)NVIC_PRI9;
		break;
	case 10:
		return (uint32*)NVIC_PRI10;
		break;
	case 11:
		return (uint32*)NVIC_PRI11;
		break;
	case 12:
		return (uint32*)NVIC_PRI12;
		break;
	case 13:
		return (uint32*)NVIC_PRI13;
		break;
	case 14:
		return (uint32*)NVIC_PRI14;
		break;
	case 15:
		return (uint32*)NVIC_PRI15;
		break;
	case 16:
		return (uint32*)NVIC_PRI16;
		break;
	case 17:
		return (uint32*)NVIC_PRI17;
		break;
	case 18:
		return (uint32*)NVIC_PRI18;
		break;
	case 19:
		return (uint32*)NVIC_PRI19;
		break;
	case 20:
		return (uint32*)NVIC_PRI20;
		break;
	case 21:
		return (uint32*)NVIC_PRI21;
		break;
	case 22:
		return (uint32*)NVIC_PRI22;
		break;
	case 23:
		return (uint32*)NVIC_PRI23;
		break;
	case 24:
		return (uint32*)NVIC_PRI24;
		break;
	case 25:
		return (uint32*)NVIC_PRI25;
		break;
	case 26:
		return (uint32*)NVIC_PRI26;
		break;
	case 27:
		return (uint32*)NVIC_PRI27;
		break;
	case 28:
		return (uint32*)NVIC_PRI28;
		break;
	case 29:
		return (uint32*)NVIC_PRI29;
		break;
	case 30:
		return (uint32*)NVIC_PRI30;
		break;
	case 31:
		return (uint32*)NVIC_PRI31;
		break;
	case 32:
		return (uint32*)NVIC_PRI32;
		break;
	case 33:
		return (uint32*)NVIC_PRI33;
		break;
	case 34:
		return (uint32*)NVIC_PRI34;
		break;
	}

}

void Set_NVIC_Enable (IntCtrl_InterruptType IRPeripheralGates)
{
	switch (IRPeripheralGates / 32)
	{
	case 0:
		NVIC_EN0 |= (1<< IRPeripheralGates);
		break;
	case 1:
		NVIC_EN1 |= (1<< IRPeripheralGates);
		break;
	case 2:
		NVIC_EN2 |= (1<< IRPeripheralGates);
		break;
	case 3:
		NVIC_EN3 |= (1<< IRPeripheralGates);
		break;
	case 4:
		NVIC_EN4 |= (1<< IRPeripheralGates);
		break;
	}
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax          : void IntCtrl_Init (Void)
 * \Description     : initialize NVIC\SCB Module by parsing the configuration into
 * 					 NVIC\SCB registers
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCtrl_Init (void)
{
	uint8 BitPositionGroup;
	uint8 BitPositionSubGroup;
	uint32 *PRIx = Get_PRIx(IntCtrlConfig.InterruptPeripheralGates);
	if((IntCtrlConfig.InterruptPeripheralGates % 4) == 0)
		BitPositionSubGroup = 5;
	else if((IntCtrlConfig.InterruptPeripheralGates % 4) == 1)
		BitPositionSubGroup = 13;
	else if((IntCtrlConfig.InterruptPeripheralGates % 4) == 2)
		BitPositionSubGroup = 21;
	else
		BitPositionSubGroup = 29;

	//TODO Configure Grouping\Subgrouping system in APINT in SCB
	//APINT->B.VECTKEY = 0x05FA;
	*((uint32 *)(0xE000ED0C)) |= (0x05FA <<16);

	if ((IntCtrlConfig.IRGroup_SubGroup /8) == 0)			//7Groups and 1Sub-Group
	{*((uint32 *)(0xE000ED0C)) |= (0x0<<8);
	BitPositionGroup = BitPositionSubGroup;}
	else if ((IntCtrlConfig.IRGroup_SubGroup /8) == 1)		//4Groups and 2Sub-Groups
	{*((uint32 *)(0xE000ED0C)) |= (0x5<<8);
	BitPositionGroup = BitPositionSubGroup + 1;
	}
	else if ((IntCtrlConfig.IRGroup_SubGroup /8) == 2)		//2Groups and 4Sub-Groups
	{*((uint32 *)(0xE000ED0C)) |= (0x6<<8);
	BitPositionGroup = BitPositionSubGroup+2;
	}
	else if ((IntCtrlConfig.IRGroup_SubGroup /8) == 3)		//1Group and 7Sub-Groups
		*((uint32 *)(0xE000ED0C)) |= (0x7<<8);
	//TODO : Assign Group\Subgroup Priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers


	*PRIx |= (IntCtrlConfig.IRSubGroupPriority << BitPositionSubGroup);
	*PRIx |= (IntCtrlConfig.IRGroupPriority << BitPositionGroup);


	//TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers
	Set_NVIC_Enable (IntCtrlConfig.InterruptPeripheralGates);



}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
