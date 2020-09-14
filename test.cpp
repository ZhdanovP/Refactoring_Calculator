#include "ChessFigure.h"
#include <gtest/gtest.h>

TEST(LAB2, IncorrectCoord) {
  auto *figure = new Pawn("E2");
  EXPECT_THROW(figure->Move("i9"), std::invalid_argument);
}

TEST(LAB2, RookShouldBeCorrectMove) {
  auto *figure = new Rook("E2");
  EXPECT_TRUE(figure->Move("C2"));
}

TEST(LAB2, RookShouldBeIncorrectMove) {
  auto *figure = new Rook("E2");
  EXPECT_FALSE(figure->Move("C5"));
}

TEST(LAB2, KnightShouldBeCorrectMove) {
  auto *figure = new Knight("B1");
  EXPECT_TRUE(figure->Move("C3"));
}

TEST(LAB2, KnightShouldBeIncorrectMove) {
  auto *figure = new Knight("B1");
  EXPECT_FALSE(figure->Move("C5"));
}

TEST(LAB2, BishopShouldBeCorrectMove) {
  auto *figure = new Bishop("C1");
  EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, BishopShouldBeIncorrectMove) {
  auto *figure = new Bishop("C1");
  EXPECT_FALSE(figure->Move("C3"));
}

TEST(LAB2, PawnShouldBeCorrectMove0) {
  auto *figure = new Pawn("E2");
  EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, PawnShouldBeCorrectMove1) {
  auto *figure = new Pawn("E2");
  EXPECT_TRUE(figure->Move("E4"));
}

TEST(LAB2, PawnShouldBeCorrectMove2) {
  auto *figure = new Pawn("E4");
  EXPECT_TRUE(figure->Move("E5"));
}

TEST(LAB2, PawnShouldBeIncorrectMove) {
  auto *figure = new Pawn("E2");
  EXPECT_FALSE(figure->Move("C5"));
}

TEST(LAB2, KingShouldBeCorrectMove) {
  auto *figure = new King("E1");
  EXPECT_TRUE(figure->Move("E2"));
}

TEST(LAB2, KingShouldBeIncorrectMove) {
  auto *figure = new King("E1");
  EXPECT_FALSE(figure->Move("E8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveVertical) {
  auto *figure = new Queen("D1");
  EXPECT_TRUE(figure->Move("D8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveDiagonal) {
  auto *figure = new Queen("D1");
  EXPECT_TRUE(figure->Move("H5"));
}

TEST(LAB2, QueenShouldBeIncorrectMove) {
  auto *figure = new Queen("D1");
  EXPECT_FALSE(figure->Move("E3"));
}
