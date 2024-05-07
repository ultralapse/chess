// Copyright (2024) Alvin Yu

#include "Piece.hpp"

std::string Piece::id() {
    switch (_color) {
        case White:
            switch (_type) {
                case P: return "♙";
                case N: return "♘";
                case R: return "♖";
                case B: return "♗";
                case Q: return "♕";
                case K: return "♔";
                default: return "♔";
            }
        case Black:
            switch (_type) {
                case P: return "♟";
                case N: return "♞";
                case R: return "♜";
                case B: return "♝";
                case Q: return "♛";
                case K: return "♚";
                default: return "♚";
            }

        default:
            return "";
    }
}

