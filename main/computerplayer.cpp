#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "computerplayer.h"
#include "move.h"

////////////////////////////
// computer
//
// Type:
//      Constructor
//
// Argumments:
//            player : int
//            board  : *int
//            length : int
//
// Return:
//        None
/////////////////////////////
computer::computer(int player, int *board, int boardLength)
{
	if(player == 1)
		playedListLength = ceil(boardLength / 2);
	else if(player == -1)
		playedListLength = floor(boardLength / 2);

	playedList = new int[playedListLength];

	playedListIndex = 0;

	//Assign constructor arrgument player to private variable player
	this->player = player;

	//Assign provided board pointer to internal board pointer
	this->board = board;

	//Assign board length provided to internal board length
	this->boardLength = boardLength;
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
	delete playedList;
}


////////////////////////////////
// numberofPlacesPlayed
//
// Arguments:
//
// Return:
//        int
////////////////////////////////
int computer::playsCount()
{
	return playedListIndex;
}


////////////////////////////////
// play
//
// Arguments:
//
// Return:
//        int
////////////////////////////////
int computer::play()
{
	srand(time(NULL));

	//If all possible positions have been played
	if (playedListIndex == playedListLength)
		//Return error (-1)
		return -1;

	//If this is first move and I am first player (X is always first player)
	if (playedListIndex == 0 && player == 1)
	{
		//Place at center of board
		addtoPlayedList(boardLength / 2);
		return boardLength / 2;
	}
	//else if this is first move
	else if (playedListIndex == 0)
	{
		int play = 0; //variable to hold play position
		do {
			//Set play equal to a random number modulus the Board Length
			play = rand() % boardLength;

		//Repeat while space on board is not empty
		} while (board[play] != 0);


		//Add play to list of played positions
		addtoPlayedList(play);

		//Return play
		return play;
	}

	move Move;

	for(int i = 0; i < boardLength; i++)
	{
		
	}

	return Move.getposition();
}

void computer::addtoPlayedList(int position)
{
	if(playedListIndex != playedListLength)
	{
		playedList[playedListIndex] = position;
		playedListIndex++;
	}
}
