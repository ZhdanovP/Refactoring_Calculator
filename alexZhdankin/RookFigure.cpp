#include "RookFigure.h"

RookFigure::RookFigure(std::string coord) : ChessFigure(coord)
{}

bool RookFigure::Move(std::string nextCoord)
{
    auto currFigureCoord = getCurrentPos();
    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
    {
        if ((nextCoord[0] != currFigureCoord[0]) && (nextCoord[1] != currFigureCoord[1]) || ((nextCoord[0] == currFigureCoord[0]) && (nextCoord[1] == currFigureCoord[1])))
            return false;
        else
            return true;
    }
    else return false;
}