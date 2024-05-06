// Copyright (2024) Alvin Yu

#include "Piece.hpp"

class Knight: public Piece {
 public:
    explicit Knight(pcolor color) {
        setColor(color);
        setType(N);
    }
};

