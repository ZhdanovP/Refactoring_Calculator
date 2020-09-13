#pragma once

#include <iostream>

extern char win;
extern char cells[9];

void show_cells();
void make_move(int num, std::istream&);
char check();
void result();
void run(std::istream&);
