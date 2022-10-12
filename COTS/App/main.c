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

uint8 count_on =0,count_off =0 , SW1_pressed =0 , SW2_pressed =0;
void HW_Init (void);

int main(void)
{
	HW_Init ();
	
	while(1)
	{
		//SW1 --> PF4
		//SW2 --> PF0
		// initially on time is 100 ms and off time is 100 ms
		
		//every press on SW1 gets on time to increase by 100 ms and decreasing off time by 100 ms
		//if number of counts = 0 then pressing on the switch do nothing
		if (Dio_ReadChannel (Dio_PortF_PF4) && (!SW1_pressed))
		{
			if (((count_on <= 10)) )
				count_on ++;  //number of counts represents time in 100 ms 
				
			if (((count_off >0)) )
				count_off --;  //number of counts represents time in 100 ms
			
			SW1_pressed = 1;
		}
		if(!Dio_ReadChannel (Dio_PortF_PF4))
					SW1_pressed= 0;
				
	
		if (Dio_ReadChannel (Dio_PortF_PF0) && (!SW2_pressed))
		{
			if (((count_on > 0)) )
				count_on --;  //number of counts represents time in 100 ms 
				
			if (( (count_off <= 10)) )
				count_off ++;  //number of counts represents time in 100 ms
			
			SW2_pressed = 1;
		}
		if(!Dio_ReadChannel (Dio_PortF_PF0))
					SW2_pressed= 0;
		
		LedOnPWM_Period((uint32)(100 + count_on * 100) , (uint32)(100 + count_off * 100));
	}
}

void HW_Init (void)
{
	IntCtrl_Init();
	GPT_init();
	port_init();
	SysTick_init();
}
