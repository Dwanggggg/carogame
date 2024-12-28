#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;  // Tên của người chơi
    char symbol;       // Ký hiệu của người chơi ('X' hoặc 'O')

public:
    //  Constructor mặc định cho Player
    Player();

    //  Constructor nhận tên và ký hiệu của người chơi
    Player(std::string playerName, char playerSymbol);

    //  Lấy tên của người chơi
    std::string getName() const;

    //  Lấy ký hiệu của người chơi ('X' hoặc 'O')
    char getSymbol() const;
};

#endif // PLAYER_H
