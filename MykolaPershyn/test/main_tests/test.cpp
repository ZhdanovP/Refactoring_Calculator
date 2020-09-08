#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest) {
  StringCalc c;
  int actual = c.Add("2,2");
  ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, EmptyString) {
  StringCalc c;
  int actual = c.Add("0");
  ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, Zero) {
  StringCalc c;
  int actual = c.Add("0");
  ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SingleNumber) {
  StringCalc c;
  int actual = c.Add("1");
  ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, SimpleSum) {
  StringCalc c;
  int actual = c.Add("1,2");
  ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, WrongArgSign) {
  StringCalc c;
  int actual = c.Add("-1,-1");
  ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, WrongArgLetters) {
  StringCalc c;
  int actual = c.Add("0abc1");
  ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SeparatorComa) {
  StringCalc c;
  int actual = c.Add("1,2");
  ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, SeparatorSpace) {
  StringCalc c;
  int actual = c.Add("1,2");
  ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, SeparatorNewLine) {
  StringCalc c;
  int actual = c.Add("1\n2");
  ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, DifferentSeparators) {
  StringCalc c;
  int actual = c.Add("1,2 3\n4");
  ASSERT_EQ(actual, 10);
}
