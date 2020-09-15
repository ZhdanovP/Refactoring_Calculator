#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP


#include <string>
class ChessFigure
{
	
public:
	ChessFigure(std::string coord);
 	virtual bool Move(std::string nextCoord)=0;
protected:
	std::string currentCoord;
};


class Rook : public ChessFigure
{

  public:
	Rook(std::string coord):ChessFigure(coord){};
    bool Move(std::string nextCoord);
  
};

class Knight : public ChessFigure
{

  public:
	Knight(std::string coord):ChessFigure(coord){};
    bool Move(std::string nextCoord);
  
};

class Bishop : public ChessFigure
{

  public:
	Bishop(std::string coord):ChessFigure(coord){};
    bool Move(std::string nextCoord);
  
};

class Pawn : public ChessFigure
{

  public:
	Pawn(std::string coord):ChessFigure(coord){};
    bool Move(std::string nextCoord);
  
};


class King : public ChessFigure
{

  public:
	King(std::string coord):ChessFigure(coord){};
    bool Move(std::string nextCoord);
  
};

class Queen : public ChessFigure
{

  public:
	Queen(std::string coord):ChessFigure(coord){};
    bool Move(std::string nextCoord);
  
};

#endif