#ifndef KING_HPP
#define KING_HPP
#include "ChessFigure.hpp"

class King : public ChessFigure {
 public:
  King(std::string coord) : ChessFigure(coord) {}

 private:
  bool allowMovement(std::string nextCoord) override {
    if (!(horizontalCoordDist <= 1 && verticalCoordDist <= 1))
      return false;
    else
      return true;
  }
};

#endif
