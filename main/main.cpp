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
#include "computerplayer.h"
#include "humanplayer.h"


//DEFINTIONS
#define BOARD_LENGTH 9
#define BOARD_WIDTH 3


//PROTOTYPES
void print_board(int board[]);


/////////////////////////////
// main
//
// Arguments:
//           None
//
// Return:
//        int
/////////////////////////////
int main()
{
    std::cout << "\033[0;32m" << "Tic-Tac-Toe\n" << "Created by Andrew Brown\n";

	//length 9 array containing the board
	int board[BOARD_LENGTH]
		{0, 0, 0,
		 0, 0, 0,
		 0, 0, 0};

	//Create new instance of computer player object as x
	computer *computerPlayerX = new computer(1, board, BOARD_LENGTH);
	computer *computerPlayerO = new computer(-1, board, BOARD_LENGTH);

	//Print Board
	print_board(board);

	//Variable to store move
	int move = 0;

	while (true)
	{
		//Computer Player X selects play position and returns position
		move = computerPlayerX->play();

		//If play is valid
		if (move != -1)
			//Play to board
			board[move] = 1;
		else if (move == -1)
			break;

		//Print Board
		print_board(board);

		move = humanPlay(board, BOARD_LENGTH, BOARD_WIDTH);

		if (move != -1)
			//Play to board
			board[move] = -1;
		else if (move == -1)
			break;

		print_board(board);
	}
	//Print Message wait message
	std::cout << "Press any key to continue...\n";

	//Wait until user presses any key
	std::cin.get();


	//Return 0
	return 0;
}


//////////////////////////
// print_board
//
// Arguments:
//           board : int[]
//
// Returns:
//         void
//////////////////////////
void print_board(int board[])
{
	std::cout << "\033[0;32m";
	/*
	# Regular Colors
	Black..."\033[0;30m"       # Black
	Red....."\033[0;31m"       # Red
	Green..."\033[0;32m"       # Green
	Yellow.."\033[0;33m"       # Yellow
	Blue...."\033[0;34m"       # Blue
	Purple.."\033[0;35m"       # Purple
	Cyan...."\033[0;36m"       # Cyan
	White..."\033[0;37m"       # White
	*/
	for (int i = 0; i < BOARD_LENGTH; i++)
	{
		//If piece is a -1 (O) print a red -1
		if(board[i] == -1)
			//Change color to red and print vlaue at location on board
			std::cout << "\033[0;31m" << board[i];

		//Else if piece is a 1 (X) print a blue 1
		else if(board[i] == 1)
			//Change color and print value at location on board
			std::cout << "\033[0;34m" << board[i];

		//Else space is empty  print a green 0
		else
			//Leave color at default value and print value at location on board
			std::cout << board[i];

		//Change color to green
		std::cout << "\033[0;32m";

		//If position modulus board width equals 2
		if (i % BOARD_WIDTH == 2)
			//Carriage Return
			std::cout << std::endl;

		//Else
		else
			//Leave color as default and print divider
			std::cout << " | ";
	}
	//Add space below board
	std::cout << "\033[0;37m" << std::endl;
}
