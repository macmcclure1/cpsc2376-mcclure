#include "Board.hpp"
#include <iostream>

Board::Board() : grid(ROWS, std::vector<Cell>(COLS, Cell::EMPTY)) {}

void Board::printBoard() const {
    std::cout << "\n 1 2 3 4 5 6 7\n";
    std::cout << "---------------\n";
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            char symbol = (cell == Cell::PLAYER_1) ? 'X' : (cell == Cell::PLAYER_2) ? 'O' : '.';
            std::cout << " " << symbol;
        }
        std::cout << "\n";
    }
    std::cout << "---------------\n";
}

bool Board::dropPiece(int column, Cell player) {
    if (column < 0 || column >= COLS) return false;
    for (int row = ROWS - 1; row >= 0; --row) {
        if (grid[row][column] == Cell::EMPTY) {
            grid[row][column] = player;
            return true;
        }
    }
    return false;
}

GameState Board::checkGameStatus() const {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (grid[row][col] == Cell::EMPTY) continue;
            Cell player = grid[row][col];

            // Check horizontal
            if (col + 3 < COLS && grid[row][col + 1] == player &&
                grid[row][col + 2] == player && grid[row][col + 3] == player)
                return (player == Cell::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

            // Check vertical
            if (row + 3 < ROWS && grid[row + 1][col] == player &&
                grid[row + 2][col] == player && grid[row + 3][col] == player)
                return (player == Cell::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

            // Check diagonal (down-right)
            if (row + 3 < ROWS && col + 3 < COLS && grid[row + 1][col + 1] == player &&
                grid[row + 2][col + 2] == player && grid[row + 3][col + 3] == player)
                return (player == Cell::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

            // Check diagonal (down-left)
            if (row + 3 < ROWS && col - 3 >= 0 && grid[row + 1][col - 1] == player &&
                grid[row + 2][col - 2] == player && grid[row + 3][col - 3] == player)
                return (player == Cell::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
        }
    }

    // Check for a draw
    for (const auto& row : grid) {
        for (Cell cell : row) {
            if (cell == Cell::EMPTY) return GameState::ONGOING;
        }
    }
    return GameState::DRAW;
}
