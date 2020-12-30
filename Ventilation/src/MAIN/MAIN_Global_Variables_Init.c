/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : MAIN_Global_Variables_Init.c                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C       It is the initialization  of global variables which can't 			*/
/*%C		be initialized during their declarations, because it is structures   */
/*%C     and arrays which need loop structure (loop "for").                   */
/******************************************************************************/
/*%I Input Parameter :  NONE                                                  */
/*%IO Input/Output :    NONE	                                                */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/
//
//#ifndef _TASKING
//#include "LH_ST10F276.h"
//#include <intrins.h>
//#else
//#include "regf276e.h"
//#endif
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../GENERAL/io_declare.h"
#include "../GENERAL/define.h"
#include "../DATABASE/DB_Config.h"
#include "../DATABASE/DB_AlarmStatus.h"
#include "MAIN_Global_Variables_Init.h"
#include "Main_Data.h"
	#define DECLARATION_SYSTEM_DATAS
#include "../DATABASE/DB_Event.h"
#include "../SYSTEM/System_Datas.h"
	#define DECLARATION_TIMER_DATA
#include "../TIMERS/Timer_Data.h"
	#define DECLARATION_EEPROM_DATA
//#include "../EEPROM/Eeprom_Data.h"
	#define DECLARATION_DISPLAY_DATA
#include "../DISPLAY/Display_Data.h"

#if 0
	#define DECLARATION_FLASH_DATA
#include "../DRIVERS_FLASH_EVENT/Flash_Event_Data.h"
	#define DECLARATION_RTC_DRIVER_DATA
#include "../DRIVERS_RTC/RTC_Driver_Data.h"
#include "../DRIVERS_SPI/DRV_SPI_POWER_Data.h"
#endif
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/


void MAIN_Global_Variables_Init(void)
{

	UWORD16 i = 0;
/******************************************************************************/
/* 								RTC FIFO Initialization 									*/
/* The variables below are initialized at their declaration */
/* in RTC_Driver_Data.h	 */
/*	RTC_FIFO_IdxPush = 0;		*/
/*	RTC_FIFO_IdxPull = 0;		 */
/*	RTC_FIFO_NbDataInFifo = 0;	  */		

#if 0 //commented by bhavya (driver function)
/*%C	Initialization of special variables RTC_FIFO_AccessDriver    */
	for (i=0;i<SIZE_OF_FIFO_RTC_ACCESS;i++)
	{
		RTC_FIFO_AccessDriver[i].ptr_data = NULL;
		RTC_FIFO_AccessDriver[i].regist = RTC_SECOND;
		RTC_FIFO_AccessDriver[i].state = FREE_RTC;		 
	}
	
#endif
/******************************************************************************/
/*  								EEPROM FIFO Initialization 								*/
/* The variables below are initialized at their declaration */
/* in EEPROM_Data.h	 */
/*	EEP_FIFO_IdxPush = 0;*/
/*	EEP_FIFO_IdxPull = 0;*/
/*	EEP_FIFO_NbDataInFifo = 0;	 */

/*%C	Initialization of special variables EEP_FIFO_AccessDriver    */

#if 0 //commented by bhavya(driver function)
	for (i=0;i<SIZE_OF_FIFO_EEP_ACCESS;i++)
	{
		EEP_FIFO_AccessDriver[i].state = FREE_EEP;
		EEP_FIFO_AccessDriver[i].ptr_DataRam = NULL;
	}	  		  
#endif
/******************************************************************************/
/*               			TIMER variables initialization 								*/


/*  Init Counters	< minute	 */
	for(i=0; i<end_of_table_cnt_decnt; i++)
	{
	TIM_TableOfCntAndDecnt[i].value = 0;
	TIM_TableOfCntAndDecnt[i].type = 0;
	TIM_TableOfCntAndDecnt[i].activate = FALSE;
	}

/*  Init Counters	> minute */
	for(i=0; i<end_of_minute_table_cnt_decnt; i++)
	{
	TIM_MinuteTableOfCntAndDecnt[i].value = 0;
	TIM_MinuteTableOfCntAndDecnt[i].type = 0;
	TIM_MinuteTableOfCntAndDecnt[i].activate = FALSE;
	TIM_MinuteTableOfCntAndDecnt[i].autoreload = FALSE;
	TIM_MinuteTableOfCntAndDecnt[i].autovalue = 0;
	}

																										  
/* Output reset 				*/
	KEY_PORT |= RAZ_COM;

	SYS_MutexStartStopVentilUP = FALSE;

/* External variable initalization			 				*/
	for(i=KEY_NO_KEYBOARD; i<Number_of_key; i++)
	{
	SYS_Num_Keyboard[i].level = FALSE;
	SYS_Num_Keyboard[i].PulseTime = 0;
	SYS_Num_Keyboard[i].debounceDetected = 0;
	SYS_Num_Keyboard[i].debounceCanceled = 0;
	SYS_Num_Keyboard[i].pulse = FALSE;
	SYS_Num_Keyboard[i].level = FALSE;
	SYS_Num_Keyboard[i].autorization = FALSE;
	SYS_Num_Keyboard[i].EventLongPush = FALSE;
	SYS_Num_Keyboard[i].MutexLongPush = FALSE;
	SYS_Num_Keyboard[i].TimerLongPush = SYS_InitTimerKey[i];
	SYS_Num_Keyboard[i].AutoRepeatPush = FALSE;
	SYS_Num_Keyboard[i].AutoRepeatSelected = FALSE;
	SYS_Num_Keyboard[i].MutexAutoRepeatPush = FALSE;
	}
	MAIN_TopTimer5ms = FALSE;

/*%C Enable Turbine */
	ENABLE_TURB = TRUE;


}
