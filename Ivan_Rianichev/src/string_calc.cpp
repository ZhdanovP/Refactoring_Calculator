#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

StringCalc::StringCalc()
    : minValue(0), maxValue(1000) {}

StringCalc::~StringCalc() {}

int StringCalc::Add(string numbers) {
  int result = 0;
  if (!parseToOperands(numbers)) {
    result = -1;
  } else {
    for (auto i : operands) {
      if (i >= minValue && i <= maxValue)
        result += i;
    }
  }
  return result;
}

bool StringCalc::parseToOperands(string numbers) {
  bool result = true;
  std::replace(numbers.begin(), numbers.end(), '\n', ',');
  std::stringstream ss(numbers);
  std::string item;

  while (std::getline(ss, item, ',')) {
    if (item >= "0" && item < "9999") {
      operands.push_back(std::stoi(item));
    } else {
      result = false;
      break;
    }
  }
  return result;
}
