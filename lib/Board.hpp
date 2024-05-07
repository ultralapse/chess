// Copyright (2024)

#pragma once
#include <iostream>
#include <vector>

#include "pieces/Piece.hpp"
#include "pieces/Pawn.hpp"
#include "pieces/Rook.hpp"
#include "pieces/Bishop.hpp"
#include "pieces/Knight.hpp"
#include "pieces/Queen.hpp"
#include "pieces/King.hpp"

class Board {
 private:
    std::vector<std::vector<Piece *>> _board;
    std::vector<Piece *> _wjail;
    std::vector<Piece *> _bjail;

 public:
    // Initializes default 8x8 grid
    Board();

    ~Board() {clear();}

    void clear();

    // Indexing function
    Piece* get(int row, int col) {return _board[row][col];}

    // Function that unconditionally writes to a square
    void write(int row, int col, Piece *p);

    // Will automatically capture pieces regardless of the rules.
    bool move(int row, int col, int dRow, int dCol);

    bool obstruction(int row, int col, int dRow, int dCol);

    friend std::ostream& operator<<(std::ostream& out, Board &b);
};

