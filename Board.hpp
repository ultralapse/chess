#include <iostream>
#include <vector>

enum Piece {
    WP=1, WH, WR, WQ, WK, WB,
    BP, BH, BR, BQ, BK, BB,
    NO
};

class Board {
    private:
        std::vector<std::vector<Piece>> board;
        bool castled; // Detecting if castling is possible
        bool turn; // White = True, Black = False
        bool check; // if check and movement false, STALEMATE

        std::pair<int, int> wKing;
        std::pair<int, int> bKing;

    public:
        Board() {
            board = std::vector<std::vector<Piece>>(8, std::vector<Piece>(8));
        }
        // bool move(int x, int y, int dX, int dY);
        // bool moveP(int x, int y, int dX, int dY);
        // bool moveH(int x, int y, int dX, int dY);
        // bool moveR(int x, int y, int dX, int dY);
        // bool moveQ(int x, int y, int dX, int dY);
        // bool moveK(int x, int y, int dX, int dY);
        // bool moveB(int x, int y, int dX, int dY);
        friend std::ostream& operator<<(std::ostream& out, Board &b);
        void override(int row, int col, Piece p);
        void debugMove(int row, int col, int dX, int dY);
        void check();
};