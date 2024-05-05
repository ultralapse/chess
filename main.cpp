// Copyright (2024)

#include <iostream>
#include "Board.hpp"

int main() {
    Board b;
    b.override(3, 3, WP);
    std::cout << b << std::endl;
    b.debugMove(3, 3, 0, 0);
    std::cout << b << std::endl;
    return 0;
}

