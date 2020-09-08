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
  bool parseToOperands(const std::string& numbers);

  std::vector<int> operands;
};

#endif
