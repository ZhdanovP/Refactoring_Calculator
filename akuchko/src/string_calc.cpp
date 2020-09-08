#include "string_calc.hpp"
#include <vector>
#include <algorithm>

#include <bits/stdc++.h>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{	
	std::vector<string> wrong_characters {"/", "%", " ", "."};
	for (const auto &chr : wrong_characters)
	{
		if (numbers.find(chr) != std::string::npos) {
    		return -1;
		}
	}

	vector <string> tokens;           
    stringstream check1(numbers);       
    string intermediate; 
          
    while(getline(check1, intermediate, ',')) 
    { 
        tokens.push_back(intermediate); 
    } 
          
	if (tokens.size() == 0)
	{
		return 0;
	}		
	else if (tokens.size() == 1)
	{
		int number = std::stoi(tokens[0]);
		return (number >=0 ? number : -1);		
	}
	else if (tokens.size() == 2)
	{
		int number1 = std::stoi(tokens[0]);
		int number2 = std::stoi(tokens[1]);

		return (number1 >=0 && number2 >=0 ? number1 + number2 : -1);
	}
	else
	{
		// TODO next
		return -1;
	}	
}
