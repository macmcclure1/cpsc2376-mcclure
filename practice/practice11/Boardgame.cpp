#include "Boardgame.h"
#include <iostream>

BoardGame::BoardGame(string title, int totalCopies)
    : title(title), totalCopies(totalCopies), availableCopies(totalCopies) {}

void BoardGame::displayInfo() const {
    cout << "Game: " << title
         << " | Total: " << totalCopies
         << " | Available: " << availableCopies << endl;
}

bool BoardGame::checkoutGame() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

void BoardGame::returnGame() {
    if (availableCopies < totalCopies) {
        availableCopies++;
    }
}
