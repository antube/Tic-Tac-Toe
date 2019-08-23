#include "move.h"

move::move()
{
    position = -1;

    type = MoveType::None;

    value = 0;
}

move::~move()
{
    position = 0;

    type = MoveType::None;

    value = 0;
}

void move::operator=(move &m1)
{
    position = m1.position;
    type = m1.type;
    value = m1.value;
}
