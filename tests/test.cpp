// Copyright (2024)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include "../lib/Board.hpp"
#include "../Game.hpp"

// Test Check
BOOST_AUTO_TEST_CASE(obstructLinear) {
    Board b;
    b.write(5, 5, new Pawn(White));
    std::cout << b.get(5, 5)->id() << std::endl;
    bool result = b.obstruction(5, 1, 5, 7);

    BOOST_CHECK_EQUAL(result, true);

    result = b.obstruction(5, 7, 5, 1);

    BOOST_CHECK_EQUAL(result, true);

    result = b.obstruction(5, 1, 5, 2);

    BOOST_CHECK_EQUAL(result, false);

    result = b.obstruction(5, 2, 5, 1);

    BOOST_CHECK_EQUAL(result, false);
}

BOOST_AUTO_TEST_CASE(obstructDiagonal) {
    Board b;
    b.write(6, 4, new Pawn(White));
    std::cout << b.get(6, 4)->id() << std::endl;

    bool result = b.obstruction(5, 3, 7, 5);
    BOOST_CHECK_EQUAL(result, true);
    result = b.obstruction(7, 5, 4, 2);
    BOOST_CHECK_EQUAL(result, true);

    result = b.obstruction(5, 5, 7, 3);
    BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(queenMovement) {
    Board b;
    b.write(4, 4, new Queen(White));
    bool result = b.get(4, 4)->move(4, 4, 3, 2);
    BOOST_CHECK_EQUAL(result, false);
    std::cout << b << std::endl;

    b.move(4, 4, 5, 5);
    std::cout << b << std::endl;
    BOOST_CHECK_EQUAL(b.get(5, 5)->type(), Q);
}

BOOST_AUTO_TEST_CASE(RookMovement) {
    std::cout << "===================================" << std::endl;
    std::cout << "Testing Rook Movement" << std::endl;
    // Initialize a Board and clear the default configuration
    Board b;
    b.clear();

    // The Rook should be initialized to Row index 3, column index 3
    b.write(3, 3, new Rook(White));

    // Initialize Enemy Queen to (3, 0)
    b.write(3, 0, new Queen(Black));

    // Initialize Friendly Queen to (7, 3)
    b.write(7, 3, new Queen(White));

    // Illegally move the Rook
    BOOST_CHECK_EQUAL(b.move(3, 3, 5, 7), false);

    // Move the Rook to Enemy Queen Square. Expect a capture.
    BOOST_CHECK_EQUAL(b.move(3, 3, 3, 0), true);
    BOOST_CHECK_EQUAL(b.wjail().at(0)->type(), Q);

    // New Rook Position is (3, 0)
    // Now Move it to (0, 0)
    BOOST_CHECK_EQUAL(b.move(3, 0, 0, 0), true);

    // Illegally move past bounds of the board
    BOOST_CHECK_EQUAL(b.move(0, 0, 0, -1), false);

    b.move(0, 0, 3, 0);
    b.move(3, 0, 3, 3);

    // Do not capture your own troops
    BOOST_CHECK_EQUAL(b.move(3, 3, 7, 3), false);

    // Obstruction testing
    b.write(3, 1, new Pawn(White));
    BOOST_CHECK_EQUAL(b.move(3, 3, 3, 0), false);
}

BOOST_AUTO_TEST_CASE(pawnMovement) {
    std::cout << "Testing Pawn Movement" << std::endl;
    Board b;
    b.clear();
    b.write(3, 3, new Pawn(White));
    // b.write(2, 3, new Rook(Black));
    std::cout << b << std::endl;
    b.move(3, 3, 2, 3);
    std::cout << b << std::endl;
}
