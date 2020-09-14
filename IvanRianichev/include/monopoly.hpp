#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <string>
#include <vector>
#include <memory>

#include "player.hpp"
#include "field.hpp"

namespace Game {

using std::string;

class Monopoly {
 public:
  Monopoly(const std::vector<std::shared_ptr<Player> >& players);
  const std::vector<std::shared_ptr<Player> >& GetPlayers();
  const std::vector<std::shared_ptr<Field> >& GetFields();
  std::shared_ptr<const Player> GetPlayerInfo(int playerID);
  std::shared_ptr<Field> GetFieldByName(string);
  bool Buy(std::shared_ptr<Player>& buyer, std::shared_ptr<Field>& fieldToBuy);
  bool Renta(std::shared_ptr<Player>& rentingPlayer,
             std::shared_ptr<Field>& fieldToRent);

 private:
  bool playerExists(const std::shared_ptr<Player>& player);
  bool fieldExists(const std::shared_ptr<Field>& field);
  std::vector<std::shared_ptr<Field> > fields_;
  std::vector<std::shared_ptr<Player> > players_;
};
}
#endif
