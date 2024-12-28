#include "Player.h"

//  Constructor mặc định cho Player

Player::Player()
    : name("Player"), symbol('X') {}

//  Constructor đầy đủ cho Player

Player::Player(std::string playerName, char playerSymbol)
    : name(playerName), symbol(playerSymbol) {}

//  Lấy tên của người chơi
std::string Player::getName() const {
    return name;
}

//  Lấy ký hiệu của người chơi ('X' hoặc 'O')
char Player::getSymbol() const {
    return symbol;
}
