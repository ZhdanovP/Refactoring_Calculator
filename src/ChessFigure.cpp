#include "ChessFigure.hpp"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, std::string coord) : type(type),
currentCoord(Coordinate(coord))
{
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::checkFieldCoordinates(Coordinate coordinate)
{
	return coordinate.x >= X_MIN && coordinate.x <= X_MAX && coordinate.y >= Y_MIN && coordinate.y <= Y_MAX;
}

bool ChessFigure::Move(string nextCoord)
{
	MoveImpl(Coordinate(nextCoord));
}

bool ChessFigure::MoveImpl(Coordinate nextCoord)
{
	if (checkFieldCoordinates(nextCoord))
	{
		int deviation_x = abs(nextCoord.x - currentCoord.x);
		int deviation_y = abs(nextCoord.y - currentCoord.y);

		bool x_not_changed = deviation_x == 0;
		bool y_not_changed = deviation_y == 0;

		switch (type)
		{
		case (PAWN):			
			if (x_not_changed && (deviation_y >= 1 || (currentCoord.y == '2' && nextCoord.y == '4')))
			{
				return true;
			}
			break;
		case (ROOK):
			if (x_not_changed || y_not_changed)
			{
				return true;
			}
			break;
		case (KNIGHT):
			if (deviation_x == 1 && deviation_y == 2 || deviation_x == 2 && deviation_y == 1)
			{
				return true;
			}
			break;
		case (BISHOP):
			if (deviation_x == deviation_y)
			{
				return true;
			}
			break;
		case (KING):
			if (deviation_x <= 1 && deviation_y <= 1)
			{
				return true;
			}
			break;
		case (QUEEN):
			if (deviation_x == deviation_y || x_not_changed || y_not_changed)
			{
				return true;
			}
			break;
		default:
			return false;
		}
	}
	return false;	
}