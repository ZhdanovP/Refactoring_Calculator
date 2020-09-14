#include "BishopFigure.h"

BishopFigure::BishopFigure(std::string coord) : ChessFigure(coord)
{}

bool BishopFigure::Move(std::string nextCoord)
{
    auto currFigureCoord = getCurrentPos();
    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
    {
        if (!(abs(nextCoord[0] - currFigureCoord[0]) == abs(nextCoord[1] - currFigureCoord[1])))
            return false;
        else
            return true;
    }
    else return false;
}