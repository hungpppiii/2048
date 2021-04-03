#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "utils.h"
#include "game.h"
#include "render.h"
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
    bool restart = true;
    SDL_Event e;
    if(menu.mouseEvent() == 0)
    {
        while(restart)
        {
            restart = false;
            draw.background();
            g_render.present();
            game.startGame(restart);
        }
    }

    //g_render.present();
    //SDL_Delay(50000);
    /*draw.background();
    game.khoiTaoBanDau();
    g_render.present();
    game.startGame();*/
    quitSDL();
    return 0;
}
