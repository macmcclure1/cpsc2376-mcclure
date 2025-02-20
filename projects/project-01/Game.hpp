#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game {
public:
    Game();
    void play(); // Main game loop

private:
    Board board;
    Cell currentPlayer;
    void switchPlayer();
};

#endif
