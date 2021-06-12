#pragma once

enum MoveType
{
	None,
	Play,
	Block,
	Won
};

struct Move
{
	int position; //Position on board
	MoveType type; //Type of move stored

	//Constructor
	Move();

	//Destructor
	~Move();

	//Overload the = operator to be used on the class
	void operator=(Move &m1);
};
