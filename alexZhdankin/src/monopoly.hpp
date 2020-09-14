#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include "field.hpp"
#include "player.hpp"

#include <list>
#include <tuple>
#include <string>
#include <vector>

constexpr short maxPlayers = 8;

class Monopoly
{
	public:
		Monopoly(std::vector<Player>);

		const std::vector<Player>& GetPlayersList();
		const std::vector<Field>& GetFieldsList();

		bool Buy(Player&, Field&);
		bool Renta(Player&, const Field&);
		Player* GetPlayer(FigureType);	 
		Field* GetField(std::string);	

	private:
		std::vector<Player> players;
		std::vector<Field> fields;
};

#endif