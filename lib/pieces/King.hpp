// Copyright (2024) Alvin Yu

#pragma once
#include "Piece.hpp"

class King: public Piece {
 public:
    explicit King(pcolor color) {
        setColor(color);
        setType(K);
    }
    virtual bool move(int row, int col, int dRow, int dCol);
};

