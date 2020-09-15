#include "ChessFigure.h"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(std::string coord) :
currentPosition(coord[0],coord[1]){
}

bool ChessFigure::Move( string nextCoord )
{
     Position nextPosition(nextCoord[0],nextCoord[1]);

     if(nextPosition.outsideEdges())
     	     return false;

     return makeMove(nextPosition); 	 
}

bool Pawn::makeMove(const Position &nextPosition){

	    
	if (nextPosition.m_Horisontal != currentPosition.m_Horisontal || nextPosition.m_Vertical <= currentPosition.m_Vertical || (nextPosition.m_Vertical - currentPosition.m_Vertical != 1 && (currentPosition.m_Vertical != '2' || nextPosition.m_Vertical != '4')))
				return false;
			else
				return true;
	
}

bool Rook::makeMove(const Position &nextPosition){

			if ((nextPosition.m_Horisontal != currentPosition.m_Horisontal) && (nextPosition.m_Vertical != currentPosition.m_Vertical) || ((nextPosition.m_Horisontal == currentPosition.m_Horisontal) && (nextPosition.m_Vertical == currentPosition.m_Vertical)))
				return false;
			else
				return true;

}

bool Knight::makeMove(const Position &nextPosition){
    
    
			int dx, dy;
			dx = abs(nextPosition.m_Horisontal - currentPosition.m_Horisontal);
			dy = abs(nextPosition.m_Vertical - currentPosition.m_Vertical);
		    if (!(abs(nextPosition.m_Horisontal - currentPosition.m_Horisontal) == 1 && abs(nextPosition.m_Vertical - currentPosition.m_Vertical) == 2 || abs(nextPosition.m_Horisontal - currentPosition.m_Horisontal) == 2 && abs(nextPosition.m_Vertical - currentPosition.m_Vertical) == 1))
			  return false;
			else
			return true;
		

}

bool Bishop::makeMove(const Position &nextPosition){

     
			if (!(abs(nextPosition.m_Horisontal - currentPosition.m_Horisontal) == abs(nextPosition.m_Vertical - currentPosition.m_Vertical)))
				return false;
			else
				return true;
		  
}

bool King::makeMove(const Position &nextPosition){

	
			if (!(abs(nextPosition.m_Horisontal - currentPosition.m_Horisontal) <= 1 && abs(nextPosition.m_Vertical - currentPosition.m_Vertical) <= 1))
				return false;
			else
				return true;
		
}

bool Queen::makeMove(const Position &nextPosition){

			if (!(abs(nextPosition.m_Horisontal - currentPosition.m_Horisontal) == abs(nextPosition.m_Vertical - currentPosition.m_Vertical) || nextPosition.m_Horisontal == currentPosition.m_Horisontal || nextPosition.m_Vertical == currentPosition.m_Vertical))
				return false;
			else
	            return true;   
}	