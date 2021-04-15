#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "draw.h"
#include "menu.h"


class Game
{
public:
    void startGame();
    bool winGame();
    bool endGame();
    void restart();
    void getHighScore();
    void saveHighScore();

    void left(bool &check);
    void right(bool &check);
    void up(bool &check);
    void down(bool &check);

    void hamLeft_Right(const int &row, const int &col, const int &x, bool &check);
    void hamUp_Down(const int &row, const int &col, const int &x, bool &check);

    void drawTable();

    void khoiTaoBanDau();
    bool viTriTrong();
    void khoiTaoThemSo();
private:
    int mangInRa[4][4] = {0};
    int highScore = 0;
    int diem = 0;
    int diemCong = 0;
    Draw draw;
    Menu menu;
};

#endif // GAME_H_INCLUDED
