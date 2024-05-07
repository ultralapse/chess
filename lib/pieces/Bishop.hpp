// Copyright (2024) Alvin Yu

#pragma once
#include "Piece.hpp"

class Bishop: public Piece {
 public:
    explicit Bishop(pcolor color) {
        setColor(color);
        setType(B);
    }
};


