#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <string>
#include <vector>

#include "player.hpp"
#include "field.hpp"

using namespace player;

class Monopoly
{
public:
	explicit Monopoly(std::vector<std::string> names);	
	std::list<Player*>	GetPlayersList();
	std::list<Field*> GetFieldsList();
	Player*  GetPlayer(int);
	bool Buy(int p, Field*);
	Field* GetFieldByName(std::string);	
	bool Renta(int p, Field* c);

private:
	std::list<Field*> Fields;
	std::list<Player*> Players;
};

#endif