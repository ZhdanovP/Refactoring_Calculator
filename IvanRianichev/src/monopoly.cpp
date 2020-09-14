#include "monopoly.hpp"
#include <algorithm>
#include <iostream>

using namespace ::std;
namespace Game {

Monopoly::Monopoly(const std::vector<shared_ptr<Player> >& players) {
  players_ = players;
  fields_.insert(fields_.begin(),
                 {make_shared<Field>("Ford", Field::AUTO),
                  make_shared<Field>("MCDonald", Field::FOOD),
                  make_shared<Field>("Lamoda", Field::CLOTHER),
                  make_shared<Field>("Air Baltic", Field::TRAVEL),
                  make_shared<Field>("Nordavia", Field::TRAVEL),
                  make_shared<Field>("Prison", Field::PRISON),
                  make_shared<Field>("MCDonald", Field::FOOD),
                  make_shared<Field>("TESLA", Field::AUTO)});
}

const std::vector<shared_ptr<Player> >& Monopoly::GetPlayers() {
  return players_;
}

const std::vector<shared_ptr<Field> >& Monopoly::GetFields() {
  return fields_;
}

std::shared_ptr<const Player> Monopoly::GetPlayerInfo(int playerID) {
  auto result = find_if(players_.begin(),
                        players_.end(),
                        [&](const std::shared_ptr<Player>& i) {
                          if (i)
                            return playerID == i->getID();
                          return false;
                        });
  if (result != players_.end())
    return *result;
  return std::shared_ptr<const Player>();
}

// bool Monopoly::Buy(int z, Field k) {
bool Monopoly::Buy(shared_ptr<Player>& buyer,
                   std::shared_ptr<Field>& fieldToBuy) {
  bool result = false;
  if (playerExists(buyer) && fieldExists(fieldToBuy) &&
      !fieldToBuy->isOwned()) {
    switch (fieldToBuy->getType()) {
      case Field::AUTO:
        buyer->debit(500);
        fieldToBuy->setOwner(buyer);
        break;
      case Field::FOOD:
        buyer->debit(250);
        fieldToBuy->setOwner(buyer);
        break;
      case Field::TRAVEL:
        buyer->debit(700);
        fieldToBuy->setOwner(buyer);
        break;
      case Field::CLOTHER:
        buyer->debit(100);
        fieldToBuy->setOwner(buyer);
        break;
      default:
        return false;
    }
    result = true;
  }
  return result;
}

std::shared_ptr<Field> Monopoly::GetFieldByName(std::string l) {
  std::vector<shared_ptr<Field> >::iterator i =
      find_if(fields_.begin(),
              fields_.end(),
              [l](shared_ptr<const Field> x) { return x->getName() == l; });
  return *i;
}

bool Monopoly::playerExists(const std::shared_ptr<Player>& player) {
  return std::find(players_.begin(), players_.end(), player) != players_.end();
}

bool Monopoly::fieldExists(const std::shared_ptr<Field>& field) {
  return std::find(fields_.begin(), fields_.end(), field) != fields_.end();
}

bool Monopoly::Renta(std::shared_ptr<Player>& rentingPlayer,
                     std::shared_ptr<Field>& fieldToRent) {
  bool result = false;
  auto owner = fieldToRent->getOwner();

  if (playerExists(rentingPlayer) && fieldExists(fieldToRent) &&
      fieldToRent->isOwned()) {
    switch (fieldToRent->getType()) {
      case Field::AUTO:
        rentingPlayer->debit(250);
        owner->addMoney(250);
        break;
      case Field::FOOD:
        rentingPlayer->debit(250);
        owner->addMoney(250);
        break;
      case Field::TRAVEL:
        rentingPlayer->debit(250);
        owner->addMoney(250);
        break;
      case Field::CLOTHER:
        rentingPlayer->debit(250);
        owner->addMoney(250);
        break;
      case Field::PRISON:
        rentingPlayer->debit(1000);
        owner->addMoney(1000);
        break;
      case Field::BANK:
        rentingPlayer->debit(700);
        owner->addMoney(700);
        break;
      default:
        return false;
    }
    result = true;
  }
  return result;
}
}
