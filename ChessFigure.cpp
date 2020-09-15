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


bool Pawn::Move(const string& nextCoord) const
{
	if (checkCoords(nextCoord))
	{
		const bool vertical = nextCoord[0] == currentCoord[0];
		const bool forward = nextCoord[1] > currentCoord[1];
		const bool firstMove = currentCoord[1] == '2' && nextCoord[1] == '4';
		const bool oneForward = nextCoord[1] - currentCoord[1] == 1;
		if (vertical && forward && (oneForward || firstMove))
			return true;
	}
	return false;
}

bool Rook::Move(const string& nextCoord) const
{
	if (checkCoords(nextCoord))
	{
		const bool vertical = nextCoord[0] == currentCoord[0];
        const bool horizontal = nextCoord[1] == currentCoord[1];
		if (vertical || horizontal)
			return true;
	}
	return false;
}

bool Knight::Move(const string& nextCoord) const
{
	if (checkCoords(nextCoord))
	{
		const int dx = nextCoord[0] - currentCoord[0];
		const int dy = nextCoord[1] - currentCoord[1];
        const bool g1 = abs(dx) == 1 && abs(dy) == 2;
        const bool g2 = abs(dx) == 2 && abs(dy) == 1;
		if (g1 || g2)
			return true;
	}
	return false;
}

bool Bishop::Move(const string& nextCoord) const
{
	if (checkCoords(nextCoord))
	{
		const int dx = nextCoord[0] - currentCoord[0];
		const int dy = nextCoord[1] - currentCoord[1];
		const bool diagonal = abs(dx) == abs(dy);
		if (diagonal)
			return true;
	}
	return false;
}

bool King::Move(const string& nextCoord) const
{
	if (checkCoords(nextCoord))
	{
		const int dx = nextCoord[0] - currentCoord[0];
		const int dy = nextCoord[1] - currentCoord[1];
		if (abs(dx) <= 1 && abs(dy) <= 1)
			return true;
	}
	return false;
}

bool Queen::Move(const string& nextCoord) const
{
	if (checkCoords(nextCoord))
	{
		const int dx = nextCoord[0] - currentCoord[0];
		const int dy = nextCoord[1] - currentCoord[1];
		const bool vertical = nextCoord[0] == currentCoord[0];
		const bool horizontal = nextCoord[1] == currentCoord[1];
		const bool diagonal = abs(dx) == abs(dy);
		if (diagonal || vertical || horizontal)
			return true;
	}
	return false;
}
