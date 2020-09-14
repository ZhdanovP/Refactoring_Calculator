#ifndef PAWN_HPP
#define PAWN_HPP
#include "ChessFigure.hpp"
class Pawn : public ChessFigure {
 public:
  Pawn(std::string coord) : ChessFigure(coord) {}

 private:
  bool allowMovement(std::string nextCoord) override {
    if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] ||
        (nextCoord[1] - currentCoord[1] != 1 &&
         (currentCoord[1] != '2' || nextCoord[1] != '4')))
      return false;
    else
      return true;
  }
};

#endif
