#pragma once

//Defintions
#define BOARD_SIZE 9
#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3
#define PIECE_SELECTION_NUMBER 3

//Computer Play
unsigned int computer_play(int (&board)[BOARD_SIZE], int);

//End of Game Detection
bool winner(int (&board)[BOARD_SIZE], int);
bool catgame(int (&board)[BOARD_SIZE]);