#pragma once

#include "ChessFigure.h"

class KingFigure : public ChessFigure
{
    public:
        KingFigure(std::string coord);
        bool Move(std::string nextCoord) override;
};