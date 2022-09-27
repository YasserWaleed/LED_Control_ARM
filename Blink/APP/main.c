/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*   FILE NAME					:  main.c
 *   BRIEF DESCRIPTION	:  Blink LED on Port & Pin specified by user, for ON & OFF durations specified by user 
 *   AUTHOR							:  Yasser Waleed  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../HAL/LED_interface.h"
#include "../HAL/Switch_interface.h"
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
*  LOCAL CONSTANT MACROS\FUNCTION PROTOTYPES
*********************************************************************************************************************/
void On_Duration_Update (u8);
void Off_Duration_Update(u8);
#define OFF 0 
#define ON  1
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/				
const u8 Red_LED_Port   = F, Red_LED_Pin    = 1;
const u8 Blue_LED_Port  = F, Blue_LED_Pin   = 2;
const u8 Green_LED_Port = F, Green_LED_Pin  = 3;

const u8 Switch_1_Port  = F, Switch_1_Pin   = 4;
const u8 Switch_2_Port  = F, Switch_2_Pin   = 0;

u8 Seconds_ON  = 1;
u8 Seconds_OFF = 1;

u8 press1 = 0, press2 = 0, hold1 = 0, hold2 = 0;
u64 long_press1 = 0, long_press2 = 0;

static u8  On_Off_Flag 			= OFF;
static u16 Last_Switch			= 0;
static u16 Seconds_Count		= 0;
/**********************************************************************************************************************
 *  MAIN FUNCTIONS
 *********************************************************************************************************************/
int main()
{
	LED_Init(Green_LED_Port, Green_LED_Pin);
	Switch_Init(Switch_1_Port, Switch_1_Pin);
	Switch_Init(Switch_2_Port, Switch_2_Pin);
	while (1)
	{
		On_Duration_Update  ( Switch_Read(Switch_1_Port, Switch_1_Pin) );
		Off_Duration_Update ( Switch_Read(Switch_2_Port, Switch_2_Pin) );
	}
	
}

void SysTick_Handler(void)
{
	Seconds_Count++;
	if (On_Off_Flag == ON)
	{
		if ((Seconds_Count - Last_Switch) == Seconds_ON){LED_Toggle(Green_LED_Port, Green_LED_Pin); On_Off_Flag = OFF; Last_Switch = Seconds_Count;}
	}
	else if(On_Off_Flag == OFF)
	{
		if ((Seconds_Count - Last_Switch) == Seconds_OFF){LED_Toggle(Green_LED_Port, Green_LED_Pin);	On_Off_Flag = ON; Last_Switch = Seconds_Count;}
	}
	
}
void On_Duration_Update (u8 Switch1_State)
{
	//SWITCH 1 MONITORING INSTRUCTIONS
	if(Switch1_State== 0 && press1 == 0 && hold1 == 0) {Seconds_ON++; press1 = 1;}
	else if (Switch1_State == 0 && press1 == 1 && hold1 == 0) {hold1 = 1;}
	else if (Switch1_State == 0 && press1 == 1 && hold1 == 1) 
	{
		long_press1++;
		if (long_press1 >= 500000)	{Seconds_ON = 1; long_press1 = 0; Seconds_Count = 0;}
	}
	else if (Switch1_State == 1 && press1 == 1 && hold1 == 1) {hold1 = 0; press1 = 0;	long_press1 = 0;}
}
void Off_Duration_Update (u8 Switch2_State)
{
	//SWITCH 2 MONITORING INSTRUCTIONS
	if (Switch2_State == 0 && press2 == 0 && hold2 == 0) {Seconds_OFF++; press2 = 1;}
	else if (Switch2_State == 0 && press2 == 1 && hold2 == 0) {hold2 = 1;}
	else if (Switch2_State == 0 && press2 == 1 && hold2 == 1)
	{
		long_press2++;
		if (long_press2 >= 500000)	{Seconds_OFF = 1;	long_press2 = 0; Seconds_Count = 0;}
	}
	else if (Switch2_State == 1 && press2 == 1 && hold2 == 1) {hold2 = 0; press2 = 0;	long_press2 = 0;}
}
/**********************************************************************************************************************
 *  END OF FILE: main.c
 *********************************************************************************************************************/
