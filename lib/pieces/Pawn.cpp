// Copyright (2024) Alvin Yu

#include "Pawn.hpp"

bool Pawn::move(int row, int col, int dRow, int dCol, std::vector<std::vector<Piece *>> board) {
    int cRow = dRow - row;
    int cCol = dCol - col;

    if (abs(cRow) > 1 || abs(cCol) > 1) return false;

    if (abs(cCol) == 1 && abs(cRow) != 1) return false;

    switch (color()) {
        case White:
            if (cRow == 1) return false;
        case Black:
            if (cRow == -1) return false;
        default:
            return false;
    }

    if (abs(cCol) == 1 && abs(cRow) == 1) {
        if (board[dRow][dCol] != nullptr) {
            return board[row][col]->color() == board[dRow][dCol]->color();
        }
    }

    return board[dRow][dCol] != nullptr;
}



