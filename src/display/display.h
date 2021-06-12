#pragma once

#include <string>
#include "displayMode.h"
#include "terminal/terminal.h"


class Display
{
private:
    Terminal terminal;

    int *board;

    void splash();
    int menu();
    void computerBoard(int*);
    int humanBoard(int*);
    void winner(int*, int);
    void draw(int*);

    std::vector<std::string> getAscii(std::string);
    void showAscii(std::vector<std::string>&);

public:
    Display(int*);
    ~Display();

    int show(DisplayMode, int);
};