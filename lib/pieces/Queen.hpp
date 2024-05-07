// Copyright (2024) Alvin Yu

#pragma once
#include <iostream>
#include <optional>
#include "Piece.hpp"

class Queen: public Piece {
 public:
    explicit Queen(pcolor color) {
        setColor(color);
        setType(Q);
    }

    virtual bool move(int row, int col, int dRow, int dCol);
};

