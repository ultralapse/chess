// Copyright (2024) Alvin Yu

#pragma once
#include <memory>
#include <vector>
#include <string>

enum ptype {
    P, N, R, B, Q, K
};

enum pcolor {
    White, Black
};

class Piece {
    ptype _type;
    pcolor _color;

 public:
    virtual ~Piece() {}
    virtual ptype type() {return _type;}
    virtual pcolor color() {return _color;}
    virtual void setType(ptype _type) {this->_type = _type;}
    virtual void setColor(pcolor _color) {this->_color = _color;}
    virtual std::string id();
    virtual bool ep() {return false;}
    virtual void setEP(bool ep) {ep = 2;}
    virtual bool move(int row, int col, int dRow, int dCol) {return false;}
    virtual bool move(int row, int col, int dRow, int dCol,
                      std::vector<std::vector<std::shared_ptr<Piece>>> board) {return false;}
};



