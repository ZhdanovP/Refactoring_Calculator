#pragma once

#include "ChessFigure.h"

class BishopFigure : public ChessFigure
{
    public:
        BishopFigure(std::string coord);
        bool Move(std::string nextCoord) override;
};