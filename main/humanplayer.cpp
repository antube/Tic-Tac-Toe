#include "humanplayer.h"
#include <iostream>

void print_board(int board[], int boardLength, int boardWidth);

///////////////////////////////
// humanPlay
// 
// Arguments:
//     board       : int[]
//     boardLength : int
//     boardWidth  : int
//
// Return:
//     int
///////////////////////////////
int humanPlay(int board[], int boardLength, int boardWidth)
{
	while(true)
	{
		//Print board
		print_board(board, boardLength, boardWidth);

		int x = 0; //Variable to store x coordinate
		int y = 0; //Variable to store y coordinate

		//Ask user for x coordinate
		std::cout << "X Coordinate: ";
		
		//Get x coordinate from user
		std::cin >> x;

		//Ask user for y coordinate
		std::cout << "Y Coordinate: ";
		
		//Get y  coordinate from user
		std::cin >> y;

		//If y coordinate is greater than or equal to board width
		if(x >= boardWidth)
		{
			//Alert user to invalid coordinate
			std::cout << "Invalid Coordinates\n\n";
			
			//continue with execution
			continue;
		}

		//set z equal to x coordinate multiplied by the boardwidth and add y c
		int z = (y * boardWidth) + x;

		//If selected space is within bounds of the board empty
		if(z > 0 && z < boardLength && board[z] == 0)
			//return the space index
			return z;
		//Else
		else
			//Alert user to invalid coordinates
			std::cout << "Invalid Coordinates\n\n";
	}

	//Return error
	return -1;
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
void print_board(int board[], int boardLength, int boardWidth)
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

	//Print x coordinates
	std::cout << "    0 | 1 | 2" << std::endl << std::endl;

	for (int i = 0; i < boardLength; i++)
	{
		//i mod 3 equals 0
		if(i % 3 == 0)
			//Print y coordinate
			std::cout << i / 3 << "   ";

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
		if (i % boardWidth == 2)
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