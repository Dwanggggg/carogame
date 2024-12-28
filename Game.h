#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "BotMode.h"

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    Bot bot;
    Player* currentPlayer;
    bool isPvP;

    void switchPlayer();
    bool isWinningMove(int x, int y);

public:
    // Constructor chế độ Player vs Player (PvP)
    Game(Player p1, Player p2);

    // Constructor chế độ Player vs Bot (PvB)
    Game(Player p1, Bot b);

    void startPvPGame();
    void startBotGame();
};

#endif // GAME_H
