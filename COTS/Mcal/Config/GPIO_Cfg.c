/*
 * GPIO_Lcfg.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Bassant Ahmed
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Mcu_Hw.h"
#include "../Inc/TM4C123GH6PM_GPIO.h"
#include "GPIO_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Port_ConfigType PortConfig[] = 
							{
								{Dio_PortA_PA0, Port_PinMode_GPIO, 0, Port_PinDir_Input, Port_PinAttach_PD, 0},
								{Dio_PortA_PA1, Port_PinMode_GPIO, 0, Port_PinDir_Input, Port_PinAttach_PD, 0},
								{Dio_PortA_PA2, Port_PinMode_GPIO, 0, Port_PinDir_Input, Port_PinAttach_PD, 0},
								{Dio_PortA_PA3, Port_PinMode_GPIO, 0, Port_PinDir_Input, Port_PinAttach_PD, 0},
								{Dio_PortA_PA4, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortA_PA5, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortA_PA6, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortA_PA7, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								
								{Dio_PortB_PB0, Port_PinMode_GPIO, 0, Port_PinDir_Input, Port_PinAttach_PD, 0},
								{Dio_PortB_PB1, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortB_PB2, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortB_PB3, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortB_PB4, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortB_PB5, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortB_PB6, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortB_PB7, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								
								{Dio_PortC_PC0, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortC_PC1, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortC_PC2, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortC_PC3, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortC_PC4, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortC_PC5, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortC_PC6, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortC_PC7, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								
								{Dio_PortD_PD0, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortD_PD1, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortD_PD2, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortD_PD3, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortD_PD4, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortD_PD5, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortD_PD6, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortD_PD7, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								
								{Dio_PortE_PE0, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortE_PE1, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortE_PE2, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortE_PE3, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortE_PE4, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortE_PE5, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
																
								{Dio_PortF_PF0, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortF_PF1, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortF_PF2, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortF_PF3, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
								{Dio_PortF_PF4, Port_PinMode_GPIO, 0, Port_PinDir_Output, Port_PinAttach_OD, Port_PinOutCurrent_4mA},
							};


uint16 PinConfig_size = sizeof(PortConfig)/sizeof(Port_ConfigType);
/**********************************************************************************************************************
 *  END OF FILE: GPIO_Lcfg.c
 *********************************************************************************************************************/

