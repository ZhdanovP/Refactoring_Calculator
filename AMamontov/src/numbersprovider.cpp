#include "numbersprovider.hpp"

#include <algorithm>
#include <iostream>
#include <cctype>
#include <functional>
#include <regex>

using namespace std;

NumbersProvider::NumbersProvider(std::string numbers):m_Numbers(numbers)
{
    parseSeparators();
    parseNumbers();
}

bool NumbersProvider::hasNextNumber() {

    return m_CurPos<m_OutNumbers.size();
}

int NumbersProvider::getNextNumber(){

      return m_OutNumbers[m_CurPos++];
}

void NumbersProvider::replaceSeparators(){
 
    for(auto separator: separators){

     std::string::size_type pos = m_CurPos;

     while((pos = m_Numbers.find(separator, pos)) != std::string::npos){
     m_Numbers.replace(pos, separator.length()," ");
     pos+=separator.length();
       }
        
    }
}

void NumbersProvider::parseNumbers(){
	  
	  replaceSeparators();
      
      size_t curPos=0;

      while(m_CurPos<m_Numbers.length()){

          curPos = m_Numbers.find(' ',m_CurPos); 

          if(curPos == string::npos){
              curPos =  m_Numbers.length();              
          } 

        string number =  m_Numbers.substr(m_CurPos,curPos-m_CurPos);
        
        if(!regex_replace(number,regex("[0-9]"),"").length()){
           m_OutNumbers.emplace_back(stoi(number)); 
        }
         else{
           throw invalid_argument("wrong number value");
        }   

         m_CurPos = ++curPos; 
      }

      m_CurPos=0;
}

bool NumbersProvider::getOneSymbSep(){

   if(m_Numbers[m_CurPos]!='['){
        	separators.insert(string(1,m_Numbers[m_CurPos]));
        	m_CurPos++;
        	return true; 
        }

   return false;
}

void NumbersProvider::getManySymbSep(){

	   size_t posClosed;

        if(( posClosed = m_Numbers.find(']',++m_CurPos))!=string::npos){
              separators.insert(m_Numbers.substr(m_CurPos,posClosed-m_CurPos));                
                m_CurPos = ++posClosed;
        }
         else
           throw invalid_argument("wrong separator"); 

}

void NumbersProvider::parseSeparators(){
 
   separators.insert(",");
   separators.insert("\n");

   if(m_Numbers.substr(0,2)!="//")return;
   size_t m_CurPos = 2;
   while(m_Numbers[m_CurPos]!='\n'){
        
        if(!getOneSymbSep()){
        	  getManySymbSep();
        }
   }
    m_CurPos++;  
}