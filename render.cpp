#include "render.h"
#include "utils.h"
#include <SDL.h>

Render g_render;

void Render::init(SDL_Renderer* renderer)
{
    m_renderer = renderer;
}

void Render::setColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void Render::present()
{
    SDL_RenderPresent(m_renderer);
}
void Render::clears()
{
    SDL_RenderClear(m_renderer);
}
void Render::fillRect(SDL_Rect &rect)
{
    SDL_RenderFillRect(m_renderer, &rect);
}
void Render::drawRect(SDL_Rect &rect)
{
    SDL_RenderDrawRect(m_renderer, &rect);
}

void Render::copyTex(SDL_Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dsRect)
{
    SDL_RenderCopy(m_renderer, texture, srcRect, dsRect);
}

void Render::copyTex(SDL_Texture* texture, const SDL_Rect* dsRect)
{
    SDL_RenderCopy(m_renderer, texture, NULL, dsRect);
}

SDL_Texture* Render::loadTexture(const std::string &file)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	if (loadedImage != NULL){
		texture = SDL_CreateTextureFromSurface(m_renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		if (texture == NULL){
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		logSDLError(cout, "LoadBMP");
	}
	return texture;
}