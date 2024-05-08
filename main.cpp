// Copyright (2024)

#include <iostream>
#include "Game.hpp"
#include "lib/Board.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "CLI Options" << std::endl;
        std::cout << "FILENAME X Y DX DY\n";
    } else {
        Game g(argv[1]);
        g.load();
        if (argc > 2) {
            g.move(argv[2], argv[3]);
        }
        std::cout << g.getBoard() << std::endl;
        g.save();
    }
    return 0;
}

