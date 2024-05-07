// Copyright (2024) Alvin Yu
#include "Piece.hpp"

class King: public Piece {
 public:
    explicit King(pcolor color) {
        setColor(color);
        setType(K);
    }
};

