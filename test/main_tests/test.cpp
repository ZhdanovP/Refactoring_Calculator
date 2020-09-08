#include <iostream>
#include "gtest/gtest.h"
#include "string_calc.hpp"

TEST(CalculatorTest, TestName)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(CalculatorTest, SampleTest)
{
    StringCalc c;
    int        actual = c.Add("2,2");
    ASSERT_EQ(actual, 4);
}

TEST(CalculatorTest, EmptyInputStringTest)
{
    StringCalc c;
    int        actual = c.Add("");
    ASSERT_EQ(actual, 0);
}

TEST(CalculatorTest, OneNumberInputStringTest)
{
    StringCalc c;
    auto       actual = c.Add("0");
    ASSERT_EQ(actual, 0);

    actual = c.Add("1");
    ASSERT_EQ(actual, 1);
}

TEST(CalculatorTest, InvalidInputStringTest)
{
    StringCalc c;
    auto       actual = c.Add("   ");
    ASSERT_EQ(actual, -1);
}

TEST(CalculatorTest, InvalidInputStringDelimiterTest)
{
    StringCalc c;
    auto       actual = c.Add("2\n2");
    ASSERT_EQ(actual, 4);
}


TEST(CalculatorTest, NegativeNumberAreNotAllowedTest)
{
    StringCalc c;
    auto       actual = c.Add("2,-2");
    ASSERT_EQ(actual, 2);
}
