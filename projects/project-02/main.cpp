#include "game.h"
#include <iostream>

int main() {
    Game game;
    int row, col;

    while (game.status() == Game::ONGOING) {
        std::cout << game;
        std::cout << "Enter row and column to toggle: ";
        std::cin >> row >> col;
        game.play(row, col);
    }
    
    std::cout << "You won!" << std::endl;
    return 0;
}
