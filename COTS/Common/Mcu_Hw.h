/*
 * Mcu_Hw.h
 *
 *  Created on: Aug 14, 2022
 *      Author: Bassant Ahmed
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/

#ifndef SRC_COMMON_MCU_HW_H_
#define SRC_COMMON_MCU_HW_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
//#include "stdlib.h"
//#include "stdio.h"
//#include "stdint.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	uint32 TAEN			:1;
	uint32 TASTALL		:1;
	uint32 TAEVENT		:2;
	uint32 RTCEN		:1;
	uint32 TAOTE		:1;
	uint32 TAPWML		:1;
	uint32 				:1;
	uint32 TBEN			:1;
	uint32 TBSTALL		:1;
	uint32 TBEVENT		:2;
	uint32 				:1;
	uint32 TBOTE		:1;
	uint32 TBPWML		:1;
}GPTMCTL_BF;

typedef struct
{
	uint32 VECACT		:8;
	uint32				:3;
	uint32 RETBASE		:1;
	uint32 VECPEND		:8;
	uint32				:2;
	uint32 ISRPEND		:1;
	uint32 ISRPRE		:1;
	uint32				:1;
	uint32 PENDSTCLR	:1;
	uint32 PENDSTSET	:1;
	uint32 UNPENDSV		:1;
	uint32 PENDSV		:1;
	uint32 				:2;
	uint32 NMISET		:1;
}INTCTRL_BF;

typedef struct
{
	uint32 VECTRESET	:1;
	uint32 VECTCLRACT	:1;
	uint32 SYSRESREQ	:1;
	uint32 Reserved		:5;
	uint32 Reserved1	:2;
	uint32 PRIGROUP		:3;
	uint32 Reserved2	:4;
	uint32 ENDIANESS	:1;
	uint32 VECTKEY		:16;
}APINT_BF;

typedef struct
{
	uint32 PMC0			:4;
	uint32 PMC1			:4;
	uint32 PMC2			:4;
	uint32 PMC3			:4;
	uint32 PMC4			:4;
	uint32 PMC5			:4;
	uint32 PMC6			:4;
	uint32 PMC7			:4;
}GPIOPCTL_BF;

typedef struct
{
	uint32 TAMR 		:2;
	uint32 TACMR 		:1;
	uint32 TAAMS 		:1;
	uint32 TACDIR 		:1;
	uint32 TAMIE 		:1;
	uint32 TAWOT 		:1;
	uint32 TASNAPS 		:1;
	uint32 TAILD 		:1;
	uint32 TAPWMIE 		:1;
	uint32 TAMRSU 		:1;
	uint32 TAPLO 		:1;
}GPTMTAMR_BF;

typedef struct
{
	uint32 TATOCINT		:1;
	uint32 CAMCINT		:1;
	uint32 CAECINT		:1;
	uint32 RTCCINT		:1;
	uint32 TAMCINT		:1;
	uint32 				:3;
	uint32 TBTOCINT		:1;
	uint32 CBMCINT		:1;
	uint32 CBECINT		:1;
	uint32 TBMCINT		:1;
	uint32 				:4;
	uint32 WUECINT		:1;
}GPTMICR_BF;


typedef union
{
	uint32		R;
	APINT_BF	B;
}APINT_Tag;

typedef union
{
	uint32		R;
	INTCTRL_BF	B;
}INTCTRL_Tag;

typedef union
{
	uint32		R;
	GPTMCTL_BF	B;
}GPTMCTL_Tag;

typedef union
{
	uint32		R;
	GPIOPCTL_BF	B;
}GPIOPCTL_Tag;

typedef union
{
	uint32 		R;
	GPTMTAMR_BF	B;
}GPTMTAMR_Tag;

typedef union
{
	uint32 		R;
	GPTMICR_BF	B;
}GPTMICR_Tag;


typedef struct
{
	volatile uint32 			GPIODATA;
	volatile uint32 			Reserved1[99];
	volatile uint32 			GPIODIR;
	volatile uint32 			GPIOIS;
	volatile uint32 			GPIOIBE;
	volatile uint32 			GPIOIEV;
	volatile uint32 			GPIOIM;
	volatile uint32 			GPIORIS;
	volatile uint32 			GPIOMIS;
	volatile uint32 			GPIOICR;
	volatile uint32 			GPIOAFSEL;
	volatile uint32 			Reserved2[37];
	volatile uint32 			GPIODR2R;
	volatile uint32 			GPIODR4R;
	volatile uint32 			GPIODR8R;
	volatile uint32 			GPIOODR;
	volatile uint32 			GPIOPUR;
	volatile uint32 			GPIOPDR;
	volatile uint32 			GPIOSLR;
	volatile uint32 			GPIODEN;
	volatile uint32 			GPIOLOCK;
	volatile uint32 			GPIOCR;
	volatile uint32 			GPIOAMSEL;
	volatile GPIOPCTL_Tag 		GPIOPCTL;
	volatile uint32 			GPIOADCCTL;
	volatile uint32 			GPIODMACTL;
	volatile uint32 			Reserved3[678];
	volatile uint32 			GPIOPeriphID4;
	volatile uint32 			GPIOPeriphID5;
	volatile uint32 			GPIOPeriphID6;
	volatile uint32 			GPIOPeriphID7;
	volatile uint32 			GPIOPeriphID0;
	volatile uint32 			GPIOPeriphID1;
	volatile uint32 			GPIOPeriphID2;
	volatile uint32 			GPIOPeriphID3;
	volatile uint32 			GPIOPCellID0;
	volatile uint32 			GPIOPCellID1;
	volatile uint32 			GPIOPCellID2;
	volatile uint32 			GPIOPCellID3;

}GPIO_TypeDef;

typedef struct
{
	volatile uint32 			GPTMCFG;
	volatile GPTMTAMR_Tag 		GPTMTAMR;
	volatile uint32 			GPTMTBMR;
	volatile GPTMCTL_Tag 		GPTMCTL;
	volatile uint32 			GPTMSYNC;
	volatile uint32 			Reserved;
	volatile uint32 			GPTMIMR;
	volatile uint32 			GPTMRIS;
	volatile uint32 			GPTMMIS;
	volatile GPTMICR_Tag 		GPTMICR;
	volatile uint32 			GPTMTAILR;
	volatile uint32 			GPTMTBILR;
	volatile uint32 			GPTMTAMATCHR;
	volatile uint32 			GPTMTBMATCHR;
	volatile uint32 			GPTMTAPR;
	volatile uint32 			GPTMTBPR;
	volatile uint32 			GPTMTAPMR;
	volatile uint32 			GPTMTBPMR;
	volatile uint32 			GPTMTAR;
	volatile uint32 			GPTMTBR;
	volatile uint32 			GPTMTAV;
	volatile uint32 			GPTMTBV;
	volatile uint32 			GPTMRTCPD;
	volatile uint32 			GPTMTAPS;
	volatile uint32 			GPTMTBPS;
	volatile uint32 			GPTMTAPV;
	volatile uint32 			GPTMTBPV;
	volatile uint32 			Reserved1[981];
	volatile uint32 			GPTMPP;

}GPT_TypeDef;



//-*-*-*-*-*-*-*-*-*-*-*-
//System Control
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32 MOSCDIS		:1;
	volatile uint32 Reserved	:3;
	volatile uint32 OSCSRC		:2;
	volatile uint32	XTAL		:5;
	volatile uint32	BYPASS		:1;
	volatile uint32 Reserved1	:1;
	volatile uint32	PWRDN		:1;
	volatile uint32 Reserved2	:3;
	volatile uint32 PWMDIV		:3;
	volatile uint32 USEPWMDIV	:1;
	volatile uint32 Reserved4	:1;
	volatile uint32 USESYSDIV	:1;
	volatile uint32 SYSDIV		:4;
	volatile uint32 ACG			:1;
	volatile uint32 Reserved3	:4;
}RCC_BF;


typedef union
{
	uint32		R;
	RCC_BF		B;
}RCC_Tag;

typedef struct
{
	volatile uint32 Reserved		:4;
	volatile uint32 OSCSRC2			:3;
	volatile uint32 Reserved1		:4;
	volatile uint32	BYPASS2			:1;
	volatile uint32 Reserved2		:1;
	volatile uint32	PWRDN2			:1;
	volatile uint32 USBPWRDN		:1;
	volatile uint32 Reserved3		:7;
	volatile uint32 SYSDIV2LSB		:1;
	volatile uint32 SYSDIV2			:6;
	volatile uint32 Reserved4		:1;
	volatile uint32 DIV400			:1;
	volatile uint32 USERCC2			:1;
}RCC2_BF;


typedef union
{
	uint32		R;
	APINT_BF	B;
}RCC2_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SRAM_Memory_Base				0x20000000UL
#define SRAM_BitBand_Base				0x22000000UL
#define Peripherals_Base				0x40000000UL
#define Peripherals_BitBand_Base		0x42000000UL

#define CORTEXM4_Base					0xE000E000UL
#define SystemControl_Base				0x400FE000UL

#define GPIOA_Base						0x40058000UL
#define GPIOB_Base						0x40059000UL
#define GPIOC_Base						0x4005A000UL
#define GPIOD_Base						0x4005B000UL
#define GPIOE_Base						0x4005C000UL
#define GPIOF_Base						0x4005D000UL

#define GPIODATA_offset					0x000
#define GPIODIR_offset					0x400
#define GPIOIS_offset					0x404
#define GPIOIBE_offset					0x408
#define GPIOIEV_offset					0x40C
#define GPIOAFSEL_offset				0x420
#define GPIODR2R_offset					0x500
#define GPIODR4R_offset					0x504
#define GPIODR8R_offset					0x508
#define GPIOODR_offset					0x50C
#define GPIOPUR_offset					0x510
#define GPIOPDR_offset					0x514
#define GPIOSLR_offset					0x518
#define GPIODEN_offset					0x51C
#define GPIOLOCK_offset					0x520
#define GPIOAMSEL_offset				0x528
#define GPIOPCTL_offset					0x52C
#define GPIOADCCTL_offset				0x530
#define GPIODMACTL_offset				0x534

#define STCTRL_Base						(SystemControl_Base + 0x010)

#define WDT0_Base						0x40000000UL
#define WDT1_Base						0x40001000UL
#define PWM0_Base						0x40028000UL
#define PWM1_Base						0x40029000UL
#define Timer0_16_Base					0x40030000UL
#define Timer1_16_Base					0x40031000UL
#define Timer2_16_Base					0x40032000UL
#define Timer3_16_Base					0x40033000UL
#define Timer4_16_Base					0x40034000UL
#define Timer5_16_Base					0x40035000UL
#define Timer0_32_Base					0x40036000UL
#define Timer1_32_Base					0x40037000UL
#define Timer2_32_Base					0x4004C000UL
#define Timer3_32_Base					0x4004D000UL
#define Timer4_32_Base					0x4004E000UL
#define Timer5_32_Base					0x4004F000UL

#define GPTMCFG_offset					0x000
#define GPTMTAMR_offset					0x004
#define GPTMTBMR_offset					0x008
#define GPTMCTL_offset					0x00C
#define GPTMSYNC_offset					0x010
#define GPTMIMR_offset					0x018
#define GPTMICR_offset					0x024
#define GPTMTAILR_offset				0x028
#define GPTMTBILR_offset				0x02C
#define GPTMTAMATCHR_offset				0x030
#define GPTMTBMATCHR_offset				0x034
#define GPTMTAPR_offset					0x038
#define GPTMTBPR_offset					0x03C
#define GPTMTAPMR_offset				0x040
#define GPTMTBPMR_offset				0x044
#define GPTMTAV_offset					0x050
#define GPTMTBV_offset					0x054

#define APINT							*((volatile APINT_Tag *)(CORTEXM4_Base+0xD0C))
#define INTCTRL							*((volatile INTCTRL_Tag *)(CORTEXM4_Base+0xD04))
#define NVIC_EN0						*((volatile uint32 *)(CORTEXM4_Base+0x100))
#define NVIC_EN1						*((volatile uint32 *)(CORTEXM4_Base+0x104))
#define NVIC_EN2						*((volatile uint32 *)(CORTEXM4_Base+0x108))
#define NVIC_EN3						*((volatile uint32 *)(CORTEXM4_Base+0x10C))
#define NVIC_EN4						*((volatile uint32 *)(CORTEXM4_Base+0x110))
#define NVIC_PRI0						*((volatile uint32 *)(CORTEXM4_Base+0x400))
#define NVIC_PRI1						*((volatile uint32 *)(CORTEXM4_Base+0x404))
#define NVIC_PRI2						*((volatile uint32 *)(CORTEXM4_Base+0x408))
#define NVIC_PRI3						*((volatile uint32 *)(CORTEXM4_Base+0x40C))
#define NVIC_PRI4						*((volatile uint32 *)(CORTEXM4_Base+0x410))
#define NVIC_PRI5						*((volatile uint32 *)(CORTEXM4_Base+0x414))
#define NVIC_PRI6						*((volatile uint32 *)(CORTEXM4_Base+0x418))
#define NVIC_PRI7						*((volatile uint32 *)(CORTEXM4_Base+0x41C))
#define NVIC_PRI8						*((volatile uint32 *)(CORTEXM4_Base+0x420))
#define NVIC_PRI9						*((volatile uint32 *)(CORTEXM4_Base+0x424))
#define NVIC_PRI10						*((volatile uint32 *)(CORTEXM4_Base+0x428))
#define NVIC_PRI11						*((volatile uint32 *)(CORTEXM4_Base+0x42C))
#define NVIC_PRI12						*((volatile uint32 *)(CORTEXM4_Base+0x430))
#define NVIC_PRI13						*((volatile uint32 *)(CORTEXM4_Base+0x434))
#define NVIC_PRI14						*((volatile uint32 *)(CORTEXM4_Base+0x438))
#define NVIC_PRI15						*((volatile uint32 *)(CORTEXM4_Base+0x43C))
#define NVIC_PRI16						*((volatile uint32 *)(CORTEXM4_Base+0x440))
#define NVIC_PRI17						*((volatile uint32 *)(CORTEXM4_Base+0x444))
#define NVIC_PRI18						*((volatile uint32 *)(CORTEXM4_Base+0x448))
#define NVIC_PRI19						*((volatile uint32 *)(CORTEXM4_Base+0x44C))
#define NVIC_PRI20						*((volatile uint32 *)(CORTEXM4_Base+0x450))
#define NVIC_PRI21						*((volatile uint32 *)(CORTEXM4_Base+0x454))
#define NVIC_PRI22						*((volatile uint32 *)(CORTEXM4_Base+0x458))
#define NVIC_PRI23						*((volatile uint32 *)(CORTEXM4_Base+0x45C))
#define NVIC_PRI24						*((volatile uint32 *)(CORTEXM4_Base+0x460))
#define NVIC_PRI25						*((volatile uint32 *)(CORTEXM4_Base+0x464))
#define NVIC_PRI26						*((volatile uint32 *)(CORTEXM4_Base+0x468))
#define NVIC_PRI27						*((volatile uint32 *)(CORTEXM4_Base+0x46C))
#define NVIC_PRI28						*((volatile uint32 *)(CORTEXM4_Base+0x470))
#define NVIC_PRI29						*((volatile uint32 *)(CORTEXM4_Base+0x474))
#define NVIC_PRI30						*((volatile uint32 *)(CORTEXM4_Base+0x478))
#define NVIC_PRI31						*((volatile uint32 *)(CORTEXM4_Base+0x47C))
#define NVIC_PRI32						*((volatile uint32 *)(CORTEXM4_Base+0x480))
#define NVIC_PRI33						*((volatile uint32 *)(CORTEXM4_Base+0x484))
#define NVIC_PRI34						*((volatile uint32 *)(CORTEXM4_Base+0x488))

#define RCC								*((volatile RCC_Tag *)(SystemControl_Base + 0x060))
#define RCC2							*((volatile RCC2_Tag *)(SystemControl_Base + 0x070))
#define RCGCGPIO						*((volatile uint32 *)(SystemControl_Base + 0x608))
#define RCGC2							*((volatile uint32 *)(SystemControl_Base + 0x108))

#define STCTRL							*((volatile uint32 *)(CORTEXM4_Base + 0x010))
#define STRELOAD						*((volatile uint32 *)(CORTEXM4_Base + 0x014))
#define STCURRENT						*((volatile uint32 *)(CORTEXM4_Base + 0x018))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA							((GPIO_TypeDef *)GPIOA_Base)
#define GPIOB							((GPIO_TypeDef *)GPIOB_Base)
#define GPIOC							((GPIO_TypeDef *)GPIOC_Base)
#define GPIOD							((GPIO_TypeDef *)GPIOD_Base)
#define GPIOE							((GPIO_TypeDef *)GPIOE_Base)
#define GPIOF							((GPIO_TypeDef *)GPIOF_Base)
#define GPIO_PORTF_DATA_R 				*(( volatile unsigned long *)(GPIOF_Base + 0x3FC))

#define Timer0_16						((GPT_TypeDef *)Timer0_16_Base)
#define Timer1_16						((GPT_TypeDef *)Timer1_16_Base)
#define Timer2_16						((GPT_TypeDef *)Timer2_16_Base)
#define Timer3_16						((GPT_TypeDef *)Timer3_16_Base)
#define Timer4_16						((GPT_TypeDef *)Timer4_16_Base)
#define Timer5_16						((GPT_TypeDef *)Timer5_16_Base)
#define Timer0_32						((GPT_TypeDef *)Timer0_32_Base)
#define Timer1_32						((GPT_TypeDef *)Timer1_32_Base)
#define Timer2_32						((GPT_TypeDef *)Timer2_32_Base)
#define Timer3_32						((GPT_TypeDef *)Timer3_32_Base)
#define Timer4_32						((GPT_TypeDef *)Timer4_32_Base)
#define Timer5_32						((GPT_TypeDef *)Timer5_32_Base)

//===============================================================
//IRQ

//#define Timer0A_16_IRQ					35
//#define Timer0B_16_IRQ					36
//#define Timer1A_16_IRQ					37
//#define Timer1B_16_IRQ					38
//#define Timer2A_16_IRQ					39
//#define Timer2B_16_IRQ					40
//#define Timer3A_16_IRQ					51
//#define Timer3B_16_IRQ					52
//#define Timer4A_16_IRQ					86
//#define Timer4B_16_IRQ					87
//#define Timer5A_16_IRQ					108
//#define Timer5B_16_IRQ					109
//#define Timer0A_32_IRQ					110
//#define Timer0B_32_IRQ					111
//#define Timer1A_32_IRQ					112
//#define Timer1B_32_IRQ					113
//#define Timer2A_32_IRQ					114
//#define Timer2B_32_IRQ					115
//#define Timer3A_32_IRQ					116
//#define Timer3B_32_IRQ					117
//#define Timer4A_32_IRQ					118
//#define Timer4B_32_IRQ					119
//#define Timer5A_32_IRQ					120
//#define Timer5B_32_IRQ					121






/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA_CLK_EN()					*((uint8 *)(Peripherals_BitBand_Base + (0xFE608 * 32)+ (0*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE108 * 32)+ (0*4)))=0x0F
#define GPIOB_CLK_EN()					*((uint8 *)(Peripherals_BitBand_Base + (0xFE608 * 32)+ (1*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE108 * 32)+ (1*4)))=0x0F
#define GPIOC_CLK_EN()					*((uint8 *)(Peripherals_BitBand_Base + (0xFE608 * 32)+ (2*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE108 * 32)+ (2*4)))=0x0F
#define GPIOD_CLK_EN()					*((uint8 *)(Peripherals_BitBand_Base + (0xFE608 * 32)+ (3*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE108 * 32)+ (3*4)))=0x0F
#define GPIOE_CLK_EN()					*((uint8 *)(Peripherals_BitBand_Base + (0xFE608 * 32)+ (4*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE108 * 32)+ (4*4)))=0x0F
#define GPIOF_CLK_EN()					*((uint8 *)(Peripherals_BitBand_Base + (0xFE608 * 32)+ (5*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE108 * 32)+ (5*4)))=0x0F

#define GPTTimer16_0_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE604 * 32)+ (0*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE104 * 32)+ (16*4)))=0x0F
#define GPTTimer16_1_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE604 * 32)+ (1*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE104 * 32)+ (17*4)))=0x0F
#define GPTTimer16_2_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE604 * 32)+ (2*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE104 * 32)+ (18*4)))=0x0F
#define GPTTimer16_3_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE604 * 32)+ (3*4)))=0x0F//; *((uint8 *)(Peripherals_BitBand_Base + (0xFE104 * 32)+ (19*4)))=0x0F
#define GPTTimer16_4_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE604 * 32)+ (4*4)))=0x0F
#define GPTTimer16_5_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE604 * 32)+ (5*4)))=0x0F
#define GPTTimer32_0_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE65C * 32)+ (0*4)))=0x0F
#define GPTTimer32_1_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE65C * 32)+ (1*4)))=0x0F
#define GPTTimer32_2_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE65C * 32)+ (2*4)))=0x0F
#define GPTTimer32_3_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE65C * 32)+ (3*4)))=0x0F
#define GPTTimer32_4_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE65C * 32)+ (4*4)))=0x0F
#define GPTTimer32_5_CLK_EN()			*((uint8 *)(Peripherals_BitBand_Base + (0xFE65C * 32)+ (5*4)))=0x0F

#define Byte_Offset(GPIOx_Base, RegOffset)			GPIOx_Base - Peripherals_Base +RegOffset

#define Set_bit_GPIO(GPIOx_Base ,BitNum , RegOffset)			*((uint32 *)(Peripherals_BitBand_Base + ((Byte_Offset(GPIOx_Base , RegOffset)) *32 ) + (BitNum *4)))=0xF
#define Clear_bit_GPIO(GPIOx_Base ,BitNum , RegOffset)			*((uint32 *)(Peripherals_BitBand_Base + ((Byte_Offset(GPIOx_Base , RegOffset)) *32 ) + (BitNum *4)))=0x0
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPIO_init(void);

void GPT_SetConfig_init (void);

#endif /* SRC_COMMON_MCU_HW_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
