#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

StringCalc::StringCalc() {}

StringCalc::~StringCalc() {}

int StringCalc::Add(string numbers) {
  int result = 0;
  if (!parseToOperands(numbers)) {
    result = -1;
  } else {
    for (auto i : operands) {
      if (i >= 0 && i <= 1000)
        result += i;
    }
  }
  return result;
}

bool StringCalc::parseToOperands(string numbers) {
  bool result = true;
  std::replace_if(
      numbers.begin(),
      numbers.end(),
      [](const char& i) { return !std::isdigit(i) && i != '-' && i != '.'; },
      ',');
  std::stringstream ss(numbers);
  std::string item;

  while (std::getline(ss, item, ',')) {
    if (item >= "0" && item < "9999") {
      operands.push_back(std::stoi(item));
    } else {
      result = false;
    }
  }
  return result;
}