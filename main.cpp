#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "utils.h"
#include "game.h"
#include "render.h"
//#include "draw.h"

using namespace std;

int main(int argc, char* argv[])
{
    Game game;
    Draw draw;
    initSDL();
    if(draw.mainMenu() == 0)
    {
        draw.background();
        game.khoiTaoBanDau();
        g_render.present();
        game.startGame();
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
