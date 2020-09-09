#include "string_calc.hpp"
#include "numbersprovider.hpp"

using namespace std;

int StringCalc::Add(string numbers){

    NumbersProvider mumbersProvider(numbers); 

    unsigned int result = 0;
        
      while(mumbersProvider.hasNextNumber()){
        
           string sNumber=mumbersProvider.getEndOfTheNextNumber();

           if(sNumber.length()){
           
           int currentNumber = stoi(sNumber);

           if(currentNumber<1000)
              result += currentNumber;
                    
                      } 
      }             
    
    return result;
}
