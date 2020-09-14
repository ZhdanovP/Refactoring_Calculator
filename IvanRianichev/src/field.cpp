#include <field.hpp>
#include <iostream>

namespace Game {

Game::Field::Field(std::__cxx11::string name, Game::Field::Type type)
    : name_(name), type_(type), owner_(nullptr), owned_(false) {}

std::string Field::getName() const {
  return name_;
}

Field::Type Field::getType() const {
  return type_;
}

int Field::getOwnerID() const {
  return owner_->getID();
}

bool Field::isOwned() const {
  return owned_;
}

std::shared_ptr<Player> Field::getOwner() const {
  return owner_;
}

void Field::setOwner(std::shared_ptr<Player> owner) {
  owner_ = owner;
  owned_ = true;
}

bool Field::operator==(const Field& other) const {
  return this->name_ == other.name_ && this->type_ == other.type_ &&
         this->owned_ == other.owned_ && this->owner_ == other.owner_;
}

bool Field::operator!=(const Field& other) const {
  return !(*this == other);
}
}
