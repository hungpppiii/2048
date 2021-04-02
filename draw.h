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
    Draw();
    ~Draw();
    void setFont(const string &path, const int &sizeFont);
    SDL_Rect drawText(string &path, const int &i, const SDL_Rect &drect);
    void background();
    void drawSquare2_4(const int &so, const int &x, const int &y);
    void drawSquare(const int &so, const int &x, const int &y);
    SDL_Rect setRect(const int &x, const int &y, const int &h, const int &w);
private:
    int cell_num;
    int le ;
    int dienTich;
    TTF_Font* font = NULL;
    SDL_Color color[2];
};

#endif // DRAW_H_INCLUDED
