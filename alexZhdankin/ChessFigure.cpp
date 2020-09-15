#include "ChessFigure.h"
#include <string>
#include <cmath>

namespace
{
	bool areValidSymbols(char letter, char number)
	{
		return isalpha(letter) && isdigit(number);
	}

	bool areValidRanges(char letter, char number)
	{
		return (letter >= 'A' && letter <= 'H') &&
				(number >= '1' && number <= '8');
	}
}

ChessFigure::ChessFigure(std::string coord) : currentCoord(coord)
{}

ChessFigure::~ChessFigure()
{}

std::optional<std::pair<char, unsigned short>> ChessFigure::getParsedCoords(std::string coords)
{
	char letter = coords[0];
    char number = coords[1];
    if (areValidSymbols(letter, number))
    {
        if (areValidRanges(letter, number))
        {
            return std::make_pair(letter, number);
        }
    }
    return std::nullopt;
}