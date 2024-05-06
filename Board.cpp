// Copyright (2024)

#include "Board.hpp"

void Board::write(int row, int col, Piece& p) {
    _board[row][col] = &p;
}

void Board::move(int row, int col, int dRow, int dCol) {
    if (_board[dRow][dCol] != nullptr) {
        switch (_board[row][col]->color()) {
            case White: _wjail.push_back(_board[dRow][dCol]);
            case Black: _bjail.push_back(_board[dRow][dCol]);
        }
    }
    _board[dRow][dCol] = _board[row][col];
    _board[row][col] = nullptr;
}

std::ostream& operator<<(std::ostream& out, Board &b) {
    for (unsigned int i = 0; i < 8; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if (b._board[i][j] != nullptr) {
                out << b._board[i][j]->id() << " ";
            } else {
                out << " " << " ";
            }
            
        }
        out << std::endl;
    }
    return out;
}
