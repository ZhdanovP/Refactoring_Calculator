#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include "Coord.h"

#include <utility>

template <typename Tag> class ChessFigure {
public:
  ChessFigure(Coord coord) : currentCoord(std::move(coord)) {}
  bool Move(Coord nextCoord) const;

private:
  Coord currentCoord;
};

struct PawnTag {};
struct BishopTag {};
struct KnightTag {};
struct RookTag {};
struct KingTag {};
struct QueenTag {};

using Pawn = ChessFigure<PawnTag>;
using Bishop = ChessFigure<BishopTag>;
using Knight = ChessFigure<KnightTag>;
using Rook = ChessFigure<RookTag>;
using King = ChessFigure<KingTag>;
using Queen = ChessFigure<QueenTag>;

template <> bool Pawn::Move(Coord nextCoord) const {
  bool movesByOne = currentCoord.DigitDistance(nextCoord) == 1;
  bool firstMoveByTwo = currentCoord.Digit() == '2' && nextCoord.Digit() == '4';
  return SameLetter(currentCoord, nextCoord) && (movesByOne || firstMoveByTwo);
}

template <> bool Bishop::Move(Coord nextCoord) const {
  return SameDiag(currentCoord, nextCoord);
}

template <> bool Knight::Move(Coord nextCoord) const {
  return !SameLine(currentCoord, nextCoord) &&
         AbsDistanceSquared(currentCoord, nextCoord) == 5;
}

template <> bool Rook::Move(Coord nextCoord) const {
  return SameLine(currentCoord, nextCoord);
}

template <> bool King::Move(Coord nextCoord) const {
  return AbsMaxDistance(currentCoord, nextCoord) == 1;
}

template <> bool Queen::Move(Coord nextCoord) const {
  return SameLine(currentCoord, nextCoord) || SameDiag(currentCoord, nextCoord);
}

#endif
