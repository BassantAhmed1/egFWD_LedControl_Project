/*
 * GPIO_Cfg.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Bassant Ahmed
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Cfg.h
 *       Module:  -GPIO
 *
 *  Description:  in this file there's the references and APIs for the user
 *
 *********************************************************************************************************************/

#ifndef SRC_CONFIG_GPIO_CFG_H_
#define SRC_CONFIG_GPIO_CFG_H_
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
typedef struct
{
	Dio_ChannelType PortPinType;			//specifies the GPIO pin Number to be configured.
	//this parameter must be set based on a value @ref Port_PinType_define

	uint8 PortPinMode ;			//specifies the GPIO pin Mode to be configured.
	//this parameter must be set based on a value @ref Port_PinMode_define

	uint8 PortPinLevelValue ;		//specifies the GPIO pin Level to be configured.
	//this parameter must be set based on a value @ref Port_PinLevel_define

	uint8 PortPinDirection ;		//specifies the GPIO pin Direction to be configured.
	//this parameter must be set based on a value @ref Port_PinDir_define

	uint8 PortPinInternalAttach ;	//specifies the GPIO pin internal pull up or pull down attach to be configured.
	//this parameter must be set based on a value @ref Port_PinAttach_define

	uint8 PortPinOutputCurrent ;	//specifies the GPIO pin output current to be configured.
	//this parameter must be set based on a value @ref Port_PinOutCurrent_define

}Port_ConfigType;




//------------------------------------------------------------------------------------------------------------------



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Port_ConfigType PortConfig[];
extern uint16 PinConfig_size;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* SRC_CONFIG_GPIO_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
