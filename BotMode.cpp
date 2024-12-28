#include "BotMode.h"
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

//  Constructor mặc định
Bot::Bot() : botSymbol('O'), playerSymbol('X'), depth(2) {}

//  Constructor với thông số
Bot::Bot(char botSymbol, char playerSymbol, int depth)
    : botSymbol(botSymbol), playerSymbol(playerSymbol), depth(depth) {}

char Bot::getSymbol() const {
    return botSymbol;
}

// Thiết lập độ sâu cho thuật toán Minimax
void Bot::setDepth(int newDepth) {
    depth = newDepth;
}

//  Đánh giá bàn cờ
int Bot::evaluateBoard(const Board& board) {
    int score = 0;

    // Cải tiến logic đánh giá bàn cờ
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // Đánh giá các chuỗi liên tiếp của bot
            score += board.scoreCell(i, j, botSymbol);
            // Giảm điểm cho chuỗi liên tiếp của người chơi, giảm trọng số để phòng thủ bớt mạnh
            score -= board.scoreCell(i, j, playerSymbol) * 1.5;
        }
    }

    return score;
}

//  Minimax với Alpha-Beta
int Bot::minimax(Board& board, int currentDepth, bool isMaximizing, int alpha, int beta) {
    int score = evaluateBoard(board);

    if (currentDepth == 0 || board.isDraw()) {
        return score;
    }

    if (isMaximizing) {
        int maxEval = INT_MIN;
        for (const auto& move : board.getPotentialMoves()) {
            board.setCell(move.first, move.second, botSymbol);
            int eval = minimax(board, currentDepth - 1, false, alpha, beta);
            board.setCell(move.first, move.second, ' ');
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha) break;
        }
        return maxEval;
    }
    else {
        int minEval = INT_MAX;
        for (const auto& move : board.getPotentialMoves()) {
            board.setCell(move.first, move.second, playerSymbol);
            int eval = minimax(board, currentDepth - 1, true, alpha, beta);
            board.setCell(move.first, move.second, ' ');
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}

//  Tìm nước đi tốt nhất
std::pair<int, int> Bot::getBestMove(Board& board) {
    int bestScore = INT_MIN;
    std::pair<int, int> bestMove = { -1, -1 };

    for (const auto& move : board.getPotentialMoves()) {
        board.setCell(move.first, move.second, botSymbol);
        int moveScore = minimax(board, depth, false, INT_MIN, INT_MAX);
        board.setCell(move.first, move.second, ' ');

        if (moveScore > bestScore) {
            bestScore = moveScore;
            bestMove = move;
        }
    }

    return bestMove;
}
