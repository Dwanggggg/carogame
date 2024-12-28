#ifndef BOT_MODE_H
#define BOT_MODE_H

#include "Board.h"
#include <utility> // std::pair
#include <vector>

class Bot {
private:
    int depth;             // Độ sâu của thuật toán Minimax (2, 4, 6 cho Easy, Normal, Hard)
    char botSymbol;        // Ký hiệu của bot (ví dụ: 'O')
    char playerSymbol;     // Ký hiệu của người chơi (ví dụ: 'X')

    // Đánh giá trạng thái bàn cờ, trả về điểm (+10 BOT thắng, -10 người chơi thắng, 0 hòa)
    int evaluateBoard(const Board& board);

    // Thuật toán Minimax với cắt tỉa Alpha-Beta, trả về điểm tốt nhất của nước đi
    int minimax(Board& board, int currentDepth, bool isMaximizing, int alpha, int beta);

public:
    // Constructor mặc định của Bot
    Bot();

    // Constructor nhận ký hiệu của bot, ký hiệu người chơi và độ sâu của Minimax
    Bot(char botSymbol, char playerSymbol, int depth);

    // Thiết lập độ sâu cho thuật toán Minimax
    void setDepth(int newDepth);

    // Trả về nước đi tốt nhất cho bot dưới dạng cặp tọa độ (x, y)
    std::pair<int, int> getBestMove(Board& board);

    // Trả về ký hiệu của bot ('O' hoặc 'X')
    char getSymbol() const;
};

#endif // BOT_MODE_H
