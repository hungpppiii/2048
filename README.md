# 2048

---GAME 2048---

-Cách chơi:

+bắt đầu game sẽ vào menu start.
+nháy đúp chuột vào new game để bắt đầu chơi hoặc exit để thoát khỏi trò chơi.
+nháy đúp chuột vào biểu tượng loa để tắt âm thanh trò chơi.
+Vào game sử dụng các phím lên, xuống, trái, phải trên bàn phím để di chuyển các ô số trong bảng 4x4 của game cố gắng đạt đến 2048.

-Luật chơi:

+khi bấm phím lên, các ô số sẽ dồn lên trên cùng của bảng theo từng cột của bảng số
+khi 2 ô gần nhau nhất có số giống nhau thì sẽ gộp lại với nhau để tạo thành số mới có giá trị gấp đôi số cũ
+khi bảng 4x4 đầy và người chơi không có cách nào di chuyển các ô số bên trong thì kết thúc game (game over)
+khi người chơi tạo ra được ô số 2048 thì người chơi giành chiến thắng (you win)

*Giải thích code trong game

-game được chia modul như main.cpp, game.cpp, draw.cpp,... để xử lý các chức năng riêng trong game
-các hàm trong game

+utils.cpp

    void logSDLError() : báo lỗi
    void initSDL() : khởi tạo SDL cho game
    void quitSDL() : thoát khỏi SDL
 +game.cpp
 
    bool winGame() : kiểm tra đã thắng chưa
    bool endGame() : kiểm tra đã thua chưa
    void restart() : bắt đầu game mới
    void getHighScore() : nhận vào highscore từ highScore.txt
    void saveHighScore() : khi thoát game thì lưu lại highScore
    bool getPoint_CheckWin() : hàm cập nhật điểm và kiểm tra xem đã thắng chưa
    void left() : di chuyển sang trái(lên, xuống, phải tương tự)
    void hamLeft_Right() : là hàm được gọi để xử lý lệnh trái hoặc phải
    void hamUp_Down() : là hàm được gọi để xử lý lệnh trái hoặc phải
    void drawScreen() : vẽ màn hình sau khi đã xử lý xong lệnh bàn phím
    
    void khoiTaoBanDau() : khởi tạo ban đầu khi vào game
    bool viTriTrong() : kiểm tra xem có vị trí nào trong bảng còn trống không
    void khoiTaoThemSo() : khởi tạo thêm số 2 hoặc 4
  +draw.cpp
