#include "string_calc.hpp"
#include <algorithm>
#include <iostream>
#include <optional>

using namespace std;

namespace {
    constexpr bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    string parseNum(int &a, const string& input) {
        auto it = find_if_not(input.cbegin(), input.cend(), isDigit);
        a = 0;
        const auto accumDigit = [&](char c){a *= 10; a += c - '0';};
        for_each(input.cbegin(), it, accumDigit);
        return input.substr(it - input.cbegin());
    }

    string parseDefaultSeparator(optional<string>& val, const string& input) {
        return ("\n" == input.substr(0, 1) || "," == input.substr(0, 1))
        ? val = input.substr(0, 1), input.substr(1)
        : input;
    }
    
    string parseString(string s, optional<string>& val, const string& input) {
        return input.substr(0, s.size()) == s
        ? val = input.substr(0, s.size()), input.substr(s.size())
        : input;
    }
};

int StringCalc::Add(const string& numbers)
{
    // empty case
    if("" == numbers) return 0;
    int sum = 0;
    int parsed;
    optional<string> sep = nullopt;
    optional<string> val;
    
    auto fail = [&numbers](string s = "") {
        throw(std::invalid_argument(numbers + s));
        return -1;
    };
    
    string rest = numbers;
    
    // Parse separator if specified
    rest = parseString("//", val = nullopt, rest);
    if(nullopt != val) {
        if('[' == rest[0]) {
            size_t pos = rest.find("]\n");
            if(string::npos == pos) return fail();
            sep = rest.substr(1, pos - 3);
            rest = rest.substr(pos + 2);
        }
        else {
            if('\n' != rest[1]) return fail();
            sep = rest.substr(0, 1);
            rest = rest.substr(2);
        }
    }

    // First number
    rest = ::parseNum(sum, rest);
    if(sum > 1000) sum = 0;
    
    while("" != rest) {
        // separator
        rest = nullopt == sep
        ? parseDefaultSeparator(val = nullopt, rest)
        : parseString(*sep, val = nullopt, rest);
        if(nullopt == val) return fail();
        
        // second number
        int b;
        rest = ::parseNum(b, rest);
        if(b <= 1000) sum += b;
    }

    return sum;
}
