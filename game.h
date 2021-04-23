#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "draw.h"
#include "menu.h"


class Game
{
public:
    Game();
    ~Game();
    void startGame();
    bool winGame();
    bool endGame();
    void restart(const bool &music);
    void getHighScore();
    void saveHighScore();
    bool getPoint_CheckWin(bool &music);

    void left(bool &check);
    void right(bool &check);
    void up(bool &check);
    void down(bool &check);

    void hamLeft_Right(const int &row, const int &col, const int &x, bool &check);
    void hamUp_Down(const int &row, const int &col, const int &x, bool &check);

    void drawTable(const bool &music);

    void khoiTaoBanDau();
    bool viTriTrong();
    void khoiTaoThemSo();
private:
    int mangInRa[4][4] = {0};
    int highScore; //.................
    int diem;
    int diemCong;
    Draw draw;
    Menu menu;
};

#endif // GAME_H_INCLUDED
