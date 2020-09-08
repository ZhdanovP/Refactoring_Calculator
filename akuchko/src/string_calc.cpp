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
	
	// std::cout << "numbers: " << numbers << std::endl;
	
	std::vector<string> wrong_characters {"%"};
	for (const auto &chr : wrong_characters)
	{		
		if (numbers.find(chr) != std::string::npos) {
    		// return -1;
			throw std::invalid_argument("Invalid argument syntax");
		}
	}

	std::vector<char> accepted_delimeters {' ', '.', '\n', ';', '*', '[', ']', '/'};
	for (const auto &chr : accepted_delimeters)
	{		
		std::replace( numbers.begin(), numbers.end(), chr, ',');		
	}	

	// std::cout << "numbers after: " << numbers << std::endl;

	vector <string> tokens;           
    stringstream check1(numbers);       
    string intermediate; 
          
    while(getline(check1, intermediate, ',')) 
    { 
		// std::cout << "----" << intermediate << "----" << std::endl;
        // check if previous coma was already added, then skip it		

		tokens.push_back(intermediate); 
    } 
	
	// for (auto &i : tokens)
	// 	std::cout << i <<std::endl;

	if (tokens.size() == 0)
	{
		return 0;
	}		
	else if (tokens.size() == 1)
	{
		if (tokens[0].empty())
		{
			return 0;
		}
		else
		{
			int number = std::stoi(tokens[0]);
			return (number >=0 ? number : -1);		
		}
		
	}
	else
	{		
		int result = 0;
		for (int i=0; i < tokens.size(); ++i)
		{
			if (!tokens[i].empty())
			{
				int current_number = std::stoi(tokens[i]);
				if (current_number < 0)
				{
					return -1;
				}
				else if(current_number > 1000)
				{
					current_number = 0;
				}
				else
				{
					result += current_number;
				}	
			}					
		}
		return result;
	}	
}
