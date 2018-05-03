/*
* O = -1
* X = 1
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
#include <iostream>
#include "prototypes.h"
#include "definitions.h"

//DEFINTIONS


//PROTOTYPES
void Print_Board(int *pStart, int *pEnd);


int main()
{
	int board[BOARD_LENGTH]
	{ 0, 0, 0,
		0, 0, 0,
		0, 0, 0 };

	int *final_position = (board + (sizeof(board) / sizeof(int))) - 1;

	//board[computer_play(board, final_position, 1)] = 1;

	Print_Board(board, final_position);

	return 0;
}

void Print_Board(int *pStart, int *pEnd)
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		std::cout << " " << i + 1;
	}
	std::cout << std::endl;

	while (pStart < pEnd)
	{
		if (*pStart == -1)
		{
			std::cout << " O ";
		}
		else
	}
}