#include "PawnFigure.h"

PawnFigure::PawnFigure(std::string coord) : ChessFigure(coord)
{}

bool PawnFigure::Move(std::string nextCoord)
{
    auto currParsedCoord = getParsedCoords(getCurrentPos());
    auto nextParsedCoord = getParsedCoords(nextCoord);
    
    if (!nextParsedCoord)
    {
        return false;
    }

    auto subNumbersResult = nextParsedCoord->second - currParsedCoord->second;

    auto defaultTurn = (subNumbersResult == 1) && (nextParsedCoord->first == currParsedCoord->first);
    auto firstTurn = (currParsedCoord->second == 1) && (subNumbersResult == 2);
    auto eatFigure = (subNumbersResult== 1) && (abs(nextParsedCoord->first - currParsedCoord->first) == 1);

    if (defaultTurn && firstTurn && eatFigure)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}