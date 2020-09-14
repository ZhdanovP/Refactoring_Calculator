#pragma once

#include "ChessFigure.h"

class QueenFigure : public ChessFigure
{
    QueenFigure(std::string coord);
    bool Move(std::string nextCoord) override;
};