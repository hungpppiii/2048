#include <iostream>
#include "draw.h"
#include "game.h"
#include "render.h"



using namespace std;


void Game::startGame(bool &checkRestart)
{
    restart();
    menu.gameMenu();
    khoiTaoBanDau();
    //int soItem
    bool select[2] = {false};
    while(true)
    {
        //khi bảng đầy thì kiểm tra xem đã end game chưa
        if(viTriTrong() == 0){
            if(endGame()){
                cout << "game over!!!";
                return;
            }
        }
        SDL_Event e;
        // kiểm tra xem có sự kiện bàn phím không
        while(SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                return;
            case SDL_KEYDOWN:
                {
                    bool check = false;
                    switch(e.key.keysym.sym)
                    {
                    case SDLK_UP:
                        {
                            left(check);
                            break;
                        }
                    case SDLK_DOWN:
                        {
                            right(check);
                            break;
                        }
                    case SDLK_RIGHT:
                        {
                            down(check);
                            break;
                        }
                        break;;
                    case SDLK_LEFT:
                        {
                            up(check);
                            break;
                        }
                    }

                    // check xem bảng có thay đổi sau khi nhấn phím
                    // thay đổi thì tạo thêm số
                    if(check){
                        //check xem thắng chưa
                        // 9 * 1024 = 9216
                        if(diem >= 9216){
                            if( winGame() ){
                                cout << "Victory" << endl;
                                return;
                            }
                        }

                        g_render.setColor(153, 255, 255, 255);
                        g_render.clears();
                        draw.table();
                        draw.menuTable();
                        menu.gameMenu();
                        drawTable();
                        g_render.present();

                        //khoi tao them so
                        khoiTaoThemSo();
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
                                menu.drawText(i, 1);
                                g_render.present();
                            }
                        }
                        else
                        {
                            if(select[i] == false)
                            {
                                select[i] = true;
                                menu.drawText(i, 0);
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
                                checkRestart = true;//dkjfhdksjdddddddddddddddddddddddddddd
                            return;
                        }
                    }
                }
            }
        }
    }
}

bool Game::winGame()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(mangInRa[i][j] == 2048){
                return true;
            }
        }
    }
    return false;
}


// kiểm tra game kết thúc chưa
bool Game::endGame()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((mangInRa[i][j] == mangInRa[i][j+1]) || (mangInRa[i][j] == mangInRa[i+1][j])){
                return 0;
            }
        }
        if((mangInRa[i][3] == mangInRa[i+1][3]) || (mangInRa[3][i] == mangInRa[3][i+1])){
            return 0;
        }
    }
    return true;
}

void Game::restart()
{
    for (int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            mangInRa[i][j] = 0;
    diem = 0;
}

void Game::highScore()
{

}

//++++++++++++++++++++++++++++++++++++++++
void Game::left(bool &check)
{
    for(int i = 0; i < 4; i++){
        int j = 0;
        hamLeft_Right(i, j, 1, check);
    }
}

void Game::right(bool &check)
{
    for(int i = 0; i < 4; i++){
        int j = 3;
        hamLeft_Right(i, j, -1, check);
    }
}

void Game::up(bool &check)
{
    for(int j = 0; j < 4; j++){
        int i = 0;
        hamUp_Down(i, j, 1, check);
    }
}

void Game::down(bool &check)
{
    for(int j = 0; j < 4; j++){
        int i = 3;
        hamUp_Down(i, j, -1, check);
    }
}

//**************************************************

// thuc hien lenh sang trai hoạc phải
void Game::hamLeft_Right(const int &row, const int &col, const int &x, bool &check)
{
    int n;
    if(x == 1) n = 3;
    else n = 0;
    for(int j = col + x; (j * x) <= n; j = j + x){
        //kiểm tra xem ô này có khác 0
        if(mangInRa[row][col]){
            //2 ô gần nhất có giá trị bằng nhau và khác 0 thì cộng lại
            if(mangInRa[row][col] == mangInRa[row][j]){
            mangInRa[row][col] = mangInRa[row][col] * 2;
            diem += mangInRa[row][col];
            check = true;
            mangInRa[row][j] = 0;
            hamLeft_Right(row, col+x, x, check);
            break;
            }//kiểm tra hết với các ô phía sau(ko thay đổi) thì kiểm tra ô tiếp theo
            else if(mangInRa[row][j] != 0){
                hamLeft_Right(row, col+x, x, check);
                break;
            }
        }//ô này = 0 thì đổi chỗ ô này với ô gần nhất khác 0
        else {
            if(mangInRa[row][j]){
                mangInRa[row][col] = mangInRa[row][j];
                mangInRa[row][j] = 0;
                check = true;
                hamLeft_Right(row, col, x, check);
                break;
            }
        }
    }
}

//thuc hien lenh len hoặc xuống
void Game::hamUp_Down(const int &row, const int &col, const int &x, bool &check)
{
    int n;
    if(x == 1) n = 3;
    else n = 0;
    for(int i = row + x; (i * x) <= n; i = i + x){
        if(mangInRa[row][col]){
            if(mangInRa[row][col] == mangInRa[i][col]){
            mangInRa[row][col] = mangInRa[row][col] * 2;
            diem += mangInRa[row][col];
            check = true;
            mangInRa[i][col] = 0;
            hamUp_Down(row+x, col, x, check);
            break;
            }
            else if(mangInRa[i][col] != 0){
                hamUp_Down(row+x, col, x, check);
                break;
            }
        }
        else {
            if(mangInRa[i][col]){
                mangInRa[row][col] = mangInRa[i][col];
                mangInRa[i][col] = 0;
                check = true;
                hamUp_Down(row, col, x, check);
                break;
            }
        }
    }
}

// vẽ lại bảng sau khi nhấn phím
void Game::drawTable()
{
        for(int j = 0; j < 4; j++){
            for(int i = 0; i < 4; i++){
                draw.drawSquare(mangInRa[i][j], i, j);
            }
        }
}


//khởi tạo 2 giá trị ban đầu của mảng
void Game::khoiTaoBanDau()
{

    khoiTaoThemSo();
    khoiTaoThemSo();

}

//tìm các vị trí trống trong mảng
bool Game::viTriTrong()
{
    int dem = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++){
            if(!mangInRa[i][j]){
                return true;
            }
        }
    }
    return false;
}
//khơi tạo thêm gia trị cho mang
void Game::khoiTaoThemSo()
{
    //srand((int)time(NULL));
    if(viTriTrong()){
        int i, j;
        do{
            i = rand() % 4;
            j = rand() % 4;
        } while(mangInRa[i][j] != 0);
        if(rand() % 10 == 9)
        {
            mangInRa[i][j] = 4;
        }
        else
            mangInRa[i][j] = 2;
        draw.drawSquare2_4(mangInRa[i][j], i, j);//????????
        g_render.present();
        SDL_Delay(10);
        draw.drawSquare(mangInRa[i][j], i, j);
        g_render.present();
    }
}
