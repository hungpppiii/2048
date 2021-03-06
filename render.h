#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include "utils.h"

using namespace std;

class Render
{
public:
    void init(SDL_Renderer* renderer);
    void setColor(int r, int g, int b, int a);
    void present();
    void clears();
    //void drawFillRect(SDL_Rect &fillRect);
    //void drawRect(SDL_Rect &fillRect);
    void copyTex(SDL_Texture* texture, const SDL_Rect* dsRect);
    SDL_Texture* loadTexturePath(const string &file);
    SDL_Texture* loadTextureSurface(SDL_Surface* surface);

private:
    SDL_Renderer* m_renderer;
};

extern Render g_render;

#endif // RENDER_H_INCLUDED
