#include "monopoly.hpp"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10], int countPlaers)
{
  for (int i = 0; i < countPlaers; i++)
  {
    Players.push_back({names[i], 6000});
  }
  Fields.push_back({"Ford", Monopoly::AUTO, 0});
  Fields.push_back({"MCDonald", Monopoly::FOOD, 0});
  Fields.push_back({"Lamoda", Monopoly::CLOTHER, 0});
  Fields.push_back({"Air Baltic", Monopoly::TRAVEL, 0});
  Fields.push_back({"Nordavia", Monopoly::TRAVEL, 0});
  Fields.push_back({"Prison", Monopoly::PRISON, 0});
  Fields.push_back({"MCDonald", Monopoly::FOOD, 0});
  Fields.push_back({"TESLA", Monopoly::AUTO, 0});
}

Monopoly::Monopoly(std::initializer_list<const char*>& names)
{
  
  for (string n : names) Players.push_back({n, 6000});
  Fields.push_back({"Ford", Monopoly::AUTO, 0});
  Fields.push_back({"MCDonald", Monopoly::FOOD, 0});
  Fields.push_back({"Lamoda", Monopoly::CLOTHER, 0});
  Fields.push_back({"Air Baltic", Monopoly::TRAVEL, 0});
  Fields.push_back({"Nordavia", Monopoly::TRAVEL, 0});
  Fields.push_back({"Prison", Monopoly::PRISON, 0});
  Fields.push_back({"MCDonald", Monopoly::FOOD, 0});
  Fields.push_back({"TESLA", Monopoly::AUTO, 0});
}

std::list<Monopoly::Player> * Monopoly::GetPlayersList()
{
  return &Players;
}

std::list<Monopoly::field_t> * Monopoly::GetFieldsList()
{
  return &Fields;
}

Monopoly::Player Monopoly::GetPlayerInfo(int m)
{
  auto i = Players.begin();
  advance(i, m - 1);
  return *i;
}

bool Monopoly::Buy(int z, field_t k)
{
  auto x = GetPlayerInfo(z);
  Player p;
  list<field_t>::iterator i;
  auto j = Players.begin();
  if (k.owner)
    return false;
  if(nullopt == price(k.type)) return false;
  p = {x.name, x.money - *price(k.type)};
  k.owner = z;
  i = find_if(Fields.begin(), Fields.end(), [k](auto x) { return x.name == k.name; });
  *i = k;
  advance(j, z-1);
  *j = p;
  return true;
}

Monopoly::field_t  Monopoly::GetFieldByName(const std::string l) const
{
  auto compareL = [l] (field_t x) {
    return x.name == l;
  };
  auto i = find_if(Fields.cbegin(), Fields.cend(), compareL);
  return *i;
}

bool Monopoly::Renta(int m, field_t c)
{
  auto z = GetPlayerInfo(m);
  Player o;
  
  if(nullopt == price(c.type)) {
    switch (c.type)
    {
      case PRISON:
        z.money -= 11000;
        break;
      case BANK:
        z.money -= 700;
        break;
      default:
        return false;
    }
  }
  else {
    if (!(c.owner))
      return false;
    o = GetPlayerInfo(c.owner);
    o.money += 250;
    z.money -= 250;
  }
  
  auto i = Players.begin();
  advance(i, m - 1);
  *i = z;
  i = find_if(Players.begin(), Players.end(), [o](auto x) { return x.name == o.name; });
  *i = o;
  return true;
}
