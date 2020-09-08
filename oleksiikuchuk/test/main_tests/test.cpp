#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>
#include <stdexcept>

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
 	EXPECT_THROW(c.Add("42,"), std::invalid_argument);
}

TEST(CalculatorTest, EmptyFirstArg) {
	StringCalc c;
 	EXPECT_THROW(c.Add(",42"), std::invalid_argument);
}

TEST(CalculatorTest, EmptyString) {
  StringCalc c;
  int res = c.Add("");
  EXPECT_EQ(res, 0);
}

TEST(CalculatorTest, InvalidString) {
  StringCalc c;
 	EXPECT_THROW(c.Add("s"), std::invalid_argument);
}

TEST(CalculatorTest, NegativeArgument) {
	StringCalc c;
 	EXPECT_THROW(c.Add("42,"), std::invalid_argument);
}


TEST(CalculatorTest, NegativeArguments) {
	StringCalc c;
 	EXPECT_THROW(c.Add("42,"), std::invalid_argument);
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

TEST(CalculatorTest, CustomSeparators) {
  StringCalc c;
 	int res = c.Add("//;\n5;15");
  EXPECT_EQ(res, 20);
}

TEST(CalculatorTest, NotSpecifiedSeparator) {
  StringCalc c;
 	EXPECT_THROW(c.Add("5;15"), std::invalid_argument);
}

TEST(CalculatorTest, NotSpecifiedSeparatorButSPecifiedPrefix) {
  StringCalc c;
  EXPECT_THROW(c.Add("//,5;15"), std::invalid_argument);
}

TEST(CalculatorTest, SeparatorListNotTerminated) {
  StringCalc c;
  EXPECT_THROW(c.Add("//;5;15"), std::invalid_argument);
}

TEST(CalculatorTest, IgnoreGt1000) {
	StringCalc c;
 	int res = c.Add("1001,15");
  EXPECT_EQ(res, 15);
}

TEST(CalculatorTest, IgnoreGt1000Case2) {
	StringCalc c;
 	int res = c.Add("15,1001");
  EXPECT_EQ(res, 15);
}

TEST(CalculatorTest, IgnoreGt1000Case3) {
	StringCalc c;
 	int res = c.Add("1001,1001,1001");
  EXPECT_EQ(res, 0);
}
