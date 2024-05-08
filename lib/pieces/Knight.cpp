// Copyright (2024) Alvin Yu

#include "Knight.hpp"

bool Knight::move(int row, int col, int dRow, int dCol) {
    int cRow = dRow - row;
    int cCol = dCol - col;

    return (abs(cRow) == 1 && abs(cCol) == 2) ||
            (abs(cRow) == 2 && abs(cCol) == 1);
}


