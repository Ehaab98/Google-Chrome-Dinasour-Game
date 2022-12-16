/*
 * funs.c
 *
 *  Created on: Dec 16, 2022
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
#include "funsPrivate.h"



/*A function used to move the dino from up to down or from down to up
 * using the variable dino row when "1: down" "0: Up" */
void Toggle_dino()
{
	TOGGLE_BIT(dino_row, 0);
}

/*This function to see the condition of dino and switch it from standing to kneeling and vice versa as long as the button pressed
 * then draw on the screen the three different states of him while running*/
void Switch_dino()
{
	if (dino_cond == up)
	{
		dino_cond = down;
		LCD_SendSpecialChar(Dino_2LegDown,0);
		LCD_SendSpecialChar(Dino_LeftLegDown,1);
		LCD_SendSpecialChar(Dino_RightLegDown,2);
	}
	else
	{
		dino_cond = up;
		LCD_SendSpecialChar(Dino_2Leg,0);
		LCD_SendSpecialChar(Dino_LeftLeg,1);
		LCD_SendSpecialChar(Dino_RightLeg,2);

	}
}


void SendToCGRom(void)
{
	/*Sending the drawings of the dino to the LCD CGROM*/
	LCD_SendSpecialChar(Dino_2Leg,0);
	LCD_SendSpecialChar(Dino_LeftLeg,1);
	LCD_SendSpecialChar(Dino_RightLeg,2);
	LCD_SendSpecialChar(Cactus_Big,3);
	LCD_SendSpecialChar(Cactus_Big2,4);
	LCD_SendSpecialChar(Cactus_Small,5);
	LCD_SendSpecialChar(Bird_Down,6);
	LCD_SendSpecialChar(Bird_Up,7);

}

/*A function used to switch between the three states of dino while running in the normal case eg: no button pressed*/
void DrawDino(void)
{
	din_num ++;
	if(din_num == 3)
	{
		din_num = 0;
	}
}

/*This is the function that display the game
 * Every line of code will be explained in the function*/
void draw_cactus(void)
{

	/*First we need to make random variable to display random shapes of cactus or birds and also display 2 or 1 cactus on screen*/
	u8 random_cactus = 3 + rand()%5;
	u8 random_cactus2 = 3 + rand()%5;
	/*This variable used to display the cactus on a random position on the screen*/
	u8 random_position = rand()%9;
	/**/
	s8 CactusIndex2;
	u8 cactus1_row = 1;
	u8 cactus2_row = 1;

	/*show if the random drawing brings bird then the space between the first one and second more than 4 spaces*/
	if(random_cactus > 5 || random_cactus2 > 5)
	{
		random_position = 4 + rand()%5;
	}

	/*if the first object to be drawn is bird down then make the row of drawing is down*/
	if(random_cactus == 7)
	{
		cactus1_row = 0;
	}
	/*if the second object to be drawn is bird down then make the row of drawing is down*/
	if(random_cactus2 == 7)
	{
		cactus2_row = 0;
	}

	/*loop for drawing cactus and birds from the right of the screen to the left
	 * and leaving 4 spaces at the right most of the screen to display score*/
	for(u8 i = 12; i > 0; i-- )
	{
		LCD_Clear();



		/*Print the second cactus at a random position from the first one by leaving a suitable space*/
		CactusIndex2 = (s8)i-(s8)random_position;
		/*Print the first cactus with random shape from the right most of screen to the left*/
		LCD_VidCursorPosition(cactus1_row,i);
		LCD_VidSendData(random_cactus);


		if(CactusIndex2 >= 0)
		{
			LCD_VidCursorPosition(cactus2_row,CactusIndex2);
			LCD_VidSendData(random_cactus2);
		}

		/*Print dino on screen*/
		LCD_VidCursorPosition(dino_row,0);
		LCD_VidSendData(din_num);

		/*Displaying the score at the right most of the screen*/
		LCD_VidCursorPosition(0,13);
		LCD_VidSendnum(Score);
		LCD_VidCursorPosition(1,13);
		LCD_VidSendnum(SubScore);
		Score++;
		if(Score == 999)
		{
			Score = 0;
			SubScore ++;
		}

		/*Game Over States*/

		/*For Cactus 1
		 * if there is cactus and the dino in the lower row
		 * if there is a bird down and the dino is in the lower row and standing
		 * if there is a bird up and the dino is in the upper row
		 */
		if(random_cactus < 6 )
		{
			if(i == 1 && dino_row == 1)
			{
				game_over = 1;
			}
		}
		else if(random_cactus == 6)
		{
			if(i == 1 && dino_row == 1 && dino_cond == up)
			{
				game_over = 1;
			}
		}
		else if(random_cactus == 7)
		{
			if(i == 1 && dino_row == 0)
			{
				game_over = 1;
			}
		}

		/*For Cactus 1
		* if there is cactus and the dino in the lower row
		* if there is a bird down and the dino is in the lower row and standing
		* if there is a bird up and the dino is in the upper row
		*/
		if(random_cactus2 < 6 )
		{
			if(CactusIndex2 == 1 && dino_row == 1)
			{
				game_over = 1;
				break;
			}
		}
		else if(random_cactus2 == 6)
		{
			if(CactusIndex2 == 1 && dino_row == 1 && dino_cond == up)
			{
				game_over = 1;
				break;
			}
		}
		else if(random_cactus2 == 7)
		{
			if(CactusIndex2 == 1 && dino_row == 0)
			{
				game_over = 1;
				break;
			}
		}

		_delay_ms(200);
	}

}

void StartGame(void)
{
	/*The opening of the screen to start the game*/
	LCD_VidCursorPosition(0,3);
	LCD_VidSendString("Welcome in");
	LCD_VidCursorPosition(1,3);
	LCD_VidSendString("Dino Game");
	_delay_ms(2000);


	while(game_over == 0)
	{
		/*Call the function that responsible for the algorithm of the game*/
		draw_cactus();
	}
	/*Displaying score after game is over*/
	LCD_Clear();
	Total_Score = ((SubScore-1)*1000) + Score;
	LCD_VidCursorPosition(0,3);
	LCD_VidSendString("Game Over");
	LCD_VidCursorPosition(1,3);
	LCD_VidSendString("Score: ");
	LCD_VidSendnum(Total_Score);
}
