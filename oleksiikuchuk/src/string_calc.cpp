#include "string_calc.hpp"
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace {

std::string ParseExtraSeparators(istringstream &iss, const string& separators) {
		char prefix1, prefix2;
    iss >> prefix1 >> prefix2;
    if (iss.fail() || iss.eof() || prefix1 != '/' || prefix2 != '/') throw invalid_argument{"invalid prefix"};

    string extra_separators;
    while (1) {
      char s;
      iss.get(s);
      if (iss.fail() || iss.eof()) throw invalid_argument{"prefix not terminated"};
      if (separators.find(s) != string::npos) break;
      extra_separators += s;
    }
		return extra_separators;
}

int ParseNumber(istringstream& iss) {
	int x;
  iss >> x;
  if (iss.fail() || x < 0) throw invalid_argument{"invalid number"};
  if (x > 1000) x = 0;
	return x;
}

int SkipSeparators(istringstream& iss, const string& separators) {
	while (1) {
      int ch = iss.peek();
      if (separators.find(ch) != string::npos)
        iss.ignore(1);
      else
        break;
  }
}

} // namespace

int StringCalc::Add(string numbers) {
  if (numbers.empty()) return 0;

  istringstream iss{numbers};
  string separators{",\n"};
	if (iss.peek() == '/') separators += ParseExtraSeparators(iss, separators);

  int a = ParseNumber(iss);
  while (!iss.eof()) {
		SkipSeparators(iss, separators);
		int b = ParseNumber(iss);
    a += b;
  }

  return a;
}
