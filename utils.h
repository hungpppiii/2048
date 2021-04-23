#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>
#include "render.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const string WINDOW_TITLE;

void logSDLError(ostream& os,
                 const string &msg, bool fatal = false);
void initSDL();
void quitSDL();


#endif // UTILS_H_INCLUDED
