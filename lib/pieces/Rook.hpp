// Copyright (2024) Alvin Yu

#pragma once
#include "Piece.hpp"

class Rook: public Piece {
 public:
    explicit Rook(pcolor color) {
        setColor(color);
        setType(R);
    }
    virtual bool move(int row, int col, int dRow, int dCol);
};

