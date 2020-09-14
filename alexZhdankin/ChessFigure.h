#pragma once

#include <string>

class ChessFigure
{
	
public:
	ChessFigure(std::string coord);
	virtual ~ChessFigure();

	virtual bool Move(std::string nextCoord) = 0;
	std::string getCurrentPos() const { return currentCoord; }

private:
	std::string currentCoord;
};