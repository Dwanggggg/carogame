#include "ScreenController.h"
#include "Game.h"
#include "Player.h"
#include "BotMode.h"
#include <iostream>
using namespace std;

void ScreenController::displayMainMenu() {
    cout << "\n------- MAIN MENU -------\n";
    cout << "1. Play with Other Player (PvP)\n";
    cout << "2. Play with BOT\n";
    cout << "3. Player's Information\n";
    cout << "4. Guide\n";
    cout << "5. Exit\n";
    cout << "Press number to choose: ";
}

int ScreenController::getMainMenuChoice() {
    int choice;
    cin >> choice;
    return choice;
}

void ScreenController::handleMainMenu() {
    while (true) {
        displayMainMenu();
        int choice = getMainMenuChoice();

        switch (choice) {
        case 1: {
            string player1Name, player2Name;
            cout << "Enter name for Player 1 (X): ";
            cin >> player1Name;
            cout << "Enter name for Player 2 (O): ";
            cin >> player2Name;

            Player player1(player1Name, 'X');
            Player player2(player2Name, 'O');

            Game game(player1, player2);
            game.startPvPGame();
            break;
        }
        case 2: {
            string player1Name;
            int botLevel;

            cout << "Enter your name (Player 1) (X): ";
            cin >> player1Name;

            cout << "\nChoose BOT Level:\n";
            cout << "1. Easy \n";
            cout << "2. Normal \n";
            cout << "3. Hard \n";
            cout << "Enter your choice (1-3): ";
            cin >> botLevel;

            int depth = (botLevel == 2) ? 4 : (botLevel == 3) ? 6 : 2;

            Player player1(player1Name, 'X');
            Bot bot('O', 'X', depth);

            Game game(player1, bot);
            game.startBotGame();
            break;
        }
        case 3: {
            cout << "\n--- PLAYER'S INFORMATION ---\n";
            cout << "1. Player 1: X\n";
            cout << "2. Player 2: O or Bot (O)\n";
            cout << "-----------------------------\n";
            break;
        }
        case 4: {
            displayInstructions();
            break;
        }
        case 5: {
            exitGame();
            return;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void ScreenController::displayInstructions() {
    cout << "\n------- GAME GUIDE -------\n";
    cout << "1. Choose Player vs Player (PvP) or Player vs Bot (PvB).\n";
    cout << "2. For PvP, both players enter their names and take turns placing X or O.\n";
    cout << "3. For PvB, you choose the BOT difficulty (Easy, Normal, Hard).\n";
    cout << "4. To win, you must get 5 consecutive symbols (X or O) in a row, column, or diagonal.\n";
    cout << "5. If the board is full, the game is a draw.\n";
    cout << "--------------------------\n";
}

void ScreenController::exitGame() {
    cout << "Exiting game. Goodbye!\n";
    exit(0);
}
