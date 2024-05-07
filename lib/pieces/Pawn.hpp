// Copyright (2024) Alvin Yu

#pragma once
#include "Piece.hpp"

class Pawn: public Piece {
 public:
    explicit Pawn(pcolor color) {
        setColor(color);
        setType(P);
    }
};

