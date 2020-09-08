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

if(numbers.empty())
{
 return -1;
}

     std::string number;
     std::istringstream numbersStream(numbers);
            auto sum = 0;

             while (std::getline(numbersStream, number, ','))
             {
                    sum += std::stoi(number);

             }

    return sum;//Not Implemented yet

}
