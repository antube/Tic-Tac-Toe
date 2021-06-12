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
Move::Move()
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
Move::~Move()
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
void Move::operator=(Move &moveRightSide)
{
	//Set position of current move equal to moveRightSide's stored position
	position = moveRightSide.position;

	//Set type of current move equal to moveRightSide's stored position
	type = moveRightSide.type;
}
