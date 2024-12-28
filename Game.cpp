#include "Game.h"
#include <iostream>
using namespace std;

//  Constructor chế độ Player vs Player (PvP)
Game::Game(Player p1, Player p2)
    : player1(p1), player2(p2), currentPlayer(&player1), isPvP(true) {}

//  Constructor chế độ Player vs Bot (PvB)
Game::Game(Player p1, Bot b)
    : player1(p1), bot(b), currentPlayer(&player1), isPvP(false) {}

void Game::switchPlayer() {
    if (isPvP) {
        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    }
    else {
        currentPlayer = (currentPlayer == &player1) ? nullptr : &player1; // nullptr đại diện cho Bot
    }
}

bool Game::isWinningMove(int x, int y) {
    int dx[] = { 0, 1, 1, 1 };
    int dy[] = { 1, 0, 1, -1 };

    char symbol = currentPlayer ? currentPlayer->getSymbol() : bot.getSymbol();

    for (int dir = 0; dir < 4; ++dir) {
        int count = 1;
        for (int step = 1; step <= 4; ++step) {
            int newX = x + step * dx[dir];
            int newY = y + step * dy[dir];
            if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && board.getCell(newX, newY) == symbol)
                count++;
            else break;
        }
        for (int step = 1; step <= 4; ++step) {
            int newX = x - step * dx[dir];
            int newY = y - step * dy[dir];
            if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && board.getCell(newX, newY) == symbol)
                count++;
            else break;
        }
        if (count >= 5) return true;
    }
    return false;
}

void Game::startPvPGame() {
    int x, y;

    while (true) {
        board.drawBoard();
        cout << currentPlayer->getName() << "'s turn (" << currentPlayer->getSymbol() << "). Enter row and column: ";
        cin >> x >> y;

        if (x < 0 || x >= 10 || y < 0 || y >= 10 || board.getCell(x, y) != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board.setCell(x, y, currentPlayer->getSymbol());

        if (isWinningMove(x, y)) {
            board.drawBoard();
            cout << currentPlayer->getName() << " wins!\n";
            break;
        }

        if (board.isDraw()) {
            board.drawBoard();
            cout << "The game is a draw!\n";
            break;
        }

        switchPlayer();
    }
}

void Game::startBotGame() {
    int x, y;

    while (true) {
        board.drawBoard();

        if (currentPlayer == &player1) {
            cout << player1.getName() << "'s turn (" << player1.getSymbol() << "). Enter row and column: ";
            cin >> x >> y;

            if (x < 0 || x >= 10 || y < 0 || y >= 10 || board.getCell(x, y) != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board.setCell(x, y, player1.getSymbol());
        }
        else {
            cout << "Bot is thinking...\n";
            std::pair<int, int> botMove = bot.getBestMove(board);
            x = botMove.first;
            y = botMove.second;

            cout << "Bot places at (" << x << ", " << y << ")\n";
            board.setCell(x, y, bot.getSymbol());
        }

        if (isWinningMove(x, y)) {
            board.drawBoard();
            if (currentPlayer == &player1) {
                cout << player1.getName() << " wins!\n";
            }
            else {
                cout << "Bot wins!\n";
            }
            break;
        }

        if (board.isDraw()) {
            board.drawBoard();
            cout << "The game is a draw!\n";
            break;
        }

        switchPlayer();
    }
}

