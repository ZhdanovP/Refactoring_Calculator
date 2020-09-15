#pragma once

#include <string>
#include <optional>

class ChessFigure
{
	
public:
	ChessFigure(std::string coord);
	virtual ~ChessFigure();

	virtual bool Move(std::string nextCoord) = 0;
	std::string getCurrentPos() const { return currentCoord; }

	static std::optional<std::pair<char, unsigned short>> getParsedCoords(std::string);

private:
	std::string currentCoord;
};