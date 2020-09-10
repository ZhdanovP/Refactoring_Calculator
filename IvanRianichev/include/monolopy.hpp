#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <string>
#include <vector>

namespace Game {

using std::string;

class Player {
 public:
  Player(const string& name = "", int money = 6000)
      : name(name), money(money) {}
  string getName() const {
    return name;
  }

  int getMoney() const {
    return money;
  }

 private:
  string name;
  int money;
};

class Field {
 public:
  enum Type { AUTO, FOOD, TRAVEL, CLOTHER, PRISON, BANK };

  Field(string name, Type type, int number, bool occupied)
      : name_(name), type_(type), number_(number), occupied_(occupied) {}

  string getName() const {
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

 private:
  string name_;
  Type type_;
  int number_;
  bool occupied_;
};

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
