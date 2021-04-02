#include "draw.h"
#include "render.h"

void Draw::mainMenu()
{

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
            image = g_render.loadTexture("picture//2.jpg");
            break;
        }
    case 4:
        {
            image = g_render.loadTexture("picture//4.jpg");
            break;
        }
    case 8:
        {
            image = g_render.loadTexture("picture//8.jpg");
            break;
        }
    case 16:
        {
            image = g_render.loadTexture("picture//16.jpg");
            break;
        }
    case 32:
        {
            image = g_render.loadTexture("picture//32.jpg");
            break;
        }
    case 64:
        {
            image = g_render.loadTexture("picture//64.jpg");
            break;
        }
    case 128:
        {
            image = g_render.loadTexture("picture//128.jpg");
            break;
        }
    case 256:
        {
            image = g_render.loadTexture("picture//256.jpg");
            break;
        }
    case 512:
        {
            image = g_render.loadTexture("picture//512.jpg");
            break;
        }
    case 1024:
        {
            image = g_render.loadTexture("picture//1024.jpg");
            break;
        }
    case 2048:
        {
            image = g_render.loadTexture("picture//2048.jpg");
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
