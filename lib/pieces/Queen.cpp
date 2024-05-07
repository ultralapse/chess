// Copyright (2024) Alvin Yu

#include "Queen.hpp"

bool Queen::move(int row, int col, int dRow, int dCol) {
    int changeRow = dRow - row;
    int changeCol = dCol - col;

    if (changeRow == 0 || changeCol == 0) return true;

    std::cout << "It's a diagonal move" << std::endl;

    int result = changeRow/changeCol;

    return result == 1 || result == -1;
}


