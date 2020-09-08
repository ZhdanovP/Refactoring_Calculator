#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <regex>
#include <iostream>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers){

    const std::regex rgx("[0-9]|,");

    if(std::regex_replace(numbers,rgx,"").length()){
         return -1;
    }

    unsigned int result = 0;
    size_t endPos = 0;
    size_t curPos = 0;
    char separator =','; 

      while(curPos<numbers.length()){
   
           endPos = numbers.find(separator,curPos);
           
           if(endPos==std::string::npos){
               endPos = numbers.length();    
           } 
                           
           result += stoi(numbers.substr(curPos,endPos - curPos));

           curPos = endPos+1; 
      }             
    
    return result;
}
