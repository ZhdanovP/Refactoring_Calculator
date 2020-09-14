#include "ChessFigure.h"
#include <string>
#include <cmath>
#include <utility>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, Coord coord) : type(type),
currentCoord(std::move(coord))
{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(Coord nextCoord)
{
	if (type == PAWN)
	{
			if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
				return false;
			else
				return true;
	}
	
	else if (type == ROOK)
	{
			if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
				return false;
			else
				return true;
	}
	else if (type == KNIGHT)
	{
			int dx, dy;
			dx = abs(nextCoord[0] - currentCoord[0]);
			dy = abs(nextCoord[1] - currentCoord[1]);
		    if (!(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
			  return false;
			else
			return true;
	}
	
	else if (type == BISHOP)
	{
			if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])))
				return false;
			else
				return true;
	}
	
	else if (type == KING)
	{
			if (!(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1))
				return false;
			else
				return true;
	}
	else if (type == QUEEN)
	{
			if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
				return false;
			else
				return true;
	}
	else
		return false;
}