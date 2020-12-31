#pragma once

enum MoveType
{
	None,
	Play,
	Block,
	Win
};

struct move
{
	int position; //Position on board
	MoveType type; //Type of move stored

	//Constructor
	move();

	//Destructor
	~move();

	//Overload the = operator to be used on the class
	void operator=(move &m1);
};
