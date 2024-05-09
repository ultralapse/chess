// Copyright (2024) Alvin Yu

#include "Game.hpp"
#include <fstream>

void Game::move(const std::string &pos1, const std::string &pos2) {
    std::pair<int, int> c1 = converter(pos1);
    std::pair<int, int> c2 = converter(pos2);

    b.move(c1.first, c1.second, c2.first, c2.second);
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
            Piece* piece = b.get(i, j);
            if (piece == nullptr) {
                file << "0 ";  // Write 0 for empty squares
                continue;
            }
            int value = 0;
            switch (piece->type()) {
                case P:
                    value = (piece->color() == White) ? 1 : 7;
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

    for (Piece *piece : b.wjail()) {
        int value = 0;
        switch (piece->type()) {
            case P:
                value = (piece->color() == White) ? 1 : 7;
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

    for (Piece *piece : b.wjail()) {
        int value = 0;
        switch (piece->type()) {
            case P:
                value = (piece->color() == White) ? 1 : 7;
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

    // Close the file
    file.close();
}

void Game::load() {
    // Open the file
    std::ifstream file(filename);

    // Check if the file was opened successfully
    if (!file) {
        std::cerr << "Unable to open file output.txt";
        return;
    }

    // Read the values from the file
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int value;
            file >> value;

            // Replace the old piece with a new one based on the value
            if (value != 0) {
                pcolor color = (value <= 6) ? White : Black;
                switch (value % 6) {
                    case 1:
                        b.set(i, j, new Pawn(color));
                        break;
                    case 2:
                        b.set(i, j, new Knight(color));
                        break;
                    case 3:
                        b.set(i, j, new Rook(color));
                        break;
                    case 4:
                        b.set(i, j, new Bishop(color));
                        break;
                    case 5:
                        b.set(i, j, new Queen(color));
                        break;
                    case 0:
                        b.set(i, j, new King(color));
                        break;
                }
            } else {
                b.set(i, j, nullptr);  // Set empty squares to nullptr
            }
        }
    }

    // Close the file
    file.close();
}

// WP=1, WN=2, WR=3, WB=4, WQ=5, WK=6, BP=7, BN=8, BR=9, BB=10, BQ=11, BK=12


