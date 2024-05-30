// Copyright (2024) Alvin Yu

#pragma once
#include <string>
#include "../lib/Board.hpp"

struct Player {
    bool checkmate = false;
    bool check = false;
    bool stalemate = false;
    bool castled = false;
};

class Game {
    // WP=1, WN=2, WR=3, WB=4, WQ=5, WK=6, BP=7, BN=8, BR=9, BB=10, BQ=11, BK=12
    Board b;

    bool turn;

    Player white;
    Player black;

    std::string filename;

 public:
    // White Starts the Game
    explicit Game(std::string filename): turn(true), filename(std::move(filename)) {}

    // Converts chess notation into (row, col) format
    std::pair<int, int> converter(const std::string& notation);

    // Moves a piece from one square to the other. Interally calls the Board object move
    void move(const std::string &pos1, const std::string &pos2);

    // Restart the game
    void reset() {this->b = Board(); turn = true;}

    // Load a saved game from a file
    void load();

    // Save a game to the file
    void save();

    // Manipulate a board object directly
    Board& getBoard() {return b;}
};


