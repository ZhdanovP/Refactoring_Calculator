#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>
class ChessFigure
{
public:
  ChessFigure(std::string coord);
  bool Move(const std::string& nextCoord) const;
  virtual ~ChessFigure();
protected:
  bool checkCoords(const std::string& nextCoord) const;
  virtual bool peiceSpecificMove(const int dx, const int dy) const = 0;
  std::string currentCoord;
};

class Pawn : public ChessFigure
{
public:
  Pawn(std::string coord) : ChessFigure(coord) {}
protected:
  bool peiceSpecificMove(const int dx, const int dy) const override;
};

class Rook : public ChessFigure
{
public:
  Rook(std::string coord) : ChessFigure(coord) {}
protected:
  bool peiceSpecificMove(const int dx, const int dy) const override;
};

class Knight : public ChessFigure
{
public:
  Knight(std::string coord) : ChessFigure(coord) {}
protected:
  bool peiceSpecificMove(const int dx, const int dy) const override;
};

class Bishop : public ChessFigure
{
public:
  Bishop(std::string coord) : ChessFigure(coord) {}
protected:
  bool peiceSpecificMove(const int dx, const int dy) const override;
};

class King : public ChessFigure
{
public:
  King(std::string coord) : ChessFigure(coord) {}
protected:
  bool peiceSpecificMove(const int dx, const int dy) const override;
};

class Queen : public ChessFigure
{
public:
  Queen(std::string coord) : ChessFigure(coord) {}
protected:
  bool peiceSpecificMove(const int dx, const int dy) const override;
};

#endif
