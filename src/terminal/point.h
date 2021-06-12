#pragma once


#include "color.h"


struct Point
{
	int X;
	int Y;
	char symbol;
	int color;


	Point();
	Point(int, int, char);
	Point(int, int, char, int);
	~Point();
};
