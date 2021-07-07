#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <regex>

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

	std::regex words_regex("[^\\n.,:;!?a-zA-Z ]+");
	auto words_begin = std::sregex_iterator(numbers.begin(), numbers.end(), words_regex);
	auto words_end = std::sregex_iterator();

	std::vector<std::string> seglist;

	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{
		if ((*i).str().empty())
			continue;
		seglist.push_back((*i).str());
	}

	if (seglist.size() == 0)
		return 0;
	bool good = true;
	int sum = 0;

	for (auto &str : seglist)
		if (!is_number(str))
		{
			good = false;
			break;
		}
		else
		{
			sum += std::atoi(str.c_str());
		}

	if (!good)
		return -1;

	return sum;
}
