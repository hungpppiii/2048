#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "render.h"
#include "draw.h"

class Menu
{
public:
    enum
    {
        MOVE,
        CLICK,
        WINGAME,
        GAMEOVER
    };

    Menu();
    ~Menu();
    void playMusic();
    void playSoundEffect(const int &action);
    void drawMenuText(const int &item, const int &color);
    void drawGameMenu(const string &point, const string &highScore);
    void backgroundMenu();
    void iconSound(const bool &music);
    void setStartMenu();
    void setGameMenu();
    int mouseEvent(bool &music);
    bool check(int &x, int &y, const int &item);
    bool checkPlayMusic(const int &x, const int &y);
private:
    Draw draw;
    int soItem = 2;
    string menuItem[2], pointItem[2];
    SDL_Rect dsRect[2], rect[2], point_rect[2];
    SDL_Rect music_rect;
    Mix_Chunk* moveGame = NULL;
    Mix_Chunk* click = NULL;
    Mix_Chunk* gameOver = NULL;
    Mix_Chunk* winGame = NULL;
    Mix_Music* music = NULL;
};

#endif // MENU_H_INCLUDED
