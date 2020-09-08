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


int StringCalc::Add(string numbers)
{
    if("" == numbers) return 0;
    int a;
    int b;
    sscanf(numbers.c_str(), "%d,%d", &a, &b);
//     cout << "a: " << a << "\n";
//     cout << "b: " << b << "\n";
    if(a < 0) return -1;
    if(b < 0) return -1;
    return a + b;
	return 0;//Not Implemented yet
}
