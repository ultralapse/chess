// Copyright (2024) Alvin Yu

#pragma once
#include <iostream>
#include <memory>
#include "Piece.hpp"

class Pawn: public Piece {
 public:
    explicit Pawn(pcolor color) {
        setColor(color);
        setType(P);
    }
    virtual bool move(int row, int col, int dRow, int dCol,
                      std::vector<std::vector<std::shared_ptr<Piece>>> board);
};

