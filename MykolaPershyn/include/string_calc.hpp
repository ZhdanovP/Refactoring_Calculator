#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>

class StringCalc
{
public:
	StringCalc() = default;

	~StringCalc() = default;
	
	int Add(const std::string& numbers);
};

#endif

