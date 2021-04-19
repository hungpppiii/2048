#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "render.h"
#include "draw.h"

class Menu
{
public:
    Menu();
    ~Menu();
    void drawMenuText(const int &i, const int &color);
    void drawGameMenu(const string &point, const string &highScore);
    void backgroundMenu();
    void mainMenu();
    void gameMenu();
    int mouseEvent();
    bool check(int &x, int &y, const int &i);
private:
    Draw draw;
    int soItem;
    string menuItem[2], pointItem[2];
    SDL_Rect dsRect[2], rect[2], point_rect[2];
};

#endif // MENU_H_INCLUDED
