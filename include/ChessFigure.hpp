#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>
class ChessFigure {
 public:
  enum FigureType { ROOK, KNIGHT, BISHOP, PAWN, KING, QUEEN };

  ChessFigure(FigureType type, std::string coord);
  bool Move(std::string nextCoord);
  virtual ~ChessFigure();

 private:
  bool isCoordinatesValid(std::string nextCoord);
  bool pawnMove(std::string nextCoord);
  bool rookMove(std::string nextCoord);
  bool knightMove(std::string nextCoord);
  bool bishopMove(std::string nextCoord);
  bool kingMove(std::string nextCoord);
  bool queenMove(std::string nextCoord);
  FigureType type;
  std::string currentCoord;
  int horizontalCoordDist;
  int verticalCoordDist;
};

#endif
