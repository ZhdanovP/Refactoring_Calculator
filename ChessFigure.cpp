#include "ChessFigure.h"
#include <cmath>
#include <string>
#include <utility>

using namespace std;

bool SameDigit(const Coord &c1, const Coord &c2) {
  return c1.digit_ == c2.digit_;
}

bool SameLetter(const Coord &c1, const Coord &c2) {
  return c1.letter_ == c2.letter_;
}

bool SameLine(const Coord &c1, const Coord &c2) {
  return SameDigit(c1, c2) || SameLetter(c1, c2);
}

bool SameDiag(const Coord &c1, const Coord &c2) {
  return abs(c1.letter_ - c2.letter_) == abs(c1.digit_ - c2.digit_);
}

int AbsMaxDistance(const Coord &c1, const Coord &c2) {
  return max(abs(c1.DigitDistance(c2)), abs(c1.LetterDistance(c2)));
}

int AbsDistanceSquared(const Coord &c1, const Coord &c2) {
  auto dx = c1.DigitDistance(c2);
  auto dy = c1.LetterDistance(c2);
  return dx * dx + dy * dy;
}

bool Pawn::Move(Coord nextCoord) const {
  if (!SameLetter(currentCoord, nextCoord) ||
      currentCoord.DigitDistance(nextCoord) <= 0 ||
      (currentCoord.DigitDistance(nextCoord) != 1 &&
       (currentCoord.Digit() != '2' || nextCoord.Digit() != '4')))
    return false;
  else
    return true;
}

bool Rook::Move(Coord nextCoord) const {
  if (!SameLine(currentCoord, nextCoord))
    return false;
  else
    return true;
}

bool Knight::Move(Coord nextCoord) const {
  if (SameLine(currentCoord, nextCoord) ||
      AbsDistanceSquared(currentCoord, nextCoord) != 5)
    return false;
  else
    return true;
}

bool Bishop::Move(Coord nextCoord) const {
  if (!SameDiag(currentCoord, nextCoord))
    return false;
  else
    return true;
}

bool King::Move(Coord nextCoord) const {
  if (AbsMaxDistance(currentCoord, nextCoord) != 1)
    return false;
  else
    return true;
}

bool Queen::Move(Coord nextCoord) const {
  if (!SameLine(currentCoord, nextCoord) && !SameDiag(currentCoord, nextCoord))
    return false;
  else
    return true;
}
