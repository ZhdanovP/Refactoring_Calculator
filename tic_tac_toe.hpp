#pragma once

#include <iostream>

extern char win;
extern char cells[9];

struct Move {
 int cell{-1};
 int value{-1};
};

void show_cells();
Move ask_move(int num, std::istream&);
void make_move(const Move&);
char check();
void result();
void run(std::istream&);
