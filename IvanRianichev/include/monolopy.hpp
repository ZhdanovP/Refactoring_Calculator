#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <string>
#include <vector>

#include "player.hpp"
#include "field.hpp"

namespace Game {

using std::string;

class Monopoly {
 public:
  Monopoly(const std::vector<Player>& players);
  std::vector<Player>* GetPlayers();
  std::vector<Field>* GetFields();
  std::vector<Field> fields_;
  std::vector<Player> players_;
  Player GetPlayerInfo(int);
  bool Buy(int p, Field);
  Field GetFieldByName(string);
  bool Renta(int p, Field c);
};
}
#endif
