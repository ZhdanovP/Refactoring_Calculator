#include "ChessFigure.hpp"
#include <gtest/gtest.h>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(LAB2, RookShouldBeCorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Rook("E2")};
	EXPECT_TRUE(figure->Move("C2"));
}

TEST(LAB2, RookShouldBeIncorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Rook("E2")};
	EXPECT_FALSE(figure->Move("C5"));
}
TEST(LAB2, KnightShouldBeCorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Knight("B1")};
	EXPECT_TRUE(figure->Move("C3"));
}
TEST(LAB2, KnightShouldBeIncorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Knight("B1")};
	EXPECT_FALSE(figure->Move("C5"));
}

TEST(LAB2, BishopShouldBeCorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Bishop("C1")};
	EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, BishopShouldBeIncorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Bishop("C1")};
	EXPECT_FALSE(figure->Move("C3"));
}
TEST(LAB2, PawnShouldBeCorrectMove0)
{
	std::unique_ptr<ChessFigure> figure{new Pawn("E2")};
	EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, PawnShouldBeCorrectMove1)
{
	std::unique_ptr<ChessFigure> figure{new Pawn("E2")};
	EXPECT_TRUE(figure->Move("E4"));
}

TEST(LAB2, PawnShouldBeCorrectMove2)
{
	std::unique_ptr<ChessFigure> figure{new Pawn("E4")};
	EXPECT_TRUE(figure->Move("E5"));
}

TEST(LAB2, PawnShouldBeIncorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Pawn("E2")};
	EXPECT_FALSE(figure->Move("C5"));
}
TEST(LAB2, KingShouldBeCorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new King("E1")};
	EXPECT_TRUE(figure->Move("E2"));
}
TEST(LAB2, KingShouldBeIncorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new King("E1")};
	EXPECT_FALSE(figure->Move("E8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveVertical)
{
	std::unique_ptr<ChessFigure> figure{new Queen("D1")};
	EXPECT_TRUE(figure->Move("D8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveDiagonal)
{
	std::unique_ptr<ChessFigure> figure{new Queen("D1")};
	EXPECT_TRUE(figure->Move("H5"));
}

TEST(LAB2, QueenShouldBeIncorrectMove)
{
	std::unique_ptr<ChessFigure> figure{new Queen("D1")};
	EXPECT_FALSE(figure->Move("E3"));
}

TEST(LAB2, PawnCantStay)
{
	std::unique_ptr<ChessFigure> figure{new Pawn("D3")};
	EXPECT_FALSE(figure->Move("D3"));
}

TEST(LAB2, RookCantStay)
{
	std::unique_ptr<ChessFigure> figure{new Rook("D3")};
	EXPECT_FALSE(figure->Move("D3"));
}

TEST(LAB2, BishopCantStay)
{
	std::unique_ptr<ChessFigure> figure{new Bishop("D3")};
	EXPECT_FALSE(figure->Move("D3"));
}

TEST(LAB2, KnightCantStay)
{
	std::unique_ptr<ChessFigure> figure{new Knight("D3")};
	EXPECT_FALSE(figure->Move("D3"));
}

TEST(LAB2, QueenCantStay)
{
	std::unique_ptr<ChessFigure> figure{new Queen("D3")};
	EXPECT_FALSE(figure->Move("D3"));
}

TEST(LAB2, KingCantStay)
{
	std::unique_ptr<ChessFigure> figure{new King("D3")};
	EXPECT_FALSE(figure->Move("D3"));
}

