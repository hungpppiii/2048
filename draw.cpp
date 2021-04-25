#include "draw.h"

Draw::Draw()
{
    color[RED] = {255, 36, 0, 255};
    color[YELLOW] = {255, 215, 0, 255};
    cell_num = 4;
    leTrai = SCREEN_WIDTH / 20;
    leTren = 1.5 * leTrai;
    dienTich = (SCREEN_HEIGHT - 2 * leTrai) / cell_num;
    //load ảnh background của game
    bkg = g_render.loadTexturePath("picture//bggame.png");
}
Draw::~Draw()
{
    if(font != NULL)
    {
        TTF_CloseFont(font);
        font = NULL;
    }
    if(bkg != NULL)
    {
        SDL_DestroyTexture(bkg);
    }
}

void Draw::gameOver_WinGame(const bool &win)
{
    SDL_Texture* image = NULL;
    SDL_Rect rect;
    if(win)
    {
        image = g_render.loadTexturePath("picture//WinGame.png");
        rect = setRect(leTrai + dienTich * 0.5, leTren + dienTich * 1.5, dienTich, 3 * dienTich);
        g_render.copyTex(image, &rect);
    }
    else
    {
        image = g_render.loadTexturePath("picture//GameOver.png");
        rect = setRect(leTrai + dienTich * 0.05, leTren + dienTich * 1.5, dienTich, 4 * dienTich);
        g_render.copyTex(image, &rect);
    }
    g_render.present();
    SDL_DestroyTexture(image);
}


SDL_Rect Draw::drawText(const string &path, const int &colors,
                         const SDL_Rect &rect, const int &sizeText)
{
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    font = TTF_OpenFont("fonts//SF Atarian System.ttf", sizeText);
    surface = TTF_RenderText_Solid(font, path.c_str(), color[colors]);
    texture = g_render.loadTextureSurface(surface);
    SDL_FreeSurface(surface);

    SDL_Rect dsRect = rect;
    //trả về size của text
    TTF_SizeText(font, path.c_str(), &dsRect.w, &dsRect.h);
    //copy texture vào màn hình
    g_render.copyTex(texture, &dsRect);
    //giải phóng texture
    SDL_DestroyTexture(texture);
    return dsRect;
}

void Draw::background()
{
    SDL_Rect rect = setRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
    g_render.copyTex(bkg, &rect);
}

void Draw::drawSquare(const int &so, const int &y, const int &x)
{
    SDL_Texture* image = NULL;
    int h_w = dienTich - 2;  // -2 để ko che viền ô
    SDL_Rect rect = setRect(leTrai + dienTich * x + 1, leTren + dienTich * y + 1, h_w, h_w) ;
    switch(so)
    {
    case 2:
        {
            image = g_render.loadTexturePath("picture//2.jpg");
            break;
        }
    case 4:
        {
            image = g_render.loadTexturePath("picture//4.jpg");
            break;
        }
    case 8:
        {
            image = g_render.loadTexturePath("picture//8.jpg");
            break;
        }
    case 16:
        {
            image = g_render.loadTexturePath("picture//16.jpg");
            break;
        }
    case 32:
        {
            image = g_render.loadTexturePath("picture//32.jpg");
            break;
        }
    case 64:
        {
            image = g_render.loadTexturePath("picture//64.jpg");
            break;
        }
    case 128:
        {
            image = g_render.loadTexturePath("picture//128.jpg");
            break;
        }
    case 256:
        {
            image = g_render.loadTexturePath("picture//256.jpg");
            break;
        }
    case 512:
        {
            image = g_render.loadTexturePath("picture//512.jpg");
            break;
        }
    case 1024:
        {
            image = g_render.loadTexturePath("picture//1024.jpg");
            break;
        }
    case 2048:
        {
            image = g_render.loadTexturePath("picture//2048.jpg");
            break;
        }
    }

    // đưa ảnh từ texture vào màn hình, ảnh co dãn theo kich thuoc
    g_render.copyTex(image, &rect);
    //hủy texture
    SDL_DestroyTexture(image);
}

SDL_Rect Draw::setRect(const int &x, const int &y, const int &h, const int &w)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;
    return rect;
}
