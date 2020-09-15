#include "BishopFigure.h"

BishopFigure::BishopFigure(std::string coord) : ChessFigure(coord)
{}

bool BishopFigure::Move(std::string nextCoord)
{
    auto currParsedCoord = getParsedCoords(getCurrentPos());
    auto nextParsedCoord = getParsedCoords(nextCoord);
    if (!nextParsedCoord)
    {
        return false;
    }
    auto absValOfLettersSub = abs(nextParsedCoord->first - currParsedCoord->first);
    auto absValOfNumbersSub = abs(nextParsedCoord->second - currParsedCoord->second);
    if (absValOfLettersSub == absValOfNumbersSub)
    {
        return true;
    }
    else
    {
        return false;
    }
}