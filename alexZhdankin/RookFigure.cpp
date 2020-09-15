#include "RookFigure.h"

RookFigure::RookFigure(std::string coord) : ChessFigure(coord)
{}

bool RookFigure::Move(std::string nextCoord)
{
    auto currParsedCoord = getParsedCoords(getCurrentPos());
    auto nextParsedCoord = getParsedCoords(nextCoord);
    
    if (!nextParsedCoord)
    {
        return false;
    }

    auto isLetterChanged = nextParsedCoord->first == currParsedCoord->first;
    auto isNumberChanged = nextParsedCoord->second == currParsedCoord->second;
    auto horizTurn = isLetterChanged && !isNumberChanged;
    auto vertTurn = !isLetterChanged && isNumberChanged;
    if (horizTurn || vertTurn)
    {
        return true;
    }
    else
    {
        return false;
    }
}