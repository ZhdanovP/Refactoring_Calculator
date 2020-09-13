#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <unordered_map>
#include <string>

#include "player.hpp"
#include "fields.hpp"

class Monopoly
{
public:
	
	Monopoly(std::string names[10],int);

	std::shared_ptr<Player> getPlayer(std::string name);
	std::shared_ptr<Field>  getField(std::string name);


	std::unordered_map<std::string,std::shared_ptr<Field>> Fields;
	
	std::unordered_map<std::string,std::shared_ptr<Player>> Players;

	bool Buy(std::string namePlayer, std::string nameField);

	bool Rent(std::string namePlayer, std::string nameField);
	
};

#endif