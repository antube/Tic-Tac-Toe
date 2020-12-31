#include "move.h"


/////////////////////////////////
// move
//
// Arguments:
//     None
//
// Returns:
//     None
/////////////////////////////////
move::move()
{
	//Set position to -1
	position = -1;

	//Set move type to None
	type = MoveType::None;
}

////////////////////////
// ~move
//
// Arguments:
//     None
//
// Return:
//     None
///////////////////////
move::~move()
{
	//Reset position
	position = 0;

	//Reset type
	type = MoveType::None;
}

/////////////////////////
// operator=
//
// Arguments:
//     moveRightSide : move&
//
// Return:
//     None
/////////////////////////
void move::operator=(move &moveRightSide)
{
	//Set position of current move equal to moveRightSide's stored position
	position = moveRightSide.position;

	//Set type of current move equal to moveRightSide's stored position
	type = moveRightSide.type;
}
