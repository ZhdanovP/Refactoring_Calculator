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

    string parseDefaultSeparator(string s, int &parsed) {
        if(s.size() >= 1) {
            if('\n' == s[0] || ',' == s[0]) {
                parsed = 1;
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
    bool defaultSep = true;
    
    auto fail = [&numbers](string s = "") {
        throw(std::invalid_argument(numbers + s));
        return -1;
    };
    
    string rest = numbers;
    if("//" == numbers.substr(0, 2)) {
        defaultSep = false;
        if('[' == numbers[2]) {
            size_t pos = numbers.find("]\n");
            if(string::npos == pos) return fail();
            sep = numbers.substr(3, pos - 3);
            rest = numbers.substr(pos + 2);
        }
        else {
            sep = numbers.substr(2, 1);
            rest = numbers.substr(4);
            if('\n' != numbers[3]) return fail();
        }
    }
    // first number
    rest = ::parseNum(rest, a, parsed);
    
    while("" != rest) {
        // separator
        rest = defaultSep ? parseDefaultSeparator(rest, parsed) : parseSeparator(rest, sep, parsed);
        if(0 == parsed) return fail();
        
        // second number
        rest = ::parseNum(rest, b, parsed);
        a += b;
    }

    return a;
}
