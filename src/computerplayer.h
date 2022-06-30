#pragma once

#include <memory>
#include "boolean.h"
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
		bool checkSpace(int, int[], int);
		
		int playReturn();
		int PredictPlays();
		
		bool isCatGame(int[]);
		std::shared_ptr<Boolean> isThereWinner(int[], int);

	public:
		ComputerPlayer(int player, int *board, int boardlength, bool boardEmpty = true);
		~ComputerPlayer();
		int playsCount();
		void play();
};
