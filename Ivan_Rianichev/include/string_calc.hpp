#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>
#include <iostream>

class StringCalc {
 public:
  StringCalc();

  ~StringCalc();

  int Add(std::string numbers);

 private:
  bool parseToOperands(std::string numbers);
  bool isNumber(const std::string& operand);

  std::vector<int> operands;
  const std::string customDelimiterPrefix;
  const int minValue;
  const int maxValue;
};

#endif
