/*
 * O = -1
 * X =  1
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
#include "headers/prototypes.h"
#include "headers/definitions.h"


//DEFINTIONS


//PROTOTYPES
void Print_Board(int *pStart, int *pEnd);


int main()
{
    std::cout << "\033[0;32m" << "Tic-Tac-Toe\n" << "Created by Andrew Brown\n";

	int board[BOARD_LENGTH]
	    {1, 1, 0,
		 0, 0, 0,
		 0, 0, 0 };

	int *final_position = (board + (sizeof(board) / sizeof(int)));

	board[computer_play(board, 1)] = 1;

	Print_Board(board, final_position);

	std::cout << "Press any key to continue...";
	std::cin.get();

	return 0;
}

void Print_Board(int *pStart, int *pEnd)
{
	while (pStart < pEnd)
	{
        if(*pStart == -1)
        {
            std::cout << "\033[0;31m" << *pStart;
        }
        else if(*pStart == 1)
        {
            std::cout << "\033[0;34m" << *pStart;
        }
        else
        {
            std::cout << *pStart;
        }

        std::cout << "\033[0;32m";

		if (((pEnd - pStart) + 1) % BOARD_WIDTH == 2)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << " | ";
        }
		pStart++;
	}
}