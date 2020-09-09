#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <list>
#include <set>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
    int result = 0;
    std::set<char> delimiters = {',', '\n'};
    size_t len = numbers.size();
    if (len > 0)
    {
        size_t start = 0;
        if (len > 3)
        {
            if (numbers[0] == '/' && numbers[1] == '/' && numbers[3] == '\n')
            {
                delimiters.insert(numbers[2]);
                start = 4;
            }
        }
        int curr = 0;
        for(int i = start; i < len; ++i)
        {
            if ((numbers[i] >= '0')  && (numbers[i] <= '9'))
                curr = curr*10 + (numbers[i] - '0');
            else
            {
                if (delimiters.count(numbers[i]))
                {
                    result += curr;
                    curr = 0;
                }
                else
                {
                    result = -1;
                    curr = 0;
                    break;
                }
            }
        }
        if (curr > 0) result += curr;
    }
	return result;//Not Implemented yet
}
