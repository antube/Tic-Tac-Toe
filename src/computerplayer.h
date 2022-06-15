#pragma once

#include "move.h"

class ComputerPlayer
{
	private:
		static int playCount;

		int player;      //Assigned player
		int *board;      //Pointer to board
		int boardLength; //Length of board

		bool onLine(int, int);
		void checkSpace(Move&, int, MoveType);

	public:
		ComputerPlayer(int player, int *board, int boardlength, bool boardEmpty = true);
		~ComputerPlayer();
		int playsCount();
		int play();
};
