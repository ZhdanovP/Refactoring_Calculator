#pragma once

#include "ChessFigure.h"

class PawnFigure : public ChessFigure
{
    public:
        PawnFigure(std::string coord);
        bool Move(std::string nextCoord) override;
};
