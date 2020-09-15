#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

static size_t findEndOfDelimitersList(string numsStr)
{
	size_t delimListEndPos = 0;
	delimListEndPos = numsStr.find('\n');
	while(!isdigit(numsStr[delimListEndPos + 1])) // checking if \n is the right bound of delimiters list
	{
		delimListEndPos = numsStr.find('\n', delimListEndPos + 1); // find next 'end of line' symbol
		if (delimListEndPos == string::npos)
		{
			throw invalid_argument("Invalid delimeter list!");
		}
	}
	return delimListEndPos;
}

static void getDelimiters(map<char, int>& delimsVec, string& numsStr)
{
	if (numsStr.find("//") == 0) // if numbers starts with "//"
	{
		// end of delimeters list
		auto delimListEndPos = findEndOfDelimitersList(numsStr);
		for (size_t i = 2; i < delimListEndPos; ++i)
		{
			if (isdigit(numsStr[i]))
			{
				throw invalid_argument("End of delimiters list is missed!");
			}
			pair<char, int> tmpPair;
			if (numsStr[i] == '[')
			{
				++i; // go to delimeter symbol
				auto closeBracePos = numsStr.find_first_of(']', i); // find the end of delimeter definition
				if (closeBracePos == string::npos)
				{
					throw invalid_argument("Invalid delimeter definition!");
				}
				tmpPair = make_pair(numsStr[i], closeBracePos - i); // calculating quantity of delimeter symbols
				i = closeBracePos; // i is the pos of ']'
			}
			else
			{
				tmpPair = make_pair(numsStr[i], 1);
			}
			if (delimsVec.find(tmpPair.first) != delimsVec.end())
			{
				throw invalid_argument("Repeating delimeter!");
			}
			delimsVec.insert(tmpPair);
		}
		numsStr.erase(0, delimListEndPos + 1); // erase delimeters list from input string
	}
	else
	{
		delimsVec.insert(make_pair(',', 1));
		delimsVec.insert(make_pair('\n', 1));
	}
}

static void getSeparatedNumbers(vector<string>& numsVec, string numsStr)
{
	map<char, int> delimiters; // char - delimeter symbol, int - quantity of delimeter symbols
	getDelimiters(delimiters, numsStr);

	string tmpStr;
	for (size_t i = 0; i < numsStr.size();)
	{
		auto delimIter = delimiters.find(numsStr[i]);
		if (delimIter != delimiters.end())
		{
			numsVec.push_back(tmpStr);
			tmpStr.clear();
			i += delimIter->second; // go to the start of next number
		}
		else
		{
			tmpStr.push_back(numsStr[i]);
			++i;
		}
	}
	if (!tmpStr.empty())
	{
		numsVec.push_back(tmpStr);
	}
}

int StringCalc::Add(string numbers)
{
	vector<string> numbersVec;

	getSeparatedNumbers(numbersVec, numbers);

	if (numbersVec.size() == 0)
		return 0;

	int result = 0;

	for (size_t i = 0; i < numbersVec.size(); ++i)
	{
		auto currStrNum = numbersVec[i];
		if (all_of(currStrNum.begin(), currStrNum.end(), [](char val) { return isdigit(val); }))
		{
			auto resultNumber = stoi(currStrNum);
			if (resultNumber > 1000)
			{
				continue;
			}
			else
			{
				result += resultNumber;
			}
		}
		else
		{
			throw invalid_argument("Invalid argument!");
		}
	}

	return result;
}