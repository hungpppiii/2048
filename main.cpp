#include <iostream>
#include "game.h"
#include "menu.h"

using namespace std;


int main(int argc, char* argv[])
{
    initSDL();

    Game game;
    Draw draw;
    Menu menu;
    bool music = true;

    menu.backgroundMenu();
    //lay toa do cho cac item cua menu bat dau
    menu.setStartMenu();
    //play nhạc game
    /*if(music)
    {
        menu.playMusic();
    }*/

    if(menu.mouseEvent(music) == 0)
    {
        game.getHighScore();
        //lay toa do cho cac item cua menu trong game
        menu.setGameMenu();
        //ve lai man hinh
        game.drawScreen(music);
        //khoi tao 2 soban dau cho game
        game.khoiTaoBanDau();


        bool check, gameContinue = true;
        //tạo biến để tránh lặp music ở game over
        bool loopMusic = true;
        bool select[2] = {true};
        SDL_Event e;
        while(gameContinue)
        {
            //khi bảng đầy thì kiểm tra xem đã end game chưa
            if(game.viTriTrong() == 0){
                if(game.endGame()){
                    if(music && loopMusic){
                        loopMusic =  false;
                        menu.playSoundEffect(Menu::GAMEOVER);
                    }
                    draw.gameOver_WinGame(false);
                }
            }

            // kiểm tra xem có sự kiện bàn phím không
            while(SDL_PollEvent(&e) != 0)
            {
                switch (e.type)
                {
                case SDL_QUIT:
                    {
                        gameContinue = false;
                        break;
                    }
                case SDL_KEYDOWN:
                    {
                        check = false;
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_UP:
                            {
                                game.up(check);
                                break;
                            }
                        case SDLK_DOWN:
                            {
                                game.down(check);
                                break;
                            }
                        case SDLK_RIGHT:
                            {
                                game.right(check);
                                break;
                            }
                        case SDLK_LEFT:
                            {
                                game.left(check);
                                break;
                            }
                        }

                        // check xem bảng có thay đổi sau khi nhấn phím
                        // thay đổi thì tạo thêm số
                        if(check)
                        {
                            if(music)
                            {
                                menu.playSoundEffect(Menu::MOVE);
                            }
                            if(!game.getPoint_CheckWin(music))
                            {
                                gameContinue = false;
                                break;
                            }
                        }

                    }
                case SDL_MOUSEMOTION:
                    {
                        int x = e.motion.x;
                        int y = e.motion.y;

                        for(int i = 0; i < 2; i++)
                        {
                            if(menu.check(x, y, i))
                            {
                                if(select[i]){
                                    select[i] = false;
                                    menu.drawMenuText(i, Draw::YELLOW);
                                    g_render.present();
                                }
                            }
                            else
                            {
                                if(!select[i])
                                {
                                    select[i] = true;
                                    menu.drawMenuText(i, Draw::RED);
                                    g_render.present();
                                }
                            }
                        }
                    break;
                    }
                case SDL_MOUSEBUTTONDOWN:
                    {
                        int x = e.motion.x;
                        int y = e.motion.y;

                        for(int i = 0; i < 2; i++)
                        {
                            if(menu.check(x, y, i))
                                {
                                    //âm thanh click chuột
                                    if(music)
                                        {
                                            menu.playSoundEffect(Menu::CLICK);
                                        }
                                    if(i == 0)
                                    {
                                        loopMusic = true;
                                        game.restart(music);
                                        select[i] = true;
                                    }
                                    else
                                    {
                                        gameContinue = false;
                                        break;
                                    }
                            }

                        }
                        if(menu.checkPlayMusic(x, y))
                           {
                                music = !music;
                                menu.iconSound(music);
                                g_render.present();
                           }
                    }
                }
            }
        }
        game.saveHighScore();
    }
    //dừng để nghe âm click
    SDL_Delay(200);
    quitSDL();
    return 0;
}
