// Copyright (2024)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Game.hpp"
#include "lib/Board.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>


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
    Board b;
    b.clear();

    b.write(4, 4, new Rook(Black));
    BOOST_CHECK_EQUAL(b.move(4, 4, 5, 5), false);

    std::cout << b << std::endl;

    Board c;
    c.clear();
    c.write(4, 4, new Rook(Black));
    b.move(4, 4, 7, 4);

    BOOST_CHECK_EQUAL(b.get(7, 4)->type(), R);
}

BOOST_AUTO_TEST_CASE(testSaving) {
    Game g("board.txt");
    g.load();
    std::cout << g.getBoard() << std::endl;
}

