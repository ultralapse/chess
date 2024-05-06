// Copyright (2024)

#include <iostream>
#include <vector>
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "King.hpp"

class Board {
 private:
    std::vector<std::vector<Piece *>> _board;
    std::vector<Piece *> _wjail;
    std::vector<Piece *> _bjail;

 public:
    Board() {
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

    void write(int row, int col, Piece& p);

    // Will automatically capture pieces regardless of the rules.
    void move(int row, int col, int dRow, int dCol);

    friend std::ostream& operator<<(std::ostream& out, Board &b);
};

