// Copyright (2024) Alvin Yu

#pragma once
#include <string>
#include "lib/Board.hpp"

class Game {
    // WP=1, WN=2, WR=3, WB=4, WQ=5, WK=6, BP=7, BN=8, BR=9, BB=10, BQ=11, BK=12
    Board b;

    bool checkmate;
    bool check;
    bool castled;

    std::string filename;

 public:
    explicit Game(std::string filename) {this->filename = filename;}

    void load();

    void save();

    Board& getBoard() {return b;}

    bool castle();
};


