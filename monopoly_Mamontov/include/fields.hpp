#ifndef FIELDS_HPP
#define FIELDS_HPP

#include <string>
#include <memory>

class Player;

class Field{

public:

Field(int sellingPrise):
m_SellingPrise(sellingPrise){};

virtual bool buy(std::shared_ptr<Player>);

protected:
	 const int m_SellingPrise;

};

class RentalField : public Field
{
public:
	RentalField(int sellingPrise,int renatalPrise):
	Field(sellingPrise),
    m_RentalPrise(renatalPrise){};

bool rent(std::shared_ptr<Player>);
bool sell(std::shared_ptr<Player>);
bool buy(std::shared_ptr<Player>);
  
private:
	const int m_RentalPrise;
    std::shared_ptr<Player> m_Owner=0;
};



class Prison: public Field{

public:    
      Prison():Field(700){}; 
   
};

class Bank: public Field{

public:    
      Bank():Field(500){}; 
   
};

class Travel: public RentalField{

public:    
      Travel():RentalField(500,250){}; 
   
};


class Auto: public RentalField{

public:    
      Auto():RentalField(500,250){}; 
   
};


class Closes: public RentalField{

public:    
      Closes():RentalField(500,250){}; 
   
};

class Food: public RentalField{

public:    
      Food():RentalField(100,50){}; 
   
};



#endif