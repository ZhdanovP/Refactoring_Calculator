#include "QueenFigure.h"

QueenFigure::QueenFigure(std::string coord) : ChessFigure(coord)
{}

bool QueenFigure::Move(std::string nextCoord)
{
    auto currParsedCoord = getParsedCoords(getCurrentPos());
    auto nextParsedCoord = getParsedCoords(nextCoord);
    
    if (!nextParsedCoord)
    {
        return false;
    }

    auto subLettersResult = nextParsedCoord->first - currParsedCoord->first;
    auto subNumbersResult = nextParsedCoord->second - currParsedCoord->second;
    auto diagTurn = abs(subLettersResult) == abs(subNumbersResult);

    auto isLettersEqual = nextParsedCoord->first == currParsedCoord->first;
    auto isNumberEqual = nextParsedCoord->second == currParsedCoord->second;
    auto directTurn =  nextParsedCoord->first == currParsedCoord->first ||
        nextParsedCoord->second == currParsedCoord->second;

    if (diagTurn || directTurn) 
    {
        return true;
    }
    else
    {
        return false;
    }
}