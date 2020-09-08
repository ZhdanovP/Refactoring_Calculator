#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>

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

		string separators{",\n"};
		istringstream iss{numbers};
		int a;
		iss >> a;
		if (iss.fail())
		{
			iss.clear();
			char prefix1, prefix2;
			iss.get(prefix1);
			iss.get(prefix2);
			if (iss.fail() || iss.eof() || prefix1 != '/' || prefix2 != '/') throw invalid_argument{"invalid prefix"};

			string extra_separators;
			while(1)
			{
				char s;
				iss.get(s);
				if (iss.fail() || iss.eof()) throw invalid_argument{"prefix not terminated"};
				if (s == ',' || s == '\n') break;
				extra_separators += s;
			}
			separators += extra_separators;
			iss >> a;
		}
		
		if(iss.fail() || a < 0) throw invalid_argument{"invalid a"};
		if (a > 1000) a = 0;

		while (!iss.eof()) {
			int b;

			while(1) {
				int ch = iss.peek();
				char comma;
				if (separators.find(ch) != string::npos)
					iss.get(comma);
				else
					break;
			}
			iss >> b;

			if (iss.fail() || b < 0) throw invalid_argument{"invalid b"};
			if (b > 1000) b = 0;
			a += b;
		}
	
		return a;
}
