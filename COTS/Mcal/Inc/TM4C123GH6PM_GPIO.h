/*
 * TM4C123GH6PM_GPIO.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Bassant Ahmed
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TM4C123GH6PM_GPIO.h
 *       Module:  -GPIO
 *
 *  Description:  GPIO Driver for TM4C123GH6PM
 *
 *********************************************************************************************************************/


#ifndef SRC_MCAL_INC_TM4C123GH6PM_GPIO_H_
#define SRC_MCAL_INC_TM4C123GH6PM_GPIO_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref Port_PinMode_define
#define		Port_PinMode_GPIO			0
#define		Port_PinMode_AF				1

//@ref Port_PinLevel_define
#define 	Port_PinLevel_Low			0
#define 	Port_PinLevel_High			1

//@ref Port_PinDir_define
#define 	Port_PinDir_Input			0
#define 	Port_PinDir_Output			1


//@ref Port_PinAttach_define
#define 	Port_PinAttach_PU			0
#define 	Port_PinAttach_PD			1
#define 	Port_PinAttach_OD			2

//@ref Port_PinOutCurrent_define
#define 	Port_PinOutCurrent_2mA		0
#define 	Port_PinOutCurrent_4mA		1
#define 	Port_PinOutCurrent_8mA		2


//@ref Port_PinType_define
typedef enum
{
	Dio_PortA_PA0,
	Dio_PortA_PA1,
	Dio_PortA_PA2,
	Dio_PortA_PA3,
	Dio_PortA_PA4,
	Dio_PortA_PA5,
	Dio_PortA_PA6,
	Dio_PortA_PA7,

	Dio_PortB_PB0,
	Dio_PortB_PB1,
	Dio_PortB_PB2,
	Dio_PortB_PB3,
	Dio_PortB_PB4,
	Dio_PortB_PB5,
	Dio_PortB_PB6,
	Dio_PortB_PB7,

	Dio_PortC_PC0,
	Dio_PortC_PC1,
	Dio_PortC_PC2,
	Dio_PortC_PC3,
	Dio_PortC_PC4,
	Dio_PortC_PC5,
	Dio_PortC_PC6,
	Dio_PortC_PC7,

	Dio_PortD_PD0,
	Dio_PortD_PD1,
	Dio_PortD_PD2,
	Dio_PortD_PD3,
	Dio_PortD_PD4,
	Dio_PortD_PD5,
	Dio_PortD_PD6,
	Dio_PortD_PD7,

	Dio_PortE_PE0,
	Dio_PortE_PE1,
	Dio_PortE_PE2,
	Dio_PortE_PE3,
	Dio_PortE_PE4,
	Dio_PortE_PE5,

	Dio_PortF_PF0 =40,
	Dio_PortF_PF1,
	Dio_PortF_PF2,
	Dio_PortF_PF3,
	Dio_PortF_PF4
}Dio_ChannelType;



typedef enum
{
	Low,
	High
}Dio_LevelType;


typedef enum
{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
}PinNum;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern void port_init (void);
extern Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
extern void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level );
extern uint8 Dio_ReadPort (GPIO_TypeDef * GPIOx);
extern void Dio_WritePort (GPIO_TypeDef * GPIOx,uint8 Data );
extern void Dio_FlipChannel (Dio_ChannelType ChannelId);


#endif /* SRC_MCAL_INC_TM4C123GH6PM_GPIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
