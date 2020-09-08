#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest) 
{
 	StringCalc calc;
 	int actual = calc.Add("2,2");
 	ASSERT_EQ(actual, 4);
}

// -------1-------

TEST(CalculatorTest, EmptyStringTest)
{
  StringCalc calc;
  int actual = calc.Add("");
  ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, OneOperandTest)
{
  StringCalc calc;
  int actual = calc.Add("3");
  ASSERT_EQ(actual, 3);
}

// -------5-------

TEST(CalculatorTest, NegativeOperandTest)
{
  StringCalc calc;
  ASSERT_THROW(calc.Add("-2,5"), std::invalid_argument);
}

TEST(CalculatorTest, SymbolicOperandTest)
{
  StringCalc calc;
  ASSERT_THROW(calc.Add("a,5"), std::invalid_argument);
}

TEST(CalculatorTest, NegativeAndSymbolicOperandsTest)
{
  StringCalc calc;
  ASSERT_THROW(calc.Add("1,3,-1,b"), std::invalid_argument);
}

// -------2-------

TEST(CalculatorTest, ThreeOperandTest)
{
  StringCalc calc;
  int actual = calc.Add("4,5,7");
  ASSERT_EQ(actual, 16);
}

TEST(CalculatorTest, SevenOperandTest)
{
  StringCalc calc;
  int actual = calc.Add("4,5,7,10,15,27,34");
  ASSERT_EQ(actual, 102);
}

// -------3-------

TEST(CalculatorTest, EndLineDelimeterTest)
{
  StringCalc calc;
  int actual = calc.Add("2\n3");
  ASSERT_EQ(actual, 5);
}

TEST(CalculatorTest, EndLineAndCommaDelimetersTest)
{
  StringCalc calc;
  int actual = calc.Add("2\n3,4\n5\n6");
  ASSERT_EQ(actual, 20);
}

// -------4-------

TEST(CalculatorTest, PercentDelimeterTest)
{
  StringCalc calc;
  int actual = calc.Add("//,%\n20%3");
  ASSERT_EQ(actual, 23);
}

TEST(CalculatorTest, PercentAndSemicolonAndCommaDelimeterTest)
{
  StringCalc calc;
  int actual = calc.Add("//,%;\n20%3;4,1");
  ASSERT_EQ(actual, 28);
}

TEST(CalculatorTest, SymbolicAndSlashDelimeterTest)
{
  StringCalc calc;
  int actual = calc.Add("///b\n20b3/4b1");
  ASSERT_EQ(actual, 28);
}

TEST(CalculatorTest, UsingUndefinedDelimeterTest)
{
  StringCalc calc;
  ASSERT_THROW(calc.Add("//;\n4,1"), std::invalid_argument);
}

// -------6-------

TEST(CalculatorTest, OverrangeNumberTest)
{
  StringCalc calc;
  int actual = calc.Add("1001,5");
  ASSERT_EQ(actual, 5);
}

TEST(CalculatorTest, PreOverrangeNumberTest)
{
  StringCalc calc;
  int actual = calc.Add("1000,1");
  ASSERT_EQ(actual, 1001);
}

TEST(CalculatorTest, OverrangeSumTest)
{
  StringCalc calc;
  int actual = calc.Add("//;\n1000;1;10");
  ASSERT_EQ(actual, 1011);
}

// -------7-------

TEST(CalculatorTest, ThreeDotsDelimeterTest)
{
  StringCalc calc;
  int actual = calc.Add("//[...]\n20...3...1");
  ASSERT_EQ(actual, 24);
}

TEST(CalculatorTest, TwoCommasAndThreeDotsDelimeterTest)
{
  StringCalc calc;
  int actual = calc.Add("//[...][,,]\n20...3,,5");
  ASSERT_EQ(actual, 28);
}

TEST(CalculatorTest, RepeatDelimeterTest)
{
  StringCalc calc;
  ASSERT_THROW(calc.Add("//[...].\n20...3.3"), std::invalid_argument);
}

TEST(CalculatorTest, DelimeterListWitnEndLineDelimeterTest)
{
  StringCalc calc;
  int actual = calc.Add("//\n,\n20\n1");
  ASSERT_EQ(actual, 21);
}

TEST(CalculatorTest, MissEndOfDelimitersListTest)
{
  StringCalc calc;
  ASSERT_THROW(calc.Add("//,;2\n2;3,3"), std::invalid_argument);
}



/*TEST(CalculatorTest, InvalidNegativeOperandTest)
{
  StringCalc calc;
  int actual = calc.Add("-3,5");
  ASSERT_EQ(actual, -1);
}*/


