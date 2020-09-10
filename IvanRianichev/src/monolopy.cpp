#include "monolopy.hpp"
#include <algorithm>
#include <iostream>

using namespace ::std;
namespace Game {

Monopoly::Monopoly(const std::vector<Player>& players) {
  for (const auto& player : players) {
    players_.push_back(player);
  }
  fields_.push_back(Field("Ford", Field::AUTO, 0, false));
  fields_.push_back(Field("MCDonald", Field::FOOD, 0, false));
  fields_.push_back(Field("Lamoda", Field::CLOTHER, 0, false));
  fields_.push_back(Field("Air Baltic", Field::TRAVEL, 0, false));
  fields_.push_back(Field("Nordavia", Field::TRAVEL, 0, false));
  fields_.push_back(Field("Prison", Field::PRISON, 0, false));
  fields_.push_back(Field("MCDonald", Field::FOOD, 0, false));
  fields_.push_back(Field("TESLA", Field::AUTO, 0, false));
}

std::vector<Player>* Monopoly::GetPlayers() {
  return &players_;
}

std::vector<Field>* Monopoly::GetFields() {
  return &fields_;
}

Player Monopoly::GetPlayerInfo(int m) {
  vector<Player>::iterator i = players_.begin();
  advance(i, m - 1);
  return *i;
}

bool Monopoly::Buy(int z, Field k) {
  auto x = GetPlayerInfo(z);
  Player p;
  vector<Field>::iterator i;
  vector<Player>::iterator j = players_.begin();
  switch (k.getType()) {
    case Field::AUTO:
      if (k.getNumber())
        return false;
      p = Player(x.getName(), x.getMoney() - 500);
      k = Field(k.getName(), k.getType(), z, k.getNumber());
      break;
    case Field::FOOD:
      if (k.getNumber())
        return false;
      p = Player(x.getName(), x.getMoney() - 250);
      k = Field(k.getName(), k.getType(), z, k.getNumber());
      break;
    case Field::TRAVEL:
      if (k.getNumber())
        return false;
      p = Player(x.getName(), x.getMoney() - 700);
      k = Field(k.getName(), k.getType(), z, k.getNumber());
      break;
    case Field::CLOTHER:
      if (k.getNumber())
        return false;
      p = Player(x.getName(), x.getMoney() - 100);
      k = Field(k.getName(), k.getType(), z, k.getNumber());
      break;
    default:
      return false;
  };
  i = find_if(fields_.begin(),
              fields_.end(),
              [k](auto x) { return x.getName() == k.getName(); });
  *i = k;
  advance(j, z - 1);
  *j = p;
  return true;
}

Field Monopoly::GetFieldByName(std::string l) {
  std::vector<Field>::iterator i =
      find_if(fields_.begin(),
              fields_.end(),
              [l](const Field& x) { return x.getName() == l; });
  return *i;
}

bool Monopoly::Renta(int m, Field c) {
  Player z = GetPlayerInfo(m);
  Player o;

  switch (c.getType()) {
    case Field::AUTO:
      if (!c.getNumber())
        return false;
      o = GetPlayerInfo(c.getNumber());
      o = Player(o.getName(), o.getMoney() + 250);
      z = Player(z.getName(), z.getMoney() - 250);
      break;
    case Field::FOOD:
      if (!c.getNumber())
        return false;
    case Field::TRAVEL:
      if (!c.getNumber())
        return false;
      o = GetPlayerInfo(c.getNumber());
      o = Player(o.getName(), o.getMoney() + 250);
      z = Player(z.getName(), z.getMoney() - 250);
      break;
    case Field::CLOTHER:
      if (!c.getNumber())
        return false;
      o = GetPlayerInfo(c.getNumber());
      o = Player(o.getName(), o.getMoney() + 250);
      z = Player(z.getName(), z.getMoney() - 250);
      break;
    case Field::PRISON:
      z = Player(z.getName(), z.getMoney() - 1000);
      break;
    case Field::BANK:
      z = Player(z.getName(), z.getMoney() - 700);
      break;
    default:
      return false;
  }
  vector<Player>::iterator i = players_.begin();
  advance(i, m - 1);
  *i = z;
  i = find_if(players_.begin(),
              players_.end(),
              [o](auto x) { return x.getName() == o.getName(); });
  *i = o;
  return true;
}
}
