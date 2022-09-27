/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*   FILE NAME					:  PORT_program.c
 *   BRIEF DESCRIPTION	:  Implementation of PORT_interface.h
 *   AUTHOR							:  Yasser Waleed  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM.h"
#include "PORT_interface.h"
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define	A	0
#define	B	1
#define	C	2
#define	D	3
#define	E	4
#define	F	5
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void PORT_Init(u8 Port_Num, u8 Pin_Num, Direction_t Direction, ResType_t ResType, Current_t Current)
{
	SYSCTL->RCGCGPIO |= (1<<Port_Num); while(!(SYSCTL->RCGCGPIO &= (1<<Port_Num)));
	if (Direction == OUTPUT)
	{
		switch(Port_Num)
		{
								//UNLOCK                	  //COMMIT											//DIRECTION                    //DIGITAL ENABLE 						    
			case A	:	GPIOA->LOCK = 0x4C4F434B;		GPIOA->CR |= (1<<Pin_Num);		GPIOA->DIR |= (1<<Pin_Num);    GPIOA->DEN |= (1<<Pin_Num);	  break;
			case B	:	GPIOB->LOCK = 0x4C4F434B;		GPIOB->CR |= (1<<Pin_Num);		GPIOB->DIR |= (1<<Pin_Num);    GPIOB->DEN |= (1<<Pin_Num);	  break;
			case C	:	GPIOC->LOCK = 0x4C4F434B;		GPIOC->CR |= (1<<Pin_Num);		GPIOC->DIR |= (1<<Pin_Num);    GPIOC->DEN |= (1<<Pin_Num);	  break;
			case D	:	GPIOD->LOCK = 0x4C4F434B;		GPIOD->CR |= (1<<Pin_Num);		GPIOD->DIR |= (1<<Pin_Num);    GPIOD->DEN |= (1<<Pin_Num);	  break;
			case E	:	GPIOE->LOCK = 0x4C4F434B;		GPIOE->CR |= (1<<Pin_Num);		GPIOE->DIR |= (1<<Pin_Num);    GPIOE->DEN |= (1<<Pin_Num);	  break;
			case F	:	GPIOF->LOCK = 0x4C4F434B;		GPIOF->CR |= (1<<Pin_Num);		GPIOF->DIR |= (1<<Pin_Num);    GPIOF->DEN |= (1<<Pin_Num);	  break;
		}                                    		                          		 	
	}                                      		                          		 	
	if (Direction == INPUT)                		                          		 	
	{                                      		                          		 	
		switch(Port_Num)                     		                          		 	
		{                                    		                          		        	
			case A	:	GPIOA->LOCK = 0x4C4F434B;		GPIOA->CR |= (1<<Pin_Num);		GPIOA->DIR &=~ (1<<Pin_Num);	 GPIOA->DEN |= (1<<Pin_Num);  break;
			case B	:	GPIOB->LOCK = 0x4C4F434B;		GPIOB->CR |= (1<<Pin_Num);		GPIOB->DIR &=~ (1<<Pin_Num);	 GPIOB->DEN |= (1<<Pin_Num);  break;
			case C	:	GPIOC->LOCK = 0x4C4F434B;		GPIOC->CR |= (1<<Pin_Num);		GPIOC->DIR &=~ (1<<Pin_Num);	 GPIOC->DEN |= (1<<Pin_Num);  break;
			case D	:	GPIOD->LOCK = 0x4C4F434B;		GPIOD->CR |= (1<<Pin_Num);		GPIOD->DIR &=~ (1<<Pin_Num);	 GPIOD->DEN |= (1<<Pin_Num);  break;
			case E	:	GPIOE->LOCK = 0x4C4F434B;		GPIOE->CR |= (1<<Pin_Num);		GPIOE->DIR &=~ (1<<Pin_Num);	 GPIOE->DEN |= (1<<Pin_Num);  break;
			case F	:	GPIOF->LOCK = 0x4C4F434B;		GPIOF->CR |= (1<<Pin_Num);		GPIOF->DIR &=~ (1<<Pin_Num);	 GPIOF->DEN |= (1<<Pin_Num);  break;
		}
	}
	//INTERNAL ATTACHMENT (PU/PD/OD)
	if (ResType == PULL_UP)
	{
		switch(Port_Num)
		{
			case A	:	GPIOA->PUR |= (1<<Pin_Num);	   
			case B	:	GPIOB->PUR |= (1<<Pin_Num);	   
			case C	:	GPIOC->PUR |= (1<<Pin_Num);	   
			case D	:	GPIOD->PUR |= (1<<Pin_Num);	   
			case E	:	GPIOE->PUR |= (1<<Pin_Num);	   
			case F	:	GPIOF->PUR |= (1<<Pin_Num);	
		}
	}
	if (ResType == PULL_DOWN)
	{
		switch(Port_Num)
		{
			case A	:	GPIOA->PDR |= (1<<Pin_Num);	   
			case B	:	GPIOB->PDR |= (1<<Pin_Num);	   
			case C	:	GPIOC->PDR |= (1<<Pin_Num);	   
			case D	:	GPIOD->PDR |= (1<<Pin_Num);	   
			case E	:	GPIOE->PDR |= (1<<Pin_Num);	   
			case F	:	GPIOF->PDR |= (1<<Pin_Num);	
		}
	}
	if (ResType == OPEN_DRAIN)
	{
		switch(Port_Num)
		{
			case A	:	GPIOA->ODR |= (1<<Pin_Num);	   
			case B	:	GPIOB->ODR |= (1<<Pin_Num);	   
			case C	:	GPIOC->ODR |= (1<<Pin_Num);	   
			case D	:	GPIOD->ODR |= (1<<Pin_Num);	   
			case E	:	GPIOE->ODR |= (1<<Pin_Num);	   
			case F	:	GPIOF->ODR |= (1<<Pin_Num);	
		}
	}
	//CURRENT DRIVE(MA IS 2/4/8)  
	if (Current == CUR_2MA)
	{
		switch(Port_Num)
		{
			case A	:	GPIOA->DR2R |= (1<<Pin_Num);	   
			case B	:	GPIOB->DR2R |= (1<<Pin_Num);	   
			case C	:	GPIOC->DR2R |= (1<<Pin_Num);	   
			case D	:	GPIOD->DR2R |= (1<<Pin_Num);	   
			case E	:	GPIOE->DR2R |= (1<<Pin_Num);	   
			case F	:	GPIOF->DR2R |= (1<<Pin_Num);	
		}
	}
	if (Current == CUR_4MA)
		{
		switch(Port_Num)
		{
			case A	:	GPIOA->DR4R |= (1<<Pin_Num);	   
			case B	:	GPIOB->DR4R |= (1<<Pin_Num);	   
			case C	:	GPIOC->DR4R |= (1<<Pin_Num);	   
			case D	:	GPIOD->DR4R |= (1<<Pin_Num);	   
			case E	:	GPIOE->DR4R |= (1<<Pin_Num);	   
			case F	:	GPIOF->DR4R |= (1<<Pin_Num);	
		}
	}
	if (Current == CUR_8MA)
	{
		switch(Port_Num)
		{
			case A	:	GPIOA->DR8R |= (1<<Pin_Num);	   
			case B	:	GPIOB->DR8R |= (1<<Pin_Num);	   
			case C	:	GPIOC->DR8R |= (1<<Pin_Num);	   
			case D	:	GPIOD->DR8R |= (1<<Pin_Num);	   
			case E	:	GPIOE->DR8R |= (1<<Pin_Num);	   
			case F	:	GPIOF->DR8R |= (1<<Pin_Num);	
		}
	}
}	

void PORT_TogglePin(u8 Port_Num, u8 Pin_Num)
{
	switch(Port_Num)
	{
		case A	:	GPIOA->DATA  ^= (1<<Pin_Num); break;
		case B	:	GPIOB->DATA  ^= (1<<Pin_Num); break;
		case C	:	GPIOC->DATA  ^= (1<<Pin_Num); break;
		case D	:	GPIOD->DATA  ^= (1<<Pin_Num); break;
		case E	:	GPIOE->DATA  ^= (1<<Pin_Num); break;
		case F	:	GPIOF->DATA  ^= (1<<Pin_Num); break;
  }	
}
u8 PORT_ReadPin(u8 Port_Num, u8 Pin_Num)
{
	switch(Port_Num)
	{
		case A	:	return ((GPIOA->DATA  & (1<<Pin_Num))>>Pin_Num); 
		case B	:	return ((GPIOB->DATA  & (1<<Pin_Num))>>Pin_Num); 
		case C	:	return ((GPIOC->DATA  & (1<<Pin_Num))>>Pin_Num); 
		case D	:	return ((GPIOD->DATA  & (1<<Pin_Num))>>Pin_Num); 
		case E	:	return ((GPIOE->DATA  & (1<<Pin_Num))>>Pin_Num); 
		case F	:	return ((GPIOF->DATA  & (1<<Pin_Num))>>Pin_Num); 
		default : return 2;
  }	
}
/**********************************************************************************************************************
 *  END OF FILE: PORT_program.c
 *********************************************************************************************************************/
