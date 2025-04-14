#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Customer {
public:
    string name;
    vector<string> borrowedGames;

    Customer(string name);
    void borrowGame(string gameTitle);
    void returnGame(string gameTitle);
    void displayBorrowedGames() const;
};

#endif 