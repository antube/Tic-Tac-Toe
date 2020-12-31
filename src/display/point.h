#pragma once

struct point
{
	int X;
	int Y;

	point();
	point(int, int);
	~point();
};

inline point::point()
{
	X = 0;
	Y = 0;
}

inline point::point(int x, int y)
{
	X = x;
	Y = y;
}

inline point::~point()
{
	X = 0;
	Y = 0;
}
