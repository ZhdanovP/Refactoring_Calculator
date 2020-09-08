#include "string_calc.hpp"
#include <vector>
#include <algorithm>

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

std::vector<std::string> split(std::string str)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::ostream_iterator<std::string>(std::cout, "\n"));
}

int StringCalc::Add(string numbers)
{
	auto operands = split(numbers);
	int result {0};
	for(auto num : operands)
	{
		result += atoi(num.data());
	}
	return result;
}
