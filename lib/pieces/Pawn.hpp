// Copyright (2024) Alvin Yu

#pragma once
#include <iostream>
#include <memory>
#include "Piece.hpp"

class Pawn: public Piece {
    bool _ep;
 public:
    Pawn(pcolor color, bool ep) {
        _ep = ep;
        setColor(color);
        setType(P);
    }

    virtual bool ep() {return _ep;}

    virtual bool move(int row, int col, int dRow, int dCol,
                      std::vector<std::vector<std::shared_ptr<Piece>>> board);
};

