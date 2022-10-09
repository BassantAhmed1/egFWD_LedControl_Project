/*
 * TM4c123GH6PM_SysTick.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Bassant Ahmed
 */

#ifndef SRC_MCAL_INC_TM4C123GH6PM_SYSTICK_H_
#define SRC_MCAL_INC_TM4C123GH6PM_SYSTICK_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
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
//@ref SystTick_ClkSrc_Define
typedef enum
{
	PIOSC_Quarter,			//PIOSC/4  = 4MHZ
	System_CLK

}Systick_ClkSrcType;


typedef struct
{
	Systick_ClkSrcType 		ClkSource;		//@ref SystTick_ClkSrc_Define
	uint8					IRQEnable;		//@ref IR_Enable_Define
}SysTick_ConfigType;



//-----------------------------
//Macros Configuration References
//-----------------------------


//@ref IR_Enable_Define
#define IRQ_Enable		1
#define IRQ_Disable		0


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern SysTick_ConfigType STConfig;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern void SysTick_init (void);
extern void StartSysTick (uint32 Seconds_ms);
extern void StopSysTick (void);
extern void SysTick_Handler(void);

#endif /* SRC_MCAL_INC_TM4C123GH6PM_SYSTICK_H_ */
