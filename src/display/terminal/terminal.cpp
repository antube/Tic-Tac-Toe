#include <ncurses.h>
#include <queue>

#include "rasterPoint.h"
#include "terminal.h"
#include "point.h"
#include "color.h"


Terminal::Terminal()
{
	initscr();
	raw();
	keypad(stdscr, true);
	noecho();
	cbreak();

	hasColor = has_colors();

	if (hasColor)
	{
		start_color();

		init_pair(COLOR_LOGO, COLOR_BLUE, COLOR_BLACK);
		init_pair(COLOR_MENU, COLOR_CYAN, COLOR_BLACK);
		init_pair(COLOR_O_PIECE, COLOR_BLUE, COLOR_BLACK);
		init_pair(COLOR_X_PIECE, COLOR_RED, COLOR_BLACK);
		init_pair(COLOR_BOARD, COLOR_GREEN, COLOR_BLACK);
		init_pair(COLOR_BOARD_SELECT, COLOR_BLACK, COLOR_WHITE);
		init_pair(COLOR_MENU_SELECT, COLOR_WHITE, COLOR_GREEN);
	}

	getmaxyx(stdscr, height, width);

	height--;
	width--;
}


Terminal::~Terminal()
{
	endwin();
}


void Terminal::screenUpdate()
{
	//Dump memory contents to screen
	refresh();
}


void Terminal::draw(std::queue<RasterPoint> &raster)
{
	if (raster.size() == 0)
		return;

	RasterPoint  previousPoint = raster.front();
	raster.pop();

	if (hasColor && previousPoint.color != 0)
		attron(COLOR_PAIR(previousPoint.color));

	mvaddch(previousPoint.Y, previousPoint.X, previousPoint.symbol);

	if (hasColor && previousPoint.color != 0)
		attroff(COLOR_PAIR(previousPoint.color));



	while(!raster.empty())
	{
		RasterPoint currentPoint = raster.front();
		raster.pop();

		if (hasColor && currentPoint.color != 0)
			attron(COLOR_PAIR(currentPoint.color));

		if (previousPoint.isConnected)
		{
			int deltaX = currentPoint.X - previousPoint.X;
			int deltaY = currentPoint.Y - previousPoint.Y;

			if (deltaX == 0 && deltaY != 0)
				for (int Y = previousPoint.Y;
					((deltaY < 0)? Y > currentPoint.Y : Y < currentPoint.Y);
					((deltaY < 0)? Y-- : Y++))

					mvaddch(Y, currentPoint.X, previousPoint.symbol);

			else if (deltaX != 0 && deltaY == 0)
				for (int X = previousPoint.X;
					((deltaX < 0)? X > currentPoint.X : X < currentPoint.X);
					((deltaX < 0)? X-- : X++))

					mvaddch(currentPoint.Y, X, previousPoint.symbol);
		}
		mvaddch(currentPoint.Y, currentPoint.X, previousPoint.symbol);

		previousPoint = currentPoint;

		if (hasColor && currentPoint.color != 0)
			attroff(COLOR_PAIR(currentPoint.color));
	}
}

void Terminal::draw(Point &object)
{
	if (hasColor && object.color != 0)
		attron(COLOR_PAIR(object.color));

	mvaddch(object.Y, object.X, object.symbol);

	if (hasColor && object.color != 0)
		attroff(COLOR_PAIR(object.color));
}
