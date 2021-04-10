#include <iostream>
#include "game.h"
#include "menu.h"

using namespace std;

int main(int argc, char* argv[])
{
    Game game;
    Draw draw;
    Menu menu;
    initSDL();
    menu.backgroundMenu();
    menu.mainMenu();
    SDL_Event e;
    if(menu.mouseEvent() == 0)
    {
        game.startGame();
    }
    quitSDL();
    return 0;
}
