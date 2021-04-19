#include "menu.h"

Menu::Menu()
{
     soItem = 2;
     menuItem[0] = "NEW GAME";
     menuItem[1] = "EXIT";
     pointItem[0] = "POINT : ";
     pointItem[1] = "HIGH SCORE : ";
}

Menu::~Menu(){}

void Menu::drawMenuText(const int &i, const int &color)
{
    draw.drawText(menuItem[i], color, dsRect[i], 90);
}

void Menu::drawGameMenu(const string &point, const string &highScore)
{
    string text[2] = {pointItem[0] + point, pointItem[1] + highScore};
    for(int i = 0; i < 2; i++)
    {
        draw.drawText(text[i], 0, point_rect[i], 50);
        draw.drawText(menuItem[i], 0, dsRect[i], 90);
    }

}


void Menu::backgroundMenu()
{
    SDL_Texture* bkgMenu = g_render.loadTexturePath("picture//bkg2048.jpg");
    SDL_Rect fill_rect = draw.setRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
    g_render.copyTex(bkgMenu, &fill_rect);
    SDL_DestroyTexture(bkgMenu);
}

void Menu::mainMenu()
{
        dsRect[0].x = SCREEN_WIDTH * 2.1 / 3;
        dsRect[0].y = SCREEN_HEIGHT / 2.9;
        rect[0] = draw.drawText(menuItem[0], 0, dsRect[0], 90);

        dsRect[1].x = SCREEN_WIDTH / 10;
        dsRect[1].y = SCREEN_HEIGHT / 1.9;
        rect[1] = draw.drawText(menuItem[1], 0, dsRect[1], 90);

}

void Menu::gameMenu()
{
    //gán tạo độ cho từng item, lấy tọa độ mới
    for(int i = 0; i < soItem; i++)
    {
        dsRect[i].x = SCREEN_WIDTH * 2 / 3 + i * SCREEN_WIDTH / 16;
        dsRect[i].y = SCREEN_HEIGHT * 4 / 9 + i * (SCREEN_HEIGHT / 5);

        rect[i] = draw.drawText(menuItem[i], 0, dsRect[i], 90);

        point_rect[i].x = SCREEN_WIDTH * 2 / 3;
        point_rect[i].y = SCREEN_HEIGHT / 5 + i * SCREEN_HEIGHT / 12;
    }
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
