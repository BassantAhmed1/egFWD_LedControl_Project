/*
 * TM4C123GH6PM_GPIO.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Bassant Ahmed
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**     \file  TM4C123GH6PM_GPIO.c
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
#include "Inc/TM4C123GH6PM_GPIO.h"
#include "Config/GPIO_Cfg.h"
#include "../Common/Mcu_Hw.h"

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
uint32 Get_Port (Dio_ChannelType Port)
{
	switch ((uint8)Port/8)
	{
	case 0:	//PortA
		return (uint32)GPIOA_Base;
		break;

	case 1: //PortB
		return (uint32)GPIOB_Base;
		break;

	case 2: //PortC
		return (uint32)GPIOC_Base;
		break;

	case 3: //PortD
		return (uint32)GPIOD_Base;
		break;

	case 4: //PortE
		return (uint32)GPIOE_Base;
		break;

	case 5: //PortF
		return (uint32)GPIOF_Base;
		break;
	}
}

PinNum Get_Pin (Dio_ChannelType Pin)
{
	uint8 pinx = Pin % 8;
	switch (pinx)
	{
	case 0:	//Pin0
		return Pin0;
		break;

	case 1: //Pin1
		return Pin1;
		break;

	case 2: //Pin2
		return Pin2;
		break;

	case 3: //Pin3
		return Pin3;
		break;

	case 4: //Pin4
		return Pin4;
		break;

	case 5: //Pin5
		return Pin5;
		break;

	case 6: //Pin6
		return Pin6;
		break;

	case 7: //Pin7
		return Pin7;
		break;
	}
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax          : void port_init (const Port_ConfigType* ConfigPtr)
 * \Description     : initializing the specified port
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Port_ConfigType* ConfigPtr
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void port_init (void)
{
	uint32 Portx = 0;
	PinNum Pinx = 0;
	
	int i=0;
	
	for(i = 0; i < PinConfig_size;i++)
	{
		Portx = Get_Port(PortConfig[i].PortPinType);
		Pinx = Get_Pin(PortConfig[i].PortPinType);
		//Enable the clock
		if (Portx == GPIOA_Base)
			{GPIOA_CLK_EN();}
		else if (Portx == GPIOB_Base)
			{GPIOB_CLK_EN();}
		else if (Portx == GPIOC_Base)
			{GPIOC_CLK_EN();}
		else if (Portx == GPIOD_Base)
			{GPIOD_CLK_EN();}
		else if (Portx == GPIOE_Base)
			{GPIOE_CLK_EN();}
		else if (Portx == GPIOF_Base)
			{GPIOF_CLK_EN();}



		//Set the direction of the GPIO port pins by programming the GPIODIR register.
		if (PortConfig[i].PortPinDirection == Port_PinDir_Input)
			Clear_bit_GPIO(Portx ,Pinx, GPIODIR_offset);
		else
			Set_bit_GPIO(Portx ,Pinx , GPIODIR_offset);

		//Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin
		if (PortConfig[i].PortPinMode == Port_PinMode_GPIO)
			Clear_bit_GPIO(Portx ,Pinx , GPIOAFSEL_offset);
		else
			Set_bit_GPIO(Portx ,Pinx , GPIOAFSEL_offset);

		//Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers
		switch (PortConfig[i].PortPinOutputCurrent)
		{
		case Port_PinOutCurrent_2mA :
			Set_bit_GPIO(Portx ,Pinx , GPIODR2R_offset);
			break;
		case Port_PinOutCurrent_4mA :
			Set_bit_GPIO(Portx ,Pinx , GPIODR4R_offset);
			break;
		case Port_PinOutCurrent_8mA :
			Set_bit_GPIO(Portx ,Pinx , GPIODR8R_offset);
			break;
		}

		//Program each pad in the port to have either pull-up, pull-down, or open drain functionality through
		//the GPIOPUR, GPIOPDR, GPIOODR register.
		switch (PortConfig[i].PortPinInternalAttach)
		{
		case Port_PinAttach_PU :
			Set_bit_GPIO(Portx ,Pinx , GPIOPUR_offset);
			break;
		case Port_PinAttach_PD :
			Set_bit_GPIO(Portx ,Pinx , GPIOPDR_offset);
			break;
		case Port_PinAttach_OD :
			Set_bit_GPIO(Portx ,Pinx , GPIOODR_offset);
			break;
		}

		//Enable DEN
		Set_bit_GPIO(Portx ,Pinx , GPIODEN_offset);

		if (PortConfig[i].PortPinLevelValue == Port_PinLevel_High)
			Set_bit_GPIO(Portx ,Pinx , GPIODATA_offset);
	}
}

/******************************************************************************
 * \Syntax          : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
 * \Description     : Reading the GPIO Specific pin
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Dio_ChannelType ChannelId
 * \Parameters (out): None
 * \Return value:   : Dio_LevelType  High
 *                                   Low
 *******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	uint32 * Portx = Get_Port(ChannelId) + 0x3FC ;
	PinNum Pinx = Get_Pin(ChannelId);
	
	uint32 Data = *Portx ;
	

	if((( Data & (1<<Pinx))>>Pinx)==1)
	{
		return High;
	}
		
	else
		return Low;
}

/******************************************************************************
 * \Syntax          : void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level )
 * \Description     : Writing on a GPIO specific pin
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Dio_ChannelType ChannelId
 * \Parameters (in) : Dio_LevelType Level
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level )
{
	uint32 Portx = Get_Port(ChannelId);
	PinNum Pinx = Get_Pin(ChannelId);

	if (Level == High)
		Set_bit_GPIO(Portx ,Pinx , 0x3FC);
	else
		Clear_bit_GPIO(Portx ,Pinx , 0x3FC);
}

/******************************************************************************
 * \Syntax          : Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
 * \Description     : Reading a specific GPIO Port
  * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIO_TypeDef * GPIOx
 * \Parameters (out): None
 * \Return value:   : Portx Data
 *******************************************************************************/
uint8 Dio_ReadPort (GPIO_TypeDef * GPIOx)
{
	return (uint8)GPIOx->GPIODATA ;
}

/******************************************************************************
 * \Syntax          : void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level )
 * \Description     : write on a specific GPIO Port
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIO_TypeDef * GPIOx
 * \Parameters (in) : uint8 Data
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_WritePort (GPIO_TypeDef * GPIOx,uint8 Data )
{
	uint8 * Portx = &GPIOx->GPIODATA + 0x3FC ;
	* Portx = Data;
}

/******************************************************************************
 * \Syntax          : Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
 * \Description     : toggling a Specific GPIO Pin
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Dio_ChannelType ChannelId
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_FlipChannel (Dio_ChannelType ChannelId)
{
	uint32 Portx = Get_Port(ChannelId);
	PinNum Pinx = Get_Pin(ChannelId);

	if ( Dio_ReadChannel (ChannelId) == 0)
		Set_bit_GPIO(Portx ,Pinx , 0x3FC);
	else
		Clear_bit_GPIO(Portx ,Pinx , 0x3FC);
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
