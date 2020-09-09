#include "numbersprovider.hpp"

#include <algorithm>
#include <iostream>
#include <cctype>
#include <functional>

using namespace std;

NumbersProvider::NumbersProvider(std::string numbers):m_Numbers(numbers)
{
    parseSeparators();
    prepareNumbers();
}


bool NumbersProvider::hasNextNumber() 
{
    return m_CurPos<m_OutNumbers.size();
}

void NumbersProvider::prepareNumbers(){
 
     string number;
     string separator; 

     for (auto symb : m_Numbers){

         if(isdigit(symb)){

             number += string(1,symb);

          }
         else{

             separator += string(1,symb);
             
             std::function<bool(const string &)> func = [separator]( const string &curSeporator ) -> bool
             {
                 if(separator.length()>curSeporator.length()){
                 	return false;
                 } 

                 return  ( curSeporator.find(separator) ==0 )?true:false;    
             };

             set<string>::iterator separatorExistence =  find_if(separators.begin(),separators.end(),func); 

            if(separatorExistence!=separators.end()){

            if((*separatorExistence)==separator){

                 if(number.length()){
                    m_OutNumbers.emplace_back(number); 
                    number="";    
                 }

                 separator = "";
                }

             }
             else{
             	throw invalid_argument("illegal symbol");
             } 
 
         }

     }

      if(number.length()){
             
             m_OutNumbers.emplace_back(number);
      }
     
}

std::string NumbersProvider::getEndOfTheNextNumber(){

      return m_OutNumbers[m_CurPos++];
}

void NumbersProvider::parseSeparators(){

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

}