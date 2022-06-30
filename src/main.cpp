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
#include <memory>
#include "display/display.h"
#include "display/displayMode.h"
#include "computerplayer.h"
#include "boolean.h"


//DEFINTIONS
#define BOARD_LENGTH 9
#define BOARD_WIDTH 3


//STRUCTURES



//PROTOTYPES
void printBoard(int[]);
void UserPlay(int[], int);
std::shared_ptr<Boolean> isThereWinner(int[], int = 0);
bool isCatGame(int[]);
char whoWon(int[]);
bool checkSpace(int, int[], int);
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

	ComputerPlayer playerX(1, board, BOARD_LENGTH);
	ComputerPlayer playerY(-1, board, BOARD_LENGTH);


	while (true)
	{
		playerX.play();

		if (isThereWinner(board, 1)->True || isCatGame(board))
			break;
			

		printBoard(board);

		UserPlay(board, -1);

		if (isThereWinner(board, -1)->True || isCatGame(board))
			break;
			

		//std::system("clear");
	}

	std::system("clear");
	
	printBoard(board);

	if(isThereWinner(board)->True)
		std::cout << ((isThereWinner(board)->piece == 1) ? 'X' : 'O') << " Won!!" << std::endl << std::endl;
	else if (isCatGame(board))
		std::cout << "Cat Game" << std::endl << std::endl;
	else
		std::cout << "ERROR: there is no winner and it is not a cat game. I am currently scratching my head as to how this could happen but here you are." << std::endl << std::endl;

	std::cout << "End of Line" << std::endl;

	
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


void UserPlay(int board[], int player)
{
	int playPosition = 0;

	do
	{
		std::cout << "Please enter a play location (0-" << BOARD_LENGTH - 1 << "): ";
		std::cin >> playPosition;
	} while (board[playPosition] != 0);
	
	board[playPosition] = player;
}


std::shared_ptr<Boolean> isThereWinner(int board[], int player)
{
	for(int i = 0; i < BOARD_LENGTH; i++)
	{
		std::shared_ptr<Boolean> b(new Boolean());
		b->piece = board[i];

		if (player == 0)
		{
			if (board[i] == 1)
			{
				b->True = checkSpace(i, board, 1);

				if (b->True)
					return b;
			}

			if (board[i] == -1)
			{
				b->True = checkSpace(i, board, -1);

				if (b->True)
					return b;
			}
		}
		else
		{
			if (board[i] == player)
			{
				b->True = checkSpace(i, board, player);

				if (b->True)
					return b;
			}
		}
	}

	std::shared_ptr<Boolean> b(new Boolean());
	b->True = false;
	b->piece = 0;

	return b;
}


bool isCatGame(int board[])
{
	int count = 0;

	for (int i = 0; i < BOARD_LENGTH; i++)
	{
		if (board[i] != 0)
			count++;
	}

	if (count == BOARD_LENGTH)
		return true;

	return false;
}


struct delta
{
	int piece;
	int deltaX;
	int deltaY;
};


bool checkSpace(int i, int board[], int piece)
{
	std::vector<delta> deltas;

	
	//Initialize i2 to the inverse of i so that when it is added to i it equals zero
	for (int i2 = -i; i + i2 < BOARD_LENGTH; i2++)
	{
		//If the space at the described board position is filled with the piece I am currerntly looking for
		//	And the pieces at at i+i2 and i are on a line
		if (board[i + i2] == piece && onLine(i + i2, i))
		{
			//ISSUE: Take the center postion, as all diagonal spots have an absolute value change
			//  on both the x and y of 1 they will look the same.

			//Take the change in x and y
			int tempDeltaX = (i % BOARD_WIDTH) - ((i + i2) % BOARD_WIDTH);
			int tempDeltaY = (i / BOARD_WIDTH) - ((i + i2) / BOARD_WIDTH);

			//Loop through the list of deltas
			for (delta d : deltas)
			{
				//What I am looking for is if the deltas line up so that the empty space I am currently looking at
				//  is bounded by two pieces in a line by looking for another set of deltas that compliments the temporary deltas
				//  If the deltas are in a line and they 

				//IF
				//    The temporary deltas are equal to the inverse of the list deltas item
				//OR
				//    The temporary deltas are equal to the list deltas added to themselves
				//OR
				//    The temporary deltas added to themselves are equal to the list deltas
				if ((tempDeltaX == -d.deltaX && tempDeltaY == -d.deltaY) ||
				    (tempDeltaX == d.deltaX + d.deltaX && tempDeltaY == d.deltaY + d.deltaY) ||
					(tempDeltaX + tempDeltaX == d.deltaX && tempDeltaY + tempDeltaY == d.deltaY))
				{
					return true;
				}
			}

			//Add deltas to list
			delta d;
			d.deltaX = tempDeltaX;
			d.deltaY = tempDeltaY;

			deltas.push_back(d);
		}
	}

	//If I fall out I did not find a block or win so return false
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