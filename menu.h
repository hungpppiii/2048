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
    void drawText(const int &i, const int &color);
    void backgroundMenu();
    void mainMenu();
    void gameMenu();
    int mouseEvent();
    bool check(int &x, int &y, const int &i);
private:
    Draw draw;
    int soItem;
    string menuItem[2];
    SDL_Rect dsRect[2], rect[2];
};

#endif // MENU_H_INCLUDED
