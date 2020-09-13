#include "tic_tac_toe.hpp"

#include <sstream>

#include <gtest/gtest.h>

using namespace std;

TEST(Game, AskMove) {
  memset(cells, '-', 9);

  istringstream iss{"1\n2\n"};

  auto move1 = ask_move(1, iss);
  EXPECT_EQ(move1.cell, 0);
  EXPECT_EQ(move1.value, 'X');

  auto move2 = ask_move(2, iss);
  EXPECT_EQ(move2.cell, 1);
  EXPECT_EQ(move2.value, 'O');
}

TEST(Game, MakeMove) {
  memset(cells, '-', 9);

  Move move{0, 'X'};
  make_move(move);

  EXPECT_EQ(cells[0], 'X');
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
