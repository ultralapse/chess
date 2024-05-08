// Copyright (2024) Alvin Yu

#pragma once
#include "Piece.hpp"

class Knight: public Piece {
 public:
    explicit Knight(pcolor color) {
        setColor(color);
        setType(N);
    }

    virtual bool move(int row, int col, int dRow, int dCol);
};

