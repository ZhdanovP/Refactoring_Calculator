#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "Rook.hpp"
#include "Bishop.hpp"
class Queen : public Rook, public Bishop {
 public:
  Queen(std::string coord) : ChessFigure(coord), Rook(coord), Bishop(coord) {}

 private:
  bool allowMovement(std::string nextCoord) override {
    return Rook::allowMovement(nextCoord) || Bishop::allowMovement(nextCoord);
  }
};

#endif
