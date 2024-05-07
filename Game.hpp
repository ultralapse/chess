// Copyright (2024) Alvin Yu

#pragma once
#include "Board.hpp"

class Game {
    Board b;

    bool checkmate;
    bool check;
    bool castled;

 public:
    Game() {}

    Board& getBoard() {return b;}

    bool castle();
};


