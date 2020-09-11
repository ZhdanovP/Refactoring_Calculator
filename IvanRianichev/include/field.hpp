#ifndef FIELD_HPP
#define FIELD_HPP
#include <string>
#include "player.hpp"
#include <memory>

namespace Game {

class Field {
 public:
  enum Type { AUTO, FOOD, TRAVEL, CLOTHER, PRISON, BANK };

  Field(std::string name, Type type, int number, bool occupied)
      : name_(name), type_(type), number_(number), occupied_(occupied) {}

  std::string getName() const {
    return name_;
  }

  Type getType() const {
    return type_;
  }

  int getNumber() const {
    return number_;
  }
  bool isOccupied() const {
    return occupied_;
  }

  friend bool operator==(const Field& field1, const Field& field2) {
    return field1.getName() == field2.getName() &&
           field1.getType() == field2.getType() &&
           field1.getNumber() == field2.getNumber() &&
           field1.isOccupied() == field2.isOccupied();
  };
  friend bool operator!=(const Field& field1, const Field& field2) {
    return !(field1 == field2);
  }

 private:
  std::string name_;
  Type type_;
  int number_;
  Player owner_;
  bool occupied_;
};
}
#endif
