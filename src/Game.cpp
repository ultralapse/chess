// Copyright (2024) Alvin Yu

#include "Game.hpp"
#include <fstream>


// void Game::undo() {
//     if (stack.empty()) {
//         std::cout << "You have not made a move" << std::endl;
//         return;
//     }

//     std::shared_ptr<Piece> p = nullptr;


//     if (stack.back() == "CB") {
//         p = b.wjail().back();
//         b.wjail().pop_back();
//         stack.pop_back();
//     }

//     if (stack.back() == "CW") {
//         p = b.bjail().back();
//         b.bjail().pop_back();
//         stack.pop_back();
//     }

//     std::string pos1 = stack.back(); stack.pop_back();
//     std::string pos2 = stack.back(); stack.pop_back();

//     std::pair<int, int> c1 = converter(pos1);
//     std::pair<int, int> c2 = converter(pos2);

//     b.swap(c1.first, c1.second, c2.first, c2.second);
//     b.write(c1.first, c1.second, p);

//     if (c2.first == 1 || c2.first == 6) {
//         b.get(c2.first, c2.second)->setEP(false);
//     }
// }

void Game::move(const std::string &pos1, const std::string &pos2) {
    std::pair<int, int> c1 = converter(pos1);
    std::pair<int, int> c2 = converter(pos2);

    // unsigned int wSize = b.wjail().size();
    // unsigned int bSize = b.bjail().size();

    // Make sure the player is moving the right piece.
    if (turn && b.get(c1.first, c1.second)->color() != White) {
        std::cout << "It's White's Turn." << std::endl;
        return;
    }

    if (!turn && b.get(c1.first, c1.second)->color() != Black) {
        std::cout << "It Black's Turn." << std::endl;
        return;
    }

    b.move(c1.first, c1.second, c2.first, c2.second);

    // And then undo the move if it results in a Check.

    // if (moved) {
    //     stack.push_back(pos1);
    //     stack.push_back(pos2);

    //     if (b.wjail().size() != wSize) {
    //         stack.push_back("CB");
    //     }

    //     if (b.bjail().size() != bSize) {
    //         stack.push_back("CW");
    //     }
    // }

    turn = !turn;
}

std::pair<int, int> Game::converter(const std::string& notation) {
    if (notation.size() != 2) {
        throw std::invalid_argument("Invalid chess notation");
    }

    char colLetter = notation[0];
    char rowNumber = notation[1];

    if (colLetter < 'A' || colLetter > 'H' || rowNumber < '1' || rowNumber > '8') {
        throw std::invalid_argument("Invalid chess notation");
    }

    int col = colLetter - 'A';
    int row = '8' - rowNumber;

    return {row, col};
}

void Game::save() {
    // Open the file
    std::ofstream file(filename);

    // Assuming _board is a 2D array of Piece*
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::shared_ptr<Piece> piece = b.get(i, j);
            if (piece == nullptr) {
                file << "0 ";  // Write 0 for empty squares
                continue;
            }
            int value = 0;
            switch (piece->type()) {
                case P:
                    value = (piece->color() == White) ? 1 : 7;
                    if (piece->ep()) value = -value;
                    // std::cout << value << std::endl;
                    break;
                case N:
                    value = (piece->color() == White) ? 2 : 8;
                    break;
                case R:
                    value = (piece->color() == White) ? 3 : 9;
                    break;
                case B:
                    value = (piece->color() == White) ? 4 : 10;
                    break;
                case Q:
                    value = (piece->color() == White) ? 5 : 11;
                    break;
                case K:
                    value = (piece->color() == White) ? 6 : 12;
                    break;
            }

            // Write the value to the file, followed by a space
            file << value << ' ';
        }

        // Write a newline at the end of each row
        file << '\n';
    }

    file << b.wjail().size() << " ";
    for (std::shared_ptr<Piece> piece : b.wjail()) {
        int value = 0;
        switch (piece->type()) {
            case P:
                value = (piece->color() == White) ? 1 : 7;
                if (piece->ep()) value = -value;
                break;
            case N:
                value = (piece->color() == White) ? 2 : 8;
                break;
            case R:
                value = (piece->color() == White) ? 3 : 9;
                break;
            case B:
                value = (piece->color() == White) ? 4 : 10;
                break;
            case Q:
                value = (piece->color() == White) ? 5 : 11;
                break;
            case K:
                value = (piece->color() == White) ? 6 : 12;
                break;
        }

        // Write the value to the file, followed by a space
        file << value << ' ';
    }

    file << "\n";

    file << b.bjail().size() << " ";
    for (std::shared_ptr<Piece> piece : b.bjail()) {
        int value = 0;
        switch (piece->type()) {
            case P:
                value = (piece->color() == White) ? 1 : 7;
                if (piece->ep()) value = -value;
                break;
            case N:
                value = (piece->color() == White) ? 2 : 8;
                break;
            case R:
                value = (piece->color() == White) ? 3 : 9;
                break;
            case B:
                value = (piece->color() == White) ? 4 : 10;
                break;
            case Q:
                value = (piece->color() == White) ? 5 : 11;
                break;
            case K:
                value = (piece->color() == White) ? 6 : 12;
                break;
        }

        // Write the value to the file, followed by a space
        file << value << ' ';
    }

    file << "\n";

    file << turn;

    // file << stack.size() << ' ';


    // for (std::string s : stack) {
    //     file << s << ' ';
    // }

    // Close the file
    file.close();
}

void Game::load() {
    // Open the file
    std::ifstream file(filename);

    // Check if the file was opened successfully
    if (!file) {
        std::cerr << "Unable to open file " << filename << ". ";
        std::cerr << "Creating new file.\n";
        return;
    }

    // Read the values from the file
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int value;
            file >> value;

            // Replace the old piece with a new one based on the value
            if (value != 0) {
                pcolor color = (abs(value) <= 6) ? White : Black;
                switch (value % 6) {
                    case -1:
                        // std::cout << color << std::endl;
                        b.set(i, j, std::make_shared<Pawn>(color, true));
                        break;
                    case 1:
                        b.set(i, j, std::make_shared<Pawn>(color, false));
                        break;
                    case 2:
                        b.set(i, j, std::make_shared<Knight>(color));
                        break;
                    case 3:
                        b.set(i, j, std::make_shared<Rook>(color));
                        break;
                    case 4:
                        b.set(i, j, std::make_shared<Bishop>(color));
                        break;
                    case 5:
                        b.set(i, j, std::make_shared<Queen>(color));
                        break;
                    case 0:
                        b.set(i, j, std::make_shared<King>(color));
                        break;
                }
            } else {
                b.set(i, j, nullptr);  // Set empty squares to nullptr
            }
        }
    }

    int value;
    file >> value;
    for (int i = 0; i < value; i++) {
        int code;
        file >> code;
        switch (code % 6) {
            case -1:
                b.wjail().push_back(std::make_shared<Pawn>(Black, true));
                break;
            case 1:
                b.wjail().push_back(std::make_shared<Pawn>(Black, false));
                break;
            case 2:
                b.wjail().push_back(std::make_shared<Knight>(Black));
                break;
            case 3:
                b.wjail().push_back(std::make_shared<Rook>(Black));
                break;
            case 4:
                b.wjail().push_back(std::make_shared<Bishop>(Black));
                break;
            case 5:
                b.wjail().push_back(std::make_shared<Queen>(Black));
                break;
            case 0:
                b.wjail().push_back(std::make_shared<King>(Black));
                break;
        }
    }

    file >> value;
    for (int i = 0; i < value ; i++) {
        int code;
        file >> code;
        switch (code % 6) {
            case -1:
                b.wjail().push_back(std::make_shared<Pawn>(White, true));
                break;
            case 1:
                b.bjail().push_back(std::make_shared<Pawn>(White, false));
                break;
            case 2:
                b.bjail().push_back(std::make_shared<Knight>(White));
                break;
            case 3:
                b.bjail().push_back(std::make_shared<Rook>(White));
                break;
            case 4:
                b.bjail().push_back(std::make_shared<Bishop>(White));
                break;
            case 5:
                b.bjail().push_back(std::make_shared<Queen>(White));
                break;
            case 0:
                b.bjail().push_back(std::make_shared<King>(White));
                break;
        }
    }

    file >> turn;

    // int total;
    // file >> total;

    // for (int i = 0; i < total; i++) {
    //     std::string s;
    //     file >> s;
    //     stack.push_back(s);
    // }

    // Close the file
    file.close();
}

// WP=1, WN=2, WR=3, WB=4, WQ=5, WK=6, BP=7, BN=8, BR=9, BB=10, BQ=11, BK=12


