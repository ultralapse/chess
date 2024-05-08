// Copyright (2024) Alvin Yu

#include "King.hpp"

bool King::move(int row, int col, int dRow, int dCol) {
    int cRow = dRow - row;
    int cCol = dCol - col;

    bool rRow = cRow == 1 || cRow == 0 || cRow == -1;
    bool rCol = cCol == 1 || cCol == 0 || cCol == -1;

    return rRow && rCol;
}
