#include <iostream>
#include "game.h"

int main() {
    Game game;
    int row, col;

    while (game.status() == Game::ONGOING) { //This just means the codes/ games status. As the game goes on then the when all the lights are out, it will print out YOU WON!
        std::cout << game;
        std::cout << "Enter row and column to toggle: ";
        std::cin >> row >> col;
        game.play(row, col);
    }
    
    std::cout << "You won!" << std::endl;
    return 0;
}
