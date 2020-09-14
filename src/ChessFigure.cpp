#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, std::string coord)
    : type(type), currentCoord(coord) {}

ChessFigure::~ChessFigure() {}

bool ChessFigure::Move(string nextCoord) {
  int horizontalCoordDist = abs(nextCoord[0] - currentCoord[0]);
  int verticalCoordDist = abs(nextCoord[1] - currentCoord[1]);

  if (isCoordinatesValid(nextCoord)) {
    if (type == PAWN) {
      if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] ||
          (nextCoord[1] - currentCoord[1] != 1 &&
           (currentCoord[1] != '2' || nextCoord[1] != '4')))
        return false;
      else
        return true;

    } else if (type == ROOK) {
      if (((nextCoord[0] != currentCoord[0]) &&
           (nextCoord[1] != currentCoord[1])) ||
          ((nextCoord[0] == currentCoord[0]) &&
           (nextCoord[1] == currentCoord[1])))
        return false;
      else
        return true;
    } else if (type == KNIGHT) {
      if (!((horizontalCoordDist == 1 && verticalCoordDist == 2) ||
            (horizontalCoordDist == 2 && verticalCoordDist == 1)))
        return false;
      else
        return true;
    } else if (type == BISHOP) {
      if (!(horizontalCoordDist == verticalCoordDist))
        return false;
      else
        return true;
    } else if (type == KING) {
      if (!(horizontalCoordDist <= 1 && verticalCoordDist <= 1))
        return false;
      else
        return true;
    } else if (type == QUEEN) {
      if (!(horizontalCoordDist == verticalCoordDist ||
            nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
        return false;
      else
        return true;
    } else
      return false;
  } else
    return false;
}

bool ChessFigure::isCoordinatesValid(string nextCoord) {
  return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' &&
         nextCoord[1] <= '8';
}
