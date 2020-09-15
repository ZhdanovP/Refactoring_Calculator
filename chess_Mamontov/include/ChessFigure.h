#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <cmath>

class Position
{

public:	
   static const char leftHorisontalEdge = 'A';
   static const char rightHorisontalEdge = 'H';

   static const char bottomVerticalEdge = '1';
   static const char topVerticalEdge = '8';

   
   Position(char horisontalValue, char verticalValue):
   m_Horisontal(horisontalValue),
   m_Vertical(verticalValue){}; 
       
  const char m_Horisontal;
  const char m_Vertical; 

    bool outsideEdges(){

    return	!(m_Horisontal >= leftHorisontalEdge && 
            m_Horisontal <= rightHorisontalEdge && 
            m_Vertical >= bottomVerticalEdge &&  
            m_Vertical <= topVerticalEdge);
   }    

    char getVerticalDistance(const Position & nextCoord){
    	return  abs(m_Vertical - nextCoord.m_Vertical);
    }
    char getHorisontalDistance(const Position & nextCoord){
        return  abs(m_Horisontal - nextCoord.m_Horisontal);  
    }

};


#include <string>
class ChessFigure
{
	
public:
	ChessFigure(std::string coord);
    bool Move(std::string nextCoord);

protected:
	virtual bool makeMove(const Position & nextCoord)=0;
	Position currentPosition;
};


class Rook : public ChessFigure
{

  public:
	Rook(std::string coord):ChessFigure(coord){};
    bool makeMove(const Position & nextCoord);
  
};

class Knight : public ChessFigure
{

  public:
	Knight(std::string coord):ChessFigure(coord){};
    bool makeMove(const Position & nextCoord);
  
};

class Bishop : public ChessFigure
{

  public:
	Bishop(std::string coord):ChessFigure(coord){};
    bool makeMove(const Position & nextCoord);
  
};

class Pawn : public ChessFigure
{

  public:
	Pawn(std::string coord):ChessFigure(coord){};
    bool makeMove(const Position & nextCoord);
  
};


class King : public ChessFigure
{

  public:
	King(std::string coord):ChessFigure(coord){};
    bool makeMove(const Position & nextCoord);
  
};

class Queen : public ChessFigure
{

  public:
	Queen(std::string coord):ChessFigure(coord){};
    bool makeMove(const Position & nextCoord);
  
};

#endif