#include <iostream>
#include "Game.hpp"
#include <vector>



int main() {
    char choice;
    std::cout << "Welcome to Connect Four!\n";
    std::cout << "Rules: Players take turns dropping pieces into columns. The first to connect four in a row wins.\n";

    do {
        play();
        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

  

    std::cout << "Thanks for playing!\n";
    return 0;

}
