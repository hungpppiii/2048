#include "draw.h"
#include "render.h"

Draw::Draw()
{
    color[0] = {255, 36, 0};
    color[1] = {255, 215, 0};
    cell_num = 4;
    le = SCREEN_WIDTH / 20;
    dienTich = (SCREEN_HEIGHT - 2 * le) / cell_num;
}
Draw::~Draw()
{
    if(font != NULL)
    {
        TTF_CloseFont(font);
        font = NULL;
    }
}

void Draw::setFont(const string &path, const int &sizeFont)
{
    font = TTF_OpenFont(path.c_str(), sizeFont);
}

SDL_Rect Draw::drawText(const string &path, const int &i,
                         const SDL_Rect &rect, const int &sizeText)
{
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    setFont("QueenieSans.ttf", sizeText); //...............................................
    //string text = to_string(diem);
    surface = TTF_RenderText_Solid(font, path.c_str(), color[i]);
    texture = g_render.loadTextureSurface(surface);
    SDL_FreeSurface(surface);
    SDL_Rect srcRect, dsRect = rect;
    //trả về size của text
    TTF_SizeText(font, path.c_str(), &srcRect.w, &srcRect.h);
    srcRect.x = 0;
    srcRect.y = 0;

    dsRect.x -= srcRect.w / 2;
    dsRect.h = srcRect.h;
    dsRect.w = srcRect.w;

    g_render.copyTex(texture, &srcRect, &dsRect);

    //giải phóng
    SDL_DestroyTexture(texture);
    return dsRect;
}

void Draw::background()
{
    g_render.setColor(153, 255, 255, 255);
    g_render.clears();

    g_render.setColor(255, 255, 102, 255);
    int h_w = dienTich * cell_num;
    SDL_Rect filled_rect = setRect(le, le, h_w, h_w);
    g_render.fillRect(filled_rect);
    table();
    menuTable();
}

void Draw::table()
{
    //g_render.setColor(255, 253, 208, 255);
    SDL_Rect filled_rect;
    g_render.setColor(0, 0, 0, 255);
    for(int row = 0; row < cell_num; row++){
        for(int col = 0; col < cell_num; col++){
            filled_rect = setRect(le + dienTich * row, le + dienTich * col, dienTich, dienTich);
            g_render.drawRect(filled_rect);
        }
    }
}

void Draw::menuTable()
{
    SDL_Rect filled_rect;
    g_render.setColor(255, 253, 208, 255);
    //g_render.setColor(204, 204, 255, 255);
    filled_rect = setRect(le + dienTich * (cell_num + 1), le, dienTich * cell_num, dienTich * 3);
    g_render.fillRect(filled_rect);
}

// vẽ ô trong bảng chơi

void Draw::drawSquare2_4(const int &so, const int &y, const int &x)
{
    SDL_Texture* image = NULL;
    int h_w = dienTich / 2 ;
    SDL_Rect filled_rect = setRect(le + dienTich / 2 * x + 1, le + dienTich / 2 * y + 1, h_w, h_w) ;
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
    }
    SDL_DestroyTexture(image);
}

void Draw::drawSquare(const int &so, const int &y, const int &x)
{
    SDL_Texture* image = NULL;
    int h_w = dienTich - 2;  // -2 để ko che viền ô
    SDL_Rect filled_rect = setRect(le + dienTich * x + 1, le + dienTich * y + 1, h_w, h_w) ;
    switch(so)
    {
    case 0:
        {
            g_render.setColor(255, 255, 102, 255);
            g_render.fillRect(filled_rect);
            return;
        }
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
    g_render.copyTex(image, &filled_rect);
    //cập nhật thay đổi lên màn hình
    SDL_DestroyTexture(image);
    //SDL_RenderPresent(renderer);
}

SDL_Rect Draw::setRect(const int &x, const int &y, const int &h, const int &w)
{
    SDL_Rect fill_rect;
    fill_rect.x = x;
    fill_rect.y = y;
    fill_rect.h = h;
    fill_rect.w = w;
    return fill_rect;
}
