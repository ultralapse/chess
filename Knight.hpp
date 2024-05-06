// Copyright (2024) Alvin Yu

#include "Piece.hpp"

class Knight: public Piece {
 public:
    Knight(pcolor color) {
        setColor(color);
        setType(N);
    }
};

