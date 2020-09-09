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

    const std::regex rgx("[0-9]|,|\n");

    if(std::regex_replace(numbers,rgx,"").length()){
         return -1;
    }

    unsigned int result = 0;
    size_t endPosComma = 0;
    size_t endPosTerm = 0;
    size_t endPos = 0;
    size_t curPos = 0;
    size_t separatorOffs = 1;
     
      while(curPos<numbers.length()){

           endPosComma = numbers.find(',',curPos);
           endPosTerm = numbers.find('\n',curPos);
           
           if(endPosComma==std::string::npos){
                endPosComma = numbers.length();
              }
                
           if(endPosTerm==std::string::npos){
                endPosTerm = numbers.length();
              }
             
           if(endPosTerm<endPosComma){  
               endPos = endPosTerm;
              }
              else{
               endPos = endPosComma;
              }
                           
           result += stoi(numbers.substr(curPos,endPos - curPos));

           curPos = endPos+1; 
      }             
    
    return result;
}
