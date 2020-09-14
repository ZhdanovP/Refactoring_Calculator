#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <stdexcept>
#include <utility>

struct Coord {
  Coord(char letter, char digit) : letter_{letter}, digit_{digit} {
    if (letter_ < 'A' || letter_ > 'H')
      throw std::invalid_argument{
          "Letter part of coordinate must be in A-H range"};
    if (digit_ < '1' || digit_ > '8')
      throw std::invalid_argument{
          "Digit part of coordinate must be in 1-8 range"};
  }

  Coord(const char coords[2]) : Coord(coords[0], coords[1]) {}

  int LetterDistance(const Coord &other) const {
    return other.letter_ - letter_;
  }

  int DigitDistance(const Coord &other) const { return other.digit_ - digit_; }

  char Digit() const { return digit_; }
  char Letter() const { return letter_; }

  friend bool SameLetter(const Coord &c1, const Coord &c2);
  friend bool SameDigit(const Coord &c1, const Coord &c2);
  friend bool SameDiag(const Coord &c1, const Coord &c2);

private:
  char letter_;
  char digit_;
};

class ChessFigure {
public:
  virtual bool Move(Coord nextCoord) const = 0;
  virtual ~ChessFigure() {}
};

class RealChessFigure {
public:
  virtual ~RealChessFigure() {}
  RealChessFigure(Coord coord) : currentCoord(std::move(coord)) {}

protected:
  Coord currentCoord;
};

class Pawn : public ChessFigure, protected RealChessFigure {
public:
  Pawn(Coord coord) : RealChessFigure(coord) {}

  bool Move(Coord nextCoord) const override;
};

class Bishop : public ChessFigure, protected RealChessFigure {
public:
  Bishop(Coord coord) : RealChessFigure(coord) {}

  bool Move(Coord nextCoord) const override;
};

class Knight : public ChessFigure, protected RealChessFigure {
public:
  Knight(Coord coord) : RealChessFigure(coord) {}

  bool Move(Coord nextCoord) const override;
};

class Rook : public ChessFigure, protected RealChessFigure {
public:
  Rook(Coord coord) : RealChessFigure(coord) {}

  bool Move(Coord nextCoord) const override;
};

class King : public ChessFigure, protected RealChessFigure {
public:
  King(Coord coord) : RealChessFigure(coord) {}

  bool Move(Coord nextCoord) const override;
};

class Queen : public ChessFigure, protected RealChessFigure {
public:
  Queen(Coord coord) : RealChessFigure(coord) {}

  bool Move(Coord nextCoord) const override;
};

#endif
