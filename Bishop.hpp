// Copyright (2024) Alvin Yu

#include "Piece.hpp"

class Bishop: public Piece {
 public:
    explicit Bishop(pcolor color) {
        setColor(color);
        setType(B);
    }
};


