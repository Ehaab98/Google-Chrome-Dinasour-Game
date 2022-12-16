/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: moham
 */

#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include"LCD_Interface.h"
#include "LCD_Cfg.h"
#include "Timer_Interface.h"
#include "Timer_Cfg.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "EInterput_Interface.h"
#include "EInterupt_Cfg.h"
#include <stdlib.h>
#include "funs.h"



int main (void)
{

	/*Initialize LCD*/
	LCD_VidLCDInit();
	/*Delete cursor from screen*/
	LCD_VidSendCommand(0b00001100);

	/*Enable global interrupt*/
	GIE_VidEnable();



	/*Make the pins of interrupt 1 as input pins*/
	DIO_VidSetPinDirection(3, 3, 0);
	DIO_VidSetPinValue(3, 3, 1);

	/*Make the pins of interrupt 0 as input pins*/
	DIO_VidSetPinDirection(3, 2, 0);
	DIO_VidSetPinValue(3, 2, 1);

	/*Enable external interrupt 1*/
	EInterupt1_VidEnable();
	/*Set the interrupt to be on change to make dino in his case as long as the button is pressed */
	EInt1_VidSenseControl();

	/*Enable external interrupt 1*/
	EInterupt0_VidEnable();
	/*Set the interrupt to be on change to make dino in his case as long as the button is pressed */
	EInt0_VidSenseControl();



	/*Initialize Timer 0*/
	Timer_VidInit();



	/*make the switch connected to interrupt 1 switch the dino from standing to kneeing*/
	INT1_setCallBack(&Switch_dino);
	/*make the switch connected to interrupt 0 switch the dino from lower row to the upper row*/
	INT0_setCallBack(&Toggle_dino);

	/*Make the dino switch his leg while running every 200ms*/
	Timer_setCallBack(DrawDino, 200);


	SendToCGRom();

	StartGame();





	while(1)
	{

	}
}


