#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, OneArg) {
	StringCalc c;
 	int res = c.Add("42");
  EXPECT_EQ(res, 42);
}

TEST(CalculatorTest, TwoArg) {
	StringCalc c;
 	int res = c.Add("2,2");
  EXPECT_EQ(res, 4);
}

TEST(CalculatorTest, EmptySecondArg) {
	StringCalc c;
 	int res = c.Add("42,");
  EXPECT_EQ(res, -1);
}

TEST(CalculatorTest, EmptyFirstArg) {
	StringCalc c;
 	int res = c.Add(",42");
  EXPECT_EQ(res, -1);
}

TEST(CalculatorTest, EmptyString) {
  StringCalc c;
  int res = c.Add("");
  EXPECT_EQ(res, 0);
}

TEST(CalculatorTest, InvalidString) {
  StringCalc c;
  int res = c.Add("a");
  EXPECT_EQ(res, -1);
}

TEST(CalculatorTest, NegativeArgument) {
	StringCalc c;
 	int res = c.Add("-5");
  EXPECT_EQ(res, -1);
}


TEST(CalculatorTest, NegativeArguments) {
	StringCalc c;
 	int res = c.Add("-5,-5");
  EXPECT_EQ(res, -1);
}

TEST(CalculatorTest, ZeroArg) {
	StringCalc c;
 	int res = c.Add("0");
  EXPECT_EQ(res, 0);
}

TEST(CalculatorTest, OneOfZeroArg) {
	StringCalc c;
 	int res = c.Add("0, 42");
  EXPECT_EQ(res, 42);
}

TEST(CalculatorTest, TwoZeroArg) {
	StringCalc c;
 	int res = c.Add("0, 0");
  EXPECT_EQ(res, 0);
}

TEST(CalculatorTest, Commutativity) {
	StringCalc c;
 	int res1 = c.Add("5, 10");
  int res2 = c.Add("10, 5");
  EXPECT_EQ(res1, res2);
}

TEST(CalculatorTest, ThreeArg) {
  StringCalc c;
 	int res = c.Add("5, 10, 15");
  EXPECT_EQ(res, 30);
}

TEST(CalculatorTest, EolAsSeparator) {
  StringCalc c;
 	int res = c.Add("5\n10");
  EXPECT_EQ(res, 15);
}

TEST(CalculatorTest, EolAndCommaSeparatorMixed) {
  StringCalc c;
 	int res = c.Add("5\n10,15");
  EXPECT_EQ(res, 30);
}
