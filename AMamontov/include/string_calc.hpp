#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <set>

class StringCalc
{
public:
	StringCalc();

	~StringCalc();
	
	int Add(std::string numbers);
         
private:
        void dropState();
        void getEndOfTheNextNumber();  
        void parseSeparators(); 
        void checkWrongArguments();
        void setNumbers(std::string numbers); 

        std::set<std::string> separators;
        std::string m_Numbers; 
        size_t m_EndPos;
        size_t m_CurPos;
        size_t m_Offs;
};

#endif

