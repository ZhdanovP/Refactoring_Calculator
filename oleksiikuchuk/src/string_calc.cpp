#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <exception>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
		if (numbers.empty()) return 0;

		istringstream iss{numbers};
		int a, b;
		char comma;

		iss >> a;
		if (iss.fail() || a < 0) return -1;
		if (iss.eof()) return a;
	
		iss >> comma;
		if (iss.fail() || iss.fail() || comma != ',') return -1;

		iss >> b;
		if (iss.fail() || !iss.eof() || b < 0) return -1;

	 return a + b;
}
