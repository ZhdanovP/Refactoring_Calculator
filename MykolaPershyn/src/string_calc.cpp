#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

namespace {
    string parseNum(string s, int &a, int &parsed) {
        a = 0;
        parsed = 0;
        for(char c : s) {
            if('0' <= c && c <= '9')
            {
                ++parsed;
                a *= 10;
                a += c - '0';
            }
            else
                break;
        }
        return s.substr(parsed);
    }
};

int StringCalc::Add(string numbers)
{
    // empty case
    if("" == numbers) return 0;
    int a;
    int b;
    int parsed;
    
    // first number
    string rest = ::parseNum(numbers, a, parsed);
    if(0 == parsed) return -1; // expecting a number
    if(numbers.size() == parsed) {
        // the string contains just one number
        return a;
    }
    // coma
    if(',' != rest[0]) return -1;
    rest = rest.substr(1);
    
    // second number
    string rest2 = ::parseNum(rest, b, parsed);
    if(0 == parsed) return -1; // expecting a number
    if(rest.size() == parsed) {
        return a + b;
    }

    return -1;
}
