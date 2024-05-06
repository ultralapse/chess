// Copyright (2024) Alvin Yu

#include "Board.hpp"

class Game {
    Board b;

    bool checkmate;
    bool check;
    bool castled;

 public:
    Game() {}

    Board& getBoard() {return b;}

    // Checks if a multisquare diagonal or straight line move is obstructed.
    bool obstruction(int row, int col, int dRow, int dCol);

    bool castle();
};


