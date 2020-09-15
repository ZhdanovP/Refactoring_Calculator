#include "KnightFigure.h"

KnightFigure::KnightFigure(std::string coord) : ChessFigure(coord)
{}

bool KnightFigure::Move(std::string nextCoord)
{
    auto currParsedCoord = getParsedCoords(getCurrentPos());
    auto nextParsedCoord = getParsedCoords(nextCoord);
    if (!nextParsedCoord)
    {
        return false;
    }
    auto absSubLettersResult = abs(nextParsedCoord->first - currParsedCoord->first);
    auto absSubNumbersResult = abs(nextParsedCoord->second - currParsedCoord->second);
    if (((absSubLettersResult == 1) && (absSubNumbersResult == 2)) || 
        ((absSubLettersResult == 2) && (absSubNumbersResult == 1)))
    {
        return true;
    }
    else
    {
        return false;
    }
}