#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>
class ChessFigure
{
public:
	ChessFigure(std::string coord);
	virtual bool Move(const std::string& nextCoord) const = 0;
	virtual ~ChessFigure();
protected:
	bool checkCoords(const std::string& nextCoord) const;
	std::string currentCoord;
};

class Pawn : public ChessFigure
{
	
public:
	Pawn(std::string coord) : ChessFigure(coord) {}
	bool Move(const std::string& nextCoord) const override;

private:
};

class Rook : public ChessFigure
{
	
public:
	Rook(std::string coord) : ChessFigure(coord) {}
	bool Move(const std::string& nextCoord) const override;

private:
};

class Knight : public ChessFigure
{
	
public:
	Knight(std::string coord) : ChessFigure(coord) {}
	bool Move(const std::string& nextCoord) const override;

private:
};

class Bishop : public ChessFigure
{
	
public:
	Bishop(std::string coord) : ChessFigure(coord) {}
	bool Move(const std::string& nextCoord) const override;

private:
};

class King : public ChessFigure
{
	
public:
	King(std::string coord) : ChessFigure(coord) {}
	bool Move(const std::string& nextCoord) const override;

private:
};

class Queen : public ChessFigure
{
	
public:
	Queen(std::string coord) : ChessFigure(coord) {}
	bool Move(const std::string& nextCoord) const override;

private:
};


#endif
