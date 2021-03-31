#include "draw.h"
#include "render.h"

void Draw::background()
{
    g_render.setColor(153, 255, 255, 255);
    g_render.clears();

    g_render.setColor(255, 255, 102, 255);
    SDL_Rect filled_rect;
    filled_rect.x = le;
    filled_rect.y = le;
    filled_rect.h = dienTich * cell_num;
    filled_rect.w = dienTich * cell_num;
    g_render.fillRect(filled_rect);

    for(int r = 0; r < cell_num; r++){
        for(int c = 0; c < cell_num; c++){
            SDL_Rect filled_rect;
            filled_rect.x = le + dienTich * r;
            filled_rect.y = le + dienTich * c;
            filled_rect.h = dienTich;
            filled_rect.w = dienTich;
            g_render.setColor(0, 0, 204, 255);
            g_render.drawRect(filled_rect);
        }
    }
    //cập nhật thay đổi lên màn hình
    g_render.present(); //fkjkjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
}


// vẽ ô trong bảng chơi
void Draw::drawSquare(const int &so, const int &x, const int &y)
{
    SDL_Texture* image = NULL;
    SDL_Rect filled_rect;
    filled_rect.x = le + dienTich * x + 1;
    filled_rect.y = le + dienTich * y + 1;
    filled_rect.h = dienTich - 2;
    filled_rect.w = dienTich - 2;
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
            image = g_render.loadTexture("picture//2.bmp");
            break;
        }
    case 4:
        {
            image = g_render.loadTexture("picture//4.bmp");
            break;
        }
    case 8:
        {
            image = g_render.loadTexture("picture//8.bmp");
            break;
        }
    case 16:
        {
            image = g_render.loadTexture("picture//16.bmp");
            break;
        }
    case 32:
        {
            image = g_render.loadTexture("picture//32.bmp");
            break;
        }
    case 64:
        {
            image = g_render.loadTexture("picture//64.bmp");
            break;
        }
    case 128:
        {
            image = g_render.loadTexture("picture//128.bmp");
            break;
        }
    case 256:
        {
            image = g_render.loadTexture("picture//256.bmp");
            break;
        }
    case 512:
        {
            image = g_render.loadTexture("picture//512.bmp");
            break;
        }
    case 1024:
        {
            image = g_render.loadTexture("picture//1024.bmp");
            break;
        }
    case 2048:
        {
            image = g_render.loadTexture("picture//2048.bmp");
            break;
        }
    }

    // đưa ảnh từ texture vào màn hình, ảnh co dãn theo kich thuoc
    g_render.copyTex(image, &filled_rect);
    //cập nhật thay đổi lên màn hình
    SDL_DestroyTexture(image);
    //SDL_RenderPresent(renderer);
}
