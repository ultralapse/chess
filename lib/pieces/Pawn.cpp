// Copyright (2024) Alvin Yu

#include "Pawn.hpp"


bool Pawn::move(int row, int col, int dRow, int dCol,
                std::vector<std::vector<std::shared_ptr<Piece>>> board) {
    int cRow = dRow - row;
    int cCol = dCol - col;

    // White Initial Double Move
    if (cRow == -2 && cCol == 0 && row == 6) {
        switch (color()) {
            case White:
                _ep = true;
                return row == 6 && board[dRow][dCol] == nullptr;
            case Black:
                return false;
        }
    }

    // Black Initial Double Move
    if (cRow == 2 && cCol == 0 && row == 1) {
        switch (color()) {
            case Black:
                _ep = true;
                return row == 1 && board[dRow][dCol] == nullptr;
            case White:
                return false;
        }
    }

    // Make sure that the move is 1 unit
    if (abs(cRow) > 1 || abs(cCol) > 1) {
        return false;
    }

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

    // Diagonal Movement
    if (abs(cCol) == 1 && abs(cRow) == 1) {
        if (board[dRow][dCol] != nullptr) {
            return board[row][col]->color() != board[dRow][dCol]->color();
        } else if (row == 4 && board[4][dCol]->type() == P && board[4][dCol]->color() == White
                    && board[row][col]->color() == Black) {
            return board[4][dCol]->ep();
        } else if (row == 3 && board[3][dCol]->type() == P && board[3][dCol]->color() == Black
                    && board[row][col]->color() == White) {
            return board[3][dCol]->ep();
        } else {
            return false;
        }
    }

    std::cout << "Success" << std::endl;

    return board[dRow][dCol] == nullptr;
}



