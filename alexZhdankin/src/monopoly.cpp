#include "monopoly.hpp"

#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(std::vector<Player> participants)
{
	auto playersListSize = (maxPlayers > participants.size()) ? participants.size() : maxPlayers;
	players.insert(players.end(), participants.begin(), participants.begin() + playersListSize);
	fields.push_back(Field::getField("Ford", FieldType::AUTO));
	fields.push_back(Field::getField("MCDonald", FieldType::FOOD));
	fields.push_back(Field::getField("Lamoda", FieldType::CLOTHER));
	fields.push_back(Field::getField("Air Baltic", FieldType::TRAVEL));
	fields.push_back(Field::getField("Nordavia", FieldType::TRAVEL));
	fields.push_back(Field::getField("Prison", FieldType::PRISON));
	fields.push_back(Field::getField("KFC", FieldType::FOOD));
	fields.push_back(Field::getField("TESLA", FieldType::AUTO));
	fields.push_back(Field::getField("Bank", FieldType::BANK));
}

const std::vector<Player>& Monopoly::GetPlayersList()
{
	return players;
}

const std::vector<Field>& Monopoly::GetFieldsList()
{
	return fields;
}

Player* Monopoly::GetPlayer(FigureType figure)
{
	auto player = find_if(players.begin(), players.end(), 
		[&figure](auto prtcpnt){ return prtcpnt.getFigure() == figure; });
	if (player == players.end()) 
	{
		return nullptr;
	}
	return &(*player); 
}

Field* Monopoly::GetField(std::string fieldName)
{
	auto field = find_if(fields.begin(), fields.end(), 
		[&fieldName](auto fld){ return fld.getName() == fieldName; });
	if (field == fields.end()) 
	{
		return nullptr;
	}
	return &(*field);
}

bool Monopoly::Buy(Player& player, Field& field)
{
	auto currentFieldType = field.getType();
	auto result = false;
	if (currentFieldType != FieldType::PRISON && currentFieldType != FieldType::BANK)
	{
		auto fieldPrice = field.getPrice();
		if (player.getCurrentMoney() > fieldPrice)
		{
			player.substractFromMoney(field.getPrice());
			field.setOwner(&player);
			result = true;
		}
	}
	
	return result;
}

bool Monopoly::Renta(Player& player, Field& field)
{
	auto currentFieldType = field.getType();
	auto result = true;
	auto owner = field.getOwner();
	if (currentFieldType == FieldType::PRISON)
	{
		player.substractFromMoney(field.getRenta());
	}
	else if (currentFieldType == FieldType::BANK)
	{
		player.addToMoney(field.getRenta());
	}
	else
	{
		if (owner != nullptr)
		{
			if (player.getFigure() != owner->getFigure())
			{
				player.substractFromMoney(field.getRenta());
				owner->addToMoney(field.getRenta());
			}
			else
			{
				result = false;
			}
		}
		else
		{
			result = false;
		}
	}
	
	return result;
}



