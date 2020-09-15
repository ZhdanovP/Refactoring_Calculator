#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(std::string coord)
    : currentCoord(coord), horizontalCoordDist(0), verticalCoordDist(0) {}

ChessFigure::~ChessFigure() {}

bool ChessFigure::Move(string nextCoord) {
  horizontalCoordDist = abs(nextCoord[0] - currentCoord[0]);
  verticalCoordDist = abs(nextCoord[1] - currentCoord[1]);

  if (isCoordinatesValid(nextCoord)) {
    return allowMovement(nextCoord);
  } else
    return false;
}

bool ChessFigure::isCoordinatesValid(string nextCoord) {
  return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' &&
         nextCoord[1] <= '8';
}
