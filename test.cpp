// Copyright (2024)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Board.hpp"

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


