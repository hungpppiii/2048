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
    SDL_Rect drawText(const string &path, const int &i,
                       const SDL_Rect &drect,  const int &sizeText);
    void background();
    void table();
    void menuTable();

    void drawSquare2_4(const int &so, const int &y, const int &x);
    void drawSquare(const int &so, const int &y, const int &x);
    SDL_Rect setRect(const int &x, const int &y, const int &h, const int &w);
private:
    int cell_num;
    int le ;
    int dienTich;
    TTF_Font* font = NULL;
    SDL_Color color[2];
};

#endif // DRAW_H_INCLUDED
