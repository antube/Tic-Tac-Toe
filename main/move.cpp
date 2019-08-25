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

    //Set move type to 
    type = MoveType::None;

    //Set statistical value to 0
    value = 0;
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

    //reset value
    value = 0;
}

/////////////////////////
// operator=
//
// Arguments:
//     m1 : move&
//
// Return:
//     None
/////////////////////////
void move::operator=(move &m1)
{
    //Set position of current move equal to m1's stored position
    position = m1.position;

    //Set type of current move equal to m1's stored position
    type = m1.type;

    //Set value of current move equal to m1's stored position
    value = m1.value;
}
