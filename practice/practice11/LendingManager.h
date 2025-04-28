#ifndef LENDINGMANAGER_H
#define LENDINGMANAGER_H

#include "Boardgame.h"
#include "Customer.h"
#include <vector>
using namespace std;

class LendingManager {
public:
    vector<BoardGame> games;
    vector<Customer> customers;

    void addGame(string title, int totalCopies);
    void listGames() const;
    void checkoutGame(string customerName, string gameTitle);
    void returnGame(string customerName, string gameTitle);
    Customer* findCustomer(string customerName);
    BoardGame* findGame(string gameTitle);
};

#endif 
