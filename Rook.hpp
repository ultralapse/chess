// Copyright (2024) Alvin Yu

#include "Piece.hpp"

class Rook: public Piece {
 public:
    Rook(pcolor color) {
        setColor(color);
        setType(R);
    }
};

