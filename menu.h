#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "render.h"
#include "draw.h"

class Menu
{
public:
    Menu();
    ~Menu();
    void playMusic();
    void playSoundEffect(const int &i);
    void drawMenuText(const int &i, const int &color);
    void drawGameMenu(const string &point, const string &highScore);
    void backgroundMenu();
    void iconSound(const bool &music);
    bool checkPlayMusic(const int &x, const int &y);
    void mainMenu();
    void gameMenu();
    int mouseEvent(bool &music);
    bool check(int &x, int &y, const int &i);
private:
    Draw draw;
    int soItem;
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
