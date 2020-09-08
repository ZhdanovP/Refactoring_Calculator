#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include <iostream>

using namespace std;

namespace {

std::pair<std::string, std::vector<char>>
getDelimeters(std::string const& inputNumber)
{
    try {
        auto const prefix = inputNumber.substr(0, 2);
        if (prefix.compare("//") != 0) {
            return {inputNumber, {}};
        }
    }
    catch (std::out_of_range const& ex) {
        return {inputNumber, {}};
    }

    auto found = inputNumber.find("\n");

    if (found == std::string::npos) {
        return {};
    }

    auto const        delimitersString = inputNumber.substr(2, found - 1);
    std::vector<char> delimiters;
    for (auto d : delimitersString) {
        delimiters.push_back(d);
    }
    auto returnedString = inputNumber.substr(found + 1, inputNumber.size() + 1);
    return {returnedString, delimiters};
}

std::vector<int>
getNumbers(std::string inputNumbers)
{
    auto const delimiters = getDelimeters(inputNumbers);
    if (delimiters.first.empty()) {
        return {};
    }
    auto handledString = delimiters.first;

    if (delimiters.second.empty()) {
        std::replace(handledString.begin(), handledString.end(), '\n', ',');
    }
    else {
        for (char d : delimiters.second) {
            std::replace(handledString.begin(), handledString.end(), d, ',');
        }
    }
    std::istringstream numbersStream(handledString);
    std::vector<int>   numbers;
    std::string        number;
    while (std::getline(numbersStream, number, ',')) {
        try {
            numbers.push_back(std::stoi(number));
        }
        catch (std::invalid_argument const& ex) {
            return {};
        }
    }
    return numbers;
}
}  // namespace

StringCalc::StringCalc() {}


StringCalc::~StringCalc() {}


int
StringCalc::Add(string numbers)
{
    auto constexpr kFailedResult      = -1;
    auto constexpr kEmptyStringResult = 0;
    if (numbers.empty()) {
        return kEmptyStringResult;
    }


    auto numbersVector = getNumbers(numbers);
    if (numbersVector.empty()) {
        return kFailedResult;
    }

    auto sum = 0;
    for (auto const& n : numbersVector) {
        if (n > 0) {
            sum += n;
        }
    }

    return sum;
}
