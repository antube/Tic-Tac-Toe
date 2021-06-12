/*
 * O           = -1
 * X           =  1
 * Empty Space =  0
 *
 *     0 | 1 | 2
 *     --+---+--
 *     3 | 4 | 5
 *     --+---+--
 *     6 | 7 | 8
 *
 *  0/0 | 1/0 | 2/0
 *  ----+-----+----
 *  0/1 | 1/1 | 2/1
 *  ----+-----+----
 *  0/2 | 1/2 | 2/2
 *
 * Modulus / Division
 *
 * Modulus:  i % 3
 * Division: i / 3
*/


//INCLUDES
#include <iostream>
#include <vector>
#include "display/display.h"
#include "display/displayMode.h"
#include "computerplayer.h"


//DEFINTIONS
#define BOARD_LENGTH 9
#define BOARD_WIDTH 3


//STRUCTURES
struct Boolean
{
	bool True;
	int piece;
};


//PROTOTYPES
void printBoard(int[]);
Boolean isThereWinner(int[]);
bool checkSpace(int&, int[]);
bool onLine(int, int);


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
	//length 9 array containing the board
	int board[BOARD_LENGTH]
		{0,  0,  0,
		 0,  0,  0,
		 0,  0,  0};

	Display display = Display(board);

	display.show(Splash, 1);

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
void printBoard(int board[])
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
			//Change color to red and print value at location on board
			std::cout << "\033[0;31m" << "O";

		//Else if piece is a 1 (X) print a blue 1
		else if(board[i] == 1)
			//Change color and print value at location on board
			std::cout << "\033[0;34m" << "X";

		//Else space is empty  print a green 0
		else
			//Leave color at default value and print value at location on board
			std::cout << " ";

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


Boolean isThereWinner(int board[])
{
	for(int i = 0; i < BOARD_LENGTH; i++)
	{
		Boolean b;
		b.True = checkSpace(i, board);
		b.piece = board[i];

		if (!b.True)
			return b;
	}

	Boolean b;
	b.True = false;
	b.piece = 0;

	return b;
}


struct delta
{
	int piece;
	int deltaX;
	int deltaY;
};


bool checkSpace(int &position, int board[])
{
	const int &i = position;

	std::vector<delta> deltas;

	/*
	* Initialize i2 to the inverse of i so that when it is added to i it equals zero
	*/
	for (int i2 = -i; i + i2 < BOARD_LENGTH; i2++)
	{
		if (board[i + i2] == board[i] && onLine(i + i2, i))
		{
			int tempDeltaX = abs((i % BOARD_WIDTH) - ((i + i2) % BOARD_WIDTH));
			int tempDeltaY = abs((i / BOARD_WIDTH) - ((i + i2) / BOARD_WIDTH));

			for (delta d : deltas)
			{
				if ((tempDeltaX == d.deltaX && tempDeltaY == d.deltaY) ||
				    (tempDeltaX == d.deltaX + d.deltaX && tempDeltaY == d.deltaY + d.deltaY) ||
					(tempDeltaX + tempDeltaX == d.deltaX && tempDeltaY + tempDeltaY == d.deltaY))
				{
					return true;
				}
			}

			delta d;
			d.deltaX = tempDeltaX;
			d.deltaY = tempDeltaY;

			deltas.push_back(d);
		}
	}


	return false;
}


////////////////////////////////
// Name: onLine
//
// Description:
//		 Return true if i1 and i2 are on a reasonable line with each other
//
// Parameters:
//			
//
// Return:
//			bool :
////////////////////////////////
bool onLine(int i1, int i2)
{
	const int X1 = i1 % BOARD_WIDTH;
	const int X2 = i2 % BOARD_WIDTH;
	const int Y1 = i1 / BOARD_WIDTH;
	const int Y2 = i2 / BOARD_WIDTH;

	/*******************************************************************************************
	* return true if
	********************************************************************************************
	* The absolute value of i1 minus i2 and modulus 2 is not equal to 0
	* and
	* The absolute value of i1 minus i2 is less than 4
	*
	* or
	*
	* The absolute value of i1 minus and modulus 2 is equal to zero
	********************************************************************************************
	*/
	return (X1 - X2 == 0 || Y1 - Y2 == 0) ||
		   (X1 - Y1 == 0 && X2 - Y2 == 0) ||
		   (abs(X1 - Y1) == 2 && abs(X2 - Y2) == 2) ||
		   ((abs(X1 - Y1) == 2 && X2 - Y2 == 0) ||
		    (X1 - Y1 == 0 && abs(X2 - Y2) == 2));
}