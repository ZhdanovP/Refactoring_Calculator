#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

using namespace std;

class CalculatorTest : public ::testing::Test {
  
public:
    StringCalc m_Calculator;
};

TEST_F(CalculatorTest, TestEmptyString) {
  EXPECT_EQ(0, m_Calculator.Add(""));
 }

TEST_F(CalculatorTest, TestSum) {
  EXPECT_EQ(15, m_Calculator.Add("12,3"));
 }

TEST_F(CalculatorTest, TestWrongArguments) {
  EXPECT_THROW(m_Calculator.Add("19-4-"),invalid_argument);
 }

TEST_F(CalculatorTest, TestCommaAsLast) {
  EXPECT_EQ(23, m_Calculator.Add("19,,4,"));
 }

TEST_F(CalculatorTest, TestFourArguments) {
  EXPECT_EQ(3400, m_Calculator.Add("19,4,2340,1037"));
 }

TEST_F(CalculatorTest, TestWithBothSeparators) {
  EXPECT_EQ(7500, m_Calculator.Add("19\n4,2340\n1037,4100"));
 }

TEST_F(CalculatorTest, TestExpandedSeparators) {
  EXPECT_EQ(7750, m_Calculator.Add("//;*#&\n19\n4,2340;1037;4100#100*100&50"));
}


// TEST(CalculatorTest, SampleTest) {
// 	StringCalc c;
// 	int actual = c.Add("2,2");
// 	ASSERT_EQ(actual, 4);
// }

