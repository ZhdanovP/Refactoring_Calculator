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

void replaceAllSubStrings(string& str, const string& from, const string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

void defineDelimeters(string string_to_search ,string mask, 
					 vector<string>& accepted_delimeters,
					 char end_symbol)
{
	string new_delimeter;	
	for (int i=mask.size(); string_to_search[i] != end_symbol; ++i)
	{
		new_delimeter += string_to_search[i];
	}
	
	string end_symbol_str;
	end_symbol_str += end_symbol;
	accepted_delimeters.push_back(mask);	
	accepted_delimeters.push_back(end_symbol_str);
	accepted_delimeters.push_back(new_delimeter);
}

int convertNumber(const char * str_to_convert)
{
    char *endptr;
    long value = std::strtol(str_to_convert, &endptr, 10);

    if (endptr == str_to_convert || *endptr != '\0')
    {        
		throw invalid_argument("Invalid argument exception");
    }
    else
    {
        return value;
    }
} 

int StringCalc::Add(string numbers)
{		
	vector<string> accepted_delimeters {",", "\n"};	

	string mask("//");
	string long_mask = mask + "[";
	
	if (numbers.rfind(long_mask, 0) == 0) 	
	{
		defineDelimeters(numbers, long_mask, accepted_delimeters, ']');
	}
	else if (numbers.rfind(mask, 0) == 0)
	{
		defineDelimeters(numbers, mask, accepted_delimeters, '\n');		
	}
	else
	{
		accepted_delimeters = {"\n"};
	}

	for (auto chr : accepted_delimeters)
	{			
		replaceAllSubStrings( numbers, chr, ",");		
	}	

	vector<string> tokens;           
    stringstream stream_numbers(numbers);       
    string intermediate; 
          
    while(getline(stream_numbers, intermediate, ',')) 
    { 
		tokens.push_back(intermediate); 
    } 

	if (tokens.size() == 0)
	{
		return 0;
	}
	else
	{		
		int result = 0;
		for (int i=0; i < tokens.size(); ++i)
		{
			if (!tokens[i].empty())
			{
				int current_number = 0;
				current_number = convertNumber(tokens[i].c_str());
								
				if (current_number < 0)
				{
					return -1;
				}
				else if(current_number > max_number_)
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
