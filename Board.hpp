// Copyright (2024)

#include <iostream>
#include <vector>
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "King.hpp"

class Board {
 private:
    std::vector<std::vector<Piece *>> _board;
    std::vector<Piece *> _wjail;
    std::vector<Piece *> _bjail;

 public:
    // Initializes default 8x8 grid
    Board();

    // Indexing function
    Piece* get(int row, int col) {return _board[row][col];}

    // Function that unconditionally writes to a square
    void write(int row, int col, Piece *p);

    // Will automatically capture pieces regardless of the rules.
    void move(int row, int col, int dRow, int dCol);

    bool obstruction(int row, int col, int dRow, int dCol);

    friend std::ostream& operator<<(std::ostream& out, Board &b);
};

