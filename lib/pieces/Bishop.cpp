// Copyright (2024) Alvin Yu

#include "Bishop.hpp"

bool Bishop::move(int row, int col, int dRow, int dCol) {
    int changeRow = dRow - row;
    int changeCol = dCol - col;
    int result = changeRow/changeCol;

    return result == 1 || result == -1;
}

