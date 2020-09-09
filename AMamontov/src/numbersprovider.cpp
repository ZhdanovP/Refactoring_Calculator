#include "numbersprovider.hpp"

#include <algorithm>
#include <regex>
#include <iostream>

using namespace std;

NumbersProvider::NumbersProvider(std::string numbers):m_Numbers(numbers)
{
    parseSeparators();
    checkWrongArguments();
}


bool NumbersProvider::hasNextNumber() 
{
    return m_CurPos<m_Numbers.length();
}

void NumbersProvider::checkWrongArguments(){
 
    string wrongSymbs = std::regex_replace(m_Numbers,std::regex("[0-9]"),"");

    for(auto separator: separators){
      std::string::size_type pos = 0;

  while((pos = wrongSymbs.find(separator, pos)) != std::string::npos){
      wrongSymbs.replace(pos, separator.length(), "");
  }
    }

    if (wrongSymbs.length()) {
         throw std::invalid_argument("wrong argument");
    }
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

   /* for(auto separator: separators){
          cout<<"separator="<<separator<<endl;
    }*/
}

std::string NumbersProvider::getEndOfTheNextNumber(){

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

   std::string sNumber = m_Numbers.substr(m_CurPos,m_EndPos - m_CurPos);

   m_CurPos = m_EndPos+m_Offs;

   return sNumber;
}