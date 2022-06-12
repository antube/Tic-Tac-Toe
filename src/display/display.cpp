#include <queue>
#include <vector>
#include <string>
#include <fstream>

#include "display.h"
#include "displayMode.h"
#include "terminal/point.h"
#include "terminal/rasterPoint.h"
#include "terminal/color.h"


Display::Display(int *b)
{
    board = b;
}


Display::~Display()
{
    terminal.~Terminal();
}


int Display::show(DisplayMode mode, int player)
{
    switch (mode)
    {
        case Splash:
            splash();
            break;

        case Menu:
            return menu();
            break;

        case Board_Human:
            return humanBoard(board);
            break;

        case Board_Computer:
            computerBoard(board);
            break;
        
        case Win:
            winner(board, player);
            break;

        case Draw:
            draw(board);
            break;

        default:

            break;
    }

    terminal.screenUpdate();

    return 0;
}


void Display::splash()
{
    unsigned int splashWidth = 0;
    unsigned int splashHeight = 0;

    std::vector<std::string> splash;

    splash = getAscii("splash.ascii");

    splashHeight = splash.size();

    for (std::string str : splash)
        if (splashWidth == 0)
            splashWidth = str.length();
        else if (splashWidth < str.length())
            splashWidth = str.length();


    int topX = (terminal.getWidth() - splashWidth) >> 1;
    int topY = (terminal.getHeight() - splashHeight) >> 1;

    std::queue<RasterPoint> raster;

    for (std::string str : splash)
    {
        int xOffSet = 0;

        for (char c : str)
        {
            RasterPoint r;
            r.symbol = c;
            r.X = topX + xOffSet;
            r.Y = topY;
            r.color = COLOR_LOGO;
            r.isConnected = false;

            raster.push(r);

            xOffSet++;
        }

        topY++;
    }

    terminal.draw(raster);
}


int Display::menu()
{
    std::vector<std::string> logo;

    logo = getAscii("logo.ascii");

    return 0;
}


void Display::computerBoard(int *board)
{
    
}


int Display::humanBoard(int *board)
{

    return 0;
}


void Display::winner(int *board, int player)
{

}


void Display::draw(int *board)
{

}


std::vector<std::string> Display::getAscii(std::string path)
{
    std::vector<std::string> logo;

    std::ifstream infile;

    infile.open(path, std::ios::in);

    if (!infile)
        return logo;

    std::string line;

    while (std::getline(infile, line))
    {
        logo.push_back(line);
    }

    infile.close();

    return logo;
}