#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, two_two) {
  StringCalc c;
  int actual = c.Add("2,2");
  ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, two) {
	StringCalc c;
	int actual = c.Add("2");
	ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, two_three) {
	StringCalc c;
	int actual = c.Add("2,3");
	ASSERT_EQ(actual, 5);
}

TEST(CalculatorTest, zero_num) {
	StringCalc c;
	int actual = c.Add("0");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, empty_string) {
	StringCalc c;
	int actual = c.Add("");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, low_char) {
	StringCalc c;
	int actual = c.Add("a");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, one_letter_capital) {
	StringCalc c;
	int actual = c.Add("A");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, capital_two_letters) {
	StringCalc c;
	int actual = c.Add("A,A");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, three_numbers) {
	StringCalc c;
	int actual = c.Add("2,2,2");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, number_char) {
	StringCalc c;
	int actual = c.Add("2,a");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, number_space_number) {
	StringCalc c;
	int actual = c.Add("2 2");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, char_number) {
	StringCalc c;
	int actual = c.Add("a,2");
	ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, three_with_chars) {
	StringCalc c;
	int actual = c.Add("a,2k,9");
	ASSERT_EQ(actual, -1);
}



