#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool is_number(const std::string &s)
{
	return !s.empty() && std::find_if(s.begin(),
									  s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

StringCalc::StringCalc()
{
}

StringCalc::~StringCalc()
{
}

int StringCalc::Add(string numbers)
{
	if (numbers.empty())
		return 0;

	if (numbers.find(",") == std::string::npos)
	{
		if (is_number(numbers))
			return std::atoi(numbers.c_str());
		else
			return -1;
	}
	std::vector<std::string> seglist;
	{
		std::stringstream test(numbers);
		std::string segment;

		while (std::getline(test, segment, ','))
		{
			seglist.push_back(segment);
		}
	}
	if (seglist.size() == 0)
		return 0;
	if (seglist.size() == 1)
	{
		auto num = seglist[0];
		if (is_number(num))
			return std::atoi(num.c_str());
		else
			return -1;
	}
	if (seglist.size() == 2)
	{
		if (!is_number(seglist[0].c_str()) || !is_number(seglist[1].c_str()))
			return -1;
		int a = std::atoi(seglist[0].c_str()), b = std::atoi(seglist[1].c_str());
		return a + b;
	}
	else
	{
		return -1;
	}
}
