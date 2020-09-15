#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>
class ChessFigure
{
	
public:
	enum FigureType
	{
		ROOK,
		KNIGHT,
		BISHOP,
		PAWN,
		KING,
		QUEEN
	};

	struct Coordinate
	{
		Coordinate(std::string coord):
			x(coord[0]),
			y(coord[1])
		{}
		char x;
		char y;
	};

	ChessFigure(FigureType type,std::string coord);
	virtual bool Move(std::string nextCoord);
	virtual ~ChessFigure();

protected:

	bool checkFieldCoordinates(Coordinate coordinate);
	bool MoveImpl(Coordinate nextCoord);

private:
	FigureType type;
	Coordinate currentCoord;
	const char X_MIN = 'A';
	const char X_MAX = 'H';
	const char Y_MIN = '1';
	const char Y_MAX = '8';
};

#endif