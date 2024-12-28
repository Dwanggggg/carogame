#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    grid = vector<vector<char>>(10, vector<char>(10, ' '));
}

void Board::drawBoard() {
    cout << "   ";
    for (int i = 0; i < 10; ++i) cout << i << " ";
    cout << "\n";
    for (int i = 0; i < 10; ++i) {
        cout << i << " |";
        for (int j = 0; j < 10; ++j)
            cout << grid[i][j] << "|";
        cout << "\n";
    }
}

char Board::getCell(int x, int y) const {
    return grid[x][y];
}

void Board::setCell(int x, int y, char value) {
    grid[x][y] = value;
}
bool Board::isDraw() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == ' ')
                return false; // Vẫn còn ô trống, chưa hòa
        }
    }
    return true; // Không còn ô trống, ván cờ hòa
}
bool Board::isValidMove(int row, int col) const {
    return row >= 0 && row < 10 && col >= 0 && col < 10 && grid[row][col] == ' ';
}

int Board::scoreCell(int row, int col, char symbol) const {
    if (grid[row][col] != ' ') return 0; // Nếu ô đã được đánh thì không tính điểm

    int score = 0;
    int directions[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} }; // Hướng: ngang, dọc, chéo chính, chéo phụ

    for (auto& dir : directions) {
        int count = 0;
        for (int step = 1; step <= 4; ++step) {
            int x = row + step * dir[0];
            int y = col + step * dir[1];
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && grid[x][y] == symbol) {
                count++;
            }
            else break;
        }
        for (int step = 1; step <= 4; ++step) {
            int x = row - step * dir[0];
            int y = col - step * dir[1];
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && grid[x][y] == symbol) {
                count++;
            }
            else break;
        }
        score += count * count; // Điểm tăng theo bình phương số lượng
    }

    return score;
}

std::vector<std::pair<int, int>> Board::getPotentialMoves() const {
    std::vector<std::pair<int, int>> moves;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == ' ') {
                bool near = false;
                for (int di = -1; di <= 1 && !near; ++di) {
                    for (int dj = -1; dj <= 1 && !near; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10 && grid[ni][nj] != ' ') {
                            near = true;
                        }
                    }
                }
                if (near) moves.emplace_back(i, j);
            }
        }
    }

    return moves;
}
