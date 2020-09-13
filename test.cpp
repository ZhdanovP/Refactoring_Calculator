#include "tic_tac_toe.hpp"

#include <sstream>

#include <gtest/gtest.h>

using namespace std;

TEST(Game, MakeMove) {
  memset(cells, '-', 9);

  istringstream iss{"1\n2\n"};
  make_move(0, iss);
  make_move(1, iss);

  EXPECT_EQ(cells[0], 'O');
  EXPECT_EQ(cells[1], 'X');
}

TEST(Game, Run) {
  memset(cells, '-', 9);

  istringstream iss{"a\nb\n1\n4\n2\n5\n3\n"};
  run(iss);

  EXPECT_EQ(win, 'X');
}

TEST(Gem, Check) {
  memset(cells, '-', 9);
  EXPECT_EQ(check(), '-');

  char win_row[9] = {'X', 'X', 'X', '-', '-', '-', '-', '-', '-'};
  char win_col[9] = {'X', '-', '-', 'X', '-', '-', 'X', '-', '-'};
  char win_diag[9] = {'X', '-', '-', '-', 'X', '-', '-', '-', 'X'};

  memcpy(cells, win_row, 9);
  EXPECT_EQ(check(), 'X');

  memcpy(cells, win_col, 9);
  EXPECT_EQ(check(), 'X');

  memcpy(cells, win_diag, 9);
  EXPECT_EQ(check(), 'X');
}
