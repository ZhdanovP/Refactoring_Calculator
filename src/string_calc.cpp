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
void StringCalc::setNumbers(std::string numbers){
     m_Numbers = numbers;
     updateSeparators(); 
     dropState(); 
}

void StringCalc::updateSeparators(){

    vector<char>().swap(separators);
 
    if(m_Numbers.substr(0,2) == "//"){

       size_t endList = m_Numbers.find('\n',2);

       if(endList!=std::string::npos){

             size_t pos = 2;

             while(pos < endList){
                    
                 separators.emplace_back(m_Numbers[pos++]); 
            }
  
           endList++; 
           m_Numbers  = m_Numbers.substr(endList, m_Numbers.length() - endList );
        }
    }
    
    separators.emplace_back(',');
    separators.emplace_back('\n');
}
void StringCalc::dropState(){
     m_EndPos = 0;
     m_CurPos = 0;
}

void StringCalc::getEndOfTheNextNumber(){

    size_t minEndPos = m_Numbers.length();
    

    for(auto separator: separators){

     size_t endPos = m_Numbers.find(separator,m_CurPos);
           
           
           if(endPos==std::string::npos){
                endPos = m_Numbers.length();
              }          
           
           if(endPos < minEndPos){  
                minEndPos = endPos;
              }
     }

     m_EndPos = minEndPos;
}


bool StringCalc::hasWrongArguments(){
 
    const std::regex rgx("[0-9]");

    string wrongSymbs = std::regex_replace(m_Numbers,rgx,"");

    for(auto separator: separators){
        wrongSymbs.erase(std::remove(wrongSymbs.begin(), wrongSymbs.end(), separator), wrongSymbs.end()); 
    }

    return (wrongSymbs.length())?true:false;
}


int StringCalc::Add(string numbers){

    setNumbers(numbers);

    if(hasWrongArguments()){
             return -1;
        }
    
    unsigned int result = 0;
   
     
      while(m_CurPos<m_Numbers.length()){
        
           getEndOfTheNextNumber();
  
           string sNumber = m_Numbers.substr(m_CurPos,m_EndPos - m_CurPos);

           //cout<<"m_CurPos = " << m_CurPos <<"m_EndPos="<< m_EndPos <<" : "<< sNumber <<endl;

           result += stoi(sNumber);

           m_CurPos = m_EndPos+1; 
      }             
    
    return result;
}
