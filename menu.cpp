#include "menu.h"
#include <string>

Menu::Menu(){}

Menu::~Menu(){}

int Menu::mainMenu()
{
    //tạo background cho menu
    SDL_Texture* bkgMenu = g_render.loadTexturePath("picture//bkg.jpg");
    SDL_Rect fill_rect = draw.setRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
    g_render.copyTex(bkgMenu, &fill_rect);
    SDL_DestroyTexture(bkgMenu);

    //đặt số item của menu
    int soItem = 2;
    string menuItem[soItem] = {"PLAY GAME", "EXIT"};
    SDL_Rect dsRect[soItem], rect[soItem];
    //gán tạo độ cho từng item, lấy tọa độ mới
    for(int i = 0; i < soItem; i++)
    {
        dsRect[i].x = SCREEN_WIDTH / 2;
        dsRect[i].y = SCREEN_HEIGHT / 6 + i * (SCREEN_HEIGHT / 4 * 3) / soItem;
        rect[i] = draw.drawText(menuItem[i], 0, dsRect[i]);
    }
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
                        if(check(x, y, rect[i]))
                        {
                            if(select[i]){
                                select[i] = false;
                                draw.drawText(menuItem[i], 1, dsRect[i]);
                            }
                        }
                        else
                        {
                            if(select[i] == false)
                            {
                                select[i] = true;
                                draw.drawText(menuItem[i], 0, dsRect[i]);
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

//check xem chuột có đến đúng vị trí item menu ko
bool Menu::check(int &x, int &y, const SDL_Rect &rect)
{
    if(x >= rect.x && x <= (rect.x + rect.w) && y >= rect.y && y <= (rect.y + rect.h))
        return 1;
    return 0;
}
