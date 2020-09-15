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
		if (nextCoord[0] == currentCoord[0] && nextCoord[1] > currentCoord[1] && (nextCoord[1] - currentCoord[1] == 1 || (currentCoord[1] == '2' && nextCoord[1] == '4')))
			return true;
	}
	return false;
}

bool Rook::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		if (((nextCoord[0] == currentCoord[0]) || (nextCoord[1] == currentCoord[1])) && ((nextCoord[0] != currentCoord[0]) || (nextCoord[1] != currentCoord[1])))
			return true;
	}
	return false;
}

bool Knight::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		int dx, dy;
		dx = abs(nextCoord[0] - currentCoord[0]);
		dy = abs(nextCoord[1] - currentCoord[1]);
	    if ((abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2) || (abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
			return true;
	}
	return false;
}

bool Bishop::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		if (abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]))
			return true;
	}
	return false;
}

bool King::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		if (abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1)
			return true;
	}
	return false;
}

bool Queen::Move(string nextCoord)
{
	if (isWithinBoard(nextCoord))
	{
		if (abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1])
			return true;
	}
	return false;
}
