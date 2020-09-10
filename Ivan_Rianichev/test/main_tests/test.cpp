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
  EXPECT_THROW({ c.Add("cdfgdg"); }, std::invalid_argument);
}

TEST(CalculatorTest, NegativeNumberTest) {
  StringCalc c;
  EXPECT_THROW({ c.Add("-10"); }, std::invalid_argument);
}

TEST(CalculatorTest, SymbolTest2) {
  StringCalc c;
  EXPECT_THROW({ c.Add("cdfgdg,sdfsfd"); }, std::invalid_argument);
}

TEST(CalculatorTest, MultipleNumbers) {
  StringCalc c;
  int actual = c.Add("2,2,2,2,2,2");
  ASSERT_EQ(actual, 12);
}

TEST(CalculatorTest, FloatNumbersTest) {
  StringCalc c;
  EXPECT_THROW({ c.Add("2.5,2.5"); }, std::invalid_argument);
}

TEST(CalculatorTest, TestForNewLineDelimiter) {
  StringCalc c;
  int actual = c.Add("2\n5");
  ASSERT_EQ(actual, 7);
}

TEST(CalculatorTest, TestForNewLineDelimiter2) {
  StringCalc c;
  int actual = c.Add("20\n5,2");
  ASSERT_EQ(actual, 27);
}

TEST(CalculatorTest, OperandsOver1000Ignored) {
  StringCalc c;
  int actual = c.Add("1001,2");
  ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, CustomOperandDelimiter) {
  StringCalc c;
  int actual = c.Add("//;\n1;2");
  ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, CustomOperandDelimiter2) {
  StringCalc c;
  int actual = c.Add("//;\n1;2,3\n4");
  ASSERT_EQ(actual, 10);
}
