#pragma once

#include <ncurses.h>
#include <queue>

#include "point.h"
#include "rasterPoint.h"

class terminal
{
private:
	int width;
	int height;

public:
	terminal();
	~terminal();

	int getWidth() { return width; }
	int getHeight() { return height; }

	char getChar() { return getch();};

	void screenUpdate();
	void draw(std::queue<rasterPoint>, char);
	void draw(point, char);
};
