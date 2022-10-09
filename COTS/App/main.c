/*
 * main.c
 *
 *  Created on: Aug 18, 2022
 *      Author: Bassant Ahmed
 */


#include "../Mcal/Inc/TM4C123GH6PM_GPIO.h"
#include "../Mcal/Inc/TM4C123GH6PM_GPT.h"
#include "../Common/Mcu_Hw.h"
#include "../Mcal/Config/IntCtrl_Cfg.h"
#include "../Mcal/Inc/IntCtrl.h"
#include "../Mcal/Inc/IntCtrl_Types.h"
#include "../Mcal/Inc/TM4c123GH6PM_SysTick.h"
#include "../Hal/LED.h"


void HW_Init (void);

int main(void)
{
	HW_Init ();
	int count_on =0,count_off =0 , pressed =0;
	while(1)
	{
		//Pressing PA0 means that every press on PA1 is a count
		//after releasing PA0 Led_On time will be number of counts *100 ms
		while (Dio_ReadChannel (Dio_PortA_PA0))
		{
				if(Dio_ReadChannel (Dio_PortA_PA1) && (!pressed))
				{
					count_on ++;  //number of counts represents time in 100 ms 
					pressed = 1;
				}
				if(!Dio_ReadChannel (Dio_PortA_PA1))
					pressed= 0;
		}
		pressed= 0;
		
		//Pressing PA2 means that every press on PA3 is a count
		//after releasing PA2 Led_Off time will be number of counts *100 ms
		while (Dio_ReadChannel (Dio_PortA_PA2))
		{
				if(Dio_ReadChannel (Dio_PortA_PA3) && (!pressed))
				{
					count_off ++;  //number of counts represents time in 100 ms 
					pressed = 1;
				}
				if(!Dio_ReadChannel (Dio_PortA_PA3))
					pressed= 0;
		}
		pressed= 0;
		//after adjusting the on and off time, pressing on PB0 starts the led periods 
		//and after releasing PB0 it starts to take the counts again from the user
		if (count_on && count_off)
		{
			if(Dio_ReadChannel (Dio_PortB_PB0) && (!pressed))
			{
				pressed = 1;
				while (Dio_ReadChannel (Dio_PortB_PB0))
					LedOnPWM_Period((uint32)(count_on * 100) , (uint32)(count_off * 100));
			}
			if(!Dio_ReadChannel (Dio_PortA_PA3) && pressed)
			{
				pressed= 0;
				count_on =0;
				count_off =0;
			}
		}
	}
}


void HW_Init (void)
{
	IntCtrl_Init();
	GPT_init();
	port_init();
	SysTick_init();
}
