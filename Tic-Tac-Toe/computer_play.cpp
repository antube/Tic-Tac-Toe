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
position check_position(int*, int, int, int, position);
position place(int, int, int, position);

int computer_play(int *bStart, int player)
{
	srand(time(NULL));
	position move;
	move.initialization();
	int p1 = 0;
	while (p1 < BOARD_LENGTH)
	{
		if(*(bStart + p1) == player)
		{
			move = check_position(bStart, p1, 1, player, move);

			if(move.type == 2)
			{
				return move.position;
			}
		}
		else if(*(bStart + p1) == player * -1)
		{
			move = check_position(bStart, p1, 0, player, move);
		}
		else
		{

		}

		p1++;
	}


	return move.position;
}

position check_position(int *bStart, int p1, int bias, int player, position move)
{
	int p2 = p1 + 1;
	while(p2 < BOARD_LENGTH)
	{
		if(*(bStart + p2) == player) continue;
		int diff = p1 -p2;

		if (diff == 1 || diff == 1)
		{
			if(diff == 1 && (p1 % BOARD_WIDTH == 0 && p2 % BOARD_WIDTH != 2))
			{
				move = place(diff, p1, p2, move);
			}
			else if (diff == -1 && (p1 % BOARD_WIDTH == 2 && p2 % BOARD_WIDTH != 0))
			{
				move = place(diff, p1, p2, move);
			}
		}
		/*else if (diff == 2 || diff == -2)
		{
			if(p2 == (BOARD_LENGTH - 1) / 2)
			{

			}
		}
		else if (diff == 3 || diff == -3)
		{

		}
		else if (diff == 4 || diff == -4)
		{

		}
		else if(diff == 6 || diff == -6)
		{

		}
		else if (diff == 8 || diff == -8)
		{

		}*/

		p2++;
	}

	return move;
}

position place(int diff, int p1, int p2, position move)
{
	if(diff < 0)
	{
		move.position = p1 + diff;
	}
	else if(diff > 0)
	{
		move.position = p2 + diff;
	}

	return move;
}