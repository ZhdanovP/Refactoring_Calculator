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
     parseSeparators(); 
     dropState(); 
}

void StringCalc::parseSeparators(){

    separators.clear();
 
    if(m_Numbers.substr(0,2) == "//"){

       size_t endList = m_Numbers.find('\n',2);

       if(endList != std::string::npos){

             size_t pos = 2;

             bool waitingSeparatorEnd=false;
             std::string separatorString;   

             while(pos < endList){
                 
                 if(waitingSeparatorEnd){

                      if(m_Numbers[pos] != ']'){
                          separatorString+=m_Numbers.substr(pos++,1);
                      }
                       else{
                            separators.insert(separatorString);
                            separatorString = "";
                            pos++;
                            waitingSeparatorEnd = false;
                      } 
           
                   }
                   else{

                      if(m_Numbers[pos] == '['){
                        waitingSeparatorEnd = true;
                        pos++;
                      }
                      else{
                       separators.insert(m_Numbers.substr(pos++,1)); 
                      }
                    }
            }
  
           endList++; 
           m_Numbers  = m_Numbers.substr(endList, m_Numbers.length() - endList );
        }
    }
    
    separators.insert(",");
    separators.insert("\n");

   /* for(auto separator: separators){
          cout<<"separator="<<separator<<endl;
    }*/
}
void StringCalc::dropState(){
     m_EndPos = 0;
     m_CurPos = 0;
     m_Offs = 0;
}

void StringCalc::getEndOfTheNextNumber(){

    m_EndPos = m_Numbers.length();
    

    for(auto separator: separators){

     size_t endPos = m_Numbers.find(separator,m_CurPos);
           
           
           if(endPos==std::string::npos){
                endPos = m_Numbers.length();
              }          
           
           if(endPos < m_EndPos){  
                m_EndPos = endPos;
                m_Offs = separator.length();
              }
     }

}


void StringCalc::checkWrongArguments(){
 
    const std::regex rgx("[0-9]");

    string wrongSymbs = std::regex_replace(m_Numbers,rgx,"");

    for(auto separator: separators){
      std::string::size_type pos = 0u;

  while((pos = wrongSymbs.find(separator, pos)) != std::string::npos){
      wrongSymbs.replace(pos, separator.length(), "");
  }
    }

    if (wrongSymbs.length()) {
         throw std::invalid_argument("wrong argument");
    }
}


int StringCalc::Add(string numbers){

    setNumbers(numbers);

    checkWrongArguments();

    unsigned int result = 0;
        
      while(m_CurPos<m_Numbers.length()){
        
           getEndOfTheNextNumber();
  
           string sNumber = m_Numbers.substr(m_CurPos,m_EndPos - m_CurPos);

           //cout<<"m_CurPos = " << m_CurPos <<"m_EndPos="<< m_EndPos <<" : "<< sNumber <<endl;
 
           if(sNumber.length()){
           
           int currentNumber = stoi(sNumber);

           if(currentNumber<1000)
              result += currentNumber;
         
           m_CurPos = m_EndPos+m_Offs;
                      } 

      }             
    
    return result;
}
