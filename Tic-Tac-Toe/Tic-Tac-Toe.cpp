// Tic-Tac-Toe.cpp : Defines the entry point for the console application.
// -1 = X
//  0 = Blank
//  1 = O
//result order Computer X:|:Computer Y:|:Human X:|:Human Y

#include "prototypes.h"
#include <iostream>
using namespace std;

//Defintions
#define BOARD_SIZE 9
#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3

//Functions
void draw_board(int (&board)[BOARD_SIZE])
{
	system("cls");
	std::cout << "    1 | 2 | 3\n";
	cout << "   -----------\n";
	for (int i = 0; i < BOARD_SIZE; i++)
	{

		if (i % 3 == 0 && i != 0)
		{
			cout << "\n";
			cout << "   -----------\n";
			cout << ' ' << (i / BOARD_HEIGHT) + 1 << "  ";
		}
		else if (i % BOARD_WIDTH == 0)
		{
			cout << ' ' << (i / BOARD_HEIGHT) + 1 << "  ";
		}
		else
		{
			cout << "| ";
		}

		if (board[i] == -1)
		{
			cout << "X ";
		}
		else if (board[i] == 1)
		{
			cout << "O ";
		}
		else
		{
			cout << "  ";
		}
	}
	cout << "\n\n";
}

unsigned int human_play()
{
	int x, y;

	//Ask and accept X Coordinate
	cout << "X Postion: ";
	cin >> x;

	//Ask and accept Y Coordinate
	cout << "Y Postion: ";
	cin >> y;

	y -= 1;
	x -= 1;

	return (y * 3) + x;
}

int main()
{
	int board[BOARD_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};



	while(true)
	{
		draw_board(board);
		board[human_play()] = -1;
		if (winner(board, -1))
		{
			draw_board(board);
			cout << "X Wins";
			break;
		}
		else if (catgame(board))
		{
			draw_board(board);
			cout << "Cat Game" << endl;
			break;
		}

		board[computer_play(board, 1)] = 1;
		if (winner(board, 1))
		{
			draw_board(board);
			cout << "O Wins";
			break;
		}
		else if (catgame(board))
		{
			draw_board(board);
			cout << "Cat Game" << endl;
			
			break;
		}
	}
	system("PAUSE");

    return 0;
}