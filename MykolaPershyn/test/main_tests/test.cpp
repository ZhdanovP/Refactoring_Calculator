#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>
#include <stdexcept>

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
  int actual = c.Add("");
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

TEST(CalculatorTest, InvalidArgument) {
  StringCalc c;
  int actual;
  try {
    actual = c.Add("abc");
    throw(std::invalid_argument("The argument is valid..."));
  }
  catch (const std::invalid_argument& e) {   
    ASSERT_EQ(e.what(), std::string("abc"));
  }
  catch(...) {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST(CalculatorTest, WrongArgSign) {
  StringCalc c;
  int actual;
  try {
    actual = c.Add("-1,-1");
    throw(std::invalid_argument("The argument is valid..."));
  }
  catch (const std::invalid_argument& e) {   
    ASSERT_EQ(e.what(), std::string("-1,-1"));
  }
  catch(...) {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST(CalculatorTest, WrongArgLetters) {
  StringCalc c;
  int actual;
  try {
    actual = c.Add("0abc1");
    throw(std::invalid_argument("The argument is valid..."));
  }
  catch (const std::invalid_argument& e) {   
    ASSERT_EQ(e.what(), std::string("0abc1"));
  }
  catch(...) {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST(CalculatorTest, MultiArg) {
  StringCalc c;
  int actual = c.Add("1,2,3,4");
  ASSERT_EQ(actual, 10);
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

TEST(CalculatorTest, GeneralisedSeparators) {
  StringCalc c;
  int actual = c.Add("//;\n1;2");
  ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, ArbitratyLengthSeparators) {
  StringCalc c;
  int actual = c.Add("//[***]\n***2***3");
  ASSERT_EQ(actual, 5);
}
