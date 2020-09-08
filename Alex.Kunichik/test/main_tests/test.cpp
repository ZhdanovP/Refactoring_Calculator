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



 TEST(CalculatorTest, TwoOperands) {
 	StringCalc c;
	int actual = c.Add("18, 17");
	ASSERT_EQ(actual, 35);
}


 TEST(CalculatorTest, NoneOperands) {
 	StringCalc c;
	int actual = c.Add("");
	ASSERT_EQ(actual, 0);
}


 TEST(CalculatorTest, OneOperand) {
 	StringCalc c;
	int actual = c.Add("9");
	ASSERT_EQ(actual, 9);
}


 TEST(CalculatorTest, OneLetterAndNumber) {
 	StringCalc c;
	int actual = c.Add("18, d");
	ASSERT_EQ(actual, 18);
}
