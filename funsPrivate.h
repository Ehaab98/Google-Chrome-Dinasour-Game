/*
 * funsPrivate.h
 *
 *  Created on: Dec 16, 2022
 *      Author: moham
 */

#ifndef FUNSPRIVATE_H_
#define FUNSPRIVATE_H_



#define up 0
#define down 1


/*Some Global Variables used to specify the status of dino and the cactus*/

u8 dino_row =1;
u8 din_num = 0;
u8 cactus_column;
u8 dino_cond = up;

u32 Score = 1;
u32 SubScore = 1;
u32 Total_Score = 0;
u8 game_over = 0;


/*Arrays that contain the drawing of objects on the lcd*/

u8 Dino_2Leg [8] = {(0b00000011),
			(0b00010011),
			(0b00010010),
			(0b00011110),
			(0b00011110),
			(0b00011110),
			(0b00001010),
			(0b00000000),

								};

	u8 Dino_LeftLeg [8] = {(0b00000011),
			(0b00010011),
			(0b00010010),
			(0b00011110),
			(0b00011110),
			(0b00011110),
			(0b00001000),
			(0b00000000),


									};
	u8 Dino_RightLeg [8] = {(0b00000011),
			(0b00010011),
			(0b00010010),
			(0b00011110),
			(0b00011110),
			(0b00011110),
			(0b00000010),
			(0b00000000),


									};

	u8 Dino_2LegDown [8] = {(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00010011),
			(0b00011111),
			(0b00011110),
			(0b00001010),


									};
	u8 Dino_LeftLegDown [8] = {(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00010011),
			(0b00011111),
			(0b00011110),
			(0b00001000),



									};
	u8 Dino_RightLegDown [8] = {(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00010011),
			(0b00011111),
			(0b00011110),
			(0b00000010),



									};



	u8 Cactus_Big [8] = {(0b00010100),
			(0b00010100),
			(0b00010101),
			(0b00010101),
			(0b00011111),
			(0b00000100),
			(0b00000100),
			(0b00000100),

										};

	u8 Cactus_Big2 [8] = {(0b00000101),
			(0b00000101),
			(0b00010101),
			(0b00010101),
			(0b00011111),
			(0b00000100),
			(0b00000100),
			(0b00000100),


										};
	u8 Cactus_Small [8] = {(0b00010100),
			(0b00010100),
			(0b00010100),
			(0b00010100),
			(0b00011100),
			(0b00000100),
			(0b00000100),
			(0b00000100),


										};

	u8 Bird_Up [8] = {(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00011101),
			(0b00011101),
			(0b00000111),
			(0b00000000),
										};

	u8 Bird_Down [8] = {(0b00011101),
			(0b00011101),
			(0b00000111),
			(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00000000),
			(0b00000000),

										};



#endif /* FUNSPRIVATE_H_ */
