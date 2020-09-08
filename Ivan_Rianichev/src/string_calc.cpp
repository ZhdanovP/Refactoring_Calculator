#include "string_calc.hpp"
#include <algorithm>
#include <sstream>

using namespace std;

StringCalc::StringCalc() {}

StringCalc::~StringCalc() {}

int StringCalc::Add(string numbers) {
  int result = 0;
  if (!parseToOperands(numbers)) {
    result = -1;
  } else {
    for (auto i : operands) {
      result += i;
    }
  }
  return result;
}

bool StringCalc::parseToOperands(const std::string& numbers) {
  bool result = true;
  std::stringstream ss(numbers);
  std::string item;
  while (std::getline(ss, item, ',')) {
    if (item < "0" || item > "9") {
      result = false;
    } else {
      operands.push_back(std::stoi(item));
    }
  }
  return result;
}
