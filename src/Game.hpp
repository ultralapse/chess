// Copyright (2024) Alvin Yu

#pragma once
#include <string>
#include "../lib/Board.hpp"

class Game {
    // WP=1, WN=2, WR=3, WB=4, WQ=5, WK=6, BP=7, BN=8, BR=9, BB=10, BQ=11, BK=12
    Board b;

    bool turn;

    bool wcheckmate;
    bool wcheck;

    bool bcheckmate;
    bool bcheck;

    bool wcastled;
    bool bcastled;

    std::string filename;

    std::vector<std::string> stack;

 public:
    explicit Game(std::string filename): turn(true) {this->filename = filename;}

    std::pair<int, int> converter(const std::string& notation);

    void move(const std::string &pos1, const std::string &pos2);

    void load();

    void undo();

    void reset() {this->b = Board(); stack.clear();}

    void save();

    Board& getBoard() {return b;}

    bool castle();
};


