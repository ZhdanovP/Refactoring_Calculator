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
     int getNextNumber();
   
   private:
   	   void parseNumbers();
   	   void parseSeparators();
   	   bool getOneSymbSep();
   	   void getManySymbSep();
   	   void replaceSeparators();

       std::string m_Numbers;
       std::set<std::string> separators;
       std::vector<int> m_OutNumbers;

       size_t m_CurPos = 0;

};

#endif

