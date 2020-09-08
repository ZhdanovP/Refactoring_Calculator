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
    
    
    string parseSeparator(string s, string &a, int &parsed) {
        
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
    
    while("" != rest) {
        // separator
        if(',' != rest[0]) return -1;
        rest = rest.substr(1);
        
        // second number
        rest = ::parseNum(rest, b, parsed);
        if(0 == parsed) return -1; // expecting a number
        a += b;
    }

    return a;
}
