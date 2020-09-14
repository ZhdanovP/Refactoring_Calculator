#pragma once

#include "ChessFigure.h"

class KnightFigure : public ChessFigure
{
    KnightFigure(std::string coord);
    bool Move(std::string nextCoord) override;
};