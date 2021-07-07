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
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, one_letter_capital) {
	StringCalc c;
	int actual = c.Add("A");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, capital_two_letters) {
	StringCalc c;
	int actual = c.Add("A,A");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, number_char) {
	StringCalc c;
	int actual = c.Add("2,a");
	ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, number_space_number) {
	StringCalc c;
	int actual = c.Add("2 2");
	ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, char_number) {
	StringCalc c;
	int actual = c.Add("a,2");
	ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, three_with_chars) {
	StringCalc c;
	int actual = c.Add("a,2k,9");
	ASSERT_EQ(actual, 11);
}

TEST(CalculatorTest, three_numbers) {
	StringCalc c;
	int actual = c.Add("2,2,2");
	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, three_numbers_six) {
	StringCalc c;
	int actual = c.Add("0,2,4");
	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, four_numbers) {
	StringCalc c;
	int actual = c.Add("2,2,7,2");
	ASSERT_EQ(actual, 6+7);
}

TEST(CalculatorTest, five_num) {
	StringCalc c;
	int actual = c.Add("1,2,3,4,5");
	ASSERT_EQ(actual, 6+4+5);
}

TEST(CalculatorTest, five_num_bad) {
	StringCalc c;
	int actual = c.Add("1,2,3,a,5");
	ASSERT_EQ(actual, 11);
}

// \n sepa


TEST(CalculatorTest, two_two) {
  StringCalc c;
  int actual = c.Add("2\n2");
  ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, two_three_nsep) {
	StringCalc c;
	int actual = c.Add("2\n3");
	ASSERT_EQ(actual, 5);
}

TEST(CalculatorTest, capital_two_letters_nsep) {
	StringCalc c;
	int actual = c.Add("A\nA");
	ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, number_char_nsep) {
	StringCalc c;
	int actual = c.Add("2\na");
	ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, number_space_number_nsep) {
	StringCalc c;
	int actual = c.Add("2 2\n3");
	ASSERT_EQ(actual, 7);
}

TEST(CalculatorTest, char_number_nsep) {
	StringCalc c;
	int actual = c.Add("a\n2");
	ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, three_with_chars_nsep) {
	StringCalc c;
	int actual = c.Add("a,2k\n9");
	ASSERT_EQ(actual, 11);
}

TEST(CalculatorTest, three_numbers_nsep) {
	StringCalc c;
	int actual = c.Add("2\n2,2");
	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, three_numbers_six_nsep) {
	StringCalc c;
	int actual = c.Add("0\n2\n4");
	ASSERT_EQ(actual, 6);
}

TEST(CalculatorTest, four_numbers_nsep) {
	StringCalc c;
	int actual = c.Add("2\n2\n7\n2");
	ASSERT_EQ(actual, 6+7);
}

TEST(CalculatorTest, five_num_nsep) {
	StringCalc c;
	int actual = c.Add("1,2\n3,4\n5");
	ASSERT_EQ(actual, 6+4+5);
}

TEST(CalculatorTest, five_num_bad_nsep) {
	StringCalc c;
	int actual = c.Add("1,2\n3,a\n5");
	ASSERT_EQ(actual, 11);
}