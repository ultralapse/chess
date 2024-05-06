// Copyright (2024) Alvin Yu
#include "Piece.hpp"

class King: public Piece {
 public:
    King(pcolor color) {
        setColor(color);
        setType(K);
    }
};