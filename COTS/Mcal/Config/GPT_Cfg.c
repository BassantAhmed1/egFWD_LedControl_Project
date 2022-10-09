/*
 * GPT_Cfg.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Bassant Ahmed
 */

#include "../../Common/Mcu_Hw.h"
#include "../Inc/TM4C123GH6PM_GPT.h"

GPT_ConfigType GPT_Config = {
		Timer0_32_,
		WT0CCP0_PortC_PC4,
		GPT_Freq_Define,
		4000000,
		GPT_ChannelMode_OneShot,
		0
};


