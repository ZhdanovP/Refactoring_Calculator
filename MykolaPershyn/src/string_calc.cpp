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
    
    
    string parseSeparator(string s, string sep, int &parsed) {
        if(s.size() >= sep.size()) {
            if(s.substr(0, sep.size()) == sep) {
                parsed = sep.size();
                return s.substr(parsed);
            }
            else {
                parsed = 0;
                return s;
            }
        }
        else {
            parsed = 0;
            return s;
        }
    }
};

int StringCalc::Add(string numbers)
{
    // empty case
    if("" == numbers) return 0;
    int a;
    int b;
    int parsed;
    string sep = "";
    
    auto fail = [&numbers]() {
        throw(std::invalid_argument(numbers));
        return -1;
    };
    // Parsed
    
    
    // first number
    string rest = ::parseNum(numbers, a, parsed);
    if(0 == parsed) return fail(); // expecting a number
    
    while("" != rest) {
        // separator
        rest = parseSeparator(rest, ",", parsed);
        if(0 == parsed) return fail();
        
        // second number
        rest = ::parseNum(rest, b, parsed);
        if(0 == parsed) return fail();
        a += b;
    }

    return a;
}
