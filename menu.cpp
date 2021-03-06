#include "menu.h"

Menu::Menu()
{
    soItem = 2;
    menuItem[0] = "NEW GAME";
    menuItem[1] = "EXIT";
    pointItem[0] = "POINT : ";
    pointItem[1] = "HIGH SCORE : ";

    music_rect.x = SCREEN_WIDTH * 5.1 / 6;
    music_rect.y = SCREEN_HEIGHT / 35;
    music_rect.w = SCREEN_HEIGHT / 10;
    music_rect.h = music_rect.w;

    moveGame = Mix_LoadWAV("music//move.wav");
    click = Mix_LoadWAV("music//click.wav");
    if(moveGame == NULL || click == NULL)
    logSDLError(cout, "loadWAV");
    music = Mix_LoadMUS("music//game.mp3");
    if(music == NULL)
    logSDLError(cout, "loadMUSIC");
}

Menu::~Menu(){}

void Menu::playMusic()
{
    Mix_PlayMusic(music, -1);
}

void Menu::playSoundEffect(const int &action)
{
    switch(action)
        {
        case MOVE:
            {
                Mix_PlayChannel(-1, moveGame, 0);
                break;
            }
        case CLICK:
            {
                Mix_PlayChannel(-1, click, 0);
                break;
            }
        case GAMEOVER:
            {
                gameOver = Mix_LoadWAV("music//lose.wav");
                Mix_PlayChannel(-1, gameOver, 0);
                break;
            }
        case WINGAME:
            {
                winGame = Mix_LoadWAV("music//win.wav");
                Mix_PlayChannel(-1, winGame, 0);
                break;
            }
        }

}

void Menu::drawMenuText(const int &item, const int &color)
{
    draw.drawText(menuItem[item], color, dsRect[item], 90);
}

void Menu::drawGameMenu(const string &point, const string &highScore)
{
    string text[2] = {pointItem[0] + point, pointItem[1] + highScore};
    for(int i = 0; i < 2; i++)
    {
        draw.drawText(text[i], Draw::RED, point_rect[i], 50);
        draw.drawText(menuItem[i], Draw::RED, dsRect[i], 90);
    }

}


void Menu::backgroundMenu()
{
    SDL_Texture* bkgMenu = g_render.loadTexturePath("picture//bkg2048.jpg");
    SDL_Rect fill_rect = draw.setRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
    g_render.copyTex(bkgMenu, &fill_rect);
    SDL_DestroyTexture(bkgMenu);
}

void Menu::iconSound(const bool &music)
{
    SDL_Texture* icon;
    if(music)
    {
        icon = g_render.loadTexturePath("picture//on.png");
    }
    else
    {
        icon = g_render.loadTexturePath("picture//off.png");
    }
    g_render.copyTex(icon, &music_rect);
    SDL_DestroyTexture(icon);
}

void Menu::setStartMenu()
{
    dsRect[0].x = SCREEN_WIDTH * 2.1 / 3;
    dsRect[0].y = SCREEN_HEIGHT / 2.9;
    rect[0] = draw.drawText(menuItem[0], Draw::RED, dsRect[0], 90);

    dsRect[1].x = SCREEN_WIDTH / 10;
    dsRect[1].y = SCREEN_HEIGHT / 1.9;
    rect[1] = draw.drawText(menuItem[1], Draw::RED, dsRect[1], 90);

}

void Menu::setGameMenu()
{
    //g??n t???o ????? cho t???ng item, l???y t???a ????? m???i
    for(int i = 0; i < soItem; i++)
    {
        dsRect[i].x = SCREEN_WIDTH * 2 / 3 + i * SCREEN_WIDTH / 16;
        dsRect[i].y = SCREEN_HEIGHT * 4 / 9 + i * (SCREEN_HEIGHT / 5);

        rect[i] = draw.drawText(menuItem[i], Draw::RED, dsRect[i], 90);

        point_rect[i].x = SCREEN_WIDTH * 2 / 3;
        point_rect[i].y = SCREEN_HEIGHT / 5 + i * SCREEN_HEIGHT / 12;
    }
}


int Menu::mouseEvent(bool &music)
{
    iconSound(music);
    g_render.present();
    //x??? l?? s??? ki???n chu???t
    SDL_Event e;
    bool select[soItem] = {true};
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
                                draw.drawText(menuItem[i], Draw::YELLOW, dsRect[i], 90);
                            }
                        }
                        else
                        {
                            if(select[i] == false)
                            {
                                select[i] = true;
                                draw.drawText(menuItem[i], Draw::RED, dsRect[i], 90);
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
                            //??m thanh click chu???t
                            if(music)
                            {
                                playSoundEffect(CLICK);
                            }
                            return i;
                        }
                    }
                    if(checkPlayMusic(x, y))
                           {
                                music = !music;
                                iconSound(music);
                                g_render.present();
                           }

                }
            }
        }
    }
}

//check xem chu???t c?? ?????n ????ng v??? tr?? item menu ko
bool Menu::check(int &x, int &y, const int &item)
{
    if(x >= rect[item].x && x <= (rect[item].x + rect[item].w)
            && y >= rect[item].y && y <= (rect[item].y + rect[item].h))
        return 1;
    return 0;
}

bool Menu::checkPlayMusic(const int &x, const int &y)
{
    if(x >= music_rect.x && x <= (music_rect.x + music_rect.w)
            && y >= music_rect.y && y <= (music_rect.y + music_rect.h))
        return 1;
    return 0;
}
