#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <string>
#include "utils.h"

class Draw
{
public:
    Draw();
    ~Draw();

    void gameOver_WinGame(const bool &win);

    void setFont(const string &path, const int &sizeFont);
    SDL_Rect drawText(const string &path, const int &i,
                       const SDL_Rect &drect,  const int &sizeText);
    void background();
    void table();
    void menuTable();

    void drawSquare(const int &so, const int &y, const int &x);
    SDL_Rect setRect(const int &x, const int &y, const int &h, const int &w);
private:
    int cell_num;
    int leTrai, leTren;
    int dienTich;
    TTF_Font* font = NULL;
    SDL_Color color[2];
};

#endif // DRAW_H_INCLUDED
