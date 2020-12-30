/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: enum.h	 	   				   					               		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C Functionnal description : 	I/O declaration      								*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter : 			None		       			                  	*/
/*%IO Input/Output Parameter :   None                                		  	*/
/*%O 	Output Parameter : 			None     	                				  		*/
/******************************************************************************/
#ifndef IO_DECLARE_H	/* mono inclusion */
#define IO_DECLARE_H

#include "typedef.h"
#include "io_stubs.h"
#define sfr unsigned int			// manoj
#define sbit int			// manoj

/************************************************************************/
/*                         ENUM DECLARATION    	                		*/
/************************************************************************/


/************************************************************************/
/*                       STRUCTURE DECLARATION     	               		*/
/************************************************************************/

#ifndef _BORLAND
/************************************************************************/
/*                   EXTERNAL CONSTANT DECLARATION                     	*/
/************************************************************************/
#define FCPU 40 //MHz


/************************************************************************/
/*                   EXTERNAL VARIABLE DECLARATION                    	*/
/************************************************************************/
/* Io Declare pour Keil									*/

//#ifndef _TASKING
//#include "LH_ST10F276.h"
/*----------------------------------------------------------------------*/
/* Pilotage  de la turbine	par PWM													*/
/*----------------------------------------------------------------------*/
sfr BLOWER_CMD = 0xFE30; //platform specific manoj
sbit CONS_VIT =		P7_0;	//
sbit DEF_TURB = 	P2_2;		//
sbit ENABLE_TURB = P2_3;		//
sbit BRAKE_BLOWER = P2_1;		//
sbit SPEED_BLOWER_PIN = P2_0;	//
 
/*----------------------------------------------------------------------*/
/* Variable de pilotage de la valve par PWM										*/
/*----------------------------------------------------------------------*/
sfr   VALVE_CMD      = 0xFE32;
sbit CD_VALVE 	=	P7_1;

/*----------------------------------------------------------------------*/
/* Pilotage direct de la Vanne O2 par le port									*/
/*----------------------------------------------------------------------*/
sfr   VANNE_O2_CMD   = 0xFE34;	 
sbit CD_VANNE_FIO2 =	P7_2;

/*----------------------------------------------------------------------*/
/* Acitvation du Buzzer																	*/
/*----------------------------------------------------------------------*/
sfr	PWM_BUZ			= 0xFE36; 
sfr 	FREQ_BUZ			= 0xF03E;  

/*----------------------------------------------------------------------*/
/* Alim Failure																			*/
/*----------------------------------------------------------------------*/
sbit ALIM_FAILURE_3_3V  =	P2_5;
sbit ALIM_FAILURE_5VREF  =	P2_6;
sbit ALIM_FAILURE_10VREF  =	P2_7;

/*----------------------------------------------------------------------*/
/* USB declaration																		*/
/*----------------------------------------------------------------------*/
sbit USB_BUSY = 	P2_10;
sbit RESET_USB =  	P3_5;

/*----------------------------------------------------------------------*/
/* REMOTE ALARM STATE																	*/
/*----------------------------------------------------------------------*/
sbit ALARM_REMOTE_STATE =	P2_12;
sbit RAPPEL_ALARM =	P2_14;

/*----------------------------------------------------------------------*/
/* WATCHDOG																					*/
/*----------------------------------------------------------------------*/
sbit WDOG =	P2_4;

/*----------------------------------------------------------------------*/
/* ARRET INVOLONTAIRE																	*/
/*----------------------------------------------------------------------*/
sbit ARRET_INVOLONTAIRE =	P2_13;

/*----------------------------------------------------------------------*/
/* Flash        																			*/
/*----------------------------------------------------------------------*/
sbit BUSY_MEM1  	= P2_8;
sbit BUSY_MEM2 	= P2_9;
sbit CMD_ME1  	=	P2_15;
sbit ALE_ME1  	=	P3_15;

/*----------------------------------------------------------------------*/
/* RAM	        																			*/
/*----------------------------------------------------------------------*/
sbit BHE  =	P3_12;

/*----------------------------------------------------------------------*/
/* UART																						*/
/*----------------------------------------------------------------------*/
sbit RF  	=	P3_7;
sbit IRQ_UART = P8_5;

/*----------------------------------------------------------------------*/
/* UART ST																					*/
/*----------------------------------------------------------------------*/
sbit TX_UART_ST = P3_10;
sbit RX_UART_ST = P3_11;

/*----------------------------------------------------------------------*/
/* Driver SPI																				*/
/*----------------------------------------------------------------------*/

sbit MRST_SPI_ALIM  =	P6_7;
sbit MTSR_SPI_ALIM  =	P6_6;
sbit CLK_SPI_ALIM   =	P6_5;

sbit MRST_SPI_CPU  =	P3_8;
sbit MTSR_SPI_CPU  =	P3_9;
sbit SCLK_SPI_CPU  =	P3_13;

#define SPI_PORT  	P3

/*%C RAZ Chip Enable barred */
#define RAZ_CEb_SPI		0xFFEF
/*%C RAZ Chip Enable */
#define RAZ_CE_SPI		0x1DE8


/*----------------------------------------------------------------------*/
/* Device Identification																*/
/*----------------------------------------------------------------------*/
sbit JUMPER_JP8 = P8_2;
sbit JUMPER_JP7 = P8_3;

/*----------------------------------------------------------------------*/
/* Buzzer 																					*/
/*----------------------------------------------------------------------*/
sbit SEC_BUZ =	P7_5;

/*----------------------------------------------------------------------*/
/* Afficheur																				*/
/*----------------------------------------------------------------------*/
sbit MASTERBUSY =	P2_11;

/*----------------------------------------------------------------------*/
/* Keyboard + LEDs																		*/
/*----------------------------------------------------------------------*/
#define  KEY_PORT  		P3 	 // Port 3
sbit INHIB_DETECTED 	=	P3_6;

#define RAZ_COM      		0x0007 // RAZ des COM1, 2 et 3
#define COM1         	  	0xFFFE // P3^0
#define COM2        			0xFFFD // P3^1
#define COM3      			0xFFFB // P3^2
#define TOUCHE_1      		0x0008 // P3^3
#define TOUCHE_2     		0x0010 // P3^4
#define TOUCHE_INHIB   		0x0040 // P3^6

sbit LED_ALARME_ROUGE  =	P7_7;
sbit LED_ALARME_ORANGE =	P7_6;

sbit AC_SELECT 	=		P8_0;
sbit DC_SELECT 	=		P8_1;







#else


/* Io Declare pour Tasking									*/
/*----------------------------------------------------------------------*/
/* Pilotage  de la turbine	par PWM													*/
/*----------------------------------------------------------------------*/
#define BLOWER_CMD 	PW0
#define CONS_VIT 		P7_0
#define DEF_TURB  	P2_2
#define ENABLE_TURB  P2_3
#define BRAKE_BLOWER P2_1
#define SPEED_BLOWER_PIN  P2_0
/*----------------------------------------------------------------------*/
/* Variable de pilotage de la valve par PWM										*/
/*----------------------------------------------------------------------*/
#define VALVE_CMD 	PW1
#define CD_VALVE 		P7_1

/*----------------------------------------------------------------------*/
/* Pilotage direct de la Vanne O2 par le port									*/
/*----------------------------------------------------------------------*/
#define VANNE_O2_CMD PW2 	 
#define CD_VANNE_FIO2 	P7_2

/*----------------------------------------------------------------------*/
/* Acitvation du Buzzer																	*/
/*----------------------------------------------------------------------*/
#define PWM_BUZ 	PW3 
#define FREQ_BUZ 	PP3   

/*----------------------------------------------------------------------*/
/* Alim Failure																			*/
/*----------------------------------------------------------------------*/
#define ALIM_FAILURE_3_3V  	P2_5
#define ALIM_FAILURE_5VREF  	P2_6
#define ALIM_FAILURE_10VREF  	P2_7

/*----------------------------------------------------------------------*/
/* USB declaration																		*/
/*----------------------------------------------------------------------*/
#define USB_BUSY  	P2_10
#define RESET_USB  	P3_5

/*----------------------------------------------------------------------*/
/* REMOTE ALARM STATE																	*/
/*----------------------------------------------------------------------*/
#define ALARM_REMOTE_STATE 	P2_12
#define RAPPEL_ALARM 	P2_14 	

/*----------------------------------------------------------------------*/
/* WATCHDOG																					*/
/*----------------------------------------------------------------------*/
#define WDOG 	P2_4

/*----------------------------------------------------------------------*/
/* ARRET INVOLONTAIRE																	*/
/*----------------------------------------------------------------------*/
#define ARRET_INVOLONTAIRE 	P2_13

/*----------------------------------------------------------------------*/
/* Flash        																			*/
/*----------------------------------------------------------------------*/
#define BUSY_MEM1  	P2_8
#define BUSY_MEM2 	P2_9
#define CMD_ME1  		P2_15
#define ALE_ME1  		P3_15

/*----------------------------------------------------------------------*/
/* RAM	        																			*/
/*----------------------------------------------------------------------*/
#define BHE  	P3_12

/*----------------------------------------------------------------------*/
/* UART																						*/
/*----------------------------------------------------------------------*/
#define RF  		P3_7
#define IRQ_UART  P8_5

/*----------------------------------------------------------------------*/
/* UART ST																					*/
/*----------------------------------------------------------------------*/
#define TX_UART_ST  P3_10
#define RX_UART_ST  P3_11

/*----------------------------------------------------------------------*/
/* Driver SPI																				*/
/*----------------------------------------------------------------------*/

#define MRST_SPI_ALIM  	P6_7
#define MTSR_SPI_ALIM  	P6_6
#define CLK_SPI_ALIM   	P6_5

#define MRST_SPI_CPU  	P3_8
#define MTSR_SPI_CPU  	P3_9
#define SCLK_SPI_CPU  	P3_13

#define SPI_PORT  		P3

/*%C RAZ Chip Enable barred */
#define RAZ_CEb_SPI		0xFFEF
/*%C RAZ Chip Enable */
#define RAZ_CE_SPI		0x1DE8

/*----------------------------------------------------------------------*/
/* Device Identification																*/
/*----------------------------------------------------------------------*/
#define JUMPER_JP8  P8_2
#define JUMPER_JP7  P8_3

/*----------------------------------------------------------------------*/
/* Buzzer 																					*/
/*----------------------------------------------------------------------*/
#define SEC_BUZ 	P7_5

/*----------------------------------------------------------------------*/
/* Afficheur																				*/
/*----------------------------------------------------------------------*/
#define MASTERBUSY 	P2_11

/*----------------------------------------------------------------------*/
/* Keyboard + LEDs																		*/
/*----------------------------------------------------------------------*/
#define KEY_PORT  			P3 	 // Port 3
#define INHIB_DETECTED 		P3_6

#define RAZ_COM      		0x0007 // RAZ des COM1, 2 et 3
#define COM1         	  	0xFFFE // P3^0
#define COM2        			0xFFFD // P3^1
#define COM3      			0xFFFB // P3^2
#define TOUCHE_1      		0x0008 // P3^3
#define TOUCHE_2     		0x0010 // P3^4
#define TOUCHE_INHIB   		0x0040 // P3^6

#define LED_ALARME_ROUGE  	P7_7
#define LED_ALARME_ORANGE 	P7_6

#define AC_SELECT 			P8_0
#define DC_SELECT 			P8_1
#endif


#endif /* #ifndef _BORLAND */
/************************************************************************/
//#endif
