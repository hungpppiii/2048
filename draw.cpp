#include "draw.h"
#include "render.h"

int Draw::mainMenu()
{
    SDL_Texture* menu = g_render.loadTexturePath("picture//bkg.jpg");
    SDL_Rect fill_rect = setRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
    g_render.copyTex(menu, &fill_rect);
    SDL_DestroyTexture(menu);

    int menuItem = 2;
    SDL_Color color[2];
    color[0] = {127, 255, 212};
    color[1] = {255, 36, 0};
    string path[menuItem] = {"PLAY GAME", "EXIT"};
    SDL_Rect dsRect[menuItem], rect[menuItem];
    for(int i = 0; i < menuItem; i++)
    {
        dsRect[i].x = SCREEN_WIDTH / 2;
        dsRect[i].y = SCREEN_HEIGHT / 6 + i * (SCREEN_HEIGHT / 4 * 3) / menuItem;
        rect[i] = drawText(path[i], color[0], dsRect[i]);
    }
    SDL_Event e;
    bool select[menuItem] = {false};
    while(true)
    {
        g_render.present();
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
            case SDL_QUIT:
                return 1;

            case SDL_MOUSEMOTION:
                {
                    int x = e.motion.x;
                    int y = e.motion.y;

                    for(int i = 0; i < menuItem; i++)
                    {
                        if(check(x, y, rect[i]))
                        {
                            if(select[i]){
                                select[i] = false;
                                drawText(path[i], color[1], dsRect[i]);
                            }
                        }
                        else
                        {
                            if(select[i] == false)
                            {
                                select[i] = true;
                                drawText(path[i], color[0], dsRect[i]);
                            }
                        }
                    }
                    break;
                }

            case SDL_MOUSEBUTTONDOWN:
                {
                    int x = e.motion.x;
                    int y = e.motion.y;

                    for(int i = 0; i < menuItem; i++)
                    {
                        if(check(x, y, rect[i]))
                        {
                            return i;
                        }
                    }

                }

            }
        }
    }
    g_render.present();
}

bool Draw::check(int &x, int &y, const SDL_Rect &rect)
{
    if(x >= rect.x && x <= (rect.x + rect.w) && y >= rect.y && y <= (rect.y + rect.h))
        return 1;
    return 0;
}

SDL_Rect Draw::drawText(string &path, SDL_Color &color, const SDL_Rect &rect)
{
    SDL_Surface* surface = NULL;
    TTF_Font* font = NULL;
    SDL_Texture* texture = NULL;
    font = TTF_OpenFont("QueenieSans.ttf", 90);
    //string text = to_string(diem);
    surface = TTF_RenderText_Solid(font, path.c_str(), color);
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

    for(int row = 0; row < cell_num; row++){
        for(int col = 0; col < cell_num; col++){
            SDL_Rect filled_rect = setRect(le + dienTich * row, le + dienTich * col, dienTich, dienTich);
            g_render.setColor(0, 0, 204, 255);
            g_render.drawRect(filled_rect);
        }
    }
    //cập nhật thay đổi lên màn hình
    g_render.present(); //fkjkjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
}


// vẽ ô trong bảng chơi

void Draw::drawSquare2_4(const int &so, const int &x, const int &y)
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

void Draw::drawSquare(const int &so, const int &x, const int &y)
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
