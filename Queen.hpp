// Copyright (2024) Alvin Yu

#include "Piece.hpp"

class Queen: public Piece {
 public:
    Queen(pcolor color) {
        setColor(color);
        setType(Q);
    }
};

