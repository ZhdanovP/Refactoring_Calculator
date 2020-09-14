#include "KnightFigure.h"

KnightFigure::KnightFigure(std::string coord) : ChessFigure(coord)
{}

bool KnightFigure::Move(std::string nextCoord)
{
    auto currFigureCoord = getCurrentPos();
    if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
    {
        int dx, dy;
        dx = abs(nextCoord[0] - currFigureCoord[0]);
        dy = abs(nextCoord[1] - currFigureCoord[1]);
        if (!(abs(nextCoord[0] - currFigureCoord[0]) == 1 && abs(nextCoord[1] - currFigureCoord[1]) == 2 || abs(nextCoord[0] - currFigureCoord[0]) == 2 && abs(nextCoord[1] - currFigureCoord[1]) == 1))
            return false;
        else
        return true;
    }
    else return false;
}