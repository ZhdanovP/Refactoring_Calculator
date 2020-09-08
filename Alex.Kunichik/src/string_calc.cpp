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
    std::istringstream ss(str);
    std::string token;
	std::vector<std::string> result;
    
    while(std::getline(ss, token, ',')) {
        //std::cout << token << '\n';
		result.push_back(token);
    }

    return result;
}

int StringCalc::Add(string numbers)
{
	auto operands = split(numbers);
	//std::cout << "operands done";
	int result {0};
	for(auto num : operands)
	{
		result += std::atoi(num.c_str());
		std::cout << result;
	}
	return result;
	//std::cout << result;
}
