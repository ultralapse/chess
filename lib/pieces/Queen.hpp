// Copyright (2024) Alvin Yu

#pragma once
#include "Piece.hpp"

class Queen: public Piece {
 public:
    explicit Queen(pcolor color) {
        setColor(color);
        setType(Q);
    }
};

