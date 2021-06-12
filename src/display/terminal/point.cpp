#include "point.h"


Point::Point()
{
	X = 0;
	Y = 0;
    symbol = 0x0;
    color = 1;
}


Point::Point(int x, int y, char chara)
{
	X = x;
	Y = y;
    symbol = chara;
    color = 1;
}


Point::Point(int x, int y, char chara, int col)
{
    X = x;
    Y = y;
    symbol = chara;
    color = col;
}


Point::~Point()
{
	X = 0;
	Y = 0;
    symbol = 0x0;
    color = 0;
}