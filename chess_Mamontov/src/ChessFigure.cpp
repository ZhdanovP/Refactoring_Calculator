#include "ChessFigure.h"
#include <string>

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


bool Rook::makeMove(const Position &nextPosition){
         
    bool horisontalPositionChanged  = currentPosition.getHorisontalDistance(nextPosition);
    bool verticalPositionChanged  =  currentPosition.getVerticalDistance(nextPosition);
  
    return horisontalPositionChanged != verticalPositionChanged;
}


bool Pawn::makeMove(const Position &nextPosition){

	bool horisontalPositionIsChanged  =   nextPosition.m_Horisontal != currentPosition.m_Horisontal;  

	if (horisontalPositionIsChanged)
		                  return false;
	
    char verticalPositionChanged  =  nextPosition.m_Vertical - currentPosition.m_Vertical;

	bool notMoreThanTwoStepsForwardVertical  =  verticalPositionChanged   <= 2;
	bool notLessThanOneStepsForwardVertical =  verticalPositionChanged   >= 1 ;
	
	return  notMoreThanTwoStepsForwardVertical && notLessThanOneStepsForwardVertical;  
}

bool Bishop::makeMove(const Position &nextPosition){

    char horisontalPositionChange  =  currentPosition.getHorisontalDistance(nextPosition);
    char verticalPositionChange  =  currentPosition.getVerticalDistance(nextPosition);

    bool isDiagonalMove =  horisontalPositionChange ==  verticalPositionChange;

    return isDiagonalMove; 
}

bool King::makeMove(const Position &nextPosition){

	
	bool  notMoreThanOneVerticalStep  =  currentPosition.getVerticalDistance(nextPosition) <= 1;
	bool  notMoreThanOneHorisontalStep  =  currentPosition.getHorisontalDistance(nextPosition) <= 1;  

    return  notMoreThanOneHorisontalStep && notMoreThanOneVerticalStep;		
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


bool Queen::makeMove(const Position &nextPosition){

			if (!(abs(nextPosition.m_Horisontal - currentPosition.m_Horisontal) == abs(nextPosition.m_Vertical - currentPosition.m_Vertical) || nextPosition.m_Horisontal == currentPosition.m_Horisontal || nextPosition.m_Vertical == currentPosition.m_Vertical))
				return false;
			else
	            return true;   
}	