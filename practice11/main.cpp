#include "LendingManager.h"
#include <iostream>

int main() {
    LendingManager manager;

    // Sample data
    manager.addGame("Catan", 3);
    manager.addGame("Ticket to Ride", 2);
    manager.addGame("Carcassonne", 4);

    int choice;
    do {
        cout << "\n=== Board Game Café Menu ===\n";
        cout << "1. List all games\n";
        cout << "2. Check out a game\n";
        cout << "3. Return a game\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string customerName, gameTitle;
        switch (choice) {
            case 1:
                manager.listGames();
                break;
            case 2:
                cout << "Enter customer name: ";
                cin >> ws;
                getline(cin, customerName);
                cout << "Enter game title: ";
                getline(cin, gameTitle);
                manager.checkoutGame(customerName, gameTitle);
                break;
            case 3:
                cout << "Enter customer name: ";
                cin >> ws;
                getline(cin, customerName);
                cout << "Enter game title: ";
                getline(cin, gameTitle);
                manager.returnGame(customerName, gameTitle);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
