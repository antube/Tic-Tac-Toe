#pragma once

#include "hashtable.h"

class computer
{
	public:
		computer(int player, int *board, int boardlength, bool boardEmpty = true);
		~computer();
		int playsCount();
		int play();

	private:
		hash playedTable;

		int playCount;

		int player;      //Assigned player
		int *board;      //Pointer to board
		int boardLength; //Length of board

		bool onLine(int, int);
};
