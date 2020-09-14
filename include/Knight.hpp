#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "ChessFigure.hpp"

class Knight : public ChessFigure {
 public:
  Knight(std::string coord) : ChessFigure(coord) {}

 private:
  bool allowMovement(std::string nextCoord) override {
    if (!((horizontalCoordDist == 1 && verticalCoordDist == 2) ||
          (horizontalCoordDist == 2 && verticalCoordDist == 1)))
      return false;
    else
      return true;
  }
};

#endif
