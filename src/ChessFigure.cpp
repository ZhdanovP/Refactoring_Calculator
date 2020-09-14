#include "ChessFigure.hpp"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, std::string coord) : type(type),
currentCoord(coord)
{
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::checkFieldCoordinates(string nextCoord)
{
	return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8';
}

bool ChessFigure::Move(string nextCoord)
{
	if (checkFieldCoordinates(nextCoord))
	{
		int deviation_x = abs(nextCoord[0] - currentCoord[0]);
		int deviation_y = abs(nextCoord[1] - currentCoord[1]);

		bool x_not_changed = deviation_x == 0;
		bool y_not_changed = deviation_y == 0;

		switch (type)
		{
		case (PAWN):			
			if (x_not_changed && (deviation_y >= 1 || (currentCoord[1] == '2' && nextCoord[1] == '4')))
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