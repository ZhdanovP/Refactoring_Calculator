#include "gtest/gtest.h"
#include "string_calc.hpp"

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest) {
  StringCalc c;
  int actual = c.Add("2,2");
  ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, EmptyStringTest) {
  StringCalc c;
  int actual = c.Add("");
  ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, ZeroTest) {
  StringCalc c;
  int actual = c.Add("0");
  ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, OneOperandTest) {
  StringCalc c;
  int actual = c.Add("1");
  ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, SymbolTest) {
  StringCalc c;
  int actual = c.Add("cdfgdg");
  ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, NegativeNumberTest) {
  StringCalc c;
  int actual = c.Add("-10");
  ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SymbolTest2) {
  StringCalc c;
  int actual = c.Add("cdfgdg,sdfsfd");
  ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, MultipleNumbers) {
  StringCalc c;
  int actual = c.Add("2,2,2,2,2,2");
  ASSERT_EQ(actual, 12);
}

TEST(CalculatorTest, FloatNumbersTest) {
  StringCalc c;
  int actual = c.Add("2.5,2.5");
  ASSERT_EQ(actual, 4);
}
