#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, std::string coord)
    : type(type)
    , currentCoord(coord)
    , horizontalCoordDist(0)
    , verticalCoordDist(0) {}

ChessFigure::~ChessFigure() {}

bool ChessFigure::Move(string nextCoord) {
  horizontalCoordDist = abs(nextCoord[0] - currentCoord[0]);
  verticalCoordDist = abs(nextCoord[1] - currentCoord[1]);

  if (isCoordinatesValid(nextCoord)) {
    if (type == PAWN) {
      return pawnMove(nextCoord);
    } else if (type == ROOK) {
      return rookMove(nextCoord);
    } else if (type == KNIGHT) {
      return knightMove(nextCoord);
    } else if (type == BISHOP) {
      return bishopMove(nextCoord);
    } else if (type == KING) {
      return kingMove(nextCoord);
    } else if (type == QUEEN) {
      return queenMove(nextCoord);
    } else
      return false;
  } else
    return false;
}

bool ChessFigure::isCoordinatesValid(string nextCoord) {
  return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' &&
         nextCoord[1] <= '8';
}

bool ChessFigure::pawnMove(string nextCoord) {
  if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] ||
      (nextCoord[1] - currentCoord[1] != 1 &&
       (currentCoord[1] != '2' || nextCoord[1] != '4')))
    return false;
  else
    return true;
}

bool ChessFigure::rookMove(string nextCoord) {
  if (((nextCoord[0] != currentCoord[0]) &&
       (nextCoord[1] != currentCoord[1])) ||
      ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
    return false;
  else
    return true;
}

bool ChessFigure::knightMove(string nextCoord) {
  if (!((horizontalCoordDist == 1 && verticalCoordDist == 2) ||
        (horizontalCoordDist == 2 && verticalCoordDist == 1)))
    return false;
  else
    return true;
}

bool ChessFigure::bishopMove(string nextCoord) {
  if (!(horizontalCoordDist == verticalCoordDist))
    return false;
  else
    return true;
}

bool ChessFigure::kingMove(string nextCoord) {
  if (!(horizontalCoordDist <= 1 && verticalCoordDist <= 1))
    return false;
  else
    return true;
}

bool ChessFigure::queenMove(string nextCoord) {
  if (!(horizontalCoordDist == verticalCoordDist ||
        nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
    return false;
  else
    return true;
}
