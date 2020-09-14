#include "PawnFigure.h"

PawnFigure::PawnFigure(std::string coord) : ChessFigure(coord)
{}

bool PawnFigure::Move(std::string nextCoord)
{
    auto currFigureCoord = getCurrentPos();
    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
    {
        if (nextCoord[0] != currFigureCoord[0] || nextCoord[1] <= currFigureCoord[1] || (nextCoord[1] - currFigureCoord[1] != 1 && (currFigureCoord[1] != '2' || nextCoord[1] != '4')))
            return false;
        else
            return true;
    }
    else return false;
}