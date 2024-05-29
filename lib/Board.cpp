// Copyright (2024)

#include "Board.hpp"

Board::Board() {
    _board = std::vector<std::vector<std::shared_ptr<Piece>>>
            (8, std::vector<std::shared_ptr<Piece>>(8));
    for (int i = 0; i < 8; i++) {
        _board[6][i] = std::make_shared<Pawn>(White, false);
    }

    for (int i = 0; i < 8; i++) {
        _board[1][i] = std::make_shared<Pawn>(Black, false);
    }

    _board[0][0] = std::make_shared<Rook>(Black);
    _board[0][1] = std::make_shared<Knight>(Black);
    _board[0][2] = std::make_shared<Bishop>(Black);
    _board[0][3] = std::make_shared<Queen>(Black);
    _board[0][4] = std::make_shared<King>(Black);
    _board[0][5] = std::make_shared<Bishop>(Black);
    _board[0][6] = std::make_shared<Knight>(Black);
    _board[0][7] = std::make_shared<Rook>(Black);

    _board[7][0] = std::make_shared<Rook>(White);
    _board[7][1] = std::make_shared<Knight>(White);
    _board[7][2] = std::make_shared<Bishop>(White);
    _board[7][3] = std::make_shared<Queen>(White);
    _board[7][4] = std::make_shared<King>(White);
    _board[7][5] = std::make_shared<Bishop>(White);
    _board[7][6] = std::make_shared<Knight>(White);
    _board[7][7] = std::make_shared<Rook>(White);
}

void Board::write(int row, int col, std::shared_ptr<Piece> p) {
    _board[row][col] = p;
}

void Board::swap(int row, int col, int dRow, int dCol) {
    _board[dRow][dCol] = _board[row][col];
    _board[row][col] = nullptr;
}

bool Board::move(int row, int col, int dRow, int dCol) {
    if (_board[row][col] == nullptr) {
        std::cout << "Invalid Move: Empty Square" << std::endl;
        return false;
    }

    // Bounds checking
    if (row > 7 || row < 0 || col > 7 || col < 0 ||
        dRow > 7 || dRow < 0 || dCol > 7 || dCol < 0) {
        std::cout << "Invalid Move: Out of bounds" << std::endl;
        return false;
    }

    // See if the move is even a legal piece movemement
    if (_board[row][col]->type() == P) {
        if (!_board[row][col]->move(row, col, dRow, dCol, _board)) {
            std::cout << "Invalid Piece Movement. Please refer to the rules" << std::endl;
            return false;
        }

        // En Passant
        if (_board[3][dCol] != nullptr || _board[4][dCol] != nullptr) {
            if (row == 4 && _board[row][col]->color() == Black) {
                if (_board[4][dCol]->type() == P && _board[4][dCol]->color() == White) {
                    _bjail.push_back(_board[4][dCol]);
                    _board[4][dCol] = nullptr;
                }
            }

            if (row == 3 && _board[row][col]->color() == White) {
                if (_board[3][dCol]->type() == P && _board[3][dCol]->color() == Black) {
                    _wjail.push_back(_board[3][dCol]);
                    _board[3][dCol] = nullptr;
                }
            }
        }

    } else {
        if (!_board[row][col]->move(row, col, dRow, dCol)) {
            std::cout << "Invalid Piece Movement. Please refer to the rules" << std::endl;
            return false;
        }
    }

    // Cannot move past a piece. Knights skip this check
    if (_board[row][col]->type() != K && obstruction(row, col, dRow, dCol)) {
        std::cout << "Invalid Move: You cannot move past a piece" << std::endl;
        return false;
    }

    // Capturing logic
    if (_board[dRow][dCol] != nullptr) {
        pcolor curColor = _board[row][col]->color();
        pcolor destColor = _board[dRow][dCol]->color();

        if (curColor == destColor) {
            std::cout << "Invalid Move: You cannot capture your own piece" << std::endl;
            return false;
        }

        switch (curColor) {
            case White:
                _wjail.push_back(_board[dRow][dCol]);
                break;
            default:
                _bjail.push_back(_board[dRow][dCol]);
                break;
        }
    }

    // Simulate movement
    _board[dRow][dCol] = _board[row][col];
    _board[row][col] = nullptr;
    return true;
}

std::ostream& operator<<(std::ostream& out, Board &b) {
    out << "  a b c d e f g h\n";
    for (unsigned int i = 0; i < 8; i++) {
        out << 8-i << " ";
        for (unsigned int j = 0; j < 8; j++) {
            if (b._board[i][j] != nullptr) {
                out << b._board[i][j]->id() << " ";
            } else {
                out << " " << " ";
            }
        }
        out << std::endl;
    }

    out << "\n";
    out << "Captured Pieces:\n";
    out << "White: ";
    for (std::shared_ptr<Piece> p : b._wjail) {
        out << p->id() << " ";
    }
    out << "\nBlack: ";
    for (std::shared_ptr<Piece> p : b._bjail) {
        out << p->id() << " ";
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
                return true;
            }
        }
        return false;
    }

    // Check for Left Linear Obstruction
    if (changeRow == 0 && changeCol < 0) {
        for (int i = col - 1; i > dCol; i--) {
            if (_board[row][i] != nullptr) {
                return true;
            }
        }
        return false;
    }

    // Check for Up Linear Obstruction
    if (changeCol == 0 && changeRow < 0) {
        for (int i = row - 1; i > dRow; i--) {
            if (_board[i][col] != nullptr) return true;
        }
        return false;
    }

    // Check for Down Linear Obstruction
    if (changeCol == 0 && changeRow > 0) {
        for (int i = row + 1; i < dRow; i++) {
            if (_board[i][col] != nullptr) return true;
        }
        return false;
    }

    if (abs(changeRow/changeCol) != 1) {
        return false;
    }

    // Check for Top-Right Diagonal Obstruction
    if (changeRow < 0 && changeCol > 0) {
        int i = row - 1;
        int j = col + 1;
        while (i > dRow && j < dCol) {
            if (_board[i--][j++] != nullptr) return true;
        }
        return false;
    }

    // Check for Top-Left Diagonal Obstruction
    if (changeRow < 0 && changeCol < 0) {
        int i = row - 1;
        int j = col - 1;
        while (i > dRow && j > dCol) {
            if (_board[i--][j--] != nullptr) return true;
        }
        return false;
    }

    // Check for Bottom-Left Diagonal Obstruction
    if (changeRow > 0 && changeCol < 0) {
        int i = row + 1;
        int j = col - 1;
        while (i < dRow && j > dCol) {
            if (_board[i++][j--] != nullptr) return true;
        }
        return false;
    }

    // Check for Bottom-Right Diagonal Obstruction
    if (changeRow > 0 && changeCol > 0) {
        int i = row + 1;
        int j = col + 1;
        while (i < dRow && j < dCol) {
            if (_board[i++][j++] != nullptr) return true;
        }
        return false;
    }

    return false;
}

void Board::clear() {
    for (unsigned int i = 0; i < _board.size(); i++) {
        for (unsigned int j = 0; j < _board.size(); j++) {
            _board[i][j] = nullptr;
        }
    }
}

Board& Board::operator=(Board&& other) noexcept {
    if (this != &other) {
        _board = std::move(other._board);
        _wjail = std::move(other._wjail);
        _bjail = std::move(other._bjail);

        // Reset other's state
        other._board.clear();
        other._wjail.clear();
        other._bjail.clear();
    }
    return *this;
}
