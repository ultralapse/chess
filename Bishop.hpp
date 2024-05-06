#include "Piece.hpp"

class Bishop: public Piece {
 public:
    Bishop(pcolor color) {
        setColor(color);
        setType(B);
    }
};