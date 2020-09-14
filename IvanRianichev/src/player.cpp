#include "player.hpp"
#include <iostream>

namespace Game {
using namespace std;
size_t Player::counter = 0;

Player::Player(const std::string& name, int money)
    : name_(name), money_(money), id_(counter++) {}

std::string Player::getName() const {
  return name_;
}

int Player::getMoney() const {
  return money_;
}

int Player::debit(int amountOfMoney) {
  money_ -= amountOfMoney;
  return money_;
}

int Player::addMoney(int amountOfMoney) {
  money_ += amountOfMoney;
  return money_;
}

int Player::getID() const {
  return id_;
}

bool Player::operator==(const Player& other) const {
  return this->id_ == other.id_ && this->name_ == other.name_ &&
         this->money_ == other.money_;
}

bool Player::operator!=(const Player& other) const {
  return !(*this == other);
}
}
