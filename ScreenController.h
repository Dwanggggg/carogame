#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

class ScreenController {
public:
    void displayMainMenu();
    int getMainMenuChoice();
    void handleMainMenu();
    void displayInstructions();
    void exitGame();
};

#endif // SCREENCONTROLLER_H
