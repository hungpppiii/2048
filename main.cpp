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

    menu.backgroundMenu();
    //lay toa do cho cac item cua menu bat dau
    menu.mainMenu();

    if(menu.mouseEvent() == 0)
    {
        game.getHighScore();
        //lay toa do cho cac item cua menu trong game
        menu.gameMenu();
        //ve lai man hinh
        game.drawTable();
        //khoi tao 2 soban dau cho game
        game.khoiTaoBanDau();

        bool check, gameContinue = true;
        bool select[2] = {false};
        SDL_Event e;
        while(gameContinue)
        {
            //khi bảng đầy thì kiểm tra xem đã end game chưa
            if(game.viTriTrong() == 0){
                if(game.endGame()){
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
                        if(check){
                            if(!game.getPoint_CheckWin())
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
                                    menu.drawMenuText(i, 1);
                                    g_render.present();
                                }
                            }
                            else
                            {
                                if(select[i] == false)
                                {
                                    select[i] = true;
                                    menu.drawMenuText(i, 0);
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
                                if(i == 0)
                                {
                                    game.restart();
                                    select[i] = true;
                                }
                                else
                                {
                                    gameContinue = false;
                                    break;
                                }

                            }
                        }
                    }
                }
            }
        }
        game.saveHighScore();
    }
    quitSDL();
    return 0;
}
