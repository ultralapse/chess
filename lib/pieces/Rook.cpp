// Copyright (2024) Alvin Yu

#include <iostream>
#include "Rook.hpp"

bool Rook::move(int row, int col, int dRow, int dCol) {
    int changeRow = dRow - row;
    int changeCol = dCol - col;
    if (changeRow == 0 || changeCol == 0) return true;
    return false;
}
