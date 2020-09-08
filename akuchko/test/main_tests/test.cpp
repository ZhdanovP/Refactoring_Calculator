#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest1) {
	StringCalc c;
	int actual = c.Add("1,2");
	ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, SampleTest2) {
	StringCalc c;
	int actual = c.Add("5,7");
	ASSERT_EQ(actual, 12);
}

TEST(CalculatorTest, EmptyTest) {
	StringCalc c;
	int actual = c.Add("");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, ZeroTest) {
	StringCalc c;
	int actual = c.Add("0");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, FristWrongValueTest) {
	StringCalc c;
	int actual = c.Add("-4,5");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SecondWrongValueTest) {
	StringCalc c;
	int actual = c.Add("4,-5");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, BothWrongValueTest) {
	StringCalc c;
	int actual = c.Add("3,-6");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, WrongDelimeter2ValueTest) {
	StringCalc c;
  EXPECT_THROW(c.Add("3%6"), std::invalid_argument);
}

TEST(CalculatorTest, ThreeValuesTest) {
	StringCalc c;
	int actual = c.Add("3,4,6");
	ASSERT_EQ(actual, 13);
}

TEST(CalculatorTest, FourValuesTest) {
	StringCalc c;
	int actual = c.Add("10,3,4,6");
	ASSERT_EQ(actual, 23);
}

TEST(CalculatorTest, FourValuesWithErrorTest) {
	StringCalc c;
	int actual = c.Add("10,3,-4,6");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, FourZeroValuesTest) {
	StringCalc c;
	int actual = c.Add("0,0,0,0");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, NewDelimeterTest) {
	StringCalc c;
	int actual = c.Add("1,0\n,2");
	ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, NewDelimeter2Test) {
	StringCalc c;
	int actual = c.Add("1\n2");
	ASSERT_EQ(actual, 3);
}

TEST(CalculatorTest, AcceptedDelimetersTest) {
	StringCalc c;
	int actual = c.Add("1;2\n3");
	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, WrongDelimeterThreeArgsTest) {
	StringCalc c;
 EXPECT_THROW(c.Add("1;2%3"), std::invalid_argument);
}

TEST(CalculatorTest, BigNumberTest) {
	StringCalc c;
	int actual = c.Add("1001,2");
	ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, MultipleCharacterDelimeterTest) {
	StringCalc c;
	int actual = c.Add("\n1**2**3");
	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, SecondMultipleCharacterDelimeterTest) {
	StringCalc c;
	int actual = c.Add("//[***]\n1***2***3");
	ASSERT_EQ(actual, 6);
}