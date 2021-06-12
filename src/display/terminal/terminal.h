#pragma once

#include <ncurses.h>
#include <queue>

#include "point.h"
#include "rasterPoint.h"

class Terminal
{
private:
	int width;
	int height;

	bool hasColor;

public:
	Terminal();
	~Terminal();

	int getWidth() { return width; }
	int getHeight() { return height; }

	char getChar() { return getch();};

	void screenUpdate();
	void draw(std::queue<RasterPoint>&);
	void draw(Point&);
};
