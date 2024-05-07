// Copyright (2024) Alvin Yu

#pragma once
#include <iostream>
#include "Piece.hpp"

class Bishop: public Piece {
 public:
    explicit Bishop(pcolor color) {
        setColor(color);
        setType(B);
    }
    bool move(int row, int col, int dRow, int dCol);
};


