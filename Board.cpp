// Copyright (2024)

#include "Board.hpp"

Board::Board() {
    _board = std::vector<std::vector<Piece *>>(8, std::vector<Piece *>(8));
    for (int i = 0; i < 8; i++) {
        _board[6][i] = new Pawn(White);
    }

    for (int i = 0; i < 8; i++) {
        _board[1][i] = new Pawn(Black);
    }

    _board[0][0] = new Rook(Black);
    _board[0][1] = new Knight(Black);
    _board[0][2] = new Bishop(Black);
    _board[0][3] = new Queen(Black);
    _board[0][4] = new King(Black);
    _board[0][5] = new Bishop(Black);
    _board[0][6] = new Knight(Black);
    _board[0][7] = new Rook(Black);

    _board[7][0] = new Rook(White);
    _board[7][1] = new Knight(White);
    _board[7][2] = new Bishop(White);
    _board[7][3] = new Queen(White);
    _board[7][4] = new King(White);
    _board[7][5] = new Bishop(White);
    _board[7][6] = new Knight(White);
    _board[7][7] = new Rook(White);
}

void Board::write(int row, int col, Piece* p) {
    _board[row][col] = p;
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

bool Board::obstruction(int row, int col, int dRow, int dCol) {
    int changeRow = dRow - row;
    int changeCol = dCol - col;

    // Check for Right Linear Obstruction
    if (changeRow == 0 && changeCol > 0) {
        for (int i = col + 1; i < dCol; i++) {
            if (_board[row][i] != nullptr) {
                std::cout << "RL-Branch Taken" << std::endl;
                return true;
            }
        }
        std::cout << "RL-Branch NOT Taken" << std::endl;
        return false;
    }
    
    // Check for Left Linear Obstruction
    if (changeRow == 0 && changeCol < 0) {
        for (int i = col - 1; i > dCol; i--) {
            if (_board[row][i] != nullptr) {
                std::cout << "LL-Branch Taken" << std::endl;
                return true;
            }
        }
        std::cout << "LL-Branch NOT Taken" << std::endl;
        return false;
    }
    
    // Check for Up Linear Obstruction
    if (changeCol == 0 && changeRow > 0) {
        for (int i = row - 1; i > dRow; i--) {
            if (_board[i][col] != nullptr) return true;
        }
        return false;
    }

    // Check for Down Linear Obstruction
    if (changeCol == 0 && changeRow < 0) {
        for (int i = row + 1; i < dRow; i++) {
            if (_board[i][col] != nullptr) return true;
        }
        return false;
    }

    
    // if (abs(changeRow/changeCol) != 1) {
    //     return false;
    // }

    return false;

    // Check for Top-Right Diagonal Obstruction

    // Check for Top-Left Diagonal Obstruction

    // Check for Bottom-Left Diagonal Obstruction

    // Check for Bottom-Right Diagonal Obstruction
}