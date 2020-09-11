#include "gtest/gtest.h"
#include "tic_tac_toe.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

const int CELL_SIZE = 9;

class TictacTest : public ::testing::Test
{
public:
  void SetUp()
  {
    ::testing::internal::CaptureStdout();
  }

  void TearDown()
  {
  }
};

TEST_F(TictacTest, CellTest) 
{
    show_cells();
    std::string capturedStdout = ::testing::internal::GetCapturedStdout().c_str();
    std::string reference_out("---|---|---\n---|---|---\n---|---|---\n");
    EXPECT_STREQ(reference_out.c_str(), capturedStdout.c_str());
}

TEST_F(TictacTest, MainFuncTest)
{     
  istringstream iss("artem tanya 1 2 4 5 7"); 
  cin.rdbuf(iss.rdbuf());

  EXPECT_NO_THROW(main_func());
}  

