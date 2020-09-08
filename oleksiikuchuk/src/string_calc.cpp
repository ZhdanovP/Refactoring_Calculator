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
		int a;
		iss >> a;
		if (iss.fail() || a < 0) return -1;

		while (!iss.eof()) {
			const string separators{",\n"};
			int b;
			char comma;
			iss.get(comma) >> b;

			if (iss.fail() || separators.find(comma) == string::npos || b < 0) return -1;
			a += b;
		}
	
		return a;
}
