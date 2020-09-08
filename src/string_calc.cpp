#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <string>




using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
auto constexpr kFailedResult = -1;
auto constexpr kEmptyString = 0;
if(numbers.empty())
{
 return  kEmptyString;
}

     std::string number;
     std::istringstream numbersStream(numbers);
            auto sum = 0;

             while (std::getline(numbersStream, number, ','))
             {
                 try {
                      sum += std::stoi(number);
                 } catch (std::invalid_argument const &ex) {
                     return kFailedResult;

                 }


             }

    return sum;//Not Implemented yet

}
