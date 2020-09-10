#include "monolopy.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(vector<std::string> names)
{
	for (auto &name : names)
	{
		Players.emplace_back(new Player(name, 6000));
	}		

	Fields.emplace_back(new AutoField("Ford")); 
	Fields.emplace_back(new FoodField("MCDonald"));
	Fields.emplace_back(new ClotherField("Lamoda"));
	Fields.emplace_back(new TravelField("Air Baltic"));
	Fields.emplace_back(new TravelField("Nordavia"));
	Fields.emplace_back(new PrisonField("Prison"));
	Fields.emplace_back(new FoodField("MCDonald"));
	Fields.emplace_back(new AutoField("TESLA"));
}

std::list<Player*> Monopoly::GetPlayersList()
{
	return Players;
}

std::list<Field*> Monopoly::GetFieldsList()
{
	return Fields;
}

Player* Monopoly::GetPlayer(int id)
{
	auto it_player = std::find_if(Players.begin(), Players.end(), [id](Player* p){
		return p->getId() == id;
	});
	return *it_player;
}

Field* Monopoly::GetFieldByName(std::string field_name)
{
	auto it_field = find_if(Fields.begin(), Fields.end(), [field_name] (Field* f) {
		return f->getName() == field_name;
	});
	return *it_field;
}

bool Monopoly::Buy(int id, Field* field)
{
	auto current_player = GetPlayer(id);
	field->OccupyByPlayer(current_player);
}

bool Monopoly::Renta(int id, Field* field)
{
	auto current_player = GetPlayer(id);
	auto own_player = GetPlayer(field->getId());

	field->ExchangeBalance(own_player, current_player);
}