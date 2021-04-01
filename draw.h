#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "utils.h"

using namespace std;

class Draw
{
public:
    void background();
    void drawSquare(const int &so, const int &x, const int &y);
    SDL_Rect setRect(const int &x, const int &y, const int &h, const int &w);
private:
    int cell_num = 4;
    const int le = SCREEN_WIDTH / 20;
    const int dienTich = (SCREEN_HEIGHT - 2 * le) / cell_num;
};

#endif // DRAW_H_INCLUDED
