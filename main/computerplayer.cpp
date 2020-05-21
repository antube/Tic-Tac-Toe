#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "computerplayer.h"
#include "move.h"


//DEFINTIONS
#define BOARD_LENGTH 9
#define BOARD_WIDTH 3


////////////////////////////
// computer
//
// Type:
//      Constructor
//
// Argumments:
//            player     :  int  : Is this computer player X or O (1 or -1 respectively)
//            board      : *int  : 
//            length     :  int  : 
//            boardEmpyt :  bool : 
// Return:
//        None
/////////////////////////////
computer::computer(int player, int *board, int boardLength, bool boardEmpty)
{
	//Assign constructor arrgument player to private variable player
	this->player = player;

	//Assign provided board pointer to internal board pointer
	this->board = board;

	//Assign board length provided to internal board length
	this->boardLength = boardLength;

	//If board is not empty
	if (!boardEmpty)
		//Check every position of board
		for (int i = 0; i < boardLength; i++)
			//If position on board is marked as played 
			if (board[i] == player)
				//Add position to hash table
				playCount++;
}


////////////////////////////////
// ~computer
//
// Arguments:
//
// Return:
//        None
////////////////////////////////
computer::~computer()
{
	board = nullptr;
}


////////////////////////////////
// numberofPlacesPlayed
//
// Arguments:
//			None
//
// Return:
//			int : value stored at 
////////////////////////////////
int computer::playsCount()
{
	return playCount;
}


////////////////////////////////
// play
//
// Description:
// 			
//
// Arguments:
//			 None
//
// Return:
//        	 int : Position to play at
////////////////////////////////
int computer::play()
{
	//If all possible positions have been played
	if (playCount == ((player == 1)?5:4))
		//Return error (-1)
		return -1;

	move Move;

	//If this is first move and I am first player (X is always first player)
	if (playCount == 0 && player == 1)
	{
		//Place at center of board
		Move.position = boardLength / 2;
	}
	//else if this is first move
	else if (playCount == 0 && player == -1)
	{
		//Seed Random Number generator
		srand(time(0));
		do {
			//Set play equal to a random number modulus the Board Length
			Move.position = rand() % boardLength;

		//Repeat while space on board is not empty
		} while (board[Move.position] != 0 || (Move.position % BOARD_WIDTH == 1 || Move.position / BOARD_WIDTH == 1));
	}
	else
	{
		//Run through positions on board
		for(int i = 0; i < boardLength; i++)
		{
			//If current space is an empty space
			if(board[i] == 0)
			{
				move possibleMove;
				//Run through the positions from minus 4 to positive four from i
				//When initializing the board if i minus 4 is less than or equal to 0 initialize i2 to 0 else initialize to i mins 4
				//End if i2 is greater than or equal to board length or i2 is greater than or equal to i plus 4
				//Increment by one
				for (int i2 = (i-4 <= 0)?0:(i-4); i2 < boardLength && i2 < i + 4; i2++)
				{
					//If position on board is marked as having already been played in
					//		and it is on a straight line from the space marked by i
					if (board[i2] == player && onLine(i2, i))
					{
						//If i2 plus the distance between i and i2 is within the bounds of the board
						if ((i2 - i) + i2 >= 0 && (i2 - i) + i2 < boardLength)
						{
							
						}
						//Else if i minus the distance between i and i2 is within the bounds of the board
						else if ((i2 - 1) - i >= 0 && (i2 - i) - i < boardLength)
						{

						}
					}
				}

				if (possibleMove.value > Move.value)
				{
					Move = possibleMove;
				}
				else if (possibleMove.value == Move.value)
				{
					srand(time(0));

					int choice = rand() % 2;

					if (choice == 0)
						Move = possibleMove;
				}
			}
		}
	}

	playCount++;

	return Move.position;
}

////////////////////////////////
// Name: onLine
//
// Description:
//		
//
// Parameters:
//			
//
// Return:
//			bool : 
////////////////////////////////
bool computer::onLine(int i1, int i2)
{
	return (i2 % BOARD_WIDTH) - 1 == i1 % BOARD_WIDTH || (i2 % BOARD_WIDTH) + 1 == i1 % BOARD_WIDTH
				|| (i2 / BOARD_WIDTH) - 1 == i1 / BOARD_WIDTH || (i2 / BOARD_WIDTH) + 1 == i1 / BOARD_WIDTH;
}