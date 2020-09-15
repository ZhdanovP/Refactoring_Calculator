#include "monolopy.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		Players[names[i]] =std::make_shared<Player>(6000);
	}
	
	 Fields["TESLA"] = std::make_shared<Auto>();
	 Fields["Ford"] = std::make_shared<Auto>();
	 Fields["AlfaBank"] = std::make_shared<Bank>();
	 Fields["McDonalds"] = std::make_shared<Food>();
	 Fields["Tour"] = std::make_shared<Travel>();

}

std::shared_ptr<Player> Monopoly::getPlayer(string  name)
{
  return Players[name];
}

std::shared_ptr<Field> Monopoly::getField(string name)
{
  return Fields[name];
}



bool Monopoly::Buy(string namePlayer, string nameField)
{    	
	return getField(nameField)->buy(getPlayer(namePlayer));
}

bool Monopoly::Rent(string namePlayer, string nameField)
{
	auto rentalField = std::dynamic_pointer_cast<RentalField>(getField(nameField));

	if(!rentalField)
		    return false;

    rentalField->rent(getPlayer(namePlayer));		

	return true;
}