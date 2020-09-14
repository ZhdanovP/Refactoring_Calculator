#pragma once

#include "ChessFigure.h"

class KingFigure : public ChessFigure
{
    KingFigure(std::string coord);
    bool Move(std::string nextCoord) override;
};