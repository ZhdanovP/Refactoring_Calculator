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
if(numbers.empty())
{
 return kFailedResult;
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
