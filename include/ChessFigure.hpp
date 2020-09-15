#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>
class ChessFigure {
 public:
  ChessFigure(std::string coord);
  bool Move(std::string nextCoord);

  virtual ~ChessFigure();

 protected:
  bool isCoordinatesValid(std::string nextCoord);
  virtual bool allowMovement(std::string nextCoord) = 0;
  std::string currentCoord;
  int horizontalCoordDist;
  int verticalCoordDist;
};

#endif
