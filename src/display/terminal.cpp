#include <ncurses.h>
#include <queue>

#include "rasterPoint.h"
#include "terminal.h"
#include "point.h"


terminal::terminal()
{
	initscr();
	raw();
	keypad(stdscr, true);
	noecho();
	start_color();
	cbreak();

	getmaxyx(stdscr, height, width);

	height--;
	width--;
}


terminal::~terminal()
{
	endwin();
}


void terminal::screenUpdate()
{
	//Dump memory contents to screen
	refresh();
}


void terminal::draw(std::queue<rasterPoint> raster, char symbol)
{
	rasterPoint  previousPoint = raster.front();
	raster.pop();

	mvaddch(previousPoint.Y, previousPoint.X, symbol);



	while(!raster.empty())
	{
		rasterPoint currentPoint = raster.front();
		raster.pop();

		if (previousPoint.isConnected)
		{
			int deltaX = currentPoint.X - previousPoint.X;
			int deltaY = currentPoint.Y - previousPoint.Y;

			if (deltaX == 0 && deltaY != 0)
				for (int Y = previousPoint.Y;
					((deltaY < 0)? Y > currentPoint.Y : Y < currentPoint.Y);
					((deltaY < 0)? Y-- : Y++))

					mvaddch(Y, currentPoint.X, symbol);

			else if (deltaX != 0 && deltaY == 0)
				for (int X = previousPoint.X;
					((deltaX < 0)? X > currentPoint.X : X < currentPoint.X);
					((deltaX < 0)? X-- : X++))

					mvaddch(currentPoint.Y, X, symbol);
		}
		mvaddch(currentPoint.Y, currentPoint.X, symbol);

		previousPoint = currentPoint;
	}
}

void terminal::draw(point object, char symbol)
{
	mvaddch(object.Y, object.X, symbol);
}
