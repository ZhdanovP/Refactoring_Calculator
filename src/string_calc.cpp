#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

namespace {

std::vector<int>
getNumbers(std::string inputNumbers)
{
    std::replace(inputNumbers.begin(), inputNumbers.end(), '\n', ',');
    std::istringstream numbersStream(inputNumbers);
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
        sum += n;
    }

    return sum;
}
