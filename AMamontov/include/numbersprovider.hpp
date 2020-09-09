#ifndef NUMBERSPROVIDER_HPP
#define NUMBERSPROVIDER_HPP

#include <string>
#include <set>

class NumbersProvider
{
   public:
     NumbersProvider(std::string numbers);
     
     bool hasNextNumber();
     std::string getEndOfTheNextNumber();
   
   private:
   	   void checkWrongArguments();
   	   void parseSeparators();

       std::string m_Numbers;
       std::set<std::string> separators;

       size_t m_CurPos = 0;
       size_t m_EndPos = 0;    
       size_t m_Offs = 0;

};

#endif

