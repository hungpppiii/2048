#include "game.h"

Game::Game()
{
    menu.gameMenu();
    diem = 0;
    diemCong = 0;
}

Game::~Game(){}

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

void Game::restart(const bool &music)
{
    for (int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            mangInRa[i][j] = 0;
    diem = 0;
    drawTable(music);
    khoiTaoBanDau();
}

void Game::getHighScore()
{
    fstream file;
    file.open("file\\highScore.txt", ios::in);
    if(file.is_open())
    {
        if(file.eof())
        {
            file.close();
            return;
        }
        else
        {
            string line;
            while(getline(file, line))
            {
                highScore = stoi(line);
            }
        }
    }
    else
    {
        cout << "error open file highScore.txt" << endl;
    }
    file.close();
}

void Game::saveHighScore()
{
    ofstream file;
    file.open("file\\highScore.txt");
    if(file.is_open())
    {
        file << highScore;
    }
    else
        cout << "error open file highScore.txt" << endl;
    file.close();
}

bool Game::getPoint_CheckWin(bool &music)
{
    if(diemCong > 0){
        diem += diemCong;
        if(diem > highScore)
        {
            highScore = diem;
        }
        drawTable(music);
        //check xem thắng chưa
        // 9 * 1024 = 9216
        if(diem >= 9216){
            if( winGame() ){
                if(music){
                    menu.playSoundEffect(3);
                }
                //draw you win lên màn hình
                for(int i = 0; i < 50; i++)
                {
                    draw.gameOver_WinGame(true);
                }
                //check sự kiện chuột
                if(menu.mouseEvent(music) == 0)
                    restart(music);
                else
                    return false;
            }
            else
                khoiTaoThemSo();
        }
        else
            khoiTaoThemSo();
    }
    else {
        drawTable(music);
        //khoi tao them so
        khoiTaoThemSo();
    }
    return true;
}

//++++++++++++++++++++++++++++++++++++++++
void Game::left(bool &check)
{
    diemCong = 0;
    for(int i = 0; i < 4; i++){
        int j = 0;
        hamLeft_Right(i, j, 1, check);
    }
}

void Game::right(bool &check)
{
    diemCong = 0;
    for(int i = 0; i < 4; i++){
        int j = 3;
        hamLeft_Right(i, j, -1, check);
    }
}

void Game::up(bool &check)
{
    diemCong = 0;
    for(int j = 0; j < 4; j++){
        int i = 0;
        hamUp_Down(i, j, 1, check);
    }
}

void Game::down(bool &check)
{
    diemCong = 0;
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
            diemCong += mangInRa[row][col];
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
            diemCong += mangInRa[row][col];
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
void Game::drawTable(const bool &music)
{
    draw.background();
    menu.drawGameMenu(to_string(diem), to_string(highScore));
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 4; i++){
            draw.drawSquare(mangInRa[i][j], i, j);
        }
    }
    menu.iconSound(music);
    g_render.present();
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
        SDL_Delay(5);
        draw.drawSquare(mangInRa[i][j], i, j);
        g_render.present();
    }
}
