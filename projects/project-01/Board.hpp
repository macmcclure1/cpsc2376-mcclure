#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Cell { EMPTY, PLAYER_1, PLAYER_2 };

class Board {
public:
    Board();
    void printBoard() const;
    bool dropPiece(int column, Cell player);
    GameState checkGameStatus() const;

private:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::vector<std::vector<Cell>> grid;
};

#endif
