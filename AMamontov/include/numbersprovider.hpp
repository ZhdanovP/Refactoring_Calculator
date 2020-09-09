#ifndef NUMBERSPROVIDER_HPP
#define NUMBERSPROVIDER_HPP

#include <string>
#include <set>
#include <vector>

class NumbersProvider
{
   public:
     NumbersProvider(std::string numbers);
     
     bool hasNextNumber();
     std::string getEndOfTheNextNumber();
   
   private:
   	   void prepareNumbers();
   	   void parseSeparators();

       std::string m_Numbers;
       std::set<std::string> separators;
       std::vector<std::string> m_OutNumbers;

       size_t m_CurPos = 0;

};

#endif

