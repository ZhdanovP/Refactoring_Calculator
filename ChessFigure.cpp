#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(std::string coord) : currentCoord(coord)
{
}

ChessFigure::~ChessFigure() = default;

bool ChessFigure::checkCoords(const std::string& nextCoord) const
{
  const bool validColomn = nextCoord[0] >= 'A' && nextCoord[0] <= 'H';
  const bool validRow = nextCoord[1] >= '1' && nextCoord[1] <= '8';
  const bool moves = nextCoord != currentCoord;
  return validColomn && validRow && moves;
}

bool ChessFigure::Move(const string& nextCoord) const
{
  const int dx = nextCoord[0] - currentCoord[0];
  const int dy = nextCoord[1] - currentCoord[1];
  return checkCoords(nextCoord) && peiceSpecificMove(dx, dy);
}

bool Pawn::peiceSpecificMove(const int dx, const int dy) const
{
  const bool vertical = 0 == dx;
  const bool firstMove2Forward = currentCoord[1] == '2' && dy == 2;
  const bool oneForward = dy == 1;
  return vertical && (oneForward || firstMove2Forward);
}

bool Rook::peiceSpecificMove(const int dx, const int dy) const
{
  const bool vertical = 0 == dx;
  const bool horizontal = 0 == dy;
  return vertical || horizontal;
}

bool Knight::peiceSpecificMove(const int dx, const int dy) const
{
  const bool g1 = abs(dx) == 1 && abs(dy) == 2;
  const bool g2 = abs(dx) == 2 && abs(dy) == 1;
  return g1 || g2;
}

bool Bishop::peiceSpecificMove(const int dx, const int dy) const
{
  const bool diagonal = abs(dx) == abs(dy);
  return diagonal;
}

bool King::peiceSpecificMove(const int dx, const int dy) const
{
  return abs(dx) <= 1 && abs(dy) <= 1;
}

bool Queen::peiceSpecificMove(const int dx, const int dy) const
{
  const bool vertical = 0 == dx;
  const bool horizontal = 0 == dy;
  const bool diagonal = abs(dx) == abs(dy);
  return diagonal || vertical || horizontal;
}
