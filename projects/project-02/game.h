#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game {
private:
    static constexpr int GRID_SIZE = 5;
    bool board[GRID_SIZE][GRID_SIZE];

public:
    enum Status { ONGOING, WON };

    Game();  // Constructor to initialize the board
    void play(int row, int col);  // Executes a move
    Status status() const;  // Checks game status
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif /
