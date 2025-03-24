#include "game.h"

Game::Game() {
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = 0; j < GRID_SIZE; ++j)
            board[i][j] = true;  // All lights start ON
}

void Game::play(int row, int col) { //this command is to show how the game will go. 
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
        return;
    
    board[row][col] = !board[row][col];
    if (row > 0) board[row - 1][col] = !board[row - 1][col];
    if (row < GRID_SIZE - 1) board[row + 1][col] = !board[row + 1][col];
    if (col > 0) board[row][col - 1] = !board[row][col - 1];
    if (col < GRID_SIZE - 1) board[row][col + 1] = !board[row][col + 1];
}

Game::Status Game::status() const {
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = 0; j < GRID_SIZE; ++j)
            if (board[i][j]) return ONGOING;
    return WON;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (int i = 0; i < Game::GRID_SIZE; ++i) {
        for (int j = 0; j < Game::GRID_SIZE; ++j)
            os << (game.board[i][j] ? "O " : ". ");
        os << '\n';
    }
    return os;
}


