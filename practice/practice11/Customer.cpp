#include "Customer.h"
#include <iostream>
#include <algorithm>

Customer::Customer(string name) : name(name) {}

void Customer::borrowGame(string gameTitle) {
    borrowedGames.push_back(gameTitle);
}

void Customer::returnGame(string gameTitle) {
    auto it = find(borrowedGames.begin(), borrowedGames.end(), gameTitle);
    if (it != borrowedGames.end()) {
        borrowedGames.erase(it);
    }
}

void Customer::displayBorrowedGames() const {
    cout << name << " has borrowed: ";
    if (borrowedGames.empty()) {
        cout << "No games." << endl;
    } else {
        for (const string& game : borrowedGames) {
            cout << game << " ";
        }
        cout << endl;
    }
}
