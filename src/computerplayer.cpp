#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "computerplayer.h"
#include "move.h"


//DEFINTIONS
#define BOARD_LENGTH 9
#define BOARD_WIDTH 3


int ComputerPlayer::playCount = 0;


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
ComputerPlayer::ComputerPlayer(int player, int *board, int boardLength, bool boardEmpty)
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
ComputerPlayer::~ComputerPlayer()
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
//			int : value stored playCount
////////////////////////////////
int ComputerPlayer::playsCount()
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
int ComputerPlayer::play()
{
	//If all possible positions have been played
	if (playCount == ((player == 1)?5:4))
		//Return error (-1)
		return -1;

	Move move;

	//If the middle space is open play there
	if (board[boardLength >> 1] == 0)
	{
		//Place at center of board
		move.position = boardLength >> 1;
	}
	//else if this is first move and the player is O
	else if (playCount == 1 && player == -1)
	{
		//Seed Random Number generator
		srand(time(0));

		/*
		 * 0 |   | 2
         * --+---+--
         *   |   |  
         * --+---+--
         * 6 |   | 8
		 * 
		 * 0 1 2 3
		*/

		do {
			//Set play equal to a random number modulus the Board Length
			move.position = rand() % boardLength;

		//Repeat while space on board is not empty
		} while (board[move.position] != 0 || (move.position % BOARD_WIDTH == 1 || move.position / BOARD_WIDTH == 1));
	}
	else
	{
		//Run through positions on board
		for(int i = 0; i < boardLength; i++)
		{
			//If current space is an empty space
			if(board[i] == 0)
			{
				Move possibleMove;
				possibleMove.position = i;

				//Check if empty space is capable of a win
				checkSpace(possibleMove, player, Won);

				if (possibleMove.type == Won)
					return possibleMove.position;

				//Check if empty space is capable of a block
				checkSpace(possibleMove, -player, Block);

				//If the value of the possible move is greater than the value of
				//	 the previously selected Move
				if (possibleMove.type > move.type
					|| possibleMove.type == Won
					|| (possibleMove.type == Block
					&& move.type != Won))
				{
					//Assign possibleMove to Move
					move = possibleMove;
				}
				//Else if the value of the possible move is equal to the value
				//	 of selected move
				else if (possibleMove.type == move.type)
				{
					//Seed random number generator with time
					srand(time(0));

					//If random number generated is zero
					if (rand() % 2 == 0)
						//Assign possibleMove to Move
						move = possibleMove;
				}
			}
		}
	}

	playCount++;

	return move.position;
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
bool ComputerPlayer::onLine(int i1, int i2)
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


struct delta
{
	int deltaX;
	int deltaY;
};


void ComputerPlayer::checkSpace(Move &possibleMove, int piece, MoveType type)
{
	const int &i = possibleMove.position;

	std::vector<delta> deltas;

	
	//Initialize i2 to the inverse of i so that when it is added to i it equals zero
	for (int i2 = -i; i + i2 < boardLength; i2++)
	{
		//If the space at the described board position is filled with the piece I am currerntly looking for
		//	And the pieces at at i+i2 and i are on a line
		if (board[i + i2] == piece && onLine(i + i2, i))
		{
			//ISSUE: Take the center postion, as all diagonal spots have an absolute value change
			//  on both the x and y of 1 they will look the same.

			//Take the change in x and y
			int tempDeltaX = abs((i % BOARD_WIDTH) - ((i + i2) % BOARD_WIDTH));
			int tempDeltaY = abs((i / BOARD_WIDTH) - ((i + i2) / BOARD_WIDTH));

			//Loop through the list of deltas
			for (delta d : deltas)
			{
				//What I am looking for is if the deltas line up so that the empty space I am currently looking at
				//  is bounded by two pieces in a line by looking for another set of deltas that compliments the temporary deltas
				//  If the deltas are in a line and they 

				//IF
				//    The temporary deltas are equal to the list deltas 
				//OR
				//    The temporary deltas are equal to the list deltas added to them selves
				//OR
				//    The temporary deltas added to them selves are equal to the list deltas
				if ((tempDeltaX == d.deltaX && tempDeltaY == d.deltaY) ||
				    (tempDeltaX == d.deltaX + d.deltaX && tempDeltaY == d.deltaY + d.deltaY) ||
					(tempDeltaX + tempDeltaX == d.deltaX && tempDeltaY + tempDeltaY == d.deltaY))
				{
					possibleMove.type = type;
					return;
				}
			}

			//Add deltas to list
			delta d;
			d.deltaX = tempDeltaX;
			d.deltaY = tempDeltaY;

			deltas.push_back(d);
		}
	}

	//If I fall out I did not find a block or win. Return that it is just a play
	possibleMove.type = Play;
}
