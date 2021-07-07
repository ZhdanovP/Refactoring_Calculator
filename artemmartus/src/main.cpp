#include <iostream>
#include "string_calc.hpp"

int main(int argc, char **argv) {
	std::string input;
	std::cin >> input;

	StringCalc calc;
	std::cout << calc.Add(input);
	return 0;
}