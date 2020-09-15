#pragma once

#include "ChessFigure.h"

class RookFigure : public ChessFigure
{
    public:
        RookFigure(std::string coord);
        bool Move(std::string nextCoord) override;
};