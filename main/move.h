#pragma once

enum MoveType
{
    None,
    Block,
    Play,
    Win
};

struct move
{
    move();
    ~move();

    //Allow for plus plus operator to be used on class
    void operator++() { value++; }

    //Allow for plus equals operator to be used on class
    void operator+=(int v) { value += v; }

    //Allow for minus minus operator to be used on class
    void operator--() { value--; }

    //Allow for minus equals operator to be used on class
    void operator-=(int v) { value -= v; }

    //Allow for equal operator to be used on class
    void operator=(move &m1);

    int position; //Position on board
    MoveType type; //Type of move stored
    int value; //Statistical value on position
};