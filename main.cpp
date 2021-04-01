#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "utils.h"
#include "game.h"
#include "render.h"

using namespace std;

int main(int argc, char* argv[])
{
    Game game;
    Draw draw;
    initSDL();
    draw.background();
    game.khoiTaoBanDau();
    g_render.present();
    game.startGame();
    quitSDL();
    return 0;
}
