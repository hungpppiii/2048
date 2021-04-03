#include "menu.h"
#include <string>

Menu::Menu()
{
     soItem = 2;
     menuItem[0] = "NEW GAME";
     menuItem[1] = "EXIT";
}

Menu::~Menu(){}

void Menu::drawText(const int &i, const int &color)
{
    draw.drawText(menuItem[i], color, dsRect[i], 90);
}

void Menu::backgroundMenu()
{
    SDL_Texture* bkgMenu = g_render.loadTexturePath("picture//bkg.jpg");
    SDL_Rect fill_rect = draw.setRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
    g_render.copyTex(bkgMenu, &fill_rect);
    SDL_DestroyTexture(bkgMenu);
}

void Menu::mainMenu()
{
    //gán tạo độ cho từng item, lấy tọa độ mới
    for(int i = 0; i < soItem; i++)
    {
        dsRect[i].x = SCREEN_WIDTH / 2;
        dsRect[i].y = SCREEN_HEIGHT / 6 + i * (SCREEN_HEIGHT / 4 * 3) / soItem;
        rect[i] = draw.drawText(menuItem[i], 0, dsRect[i], 90);
    }
}

void Menu::gameMenu()
{
    //gán tạo độ cho từng item, lấy tọa độ mới
    for(int i = 0; i < soItem; i++)
    {
        dsRect[i].x = SCREEN_WIDTH * 3 / 4;
        dsRect[i].y = SCREEN_HEIGHT * 4 / 9 + i * (SCREEN_HEIGHT / 5);

        rect[i] = draw.drawText(menuItem[i], 0, dsRect[i], 90);
    }
    /*for(int i = soItem - 2; i < soItem; i++)
    {
        dsRect[i].x = SCREEN_WIDTH * 3 / 4;
        dsRect[i].y = SCREEN_HEIGHT / 4 + (i - 2) * (SCREEN_HEIGHT / 3) / (soItem);
        rect[i] = draw.drawText(menuItem[i], 0, dsRect[i], 60);
    }*/

}


int Menu::mouseEvent()
{
    //xử lý sự kiện chuột
    SDL_Event e;
    bool select[soItem] = {false};
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

                    for(int i = 0; i < soItem; i++)
                    {
                        if(check(x, y, i))
                        {
                            if(select[i]){
                                select[i] = false;
                                draw.drawText(menuItem[i], 1, dsRect[i], 90);
                            }
                        }
                        else
                        {
                            if(select[i] == false)
                            {
                                select[i] = true;
                                draw.drawText(menuItem[i], 0, dsRect[i], 90);
                            }
                        }
                    }
                    break;
                }

            case SDL_MOUSEBUTTONDOWN:
                {
                    int x = e.motion.x;
                    int y = e.motion.y;

                    for(int i = 0; i < soItem; i++)
                    {
                        if(check(x, y, i))
                        {
                            return i;
                        }
                    }

                }
            }
        }
    }
}

//check xem chuột có đến đúng vị trí item menu ko
bool Menu::check(int &x, int &y, const int &i)
{
    if(x >= rect[i].x && x <= (rect[i].x + rect[i].w) && y >= rect[i].y && y <= (rect[i].y + rect[i].h))
        return 1;
    return 0;
}
