#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "ChessFigure.hpp"
class Bishop : virtual public ChessFigure {
 public:
  Bishop(std::string coord) : ChessFigure(coord) {}

 protected:
  bool allowMovement(std::string nextCoord) override {
    if (!(horizontalCoordDist == verticalCoordDist))
      return false;
    else
      return true;
  }
};

#endif
