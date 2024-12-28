#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    std::vector<std::vector<char>> grid; // Bàn cờ 10x10  
public:
    Board();
    void drawBoard(); // Vẽ bàn cờ  
    char getCell(int x, int y) const; // Lấy giá trị tại ô cụ thể  
    void setCell(int x, int y, char value); // Đặt giá trị cho ô cụ thể  
    bool isDraw();
    bool isValidMove(int row, int col) const; // Kiểm tra nước đi hợp lệ

    int scoreCell(int row, int col, char symbol) const; // Tính điểm cho một ô
    std::vector<std::pair<int, int>> getPotentialMoves() const; // Trả về các nước đi tiềm năng
};

#endif // BOARD_H

