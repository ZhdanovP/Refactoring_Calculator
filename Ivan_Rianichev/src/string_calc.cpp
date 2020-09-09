#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

StringCalc::StringCalc()
    : customDelimiterPrefix("//"), minValue(0), maxValue(1000) {}

StringCalc::~StringCalc() {}

int StringCalc::Add(string numbers) {
  int result = 0;
  if (!parseToOperands(numbers)) {
    throw invalid_argument("Invalid argument");
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

  if (numbers.find(customDelimiterPrefix.c_str(),
                   0,
                   customDelimiterPrefix.length()) != string::npos) {
    auto firstNewLine = numbers.find_first_of('\n') + 1;
    char customDelimiter = numbers[customDelimiterPrefix.length()];
    numbers.erase(0, firstNewLine);
    std::replace(numbers.begin(), numbers.end(), customDelimiter, '\n');
  }

  if (numbers.find(','))
    std::replace(numbers.begin(), numbers.end(), ',', '\n');

  std::stringstream ss(numbers);
  std::string item;

  while (std::getline(ss, item)) {
    if (isNumber(item)) {
      operands.push_back(std::stoi(item));
    } else {
      result = false;
      break;
    }
  }
  return result;
}

bool StringCalc::isNumber(const string& operand) {
  return !operand.empty() &&
         std::all_of(operand.begin(), operand.end(), ::isdigit);
}
