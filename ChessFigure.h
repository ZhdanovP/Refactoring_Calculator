#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <stdexcept>

struct Coord {
	Coord(char letter, char digit) : letter_{letter}, digit_{digit} {
		if (letter_ < 'A' || letter_ > 'H')
			throw std::invalid_argument{"Letter part of coordinate must be in A-H range"};
		if (digit_ < '1' || digit_ > '8')
			throw std::invalid_argument{"Digit part of coordinate must be in 1-8 range"};
	}

	Coord(const char coords[2]) : Coord(coords[0], coords[1]) {}

	int LetterDistance(const Coord& other) const {
		return other.letter_ - letter_;
	}

	int DigitDistance(const Coord& other) const {
		return other.digit_ - digit_;
	}

	char Digit() { return digit_; }
	char Letter() { return letter_; }

	friend bool SameLetter(const Coord& c1, const Coord& c2);
	friend bool SameDigit(const Coord& c1, const Coord& c2);
	friend bool SameDiag(const Coord& c1, const Coord& c2);

private:
	char letter_;
	char digit_;
};




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
	ChessFigure(FigureType type, Coord coord);
	bool Move(Coord nextCoord);
	virtual ~ChessFigure();
private:
	FigureType type;
	Coord currentCoord;
};

#endif