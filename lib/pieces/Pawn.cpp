// Copyright (2024) Alvin Yu

#include <iostream>
#include "Pawn.hpp"


bool Pawn::move(int row, int col, int dRow, int dCol, std::vector<std::vector<Piece *>> board) {
    int cRow = dRow - row;
    int cCol = dCol - col;

    // White Initial Double Move
    if (cRow == -2 && cCol == 0) {
        switch (color()) {
            case White:
                return row == 6 && board[dRow][dCol] == nullptr;
            case Black:
                return false;
        }
    }

    // Black Initial Double Move
    if (cRow == 2 && cCol == 0) {
        switch (color()) {
            case Black:
                return row == 1 && board[dRow][dCol] == nullptr;
            case White:
                return false;
        }
    }

    if (abs(cRow) > 1 || abs(cCol) > 1) return false;

    if (abs(cCol) == 1 && abs(cRow) != 1) return false;

    switch (color()) {
        case White:
            if (cRow == 1) return false;
            break;
        case Black:
            if (cRow == -1) return false;
            break;
        default:
            return false;
    }

    if (abs(cCol) == 1 && abs(cRow) == 1) {
        if (board[dRow][dCol] != nullptr) {
            return board[row][col]->color() != board[dRow][dCol]->color();
        } else {
            return false;
        }
    }

    return board[dRow][dCol] == nullptr;
}



