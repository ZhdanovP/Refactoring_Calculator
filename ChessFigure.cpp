#include "ChessFigure.hpp"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(std::string coord) : currentCoord(coord)
{
}

ChessFigure::~ChessFigure() = default;

bool ChessFigure::isWithinBoard(std::string nextCoord)
{
	return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8';
}


bool Pawn::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
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

bool Rook::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		const bool vertical = nextCoord[0] == currentCoord[0];
        const bool horizontal = nextCoord[1] == currentCoord[1];
        const bool stay = vertical && vertical;
		if ((vertical || horizontal) && !stay)
			return true;
	}
	return false;
}

bool Knight::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		const int dx = abs(nextCoord[0] - currentCoord[0]);
		const int dy = abs(nextCoord[1] - currentCoord[1]);
		if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1))
			return true;
	}
	return false;
}

bool Bishop::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		const int dx = abs(nextCoord[0] - currentCoord[0]);
		const int dy = abs(nextCoord[1] - currentCoord[1]);
		if (dx == dy)
			return true;
	}
	return false;
}

bool King::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		const int dx = nextCoord[0] - currentCoord[0];
		const int dy = nextCoord[1] - currentCoord[1];
		if (abs(dx) <= 1 && abs(dy) <= 1)
			return true;
	}
	return false;
}

bool Queen::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
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
