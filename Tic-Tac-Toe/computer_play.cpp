/* Notes
* If [Insert Number] pieces are in a row the distances between
* the pieces will be the same in a linear array
*/
#include <cstdlib>
#include <ctime>

//Defintions
#define BOARD_SIZE 9
#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3
#define PIECE_SELECTION_NUMBER 3

unsigned int computer_play(int(&board)[BOARD_SIZE], int player)
{
	unsigned int Move = 0;
	int Move_Value = 0;
	bool Move_Block = false;

	if (board[4] == 0)
	{
		return 4;
	}

	for (int i1 = 0; i1 < BOARD_SIZE; i1++)
	{
		if (board[i1] == player)
		{
			for (int i2 = 1; i2 + i1 < BOARD_SIZE; i2++)
			{
				if (board[i1 + i2] == player && i2 % 2 == 0 && (i1 % 3 == 2 || i1 / 3 == 0))
				{
					if (board[i1 + i2 / 2] == 0)
					{
						return i1 + i2 / 2;
					}
				}
			}
			for (int i2 = -BOARD_WIDTH - 1; i2 < BOARD_WIDTH + 1; i2++)
			{
				if (i2 == 0) continue;
				int _i2 = i2;

				for (int piece = 0; piece < PIECE_SELECTION_NUMBER; piece++)
				{
					if (i1 + _i2 < 0 || i1 + _i2 >= BOARD_SIZE) break;

					if (piece != 0 && (i1 + _i2) / BOARD_WIDTH != (i1 + (_i2 - i2)) / BOARD_WIDTH &&
						(((i1 + _i2) % BOARD_WIDTH - (i1 + (_i2 - i2)) % BOARD_WIDTH) < -1 ||
						((i1 + _i2) % BOARD_WIDTH - (i1 + (_i2 - i2)) % BOARD_WIDTH) > 1)) break;

					if (piece < PIECE_SELECTION_NUMBER - 1)
					{
						if (board[i1 + _i2] != player)
						{
							break;
						}
					}
					else if (piece == PIECE_SELECTION_NUMBER - 1)
					{
						if (board[i1 + _i2] == 0)
						{
							Move = i1 + _i2;
							Move_Block = true;
						}
						else
						{
							break;
						}
					}

					_i2 += i2;
				}
			}
		}
		if (board[i1] == -player)
		{
			for (int i2 = 2; i2 + i1 < BOARD_SIZE; i2++)
			{
				if (board[i1 + i2] == -player && i2 % BOARD_WIDTH == 0 && (i1 % BOARD_WIDTH == 2 || i1 / BOARD_WIDTH == 0))
				{
					if (board[i1 + i2 / 2] == 0)
					{
						Move = i1 + i2 / 2;
						Move_Block = true;
					}
				}
			}
			for (int i2 = (-1 * BOARD_WIDTH) - 1; i2 < BOARD_WIDTH + 1; i2++)
			{
				if (i2 == 0) continue;

				int _i2 = i2;

				for (int piece = 1; piece < PIECE_SELECTION_NUMBER; piece++)
				{
					if (i1 + _i2 < 0 || i1 + _i2 >= BOARD_SIZE) break;

					if ((i1 + _i2) / BOARD_WIDTH != (i1 + (_i2 - i2)) / BOARD_WIDTH &&
						(((i1 + _i2) % BOARD_WIDTH - (i1 + (_i2 - i2)) % BOARD_WIDTH) < -1 ||
						((i1 + _i2) % BOARD_WIDTH - (i1 + (_i2 - i2)) % BOARD_WIDTH) > 1)) break;

					if (piece < PIECE_SELECTION_NUMBER - 1)
					{
						if (board[i1 + _i2] != (player * -1))
						{
							break;
						}
					}
					else if (piece == PIECE_SELECTION_NUMBER - 1)
					{
						if (board[i1 + _i2] == 0)
						{
							Move = i1 + _i2;
							Move_Block = true;
						}
						else
						{
							break;
						}
					}

					_i2 += i2;
				}

			}
		}
		else if (!Move_Block)
		{
			int Current_Move_Value = 0;

			if (board[i1] != 0)
			{
				Current_Move_Value -= 10;
			}

			for (int i2 = -BOARD_WIDTH - 1; i2 < BOARD_WIDTH + 1; i2++)
			{
				if (i2 == 0) i2++;

				if (i1 + i2 < BOARD_SIZE && i1 + i2 >= 0)
				{
					if (board[i1 + i2] == player)
					{
						Current_Move_Value++;
					}
				}
			}

			if (Current_Move_Value > Move_Value)
			{
				Move = i1;
				Move_Value = Current_Move_Value;
			}
			else
			{
				srand(time(0));
				long long random = rand();
				if (random > RAND_MAX >> 1)
				{
					Move = i1;
					Move_Value = Current_Move_Value;
				}

			}
		}
	}

	return Move;
}