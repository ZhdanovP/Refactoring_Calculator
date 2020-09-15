#include "KingFigure.h"

KingFigure::KingFigure(std::string coord) : ChessFigure(coord)
{}

bool KingFigure::Move(std::string nextCoord)
{
    auto currParsedCoord = getParsedCoords(getCurrentPos());
    auto nextParsedCoord = getParsedCoords(nextCoord);
    if (!nextParsedCoord)
    {
        return false;
    }
    if ((abs(nextParsedCoord->first - currParsedCoord->first) <= 1) && 
        (abs(nextParsedCoord->second - currParsedCoord->second) <= 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}