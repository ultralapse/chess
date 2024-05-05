// Copyright (2024)

#include "Board.hpp"


// bool Board::move(int x, int y, int dX, int dY) {
//     switch (turn) {
//         case true:
//             switch (board.at(x).at(y)) {
//                 case WP: return moveP(x, y, dX, dY);
//                 case WH: return moveH(x, y, dX, dY);
//                 case WR: return moveR(x, y, dX, dY);
//                 case WQ: return moveQ(x, y, dX, dY);
//                 case WK: return moveK(x, y, dX, dY);
//                 case WB: return moveB(x, y, dX, dY);
//                 default: return false;
//             }
//         case false:
//             switch (board.at(x).at(y)){
//                 case BP: return moveP(x, y, dX, dY);
//                 case BH: return moveH(x, y, dX, dY);
//                 case BR: return moveR(x, y, dX, dY);
//                 case BQ: return moveQ(x, y, dX, dY);
//                 case BK: return moveK(x, y, dX, dY);
//                 case BB: return moveB(x, y, dX, dY);
//                 default: return false;
//         }
//     }
// }

std::ostream& operator<<(std::ostream& out, Board &b) {
    for (unsigned int i = 0; i < b.board.size(); i++) {
        for (unsigned int j = 0; j < b.board[0].size(); j++) {
            switch (b.board[i][j]) {
                case WP: out << "♙"; break;
                case WH: out << "♘"; break;
                case WR: out << "♖"; break;
                case WQ: out << "♕"; break;
                case WK: out << "♔"; break;
                case WB: out << "♗"; break;
                case BP: out << "♟"; break;
                case BH: out << "♞"; break;
                case BR: out << "♜"; break;
                case BQ: out << "♛"; break;
                case BK: out << "♚"; break;
                case BB: out << "♝"; break;
                default: out << " "; break;
            }
        }
        out << "\n";
    }
    return out;
}

void Board::override(int row, int col, Piece p) {
    board[row][col] = p;
}

void Board::debugMove(int row, int col, int dX, int dY) {
    board[dX][dY] = board[row][col];
    board[row][col] = NO;
}

bool Board::checkIf(int row, int col, bool player) {
    // Check Pawn Locations
    std::pair<int, int> diagtl = std::make_pair(-1, -1);
    std::pair<int, int> diagtr = std::make_pair(-1, -1);
    std::pair<int, int> diagbl = std::make_pair(-1, -1);
    std::pair<int, int> diagbr = std::make_pair(-1, -1);

    if (row != 0 && col != 0) diagtl = std::make_pair(row - 1, col - 1);
    if (row != 0 && col != 7) diagtr = std::make_pair(row - 1, col + 1);
    if (row != 7 && col != 0) diagbl = std::make_pair(row + 1, col - 1);
    if (row != 7 && col != 7) diagbr = std::make_pair(row + 1, col + 1);

    std::vector<std::pair<int, int>> posArray;
    posArray.push_back(diagtl); posArray.push_back(diagtr);
    posArray.push_back(diagbl); posArray.push_back(diagbr);

    for (unsigned int i = 0; i < posArray.size(); i++) {
        std::cout << posArray[i].first << " " << posArray[i].second << std::endl;
    }

    for (unsigned int i = 0; i < posArray.size(); i++) {
        if (posArray[i].first != -1) {
            switch (board[posArray[i].first][posArray[i].second]) {
                case WP:
                    switch (player) {
                        case true: break;
                        default: return true;
                    }
                    break;
                case BP:
                    switch (player) {
                        case false: break;
                        default: return true;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    // Check King Locations

    // Check Knight Locations

    // Check Queen, Rook, Bishop Locations

    bool checkQ = false;

    switch (player) {
        case true:
            for (int i = col - 1; i >= 0; i--) {
                switch (board[row][i]) {
                    case NO:
                        break;
                    default:
                        if (board[row][i] < 5) break;
                        if (board[row][i] == BQ || board[row][i] == BR) checkQ = true;
                        break;
                } 
            }

            for (int i = col + 1; i < 8; i++) {
                switch (board[row][i]) {
                    case NO:
                        break;
                    default:
                        if (board[row][i] < 5) break;
                        checkQ = true;
                        break;
                }   
            }

            for (int i = 0; i < row; i++) {
                
            }

        case false:

        default:
            break;
    }

    


    return false;
}

// bool Board::moveP(int x, int y, int dX, int dY) {
//     // Possible positions by rulebook
//     if (dY != y || dX != x + 1){
//         if (dY != y+1) return false;
//     }

//     Piece p = board[x][y];

//     return true;
// }
// bool Board::moveH(int x, int y, int dX, int dY) {
//     return false;
// }
// bool Board::moveR(int x, int y, int dX, int dY) {
//     return false;
// }
// bool Board::moveQ(int x, int y, int dX, int dY) {
//     return false;
// }
// bool Board::moveK(int x, int y, int dX, int dY) {
//     return false;
// }
// bool Board::moveB(int x, int y, int dX, int dY) {
//     return false;
// }


