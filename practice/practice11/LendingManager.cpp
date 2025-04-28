#include "LendingManager.h"
#include <iostream>

void LendingManager::addGame(string title, int totalCopies) {
    games.emplace_back(title, totalCopies);
}

void LendingManager::listGames() const {
    cout << "=== Game Inventory ===" << endl;
    for (const auto& game : games) {
        game.displayInfo();
    }
    cout << endl;
}

Customer* LendingManager::findCustomer(string customerName) {
    for (auto& customer : customers) {
        if (customer.name == customerName) {
            return &customer;
        }
    }
    customers.emplace_back(customerName);
    return &customers.back();
}

BoardGame* LendingManager::findGame(string gameTitle) {
    for (auto& game : games) {
        if (game.title == gameTitle) {
            return &game;
        }
    }
    return nullptr;
}

void LendingManager::checkoutGame(string customerName, string gameTitle) {
    BoardGame* game = findGame(gameTitle);
    if (!game) {
        cout << "Game not found!" << endl;
        return;
    }
    if (!game->checkoutGame()) {
        cout << "No copies available for checkout." << endl;
        return;
    }
    Customer* customer = findCustomer(customerName);
    customer->borrowGame(gameTitle);
    cout << customerName << " has checked out \"" << gameTitle << "\"." << endl;
}

void LendingManager::returnGame(string customerName, string gameTitle) {
    Customer* customer = findCustomer(customerName);
    BoardGame* game = findGame(gameTitle);

    if (!game) {
        cout << "Game not found!" << endl;
        return;
    }

    customer->returnGame(gameTitle);
    game->returnGame();

    cout << customerName << " has returned \"" << gameTitle << "\"." << endl;
}
