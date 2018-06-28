/*
*  0/0 | 1/0 | 2/0
*  ---------------
*  0/1 | 1/1 | 2/1
*  ---------------
*  0/2 | 1/2 | 2/2
*
* Modulus / Division
*
* Modulus:  i % 3
* Division: i / 3
*/

//INCLUDES
#include <cstdlib>
#include <ctime>
#include "headers/definitions.h"
#include "headers/structs.h"

//DEFINTIONS


//PROTOTYPES
position check_win(int*, int*, int);



int computer_play(int *bStart, int *bEnd, int player)
{
	srand(time(NULL));
	position move;
	move.initialization();
	int *p1 = bStart;
	while (bStart <= bEnd)
	{
		if (*bStart == player)
		{
			position temp = check_win(bStart, bEnd, player);
			return temp.move;
		}
		else if (*bStart == player * -1)
		{
			position temp = check_win(bStart, bEnd, player * -1);

			if (temp.type > move.type)
			{
				move = temp;
			}
			else if (temp.type == move.type)
			{
				int selector = rand() % 2;

				if (selector == 0)
				{
					move = temp;
				}
			}
		}

		else if (move.type < 2)
		{
			for (int i = 0; i < BOARD_LENGTH; i++)
			{

			}
		}
		p1++;
	}

	return 0;
}

position check_win(int *bStart, int *bEnd, int Player)
{
	position move;
	move.initialization();

	return move;
}