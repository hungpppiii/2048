#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <SDL_ttf.h>
#include <SDL.h>
#include "render.h"
#include "utils.h"
#include "draw.h"

using namespace std;

class Menu
{
public:
    Menu();
    ~Menu();
    int mainMenu();
    bool check(int &x, int &y, const SDL_Rect &rect);
private:
    Draw draw;
};

#endif // MENU_H_INCLUDED
