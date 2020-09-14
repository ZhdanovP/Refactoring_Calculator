#ifndef ROOK_HPP
#define ROOK_HPP
#include "ChessFigure.hpp"

class Rook : virtual public ChessFigure {
 public:
  Rook(std::string coord) : ChessFigure(coord) {}

 protected:
  bool allowMovement(std::string nextCoord) override {
    if (((nextCoord[0] != currentCoord[0]) &&
         (nextCoord[1] != currentCoord[1])) ||
        ((nextCoord[0] == currentCoord[0]) &&
         (nextCoord[1] == currentCoord[1])))
      return false;
    else
      return true;
  }
};

#endif
