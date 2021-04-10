#include "utils.h"

extern const int SCREEN_WIDTH = 1300;
extern const int SCREEN_HEIGHT = 700;

extern const string WINDOW_TITLE = "GAME 2048";

SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;

void logSDLError(ostream& os,
                 const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}


//Hàm khởi tạo bút vẽ
void initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        logSDLError(cout, "SDL_Init", true);

    if (TTF_Init() < 0)
		logSDLError(cout, "TTF_Init", true);

    g_window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //g_window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (g_window == NULL)
            logSDLError(cout, "CreateWindow", true);

    int imgFlags = IMG_INIT_JPG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
        logSDLError(cout, "IMG_Init", true);

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

    g_render.init(g_renderer);
    if (g_renderer == NULL) logSDLError(cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(g_renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

//Hàm giải phóng bút vẽ
void quitSDL()
{
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	SDL_Quit();
}
