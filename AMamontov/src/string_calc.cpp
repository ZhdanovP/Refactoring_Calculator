#include "string_calc.hpp"
#include "numbersprovider.hpp"

using namespace std;

int StringCalc::Add(string numbers){

    NumbersProvider mumbersProvider(numbers); 

    unsigned int result = 0;
        
      while(mumbersProvider.hasNextNumber()){
        
           int currentNumber=mumbersProvider.getNextNumber();
                  
           if(currentNumber<1000){
              result += currentNumber;
           }
                  
      }             
    
    return result;
}
