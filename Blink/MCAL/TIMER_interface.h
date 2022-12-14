/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *   FILE NAME					:  TIMER_interface.h
 *   AUTHOR							:  Yasser Waleed       
 *********************************************************************************************************************/
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CLOCK_FREQUENCY 16000000
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {SYSCLOCK, PIOSC}	ClockSource_t;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void TIMER_Init(ClockSource_t Clock_Source);
/**********************************************************************************************************************
 *  END OF FILE: TIMER_interface.h
 *********************************************************************************************************************/
#endif
