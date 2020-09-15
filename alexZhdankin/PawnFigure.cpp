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
    auto subLettersResult = nextParsedCoord->first - currParsedCoord->first;

    auto defaultTurn = (subNumbersResult == 1) && (nextParsedCoord->first == currParsedCoord->first);
    auto firstTurn = (currParsedCoord->second == '2') && (nextParsedCoord->second == '4');
    auto eatFigure = (subNumbersResult== 1) && (abs(subLettersResult) == 1);

    if (defaultTurn || firstTurn || eatFigure)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}