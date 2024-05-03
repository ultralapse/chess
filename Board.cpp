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

void Board::check() {
    
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
        