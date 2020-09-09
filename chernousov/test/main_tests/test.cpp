#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

TEST(CalculatorTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest_1) {
 	StringCalc c;
 	int actual = c.Add("2,2");
 	ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, SampleTest_2) {
StringCalc c;
int actual = c.Add("");
ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleTest_3) {
StringCalc c;
int actual = c.Add("1");
ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, SampleTest_4) {
StringCalc c;
int actual = c.Add(",2");
ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, SampleTest_5) {
StringCalc c;
int actual = c.Add("2,");
ASSERT_EQ(actual, 2);
}

TEST(CalculatorTest, SampleTest_6) {
StringCalc c;
int actual = c.Add(",");
ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleTest_7) {
StringCalc c;
int actual = c.Add("a,");
ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SampleTest_8) {
StringCalc c;
int actual = c.Add(",A");
ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SampleTest_9) {
StringCalc c;
int actual = c.Add("2,F");
ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SampleTest_10) {
StringCalc c;
int actual = c.Add("3asd,");
ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SampleTest_11) {
StringCalc c;
int actual = c.Add("2,45ass");
ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SampleTest_12) {
StringCalc c;
int actual = c.Add("g6j9");
ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, SampleTest_13) {
StringCalc c;
int actual = c.Add(",6,4145,2314");
ASSERT_EQ(actual, 6465);
}

TEST(CalculatorTest, SampleTest_14) {
StringCalc c;
int actual = c.Add("3214,243,3421");
ASSERT_EQ(actual, 6878);
}


TEST(CalculatorTest, SampleTest_15) {
StringCalc c;
int actual = c.Add(",,,,,,,");
ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleTest_16) {
StringCalc c;
int actual = c.Add("3214,243,");
ASSERT_EQ(actual, 3457);
}

TEST(CalculatorTest, SampleTest_17) {
StringCalc c;
int actual = c.Add("3214,243\n3421");
ASSERT_EQ(actual, 6878);
}


TEST(CalculatorTest, SampleTest_18) {
StringCalc c;
int actual = c.Add(",,\n,\n,,");
ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, SampleTest_19) {
StringCalc c;
int actual = c.Add("3214\n243\n");
ASSERT_EQ(actual, 3457);
}
