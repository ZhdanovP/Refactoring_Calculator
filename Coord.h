#pragma once

#include <cmath>
#include <stdexcept>

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

bool SameDigit(const Coord &c1, const Coord &c2) {
  return c1.digit_ == c2.digit_;
}

bool SameLetter(const Coord &c1, const Coord &c2) {
  return c1.letter_ == c2.letter_;
}

bool SameLine(const Coord &c1, const Coord &c2) {
  return SameDigit(c1, c2) || SameLetter(c1, c2);
}

bool SameDiag(const Coord &c1, const Coord &c2) {
  return abs(c1.letter_ - c2.letter_) == abs(c1.digit_ - c2.digit_);
}

int AbsMaxDistance(const Coord &c1, const Coord &c2) {
  return std::max(abs(c1.DigitDistance(c2)), abs(c1.LetterDistance(c2)));
}

int AbsDistanceSquared(const Coord &c1, const Coord &c2) {
  auto dx = c1.DigitDistance(c2);
  auto dy = c1.LetterDistance(c2);
  return dx * dx + dy * dy;
}
