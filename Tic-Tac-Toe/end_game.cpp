//Includes
#include <iostream>

//Defintions
#define BOARD_SIZE 9
#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3
#define PIECE_SELECTION_NUMBER 3

bool winner(int (&board)[BOARD_SIZE], int player)
{
	for (int i1 = 0; i1 < BOARD_SIZE; i1++)
	{
		if (board[i1] == player)
		{
			for (int i2 = -BOARD_WIDTH - 1; i2 < BOARD_WIDTH + 1; i2++)
			{
				if (i2 == 0 || i2 == -1) continue;

				if (i2 == 1 && i1 % 3 != 0) continue;

				if (board[i1 + i2] == player)
				{
					if (i1 + i2 + i2 < BOARD_SIZE && i1 + i2 + i2 >= 0)
					{
						if (board[i1 + i2 + i2] == player)
						{
							return true;
						}
					}
					else if (i1 - i2 < BOARD_SIZE && i1 - i2 >= 0)
					{
						if (board[i1 - i2] == player)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool catgame(int (&board)[BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (board[i] == 0)
		{
			return false;
		}
	}
	return true;
}