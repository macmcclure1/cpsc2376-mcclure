#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <string>
using namespace std;

class BoardGame {
public:
    string title;
    int totalCopies;
    int availableCopies;

    BoardGame(string title, int totalCopies);
    void displayInfo() const;
    bool checkoutGame();
    void returnGame();
};

#endif 